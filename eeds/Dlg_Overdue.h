#pragma once


// Dlg_Overdue �Ի���

class Dlg_Overdue : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Overdue)

public:
	Dlg_Overdue(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg_Overdue();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_OVERDUE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
