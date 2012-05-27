/* 
 * File:   MainWindow.h
 * Author: freeday
 *
 * Created on 13 Май 2011 г., 11:20
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <vector>
#include <gtkmm.h>
#include "Shape.h"
#include "ShapeWindow.h"

class MainWindow: public Gtk::Window {
public:
    MainWindow();
	MainWindow(BaseObjectType*, const Glib::RefPtr<Gtk::Builder>&);
    virtual ~MainWindow();
protected:
    void onShapeButtonClick(int);

	Glib::RefPtr<Gtk::Builder> m_refBuilder;
    std::vector<Gtk::Button*> m_pvShapeButtons;
    Gtk::ButtonBox* m_pShapeButtonBox;
private:
	
    ShapeWindow* shapeWindow;
};

#endif	/* MAINWINDOW_H */

