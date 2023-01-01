#pragma once
#include "afxwin.h"


// Dlg_Dilute_Solution �Ի���
extern CString LiquidPosi;
class Dlg_Dilute_Solution : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Dilute_Solution)

public:
	Dlg_Dilute_Solution(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg_Dilute_Solution();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_DILUTE_SOLUTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;

	CString bottle,liquid,cs_concentration;
	float concentration;

	void SearchData();
	void SearchLiquid();




	CComboBox m_cb_liquid;
	afx_msg void OnCbnSelchangeCbLiquid();
	virtual BOOL OnInitDialog();
};
