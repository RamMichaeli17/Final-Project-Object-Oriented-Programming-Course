#include "stdafx.h"
#include "EllipseF.h"
IMPLEMENT_SERIAL(EllipseF, CObject, 1)
EllipseF::EllipseF()
{
	shapeKind = 2;
}
EllipseF::EllipseF(CPoint p1, CPoint p2)
	:Figure(p1, p2)
{
	shapeKind = 2;
}
void EllipseF::Draw(CDC* dc)
{
	CPen pen(PS_SOLID, Thick ? 10 : 2, figureFrameColor);
	CPen* pOldPen = dc->SelectObject(&pen);
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CBrush brush(figureColor);
	CBrush* oldBrush = dc->SelectObject(&brush);
	CRect rect(P1.x, P1.y, P2.x, P2.y);
	dc->Ellipse(rect);

}
int EllipseF::calcArea()
{
	int height, length;
	length = P1.x - P2.x > 0 ? P1.x - P2.x : P2.x - P1.x;
	height = P1.y - P2.y > 0 ? P1.y - P2.y : P2.y - P1.y;
	return (3.1415926535897931 * height * length);
}
int EllipseF::calcPerimeter()
{
	int height, length;
	length = P1.x - P2.x > 0 ? P1.x - P2.x : P2.x - P1.x;
	height = P1.y - P2.y > 0 ? P1.y - P2.y : P2.y - P1.y;
	return (height*2+length*2);//Instead of calculating the perimeter of the ellipse itself (too complicated) it's calculating the perimter of the rectangle that blocks the ellipse
}
