#include <iostream>
#include <typeinfo>
#include "Panel.h"

using namespace std;

Panel::Panel(int _height, int _width) {
	this->height = _height;
	this->width = _width;
	this->showed = true;
}

void Panel::addControl(Control& control, int left, int top) {
	this->controls.push_back(&control);
	control.setLeft(left);
	control.setTop(top);
}

void Panel::draw(Graphics g, int x, int y, size_t z) {
	g.setBackground(this->background);
	g.setForeground(this->foreground);

	g.write(x, y, "\xC9");
	for (int i = 0; i < this->width; i++) {
		g.write("\xCD");
	}
	g.write("\xBB\n");
	for (int i = 1; i < this->height; i++) {
		g.write(x, y + i, "\xBA");
		g.write(x + this->width + 1, y + i, "\xBA\n");
	}
	g.write(x, y + this->height, "\xC8");
	for (int i = 0; i < this->width; i++) {
		g.write("\xCD");
	}
	g.write("\xBC");

	for (int i = 0; i < this->controls.size(); i++) {
		if (controls[i]->getShowed() == true && controls[i]->getLayer() == 0) {
			controls[i]->draw(g, controls[i]->getLeft(), controls[i]->getTop(), 0);
			controls[i]->drawBorder(controls[i]->getBorder());
		}
	}

	for (int i = 0; i < this->controls.size(); i++) {
		if (controls[i]->getShowed() == true && controls[i]->getLayer() > 0) {
			controls[i]->draw(g, controls[i]->getLeft(), controls[i]->getTop(), 0);
			controls[i]->drawBorder(controls[i]->getBorder());
		}
	}
	g.setForeground(Color::White);
	g.setBackground(Color::Black);
}

void Panel::mousePressed(int x, int y, DWORD button) {
	for (int i = 0; i < this->controls.size(); i++) {
		if (isInside(x, y, this->controls[i]->getLeft(), this->controls[i]->getTop(), this->controls[i]->getWidth(), this->controls[i]->getHeight())){
			if (controls[i]->canGetFocus())
				setFocus(*this->controls[i]);
			this->controls[i]->mousePressed(x, y, button);
			break;
		}
	}
};



