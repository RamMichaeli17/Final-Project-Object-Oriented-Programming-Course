#include "stdafx.h"
#include "SquareF.h"
IMPLEMENT_SERIAL(SquareF, CObject, 1)
SquareF::SquareF()
{
	shapeKind = 3;
}
SquareF::SquareF(CPoint p1, CPoint p2)
	:RectangleF(p1,p2)
{
	shapeKind = 3;
}
void SquareF::Draw(CDC* dc) 
{
	/* Here we calculate , according to the mouse cursor position , where to draw and redefine our shape */
	CPoint p1 = Figure::getP1();
	CPoint p2 = Figure::getP2();
	int side, length, heigth;
	length = p1.x - p2.x;
	heigth = p1.y - p2.y;
	CBrush brush(figureColor);
	CBrush* oldBrush = dc->SelectObject(&brush);
	if (length < 0)
		length *= -1;
	if (heigth < 0)
		heigth *= -1;
	side = length > heigth ? length : heigth;
	if (p2.y > p1.y && p2.x > p1.x)
	{

		p2.x = p1.x + side;
		p2.y = p1.y + side;
		Figure::Redefine(p1, p2);
	}
	else if (p2.y > p1.y && p2.x < p1.x)
	{

		p2.x = p1.x - side;
		p2.y = p1.y + side;
		Figure::Redefine(p1, p2);
	}
	else if (p2.y<p1.y && p2.x>p1.x)
	{

		p2.x = p1.x + side;
		p2.y = p1.y - side;
		Figure::Redefine(p1, p2);
	}
	else
	{

		p2.x = p1.x - side;
		p2.y = p1.y - side;
		Figure::Redefine(p1, p2);
	}

	CPen pen(PS_SOLID, Thick ? 10 : 3, figureFrameColor);
	CPen* pOldPen = dc->SelectObject(&pen);
	CRect rect(P1.x, P1.y, P2.x, P2.y);
	dc->Rectangle(&rect);


	
}
int SquareF::calcArea()
{
	int side = P1.x - P2.x > 0 ? P1.x - P2.x : P2.x - P1.x;
	return (side * side);

}
int SquareF::calcPerimeter()
{
	int side = P1.x - P2.x > 0 ? P1.x - P2.x : P2.x - P1.x;
	return (side * 4);
}
