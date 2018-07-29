#pragma once

#include "Control.h"


class TextBox : public Control {

private:
	string value = "";



public:
	TextBox(int _width);
	void SetValue(string _value);
	string GetValue();
	bool canGetFocus();
	int getWidth();
	int getHeight();
	void draw(Graphics g, int i, int j, size_t p);
	void keyDown(int keyCode, char character);
	void mousePressed(int x, int y, DWORD button);

};

