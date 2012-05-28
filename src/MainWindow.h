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

