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


#include "Parallelogram.h"

CParallelogram::CParallelogram() {
}

CParallelogram::CParallelogram(const CParallelogram& orig) {
}

CParallelogram::~CParallelogram() {
}

bool CParallelogram::isImplemented() {
    return false;
}

int CParallelogram::getShapeFieldsCount() {
    return 0;
}

void CParallelogram::calculate() {
    
}

std::string CParallelogram::getName() {
    return "Параллелограм";
}

std::string CParallelogram::getLabelForShapeField(int) {
    return "NONE";
}
