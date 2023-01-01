// Dlg_Guide.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Guide.h"
#include "afxdialogex.h"
#include "DIALOG_FORM.h"
#include "DIALOG_FUNC.h"
#include "Dlg_Item.h"
#include "Dlg_New.h"

// Dlg_Guide 对话框

IMPLEMENT_DYNAMIC(Dlg_Guide, CDialog)


Dlg_Guide::Dlg_Guide(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_GUIDE, pParent)
{

}

Dlg_Guide::~Dlg_Guide()
{
}

void Dlg_Guide::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(Dlg_Guide, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &Dlg_Guide::OnTcnSelchangeTab1)
	ON_COMMAND(IDR_TOOLBAR1, &Dlg_Guide::OnToolBarButtonback)
	ON_COMMAND(IDR_TOOLBAR2, &Dlg_Guide::OnToolBarButtonNew)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Dlg_Guide 消息处理程序


BOOL Dlg_Guide::OnInitDialog()
{
	CDialog::OnInitDialog();

	CMenu menu;
	menu.LoadMenu(IDR_MENU1);  //IDR_MENU1为菜单栏ID号
	SetMenu(&menu);

	CRect tabRect;
	m_tab.GetClientRect(&tabRect);
	tabRect.DeflateRect(2, 30, 5, 5);
	m_tab.InsertItem(0, L"配方明细");
	m_tab.InsertItem(1, L"运行配方");
	m_tab.InsertItem(2, L"位置状态");
	m_tab.InsertItem(3, L"溶液状态");
	m_tab.InsertItem(4, L"当前动作");
	m_tab.InsertItem(5, L"事件日志");
	dialog_form = new DIALOG_FORM();
	dialog_func = new DIALOG_FUNC();
	dialog_posi = new DIALOG_POSI();
	dialog_liqu = new DIALOG_LIQU();
	dialog_curr = new DIALOG_CURR();
	dialog_logs = new DIALOG_LOGS();
	dialog_form->Create(IDD_DIALOG_FORM, &m_tab);
	dialog_func->Create(IDD_DIALOG_FUNC, &m_tab);
	dialog_posi->Create(IDD_DIALOG_POSI, &m_tab);
	dialog_liqu->Create(IDD_DIALOG_LIQU, &m_tab);
	dialog_curr->Create(IDD_DIALOG_CURR, &m_tab);
	dialog_logs->Create(IDD_DIALOG_LOGS, &m_tab);
	dialog_form->MoveWindow(tabRect);
	dialog_func->MoveWindow(tabRect);
	dialog_posi->MoveWindow(tabRect);
	dialog_liqu->MoveWindow(tabRect);
	dialog_curr->MoveWindow(tabRect);
	dialog_logs->MoveWindow(tabRect);
	dialog_form->ShowWindow(SW_SHOW);
	dialog_func->ShowWindow(SW_HIDE);
	dialog_posi->ShowWindow(SW_HIDE);
	dialog_liqu->ShowWindow(SW_HIDE);
	dialog_curr->ShowWindow(SW_HIDE);
	dialog_logs->ShowWindow(SW_HIDE);


	// TODO:  在此添加额外的初始化
	////创建工具栏  
	//HWND hDlg = GetSafeHwnd();//对话框的窗口句柄
	//HINSTANCE hInstance = AfxGetInstanceHandle();//当前应用程序的实例句柄
	//											 //填充工具条按钮结构：
	//TBBUTTON ptoolbar[30] = { { STD_FILENEW, //指定Windows的标准帮助图标
	//	IDR_TOOLBAR, //工具条按钮的ID
	//	TBSTATE_ENABLED, //可用状态
	//	TBSTYLE_BUTTON, //指定创建一个可以下按的按钮
	//	0, //保留，由应用程序定义该参数意义
	//	0 }, //按钮字串索引
	//	{ STD_FILEOPEN, IDR_TOOLBAR, TBSTATE_ENABLED,  TBSTYLE_BUTTON,0, 0 },
	//	{ STD_FILESAVE, IDR_TOOLBAR, TBSTATE_ENABLED,  TBSTYLE_BUTTON,0, 0 },
	//	//创建一个分割按钮用的竖线
	//};
	////在对话框上动态创建工具条，并添加工具条按钮：
	//HWND hToolsWindow = ::CreateToolbarEx(hDlg, //指定对话框为父窗口，将工具条创建在对话框上
	//	WS_CHILD | WS_VISIBLE | TBSTYLE_WRAPABLE | TBSTYLE_TOOLTIPS |
	//	TBSTYLE_FLAT | CCS_ADJUSTABLE,//指定工具条的创建风格
	//	IDR_TOOLBAR,//预定义的工具条资源ID
	//	30, HINST_COMMCTRL, //包含图片资源的可执行文件的实例句柄
	//	IDB_STD_SMALL_COLOR,//图片的资源ID
	//	ptoolbar, //待添加的按钮
	//	3, //加入到工具条的按钮的个数
	//	0, 0, 0, 0, sizeof(TBBUTTON));
	////从IDR_TOOLBAR资源中装载按钮图标到对话框的工具条上
	//TBADDBITMAP tab;
	//tab.hInst = hInstance;
	//tab.nID = IDR_TOOLBAR;
	//::SendMessage(hToolsWindow, TB_ADDBITMAP, (WPARAM)3, (LPARAM)&tab);

	cToolBar.Create(this);
	cToolBar.LoadToolBar(IDR_TOOLBAR);
	UINT arr[] = { IDR_TOOLBAR1, IDR_TOOLBAR2,IDR_TOOLBAR3 };
	cToolBar.SetButtons(arr, 3);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_FIRST, 0);



	//int cx, cy;
	//cx = GetSystemMetrics(SM_CXSCREEN);
	//cy = GetSystemMetrics(SM_CYSCREEN);

	////再用MoveWindow
	////复制代码
	//CRect rcTemp;
	//rcTemp.BottomRight() = CPoint(cx, cy);
	//rcTemp.TopLeft() = CPoint(0, 0);
	//MoveWindow(&rcTemp);




	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}



