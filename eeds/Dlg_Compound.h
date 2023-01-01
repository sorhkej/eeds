#pragma once


// Dlg_Compound 对话框

class Dlg_Compound : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Compound)

public:
	Dlg_Compound(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_Compound();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_COMPOUND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
