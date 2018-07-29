#include "Button.h"

//button C'tor
Button::Button(int _width) {
	this->width = _width;
	this->height = 1;
	this->border = BorderType::Single;
	this->showed = true;
	this->value = "Submit";


}

//set button text
void Button::SetValue(string _value) {
	this->value = _value;
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

void Button::mousePressed(int x, int y, DWORD button) {


	listener->MousePressed(*this, x, y, true);


}


void Button::AddListener(MouseListener &_listener) {
	this->listener = &_listener;
}

