#include <gtk/gtk.h>

// This sample is for showing layout with GtkBoxes
static void activate (GtkApplication *app, gpointer data) {
    GtkWindow *window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Boxes layout");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 50);

    // This is the box container, horizontal layout and spacing of 6px
    GtkBox *box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 6);
    gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (box));

    // Let's reuse the same button!
    GtkButton *button = gtk_button_new_with_label ("Hello");
    gtk_box_pack_start (GTK_BOX (box), GTK_WIDGET (button), TRUE, TRUE, 0);

    button = gtk_button_new_with_label ("Goodbye");
    gtk_box_pack_start (GTK_BOX (box), GTK_WIDGET (button), TRUE, TRUE, 0);

    gtk_widget_show_all (GTK_WIDGET (window));
}

int main (int argc, char **argv) {
    GtkApplication *application = gtk_application_new ("org.gtk.sample.layout.boxes", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (application, "activate", G_CALLBACK (activate), NULL);

    int status = g_application_run (G_APPLICATION(application), argc, argv);
    g_object_unref (application);

    return status;
}