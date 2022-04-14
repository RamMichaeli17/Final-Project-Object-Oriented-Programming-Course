#include "stdafx.h" 
#include "Figure.h"
IMPLEMENT_SERIAL(Figure, CObject, 1)
Figure::Figure()
{
}
Figure::Figure(CPoint p1, CPoint p2) :
	P1(p1), P2(p2)
{
}
void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << figureFrameColor;
		ar << Thick;
		ar << figureColor;
	}
	else
	{
		ar >> P1;
		ar >> P2;
		ar >> figureFrameColor;
		ar >> Thick;
		ar >> figureColor;
	}
}
void Figure::Draw(CDC* dc)
{
	CPen pen(PS_SOLID, Thick ? 10 : 3, figureFrameColor);
	CPen* pOldPen = dc->SelectObject(&pen);
	CBrush brush(figureColor);
	CBrush* oldBrush = dc->SelectObject(&brush);
	CRect rect(P1.x, P1.y, P2.x, P2.y);
	dc->Rectangle(&rect);
}
CPoint Figure::getP1() const
{
	return P1;
}
CPoint Figure::getP2() const
{
	return P2;
}
void Figure::Redefine(CPoint p1, CPoint p2)
{
	P1 = p1;
	P2 = p2;
}
bool Figure::isInside(const CPoint &P) const
{
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);
}
int Figure::calcArea()
{
	return 0;
}
int Figure::calcPerimeter()
{
	return 0;
}

