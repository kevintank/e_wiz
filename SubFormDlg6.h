#if !defined(AFX_SUBFORMDLG6_H__347B8ACA_CAA1_48C7_A684_BF390B898600__INCLUDED_)
#define AFX_SUBFORMDLG6_H__347B8ACA_CAA1_48C7_A684_BF390B898600__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubFormDlg6.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg6 dialog

class CSubFormDlg6 : public CDialog
{
// Construction
public:
	CSubFormDlg6(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubFormDlg6)
	enum { IDD = IDD_SUBFORM6 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubFormDlg6)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubFormDlg6)
	afx_msg void OnButtonPrev();
	afx_msg void OnButtonNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBFORMDLG6_H__347B8ACA_CAA1_48C7_A684_BF390B898600__INCLUDED_)
