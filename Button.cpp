#include "Button.h"

//button C'tor
Button::Button(int width) {
	this->width = width;
	this->height = 1;
	this->border = BorderType::Single;
	this->showed = true;
	this->value = "Submit";


}

//set button text
void Button::SetValue(string value) {
	this->value = value;
}

//get button text
string Button::GetValue() {
	return this->value;
}

bool Button::canGetFocus() {
	return false;	//buttons can't be focused by project's demand
}

void Button::draw(Graphics g, int i, int j, size_t p) {

	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);
	drawBackground();
	graphics.write(i, j, this->GetValue());


}

void Button::keyDown(int keyCode, char character) {
	this->graphics.clearScreen();
}

void Button::mousePressed(int xPos, int yPos, DWORD button) {
	listener->MousePressed(*this, xPos, yPos, true);
}


void Button::AddListener(MouseListener &listener) {
	this->listener = &listener;
}

