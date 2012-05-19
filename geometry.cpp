/* 
 * File:   geometry.cpp
 * Author: freeday
 *
 * Created on 17 Апрель 2011 г., 14:21
 */

#include <vector>

#include "src/MainWindow.h"
#include <gtkmm/application.h>

#ifdef WIN32
#include <windows.h>
#endif

static gboolean delete_event( GtkWidget *widget, GdkEvent  *event,
                              gpointer   data )
{
    g_print ("delete event occurred\n");
    return FALSE;
}

void calculate_button_click(GtkWidget *widget, CShape* pShape)
{
    pShape->calculate();
}



int main( int   argc, char *argv[] )
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.geometry");

    MainWindow appwindow;

    return app->run(appwindow);
}
