#pragma once
#include "Control.h"


class Button;

struct MouseListener
{
	virtual void MousePressed(Button &b, int x, int y, bool isLeft) = 0;
};


class Button : public Control {

private:

	string value;
	MouseListener* listener;

public:

	Button(int _width);
	void SetValue(string _value);
	string GetValue();
	bool canGetFocus();
	void draw(Graphics g, int i, int j, size_t p);
	void keyDown(int keyCode, char character);
	void mousePressed(int x, int y, DWORD button);
	void AddListener(MouseListener &listener);

};