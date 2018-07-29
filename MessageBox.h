#pragma once

#include "Control.h"
#include "Button.h"


class Messagebox : public Control {

private:

	string title = "";
	string text = "";
	vector <Button*> buttons;


public:
	Messagebox(int _width, int _height);
	void SetTitle(string _title);
	string GetTitle();
	void SetText(string _text);
	string GetText();
	bool canGetFocus();
	void draw(Graphics g, int i, int j, size_t p);
	void keyDown(int keyCode, char character);
	void mousePressed(int x, int y, DWORD button);
	void addButton(Button &_button, int top, int left);
};

