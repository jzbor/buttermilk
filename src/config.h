#ifndef CONFIG_H
#define CONFIG_H


/* MACROS */
#define SECTION_MATCH(S)        (strcmp(section, (S)) == 0)
#define NAME_MATCH(N)           (strcmp(name, (N)) == 0)

/* STRUCTS */
typedef struct {
    int scrollback_lines;
    int scroll_keys, scroll_output, hide_mouse;
    const ColorScheme *colorscheme;
    GdkRGBA fgcolor, bgcolor;
} Config;


/* CONSTANTS */
static const char cfg_name[] = "buttermilk";
static const char cfg_default_title[] = "Buttermilk Terminal";
static const char cfg_title[] = "Buttermilk Terminal: %s"; /* may contain %s to be formatted from terminal */
static const Config default_config = {
    .scrollback_lines   = 2000,
    .scroll_output      = 0,
    .scroll_keys        = 1,
    .hide_mouse         = 1,
    .colorscheme        = &clrscm_tango,
    .fgcolor            = clrscm_tango.foreground,
    .bgcolor            = clrscm_tango.background,
};

/* FUNCTIONS */
Config *get_config(char *path);

#endif /* CONFIG_H */
