#pragma once
#include "Figure.h"
class RectangleF : public Figure 
{
	DECLARE_SERIAL(RectangleF)   
public:
	RectangleF();
	RectangleF(CPoint p1, CPoint p2);
	int calcArea();
	int calcPerimeter();
};

