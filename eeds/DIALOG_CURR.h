#pragma once
#include "afxcmn.h"


// DIALOG_CURR �Ի���

class DIALOG_CURR : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_CURR)

public:
	DIALOG_CURR(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DIALOG_CURR();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CURR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list_for;
	CListCtrl m_list_liqu;

	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;

	CString formDm, formMc, dm, mc, bz, zl;

	void CheckData();
	void SearchData();
	void DeleteData();

	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickListFor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickListFor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListFor(NMHDR *pNMHDR, LRESULT *pResult);
};
