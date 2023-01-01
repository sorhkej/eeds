#pragma once
#include "afxcmn.h"
#include"STDINT.H"
#include"DIALOG_FORM.h"
#include"DIALOG_FUNC.h"
#include"DIALOG_POSI.h"
#include"DIALOG_LIQU.h"
#include"DIALOG_CURR.h"
#include"DIALOG_LOGS.h"


// Dlg_Guide 对话框

class Dlg_Guide : public CDialog
{
	DECLARE_DYNAMIC(Dlg_Guide)

public:
	Dlg_Guide(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_Guide();
	CString m_Acc;
	CString m_Pwd;


	void LoadSCdata();

//	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedButtonSelectclass();
	afx_msg void OnBnClickedButtonChangepw();
	afx_msg void OnBnClickedCancel();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_GUIDE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CToolBar m_toolbar;
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	DIALOG_FORM* dialog_form;
	DIALOG_FUNC* dialog_func;
	DIALOG_POSI* dialog_posi;
	DIALOG_LIQU* dialog_liqu;
	DIALOG_CURR* dialog_curr;
	DIALOG_LOGS* dialog_logs;

	CToolBar cToolBar;

	CTabCtrl m_tab;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnToolBarButtonback();
	afx_msg void OnToolBarButtonNew();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
