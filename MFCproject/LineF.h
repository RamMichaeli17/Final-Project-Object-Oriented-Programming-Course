#pragma once
#include "Figure.h"
class LineF :public Figure 
{
	DECLARE_SERIAL(LineF)
public:
	LineF();
	LineF(CPoint p1, CPoint p2);
	void Draw(CDC* dc);
	int calcArea();
	int calcPerimeter();
};

