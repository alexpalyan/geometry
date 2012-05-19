/* 
 * File:   Button.h
 * Author: freeday
 *
 * Created on September 1, 2011, 10:59 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include <gtk/gtk.h>
#include <string>

class Button {
public:
    Button();
    Button(const Button& orig);
    virtual ~Button();
    void putToContainer(GtkFixed*, int, int);
    void setLabel(std::string);
    void putToBoxStart(GtkBox*, bool, bool, int);
private:
    GtkWidget* pButton;
    
};

#endif	/* BUTTON_H */

