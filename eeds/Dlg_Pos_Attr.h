#pragma once
#include "afxwin.h"


// Dlg_Pos_Attr 对话框

class Dlg_Pos_Attr : public CDialog
{
	DECLARE_DYNAMIC(Dlg_Pos_Attr)

public:
	Dlg_Pos_Attr(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_Pos_Attr();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_POSATTR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit m_edit_liquattr;
	CComboBox m_cb_liqu;
	CEdit m_edit_volume;
	CEdit m_edit_max;
	CEdit m_edit_min;
	CEdit m_edit_overdue;

	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;

	CString liquid,cs_concentration,bottle,volume, endtime, min_weighing, min_volume, max_volume, actual_volume;

	void AddData();
	void SearchData();



	afx_msg void OnBnClickedOk();
};
