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


#include "Circle.h"

CCircle::CCircle() {
}

CCircle::CCircle(const CCircle& orig) {
}

CCircle::~CCircle() {
}

bool CCircle::isImplemented() {
    return true;
}

int CCircle::getShapeFieldsCount() {
    return 2;
}

std::string CCircle::getLabelForShapeField(int iVertex) {
    std::string strings[] = {
        "Радиус R",
        "Диаметр D"
    };
    return strings[iVertex];
}

std::string CCircle::getName() {
    return "Круг";
}

void CCircle::calculate() {
    switch(getVariables()) {
        case BY_RADIUS:
            fltDiameter = fltRadius * 2;
            vDateFields.at(1)->setFloat(fltDiameter);
            break;
        case BY_DIAMETER:
            fltRadius = fltDiameter / 2;
            vDateFields.at(0)->setFloat(fltRadius);
            break;
        default:
            msgBoxEmptyFields();
            return;
    }

    fltPerimeter = fltDiameter * M_PI;
    fltSquare = M_PI * pow(fltRadius, 2);
    vDateFields.at(2)->setFloat(fltPerimeter);
    vDateFields.at(3)->setFloat(fltSquare);
}

int CCircle::getVariables() {
    fltRadius = vDateFields.at(0)->getFloat();
    fltDiameter = vDateFields.at(1)->getFloat();
    
    if (fltRadius > 0) {
        return BY_RADIUS;
    }
    
    if (fltDiameter > 0) {
        return BY_DIAMETER;
    }
    
    return ERROR;
}

void CCircle::draw(CCanvas& canvas) {
    double centerX = 50, centerY = 50, radius = 45;
    canvas.arc(centerX, centerY, radius, 0, 360);
    canvas.line(centerX, centerY,
            (centerX - radius * cos(45 * M_PI / 180)),
            (centerY + radius * sin(45 * M_PI / 180)));
    canvas.text((centerX - radius * cos(45 * M_PI / 180)/2 + 5),
            (centerY + radius * sin(45 * M_PI / 180)/2 + 5),
            "R");
}
