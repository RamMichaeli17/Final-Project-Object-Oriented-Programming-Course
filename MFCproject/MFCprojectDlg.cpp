
// MFCprojectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCprojectDlg dialog

CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
	, name(_T(""))
	, area(0)
	, Thick(FALSE)
	, perimeter(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT1, area);
	DDX_Check(pDX, IDC_CHECK1, Thick);
	DDX_Text(pDX, IDC_EDIT3, perimeter);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CMFCprojectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCprojectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCprojectDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCprojectDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCprojectDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCprojectDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCprojectDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCprojectDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCprojectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCprojectDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCprojectDlg::OnBnClickedButton8)

	ON_BN_CLICKED(IDC_BUTTON4, &CMFCprojectDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCprojectDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCprojectDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCprojectDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCprojectDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCprojectDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCprojectDlg::OnBnClickedButton12)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCprojectDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCprojectDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCprojectDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCprojectDlg::OnBnClickedButton14)
END_MESSAGE_MAP()




BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);		
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < figs.GetSize(); i++) // Here we draw all the figures over and over again
			figs[i]->Draw(&dc);
		
		CDialogEx::OnPaint();
		if (Submit == true && name !="") // If we entered a name , we want this code to run
		{
			CRect rect;
			GetClientRect(&rect);  // Get screen rectangle
			CFont font;
			font.CreatePointFont(350, _T("Arial"));
			CFont* oldFont = dc.SelectObject(&font);
			dc.SetBkMode(TRANSPARENT); // Transparent so they hide other
			dc.SetTextColor(nameColor); //Set color according to user preference
			dc.DrawText(name, &rect, DT_SINGLELINE | DT_BOTTOM | DT_LEFT); // draw
			rect.OffsetRect(0,-50); // offset a little
			dc.DrawText(_T("Hello"), &rect, DT_SINGLELINE | DT_BOTTOM | DT_LEFT); // add hello
			CDialogEx::OnPaint();
		}
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	isPressed = true;
	if (Perimeter)
	{
		for (int i = figs.GetSize() - 1; i >= 0; i--) // We run from the end to the beginning , to shift the latest object (the front object)
		{
			if (figs[i]->isInside(point)) // If mouse cursor isInside
			{
				UpdateData(TRUE);
				temp = i;
				perimeter = figs[i]->calcPerimeter();
				UpdateData(FALSE);
				break;
			}
		}
	}
	if (Area)
	{
		for (int i = figs.GetSize() - 1; i >= 0; i--) // We run from the end to the beginning , to shift the latest object (the front object)
		{
			if (figs[i]->isInside(point)) // If mouse cursor isInside
			{
				UpdateData(TRUE);
				temp = i;
				area=figs[i]->calcArea();
				UpdateData(FALSE);
				break;
				
			}
		}
		

		
	}
	if (Resize)
	{
		for (int i = figs.GetSize() - 1; i >= 0; i--) // We run from the end to the beginning , to shift the latest object (the front object)
		{
			if (figs[i]->isInside(point)) // If mouse cursor isInside
			{
				temp = i;
				break;
			}

		}
	}
	if (Delete) // If we are in delete state 
	{
		for (int i = figs.GetSize()-1; i >= 0; i--) // We run from the end to the beginning , to delete the latest object (the front object)
		{
			if (figs[i]->isInside(point)) // If mouse cursor isInside
			{
				figs[i]->P1.x = NULL; // Delete all his values
				figs[i]->P1.y = NULL;
				figs[i]->P2.x = NULL;
				figs[i]->P2.y = NULL;
				Invalidate();
				break;
			}

		}
	}
	
	else if(Move) // If we are in a move state
	{
		int counter = 0; // Here we count how many objects our mouse isInside
		for (int i = 0; i < figs.GetSize(); i++)
		{
			if (figs[i]->isInside(point)) // If mouse cursor isInside
			{
				counter++;
				temp = i; // Save the latest index
			}
			else if (counter == 0)temp = -1; // Else we assign -1 to temp to indicate our mouse isn't pointing on any object
		}
	}

	else // If we are not in a move state , we are drawing
	{

	start = point;
	switch (futureFigureKind) // What shape ? add to figure array
	{
	case 1:
		figs.Add(new RectangleF(start, start));
		break;
	case 2:
		figs.Add(new EllipseF(start, start));
		break;
	case 3:
		figs.Add(new SquareF(start, start));
		break;
	case 4:
		figs.Add(new CircleF(start, start));
		break;
	case 5:
		figs.Add(new LineF(start, start));
		break;
	}
	CDialogEx::OnLButtonDown(nFlags, point);

	}
}


