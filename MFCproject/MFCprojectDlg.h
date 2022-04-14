
// MFCprojectDlg.h : header file
//

#pragma once

#include "Figure.h"

#include "RectangleF.h"
#include "EllipseF.h"
#include "SquareF.h"
#include "CircleF.h"
#include "LineF.h"

class CMFCprojectDlg : public CDialogEx
{
// Construction
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CPoint start, end;
	bool isPressed=false;

	// Our Variables
	bool Move = false; // Indicates a "Move object" state
	bool Delete = false; // Indicates a "Delete object" state
	bool Draw = true; //Indicates a "Draw object" state
	bool Resize = false;// Indicates a "Shift object" state
	int temp=-1; // Here we save the position of the object we want to interact with
	CPoint lastPoint; // We use this point to be able to move the object by comparing current point with the last point
	int flag = 0; // An indication for the first mouse movement when we move an object
	bool Submit = false;// Indicates a "Write your name" state
	bool Area = false; //Indicates a "Calc area of an object" state
	COLORREF nameColor; // Color used for name
	COLORREF frameColor=(0,0,0); // Color used for the frame of the shapes || Default color is black
	COLORREF shapeColor; // Color used for shapes


	bool Perimeter = false;//Indicates a "Calc perimeter of an object" state

	 CTypedPtrArray< CObArray, Figure*> figs; // Array of figures
	 CTypedPtrArray< CObArray, Figure*> undo; // Array of undo figures
	

	 int futureFigureKind = 1; // 1 - 5 all our shapes

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int perimeter;
	CString name;
	BOOL Thick;
	int area;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton14();
};
