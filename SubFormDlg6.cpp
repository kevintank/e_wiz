// SubFormDlg6.cpp : implementation file
//

#include "stdafx.h"
#include "TestDlg.h"
#include "SubFormDlg6.h"
#include "TestDlgDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg6 dialog


CSubFormDlg6::CSubFormDlg6(CWnd* pParent /*=NULL*/)
	: CDialog(CSubFormDlg6::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubFormDlg6)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSubFormDlg6::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubFormDlg6)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubFormDlg6, CDialog)
	//{{AFX_MSG_MAP(CSubFormDlg6)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg6 message handlers

void CSubFormDlg6::OnButtonPrev() 
{
	// TODO: Add your control notification handler code here
	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
    pDlg->m_SubForms.ShowSubForm(pDlg->m_currentFrame);
	 
}

void CSubFormDlg6::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
    pDlg->m_SubForms.ShowSubForm(6);

}

