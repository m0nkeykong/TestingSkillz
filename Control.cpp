#include "Control.h"
#include <iostream>
#include <vector>
#define VNAME(x) #x

using namespace std;

Control* Control::focus = 0;

void Control::setFocus(Control &control) {

	if (getFocus() != NULL) {
		getFocus()->SetForeground(Color::White);
		getFocus()->setLayer(0);
	}

	control.graphics.moveTo(control.getLeft(), control.getLeft());
	control.graphics.setCursorVisibility(true);
	focus = &control;
	control.setLayer(1);
	control.SetForeground(Color::Orange);
}

void Control::drawBorder(BorderType border) {
	int i = this->getLeft() - 1;
	int j = this->getTop() - 1;

	//drawing the control's border with ascii hex codes
	switch (border) {

	case BorderType::Double:

		graphics.setBackground(this->background);
		graphics.setForeground(this->foreground);

		graphics.write(i, j, "\xC9");
		for (int k = 0; k < this->width; ++k) {
			graphics.write("\xCD");
		}
		graphics.write("\xBB\n");
		for (int k = 1; k < this->height + 1; ++k) {
			graphics.write(i, j + k, "\xBA");
			graphics.write(i + this->width + 1, j + k, "\xBA\n");
		}
		graphics.write(i, j + this->height + 1, "\xC8");
		for (int i = 0; i < this->width; ++i) {
			graphics.write("\xCD");
		}
		graphics.write("\xBC");
		break;

	case BorderType::None:

		break;

	case BorderType::Single:

		graphics.write(i, j, "\xDA");
		for (int k = 0; k < this->width; ++k) {
			graphics.write("\xC4");
		}
		graphics.write("\xBF\n");
		for (int k = 1; k < this->height + 1; ++k) {
			graphics.write(i, j + k, "\xB3");
			graphics.write(i + this->width + 1, j + k, "\xB3\n");
		}
		graphics.write(i, j + this->height + 1, "\xC0");
		for (int i = 0; i < this->width; ++i) {
			graphics.write("\xC4");
		}
		graphics.write("\xD9");
		break;
	}
}

void Control::SetForeground(Color color) {
	foreground = color;
	this->graphics.setForeground(color);
}

void Control::drawBackground() {
	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);
	for (int k = this->getTop(); k < this->getTop() + this->getHeight(); ++k) {
		for (int l = this->getLeft(); l < this->getLeft() + this->getWidth(); ++l) {
			graphics.write(l, k, " ");
		}
	}
}