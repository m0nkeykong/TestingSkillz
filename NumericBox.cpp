#pragma once
#include <string> 
#include "NumericBox.h"

NumericBox::NumericBox(int width, int min, int max) {
	this->width = width;
	this->height = 10;
	this->max = max;
	this->min = min;
	this->showed = true;
}

// Drawing the NumericBox
void NumericBox::draw(Graphics g, int x, int y, size_t z) {
	// Setting Foreground and Background
	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);
	
	// "MINUS" button
	graphics.write(x, y + 1, "(-)");

	// NumericBox's frame
	graphics.write(x + 3, y, "\xC9");

	for (int i = 0; i < this->getWidth() - 8; i++)
		graphics.write("\xCD");

	graphics.write("\xBB\n");
	graphics.write(x + 3, y + 1, "\xBA");
	graphics.write(x + this->getWidth() - 4, y + 1, "\xBA");
	graphics.write(x + 3, y + 2, "\xC8");

	for (int i = 0; i < this->getWidth() - 8; i++) 
		graphics.write("\xCD");

	graphics.write("\xBC");

	// Getting the number value and printing it
	string val = to_string(this->value);
	graphics.write(x + this->getWidth() / 2 - this->getWidth() % 2, y + 1, val);

	// "PLUS" button
	graphics.write(x + this->getWidth() - 3, y + 1, "(+)");

	// Setting Foreground and Background to default
	graphics.setForeground(Color::White);
	graphics.setBackground(Color::Black);
}

// Handle mouse clicking
void NumericBox::mousePressed(int x, int y, DWORD button) {
	this->graphics.setCursorVisibility(true);
	graphics.moveTo(x, y);

	// Decrementing value when "-" pressed
	if (x == this->getLeft() + 1)
		if (this->value > this->min)
			this->SetValue(this->value - 1);

	// Incrementing value when "+" pressed
	if (x == (this->getLeft() + this->getWidth() - 2))
		if (this->value < this->max)
			this->SetValue(this->value + 1);

}
