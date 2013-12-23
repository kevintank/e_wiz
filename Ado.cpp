// Ado.cpp: implementation of the CAdo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "testdlg.h"
#include "Ado.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

const TCHAR *oleString = _T("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=");
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdo::CAdo()
{
	CoInitialize(NULL);  //COM관련 초기화 

    m_pCON = NULL;   
	m_pRS = NULL;    
	m_pCOM = NULL;   
	m_IsDBOpen = FALSE;

 
	if(FAILED( m_pCON.CreateInstance(__uuidof(Connection)))) 
		AfxMessageBox(_T("Connection 객체 생성 실패"), MB_OK, NULL);
    if(FAILED(m_pRS.CreateInstance(__uuidof(Recordset))))
        AfxMessageBox(_T("Recordset 객체 생성 실패"), MB_OK, NULL);
	if(FAILED(m_pCOM.CreateInstance(__uuidof(Command))))
        AfxMessageBox(_T("Command 객체 생성 실패"), MB_OK, NULL);
   

}

CAdo::~CAdo()
{
	m_pCON.Release();
	m_pRS.Release();
	m_pCOM.Release();
	  
	m_pCON = NULL;   
	m_pRS = NULL;    
	m_pCOM = NULL;   
	m_IsDBOpen = FALSE;
  	CoUninitialize();	 // COM관련 개체 해제    

}
/********************************************************************
* 연결 문자열을 만든다.
* 기존 파일명과 틀릴때에만 connection을 닫고, 연결문자열을 만든다.
*
* return : BOOL : TRUE | FALSE
*
* parameter :
* [in] CString Filename : MDB 파일명
********************************************************************/
BOOL CAdo::DB_Init(CString strFilename)
{
  
	if(m_pRS == NULL || m_pCON == NULL)
		return FALSE;

	if(strFilename.IsEmpty())
		return FALSE;

	if(FileCmp(strFilename) == TRUE)
		return TRUE;

    DB_Close();
	m_strConnection = oleString + strFilename;
    return FALSE;

}
/********************************************************************
* 레코드 셋을 오픈 한다.
* 기존 recordset이 있으면 close 한다.
*
* return : BOOL : TRUE | FALSE
*
* parameter :
* [in] CString sql : SQL Query SELECT 구문
* [in] CString Filename : MDB 파일명
********************************************************************/
BOOL CAdo::DB_Open(CString sql, CString Filename) 
{
 
   HRESULT hr;
   VARIANT conn;

   if(m_pCON == NULL || m_pRS == NULL)
   {
	   
	   return FALSE;
   }
 
   if(Filename.IsEmpty() == FALSE)
   {
	   
	   AfxMessageBox("이름이 업네");
	   DB_Connection(Filename);
   }
   else
   {
	   AfxMessageBox("이름이 있네");
	    
	   DB_Connection("");
   }

    
   if(m_IsDBConn == FALSE)
   {
	  	
	   return FALSE;
   }

    

   if(m_IsDBOpen == TRUE)
	   DB_Close();

    try
    {

	
       // TRACE(sql);
	//	TRACE("\n");

		VariantInit(&conn);
		conn.pdispVal = m_pCON;
		conn.vt = VT_DISPATCH;

		
		hr = m_pRS->Open( (LPTSTR)(LPCTSTR)sql, conn,
			adOpenForwardOnly, adLockOptimistic, adCmdUnknown); //레코드셋 설정 쿼리 실행 ..... 필요한 부분 가져왓  

	}
	catch(_com_error &e)
	{
		TRACE("\tDescription: %s\n", (LPCTSTR) e.Description());
    }
	catch(...)
	{
      TRACE("*** Unhandled Exception ***\n");
	}

 


	if(SUCCEEDED(hr))
		m_IsDBOpen = TRUE;
	   
         sql.TrimLeft();
         CString str = sql.Left(7);
	  
		if(str.CollateNoCase("SELECT ")) //2개의 string 비교 
		{
	    	m_IsDBOpen = FALSE;
		}
	

  return SUCCEEDED(hr);

}


/********************************************************************
* DB에 연결한다.
* 기존 connection이 있으면 유지 한다.
*
* return : BOOL : TRUE | FALSE
*
* parameter :
* [in] CString Filename : MDB 파일명
********************************************************************/
BOOL CAdo::DB_Connection(CString Filename)
{

	if(Filename.IsEmpty() && m_strConnection.IsEmpty() )
		return FALSE;
	
	if(Filename.IsEmpty() == FALSE)
	{
       	DB_Init(Filename);
	}

	if(m_pCON == NULL)
		return FALSE;

	if(m_IsDBConn == TRUE  )
		return TRUE;

	try
	{	//connection.Open(ConnectionString, UserID, Password, Options)  데이타 베이스 연결하기.
	   	m_pCON->Open((_bstr_t)m_strConnection,"","", adConnectUnspecified);
		m_IsDBConn = TRUE;
	       	
		AfxMessageBox("트루야");
	}catch(_com_error &err)
	{
	 	m_IsDBConn = FALSE;
		AfxMessageBox("폴틀야 ");
        TRACE("Error : %s : DB CONNECTION FAIL\n", err.Description() );		 
	}
     	
	return m_IsDBConn;
}
  

