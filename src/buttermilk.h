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
#define LENGTH(X)               (sizeof X / sizeof X[0])

typedef struct {
    const char *id, *lname, *sname;
    int isflag, isset;
    char *description;
    char *value;
} Option;

typedef struct {
    char *name;
    GdkRGBA foreground, background;
    const GdkRGBA *palette;
} ColorScheme;

static void child_ready(VteTerminal *terminal, GPid pid, GError *error, gpointer user_data);
static void reset_font_size(VteTerminal *terminal);
static void set_font_size(VteTerminal *terminal, gint delta);
static gboolean on_key_press(GtkWidget *terminal,GdkEventKey *event, gpointer user_data);
static gboolean on_title_changed(GtkWidget *terminal, gpointer user_data);
