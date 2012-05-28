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


#include <string>

#include "Canvas.h"
#include "Shape.h"

CCanvas::CCanvas() {
}

CCanvas::CCanvas(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder)
: Gtk::DrawingArea (cobject),
  m_refBuilder (refBuilder)
{
    signal_draw().connect(sigc::mem_fun( *this,
            &CCanvas::onDraw));
}

CCanvas::~CCanvas() {
}

void CCanvas::setShape(CShape *shape) {
    pShape = shape;
}

CShape* CCanvas::getShape() {
    return pShape;
}

bool CCanvas::onDraw(const Cairo::RefPtr<Cairo::Context>& cr)
//: m_refCrContext(cr)
{
    Gtk::Allocation allocation = get_allocation();
    width = allocation.get_width();
    height = allocation.get_height();

    m_refCrContext = Cairo::RefPtr<Cairo::Context>::cast_const(cr);

    m_refCrContext->set_line_width(1);
    m_refCrContext->set_font_size(14);

    int xc, yc;
    xc = width / 2;
    yc = height / 2;

    pShape->draw(*this);

//    m_refCrContext->stroke();

    return true;
}

void CCanvas::arc(double xc, double yc, double radius, double angle1, double angle2) {
    m_refCrContext->save();
    m_refCrContext->set_source_rgb(0, 0, 0);
    m_refCrContext->arc(convertSizeX(xc), convertSizeY(yc), convertSizeY(radius),
            convertAngle(angle1), convertAngle(angle2));
    m_refCrContext->restore();
    m_refCrContext->stroke();
}

void CCanvas::line(double x1, double y1, double x2, double y2) {
    m_refCrContext->save();
    m_refCrContext->set_source_rgb(0, 0, 0);
    m_refCrContext->move_to(convertSizeX(x1), convertSizeY(y1));
    m_refCrContext->line_to(convertSizeX(x2), convertSizeY(y2));
    m_refCrContext->restore();
    m_refCrContext->stroke();
}

void CCanvas::text(double x, double y, std::string text) {
    m_refCrContext->save();
    m_refCrContext->set_source_rgb(0, 0, 0);
    m_refCrContext->move_to(convertSizeX(x), convertSizeY(y));
    m_refCrContext->show_text(text);
    m_refCrContext->restore();
    m_refCrContext->stroke();
}

double CCanvas::convertAngle(double angle) {
    return angle * M_PI / 180;
}

double CCanvas::convertSizeX(double x) {
    return (height * x / 100) + (width - height) / 2;
}

double CCanvas::convertSizeY(double y) {
    return height * y / 100;
}
