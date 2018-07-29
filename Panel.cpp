#include <iostream>
#include <typeinfo>
#include "Panel.h"


using namespace std;


Panel::Panel(int _height, int _width) {
	this->height = _height;
	this->width = _width;
	this->showed = true;

}

//no focus according to task definition
bool Panel::canGetFocus() {
	return false;
}


void Panel::addControl(Control& control, int left, int top) {
	this->controls.push_back(&control);
	control.setLeft(left);
	control.setTop(top);


}

void Panel::draw(Graphics graphics, int i, int j, size_t p) {

	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);

	//drawing the panel border with ascii hex codes
	graphics.write(i, j, "\xC9");
	for (int k = 0; k < this->width; k++) {
		graphics.write("\xCD");
	}
	graphics.write("\xBB\n");
	for (int k = 1; k < this->height; k++) {
		graphics.write(i, j + k, "\xBA");
		graphics.write(i + this->width + 1, j + k, "\xBA\n");
	}
	graphics.write(i, j + this->height, "\xC8");
	for (int i = 0; i < this->width; i++) {
		graphics.write("\xCD");
	}
	graphics.write("\xBC");



	for (int k = 0; k < this->controls.size(); k++) {

		if (controls[k]->getShowed() == true && controls[k]->getLayer() == 0) {
			controls[k]->draw(graphics, controls[k]->getLeft(), controls[k]->getTop(), 0);
			controls[k]->drawBorder(controls[k]->getBorder());
		}
	}

	for (int k = 0; k < this->controls.size(); k++) {

		if (controls[k]->getShowed() == true && controls[k]->getLayer() > 0) {

			controls[k]->draw(graphics, controls[k]->getLeft(), controls[k]->getTop(), 0);
			controls[k]->drawBorder(controls[k]->getBorder());
		}
	}

	graphics.setForeground(Color::White);
	graphics.setBackground(Color::Black);
}

void Panel::getAllControls(vector <Control*>* c) { *c = this->controls; }



void Panel::mousePressed(int x, int y, DWORD button) {

	for (int k = 0; k < this->controls.size(); k++) {

		if (isInside(x, y, this->controls[k]->getLeft(), this->controls[k]->getTop(), this->controls[k]->getWidth(), this->controls[k]->getHeight()))
		{
			if (controls[k]->canGetFocus())
			{
				setFocus(*this->controls[k]);	//if control can be focused then pass the focus to it
			}
			this->controls[k]->mousePressed(x, y, button);

			break;
		}
	}

};
void Panel::keyDown(int keyCode, char character) {};

