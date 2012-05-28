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


#ifndef CCANVAS_H
#define	CCANVAS_H

#include <cairo.h>
#include <math.h>
#include <string>
#include <gtkmm.h>

class CShape;

class CCanvas: public Gtk::DrawingArea {
public:
    CCanvas();
    CCanvas(BaseObjectType*, const Glib::RefPtr<Gtk::Builder>&);
    virtual ~CCanvas();
    void setShape(CShape*);
    CShape* getShape();
    void arc(double, double, double, double, double);
    void line(double, double, double, double);
    void text(double, double, std::string);
    
protected:
    virtual bool onDraw(const Cairo::RefPtr<Cairo::Context>&);
    
	Glib::RefPtr<Gtk::Builder> m_refBuilder;
    Cairo::RefPtr<Cairo::Context> m_refCrContext;
private:
    CShape* pShape;
    int width;
    int height;
    double convertAngle(double);
    double convertSizeX(double);
    double convertSizeY(double);
};

#endif	/* CCANVAS_H */

