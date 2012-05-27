/* 
 * File:   ShapeWindow.h
 * Author: freeday
 *
 * Created on 13 Май 2011 г., 11:21
 */

#ifndef SHAPEWINDOW_H
#define	SHAPEWINDOW_H

#include <vector>
#include <ostream>

#include <gtkmm.h>

#include "Shape.h"
#include "EditBox.h"

class ShapeWindow: public Gtk::Window {
public:
    ShapeWindow();
    ShapeWindow(BaseObjectType*, const Glib::RefPtr<Gtk::Builder>&);
    virtual ~ShapeWindow();
protected:
    void onCalculateButtonClick();
    void onShow();
	
	Glib::RefPtr<Gtk::Builder> m_refBuilder;
	Gtk::Button* m_pCalculateButton;
	Gtk::Box* m_pFieldsBox;
	CCanvas* m_pCanvas;
private:
    CShape* pShape;
    std::vector<CEditBox*> dateFields;
};

#endif	/* SHAPEWINDOW_H */

