/* 
 * File:   Parallelogram.cpp
 * Author: freeday
 * 
 * Created on September 3, 2011, 8:21 PM
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
