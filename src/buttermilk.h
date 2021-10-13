#ifndef BUTTERMILK_H
#define BUTTERMILK_H

/* MACROS */
#define LENGTH(X)               (sizeof X / sizeof X[0])

typedef struct {
    const char *id, *lname, *sname;
    int isflag, isset;
    char *description;
    char *value;
} Option;

/* FUNCTIONS */
static void child_ready(VteTerminal *terminal, GPid pid, GError *error, gpointer user_data);
static void clone_terminal(void);
static int parse_options(int argc, char *argv[]);
static void reset_font_size(VteTerminal *terminal);
static void set_font_size(VteTerminal *terminal, gint delta);
static gboolean on_key_press(GtkWidget *terminal,GdkEventKey *event, gpointer user_data);
static gboolean on_title_changed(GtkWidget *terminal, gpointer user_data);

#endif /* BUTTERMILK_H */
