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

