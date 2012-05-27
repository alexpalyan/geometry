/* 
 * File:   CCanvas.h
 * Author: freeday
 *
 * Created on September 4, 2011, 10:22 AM
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

