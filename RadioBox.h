#pragma once
#include "Control.h"
#include "CheckList.h"

class RadioBox : public CheckList {

private:

	size_t checked = 0;

public:

	RadioBox(int _height, int _width, vector<string> _options);
	void draw(Graphics g, int i, int j, size_t p);
	void keyDown(int keyCode, char character);
	void mousePressed(int x, int y, DWORD button);
	size_t GetSelectedIndex();
	void SetSelectedIndex(size_t index);


};