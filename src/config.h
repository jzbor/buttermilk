static const gint cfg_scrollback_lines = 200;
static const gboolean cfg_scroll_output = FALSE;
static const gboolean cfg_scroll_keys = FALSE;
static const gboolean cfg_hide_mouse = TRUE;
static const char cfg_name[] = "buttermilk";
static const char cfg_default_title[] = "Buttermilk Terminal";
static const char cfg_title[] = "Buttermilk Terminal: %s"; /* may contain %s to be formatted from terminal */

/* COLOR PALETTES */
static const GdkRGBA default_colors[] = {
    CLR_GDK(0x111111),
    CLR_GDK(0xd36265),
    CLR_GDK(0xaece91),
    CLR_GDK(0xe7e18c),
    CLR_GDK(0x5297cf),
    CLR_GDK(0x963c59),
    CLR_GDK(0x5E7175),
    CLR_GDK(0xbebebe),
    CLR_GDK(0x666666),
    CLR_GDK(0xef8171),
    CLR_GDK(0xcfefb3),
    CLR_GDK(0xfff796),
    CLR_GDK(0x74b8ef),
    CLR_GDK(0xb85e7b),
    CLR_GDK(0xA3BABF),
    CLR_GDK(0xffffff),
};
static const GdkRGBA gruvbox_colors[] = {
    CLR_GDK(0x282828),
    CLR_GDK(0xcc241d),
    CLR_GDK(0x98971a),
    CLR_GDK(0xd79921),
    CLR_GDK(0x458588),
    CLR_GDK(0xb16286),
    CLR_GDK(0x689d6a),
    CLR_GDK(0xa89984),
    CLR_GDK(0x928374),
    CLR_GDK(0xfb4934),
    CLR_GDK(0xb8bb26),
    CLR_GDK(0xfabd2f),
    CLR_GDK(0x83a598),
    CLR_GDK(0xd3869b),
    CLR_GDK(0x8ec07c),
    CLR_GDK(0xebdbb2),
};

/* COLOR SETTINGS */
/* static const GdkRGBA foreground = CLR_GDK(0xebdbb2); */
/* static const GdkRGBA background = CLR_GDK_ALPHA(0x282828, 0.85); */
static const ColorScheme *colorscheme = &clrscm_gruvbox;

