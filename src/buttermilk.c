#include <vte/vte.h>
#include "buttermilk.h"
#include "colors.h"
#include "config.h"

/* OPTIONS */
#define PARAM_HELP          0
#define PARAM_COMMAND       1
#define PARAM_WORKINGDIR    2
static Option options[] = {
    { .id = "help",       .lname = "--help",                .sname = "-h", .isflag = 1,
        .description = "print help" },
    { .id = "command",    .lname = "--execute",             .sname = "-e",
        .description = "execute command in terminal" },
    { .id = "workingdir", .lname = "--working-directory",   .sname = "-w",
        .description = "set working directory" },
};

void
child_ready(VteTerminal *terminal, GPid pid, GError *error, gpointer user_data)
{
    if (!terminal) return;
    if (pid == -1) gtk_main_quit();
}

void
clone_terminal(void)
{
    printf("@TODO implement");
}

gboolean
on_key_press(GtkWidget *terminal,GdkEventKey *event, gpointer user_data)
{
    switch (event->state & (GDK_CONTROL_MASK | GDK_SHIFT_MASK | GDK_MOD1_MASK)) {
        case GDK_CONTROL_MASK | GDK_SHIFT_MASK:
            switch(event->keyval) {
                case GDK_KEY_V:
                    vte_terminal_paste_clipboard(VTE_TERMINAL(terminal));
                    return TRUE;
                case GDK_KEY_C:
                    vte_terminal_copy_clipboard_format(VTE_TERMINAL(terminal), VTE_FORMAT_TEXT);
                    return TRUE;
                case GDK_KEY_plus:
                    set_font_size(VTE_TERMINAL(terminal), 1);
                    return TRUE;
            }
            break;
        case GDK_CONTROL_MASK:
            switch(event->keyval) {
                case GDK_KEY_minus:
                    set_font_size(VTE_TERMINAL(terminal), -1);
                    return TRUE;
                case GDK_KEY_equal:
                    reset_font_size(VTE_TERMINAL(terminal));
                    return TRUE;
                case GDK_KEY_Return:
                    clone_terminal();
                    return TRUE;
            }
            break;
        case GDK_SHIFT_MASK:
            break;
        case GDK_MOD1_MASK:
            break;
    }
    return FALSE;
}

gboolean
on_title_changed(GtkWidget *terminal, gpointer user_data)
{
    GtkWindow *window = user_data;
    const char *vte_title = vte_terminal_get_window_title(VTE_TERMINAL(terminal));
    char new_title[strlen(cfg_title) + strlen(vte_title) + 1];
    sprintf(new_title, cfg_title, vte_title);
    gtk_window_set_title(window, new_title);
    return TRUE;
}

int
parse_options(int argc, char *argv[])
{
    int i, j, matched;
    for (i = 1; i < argc; i++) {
        matched = 0;
        for (j = 0; j < LENGTH(options); j++) {
            if ((strcmp(argv[i], options[j].lname) == 0)
                    || (strcmp(argv[i], options[j].sname) == 0)) {
                if (options[j].isflag) {
                    options[j].isset = 1;
                    matched = 1;
                    break;
                } else if (i == argc - 1) {
                    fprintf(stderr, "Missing argument for option %s\n", argv[i]);
                    return 1;
                } else {
                    options[j].isset = 1;
                    options[j].value = argv[++i];
                    matched = 1;
                    break;
                }
            }
        }
        if (!matched) {
            fprintf(stderr, "Invalid parameter: '%s'\n", argv[i]);
            return 1;
        }
    }
    return 0;
}

void
print_help()
{
    char buffer[200] = {0};
    for (int i = 0; i < LENGTH(options); i++) {
        sprintf(buffer, "%s\t%s ", options[i].sname, options[i].lname);
        while (strlen(buffer) < 30)
            strcat(buffer, " ");
        printf("%s%s\n", buffer, options[i].description);
    }
}

void
reset_font_size(VteTerminal *terminal)
{
    /*
	PangoFontDescription *descr;
	if ((descr = pango_font_description_from_string(TERM_FONT)) == NULL)
		return;
	vte_terminal_set_font(terminal, descr);
	pango_font_description_free(descr);
    */
	vte_terminal_set_font(terminal, NULL);
}

void
set_font_size(VteTerminal *terminal, gint delta)
{
	PangoFontDescription *descr;
	if ((descr = pango_font_description_copy(vte_terminal_get_font(terminal))) == NULL)
		return;

	gint current = pango_font_description_get_size(descr);
	pango_font_description_set_size(descr, current + delta * PANGO_SCALE);
	vte_terminal_set_font(terminal, descr);
	pango_font_description_free(descr);
}

int
main(int argc, char *argv[])
{
    GtkWidget *window, *terminal;
    int status = 0;

    if ((status = parse_options(argc, argv)))
        return status;
    if (options[PARAM_HELP].isset) {
        print_help();
        return 0;
    }
    if (options[PARAM_WORKINGDIR].isset) {
        if ((status = chdir(options[PARAM_WORKINGDIR].value))) {
            fprintf(stderr, "Unable to set working directory to '%s'\n",
                    options[PARAM_WORKINGDIR].value);
            return status;
        }
    }

    /* Initialise GTK, the window and the terminal */
    gtk_init(&argc, &argv);
    terminal = vte_terminal_new();
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), cfg_default_title);

    /* Start a new shell */
    gchar **command;
    gchar *command0 = NULL;
    gchar **envp = g_get_environ();
    command = options[PARAM_COMMAND].isset ?
        (gchar *[]){"/bin/sh", "-c", command0 = g_strdup(options[PARAM_COMMAND].value), NULL} :
        (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")), NULL };
    g_strfreev(envp);
    vte_terminal_spawn_async(VTE_TERMINAL(terminal),
        VTE_PTY_DEFAULT,
        NULL,         /* working directory  */
        command,      /* command */
        NULL,         /* environment */
        0,            /* spawn flags */
        NULL, NULL,   /* child setup */
        NULL,         /* child pid */
        -1,           /* timeout */
        NULL,         /* cancellable */
        child_ready,  /* callback */
        NULL);        /* user_data */
    g_free(command0);

    /* Connect some signals */
    g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
    g_signal_connect(terminal, "child-exited", gtk_main_quit, NULL);
    g_signal_connect(terminal, "key-press-event", G_CALLBACK(on_key_press), GTK_WINDOW(window));
    g_signal_connect(terminal, "window-title-changed", G_CALLBACK(on_title_changed), GTK_WINDOW(window));

    /* Customize terminal */
    vte_terminal_set_colors(VTE_TERMINAL(terminal), &config.colorscheme->foreground,
            &config.colorscheme->background, config.colorscheme->palette, PALETTE_SIZE);
    vte_terminal_set_scrollback_lines(VTE_TERMINAL(terminal), config.scrollback_lines);
    vte_terminal_set_scroll_on_output(VTE_TERMINAL(terminal), config.scroll_output);
    vte_terminal_set_scroll_on_keystroke(VTE_TERMINAL(terminal), config.scroll_keys);
    vte_terminal_set_mouse_autohide(VTE_TERMINAL(terminal), config.hide_mouse);

    /* Put widgets together and run the main loop */
    gtk_container_add(GTK_CONTAINER(window), terminal);
    gtk_widget_show_all(window);
    gtk_main();

    return status;
}
