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

	Button(int);
	void SetValue(string);
	string GetValue();
	bool canGetFocus();
	void draw(Graphics, int, int, size_t);
	void keyDown(int, char);
	void mousePressed(int, int, DWORD);
	void AddListener(MouseListener&);

};