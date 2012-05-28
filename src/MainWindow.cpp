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
