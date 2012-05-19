/* 
 * File:   CCanvas.cpp
 * Author: freeday
 * 
 * Created on September 4, 2011, 10:22 AM
 */

#include <string>

#include "Canvas.h"
#include "Shape.h"

CCanvas::CCanvas() {
    set_size_request(250, 200);
    signal_draw().connect(sigc::mem_fun( *this,
            &CCanvas::onDraw));
}

CCanvas::CCanvas(const CCanvas& orig) {
}

CCanvas::~CCanvas() {
}

void CCanvas::setShape(CShape *shape) {
    pShape = shape;
}

CShape* CCanvas::getShape() {
    return pShape;
}

bool CCanvas::onDraw(const Cairo::RefPtr<Cairo::Context>& cr) {
    Gtk::Allocation allocation = get_allocation();
    width = allocation.get_width();
    height = allocation.get_height();

    this->cr = Cairo::RefPtr<Cairo::Context>::cast_const(cr);

    cr->set_line_width(1);
    cr->set_font_size(14);

    int xc, yc;
    xc = width / 2;
    yc = height / 2;

    pShape->draw(*this);

    cr->stroke();

    return true;
}

void CCanvas::arc(double xc, double yc, double radius, double angle1, double angle2) {
    cr->save();
    cr->set_source_rgb(0, 0, 0);
    cr->arc(convertSizeX(xc), convertSizeY(yc), convertSizeY(radius),
            convertAngle(angle1), convertAngle(angle2));
    cr->restore();
    cr->stroke();
}

void CCanvas::line(double x1, double y1, double x2, double y2) {
    cr->save();
    cr->set_source_rgb(0, 0, 0);
    cr->move_to(convertSizeX(x1), convertSizeY(y1));
    cr->line_to(convertSizeX(x2), convertSizeY(y2));
    cr->restore();
    cr->stroke();
}

void CCanvas::text(double x, double y, std::string text) {
    cr->save();
    cr->set_source_rgb(0, 0, 0);
    cr->move_to(convertSizeX(x), convertSizeY(y));
    cr->show_text(text);
    cr->restore();
    cr->stroke();
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
