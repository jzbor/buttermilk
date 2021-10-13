#ifndef CONFIG_H
#define CONFIG_H


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
static const char cfg_file_name[] = "buttermilk.conf";
static const Config default_config = {
    .scrollback_lines   = 10000,
    .scroll_output      = 0,
    .scroll_keys        = 1,
    .hide_mouse         = 1,
    .colorscheme        = &clrscm_gruvbox,
    .fgcolor            = clrscm_gruvbox.foreground,
    .bgcolor            = clrscm_gruvbox.background,
};

/* FUNCTIONS */
Config *get_config(char *path);
Config *load_config_files(void);
void print_config(Config *cfg);

#endif /* CONFIG_H */
