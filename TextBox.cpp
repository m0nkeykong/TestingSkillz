#include <iostream>
#include "TextBox.h"

using namespace std;

TextBox::TextBox(int _width) {
	this->width = _width;
	this->height = 1;
	this->border = BorderType::Single;
	this->showed = true;
}

void TextBox::SetValue(string _value) {
	this->value = _value;
}

string TextBox::GetValue() {
	return this->value;
}

bool TextBox::canGetFocus() {
	return true;
}

int TextBox::getWidth() {
	return this->width;
}

int TextBox::getHeight() {
	return this->height;
}


void TextBox::draw(Graphics graphics, int i, int j, size_t p) {

	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);
	graphics.write(i, j, this->GetValue());
	graphics.setForeground(Color::White);
	graphics.setBackground(Color::Black);

}

void TextBox::keyDown(int keyCode, char character) {

	int position = this->getLeft() + this->GetValue().size();
	if (this->GetValue().empty()) {
		graphics.moveTo(position, this->getTop());
	}
	else {
		graphics.moveTo(position - 1, this->getTop());

	}

	this->graphics.setCursorVisibility(true);

	string input = this->GetValue();
	int c;
	int i = 0;

	while (1) {



		c = getchar();
		position++;

		if (position > this->getLeft() + this->getWidth() && c != VK_BACK) {
			break;
		}

		input.push_back(c);
		putchar(c);

		if (c == VK_BACK) {
			input.pop_back();
			if (input.empty() == false) {
				input.pop_back();
				position -= 2;
				graphics.moveTo(position, this->getTop());
				putchar(' ');
				graphics.moveTo(position, this->getTop());
			}
			else {
				position -= 0;
			}

		}


		if (c == VK_TAB) {
			input.pop_back();
			break;
		}



	}

	this->SetValue(input);

}

void TextBox::mousePressed(int x, int y, DWORD button) {
	this->keyDown(1, 'v');
};

