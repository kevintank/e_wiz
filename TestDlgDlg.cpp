// TestDlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestDlg.h"
#include "TestDlgDlg.h"
#include "SubFormDlg1.h"
#include "SubFormDlg2.h"
#include "SubFormDlg3.h"
#include "SubFormDlg4.h"
#include "SubFormDlg5.h"
#include "SubFormDlg6.h"
#include "SubFormDlg7.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlgDlg dialog

CTestDlgDlg::CTestDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_unit = 0; 
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlgDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
		DDX_Control(pDX, IDC_B_MINI, m_mini);
	    DDX_Control(pDX, IDC_B_CLOSE, m_close);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDC_B_MINI, OnButtonMini)
	ON_BN_CLICKED(IDC_B_CLOSE, OnButtonClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlgDlg message handlers

BOOL CTestDlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
 
	m_mini.SetSkin(IDB_MINI_NOR, IDB_MINI_NOR,IDB_MINI_OVER,0,0,IDB_MINI_MASK,0,0,0);
  	m_close.SetSkin(IDB_QUIT_NOR, IDB_QUIT_NOR,IDB_QUIT_OVER,0,0,IDB_QUIT_MASK,0,0,0);

    
	this->SetWindowText("Voca");
    	   
	//Provider=Microsoft.Jet.OLEDB.4.0;Data Source=D:\\REPORTDB.mdb"  문자열 만들기 
    m_ado.DB_Init("D:\\REPORTDB.mdb");  //데이타 베이스 연결 

	CString strQuery; 
    int rst;
	CString sql = "Select * From TB_LINECODE";
	 
	m_ado.DB_Open(sql,"");  // 오픈 
    m_ado.DB_MoveLast();    //마지막 레코드로 이동 
   	rst = m_ado.GetValueInt("unit"); //정수 값으로 받아오기 
   	m_unit = rst;
	//strQuery.Format("값은 %d", m_unit);
    //AfxMessageBox(strQuery);


    CRect r;
 	   
	(GetDlgItem(IDC_SUBFORM_FRAME))->GetWindowRect(r);
	m_SubForms.SetCenterPos(r);
	
    CSubFormDlg1 *pDlg1 = new CSubFormDlg1;
	m_SubForms.CreateSubForm(pDlg1,IDD_SUBFORM1,this);
	

	CSubFormDlg2 *pDlg2 = new CSubFormDlg2;
	m_SubForms.CreateSubForm(pDlg2,IDD_SUBFORM2,this);
	
	CSubFormDlg3 *pDlg3 = new CSubFormDlg3;
	m_SubForms.CreateSubForm(pDlg3,IDD_SUBFORM3,this);

	CSubFormDlg4 *pDlg4 = new CSubFormDlg4;
	m_SubForms.CreateSubForm(pDlg4,IDD_SUBFORM4,this);
    

	CSubFormDlg5 *pDlg5 = new CSubFormDlg5;
	m_SubForms.CreateSubForm(pDlg5,IDD_SUBFORM5,this);
    

	CSubFormDlg6 *pDlg6 = new CSubFormDlg6;
	m_SubForms.CreateSubForm(pDlg6,IDD_SUBFORM6,this);
    

	CSubFormDlg7 *pDlg7 = new CSubFormDlg7;
	m_SubForms.CreateSubForm(pDlg7,IDD_SUBFORM7,this);
        
	m_SubForms.ShowSubForm();



	 

	//CString strQuery; 
    //strQuery.Format("SELECT * FROM MyTbl where MyTest like '%%반가%%'");

	//m_ado.DB_Excute(sql,"");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDlgDlg::OnPaint() 
{       
	
	CClientDC dc(this); //클라이언트 DC생성 
	CBitmap myBit, *poldBit;
	CDC memDC; //메모리 DC
	BITMAP bm; //비트맵 정버를 저장할 변수 

	myBit.LoadBitmap(IDB_TITLEBAR);   //비트맵 리소스 로드 
	myBit.GetObject(sizeof(BITMAP), &bm); //비트맵 오브젝트에 대한 정보 얻기
	int m_Width = bm.bmWidth;    //비트맵 크기를 얻는다. 
	int m_Height = bm.bmHeight;

	memDC.CreateCompatibleDC(&dc);
	poldBit=(CBitmap*)memDC.SelectObject(&myBit);
     
	dc.BitBlt(0,0, m_Width, m_Height, &memDC, 0,0, SRCCOPY); //DC에 저장된이미지 부리기
	memDC.SelectObject(poldBit);
	ReleaseDC(&memDC);
	
	if (IsIconic())  //윈도우가 아이콘 상태인지 검사 
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

	
	}
	else
	{
		CDialog::OnPaint();
	}


}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

 

void CTestDlgDlg::Dlg_Exit()
{
   OnOK();
}

void CTestDlgDlg::Minimize()
{

  //	ShowWindow(SW_MINIMIZE);
}


void CTestDlgDlg::ExClose()
{
//	 OnOK();

}

//UINT CTestDlgDlg::OnNcHitTest(CPoint point) 
//{
	// TODO: Add your message handler code here and/or call default
	
#if _MSC_VER >= 1400
LRESULT CTestDlgDlg::OnNcHitTest(CPoint point)
#else
UINT CTestDlgDlg::OnNcHitTest(CPoint point)
#endif
{
	return	HTCAPTION;

	//return CDialog::OnNcHitTest(point);
}

//}


//최소화 
 
void CTestDlgDlg::OnButtonMini() 
{

 
   // CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
   // pDlg->Minimize();

	ShowWindow(SW_MINIMIZE);

	// TODO: Add your control notification handler code here
	
}
 
//닫기 
 
void CTestDlgDlg::OnButtonClose() 
{
 	 OnOK();
//	CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
//	pDlg->ExClose();
}



BOOL CTestDlgDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class

	return CDialog::DestroyWindow();
}

void CTestDlgDlg::SetUnit(int i)
{
   m_unit = i;
}

int CTestDlgDlg::GetUnit()
{
	
  
	return m_unit;

}

int CTestDlgDlg::GetFirst()
{

	return m_selectfirst;
}

int CTestDlgDlg::GetLast()
{
   return m_selectlast;
}

void CTestDlgDlg::SetFirst(int i)
{
     m_selectfirst = i;
}

void CTestDlgDlg::SetLast(int i)
{
     m_selectlast = i;

}


int CTestDlgDlg::Getquestionnum()//몇문제 인가 알아 보기 
{
    
    CString strQuery; 
    int rst = 0;
	strQuery.Format("Select MaxNum From MaxVoca  where Pack=1 and dayUnit>=%d and dayUnit<=%d", m_selectfirst, m_selectlast);
	m_ado.DB_Open(strQuery,"");  // Execute를 써야 할듯  
      
	while(!m_ado.DB_IsEof())
	{	
	 	//필드에서 값 가져오기 
	    rst = rst + m_ado.GetValueInt("MaxNum");
     	m_ado.DB_MoveNext();
	}
  
	m_totnum = rst;  //문제 갯수 구하기 
  return rst; 

}


int CTestDlgDlg::GetTotnum()
{

	 return m_totnum;
}
