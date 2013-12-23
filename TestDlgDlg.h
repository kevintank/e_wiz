// TestDlgDlg.h : header file
//

#if !defined(AFX_TESTDLGDLG_H__65F1F5B6_0CB1_4BB6_B11B_3AC450FD257D__INCLUDED_)
#define AFX_TESTDLGDLG_H__65F1F5B6_0CB1_4BB6_B11B_3AC450FD257D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "subformcollection.h"
#include "xSkinButton.h"
#include "Ado.h"

/////////////////////////////////////////////////////////////////////////////
// CTestDlgDlg dialog

class CTestDlgDlg : public CDialog
{
// Construction
public:
	int GetTotnum();
 
	int Getquestionnum();
	void SetLast(int i);
	void SetFirst(int i);
	int GetLast();
	int GetFirst();
	int m_currentFrame;
	void Dlg_Exit();
	CTestDlgDlg(CWnd* pParent = NULL);	// standard constructor
    CSubFormCollection m_SubForms;
	void Minimize();
    void ExClose();
    int GetUnit();
	void SetUnit(int i);

 
// Dialog Data
	//{{AFX_DATA(CTestDlgDlg)
	enum { IDD = IDD_TESTDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlgDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_type3;
	int m_type2;
	int m_type1;
	int m_totnum;
	int m_selectlast;
	int m_selectfirst;


	HICON m_hIcon;
   	CxSkinButton m_mini;
	CxSkinButton m_close;
    CAdo m_ado;  //ado class
   
	// Generated message map functions
	//{{AFX_MSG(CTestDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	//afx_msg UINT OnNcHitTest(CPoint point);
#if _MSC_VER >= 1400
afx_msg LRESULT OnNcHitTest(CPoint point);
#else
afx_msg UINT OnNcHitTest(CPoint point);
#endif



	afx_msg void OnButtonMini();
	afx_msg void OnButtonClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
 
private:
  	int m_unit;//ÀüÃ¼¼ö 
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLGDLG_H__65F1F5B6_0CB1_4BB6_B11B_3AC450FD257D__INCLUDED_)
