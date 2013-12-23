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
	CoInitialize(NULL);  //COM���� �ʱ�ȭ 

    m_pCON = NULL;   
	m_pRS = NULL;    
	m_pCOM = NULL;   
	m_IsDBOpen = FALSE;

 
	if(FAILED( m_pCON.CreateInstance(__uuidof(Connection)))) 
		AfxMessageBox(_T("Connection ��ü ���� ����"), MB_OK, NULL);
    if(FAILED(m_pRS.CreateInstance(__uuidof(Recordset))))
        AfxMessageBox(_T("Recordset ��ü ���� ����"), MB_OK, NULL);
	if(FAILED(m_pCOM.CreateInstance(__uuidof(Command))))
        AfxMessageBox(_T("Command ��ü ���� ����"), MB_OK, NULL);
   

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
  	CoUninitialize();	 // COM���� ��ü ����    

}
/********************************************************************
* ���� ���ڿ��� �����.
* ���� ���ϸ�� Ʋ�������� connection�� �ݰ�, ���Ṯ�ڿ��� �����.
*
* return : BOOL : TRUE | FALSE
*
* parameter :
* [in] CString Filename : MDB ���ϸ�
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
* ���ڵ� ���� ���� �Ѵ�.
* ���� recordset�� ������ close �Ѵ�.
*
* return : BOOL : TRUE | FALSE
*
* parameter :
* [in] CString sql : SQL Query SELECT ����
* [in] CString Filename : MDB ���ϸ�
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
	   
	   AfxMessageBox("�̸��� ����");
	   DB_Connection(Filename);
   }
   else
   {
	   AfxMessageBox("�̸��� �ֳ�");
	    
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
			adOpenForwardOnly, adLockOptimistic, adCmdUnknown); //���ڵ�� ���� ���� ���� ..... �ʿ��� �κ� ������  

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
	  
		if(str.CollateNoCase("SELECT ")) //2���� string �� 
		{
	    	m_IsDBOpen = FALSE;
		}
	

  return SUCCEEDED(hr);

}


/********************************************************************
* DB�� �����Ѵ�.
* ���� connection�� ������ ���� �Ѵ�.
*
* return : BOOL : TRUE | FALSE
*
* parameter :
* [in] CString Filename : MDB ���ϸ�
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
	{	//connection.Open(ConnectionString, UserID, Password, Options)  ����Ÿ ���̽� �����ϱ�.
	   	m_pCON->Open((_bstr_t)m_strConnection,"","", adConnectUnspecified);
		m_IsDBConn = TRUE;
	       	
		AfxMessageBox("Ʈ���");
	}catch(_com_error &err)
	{
	 	m_IsDBConn = FALSE;
		AfxMessageBox("��Ʋ�� ");
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
		//Execute �Ⱦ��� �Ʒ�ó�� �Ӽ��� ���� �ش�. 
         //m_pRS->CursorLocation = adUseClient; 
        // m_pRS->CursorType =  adOpenStatic;
        // m_pRS->LockType = adLockOptimistic;

		//Ŀ�� Ÿ���� �Ʒ��� ���� ���� �� �ش�
		//recordset.Open( Source, ActiveConnection, CursorType, LockType, Options)
	    m_pRS->Open("TB_LINECODE", _variant_t((IDispatch *)m_pCON, true),adOpenStatic, adLockOptimistic,adCmdTable);
        /////////////////////////////////////////////
	
		//���� �� --> m_pRS = m_pCOM->Execute(NULL,NULL,adCmdText);
  	   	//���� 
		m_pCOM->Execute(NULL,NULL,adCmdText);
		
	}
	catch(_com_error &e)
	{	
       COMERRORMSG(e);
		//AfxMessageBox("��ȸ�� ���������� ���� �ʾҽ��ϴ�.!!");
		return;
	}

	if(m_pRS->adoEOF)		
	{
		AfxMessageBox("����Ÿ ����!!");
		return;
	}		

	_variant_t fldItem01, fldItem02, fldItem03, fldItem04, fldItem05, fldItem06, fldItem07;	

	CString strLineName01,strLineName02,strLineName03,strLineName04,strLineName05;
	long     lngIndex01,lngIndex02;

    int intFieldCount;
	intFieldCount = 1; //�ݺ� ī���� 
 
    while(!m_pRS->adoEOF)
	{	
		//�ʵ忡�� �� �������� 
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
* recordset �ݱ� 
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
* connection�� ���´�. 
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
 
//����Ÿ �߰��ϱ�
 
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

   //OnButtonSearchdb();  //FlexGrid �ʱ�ȭ �ϰ�, �ٽ� ������ �����´�. 

	//DB_Search();

}

//�����ϱ� 
                                   
void CAdo::DB_Modify(long lngIndex01, long lngIndex02, CString strLineName01,CString strLineName02,CString strLineName03,CString strLineName04,CString strLineName05, CString strOldLineName)   
{
	CString strQuery;
	//m_pCOM->ActiveConnection = m_pCON;
	//{"Update TB_LINECODE SET LINENAME='���',INDEX=102323 WHERE LINENAME ='�⵿ֱ'"}

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

 

//����Ÿ �����ϱ� where�� 
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
* ������ ���� ���ϸ�� ���� Ʋ���� FALSE�� ��ȯ�Ѵ�.
* (������ ������ ����.
* ���ϸ� ��ΰ� ���Ե� ��� ��Ȯ�� �񱳰� ���� ���� )
*
* return : BOOL : TRUE | FALSE
*
* parameter :
* [in] CString Filename : MDB ���ϸ�
********************************************************************/
BOOL CAdo::FileCmp(CString Filename)
{
   if(m_IsDBConn == FALSE)
	   return FALSE;

   return m_strConnection.CompareNoCase(oleString + Filename);

}

/********************************************************************
* �� �̻� Ʃ���� ������ TRUE�� ��ȯ �Ѵ�.
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
* ���� Ʃ���� Field�� �ش��ϴ� Instance�� ���ڿ� ���·� ��´�.
*
* return : CString : Value
*
* parameter :
* [in] CString Field : ���� ������ Attribute Name
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
* ���� Ʃ���� Field�� �ش��ϴ� Instance�� ���� ���·� ��´�.
*
* return : int : Value
*
* parameter :
* [in] CString Field : ���� ������ Attribute Name
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
* ���� Ʃ�÷� �̵��Ѵ�.
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
* ������ ���ڵ�� �̵�.
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
* DML ������ �����Ѵ�.
* connection�� ������ �����Ѵ�.
*
* return : BOOL : TRUE | FALSE
*
* parameter :
* [in] CString sql : SQL Query DML ����
* [in] CString Filename : MDB ���ϸ�
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
* ���� connection�� ��´�.
*
* return : _ConnectionPtr
*
* parameter : None
* [in] CString Filename : MDB ���ϸ�
********************************************************************/
_ConnectionPtr CAdo::DB_GetConnection()
{
	return m_pCON;
}
/********************************************************************
* connection�� ���� Attach�Ѵ�.
* �̹� ������� connection �� Recordset�� �ݴ´�.
*
* return : None
*
* parameter :
* [in] _ConnectionPtr conn : ����� Connection Object
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
* connection�� ���� Attach�Ѵ�.
* �̹� ������� connection �� Recordset�� �ݴ´�.
*
* return : None
*
* parameter :
* [in] _ConnectionPtr conn : ����� Connection Object
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

 
