
// eedsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "eedsDlg.h"
#include "afxdialogex.h"
#include "Dlg_Guide.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CeedsDlg 对话框
_RecordsetPtr CeedsDlg::DBRecordSetGet(LPCTSTR sql)
{
	// TODO: 在此处添加实现代码.
	m_pRec.CreateInstance("ADODB.Recordset");
	m_pRec = m_pCon->Execute((_bstr_t)sql, NULL, adCmdText);

	return m_pRec;
}

BOOL CeedsDlg::GetCollect(LPCTSTR Name, _variant_t& OutCol)
{
	// TODO: 在此处添加实现代码.
	_variant_t vt;
	vt = m_pRec->GetCollect(Name);
	if (vt.vt != VT_NULL)
	{
		OutCol = vt;
		return TRUE;
	}
	else
		return FALSE;
}



CeedsDlg::CeedsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EEDS_DIALOG, pParent)
	, m_Acc(_T(""))
	, m_Pwd(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CeedsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Acc);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
}

BEGIN_MESSAGE_MAP(CeedsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CeedsDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CeedsDlg 消息处理程序

BOOL CeedsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CeedsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CeedsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CeedsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CeedsDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);			//将控件的值赋值给成员变量

	CString sql;				//获取的学号密码进行匹对
	sql.Format(L"exec Login_Account '%s','%s'", m_Acc, m_Pwd);
	m_pRec = DBRecordSetGet(sql);		//执行SQL语句

	_variant_t var;
	GetCollect(L"nums", var);
	int temp = var.intVal;

	//ExitConn();
	m_pRec = NULL;
	//学号密码正确，显示学生信息
	if (temp)
	{
		ExitConn();
		OnCancel();
		Dlg_Guide dlg_guide;
		//dlg_guide.m_pCon = m_pCon;	//注意m_pCon的传递
		//dlg_guide.m_Acc = m_Acc;
		dlg_guide.DoModal();
		//CDialogEx::OnOK();
	}
	else
	{
		CString str;
		str.Format(L"error");
		MessageBox(str);
	}
}

BOOL CeedsDlg::ExitConn()
{
	//关闭记录集和连接
	if (m_pRec != NULL)
	{
		m_pRec->Close();
	}
	m_pRec = NULL;
	m_pCon->Close();
	::CoUninitialize(); //可以理解为关闭COM库组件

	return TRUE;
}