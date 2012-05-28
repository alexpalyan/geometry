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

