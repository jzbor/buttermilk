#ifndef COLORS_H
#define COLORS_H

#define PALETTE_SIZE 16

/* MACROS */
#define CLR_R(X)                (((X) & 0xff0000) >> 16)
#define CLR_G(X)                (((X) & 0x00ff00) >>  8)
#define CLR_B(X)                (((X) & 0x0000ff) >>  0)
#define CLR_16(X)               ((double)(X) / 0xff)
#define CLR_GDK(X)              (const GdkRGBA){ .red = CLR_16(CLR_R(X)), \
                                    .green = CLR_16(CLR_G(X)), \
                                    .blue = CLR_16(CLR_B(X)), \
                                    .alpha = 0 }
#define CLR_GDK_ALPHA(X, A)     (const GdkRGBA){ .red = CLR_16(CLR_R(X)), \
                                    .green = CLR_16(CLR_G(X)), \
                                    .blue = CLR_16(CLR_B(X)), \
                                    .alpha = (A) }

/* STRUCTS */
typedef struct {
    char *name;
    GdkRGBA foreground, background;
    const GdkRGBA *palette;
} ColorScheme;

/* COLOR SCHEMES */
static const GdkRGBA gruvbox_palette[PALETTE_SIZE] = {
    {0.156863, 0.156863, 0.156863, 1.000000},
    {0.800000, 0.141176, 0.113725, 1.000000},
    {0.596078, 0.592157, 0.101961, 1.000000},
    {0.843137, 0.600000, 0.129412, 1.000000},
    {0.270588, 0.521569, 0.533333, 1.000000},
    {0.694118, 0.384314, 0.525490, 1.000000},
    {0.407843, 0.615686, 0.415686, 1.000000},
    {0.658824, 0.600000, 0.517647, 1.000000},
    {0.572549, 0.513725, 0.454902, 1.000000},
    {0.984314, 0.286275, 0.203922, 1.000000},
    {0.721569, 0.733333, 0.149020, 1.000000},
    {0.980392, 0.741176, 0.184314, 1.000000},
    {0.513725, 0.647059, 0.596078, 1.000000},
    {0.827451, 0.525490, 0.607843, 1.000000},
    {0.556863, 0.752941, 0.486275, 1.000000},
    {0.921569, 0.858824, 0.698039, 1.000000},
};

static const GdkRGBA tango_palette[PALETTE_SIZE] = {
    {0,        0,        0,        1},
    {0.8,      0,        0,        1},
    {0.305882, 0.603922, 0.023529, 1},
    {0.768627, 0.627451, 0,        1},
    {0.203922, 0.396078, 0.643137, 1},
    {0.458824, 0.313725, 0.482353, 1},
    {0.0235294,0.596078, 0.603922, 1},
    {0.827451, 0.843137, 0.811765, 1},
    {0.333333, 0.341176, 0.32549,  1},
    {0.937255, 0.160784, 0.160784, 1},
    {0.541176, 0.886275, 0.203922, 1},
    {0.988235, 0.913725, 0.309804, 1},
    {0.447059, 0.623529, 0.811765, 1},
    {0.678431, 0.498039, 0.658824, 1},
    {0.203922, 0.886275, 0.886275, 1},
    {0.933333, 0.933333, 0.92549,  1}
};

static const GdkRGBA linux_palette[PALETTE_SIZE] = {
    {0,        0,        0,        1},
    {0.666667, 0,        0,        1},
    {0,        0.666667, 0,        1},
    {0.666667, 0.333333, 0,        1},
    {0,        0,        0.666667, 1},
    {0.666667, 0,        0.666667, 1},
    {0,        0.666667, 0.666667, 1},
    {0.666667, 0.666667, 0.666667, 1},
    {0.333333, 0.333333, 0.333333, 1},
    {1,        0.333333, 0.333333, 1},
    {0.333333, 1,        0.333333, 1},
    {1,        1,        0.333333, 1},
    {0.333333, 0.333333, 1,        1},
    {1,        0.333333, 1,        1},
    {0.333333, 1,        1,        1},
    {1,        1,        1,        1}
};

