#pragma once
#include "Control.h"

class CheckList : public Control {

protected:
	vector<string> options;
	vector<size_t> checked;

public:
	CheckList(int, int, vector<string>);
	vector<size_t> GetSelectedIndices()			{ return this->checked; }
	bool canGetFocus()							{ return true; }
	void draw(Graphics, int, int, size_t);
	void keyDown(int, char);
	void mousePressed(int, int, DWORD);
	void SelectIndex(size_t index)				{ this->checked[index] = 1; }
	void DeselectIndex(size_t index)			{ this->checked[index] = 0; }
};