void CAdo::DB_Search()
{
  	
	m_pCOM->ActiveConnection = m_pCON;
	m_pCOM->CommandText = "Select * From TB_LINECODE";

	try
	{    
		//Execute 안쓸때 아래처럼 속성을 정해 준다. 
         //m_pRS->CursorLocation = adUseClient; 
        // m_pRS->CursorType =  adOpenStatic;
        // m_pRS->LockType = adLockOptimistic;

		//커서 타입을 아래와 같이 정의 해 준다
		//recordset.Open( Source, ActiveConnection, CursorType, LockType, Options)
	    m_pRS->Open("TB_LINECODE", _variant_t((IDispatch *)m_pCON, true),adOpenStatic, adLockOptimistic,adCmdTable);
        /////////////////////////////////////////////
	
		//예전 꺼 --> m_pRS = m_pCOM->Execute(NULL,NULL,adCmdText);
  	   	//수정 
		m_pCOM->Execute(NULL,NULL,adCmdText);
		
	}
	catch(_com_error &e)
	{	
       COMERRORMSG(e);
		//AfxMessageBox("조회가 정상적으로 되지 않았습니다.!!");
		return;
	}

	if(m_pRS->adoEOF)		
	{
		AfxMessageBox("데이타 없음!!");
		return;
	}		

	_variant_t fldItem01, fldItem02, fldItem03, fldItem04, fldItem05, fldItem06, fldItem07;	

	CString strLineName01,strLineName02,strLineName03,strLineName04,strLineName05;
	long     lngIndex01,lngIndex02;

    int intFieldCount;
	intFieldCount = 1; //반복 카운터 
 
    while(!m_pRS->adoEOF)
	{	
		//필드에서 값 가져오기 
		fldItem01 = m_pRS->Fields->GetItem("unit")->GetValue();
        fldItem02 = m_pRS->Fields->GetItem("unitidx")->GetValue();
		fldItem03 = m_pRS->Fields->GetItem("word")->GetValue();
		fldItem04 = m_pRS->Fields->GetItem("wordkr")->GetValue();
		fldItem05 = m_pRS->Fields->GetItem("exkor")->GetValue();
		fldItem06 = m_pRS->Fields->GetItem("exeng")->GetValue();
		fldItem07 = m_pRS->Fields->GetItem("exans")->GetValue();


		strLineName01 = Convert_Variant_To_String(fldItem03);
		strLineName02 = Convert_Variant_To_String(fldItem04);
		strLineName03 = Convert_Variant_To_String(fldItem05);
		strLineName04 = Convert_Variant_To_String(fldItem06);
		strLineName05 = Convert_Variant_To_String(fldItem07);

        lngIndex01 = fldItem01; 
        lngIndex02 = fldItem02;
			  
       // AddData(lngIndex01,lngIndex02,strLineName01,strLineName02,strLineName03,strLineName04,strLineName05 );
		intFieldCount++;
		m_pRS->MoveNext();	
	}
 
    

    
  
  /*
 
	try{
	     m_pRS->MoveLast();
	}catch(_com_error &e){

		 COMERRORMSG(e);
		return;

	}

	try{
    	    fldItem01 = m_pRS->Fields->GetItem("unit")->GetValue();
	   }catch(_com_error &e){
	

		  COMERRORMSG(e);
	      return;

           
	   }
    


	 lngIndex01 = fldItem01;
	 strLineName01.Format("This: %ld", lngIndex01);
     AfxMessageBox(strLineName01);
  
  */
	 
    	m_pRS->Close();	
       // m_flxDBList.SetRedraw(1);      
       // m_flxDBList. Refresh();            
 

}

CString CAdo::Convert_Variant_To_String(_variant_t &varString)
{
    if (varString.vt == VT_BSTR)
    {
        _bstr_t bstrString = (_bstr_t)varString;
        return  (LPTSTR)bstrString;
    }
    return "";
}

