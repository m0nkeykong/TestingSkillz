#pragma once
#include "Control.h"


class Label : public Control {

private:
	int width;
	int height = 3;
	string value = "default value";

public:

	Label(int _width);
	void SetValue(string _value);
	string GetValue();
	void draw(Graphics g, int i, int j, size_t p);
	bool canGetFocus();
	void keyDown(int keyCode, char character);
	void mousePressed(int x, int y, DWORD button);
};