#pragma once
#include "RadioList.h"


RadioList::RadioList(int _height, int _width, vector<string> _options)
	:CheckList(_height, _width, _options) {

	this->height = _height;
	this->width = _width;
	this->options = _options;
	this->checked = 0;
	this->showed = true;

}


void RadioList::draw(Graphics g, int i, int j, size_t p) {
	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);

	for (int k = 0; k < this->options.size(); k++) {


		if (this->checked == k) {
			graphics.write(i, j + k, "[X]");	//mark selected option
			graphics.write(i + 7, j + k, this->options[k]);
		}
		else {
			graphics.write(i, j + k, "[ ]");	//mark non selected option
			graphics.write(i + 7, j + k, this->options[k]);
		}

	}

	graphics.setForeground(Color::White);
	graphics.setBackground(Color::Black);
}

void  RadioList::keyDown(int keyCode, char character) {

	this->graphics.setCursorVisibility(true);

	for (int i = 0; i < this->options.size(); i++)	//change selected option
	{
		graphics.moveTo(this->getLeft() + 1, this->getTop() + i);
		int c = 0;
		c = getchar();
		do {
			if (c == VK_TAB) {
				break;
			}

			this->checked = 1;
			putchar('X');
			for (int k = 0; k < this->options.size(); k++)
			{
				if (i != k) {
					this->checked = 0;
					graphics.moveTo(this->getLeft() + 1, this->getTop() + k);
					putchar(' ');
				}
				break;
			}

			break;
		} while (c != VK_TAB);

	}

}

void RadioList::mousePressed(int x, int y, DWORD button) {

	//change selected option
	for (int i = 0; i < this->getHeight(); i++)
	{
		if (x == (this->getLeft() + 1) && y == (this->getTop() + i)) {

			graphics.moveTo(this->getLeft() + 1, this->getTop() + i);
			if (this->checked != i) {
				graphics.moveTo(this->getLeft() + 1, this->getTop() + this->checked);
				putchar(' ');
				this->checked = i;
				graphics.moveTo(this->getLeft() + 1, this->getTop() + i);
				putchar('X');

			}

			break;
		}
	}
};


size_t  RadioList::GetSelectedIndex() {
	return this->checked;
};

void  RadioList::SetSelectedIndex(size_t index) {
	this->checked = index;
};