/**********************************************************
* recordset 닫기 
* return : BOOL : TRUE : FALSE
*
* parameter : None
***********************************************************/
BOOL CAdo::DB_Close()
{
   if(m_IsDBOpen == FALSE)
	   return TRUE;

   m_IsDBOpen = FALSE;

   return SUCCEEDED(m_pRS->Close());
   
}
/**********************************************************
* connection을 끊는다. 
* return : BOOL : TRUE : FALSE
*
* parameter : None
***********************************************************/
BOOL CAdo::DB_CloseConnection()
{
	if(m_pCON == FALSE)
		return TRUE;
  	m_pCON = FALSE;
	
	return SUCCEEDED( m_pCON->Close());    

}
 
//데이타 추가하기
 
void CAdo::DB_Insert(long lngIndex01, long lngIndex02,CString strLineName01,
								    CString strLineName02,CString strLineName03,CString strLineName04,CString strLineName05)
{
	CString strQuery;
	m_pCOM->ActiveConnection = m_pCON;
	strQuery.Format("Insert into TB_LINECODE(unit,unitidx,word,wordkr,exkor,exeng,exans) values(%ld,%ld,'%s','%s','%s','%s','%s')",
		      lngIndex01,lngIndex02,strLineName01,strLineName02,strLineName03,strLineName04,strLineName05);

	m_pCOM->CommandText = (LPTSTR)(_bstr_t)strQuery;

	try
	{
		m_pRS = m_pCOM->Execute(NULL, NULL, adCmdText);
	}
	catch(_com_error &e)
	{
         
		COMERRORMSG(e);
		return;
	}

   //OnButtonSearchdb();  //FlexGrid 초기화 하고, 다시 데이터 가져온다. 

	//DB_Search();

}

//수정하기 
                                   
void CAdo::DB_Modify(long lngIndex01, long lngIndex02, CString strLineName01,CString strLineName02,CString strLineName03,CString strLineName04,CString strLineName05, CString strOldLineName)   
{
	CString strQuery;
	//m_pCOM->ActiveConnection = m_pCON;
	//{"Update TB_LINECODE SET LINENAME='김삿갓',INDEX=102323 WHERE LINENAME ='최기동'"}

 	strQuery.Format("Update TB_LINECODE SET unit=%ld,unitidx=%ld,word='%s',wordkr='%s',exkor='%s',exeng='%s',exans='%s' WHERE word='%s'",
		lngIndex01,lngIndex02,strLineName01,strLineName02,strLineName03,strLineName04,strLineName05,strOldLineName);
					 		
	m_pCOM->ActiveConnection = m_pCON;
	m_pCOM->CommandText = (LPTSTR)(_bstr_t)strQuery;

	try
	{
		m_pRS = m_pCOM->Execute(NULL, NULL, adCmdText);
	}
	catch(_com_error &e)
	{
		COMERRORMSG(e);
		return;
	}


}

 

//데이타 삭제하기 where절 
void CAdo::DB_Delete(CString strQuery)
{	 
	m_pCOM->ActiveConnection = m_pCON;
	m_pCOM->CommandText = (LPTSTR)(_bstr_t)strQuery;

	try
	{
		m_pRS = m_pCOM->Execute(NULL, NULL, adCmdText);
	}
	catch(_com_error &e)
	{
		COMERRORMSG(e);
		return;
	}

	//OnButtonSearchdb();

}
void CAdo::COMERRORMSG(_com_error &e)
{

	CString sMsg, errMsg;
    /////////////////////////////////////////////////////////////////////////
    // Com errors.
    _bstr_t bstrSource(e.Source());
    _bstr_t bstrDescription(e.Description());
    errMsg.Format("%08lx : %s\n", e.Error(), e.ErrorMessage());
    sMsg += errMsg;
    errMsg.Format("Source = %s\n", (LPCSTR) bstrSource);
    sMsg += errMsg;
    errMsg.Format("Description = %s", (LPCSTR) bstrDescription);
    sMsg += errMsg;
    AfxMessageBox(sMsg, MB_ICONSTOP);


}

/********************************************************************
* 기존에 연결 파일명과 비교해 틀리면 FALSE를 반환한다.
* (개선의 여지가 있음.
* 파일명에 경로가 포함될 경우 정확한 비교가 되지 않음 )
*
* return : BOOL : TRUE | FALSE
*
* parameter :
* [in] CString Filename : MDB 파일명
********************************************************************/
BOOL CAdo::FileCmp(CString Filename)
{
   if(m_IsDBConn == FALSE)
	   return FALSE;

   return m_strConnection.CompareNoCase(oleString + Filename);

}

