#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// Dlg_New 对话框
extern int formulaNum;
class Dlg_New : public CDialog
{
	DECLARE_DYNAMIC(Dlg_New)

public:
	Dlg_New(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_New();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CComboBox m_cbb_stuff;
	CComboBox m_cbb_form;
//	CEdit m_edit_orde;
//	CEdit m_edit_qual;
	CListCtrl m_list_form;

	CString daima,mingcheng;
	CString dm = _T(""), mc = _T(""), bz = _T(""), pswz = _T(""), zl = _T(""), rl = _T("");


	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;


	void SearchData();
	void SaveToDatabase();


	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnGetform();
	afx_msg void OnCbnSelchangeComboForm();
//	afx_msg void OnBnClickedBtnAdd();
	CEdit m_edit_wei;
	CButton m_btn_save;
	afx_msg void OnBnClickedButtonSave();
};
