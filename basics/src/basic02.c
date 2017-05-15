#include <gtk/gtk.h>

static void buttonClicked(GtkButton *button, gpointer data) {
    g_print ("Hello %s!\n", (char *) data);
}

static void activate (GtkApplication *app, gpointer data) {
    GtkWindow *window = gtk_application_window_new (app);
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
    gtk_window_set_title (GTK_WINDOW (window), "Hello!");

    GtkButton *button = gtk_button_new_with_label ("Hello World!");
    g_signal_connect (button, "clicked", G_CALLBACK (buttonClicked), "cristian");
    gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (button));

    gtk_widget_show_all (GTK_WIDGET (window));
}

int main (int argc, char **argv) {
    GtkApplication *application = gtk_application_new ("org.gtk.sample.basic.windows", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (application, "activate", G_CALLBACK (activate), NULL);

    int status = g_application_run (G_APPLICATION(application), argc, argv);
    g_object_unref (application);

    return status;
}

