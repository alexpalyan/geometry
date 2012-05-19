/* 
 * File:   Triangle.h
 * Author: freeday
 *
 * Created on 17 Апрель 2011 г., 14:46
 */

#ifndef TRIANGLE_H
#define	TRIANGLE_H

#include <math.h>
#include "../Shape.h"


class CTriangle: public CShape {
public:
    CTriangle();
    CTriangle(const CTriangle& orig);
    virtual ~CTriangle();

    int getShapeFieldsCount();
    void calculate();
    bool isImplemented();
    void draw(CCanvas&);
    std::string getName();
protected:
    std::string getLabelForShapeField(int);
private:
    int getVariables();

    float fltSideA;
    float fltSideB;
    float fltSideC;

    float fltCornerA;
    float fltCornerB;
    float fltCornerC;

    enum {
        BY_SIDES,
        BY_AC_BC_AND_C,
        BY_AB_BC_AND_B,
        BY_AB_AC_AND_A,
        BY_AB_AND_A_B,
        BY_AC_AND_A_C,
        BY_BC_AND_B_C,
        ERROR
    };
    
    float squareBySidesAndCorner(float*, float*, float*, float*, float*, float*);
    float squareByCornersAndSide(float*, float*, float*, float*, float*, float*);
};

#endif	/* TRIANGLE_H */

