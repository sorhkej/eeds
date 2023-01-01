#pragma once
#include "afxcmn.h"


// Dlg_Formula_Guide 对话框
extern int formulaNum,functionNum;
class Dlg_Formula_Guide : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Formula_Guide)

public:
	Dlg_Formula_Guide(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_Formula_Guide();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FORMULA_GUIDE
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnBegindragListFormula(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();


	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;


	int row, rowSum,formulaFlag ;
	CString code, name,bottle, capacity, weight, position;
	CString remark;
	int idNum;





	void RefreshText();
	void ClearText();
	void CheckData();
	void CheckState();
	void AddData();
	void SearchData();
	void DeleteData();

	BOOL ExitConn();

	CStatic* NewSt(int nID, CRect rect);
	CStatic* NewPic(int nID, CRect rect);


	CListCtrl m_list;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOk();
};
