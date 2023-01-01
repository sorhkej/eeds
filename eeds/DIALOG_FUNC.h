#pragma once
#include "afxcmn.h"


// DIALOG_FUNC 对话框
extern int functionNum;
class DIALOG_FUNC : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_FUNC)

public:
	DIALOG_FUNC(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DIALOG_FUNC();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FUNC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMClickListForm(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListForm(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
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





};
