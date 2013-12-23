#if !defined(AFX_SUBFORMDLG7_H__346092B1_76A5_42F4_BDFC_CC948E4627B8__INCLUDED_)
#define AFX_SUBFORMDLG7_H__346092B1_76A5_42F4_BDFC_CC948E4627B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubFormDlg7.h : header file
//

typedef struct tagSortInfo
{
	CListCtrl * pListControl;
	int nColumnNo;
	bool nAscendingSortOrder;
}SortInfo;


/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg7 dialog

class CSubFormDlg7 : public CDialog
{
// Construction
private:

	SortInfo m_SortInfo;

public:
	void SetListCtrlSel(CListCtrl *pCtrl);
	void MoveData(CListCtrl *DestItm);
	CSubFormDlg7(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubFormDlg7)
	enum { IDD = IDD_SUBFORM7 };
	CListCtrl	m_list4;
	CListCtrl	m_list3;
	CListCtrl	m_list2;
	CListCtrl	m_list1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubFormDlg7)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation

protected:

	// Generated message map functions
	//{{AFX_MSG(CSubFormDlg7)
	afx_msg void OnButtonPrev();
	afx_msg void OnButtonEnd();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton5();
	afx_msg void OnButton7();
	afx_msg void OnButton9();
	afx_msg void OnButton6();
	afx_msg void OnButton8();
	afx_msg void OnButton10();
	afx_msg void OnItemclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// 정렬된 컬럼의 번호 기억
	int sortColumn;
	// 오름차순인지 내림차순인지 기억하기
	bool sortDirect;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBFORMDLG7_H__346092B1_76A5_42F4_BDFC_CC948E4627B8__INCLUDED_)
