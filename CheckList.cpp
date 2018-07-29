#pragma once
#include "CheckList.h"

//check list Ctor
CheckList::CheckList(int _height, int _width, vector<string> _options) {

	this->height = _height;
	this->width = _width;
	this->options = _options;
	this->checked = { 0, 0, 0 };
	this->showed = true;

}

//can be focused by project definition
bool CheckList::canGetFocus() {
	return true;
}


void CheckList::draw(Graphics g, int i, int j, size_t p) {
	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);

	for (int k = 0; k < this->options.size(); k++) {
		if (this->checked[k] == 0) {
			graphics.write(i, j + k, "[ ]"); // selection template
			graphics.write(i + 7, j + k, this->options[k]);	//write options text with X spaces after []
		}
		//marking selected option with X
		if (this->checked[k] == 1) {
			graphics.write(i, j + k, "[X]");
			graphics.write(i + 7, j + k, this->options[k]);	//write options text with X spaces after []
		}

	}
}

//change box status with keyboard - checked/unchecked
void  CheckList::keyDown(int keyCode, char character) {

	this->graphics.setCursorVisibility(true);

	for (int i = 0; i < this->options.size(); i++)
	{
		graphics.moveTo(this->getLeft() + 1, this->getTop() + i);


		int c = 0;
		c = getchar();


		do {
			if (c == VK_TAB) {	//move on to the next control
				break;
			}
			switch (this->checked[i]) {
			case 1:	//if checked change to unchecked
				this->checked[i] = 0;
				putchar(' ');
				break;

			case 0:	//if unchecked change to checked 
				this->checked[i] = 1;
				putchar('X');
				break;

			}

			break;
		} while (c != VK_TAB);

	}

}
//change box status with mouse - checked/unchecked
void CheckList::mousePressed(int x, int y, DWORD button) {

	for (int i = 0; i < this->getHeight(); i++)
	{
		if (x == (this->getLeft() + 1) && y == (this->getTop() + i)) {

			graphics.moveTo(this->getLeft() + 1, this->getTop() + i);
			switch (this->checked[i]) {
			case 1:	//if checked change to unchecked
				this->checked[i] = 0;
				putchar(' ');
				break;

			case 0:	//if unchecked change to checked 
				this->checked[i] = 1;
				putchar('X');
				break;

			}
			break;
		}
	}
}

//checked boxes
vector<size_t> CheckList::GetSelectedIndices() {

	return this->checked;

}

//mark box as checekd
void CheckList::SelectIndex(size_t index) {

	this->checked[index] = 1;
}

//mark box as unchecked
void CheckList::DeselectIndex(size_t index) {

	this->checked[index] = 0;
}

