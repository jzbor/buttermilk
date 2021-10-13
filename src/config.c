#include <ini.h>
#include <limits.h>
#include <stdlib.h>
#include <vte/vte.h>

#include "colors.h"
#include "config.h"


/* MACROS */
#define CLRSCM_MATCH(C)         (strcmp(str, (C)) == 0)
#define NAME_MATCH(N)           (strcmp(name, (N)) == 0)
#define SECTION_MATCH(S)        (strcmp(section, (S)) == 0)
#define LENGTH(X)               (sizeof X / sizeof X[0])

/* FUNCTIONS */
static int str_to_bool(const char *str);
static const ColorScheme *str_to_clrscm(const char *str);
static int str_to_int(int *dest, const char *str);
static int cfg_handler(void* user, const char* section, const char* name, const char* value);

static Config config = default_config;

Config *
get_config(char *path)
{
    int status;
    if (!path) return &config;

    status = ini_parse(path, cfg_handler, &config);
    if (status < 0) {
        fprintf(stderr, "Unable to read configuration from %s\n", path);
    } else if (status) {
        fprintf(stderr, "Bad config file %s (first error on line %d)\n", path, status);
    }
    return &config;
}

Config *
load_config_files(void)
{
    char config_file[PATH_MAX] = {0};

    /* load global config */
    get_config("/etc/buttermilk.conf");

    if (getenv("XDG_CONFIG_HOME")) {
        sprintf(config_file, "%s/%s/%s", getenv("XDG_CONFIG_HOME"), "buttermilk", cfg_file_name);
    } else if (getenv("HOME")){
        sprintf(config_file, "%s/.config/%s/%s", getenv("HOME"), "buttermilk", cfg_file_name);
    } else {
        sprintf(config_file, "%s", cfg_file_name);
    }
    get_config(config_file);

    return &config;
}

void
print_config(Config *cfg)
{
    printf("[config]\n");
    printf("scrollback_lines    = %d\n", cfg->scrollback_lines);
    printf("# boolean options accept '1' and 'true' as true, everything else as false\n");
    printf("scroll_on_output    = %d\n", cfg->scroll_output);
    printf("scroll_on_keys      = %d\n", cfg->scroll_keys);
    printf("hide_mouse          = %d\n", cfg->scroll_keys);
    printf("allow_hyperlink     = %d\n", cfg->allow_hyperlink);
    printf("\n");
    printf("[theming]\n");
    printf("# Available colorschemes (also sets fg and bg colors):\n#\t");
    for (int i = 0; i < LENGTH(colorschemes); i++)
        printf("%s ", colorschemes[i]->name);
    printf("\n");
    printf("colorscheme         = %s\n", cfg->colorscheme->name);
    /* printf("foreground          = 0x%08x\n", cfg->fgcolor); */
    /* printf("background          = 0x%08x\n", cfg->bgcolor); */
    printf("foreground          = %s\n", gdk_rgba_to_string(&cfg->fgcolor));
    printf("background          = %s\n", gdk_rgba_to_string(&cfg->bgcolor));
}

int
str_to_bool(const char *str)
{
    return (strcmp(str, "true") == 0 || strcmp(str, "1") == 0);
}

const ColorScheme *
str_to_clrscm(const char *str)
{
    for (int i = 0; i < LENGTH(colorschemes); i++) {
        if (strcmp(str, colorschemes[i]->name) == 0)
            return colorschemes[i];
    }

    fprintf(stderr, "Colorscheme '%s' not found\n", str);
    return NULL;
}

int
str_to_int(int *dest, const char *str)
{
    (*dest) = strtol(str, NULL, 0);
    return 1;
}

int
cfg_handler(void* user, const char* section, const char* name, const char* value)
{
    int ibuffer;
    const ColorScheme *cbuffer;
    Config *cfg = (Config*)user;

    if (SECTION_MATCH("config")) {
        if (NAME_MATCH("scrollback_lines")) {
            if (str_to_int(&ibuffer, value)) {
                cfg->scrollback_lines = ibuffer;
            }
        } else if (NAME_MATCH("allow_hyperlink")) {
            cfg->hide_mouse = str_to_bool(value);
        } else if (NAME_MATCH("hide_mouse")) {
            cfg->hide_mouse = str_to_bool(value);
        } else if (NAME_MATCH("scroll_on_keys")) {
            cfg->scroll_keys = str_to_bool(value);
        } else if (NAME_MATCH("scroll_on_output")) {
            cfg->scroll_output = str_to_bool(value);
        } else {
            return 0;
        }
    } else if (SECTION_MATCH("theming")) {
        if (NAME_MATCH("colorscheme")) {
            if ((cbuffer = str_to_clrscm(value))) {
                cfg->colorscheme = cbuffer;
                cfg->fgcolor = cbuffer->foreground;
                cfg->bgcolor = cbuffer->background;
            }
        } else if (NAME_MATCH("foreground")) {
            gdk_rgba_parse(&cfg->bgcolor, value);
            printf("Reading color (%s): %s -> %s\n", name, value, gdk_rgba_to_string(&cfg->bgcolor));
        } else if (NAME_MATCH("background")) {
            gdk_rgba_parse(&cfg->fgcolor, value);
            printf("Reading color (%s): %s -> %s\n", name, value, gdk_rgba_to_string(&cfg->fgcolor));
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    return 1;
}
