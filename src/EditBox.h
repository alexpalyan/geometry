/* 
 * This file is part of Geometry.
 *
 * Geometry is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Geometry is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Geometry.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright © 2012 Palyan Aleksander <freeday@apmpc.dp.ua>
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