void Dlg_Guide::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	switch (m_tab.GetCurSel())
	{
	case 0:
		dialog_form->ShowWindow(SW_SHOW);
		dialog_func->ShowWindow(SW_HIDE);
		dialog_posi->ShowWindow(SW_HIDE);
		dialog_liqu->ShowWindow(SW_HIDE);
		dialog_curr->ShowWindow(SW_HIDE);
		dialog_logs->ShowWindow(SW_HIDE);
		break;
	case 1:
		dialog_form->ShowWindow(SW_HIDE);
		dialog_func->ShowWindow(SW_SHOW);
		dialog_posi->ShowWindow(SW_HIDE);
		dialog_liqu->ShowWindow(SW_HIDE);
		dialog_curr->ShowWindow(SW_HIDE);
		dialog_logs->ShowWindow(SW_HIDE);
		break;
	case 2:
		dialog_form->ShowWindow(SW_HIDE);
		dialog_func->ShowWindow(SW_HIDE);
		dialog_posi->ShowWindow(SW_SHOW);
		dialog_liqu->ShowWindow(SW_HIDE);
		dialog_curr->ShowWindow(SW_HIDE);
		dialog_logs->ShowWindow(SW_HIDE);
		break;
	case 3:
		dialog_form->ShowWindow(SW_HIDE);
		dialog_func->ShowWindow(SW_HIDE);
		dialog_posi->ShowWindow(SW_HIDE);
		dialog_liqu->ShowWindow(SW_SHOW);
		dialog_curr->ShowWindow(SW_HIDE);
		dialog_logs->ShowWindow(SW_HIDE);
		break;
	case 4:
		dialog_form->ShowWindow(SW_HIDE);
		dialog_func->ShowWindow(SW_HIDE);
		dialog_posi->ShowWindow(SW_HIDE);
		dialog_liqu->ShowWindow(SW_HIDE);
		dialog_curr->ShowWindow(SW_SHOW);
		dialog_logs->ShowWindow(SW_HIDE);
		break;
	case 5:
		dialog_form->ShowWindow(SW_HIDE);
		dialog_func->ShowWindow(SW_HIDE);
		dialog_posi->ShowWindow(SW_HIDE);
		dialog_liqu->ShowWindow(SW_HIDE);
		dialog_curr->ShowWindow(SW_HIDE);
		dialog_logs->ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}

void Dlg_Guide::OnToolBarButtonNew()
{
	Dlg_Item *pDlg = new Dlg_Item;
	pDlg->Create(IDD_DLG_ITEM, this);
	pDlg->ShowWindow(SW_SHOW);
}


void Dlg_Guide::OnToolBarButtonback()
{

	Dlg_New *pDlg = new Dlg_New;
	pDlg->Create(IDD_DIALOG_NEW, this);
	pDlg->ShowWindow(SW_SHOW);
}

HBRUSH Dlg_Guide::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
