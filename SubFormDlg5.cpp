// SubFormDlg5.cpp : implementation file
//

#include "stdafx.h"
#include "TestDlg.h"
#include "SubFormDlg5.h"
#include "TestDlgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg5 dialog


CSubFormDlg5::CSubFormDlg5(CWnd* pParent /*=NULL*/)
	: CDialog(CSubFormDlg5::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubFormDlg5)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSubFormDlg5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubFormDlg5)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubFormDlg5, CDialog)
	//{{AFX_MSG_MAP(CSubFormDlg5)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg5 message handlers

void CSubFormDlg5::OnButtonPrev() 
{
	// TODO: Add your control notification handler code here
	  CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
      pDlg->m_SubForms.ShowSubForm(2);


}

void CSubFormDlg5::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
     pDlg->m_SubForms.ShowSubForm(5);
 
}
