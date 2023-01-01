#pragma once
#include "afxwin.h"


// Dlg_Place_Bottle 对话框
extern CString LiquidPosi;
class Dlg_Place_Bottle : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Place_Bottle)

public:
	Dlg_Place_Bottle(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_Place_Bottle();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_PLACE_BOTTLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cb_liquid;
	CEdit m_edit_volume;
	afx_msg void OnCbnSelchangeCbLiquid();
	afx_msg void OnBnClickedOk();

	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;

	float volume;
	CString bottle,cs_volume,liquid,concentration,endtime, min_weighing, min_volume, max_volume, actual_volume;;

	void SearchLiquid();
	void AddData();

	virtual BOOL OnInitDialog();
};
