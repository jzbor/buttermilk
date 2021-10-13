#ifndef CONFIG_H
#define CONFIG_H

#define CFG_MAX_FONTNAME_LENGHT     255

/* STRUCTS */
typedef struct {
    char fontname[CFG_MAX_FONTNAME_LENGHT + 1];
    int scrollback_lines;
    int allow_hyperlink, hide_mouse, scroll_keys, scroll_output;
    const ColorScheme *colorscheme;
    GdkRGBA fgcolor, bgcolor;
} Config;


/* CONSTANTS */
static const char cfg_name[] = "buttermilk";
static const char cfg_default_title[] = "Buttermilk Terminal";
static const char cfg_title[] = "%s"; /* may contain %s to be formatted from terminal */
static const char cfg_file_name[] = "buttermilk.conf";
static const Config default_config = {
    .fontname           = {0},
    .scrollback_lines   = 10000,
    .allow_hyperlink    = 1,
    .hide_mouse         = 1,
    .scroll_keys        = 1,
    .scroll_output      = 0,
    .colorscheme        = &clrscm_gruvbox,
    .fgcolor            = clrscm_gruvbox.foreground,
    .bgcolor            = clrscm_gruvbox.background,
};

/* FUNCTIONS */
Config *get_config(char *path);
Config *load_config_files(void);
void print_config(Config *cfg);

#endif /* CONFIG_H */
