#pragma once


// Dlg_Compound �Ի���

class Dlg_Compound : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Compound)

public:
	Dlg_Compound(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg_Compound();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_COMPOUND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
