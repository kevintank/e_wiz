// SubFormDlg3.cpp : implementation file
//

#include "stdafx.h"
#include "TestDlg.h"
#include "SubFormDlg3.h"
#include "TestDlgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg3 dialog


CSubFormDlg3::CSubFormDlg3(CWnd* pParent /*=NULL*/)
	: CDialog(CSubFormDlg3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubFormDlg3)
	m_dayfirst = _T("");
	m_daylast = _T("");
	m_totnum = _T("");
	//}}AFX_DATA_INIT
}


void CSubFormDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubFormDlg3)
	DDX_Text(pDX, IDC_DAY_FIRST, m_dayfirst);
	DDX_Text(pDX, IDC_DAY_LAST, m_daylast);
	DDX_Text(pDX, IDC_TOTNUM, m_totnum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubFormDlg3, CDialog)
	//{{AFX_MSG_MAP(CSubFormDlg3)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_AUTO, OnButtonAuto)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, OnButtonSelect)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg3 message handlers

void CSubFormDlg3::OnButtonPrev() 
{
	// TODO: Add your control notification handler code here

   CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
   pDlg->m_SubForms.ShowSubForm(1);



}

void CSubFormDlg3::OnButtonAuto() 
{
	// TODO: Add your control notification handler code here
	
	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
    pDlg->m_SubForms.ShowSubForm(3);
    pDlg->m_currentFrame = 3;  //자동 일때 

}

void CSubFormDlg3::OnButtonSelect() 
{
	 CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
     pDlg->m_SubForms.ShowSubForm(4);
     pDlg->m_currentFrame = 4; //수동 일때 

	// TODO: Add your control notification handler code here
	
}

void CSubFormDlg3::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
 
	int ifirst, ilast, inum;
    CString sz1, sz2, sz3;

	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();

	ifirst = pDlg->GetFirst();
	ilast = pDlg->GetLast();
 	inum = pDlg->Getquestionnum();

	sz1.Format("%d", ifirst);
    sz2.Format("%d", ilast);
    sz3.Format("%d", inum);

    m_dayfirst = sz1;
	m_daylast  = sz2;
 	m_totnum = sz3;

	UpdateData(FALSE); 
	  
}

 
