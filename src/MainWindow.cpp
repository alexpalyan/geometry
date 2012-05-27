/* 
 * File:   MainWindow.cpp
 * Author: freeday
 * 
 * Created on 13 Май 2011 г., 11:20
 */

#include "MainWindow.h"
#include "ShapeWindow.h"

MainWindow::MainWindow()
{
}

MainWindow::MainWindow (BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder)
: Gtk::Window (cobject),
  m_refBuilder (refBuilder),
  m_pShapeButtonBox(0),
  shapeWindow(0)
{
	m_refBuilder->get_widget("ShapeButtonBox", m_pShapeButtonBox);

	if (m_pShapeButtonBox)
	{
		int i;
		for (i = 0; i < CShape::getShapeCount(); i++) {
		    m_pvShapeButtons.push_back(new Gtk::Button(CShape::getShapeName(i+1)));
		    m_pvShapeButtons.at(i)->signal_clicked().connect(
		            sigc::bind<int> (sigc::mem_fun( *this,
		            	&MainWindow::onShapeButtonClick), (i+1) ) );
		    m_pShapeButtonBox->pack_end(*m_pvShapeButtons.at(i));
	        m_pvShapeButtons.at(i)->show();
		}
	}

}

MainWindow::~MainWindow() {
}

void MainWindow::onShapeButtonClick(int iShape) {
    CShape::setCurrentShape(iShape);
	m_refBuilder->get_widget_derived("ShapeWindow", shapeWindow);
	if (shapeWindow)
	{
		shapeWindow->show();
	}
}
