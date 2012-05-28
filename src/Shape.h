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


#ifndef SHAPE_H
#define	SHAPE_H

#include <vector>
#include "EditBox.h"
#include "Canvas.h"

class CCanvas;

class CShape {
public:
    CShape();
    CShape(const CShape& orig);
    virtual ~CShape();
    int getTextFieldsCount();
    std::string getLabelForTextField(int);
    virtual void calculate();
    void setDateFields(std::vector<CEditBox*>);
    static CShape* getShape();
    static int getShapeCount();
    static std::string getShapeName(int);
    static void setCurrentShape(int);
    virtual bool isImplemented();
    virtual void draw(CCanvas&);
    virtual std::string getName();
protected:
    std::vector<CEditBox*> vDateFields;
    virtual int getShapeFieldsCount();
    virtual std::string getLabelForShapeField(int);
    virtual int getVariables();
    void msgBoxEmptyFields();
    float fltPerimeter;
    float fltSquare;
private:
    static void initShapes();

    static int iShape;
    static std::vector<CShape*> shapes;
};

#endif	/* SHAPE_H */

