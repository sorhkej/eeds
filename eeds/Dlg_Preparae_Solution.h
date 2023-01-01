#pragma once
#include "afxwin.h"


// Dlg_Preparae_Solution 对话框
extern CString LiquidPosi,LiquidName;
class Dlg_Preparae_Solution : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Preparae_Solution)

public:
	Dlg_Preparae_Solution(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_Preparae_Solution();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_PREPARAE_SOLUTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float currentweight = 0, concentration,target_concentration,max_concentration,min_concentration;
	CString target_weight,current_weight,bottle, liquid,cs_concentration,volume,endtime,min_weighing,min_volume,max_volume,actual_volume;
	int colornum=0;

	COLORREF m_colorEditText; // edit控件的字体颜色
	CBrush* m_pEditBkBrush;


	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;

	void SearchData();
	void SearchLiquid();
	void AddData();

	virtual BOOL OnInitDialog();
	CEdit m_edit_current_weight;
	afx_msg void OnBnClickedBtnBegin();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedOk();
	CEdit m_edit_liquid;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
