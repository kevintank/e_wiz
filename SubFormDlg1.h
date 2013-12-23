#if !defined(AFX_SUBFORMDLG1_H__9C363D48_6223_40BC_81D6_148363D4AEFC__INCLUDED_)
#define AFX_SUBFORMDLG1_H__9C363D48_6223_40BC_81D6_148363D4AEFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubFormDlg1.h : header file
//
#include "xSkinButton.h"
/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg1 dialog

class CSubFormDlg1 : public CDialog
{
// Construction
public:
	CSubFormDlg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubFormDlg1)
	enum { IDD = IDD_SUBFORM1 };
	CxSkinButton	m_start;
	CxSkinButton	m_dap;
	CxSkinButton	m_sample;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubFormDlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_nMainHeight;
	int m_nMainWidth;
	CBitmap m_bmpMainBG;

	// Generated message map functions
	//{{AFX_MSG(CSubFormDlg1)
	afx_msg void OnButtonStart();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//afx_msg void OnButtonMini();
	//afx_msg void OnButtonClose();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBFORMDLG1_H__9C363D48_6223_40BC_81D6_148363D4AEFC__INCLUDED_)
