#include <iostream>
#include "MessageBox.h"

using namespace std;

Messagebox::Messagebox(int _width, int _height) {
	this->width = _width;
	this->height = _height;
	this->border = BorderType::Double;
	this->showed = false;
}

void Messagebox::SetTitle(string _title) {
	this->title = _title;
}

string Messagebox::GetTitle() {
	return this->title;
}

void Messagebox::SetText(string _text) {
	this->text = _text;
}

string Messagebox::GetText() {
	return this->text;
}

//no focus according to task definition
bool Messagebox::canGetFocus() {
	return false;
}


void Messagebox::draw(Graphics g, int i, int j, size_t p) {

	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);

	drawBackground();
	graphics.write(i, j, this->GetTitle());
	graphics.write(i, j + 2, this->GetText());

	for (int k = 0; k < this->buttons.size(); k++) {

		if (buttons[k]->getShowed() == true) {
			buttons[k]->draw(graphics, buttons[k]->getLeft(), buttons[k]->getTop(), 0);
			buttons[k]->drawBorder(buttons[k]->getBorder());
		}
	}



}

void Messagebox::keyDown(int keyCode, char character) {
}

void Messagebox::mousePressed(int x, int y, DWORD button) {

	for (int k = 0; k < this->buttons.size(); k++) {

		if (isInside(x, y, this->buttons[k]->getLeft(), this->buttons[k]->getTop(), this->buttons[k]->getWidth(), this->buttons[k]->getHeight()))
		{

			this->buttons[k]->mousePressed(x, y, button);

			break;
		}
	}
};

//add button to display
void Messagebox::addButton(Button &_button, int left, int top) {


	this->buttons.push_back(&_button);
	_button.setLeft(this->getLeft() + left);
	_button.setTop(this->getTop() + top);

}

