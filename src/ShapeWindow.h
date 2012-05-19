/* 
 * File:   ShapeWindow.h
 * Author: freeday
 *
 * Created on 13 Май 2011 г., 11:21
 */

#ifndef SHAPEWINDOW_H
#define	SHAPEWINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/enums.h>
#include <gtkmm/fixed.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/messagedialog.h>
#include <vector>
#include <ostream>

#include "Shape.h"
#include "EditBox.h"

class ShapeWindow: public Gtk::Window {
public:
    ShapeWindow();
    ShapeWindow(const ShapeWindow& orig);
    virtual ~ShapeWindow();
    void onCalculateButtonClick();
protected:
    void onShow();
private:
    Gtk::Button button;
    Gtk::Fixed frame;
    CCanvas canvas;
    CShape* pShape;
    std::vector<CEditBox*> dateFields;
    int buttons_x, buttons_y;
};

#endif	/* SHAPEWINDOW_H */

