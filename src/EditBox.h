/* 
 * File:   EditBox.h
 * Author: freeday
 *
 * Created on 23 Апрель 2011 г., 6:52
 */

#ifndef EDITBOX_H
#define	EDITBOX_H

#include <vector>
#include <string>
#include <gtkmm/fixed.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>

class CEditBox {
public:
    CEditBox();
    CEditBox(const CEditBox& orig);
    virtual ~CEditBox();
    void setWidgetSize(int, int, int);
    void putToContainer(Gtk::Fixed&, int, int);
    void setText(std::string);
    void setLabel(std::string);
    std::string getText();
    float getFloat();
    void setFloat(float);
    int getInt();
    void setInt(int);
private:
    Gtk::Entry editbox;
    Gtk::Label label;
};

#endif	/* EDITBOX_H */