/********************************************************************
* 더 이상 튜플이 없으면 TRUE를 반환 한다.
*
* return : BOOL : TRUE | FALSE
*
* parameter : None
********************************************************************/
BOOL CAdo::DB_IsEof()
{
  if(!m_IsDBOpen)
	  return TRUE;

  return(BOOL)m_pRS->GetadoEOF();


}
/********************************************************************
* 현재 튜플의 Field에 해당하는 Instance를 문자열 형태로 얻는다.
*
* return : CString : Value
*
* parameter :
* [in] CString Field : 값을 가져올 Attribute Name
********************************************************************/
CString CAdo::GetValueString(CString Field)
{

   if(!m_IsDBOpen || DB_IsEof())
		return "";
       
    _variant_t vt = m_pRS->GetCollect((LPTSTR)(LPCTSTR)Field);
      
    if( vt.vt != VT_NULL)
	   return (LPCSTR)_bstr_t(vt);        // str = (LPCSTR)_bstr_t(vt.bstrVal);
	else
	   return "";

 

}
/********************************************************************
* 현재 튜플의 Field에 해당하는 Instance를 정수 형태로 얻는다.
*
* return : int : Value
*
* parameter :
* [in] CString Field : 값을 가져올 Attribute Name
********************************************************************/
int CAdo::GetValueInt(CString Field)
{
	/*
 	_variant_t vi = m_pRS->Fields->GetItem("unit")->GetValue();

    
	int   lngIndex01;
    CString str; 
	
    lngIndex01 = atoi(GetValueString(Field));
    str.Format("this val %d", lngIndex01);
 	AfxMessageBox(str);

	
 	return 0;
  */
	  return atoi(GetValueString(Field));
}


/********************************************************************
* 다음 튜플로 이동한다.
*
* return : BOOL : TRUE | FALSE
*
* parameter : None
********************************************************************/
BOOL CAdo::DB_MoveNext()
{
	if(!m_IsDBOpen)
		  return FALSE;

	return SUCCEEDED(m_pRS->MoveNext());
}
/********************************************************************
* 마지막 레코드로 이동.
*
* return : BOOL : TRUE | FALSE
*
* parameter : None
********************************************************************/
BOOL CAdo::DB_MoveLast()
{
      if(!m_IsDBOpen)
		  return FALSE;

	  try{
	
		  m_pRS->MoveLast();
	  
	  }catch(_com_error &e){
 
		  
		  COMERRORMSG(e);
	      return FALSE;
  	  }
 return TRUE;
}
/********************************************************************
* DML 쿼리를 실행한다.
* connection이 없으면 연결한다.
*
* return : BOOL : TRUE | FALSE
*
* parameter :
* [in] CString sql : SQL Query DML 구문
* [in] CString Filename : MDB 파일명
********************************************************************/
BOOL CAdo::DB_Excute(CString sql, CString Filename /*=_T("")*/)
{
	if(m_pCON == NULL)
		return FALSE;

	if(Filename.IsEmpty() == FALSE)
	{
		DB_Connection(Filename);
	}
	else
	{
        DB_Connection("");
	}
 
	if(m_IsDBConn == FALSE)
		return FALSE;

	try
	{
		TRACE(sql);
		TRACE("\n");

		m_pCON->Execute((_bstr_t)sql, NULL, adCmdText);
	}
	catch(_com_error &err)
	{
		TRACE("Error: %s: DB Execute FAIL\n", err.Description());
		return FALSE;
	}


	return TRUE;
}
/********************************************************************
* 현재 connection을 얻는다.
*
* return : _ConnectionPtr
*
* parameter : None
* [in] CString Filename : MDB 파일명
********************************************************************/
_ConnectionPtr CAdo::DB_GetConnection()
{
	return m_pCON;
}
/********************************************************************
* connection을 새로 Attach한다.
* 이미 사용중인 connection 및 Recordset는 닫는다.
*
* return : None
*
* parameter :
* [in] _ConnectionPtr conn : 사용할 Connection Object
********************************************************************/
void CAdo::DB_AttachConnection(_ConnectionPtr conn)
{

	   if(m_IsDBOpen == TRUE)
	      DB_Close();

	   if(m_IsDBConn == TRUE)
	   {
		   DB_CloseConnection();
		   m_pCON.Release();
	   }

	   m_pCON = conn;
	   m_IsDBConn = TRUE;
	        
}
/********************************************************************
* connection을 새로 Attach한다.
* 이미 사용중인 connection 및 Recordset는 닫는다.
*
* return : None
*
* parameter :
* [in] _ConnectionPtr conn : 사용할 Connection Object
********************************************************************/
void CAdo::DB_DetachConnection()
{
   if(m_IsDBConn == FALSE)
	   return;

   m_pCON = NULL;
   m_IsDBConn = FALSE;

}


void CAdo::Test()
{

	_variant_t fldItem01;
	 CString strLineName01;
  
 //fldItem01 = m_pRS->Fields->GetItem("MaxNum")->GetValue();
 //strLineName01 = Convert_Variant_To_String(fldItem01);

 AfxMessageBox(strLineName01);
      
 

}

 
