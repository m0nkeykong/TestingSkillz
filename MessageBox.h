#pragma once

#include "Control.h"
#include "Button.h"


class Messagebox : public Control {

private:

	string title = "";
	string text = "";
	vector <Button*> buttons;


public:
	Messagebox(int, int);
	void SetTitle(string);
	string GetTitle();
	void SetText(string);
	string GetText();
	bool canGetFocus();
	void draw(Graphics, int, int, size_t);
	void keyDown(int, char) {}
	void mousePressed(int, int, DWORD);
	void addButton(Button&, int, int);
};

