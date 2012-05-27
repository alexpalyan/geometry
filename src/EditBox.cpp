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
    pack_start ( label );
    pack_end ( editbox );
	label.show ();
	editbox.show ();
}

CEditBox::CEditBox(const CEditBox& orig) {
}

CEditBox::~CEditBox() {
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
