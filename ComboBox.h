#pragma once

#include "Control.h"


class ComboBox : public Control {

private:

	vector<string> options;
	size_t selected;
	bool isOpened = false;

public:
	ComboBox(int, vector<string>);
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t);
	virtual void draw(Graphics, int, int, size_t);
	virtual bool canGetFocus();
	virtual void keyDown(int, char);
	virtual void mousePressed(int, int, DWORD);

};