#pragma once
#include "RectangleF.h"
class SquareF : public RectangleF 
{
	DECLARE_SERIAL(SquareF)
public:
	SquareF();
	SquareF(CPoint p1, CPoint p2);
	void Draw(CDC* dc);
	int calcArea();
	int calcPerimeter();
};


