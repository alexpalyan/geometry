/* 
 * File:   CCircle.h
 * Author: freeday
 *
 * Created on September 3, 2011, 9:11 PM
 */

#ifndef CCIRCLE_H
#define	CCIRCLE_H

#include <math.h>
#include "../Shape.h"
#include <gtkmm/messagedialog.h>

class CCircle: public CShape {
public:
    CCircle();
    CCircle(const CCircle& orig);
    virtual ~CCircle();

    int getShapeFieldsCount();
    void calculate();
    bool isImplemented();
    void draw(CCanvas&);
    std::string getName();
protected:
    std::string getLabelForShapeField(int);
private:
    int getVariables();
    
    float fltRadius;
    float fltDiameter;

    enum {
        BY_RADIUS,
        BY_DIAMETER,
        ERROR
    };
};

#endif	/* CCIRCLE_H */

