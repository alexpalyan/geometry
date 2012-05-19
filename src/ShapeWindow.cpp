/* 
 * File:   ShapeWindow.cpp
 * Author: freeday
 * 
 * Created on 13 Май 2011 г., 11:21
 */


#include "ShapeWindow.h"
#include "Canvas.h"

ShapeWindow::ShapeWindow() {
    buttons_x = 20;
    buttons_y = 10;
    set_border_width(10);
    set_position(Gtk::WIN_POS_CENTER_ON_PARENT);
    set_default_size(215, 250);
    set_title("Geometry");

    signal_show().connect(sigc::mem_fun(*this,
            &ShapeWindow::onShow));

    add(frame);

    button.set_label("Посчитать");
    button.set_size_request(135, 35);
    frame.put(button, buttons_x, buttons_y);

    button.signal_clicked().connect( sigc::mem_fun( *this,
                &ShapeWindow::onCalculateButtonClick) );

    frame.put(canvas, 300, 10);
}

ShapeWindow::ShapeWindow(const ShapeWindow& orig) {
}

ShapeWindow::~ShapeWindow() {
}

void ShapeWindow::onCalculateButtonClick() {
    pShape->calculate();
}

void ShapeWindow::onShow() {
    pShape = CShape::getShape();

    //dateFields.clear();
    while (!dateFields.empty()) {
        delete dateFields.back();
        dateFields.pop_back();
    }
    buttons_x = 20;
    buttons_y = 10;

    if (!pShape->isImplemented()) {
        Gtk::MessageDialog dialog(*this, "Не реализовано!", false,
            Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK);
        hide();
        dialog.run();
        return;
    }

    canvas.setShape(pShape);
    std::ostringstream titlestream;
    titlestream << "Geometry - " << pShape->getName();
    set_title(titlestream.str());

    int i;
    for (i = 0; i < pShape->getTextFieldsCount(); i++) {
        dateFields.push_back( new CEditBox() );
        dateFields.at(i)->setWidgetSize(90, 75, 30);
        dateFields.at(i)->setLabel(pShape->getLabelForTextField(i));
        dateFields.at(i)->putToContainer(frame, buttons_x + 0, buttons_y + 0);

        buttons_y += 40;
    }
    pShape->setDateFields(dateFields);
    frame.move(button, buttons_x + 30, buttons_y + 20);
    frame.set_size_request(buttons_x + 400, buttons_y + 40);
    set_size_request(buttons_x + 400, buttons_y + 40);
    frame.show_all();
}
