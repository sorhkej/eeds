#pragma once


// DIALOG_LOGS 对话框

class DIALOG_LOGS : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_LOGS)

public:
	DIALOG_LOGS(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DIALOG_LOGS();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
