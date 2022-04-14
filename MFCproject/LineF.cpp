#include "stdafx.h"
#include "LineF.h"
IMPLEMENT_SERIAL(LineF, CObject, 1)
LineF::LineF()
{
	shapeKind = 5;
}
LineF::LineF(CPoint p1, CPoint p2)
	:Figure(p1, p2)
{
	shapeKind = 5;
}
void LineF::Draw(CDC* dc)
{
	CPen pen(PS_SOLID, Thick ? 10 : 2, figureColor);
	CPen* pOldPen = dc->SelectObject(&pen);
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->MoveTo(p1.x, p1.y);
	dc->LineTo(p2.x, p2.y);

}
int LineF::calcArea()
{
	return 0.0;
}
int LineF::calcPerimeter()
{
	int height, length;
	length = P1.x - P2.x > 0 ? P1.x - P2.x : P2.x - P1.x;
	height = P1.y - P2.y > 0 ? P1.y - P2.y : P2.y - P1.y;
	return sqrt(pow(length, 2) + pow(height, 2)); // Pythagoras to calculate length of a line
}
