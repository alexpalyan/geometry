/* 
 * File:   Parallelogram.h
 * Author: freeday
 *
 * Created on September 3, 2011, 8:21 PM
 */

#ifndef CPARALLELOGRAM_H
#define	CPARALLELOGRAM_H

#include "../Shape.h"

class CParallelogram: public CShape {
public:
    CParallelogram();
    CParallelogram(const CParallelogram& orig);
    virtual ~CParallelogram();

    int getShapeFieldsCount();
    void calculate();
    bool isImplemented();
    std::string getName();
protected:
    std::string getLabelForShapeField(int);
private:

};

#endif	/* CPARALLELOGRAM_H */

