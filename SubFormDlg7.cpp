// SubFormDlg7.cpp : implementation file
//

#include "stdafx.h"
#include "TestDlg.h"
#include "SubFormDlg7.h"
#include "TestDlgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg7 dialog


CSubFormDlg7::CSubFormDlg7(CWnd* pParent /*=NULL*/)
	: CDialog(CSubFormDlg7::IDD, pParent)
	, sortColumn(-1)
	, sortDirect(true)
{
	//{{AFX_DATA_INIT(CSubFormDlg7)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSubFormDlg7::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubFormDlg7)
	DDX_Control(pDX, IDC_LIST4, m_list4);
	DDX_Control(pDX, IDC_LIST3, m_list3);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubFormDlg7, CDialog)
	//{{AFX_MSG_MAP(CSubFormDlg7)
	ON_BN_CLICKED(IDC_BUTTON_PREV, OnButtonPrev)
	ON_BN_CLICKED(IDC_BUTTON_END, OnButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_NOTIFY(HDN_ITEMCLICKA, 0, OnItemclickList1)
	ON_NOTIFY(HDN_ITEMCLICKW, 0, OnItemclickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubFormDlg7 message handlers

void CSubFormDlg7::OnButtonPrev() 
{
	// TODO: Add your control notification handler code here
	
	  CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
      pDlg->m_SubForms.ShowSubForm(5);


}

void CSubFormDlg7::OnButtonEnd() 
{
	// TODO: Add your control notification handler code here

    CTestDlgDlg *pDlg = (CTestDlgDlg*)GetParent();
	pDlg->Dlg_Exit();

}

BOOL CSubFormDlg7::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	LV_COLUMN lvcolumn;
	char *list[2] = {"일차","단어"};
	int width[2] = {40,260};
   
	m_list1.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
    m_list2.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list3.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_list4.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);


	for(int i=0; i<2;i++)
	{
   	 lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
     lvcolumn.fmt = LVCFMT_LEFT;
	 lvcolumn.pszText = list[i];
	 lvcolumn.iSubItem = i;
	 lvcolumn.cx = width[i];

	 m_list1.InsertColumn(i, &lvcolumn);
	 m_list2.InsertColumn(i, &lvcolumn);
	 m_list3.InsertColumn(i, &lvcolumn);
	 m_list4.InsertColumn(i, &lvcolumn);
	
	}

	LV_ITEM lvitem0, lvitem1;
	CString numericString;
	char itemString[2] = " ";

	lvitem0.mask = LVIF_TEXT;
	lvitem0.iSubItem = 0;

	lvitem1.mask = LVIF_TEXT;
	lvitem1.iSubItem = 1;


	for(int i=0; i < 26; i++){
        
		lvitem0.iItem = i;
		lvitem1.iItem = i;

        numericString.Format("%d", i + 1);
		itemString[0]='A' + i;
		lvitem0.pszText=(LPSTR)numericString.operator const char*(); 
		lvitem1.pszText=itemString;


		m_list1.InsertItem(&lvitem0);
		m_list1.SetItem(&lvitem1);

	}


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


//뜻 쓰기 
void CSubFormDlg7::OnButton5() 
{

   //TODO: Add your control notification handler code here
	MoveData( &m_list2);
}

//단어
void CSubFormDlg7::OnButton7() 
{
	// TODO: Add your control notification handler code here
	MoveData( &m_list3);
}

//빈칸
void CSubFormDlg7::OnButton9() 
{
	// TODO: Add your control notification handler code here
	MoveData( &m_list4);
}

void CSubFormDlg7::MoveData(CListCtrl  *DestItm)
{

	int selected;
	CString name, tel;
	selected = m_list1.GetNextItem(-1, LVNI_SELECTED);
    int nItemNum1=m_list1.GetItemCount();

	if(selected == -1)
	{
		AfxMessageBox("선택된 데이타가 없습니다.");
	}
	else
	{
       		
		//넘길곳의 라인수 얻기 
	    LV_ITEM lvItem;
        int nItemNum2=DestItm->GetItemCount();
		BOOL bDelete=false;

		 //list1에서 선택된 문자 얻기 
		name = m_list1.GetItemText(selected,0);
        tel = m_list1.GetItemText(selected,1);

		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = nItemNum2;
		lvItem.iSubItem = 0;
		lvItem.pszText=(LPTSTR)(LPCSTR)name;
		DestItm->InsertItem(&lvItem);


		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = nItemNum2;
		lvItem.iSubItem = 1;
		lvItem.pszText =(LPTSTR)(LPCSTR)tel;
		DestItm->SetItem(&lvItem);

    
		//선택된 라인 지우기 
 
        if(selected < nItemNum1 && (selected >= 0))
			  bDelete=true;
		if(bDelete)
		{
			m_list1.DeleteItem(selected);
		}
		else
		 AfxMessageBox("선택 아이템이 없습니다");
		
		
	}

}


void CSubFormDlg7::SetListCtrlSel(CListCtrl *pCtrl)
{

	int selected;
	CString name, tel;

	//삭제할 리스트 컨트롤의 선택 위치는 ?
	selected = pCtrl->GetNextItem(-1, LVNI_SELECTED); 
	//삭제할 리스트 컨트롤의 최대갯수는?
	int nItemNum1=pCtrl->GetItemCount();

	if(selected == -1)
	{
		AfxMessageBox("선택된 데이타가 없습니다.");
	}
	else
	{
       		
		//넘길곳의 라인수 얻기 
	    LV_ITEM lvItem;
        int nItemNum2=m_list1.GetItemCount();
		BOOL bDelete=false;

		 //선택된 문자 얻기 
		name = pCtrl->GetItemText(selected,0);
        tel =  pCtrl->GetItemText(selected,1);
		
		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = nItemNum2;
		lvItem.iSubItem = 0;
		lvItem.pszText=(LPTSTR)(LPCSTR)name;
		m_list1.InsertItem(&lvItem);
		
    	lvItem.mask = LVIF_TEXT;
		lvItem.iItem = nItemNum2;
		lvItem.iSubItem = 1;
		lvItem.pszText =(LPTSTR)(LPCSTR)tel;
		m_list1.SetItem(&lvItem);
        
		//선택된 라인 지우기 
 
        if(selected < nItemNum1 && (selected >= 0))
			  bDelete=true;
		if(bDelete)
		{
			pCtrl->DeleteItem(selected);
		}
		else
		 AfxMessageBox("선택 아이템이 없습니다");
		
		
	}


}

void CSubFormDlg7::OnButton6() 
{
	// TODO: Add your control notification handler code here
		SetListCtrlSel( &m_list2);
}

void CSubFormDlg7::OnButton8() 
{
	// TODO: Add your control notification handler code here
		SetListCtrlSel( &m_list3);
}

void CSubFormDlg7::OnButton10() 
{
	// TODO: Add your control notification handler code here
		SetListCtrlSel( &m_list4);
}


int CALLBACK CompareFunc(LPARAM lpOne, LPARAM lpTwo, LPARAM lpArg)
{
	 
	int nResult = 0;

	SortInfo * pSortInfo = (SortInfo *)lpArg;
    CListCtrl * pListControl = pSortInfo->pListControl;

    int nColumnNo = pSortInfo->nColumnNo;
	bool nAscendingSortOrder = pSortInfo->nAscendingSortOrder;
	int IFirstData = 0, ISecondData = 0, sort_value[2]={1,-1};
	

	LV_FINDINFO FindInfo;
    
	FindInfo.flags = LVFI_PARAM | LVFI_WRAP;
	FindInfo.lParam = lpOne;
	IFirstData = pListControl->FindItem(&FindInfo);

	FindInfo.lParam = lpTwo;
	ISecondData = pListControl->FindItem(&FindInfo, IFirstData);
	
	ASSERT(IFirstData != -1); ASSERT(ISecondData != -1);

	CString FirstText = pListControl->GetItemText(IFirstData, nColumnNo);
	CString SecondText = pListControl->GetItemText(ISecondData, nColumnNo);


	int nCompareValue = FirstText.Compare(SecondText);
	nResult = nCompareValue * sort_value[nAscendingSortOrder]; // ((nAscendingSortOrder)?1:-1);
 
	return nResult;
 
    
}

void CSubFormDlg7::OnItemclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here

	if(phdn->iButton == 0)
	{

		if(phdn->hdr.hwndFrom == m_list1.GetDlgItem(0)->GetSafeHwnd())
		{

			if(phdn->iItem == m_SortInfo.nColumnNo)
				m_SortInfo.nAscendingSortOrder = !m_SortInfo.nAscendingSortOrder;
			else
				m_SortInfo.nAscendingSortOrder = true;
  
			m_SortInfo.nColumnNo = phdn->iItem;
			m_SortInfo.pListControl = &m_list1;

			m_list1.SortItems(CompareFunc,(DWORD)&m_SortInfo); 
        
		} 
		else if(phdn->hdr.hwndFrom == m_list2.GetDlgItem(0)->GetSafeHwnd())
		{

		if(phdn->iItem == m_SortInfo.nColumnNo)
				m_SortInfo.nAscendingSortOrder = !m_SortInfo.nAscendingSortOrder;
			else
				m_SortInfo.nAscendingSortOrder = true;
  
			m_SortInfo.nColumnNo = phdn->iItem;
			m_SortInfo.pListControl = &m_list2;

			m_list2.SortItems(CompareFunc,(DWORD)&m_SortInfo); 



		}
		else if(phdn->hdr.hwndFrom == m_list3.GetDlgItem(0)->GetSafeHwnd())
		{

		    if(phdn->iItem == m_SortInfo.nColumnNo)
				m_SortInfo.nAscendingSortOrder = !m_SortInfo.nAscendingSortOrder;
			else
				m_SortInfo.nAscendingSortOrder = true;
  
			m_SortInfo.nColumnNo = phdn->iItem;
			m_SortInfo.pListControl = &m_list3;

			m_list3.SortItems(CompareFunc,(DWORD)&m_SortInfo); 

	
		}
		else if(phdn->hdr.hwndFrom == m_list4.GetDlgItem(0)->GetSafeHwnd())
		{
		   if(phdn->iItem == m_SortInfo.nColumnNo)
				m_SortInfo.nAscendingSortOrder = !m_SortInfo.nAscendingSortOrder;
			else
				m_SortInfo.nAscendingSortOrder = true;
  
			m_SortInfo.nColumnNo = phdn->iItem;
			m_SortInfo.pListControl = &m_list4;

			m_list4.SortItems(CompareFunc,(DWORD)&m_SortInfo); 

		}
			
	}

	*pResult = 0;
}

