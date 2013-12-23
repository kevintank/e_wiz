#if !defined(AFX_SUBFORMDLG4_H__05C8060F_45DD_494A_839E_12A9C09B050C__INCLUDED_)
#define AFX_SUBFORMDLG4_H__05C8060F_45DD_494A_839E_12A9C09B050C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubFormDlg4.h : header file
//
#include "TestDlgDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg4 dialog

class CSubFormDlg4 : public CDialog
{
// Construction
public:
	CSubFormDlg4(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubFormDlg4)
	enum { IDD = IDD_SUBFORM4 };
	CComboBox	m_combo3;
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	CString	m_dayfirst;
	CString	m_daylast;
	CString	m_totnum;
	CString	m_select;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubFormDlg4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void IniCombo(CTestDlgDlg *pDlg);

	// Generated message map functions
	//{{AFX_MSG(CSubFormDlg4)
	afx_msg void OnButtonPrev();
	afx_msg void OnButtonNext();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnSelchangeComboOne();
	afx_msg void OnSelchangeComboThree();
	afx_msg void OnSelchangeComboTwo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBFORMDLG4_H__05C8060F_45DD_494A_839E_12A9C09B050C__INCLUDED_)
