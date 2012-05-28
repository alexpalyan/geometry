/* 
 * File:   ShapeWindow.cpp
 * Author: freeday
 * 
 * Created on 13 Май 2011 г., 11:21
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
//        dateFields.at(i)->setWidgetSize(90, 75, 30);
        dateFields.at(i)->setLabel(pShape->getLabelForTextField(i));
		m_pFieldsBox->pack_end ( *dateFields.at(i) );
		dateFields.at(i)->show ();
    }
    pShape->setDateFields(dateFields);
}
