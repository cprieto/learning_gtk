#include <gtk/gtk.h>

static void activate (GtkApplication *app, gpointer data) {
    GtkWindow *window = GTK_WINDOW (gtk_application_window_new (app));
    gtk_window_set_title (GTK_WINDOW (window), "ListBox Demo");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    GtkBox *outer = GTK_BOX (gtk_box_new (GTK_ORIENTATION_VERTICAL, 6));
    gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (outer));

    GtkListBox *listBox = GTK_LIST_BOX (gtk_list_box_new ());
    gtk_list_box_set_selection_mode (GTK_LIST_BOX (listBox), GTK_SELECTION_NONE);
    gtk_box_pack_start (GTK_BOX (outer), GTK_WIDGET (listBox), TRUE, TRUE, 0);

    // Top 2 labels in the first row
    GtkBox *vbox = GTK_BOX (gtk_box_new (GTK_ORIENTATION_VERTICAL, 0));

    GtkLabel *label1 = GTK_LABEL (gtk_label_new ("Automatic Date & Time"));
    gtk_label_set_xalign (GTK_LABEL (label1), 0);
    gtk_box_pack_start (GTK_BOX (vbox), GTK_WIDGET (label1), TRUE, TRUE, 0);

    GtkLabel *label2 = GTK_LABEL (gtk_label_new ("Requires internet access"));
    gtk_label_set_xalign (GTK_LABEL (label2), 0);
    gtk_box_pack_start (GTK_BOX (vbox), GTK_WIDGET (label2), TRUE, TRUE, 0);

    GtkBox *hbox = GTK_BOX (gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 50));
    gtk_box_pack_start (GTK_BOX (hbox), GTK_WIDGET (vbox), TRUE, TRUE, 0);

    GtkListBoxRow *row = GTK_LIST_BOX_ROW (gtk_list_box_row_new ());
    gtk_container_add (GTK_CONTAINER (row), GTK_WIDGET (hbox));
    gtk_container_add (GTK_CONTAINER (listBox), GTK_WIDGET (row));


    // Switch in the top row
    GtkSwitch *onOff = GTK_SWITCH (gtk_switch_new ());
    gtk_widget_set_valign (GTK_WIDGET (onOff), GTK_ALIGN_CENTER);
    gtk_box_pack_start (GTK_BOX (hbox), GTK_WIDGET (onOff), FALSE, TRUE, 0);

    // Second row
    row = GTK_LIST_BOX_ROW (gtk_list_box_row_new ());
    hbox = GTK_BOX (gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 50));
    gtk_container_add (GTK_CONTAINER (row), GTK_WIDGET (hbox));
    gtk_container_add (GTK_CONTAINER (listBox), GTK_WIDGET (row));

    // Second row has a label and a checkbox
    GtkLabel *label = GTK_LABEL (gtk_label_new ("Enable automatic updates"));
    gtk_label_set_xalign (GTK_LABEL (label), 0);
    gtk_box_pack_start (GTK_BOX (hbox), GTK_WIDGET (label), TRUE, TRUE, 0);

    GtkCheckButton *check = GTK_CHECK_BUTTON (gtk_check_button_new ());
    gtk_box_pack_start (GTK_BOX (hbox), GTK_WIDGET (check), FALSE, TRUE, 0);

    // Third row
    row = GTK_LIST_BOX_ROW (gtk_list_box_row_new ());
    hbox = GTK_BOX (gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 50));
    gtk_container_add (GTK_CONTAINER (row), GTK_WIDGET (hbox));
    gtk_container_add (GTK_CONTAINER (listBox), GTK_WIDGET (row));

    // Third row has a label and a drop down list
    label = GTK_LABEL (gtk_label_new ("Date Format"));
    gtk_label_set_xalign (GTK_LABEL (label), 0);
    gtk_box_pack_start (GTK_BOX (hbox), GTK_WIDGET (label), TRUE, TRUE, 0);

    GtkComboBoxText *combo = GTK_COMBO_BOX_TEXT (gtk_combo_box_text_new ());
    gtk_combo_box_text_insert (GTK_COMBO_BOX_TEXT (combo), 0, "0", "24-hour");
    gtk_combo_box_text_insert (GTK_COMBO_BOX_TEXT (combo), 1, "1", "AM/PM");
    gtk_box_pack_start (GTK_BOX (hbox), GTK_WIDGET (combo), FALSE, TRUE, 0);

    // Now we create a new listbox
    GtkListBox *listBox2 = GTK_LIST_BOX (gtk_list_box_new ());
    gtk_box_pack_start (GTK_BOX (outer), GTK_WIDGET (listBox2), TRUE, TRUE, 0);

//    char **items = g_strsplit ("This is a sorted ListBox Fail", " ", -1);
//    for (int i = 0; i < 6; ++i) {
//        GtkListBoxRow *innerRow = GTK_LIST_BOX_ROW (gtk_list_box_row_new ());
//        g_object_set_data (G_OBJECT (innerRow), "data", items[i]);
//
//        GtkLabel *innerLabel = GTK_LABEL (gtk_label_new (items[i]));
//        gtk_container_add (GTK_CONTAINER (innerRow), GTK_WIDGET (innerLabel));
//        gtk_container_add (GTK_CONTAINER (listBox), GTK_WIDGET (innerRow));
//    }


    gtk_widget_show_all (GTK_WIDGET (window));
}

int main (int argc, char **argv) {
    GtkApplication *application = gtk_application_new ("org.gtk.sample.layout.listbox", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (application, "activate", G_CALLBACK (activate), NULL);

    int status = g_application_run (G_APPLICATION(application), argc, argv);
    g_object_unref (application);

    return status;
}

