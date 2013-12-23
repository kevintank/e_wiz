#if !defined(AFX_SUBFORMDLG2_H__EA52743A_FBD1_448C_8408_F39AA4B249CC__INCLUDED_)
#define AFX_SUBFORMDLG2_H__EA52743A_FBD1_448C_8408_F39AA4B249CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubFormDlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg2 dialog

class CSubFormDlg2 : public CDialog
{
// Construction
public:
 
	CSubFormDlg2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubFormDlg2)
	enum { IDD = IDD_SUBFORM2 };
	CComboBox	m_last;
	CComboBox	m_first;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubFormDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	

	// Generated message map functions
	//{{AFX_MSG(CSubFormDlg2)
	afx_msg void OnButtonNext();
	afx_msg void OnButtonPrev();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboFirst();
	afx_msg void OnSelchangeComboLast();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBFORMDLG2_H__EA52743A_FBD1_448C_8408_F39AA4B249CC__INCLUDED_)
