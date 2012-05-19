/* 
 * File:   Shape.h
 * Author: freeday
 *
 * Created on 17 Апрель 2011 г., 14:44
 */

#ifndef SHAPE_H
#define	SHAPE_H

#include <vector>
#include "Point.h"
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
    CPoint* pPointO;

    static void initShapes();

    static int iShape;
    static std::vector<CShape*> shapes;
};

#endif	/* SHAPE_H */

