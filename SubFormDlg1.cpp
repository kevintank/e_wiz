// SubFormDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "TestDlg.h"
#include "SubFormDlg1.h"
#include "TestDlgDlg.h"
         
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg1 dialog


CSubFormDlg1::CSubFormDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CSubFormDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubFormDlg1)
	//}}AFX_DATA_INIT
}


void CSubFormDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubFormDlg1)
	DDX_Control(pDX, IDC_BUTTON_START, m_start);
	DDX_Control(pDX, IDC_BUTTON_DAP, m_dap);
	DDX_Control(pDX, IDC_BUTTON_SAMPLE, m_sample);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubFormDlg1, CDialog)
	//{{AFX_MSG_MAP(CSubFormDlg1)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_WM_PAINT()
//	ON_BN_CLICKED(IDC_BUTTON_MINI, OnButtonMini)
//	ON_BN_CLICKED(IDC_BUTTON_CLOSE, OnButtonClose)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg1 message handlers

void CSubFormDlg1::OnButtonStart() 
{
	// TODO: Add your control notification handler code here
 
     //CTestDlgDlg *pDlg = (CTestDlgDlg*)AfxGetMainWnd();
	 
	 CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();

     pDlg->m_SubForms.ShowSubForm(1);
	 


}

BOOL CSubFormDlg1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//배경 그림의 크기 만큼 윈도우 크기를 지정해 줄수 있다. 그쵸  
	BITMAP bmpInfo;
	m_bmpMainBG.LoadBitmap(IDB_BACK_NEW);
	m_bmpMainBG.GetBitmap(&bmpInfo);
	m_nMainWidth = bmpInfo.bmWidth;
	m_nMainHeight = bmpInfo.bmHeight;
	SetWindowPos(NULL,0,0,m_nMainWidth, m_nMainHeight,SWP_NOZORDER|SWP_NOMOVE);
    
	m_sample.SetSkin(IDB_BT_NOR, IDB_BT_NOR,IDB_BT_ROLL,0,0,IDB_BT_MASK,0,0,0);
   
	m_dap.SetSkin(IDB_DAP_NOR, IDB_DAP_NOR,IDB_DAP_ROLL,0,0,IDB_DAP_MASK,0,0,0);

	m_start.SetSkin(IDB_START_NOR, IDB_START_NOR,IDB_START_ROLL,0,0,IDB_START_MASK,0,0,0);
	
//	m_mini.SetSkin(IDB_MINI_NOR, IDB_MINI_NOR,IDB_MINI_OVER,0,0,IDB_MINI_MASK,0,0,0);

//	m_close.SetSkin(IDB_QUIT_NOR, IDB_QUIT_NOR,IDB_QUIT_OVER,0,0,IDB_QUIT_MASK,0,0,0);

   
	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
    CString str;

 	//str.Format("this->%d", 	pDlg->m_unit);
 	//AfxMessageBox(str);
	
     
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSubFormDlg1::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
 	CDC cdc;
	cdc.CreateCompatibleDC(&dc);
	cdc.SelectObject(m_bmpMainBG);
	dc.BitBlt(0,0,m_nMainWidth, m_nMainHeight, &cdc, 0,0, SRCCOPY);
	cdc.DeleteDC();
 
    // Do not call CDialog::OnPaint() for painting messages
}


//최소화 
/*
void CSubFormDlg1::OnButtonMini() 
{

 
    CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
    pDlg->Minimize();

	// TODO: Add your control notification handler code here
	
}
*/
//닫기 
/*
void CSubFormDlg1::OnButtonClose() 
{
 
	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
	pDlg->ExClose();
 

}
*/

  

void CSubFormDlg1::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);

	GetParent()->PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKEWPARAM(point.x, point.y));
   
  //아래처럼 해도 되는군....
  //  ::PostMessage(GetParent()->GetSafeHwnd(), WM_NCLBUTTONDOWN, HTCAPTION, MAKEWPARAM(point.x, point.y));
	
}
