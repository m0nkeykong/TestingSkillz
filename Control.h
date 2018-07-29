#pragma once
#include <vector>
#include "Graphics.h"


enum class BorderType { Single, Double, None };
enum class ForegroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BackgroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };


class Control {

protected:

	int left;
	int top;
	int width;
	int height;
	size_t layer = 0;
	bool showed;
	BorderType border = BorderType::None;
	Graphics graphics;
	Color foreground = Color::White;
	Color background = Color::Black;
	static Control* focus;


public:
	Control();
	~Control();
	void Show();
	void Hide();
	virtual void draw(Graphics g, int i, int j, size_t p) = 0;
	virtual void getAllControls(vector <Control*>* c);
	static Control* getFocus();
	static void setFocus(Control &control);
	void setLeft(int _left);
	void setTop(int _top);
	int getLeft();
	int getTop();
	virtual void setWidth(int _width);
	int getWidth();
	int getHeight();
	bool getShowed();
	size_t getLayer();
	void setLayer(size_t _layer);
	BorderType getBorder();
	virtual void mousePressed(int x, int y, DWORD button) = 0;
	virtual void keyDown(int keyCode, char character) = 0;
	virtual bool canGetFocus() = 0;
	virtual void setValue(int value);
	void SetBorder(BorderType _border);
	void drawBorder(BorderType _border);
	virtual void SetForeground(Color color);
	virtual void SetBackground(Color color);
	void drawBackground();

};
