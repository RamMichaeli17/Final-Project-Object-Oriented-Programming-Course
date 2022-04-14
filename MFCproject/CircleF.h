#pragma once
#include "EllipseF.h"
class CircleF : public EllipseF 
{
	DECLARE_SERIAL(CircleF)
public:
	CircleF();
	CircleF(CPoint p1, CPoint p2);
	void Draw(CDC* dc);
	int calcArea();
	int calcPerimeter();
};


