#pragma once
#include "afxwin.h"


// Dlg_Item 对话框

class Dlg_Item : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Item)

public:
	Dlg_Item(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_Item();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ITEM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_btn_set;
	CFont m_font;//操作字体对象
	CToolTipCtrl m_stat;//工具提示控件对象


	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	CButton m_btn_stuff;
	CButton m_btn_liquid;
	CButton m_btn_attribute;
	CButton m_btn_formula;
	CButton m_btn_equipment;
	CButton m_btn_user;
	CButton m_btn_failure;
	CButton m_btn_compound;
	CButton m_btn_overdue;
	CButton m_btn_edit;
	CButton m_btn_fault;
	CButton m_btn_delivery;
	CButton m_btn_prove;
	CButton m_btn_history;
	CButton m_btn_liquid_report;
	CButton m_btn_stuff_report;
	CButton m_btn_formula_report;
	CButton m_btn_bottle_report;
	CButton m_btn_pic_report;
	CButton m_btn_edit_report;
	CButton m_btn_correct_report;
	CButton m_btn_failure_report;
	afx_msg void OnBnClickedButtonCompound();
	afx_msg void OnBnClickedButtonOverdue();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonStuff();
	afx_msg void OnBnClickedButtonLiquid();
	afx_msg void OnBnClickedButtonAttribute();
	afx_msg void OnBnClickedButtonFormula();
};
