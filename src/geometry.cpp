/* 
 * File:   geometry.cpp
 * Author: freeday
 *
 * Created on 17 Апрель 2011 г., 14:21
 */

#include <vector>
#include <iostream>

#include <gtkmm.h>

#include "config.h"

#include "MainWindow.h"

/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/ui/MainWindow.ui" */
#define UI_FILE "src/MainWindow.ui"


int main( int   argc, char *argv[] )
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.apmpc.geometry");

	//Load the Glade file and instiate its widgets:
	Glib::RefPtr<Gtk::Builder> builder;
	try
	{
		builder = Gtk::Builder::create_from_file(UI_FILE);
	}
	catch (const Glib::FileError & ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	MainWindow* appwindow = 0;
	builder->get_widget_derived("MainWindow", appwindow);

    return app->run(*appwindow);
}
