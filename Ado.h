// Ado.h: interface for the CAdo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADO_H__45530264_2AB4_427F_A90F_9C54315ECBDB__INCLUDED_)
#define AFX_ADO_H__45530264_2AB4_427F_A90F_9C54315ECBDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAdo  
{
public:
	CAdo();
	virtual ~CAdo();

	BOOL DB_Init(CString strFilename);
	BOOL DB_Open(CString sql, CString Filename);
    BOOL DB_Close();
	BOOL DB_CloseConnection();  //Ä¿³Ø¼Ç ´Ý±â 
    BOOL DB_Connection(CString Filename);
    BOOL DB_IsEof();
    BOOL DB_MoveNext();
    BOOL DB_MoveLast();
	BOOL DB_Excute(CString sql, CString Filename /*=_T("")*/);
    
	void DB_Search();
	void DB_AttachConnection(_ConnectionPtr conn);
	void DB_DetachConnection();
   	void DB_Insert(long lngIndex01, long lngIndex02,CString strLineName01,CString strLineName02,CString strLineName03,CString strLineName04,CString strLineName05);
    void DB_Modify(long lngIndex01, long lngIndex02,CString strLineName01,CString strLineName02,CString strLineName03,CString strLineName04,CString strLineName05, CString strOldLineName );
    void DB_Delete(CString strLineName);
	
 	CString GetValueString(CString Field);
    int GetValueInt(CString Field);
    void COMERRORMSG(_com_error &e);
	BOOL FileCmp(CString Filename);
	_ConnectionPtr DB_GetConnection();
    CString Convert_Variant_To_String(_variant_t &varString);  
 void Test();
		
private:
	BOOL m_IsDBOpen;
	BOOL m_IsDBConn;
	CString m_strConnection;

	_ConnectionPtr m_pCON;
	_RecordsetPtr  m_pRS;
	_CommandPtr    m_pCOM;
protected:
	
};

#endif // !defined(AFX_ADO_H__45530264_2AB4_427F_A90F_9C54315ECBDB__INCLUDED_)
