#include <ini.h>
#include <stdlib.h>
#include <vte/vte.h>

#include "colors.h"
#include "config.h"


/* FUNCTIONS */
static int str_to_bool(const char *str);
static int str_to_int(int *dest, const char *str);
static int cfg_handler(void* user, const char* section, const char* name, const char* value);

static Config config = default_config;

Config *
get_config(char *path)
{
    if (!path) return &config;

    if (ini_parse(path, cfg_handler, &config) < 0) {
        printf("Unable to load configuration from %s\n", path);
    }
    return &config;
}

int
str_to_bool(const char *str)
{
    return (strcmp(str, "true") == 0 || strcmp(str, "1") == 0);
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
    Config *cfg = (Config*)user;
    int ibuffer;
    if (SECTION_MATCH("config")) {
        if (NAME_MATCH("scrollback_lines")) {
            if (str_to_int(&ibuffer, value)) {
                cfg->scrollback_lines = ibuffer;
            }
        } else if (NAME_MATCH("scroll_on_output")) {
            cfg->scroll_output = str_to_bool(value);
        } else if (NAME_MATCH("scroll_on_keys")) {
            cfg->scroll_keys = str_to_bool(value);
        } else if (NAME_MATCH("hide_mouse")) {
            cfg->hide_mouse = str_to_bool(value);
        } else {
            return 0;
        }
    } else {
        return 0;
    }
    return 1;
}
