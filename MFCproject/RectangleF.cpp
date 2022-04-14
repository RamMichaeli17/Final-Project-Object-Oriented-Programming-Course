#include "stdafx.h" 
#include "RectangleF.h"
IMPLEMENT_SERIAL(RectangleF, CObject, 1)
RectangleF::RectangleF()
{
	shapeKind = 1;
}
RectangleF::RectangleF(CPoint p1, CPoint p2)
	:Figure(p1,p2)
{
	shapeKind = 1;
}
int RectangleF::calcArea()
{
	int height, length;
	length = P1.x - P2.x > 0?P1.x - P2.x : P2.x - P1.x;
	height = P1.y - P2.y > 0 ? P1.y - P2.y : P2.y - P1.y;
	return (height * length);
}
int RectangleF::calcPerimeter()
{
	int height, length;
	length = P1.x - P2.x > 0 ? P1.x - P2.x : P2.x - P1.x;
	height = P1.y - P2.y > 0 ? P1.y - P2.y : P2.y - P1.y;
	return (height * 2 + length * 2);
}

