// SubFormDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "TestDlg.h"
#include "SubFormDlg2.h"
#include "TestDlgDlg.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg2 dialog


CSubFormDlg2::CSubFormDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CSubFormDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubFormDlg2)
 	//}}AFX_DATA_INIT
}


void CSubFormDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubFormDlg2)
	DDX_Control(pDX, IDC_COMBO_LAST, m_last);
	DDX_Control(pDX, IDC_COMBO_FIRST, m_first);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubFormDlg2, CDialog)
	//{{AFX_MSG_MAP(CSubFormDlg2)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_CBN_SELCHANGE(IDC_COMBO_FIRST, OnSelchangeComboFirst)
	ON_CBN_SELCHANGE(IDC_COMBO_LAST, OnSelchangeComboLast)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg2 message handlers

void CSubFormDlg2::OnButtonNext() 
{
	// TODO: Add your control notification handler code here

	 CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();

	
    if(pDlg->GetFirst() == 0)
	{
  	  AfxMessageBox("출제할 범위를 선택해 주세요",MB_OK);

	}else{
   
		
        pDlg->m_SubForms.ShowSubForm(2);
	}


}

void CSubFormDlg2::OnButtonPrev() 
{
	// TODO: Add your control notification handler code here

	 CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
     pDlg->m_SubForms.ShowSubForm(0);
}

BOOL CSubFormDlg2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CString str;
    int totnumber;
	int i;
	char buffer[3];

	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
    totnumber = pDlg->GetUnit(); //값 가져오기 
    m_first.AddString("선택");
	m_last.AddString("선택");
  

	for(i=1; i <= totnumber; i++)
	{
       sprintf(buffer, "%d", i);
	   m_first.AddString(buffer);
       m_last.AddString(buffer);
	}
	 
	 m_first.SetCurSel(0);
     m_last.SetCurSel(0);
   
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSubFormDlg2::OnSelchangeComboFirst() 
{
	// TODO: Add your control notification handler code here
	int cur;
	cur = m_first.GetCurSel(); //현재 선택된 항목의 인덱스 얻음 
	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
    pDlg->SetFirst(cur); //값 저장 
   
	m_last.SetCurSel(cur);

}

void CSubFormDlg2::OnSelchangeComboLast() 
{
	// TODO: Add your control notification handler code here
	int cur;
	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
	cur = m_last.GetCurSel(); //현재 선택된 항목의 인덱스 얻음 
	pDlg->SetLast(cur);  
   	 
}

 
void CSubFormDlg2::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
   
}
