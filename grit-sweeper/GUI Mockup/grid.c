#include <gtk/gtk.h>

static void 
on_click (GtkWidget *widget,
             gpointer   data)
{
	gtk_widget_set_sensitive (widget, FALSE);
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button2;
	GtkWidget *grid;


	GdkPixbuf *pixBufUpdate = gdk_pixbuf_new_from_file ("./assets/grass.jpg", NULL);
	pixBufUpdate = gdk_pixbuf_scale_simple(pixBufUpdate, 100,70,GDK_INTERP_BILINEAR);

	GtkWidget *image = gtk_image_new_from_pixbuf(pixBufUpdate);

	//window
	window = gtk_application_window_new (app);
	gtk_window_set_title (GTK_WINDOW (window), "GritSweeper");
	gtk_window_set_default_size (GTK_WINDOW (window), 1200, 800);

	//button grid
	grid = gtk_grid_new ();
	gtk_grid_set_row_homogeneous (GTK_GRID (grid), TRUE);
	gtk_grid_set_column_homogeneous (GTK_GRID (grid), TRUE);
	gtk_container_add (GTK_CONTAINER (window), grid);

	GtkAllocation* alloc = g_new(GtkAllocation, 1);
    gtk_widget_get_allocation(image, alloc);


	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++) {
			button = gtk_button_new();

			gtk_grid_attach (GTK_GRID (grid), button, i, j, 1, 1);

		    g_signal_connect (button, "clicked", G_CALLBACK (on_click), NULL);
			image = gtk_image_new_from_pixbuf(pixBufUpdate);
			gtk_button_set_image (GTK_BUTTON (button), image);

		}
	}

	gtk_widget_show_all (window);
}

int
main (int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	return status;
}
