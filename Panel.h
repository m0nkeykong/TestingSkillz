#pragma once
#include "Control.h"

class Panel : public Control {

private:
	vector<Control*> controls;

public:
	Panel(int, int);
	bool canGetFocus()							{ return false; }
	void getAllControls(vector <Control*>* c)	{ *c = this->controls; }
	void keyDown(int, char)						{}
	void addControl(Control&, int, int);
	void draw(Graphics, int, int, size_t);
	void mousePressed(int, int, DWORD);

};
