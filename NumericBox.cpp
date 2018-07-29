#pragma once
#include <string> 
#include "NumericBox.h"


NumericBox::NumericBox(int _width, int _min, int _max) {
	this->width = _width;
	this->height = 3;
	this->min = _min;
	this->max = _max;
	this->showed = true;
}

void NumericBox::SetValue(int _value) {
	this->value = _value;
}

int NumericBox::GetValue() {
	return this->value;
}

//no focus according to task definition
bool NumericBox::canGetFocus() {
	return false;
}

void NumericBox::draw(Graphics g, int i, int j, size_t p) {

	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);

	//drawing the number box with ascii hex codes
	graphics.write(i, j + 1, "[-]");
	graphics.write(i + 3, j, "\xC9");
	for (int k = 0; k < this->getWidth() - 8; k++) {
		graphics.write("\xCD");
	}
	graphics.write("\xBB\n");
	graphics.write(i + 3, j + 1, "\xBA");
	graphics.write(i + this->getWidth() - 4, j + 1, "\xBA");
	graphics.write(i + 3, j + 2, "\xC8");
	for (int k = 0; k < this->getWidth() - 8; k++) {
		graphics.write("\xCD");
	}
	graphics.write("\xBC");

	//writing the number to the box
	std::string val = std::to_string(this->value);
	graphics.write(i + this->getWidth() / 2, j + 1, val);
	graphics.write(i + this->getWidth() - 3, j + 1, "[+]");


	graphics.setForeground(Color::White);
	graphics.setBackground(Color::Black);

}

void NumericBox::keyDown(int keyCode, char character) {}

void NumericBox::mousePressed(int x, int y, DWORD button) {

	this->graphics.setCursorVisibility(true);
	graphics.moveTo(x, y);

	if (x == this->getLeft() + 1) {
		if (this->value > this->min)
		{
			this->SetValue(this->value - 1);
		}
	}

	if (x == (this->getLeft() + this->getWidth() - 2)) {

		if (this->value < this->max)
		{
			this->SetValue(this->value + 1);
		}
	}

}
