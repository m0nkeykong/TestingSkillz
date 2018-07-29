#pragma once
#include "Control.h"

class CheckList : public Control {

protected:
	vector<string> options;
	vector<size_t> checked;

public:
	CheckList(int _height, int _width, vector<string> _options);
	bool canGetFocus();
	void draw(Graphics g, int i, int j, size_t p);
	void keyDown(int keyCode, char character);
	void mousePressed(int x, int y, DWORD button);
	vector<size_t> GetSelectedIndices();
	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);
};
