#pragma once


// Dlg_Overdue 对话框

class Dlg_Overdue : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Overdue)

public:
	Dlg_Overdue(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_Overdue();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_OVERDUE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
