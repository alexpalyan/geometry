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
