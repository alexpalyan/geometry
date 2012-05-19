/* 
 * File:   EditBox.cpp
 * Author: freeday
 * 
 * Created on 23 Апрель 2011 г., 6:52
 */

#include <stdlib.h>
#include <stdio.h>

#include "EditBox.h"

CEditBox::CEditBox() {
}

CEditBox::CEditBox(const CEditBox& orig) {
}

CEditBox::~CEditBox() {
}

void CEditBox::setWidgetSize(int iLabelWidth, int iTextWidth, int iHeight) {
    label.set_size_request(iLabelWidth, iHeight);
    editbox.set_size_request(iTextWidth, iHeight);
}

void CEditBox::putToContainer(Gtk::Fixed& pContainer, int iX, int iY) {
    int iLabelWidth;
    int iLabelHeight;
    
    label.get_size_request(iLabelWidth, iLabelHeight);
    pContainer.put(label, iX, iY);
    pContainer.put(editbox, iX+iLabelWidth, iY);
}

void CEditBox::setText(std::string string) {
    editbox.set_text(string);
}

void CEditBox::setLabel(std::string string) {
    label.set_text(string);
}

std::string CEditBox::getText() {
    return editbox.get_text();
}

float CEditBox::getFloat() {
    return atof(getText().c_str());
}

void CEditBox::setFloat(float value) {
    char* tmpString = (char*)malloc(15);
    sprintf(tmpString, "%.3f", value);
    setText(tmpString);
}

int CEditBox::getInt() {
    return atoi(getText().c_str());
}

void CEditBox::setInt(int value) {
    
}
