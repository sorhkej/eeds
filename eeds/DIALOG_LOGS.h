#pragma once


// DIALOG_LOGS �Ի���

class DIALOG_LOGS : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_LOGS)

public:
	DIALOG_LOGS(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DIALOG_LOGS();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
