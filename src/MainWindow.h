/* 
 * File:   MainWindow.h
 * Author: freeday
 *
 * Created on 13 Май 2011 г., 11:20
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/applicationwindow.h>
#include <gtkmm/button.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/enums.h>
#include <vector>
#include "Shape.h"
#include "ShapeWindow.h"

class MainWindow: public Gtk::Window {
public:
    MainWindow();
    MainWindow(const Glib::RefPtr<Gtk::Application>& application);
    virtual ~MainWindow();
    void onShapeButtonClick(int);
private:
    std::vector<Gtk::Button*> buttons;
    Gtk::VButtonBox buttonbox;
    ShapeWindow shapeWindow;
};

#endif	/* MAINWINDOW_H */

