
// eedsDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CeedsDlg 对话框
class CeedsDlg : public CDialogEx
{
// 构造
public:
	CeedsDlg(CWnd* pParent = NULL);	// 标准构造函数
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EEDS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_Acc;
	CString m_Pwd;

	_RecordsetPtr m_pRec;
	_ConnectionPtr m_pCon;

	BOOL ExitConn();   //断开SQL Server数据库

	_RecordsetPtr DBRecordSetGet(LPCTSTR sql);
	BOOL GetCollect(LPCTSTR Name, _variant_t& OutCol);

};
