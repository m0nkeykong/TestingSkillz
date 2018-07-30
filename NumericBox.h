#pragma once

#include "Control.h"

class NumericBox : public Control {

private:
	int min, max, value = 0;

public:
	NumericBox(int, int, int);
	inline void SetValue(int value) { this->value = value; }
	inline int GetValue() { return this->value; }
	inline bool canGetFocus() { return false; }

	void draw(Graphics g, int i, int j, size_t p);
	void keyDown(int keyCode, char character) {}
	void mousePressed(int x, int y, DWORD button);

};