static const GdkRGBA solarized_palette[PALETTE_SIZE] = {
    {0.027451, 0.211765, 0.258824, 1}, // 0 base02
    {0.862745, 0.196078, 0.184314, 1}, // 1 red
    {0.521569, 0.600000, 0.000000, 1}, // 2 green
    {0.709804, 0.537255, 0.000000, 1}, // 3 yellow
    {0.149020, 0.545098, 0.823529, 1}, // 4 blue
    {0.827451, 0.211765, 0.509804, 1}, // 5 magenta
    {0.164706, 0.631373, 0.596078, 1}, // 6 cyan
    {0.933333, 0.909804, 0.835294, 1}, // 7 base2
    {0.000000, 0.168627, 0.211765, 1}, // 8 base03 (bg)
    {0.796078, 0.294118, 0.086275, 1}, // 9 orange
    {0.345098, 0.431373, 0.458824, 1}, // 10 base01
    {0.396078, 0.482353, 0.513725, 1}, // 11 base00
    {0.513725, 0.580392, 0.588235, 1}, // 12 base0 (fg)
    {0.423529, 0.443137, 0.768627, 1}, // 13 violet
    {0.576471, 0.631373, 0.631373, 1}, // 14 base1
    {0.992157, 0.964706, 0.890196, 1}  // 15 base3
};

static const GdkRGBA nord_palette[PALETTE_SIZE] = {
    {0.0, 0.0, 0.0234375, 1.0},
    {0.74609375, 0.37890625, 0.4140625, 1.0},
    {0.63671875, 0.7421875, 0.546875, 1.0},
    {0.91796875, 0.79296875, 0.54296875, 1.0},
    {0.50390625, 0.62890625, 0.75390625, 1.0},
    {0.703125, 0.5546875, 0.67578125, 1.0},
    {0.53125, 0.75, 0.8125, 1.0},
    {0.89453125, 0.91015625, 0.9375, 1.0},
    {0.296875, 0.3359375, 0.4140625, 1.0},
    {0.74609375, 0.37890625, 0.4140625, 1.0},
    {0.63671875, 0.7421875, 0.546875, 1.0},
    {0.91796875, 0.79296875, 0.54296875, 1.0},
    {0.50390625, 0.62890625, 0.75390625, 1.0},
    {0.703125, 0.5546875, 0.67578125, 1.0},
    {0.55859375, 0.734375, 0.73046875, 1.0},
    {0.921875, 0.93359375, 0.953125, 1.0},
};


static const GdkRGBA xterm_palette[PALETTE_SIZE] = {
    {0,        0,        0,        1},
    {0.803922, 0,        0,        1},
    {0,        0.803922, 0,        1},
    {0.803922, 0.803922, 0,        1},
    {0.117647, 0.564706, 1,        1},
    {0.803922, 0,        0.803922, 1},
    {0,        0.803922, 0.803922, 1},
    {0.898039, 0.898039, 0.898039, 1},
    {0.298039, 0.298039, 0.298039, 1},
    {1,        0,        0,        1},
    {0,        1,        0,        1},
    {1,        1,        0,        1},
    {0.27451,  0.509804, 0.705882, 1},
    {1,        0,        1,        1},
    {0,        1,        1,        1},
    {1,        1,        1,        1}
};

static const GdkRGBA rxvt_palette[PALETTE_SIZE] = {
    {0,        0,        0,        1 },
    {0.803921, 0,        0,        1 },
    {0,        0.803921, 0,        1 },
    {0.803921, 0.803921, 0,        1 },
    {0,        0,        0.803921, 1 },
    {0.803921, 0,        0.803921, 1 },
    {0,        0.803921, 0.803921, 1 },
    {0.980392, 0.921568, 0.843137, 1 },
    {0.250980, 0.250980, 0.250980, 1 },
    {1,        0,        0,        1 },
    {0,        1,        0,        1 },
    {1,        1,        0,        1 },
    {0,        0,        1,        1 },
    {1,        0,        1,        1 },
    {0,        1,        1,        1 },
    {1,        1,        1,        1 }
};

static const ColorScheme clrscm_solarized   = { "solarized", solarized_palette[15], solarized_palette[0], solarized_palette };
static const ColorScheme clrscm_tango       = { "tango",     tango_palette[15], tango_palette[0], tango_palette };
static const ColorScheme clrscm_gruvbox     = { "gruvbox",   gruvbox_palette[15], gruvbox_palette[0], gruvbox_palette };
static const ColorScheme clrscm_nord        = { "nord",      nord_palette[15], nord_palette[0], nord_palette };
static const ColorScheme clrscm_xterm       = { "xterm",     xterm_palette[15], xterm_palette[0], xterm_palette };
static const ColorScheme clrscm_linux       = { "linux",     linux_palette[15], linux_palette[0], linux_palette };
static const ColorScheme clrscm_rxvt        = { "rxvt",      rxvt_palette[15], rxvt_palette[0], rxvt_palette };



/*
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
*/
#endif /* COLORS_H */
