#pragma once
#include "afxcmn.h"
#include"NEWLISTCTRL.h"

// DIALOG_LIQU �Ի���

class DIALOG_LIQU : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_LIQU)

public:
	DIALOG_LIQU(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DIALOG_LIQU();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LIQU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();


	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;

	void CheckData();


	NEWLISTCTRL m_list_pos;
};
