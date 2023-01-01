// Dlg_Guide.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Guide.h"
#include "afxdialogex.h"
#include "DIALOG_FORM.h"
#include "DIALOG_FUNC.h"
#include "Dlg_Item.h"
#include "Dlg_New.h"

// Dlg_Guide �Ի���

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


// Dlg_Guide ��Ϣ�������


BOOL Dlg_Guide::OnInitDialog()
{
	CDialog::OnInitDialog();

	CMenu menu;
	menu.LoadMenu(IDR_MENU1);  //IDR_MENU1Ϊ�˵���ID��
	SetMenu(&menu);

	CRect tabRect;
	m_tab.GetClientRect(&tabRect);
	tabRect.DeflateRect(2, 30, 5, 5);
	m_tab.InsertItem(0, L"�䷽��ϸ");
	m_tab.InsertItem(1, L"�����䷽");
	m_tab.InsertItem(2, L"λ��״̬");
	m_tab.InsertItem(3, L"��Һ״̬");
	m_tab.InsertItem(4, L"��ǰ����");
	m_tab.InsertItem(5, L"�¼���־");
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


	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	////����������  
	//HWND hDlg = GetSafeHwnd();//�Ի���Ĵ��ھ��
	//HINSTANCE hInstance = AfxGetInstanceHandle();//��ǰӦ�ó����ʵ�����
	//											 //��乤������ť�ṹ��
	//TBBUTTON ptoolbar[30] = { { STD_FILENEW, //ָ��Windows�ı�׼����ͼ��
	//	IDR_TOOLBAR, //��������ť��ID
	//	TBSTATE_ENABLED, //����״̬
	//	TBSTYLE_BUTTON, //ָ������һ�������°��İ�ť
	//	0, //��������Ӧ�ó�����ò�������
	//	0 }, //��ť�ִ�����
	//	{ STD_FILEOPEN, IDR_TOOLBAR, TBSTATE_ENABLED,  TBSTYLE_BUTTON,0, 0 },
	//	{ STD_FILESAVE, IDR_TOOLBAR, TBSTATE_ENABLED,  TBSTYLE_BUTTON,0, 0 },
	//	//����һ���ָť�õ�����
	//};
	////�ڶԻ����϶�̬����������������ӹ�������ť��
	//HWND hToolsWindow = ::CreateToolbarEx(hDlg, //ָ���Ի���Ϊ�����ڣ��������������ڶԻ�����
	//	WS_CHILD | WS_VISIBLE | TBSTYLE_WRAPABLE | TBSTYLE_TOOLTIPS |
	//	TBSTYLE_FLAT | CCS_ADJUSTABLE,//ָ���������Ĵ������
	//	IDR_TOOLBAR,//Ԥ����Ĺ�������ԴID
	//	30, HINST_COMMCTRL, //����ͼƬ��Դ�Ŀ�ִ���ļ���ʵ�����
	//	IDB_STD_SMALL_COLOR,//ͼƬ����ԴID
	//	ptoolbar, //����ӵİ�ť
	//	3, //���뵽�������İ�ť�ĸ���
	//	0, 0, 0, 0, sizeof(TBBUTTON));
	////��IDR_TOOLBAR��Դ��װ�ذ�ťͼ�굽�Ի���Ĺ�������
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

	////����MoveWindow
	////���ƴ���
	//CRect rcTemp;
	//rcTemp.BottomRight() = CPoint(cx, cy);
	//rcTemp.TopLeft() = CPoint(0, 0);
	//MoveWindow(&rcTemp);




	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}



void Dlg_Guide::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
