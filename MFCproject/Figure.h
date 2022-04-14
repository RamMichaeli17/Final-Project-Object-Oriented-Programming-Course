#pragma once
#include "stdafx.h"
#include <math.h>
class Figure: public CObject
{
	DECLARE_SERIAL(Figure)
	CPoint P1;
	CPoint P2;
public:
	COLORREF figureFrameColor; // Each figure has a color , frame color  and thinkness
	COLORREF figureColor; 
	BOOL Thick = false;
    int shapeKind;
public:
	Figure();
	Figure(CPoint p1, CPoint p2);
	void Serialize(CArchive& ar);
	virtual void Draw(CDC* dc);
	CPoint getP1() const;
	CPoint getP2() const;
	virtual void Redefine(CPoint p1, CPoint p2);
	virtual bool isInside(const CPoint &P) const;
	virtual int calcArea();
	virtual int calcPerimeter();
};
