#include <gtk/gtk.h>

// This sample is for showing layout with GtkGrid
static void activate (GtkApplication *app, gpointer data) {
    GtkWindow *window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Boxes layout");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 50);

    // This is the grid container
    GtkGrid *grid = gtk_grid_new ();
    gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (grid));

    GtkButton *button1 = gtk_button_new_with_label ("Button 1");
    gtk_grid_attach (GTK_GRID (grid), GTK_WIDGET (button1), 0, 0, 1, 1);

    GtkButton *button2 = gtk_button_new_with_label ("Button 2");
    gtk_grid_attach (GTK_GRID (grid), GTK_WIDGET (button2), 1, 0, 2, 1);

    GtkButton *button3 = gtk_button_new_with_label ("Button 3");
    gtk_grid_attach_next_to (GTK_GRID (grid), GTK_WIDGET (button3), GTK_WIDGET (button1), GTK_POS_BOTTOM, 1, 2);

    GtkButton *button4 = gtk_button_new_with_label ("Button 4");
    gtk_grid_attach_next_to (GTK_GRID (grid), GTK_WIDGET (button4), GTK_WIDGET (button3), GTK_POS_RIGHT, 2, 1);

    GtkButton *button5 = gtk_button_new_with_label ("Button 5");
    gtk_grid_attach (GTK_GRID (grid), GTK_WIDGET (button5), 1, 2, 1, 1);

    GtkButton *button6 = gtk_button_new_with_label ("Button 6");
    gtk_grid_attach_next_to (GTK_GRID (grid), GTK_WIDGET (button6), GTK_WIDGET (button5), GTK_POS_RIGHT, 1, 1);

    gtk_widget_show_all (GTK_WIDGET (window));
}

int main (int argc, char **argv) {
    GtkApplication *application = gtk_application_new ("org.gtk.sample.layout.grid2", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (application, "activate", G_CALLBACK (activate), NULL);

    int status = g_application_run (G_APPLICATION(application), argc, argv);
    g_object_unref (application);

    return status;
}

