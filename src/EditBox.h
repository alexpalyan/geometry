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
#include <gtkmm.h>

class CEditBox: public Gtk::Box {
public:
    CEditBox();
    CEditBox(const CEditBox& orig);
    virtual ~CEditBox();
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

