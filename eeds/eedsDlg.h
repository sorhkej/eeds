
// eedsDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CeedsDlg �Ի���
class CeedsDlg : public CDialogEx
{
// ����
public:
	CeedsDlg(CWnd* pParent = NULL);	// ��׼���캯��
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EEDS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

	BOOL ExitConn();   //�Ͽ�SQL Server���ݿ�

	_RecordsetPtr DBRecordSetGet(LPCTSTR sql);
	BOOL GetCollect(LPCTSTR Name, _variant_t& OutCol);

};
