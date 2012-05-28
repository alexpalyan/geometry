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


#include "Shape.h"

#include "Shape/Triangle.h"
#include "Shape/Parallelogram.h"
#include "Shape/Circle.h"

CShape::CShape() {
}

CShape::CShape(const CShape& orig) {
}

CShape::~CShape() {
}

int CShape::getShapeFieldsCount() {
}

std::string CShape::getLabelForShapeField(int iVertex) {
}

int CShape::getTextFieldsCount() {
    return getShapeFieldsCount() + 2;
}

std::string CShape::getLabelForTextField(int iTextField) {
    std::string strings[] = {"Периметр P", "Площадь S"};

    if(iTextField >= (getShapeFieldsCount() + 2)) {
        return "error";
    } else if (iTextField >= getShapeFieldsCount()) {
        iTextField -= getShapeFieldsCount();
        return strings[iTextField];
    } else {
        return getLabelForShapeField(iTextField);
    }
}

void CShape::calculate() {
}

void CShape::setDateFields(std::vector<CEditBox*> vNewDateFields) {
    vDateFields = vNewDateFields;
}

bool CShape::isImplemented() {
    return false;
}

int CShape::iShape;
std::vector<CShape*> CShape::shapes;

void CShape::initShapes() {
    if (!shapes.empty()) {
        return;
    }
    shapes.push_back(new CTriangle());
    shapes.push_back(new CParallelogram());
    shapes.push_back(new CCircle());
}

CShape* CShape::getShape() {

    initShapes();

    CShape* pShape;
    try {
        pShape = shapes.at(iShape - 1);
    } catch (std::out_of_range& e) {
        pShape = new CShape();
    }
    return pShape;
}

int CShape::getShapeCount() {
    return 3;
}

std::string CShape::getShapeName(int iShape) {
    initShapes();

    CShape* pShape;
    try {
        pShape = shapes.at(iShape - 1);
    } catch (std::out_of_range& e) {
        pShape = new CShape();
    }
    return pShape->getName();
}

int CShape::getVariables() {
    
}

void CShape::setCurrentShape(int shape) {
    iShape = shape;
}

void CShape::draw(CCanvas& canvas) {
    
}

std::string CShape::getName() {
    return "Ошибка";
}

void CShape::msgBoxEmptyFields() {
    Gtk::MessageDialog dialog("Недостаточно данных!", false,
        Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
    dialog.run();
}