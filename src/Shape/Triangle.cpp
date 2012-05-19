/* 
 * File:   Triangle.cpp
 * Author: freeday
 * 
 * Created on 17 Апрель 2011 г., 14:46
 */

#include <glib-2.0/glib/gmessages.h>

#include "Triangle.h"

CTriangle::CTriangle() {
}

CTriangle::CTriangle(const CTriangle& orig) {
}

CTriangle::~CTriangle() {
}

bool CTriangle::isImplemented() {
    return true;
}

int CTriangle::getShapeFieldsCount() {
    return 6;
}

std::string CTriangle::getLabelForShapeField(int iVertex) {
    std::string strings[] = {
        "Угол A (α)",
        "Угол B (β)",
        "Угол C (γ)",
        "Длина BC (a)",
        "Длина AC (b)",
        "Длина AB (c)"
    };
    return strings[iVertex];
}

std::string CTriangle::getName() {
    return "Треугольник";
}

void CTriangle::calculate() {
    switch(getVariables()) {
        case BY_SIDES:
            float fltPPerimeter;
            fltPPerimeter = (fltSideA + fltSideB + fltSideC) / 2;
            fltSquare = sqrt(fltPPerimeter
                    * (fltPPerimeter - fltSideA)
                    * (fltPPerimeter - fltSideB)
                    * (fltPPerimeter - fltSideC));
            fltCornerA = acos((pow(fltSideB, 2)
                    + pow(fltSideC, 2) - pow(fltSideA, 2))
                    /(2*fltSideB*fltSideC)) * 180.0 / M_PI;
            fltCornerB = acos((pow(fltSideA, 2)
                    + pow(fltSideC, 2) - pow(fltSideB, 2))
                    /(2*fltSideA*fltSideC)) * 180.0 / M_PI;
            fltCornerC = 180 - fltCornerA - fltCornerB;

            vDateFields.at(0)->setFloat(fltCornerA);
            vDateFields.at(1)->setFloat(fltCornerB);
            vDateFields.at(2)->setFloat(fltCornerC);
            break;
        case BY_AC_BC_AND_C:
            fltSquare = squareBySidesAndCorner(&fltSideA, &fltSideB, &fltSideC,
                    &fltCornerA, &fltCornerB, &fltCornerC);
            
            vDateFields.at(0)->setFloat(fltCornerA);
            vDateFields.at(1)->setFloat(fltCornerB);
            vDateFields.at(5)->setFloat(fltSideC);
            break;
        case BY_AB_BC_AND_B:
            fltSquare = squareBySidesAndCorner(&fltSideA, &fltSideC, &fltSideB,
                    &fltCornerA, &fltCornerC, &fltCornerB);
            
            vDateFields.at(0)->setFloat(fltCornerA);
            vDateFields.at(2)->setFloat(fltCornerC);
            vDateFields.at(4)->setFloat(fltSideB);
            break;
        case BY_AB_AC_AND_A:
            fltSquare = squareBySidesAndCorner(&fltSideB, &fltSideC, &fltSideA,
                    &fltCornerB, &fltCornerC, &fltCornerA);
            
            vDateFields.at(1)->setFloat(fltCornerB);
            vDateFields.at(2)->setFloat(fltCornerC);
            vDateFields.at(3)->setFloat(fltSideA);
            break;
        case BY_BC_AND_B_C:
            fltSquare = squareByCornersAndSide(&fltCornerA, &fltCornerB, &fltCornerC,
                    &fltSideA, &fltSideB, &fltSideC);

            vDateFields.at(0)->setFloat(fltCornerA);
            vDateFields.at(4)->setFloat(fltSideB);
            vDateFields.at(5)->setFloat(fltSideC);
            break;
        case BY_AC_AND_A_C:
            fltSquare = squareByCornersAndSide(&fltCornerB, &fltCornerC, &fltCornerA,
                    &fltSideB, &fltSideC, &fltSideA);

            vDateFields.at(1)->setFloat(fltCornerB);
            vDateFields.at(3)->setFloat(fltSideA);
            vDateFields.at(5)->setFloat(fltSideC);
            break;
        case BY_AB_AND_A_B:
            fltSquare = squareByCornersAndSide(&fltCornerC, &fltCornerA, &fltCornerB,
                    &fltSideC, &fltSideA, &fltSideB);

            vDateFields.at(2)->setFloat(fltCornerC);
            vDateFields.at(3)->setFloat(fltSideA);
            vDateFields.at(4)->setFloat(fltSideB);
            break;
        default:
            msgBoxEmptyFields();
            return;
    }
    fltPerimeter = fltSideA + fltSideB + fltSideC;
    vDateFields.at(6)->setFloat(fltPerimeter);
    vDateFields.at(7)->setFloat(fltSquare);
}

