#include "Button.h"

//button C'tor
Button::Button(int width) {
	this->width = width;
	this->height = 1;
	this->border = BorderType::Single;
	this->showed = true;
	this->value = "Submit";


}

void Button::draw(Graphics g, int i, int j, size_t p) {

	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);
	drawBackground();
	graphics.write(i, j, this->GetValue());

}

