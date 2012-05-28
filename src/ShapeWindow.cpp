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


#include "ShapeWindow.h"
#include "Canvas.h"

ShapeWindow::ShapeWindow()
{
	
}

ShapeWindow::ShapeWindow (BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder)
: Gtk::Window (cobject),
  m_refBuilder (refBuilder),
  m_pFieldsBox (0),
  m_pCalculateButton (0),
  m_pCanvas (0)
{
	m_refBuilder->get_widget("FieldsBox", m_pFieldsBox);
	m_refBuilder->get_widget("CalculateButton", m_pCalculateButton);
	m_refBuilder->get_widget_derived ("ShapeDrawingArea", m_pCanvas);

	if (m_pFieldsBox)
	{

		signal_show().connect(sigc::mem_fun(*this,
		        &ShapeWindow::onShow));

	}

	if (m_pCalculateButton)
	{
		m_pCalculateButton->signal_clicked().connect(
			sigc::mem_fun( *this,
		    	&ShapeWindow::onCalculateButtonClick) );

	}
	

}

ShapeWindow::~ShapeWindow()
{

}

void ShapeWindow::onCalculateButtonClick()
{
    pShape->calculate();
}

void ShapeWindow::onShow() {
    pShape = CShape::getShape();

    //dateFields.clear();
    while (!dateFields.empty()) {
        delete dateFields.back();
        dateFields.pop_back();
    }

    if (!pShape->isImplemented()) {
        Gtk::MessageDialog dialog(*this, "Не реализовано!", false,
            Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK);
        hide();
        dialog.run();
        return;
    }

	if (m_pCanvas)
	{
		m_pCanvas->setShape(pShape);
	}
    std::ostringstream titlestream;
    titlestream << "Geometry - " << pShape->getName();
    set_title(titlestream.str());

    int i;
    for (i = 0; i < pShape->getTextFieldsCount(); i++) {
        dateFields.push_back( new CEditBox() );
        dateFields.at(i)->setLabel(pShape->getLabelForTextField(i));
		m_pFieldsBox->pack_end ( *dateFields.at(i) );
		dateFields.at(i)->show ();
    }
    pShape->setDateFields(dateFields);
}
