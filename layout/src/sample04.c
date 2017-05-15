#include <gtk/gtk.h>

// This sample is for showing layout with GtkGrid
static void activate (GtkApplication *app, gpointer data) {
    GtkWindow *window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Boxes layout");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 50);

    // This is the grid container
    GtkGrid *grid = gtk_grid_new ();
    gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (grid));

    GtkButton *button = gtk_button_new_with_label ("Button 1");
    gtk_grid_attach (GTK_GRID (grid), GTK_WIDGET (button), 0, 0, 1, 1);

    button = gtk_button_new_with_label ("Button 2");
    gtk_grid_attach (GTK_GRID (grid), GTK_WIDGET (button), 1, 0, 3, 1);

    button = gtk_button_new_with_label ("Button 3");
    gtk_grid_attach (GTK_GRID (grid), GTK_WIDGET (button), 0, 1, 1, 2);

    button = gtk_button_new_with_label ("Button 4");
    gtk_grid_attach (GTK_GRID (grid), GTK_WIDGET (button), 1, 1, 3, 1);

    button = gtk_button_new_with_label ("Button 5");
    gtk_grid_attach (GTK_GRID (grid), GTK_WIDGET (button), 2, 2, 1, 1);

    button = gtk_button_new_with_label ("Button 6");
    gtk_grid_attach (GTK_GRID (grid), GTK_WIDGET (button), 3, 2, 1, 1);

    gtk_widget_show_all (GTK_WIDGET (window));
}

int main (int argc, char **argv) {
    GtkApplication *application = gtk_application_new ("org.gtk.sample.layout.grid", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (application, "activate", G_CALLBACK (activate), NULL);

    int status = g_application_run (G_APPLICATION(application), argc, argv);
    g_object_unref (application);

    return status;
}
