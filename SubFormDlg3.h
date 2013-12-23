#if !defined(AFX_SUBFORMDLG3_H__59FCA31F_D93B_406F_B978_6D6A37B6BF09__INCLUDED_)
#define AFX_SUBFORMDLG3_H__59FCA31F_D93B_406F_B978_6D6A37B6BF09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubFormDlg3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg3 dialog

class CSubFormDlg3 : public CDialog
{
// Construction
public:
	CSubFormDlg3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubFormDlg3)
	enum { IDD = IDD_SUBFORM3 };
	CString	m_dayfirst;
	CString	m_daylast;
	CString	m_totnum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubFormDlg3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubFormDlg3)
	afx_msg void OnButtonPrev();
	afx_msg void OnButtonAuto();
	afx_msg void OnButtonSelect();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBFORMDLG3_H__59FCA31F_D93B_406F_B978_6D6A37B6BF09__INCLUDED_)
