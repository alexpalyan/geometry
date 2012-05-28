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

