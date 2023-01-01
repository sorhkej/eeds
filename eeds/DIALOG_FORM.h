#pragma once
#include "afxcmn.h"


// DIALOG_FORM 对话框
extern int formulaNum;
class DIALOG_FORM : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_FORM)

public:
	DIALOG_FORM(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DIALOG_FORM();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list_liqu;
	CListCtrl m_list_for;
	virtual BOOL OnInitDialog();


	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;

	CString formDm, formMc,dm,mc,bz,zl;

	void CheckData();
	void SearchData();
	void DeleteData();



	afx_msg void OnNMClickListFor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListFor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickListFor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void On32796();
	afx_msg void OnMenu();
	afx_msg void On32794();
};
