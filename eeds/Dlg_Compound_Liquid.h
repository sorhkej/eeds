#pragma once
#include "afxwin.h"


// Dlg_Compound_Liquid �Ի���
extern CString LiquidPosi, LiquidNmae;
class Dlg_Compound_Liquid : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Compound_Liquid)

public:
	Dlg_Compound_Liquid(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg_Compound_Liquid();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_COMPOUND_LIQUID };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;

	CString liquid, concentration,bottle;

	void SearchData();
	void AddData();

	afx_msg void OnBnClickedBtnMix();
	afx_msg void OnBnClickedBtnDilute();
	CComboBox m_cb_liquid;
	afx_msg void OnCbnSelchangeCbLiquid();
	virtual BOOL OnInitDialog();
};
