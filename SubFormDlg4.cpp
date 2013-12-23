// SubFormDlg4.cpp : implementation file
//

#include "stdafx.h"
#include "TestDlg.h"
#include "SubFormDlg4.h"
#include "TestDlgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg4 dialog


CSubFormDlg4::CSubFormDlg4(CWnd* pParent /*=NULL*/)
	: CDialog(CSubFormDlg4::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubFormDlg4)
	m_dayfirst = _T("");
	m_daylast = _T("");
	m_totnum = _T("");
	m_select = _T("");
	//}}AFX_DATA_INIT
}


void CSubFormDlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubFormDlg4)
	DDX_Control(pDX, IDC_COMBO_TWO, m_combo3);
	DDX_Control(pDX, IDC_COMBO_THREE, m_combo2);
	DDX_Control(pDX, IDC_COMBO_ONE, m_combo1);
	DDX_Text(pDX, IDC_DAY_FIRST, m_dayfirst);
	DDX_Text(pDX, IDC_DAY_LAST, m_daylast);
	DDX_Text(pDX, IDC_TOTNUM, m_totnum);
	DDX_Text(pDX, IDC_EDIT_SELECT, m_select);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubFormDlg4, CDialog)
	//{{AFX_MSG_MAP(CSubFormDlg4)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_WM_SHOWWINDOW()
	ON_CBN_SELCHANGE(IDC_COMBO_ONE, OnSelchangeComboOne)
	ON_CBN_SELCHANGE(IDC_COMBO_THREE, OnSelchangeComboThree)
	ON_CBN_SELCHANGE(IDC_COMBO_TWO, OnSelchangeComboTwo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg4 message handlers

void CSubFormDlg4::OnButtonPrev() 
{
	// TODO: Add your control notification handler code here
	  CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
      pDlg->m_SubForms.ShowSubForm(2);

}

void CSubFormDlg4::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	
   CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
   pDlg->m_SubForms.ShowSubForm(5);
  
    
}

void CSubFormDlg4::OnShowWindow(BOOL bShow, UINT nStatus) 
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


   IniCombo(pDlg);
	
}

 

void CSubFormDlg4::IniCombo(CTestDlgDlg *pDlg)
{
	
	CString str;
    int totnumber;
	int i;
	char buffer[3];

	//CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
    totnumber = pDlg->GetTotnum();
   
	m_combo1.AddString("선택");
	m_combo2.AddString("선택");
	m_combo3.AddString("선택");

	for(i=0; i <= totnumber; i++)
	{
       sprintf(buffer, "%d", i);
	   m_combo1.AddString(buffer);
       m_combo2.AddString(buffer);
	   m_combo3.AddString(buffer);
	}
	 
	 m_combo1.SetCurSel(0);
     m_combo2.SetCurSel(0);
     m_combo3.SetCurSel(0); 

}

void CSubFormDlg4::OnSelchangeComboOne() 
{
	// TODO: Add your control notification handler code here
	
	int cur,tot, i;
 
    char buffer[3];

	cur = m_combo1.GetCurSel(); //현재 선택된 항목의 인덱스 얻음 
     
	if( cur > 1)
	{
		
      m_combo2.ResetContent();
	  m_combo3.ResetContent();

  	  CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
      //pDlg->SetFirst(cur); //값 저장 
      //m_last.SetCurSel(cur);
    
      tot = pDlg->GetTotnum();
      tot = tot - cur;
      tot = tot + 1;

      m_combo2.AddString("선택");
      m_combo3.AddString("선택");

	for(i=0; i <= tot; i++)
	{
       sprintf(buffer, "%d", i);
	   m_combo2.AddString(buffer);
	   m_combo3.AddString(buffer);
	}
	 	 
     m_combo2.SetCurSel(0);
     m_combo3.SetCurSel(0); 

	}else{


	  m_combo2.ResetContent();
	  m_combo3.ResetContent();

CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
    tot = pDlg->GetTotnum();
	m_combo2.AddString("선택");
	m_combo3.AddString("선택");

	for(i=0; i <= tot; i++)
	{
       sprintf(buffer, "%d", i);
	   m_combo1.AddString(buffer);
       m_combo2.AddString(buffer);
	   m_combo3.AddString(buffer);
	}
	 
	 
     m_combo2.SetCurSel(0);
     m_combo3.SetCurSel(0); 


	}



}

void CSubFormDlg4::OnSelchangeComboThree() 
{
	// TODO: Add your control notification handler code here
	
}

void CSubFormDlg4::OnSelchangeComboTwo() 
{
	// TODO: Add your control notification handler code here
	
}
