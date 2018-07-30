#pragma once
#include <vector>
#include "Graphics.h"

enum class BorderType { Single, Double, None };
enum class ForegroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BackgroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };

class Control {

protected:
	int left, top, width, height;
	bool showed;
	static Control* focus;
	size_t layer = 0;
	BorderType border = BorderType::None;
	Graphics graphics;
	Color foreground = Color::White, background = Color::Black;

public:
	Control()								{}
	~Control()								{}
	void Show()								{ this->showed = true; }
	void Hide()								{ this->showed = false; }
	void setLeft(int left)					{ this->left = left; }
	void setTop(int top)					{ this->top = top; }
	void setLayer(size_t layer)				{ this->layer = layer; }
	void SetBorder(BorderType border)		{ this->border = border; }
	void drawBorder(BorderType);
	void drawBackground();
	int getLeft()							{ return this->left; }
	int getTop()							{ return this->top; }
	int getWidth()							{ return this->width; }
	int getHeight()							{ return this->height; }
	static Control* getFocus()				{ return focus; }
	static void setFocus(Control&);
	bool getShowed()						{ return this->showed; }
	size_t getLayer()						{ return this->layer; }
	BorderType getBorder()					{ return this->border; }
	virtual void setValue(int)				{}
	virtual void setWidth(int width)		{ this->width = width; }
	virtual void SetBackground(Color color) { background = color; }
	virtual void SetForeground(Color);
	virtual void getAllControls(vector <Control*>*) {}
	virtual void draw(Graphics, int, int, size_t) = 0;
	virtual void mousePressed(int, int, DWORD) = 0;
	virtual void keyDown(int, char) = 0;
	virtual bool canGetFocus() = 0;
	
};
