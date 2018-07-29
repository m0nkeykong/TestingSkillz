#include <iostream>
#include "ComboBox.h"

using namespace std;

//C'tor
ComboBox::ComboBox(int width, vector<string> options) {
	this->width = width;
	this->height = 1;
	this->options = options;
	this->showed = true;
}

size_t ComboBox::GetSelectedIndex() {
	return this->selected;
}
void ComboBox::SetSelectedIndex(size_t index) {
	this->selected = index;
}

//can be focused according to project's definition
bool ComboBox::canGetFocus() {
	return true;
}


void ComboBox::draw(Graphics g, int i, int j, size_t p) {

	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);

	drawBackground();

	switch (this->isOpened) {
	case false:	//combobox closed

		graphics.write(i + this->width - 3, j, "\xBA"); // ||  border symbol - ascii table
		graphics.write(i + this->width - 1, j, "V");

		graphics.write(i + 1, j, this->options[this->GetSelectedIndex()]);

		break;

	case true:	//combobox opened

		graphics.write(i + this->width - 3, j, "\xBA"); // || border symbol - ascii table
		graphics.write(i + this->width - 1, j, "V");

		graphics.write(i + 1, j, this->options[this->GetSelectedIndex()]); //write the text of selected option 

		for (int k = 0; k < options.size(); ++k) {

			//handle the graphics of the selected option
			if (k == GetSelectedIndex()) {
				graphics.setBackground(Color::Blue);
				graphics.write(this->getLeft() + 1, this->getTop() + k + 1, this->options[k]);
				graphics.setBackground(this->background);

			}
			else {
				graphics.write(this->getLeft() + 1, this->getTop() + k + 1, this->options[k]);
			}
		}

	}
	graphics.setForeground(Color::White);
	graphics.setBackground(Color::Black);
}

void ComboBox::keyDown(int keyCode, char character) {
	int position = this->getTop() + this->GetSelectedIndex() + 1;
	int index = this->GetSelectedIndex();
	int iBefore = index;
	int c;
	while (1) {
		c = getchar();

		if (c == VK_UP) {

			if (position <= this->getTop() + 1) {}
			else {
				--position;
				--index;
			}

		}

		if (c == VK_DOWN) {

			if (position >= this->getTop() + this->options.size() + 1) {

			}
			else {
				++position;
				++index;
			}
		}
		if (c == VK_TAB || c == VK_RETURN) {
			break;
		}
	}

	this->SetSelectedIndex(index);
	if (index != iBefore)
		this->height -= options.size();
	this->isOpened = false;
}

void ComboBox::mousePressed(int x, int y, DWORD button) {


	int top = this->getTop();
	int left = this->getLeft();
	vector<string> options = this->options;

	switch (this->isOpened) {
	case false:
		this->height += options.size();
		this->isOpened = true;
		break;
	case true:
		for (int k = 0; k < options.size(); ++k) {
			if (y == top + k + 1) {
				this->selected = k;
				this->height -= options.size();
				this->isOpened = false;
				break;
			}
		}

	}

};

