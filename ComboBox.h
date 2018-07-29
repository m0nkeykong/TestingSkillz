#pragma once

#include "Control.h"


class ComboBox : public Control {

private:

	vector<string> options;
	size_t selected;
	bool isOpened = false;




public:
	ComboBox(int width, vector<string> options);
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);
	virtual void draw(Graphics g, int i, int j, size_t p);
	virtual bool canGetFocus();
	virtual void keyDown(int keyCode, char character);
	virtual void mousePressed(int x, int y, DWORD button);

};