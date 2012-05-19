/* 
 * File:   MainWindow.cpp
 * Author: freeday
 * 
 * Created on 13 Май 2011 г., 11:20
 */

#include "MainWindow.h"
#include "ShapeWindow.h"

MainWindow::MainWindow()
{
    set_border_width(10);
    set_position(Gtk::WIN_POS_CENTER);
    set_default_size(215, 210);
    set_title("Geometry");

    add(buttonbox);
    
    int i;
    for (i = 0; i < CShape::getShapeCount(); i++) {
        buttons.push_back(new Gtk::Button(CShape::getShapeName(i+1).c_str()));
        buttons.at(i)->signal_clicked().connect( sigc::bind<int> (sigc::mem_fun( *this,
                &MainWindow::onShapeButtonClick), (i+1) ) );
        buttonbox.pack_end(*buttons.at(i));
//        buttons.at(i)->show();
    }

    buttonbox.show_all();
}

MainWindow::MainWindow(const Glib::RefPtr<Gtk::Application>& application) {
//    Gtk::ApplicationWindow::ApplicationWindow(application);
}

MainWindow::~MainWindow() {
}

void MainWindow::onShapeButtonClick(int iShape) {
    CShape::setCurrentShape(iShape);
    shapeWindow.set_transient_for(*this);
    shapeWindow.set_position(Gtk::WIN_POS_CENTER_ON_PARENT);
    shapeWindow.set_modal(true);
    shapeWindow.show();
}