void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{	
	if (isPressed && Draw) // If we're not in a "Move object" state and mouse is pressed , we wanna draw
	{
		end = point;
		figs[figs.GetSize() - 1]->Redefine(start,end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
		undo.RemoveAll(); // Cleaning the undo array
	}
	isPressed = false;
	flag = 0;

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (Resize && isPressed && temp != -1)
	{
		figs[temp]->Redefine(figs[temp]->P1, point);
		Invalidate();
	}
	if (Move && temp != -1 && isPressed) // If we're in a "Move object" state and our mouse is inside atleast 1 object and mouse is pressed
	{
		if (flag == 0) // If it's the first mouse movement
		{
			lastPoint = point;
			flag = 1;
		}
		else // For any other mouse movements , calculate the new position by comparing with the last position and adjusting
		{
			figs[temp]->P1.x += (point.x - lastPoint.x);
			figs[temp]->P1.y += (point.y - lastPoint.y);
			figs[temp]->P2.x += (point.x - lastPoint.x);
			figs[temp]->P2.y += (point.y - lastPoint.y);
			lastPoint = point;
			Invalidate();
		}
	}

	else if(isPressed && Draw) // If we're not in a "Move object" and mouse is pressed we draw
	{
		end = point;
		figs[figs.GetSize()-1]->Redefine(start,end);
		figs[figs.GetSize() - 1]->figureColor = shapeColor;
		figs[figs.GetSize() - 1]->figureFrameColor = frameColor;
		figs[figs.GetSize() - 1]->Thick = Thick;
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


// Each button activates itself and deactivates all the other buttons

void CMFCprojectDlg::OnBnClickedButton1()
{
	// Save file pattern
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}

}


void CMFCprojectDlg::OnBnClickedButton2()
{
	// Load file pattern
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void CMFCprojectDlg::OnEnChangeEdit2() // Name box
{
}


void CMFCprojectDlg::OnBnClickedButton5() // Move button
{
	Move = true; // This indicates that we want to move objects , and not draw for example.
	Delete = false;
	Draw = false;
	Resize = false;
	Area = false;
	Perimeter = false;
}


void CMFCprojectDlg::OnBnClickedButton6() // Draw button
{
	Move = false; // Since draw is our default , we just need to disable Move
	Delete = false;
	Draw = true;
	Resize = false;
	Area = false;
	Perimeter = false;
}


void CMFCprojectDlg::OnBnClickedButton7() // Delete button
{
	Delete = true;
	Move = false;
	Draw = false;
	Resize = false;
	Area = false;
	Perimeter = false;
}


void CMFCprojectDlg::OnBnClickedButton3() // Clear button
{
	figs.RemoveAll();
	Submit = false;
	Invalidate();
	OnBnClickedButton6();
}


void CMFCprojectDlg::OnBnClickedButton8() // Resize button
{
	Delete = false;
	Move = false;
	Draw = false;
	Resize = true;
	Area = false;
	Perimeter = false;
}


void CMFCprojectDlg::OnBnClickedButton4() // Submit button
{
		UpdateData(TRUE);
		UpdateData(FALSE);
		Invalidate();
		Submit = true;
}


void CMFCprojectDlg::OnEnChangeEdit1() //Prestent the area of a shape
{
	UpdateData(TRUE);
	UpdateData(FALSE);
}


void CMFCprojectDlg::OnBnClickedButton9() //Area button
{
	Delete = false;
	Move = false;
	Draw = false;
	Resize = false; 
	Area = true;
	Perimeter = false;
}


void CMFCprojectDlg::OnBnClickedCheck1()  // Think button
{
	UpdateData(true);
	Invalidate();
}


void CMFCprojectDlg::OnBnClickedButton10() // Set the color of the frames
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		frameColor = dlg.GetColor();
	}
}


void CMFCprojectDlg::OnBnClickedButton13() // Shape Color
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		shapeColor = dlg.GetColor();
	}
}


void CMFCprojectDlg::OnBnClickedButton11() // Set the color of the name
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		nameColor = dlg.GetColor();
	}
	Invalidate();
}


void CMFCprojectDlg::OnBnClickedButton12() // perimeter button
{
	Delete = false;
	Move = false;
	Draw = false;
	Resize = false;
	Area = false;
	Perimeter = true;
}


void CMFCprojectDlg::OnEnChangeEdit3() // //Prestent the perimeter of a shape
{
	UpdateData(TRUE);
	UpdateData(FALSE);
}


void CMFCprojectDlg::OnBnClickedButton15() // Undo button
{
	if (figs.GetSize() > 0) // If there are figures in the figs array
	{
		Figure* fig = figs[figs.GetSize() - 1];
		figs.RemoveAt(figs.GetSize() - 1);
		undo.Add(fig);
	}
	Invalidate();
}


void CMFCprojectDlg::OnBnClickedButton14() // Redo button
{
	if (undo.GetSize() > 0) // If there are figures in the undo array
	{
		Figure* fig = undo[undo.GetSize() - 1];
		undo.RemoveAt(undo.GetSize() - 1);
		figs.Add(fig);
	}
	Invalidate();
}


// SHAPES

void CMFCprojectDlg::OnBnClickedRadio1()
{
	futureFigureKind = 1; // Rectangle
	OnBnClickedButton6(); // Call to draw button
}


void CMFCprojectDlg::OnBnClickedRadio2()
{
	futureFigureKind = 2; // Ellipse
	OnBnClickedButton6(); // Call to draw button
}


void CMFCprojectDlg::OnBnClickedRadio3()
{
	futureFigureKind = 3; // Square
	OnBnClickedButton6(); // Call to draw button
}


void CMFCprojectDlg::OnBnClickedRadio5()
{
	futureFigureKind = 4; // Circle
	OnBnClickedButton6(); // Call to draw button
}


void CMFCprojectDlg::OnBnClickedRadio6()
{
	futureFigureKind = 5; // Line
	OnBnClickedButton6(); // Call to draw button
}