int CTriangle::getVariables() {
    fltCornerA = vDateFields.at(0)->getFloat();
    fltCornerB = vDateFields.at(1)->getFloat();
    fltCornerC = vDateFields.at(2)->getFloat();
    fltSideA = vDateFields.at(3)->getFloat();
    fltSideB = vDateFields.at(4)->getFloat();
    fltSideC = vDateFields.at(5)->getFloat();
    
    if (fltSideA > 0 && fltSideB > 0 && fltSideC > 0) {
        return BY_SIDES;
    }
    if (fltSideA > 0 && fltSideB > 0 && fltCornerC > 0) {
        return BY_AC_BC_AND_C;
    }
    if (fltSideA > 0 && fltSideC > 0 && fltCornerB > 0) {
        return BY_AB_BC_AND_B;
    }
    if (fltSideB > 0 && fltSideC > 0 && fltCornerA > 0) {
        return BY_AB_AC_AND_A;
    }
    if (fltSideA > 0 && fltCornerB > 0 && fltCornerC > 0) {
        return BY_BC_AND_B_C;
    }
    if (fltSideB > 0 && fltCornerA > 0 && fltCornerC > 0) {
        return BY_AC_AND_A_C;
    }
    if (fltSideC > 0 && fltCornerA > 0 && fltCornerB > 0) {
        return BY_AB_AND_A_B;
    }
    return ERROR;
}

float CTriangle::squareBySidesAndCorner(float* sideA, float* sideB, float* sideC,
        float* cornerA, float* cornerB, float* cornerC) {
    *sideC = sqrt(pow(*sideA, 2) + pow(*sideB, 2)
            - 2 * (*sideA) * (*sideB) * cos((*cornerC) * M_PI / 180));
    *cornerA = acos((pow(*sideB, 2)
            + pow((*sideC), 2) - pow((*sideA), 2))
            /(2 * (*sideB) * (*sideC))) * 180.0 / M_PI;
    *cornerB = 180 - (*cornerA) - (*cornerC);
    
    return ((*sideA) * (*sideB) * sin((*cornerC) * M_PI / 180))/2;
}

float CTriangle::squareByCornersAndSide(float* cornerA, float* cornerB, float* cornerC,
        float* sideA, float* sideB, float* sideC) {
    *sideB = ((*sideA) * sin((*cornerB) * M_PI / 180)) / 
            sin(((*cornerB) + (*cornerC)) * M_PI / 180);
    *sideC = sqrt(pow(*sideA, 2) + pow(*sideB, 2)
            - 2 * (*sideA) * (*sideB) * cos((*cornerC) * M_PI / 180));
    *cornerA = 180 - (*cornerB) - (*cornerC);
    
    return ((*sideA) * (*sideB) * sin((*cornerC) * M_PI / 180))/2;
}

void CTriangle::draw(CCanvas& canvas) {
    int x1 = 10, x2 = 90, x3 = 55;
    int y1 = 90, y2 = 85, y3 = 10;
    canvas.line(x1, y1, x2, y2);
    canvas.line(x1, y1, x3, y3);
    canvas.line(x2, y2, x3, y3);
    
    canvas.text((x1 - 5), (y1 + 5), "A");
    canvas.text((x2 + 2), (y2 + 5), "B");
    canvas.text((x3 - 2), (y3 - 2), "C");
    canvas.text(((x2 - x3) / 2 + x3 + 3), ((y2 - y3) / 2 + y3 + 2), "a");
    canvas.text(((x3 - x1) / 2 + x1 - 6), ((y1 - y3) / 2 + y3 + 2), "b");
    canvas.text(((x2 - x1) / 2 + x1), ((y1 - y2) / 2 + y2 + 6), "c");
    
    canvas.arc(x1, y1, 10,
            (360 - atan(1.0 * (y1-y3)/(x3-x1)) * 180 / M_PI),
            (360 - atan(1.0 * (y1-y2)/(x2-x1)) * 180 / M_PI));
    canvas.text((x1 + 11), (y1 - 6), "α");

    canvas.arc(x2, y2, 8,
            (atan(1.0 * (x2-x1)/(y1-y2)) * 180 / M_PI + 90),
            (atan(1.0 * (y2-y3)/(x2-x3)) * 180 / M_PI + 180));
    canvas.arc(x2, y2, 10,
            (atan(1.0 * (x2-x1)/(y1-y2)) * 180 / M_PI + 90),
            (atan(1.0 * (y2-y3)/(x2-x3)) * 180 / M_PI + 180));
    canvas.text((x2 - 15), (y2 - 6), "β");
    
    canvas.arc(x3, y3, 8,
            (atan(1.0 * (y2-y3)/(x2-x3)) * 180 / M_PI),
            (180 - atan(1.0 * (y1-y3)/(x3-x1)) * 180 / M_PI));
    canvas.arc(x3, y3, 10,
            (atan(1.0 * (y2-y3)/(x2-x3)) * 180 / M_PI),
            (180 - atan(1.0 * (y1-y3)/(x3-x1)) * 180 / M_PI));
    canvas.arc(x3, y3, 12,
            (atan(1.0 * (y2-y3)/(x2-x3)) * 180 / M_PI),
            (180 - atan(1.0 * (y1-y3)/(x3-x1)) * 180 / M_PI));
    canvas.text((x3 - 2), (y3 + 18), "γ");
}
