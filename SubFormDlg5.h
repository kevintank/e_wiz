#if !defined(AFX_SUBFORMDLG5_H__A754D68C_5254_4070_8948_795FB7C5A0CA__INCLUDED_)
#define AFX_SUBFORMDLG5_H__A754D68C_5254_4070_8948_795FB7C5A0CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubFormDlg5.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg5 dialog

class CSubFormDlg5 : public CDialog
{
// Construction
public:
	CSubFormDlg5(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubFormDlg5)
	enum { IDD = IDD_SUBFORM5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubFormDlg5)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubFormDlg5)
	afx_msg void OnButtonPrev();
	afx_msg void OnButtonNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBFORMDLG5_H__A754D68C_5254_4070_8948_795FB7C5A0CA__INCLUDED_)
