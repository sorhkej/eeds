// Dlg_Item.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Item.h"
#include "afxdialogex.h"
#include"resource.h"
#include "Dlg_Compound.h"
#include "Dlg_Overdue.h"
#include "Dlg_New.h"
#include "Dlg_Stuff.h"
#include"Dlg_Liquid.h"
#include"Dlg_Attribute.h"
#include"Dlg_Formula.h"


// Dlg_Item 对话框

IMPLEMENT_DYNAMIC(Dlg_Item, CDialogEx)

Dlg_Item::Dlg_Item(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_ITEM, pParent)
{

}

Dlg_Item::~Dlg_Item()
{
}

void Dlg_Item::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_SET, m_btn_set);
	DDX_Control(pDX, IDC_BUTTON_STUFF, m_btn_stuff);
	DDX_Control(pDX, IDC_BUTTON_LIQUID, m_btn_liquid);
	DDX_Control(pDX, IDC_BUTTON_ATTRIBUTE, m_btn_attribute);
	DDX_Control(pDX, IDC_BUTTON_FORMULA, m_btn_formula);
	DDX_Control(pDX, IDC_BUTTON_EQUIPMENT, m_btn_equipment);
	DDX_Control(pDX, IDC_BUTTON_USER, m_btn_user);
	DDX_Control(pDX, IDC_BUTTON_FAILURE, m_btn_failure);
	DDX_Control(pDX, IDC_BUTTON_COMPOUND, m_btn_compound);
	DDX_Control(pDX, IDC_BUTTON_OVERDUE, m_btn_overdue);
	DDX_Control(pDX, IDC_BUTTON_EDIT, m_btn_edit);
	DDX_Control(pDX, IDC_BUTTON_FAULT, m_btn_fault);
	DDX_Control(pDX, IDC_BUTTON_DELIVERY, m_btn_delivery);
	DDX_Control(pDX, IDC_BUTTON_PROVE, m_btn_prove);
	DDX_Control(pDX, IDC_BUTTON_HISTORY, m_btn_history);
	DDX_Control(pDX, IDC_BUTTON_LIQUID_REPORT, m_btn_liquid_report);
	DDX_Control(pDX, IDC_BUTTON_STUFF_REPORT, m_btn_stuff_report);
	DDX_Control(pDX, IDC_BUTTON_FORMULA_REPORT, m_btn_formula_report);
	DDX_Control(pDX, IDC_BUTTON_BOTTLE_REPORT, m_btn_bottle_report);
	DDX_Control(pDX, IDC_BUTTON_PIC_REPORT, m_btn_pic_report);
	DDX_Control(pDX, IDC_BUTTON_EDIT_REPORT, m_btn_edit_report);
	DDX_Control(pDX, IDC_BUTTON_CORRECT_REPORT, m_btn_correct_report);
	DDX_Control(pDX, IDC_BUTTON_FAILURE_REPORT, m_btn_failure_report);
}


BEGIN_MESSAGE_MAP(Dlg_Item, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_COMPOUND, &Dlg_Item::OnBnClickedButtonCompound)
	ON_BN_CLICKED(IDC_BUTTON_OVERDUE, &Dlg_Item::OnBnClickedButtonOverdue)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &Dlg_Item::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_STUFF, &Dlg_Item::OnBnClickedButtonStuff)
	ON_BN_CLICKED(IDC_BUTTON_LIQUID, &Dlg_Item::OnBnClickedButtonLiquid)
	ON_BN_CLICKED(IDC_BUTTON_ATTRIBUTE, &Dlg_Item::OnBnClickedButtonAttribute)
	ON_BN_CLICKED(IDC_BUTTON_FORMULA, &Dlg_Item::OnBnClickedButtonFormula)
END_MESSAGE_MAP()


// Dlg_Item 消息处理程序


BOOL Dlg_Item::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置字体
	m_font.CreateFont(20, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, _T("字体设置"));//第一个参数为设置字体大小，第五个参数为风格设置——加粗、斜体。。。
	GetDlgItem(IDC_BUTTON_SET)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_STUFF)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_LIQUID)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_ATTRIBUTE)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_FORMULA)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_EQUIPMENT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_USER)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_FAILURE)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_COMPOUND)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_OVERDUE)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_EDIT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_FAULT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_DELIVERY)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_PROVE)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_HISTORY)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_LIQUID_REPORT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_STUFF_REPORT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_FORMULA_REPORT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_BOTTLE_REPORT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_PIC_REPORT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_EDIT_REPORT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_CORRECT_REPORT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮
	GetDlgItem(IDC_BUTTON_FAILURE_REPORT)->SendMessage(WM_SETFONT, WPARAM(HFONT(m_font)), 0);//将字体参数传给按钮


	//按钮上添加图标
	HICON hIconOK;
	//hIconOK = AfxGetApp()->LoadIcon(IDR_MAINFRAME);//这句只加载图标，无法设置图标大小
	//更改按钮的Icon属性——True时只显示图标，False时显示图标和文字
	hIconOK = (HICON)LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 20, 20, LR_DEFAULTCOLOR | LR_CREATEDIBSECTION);//加载图标，第四、五个参数为设置图标大小
	m_btn_set.SetIcon(hIconOK);
	m_btn_stuff.SetIcon(hIconOK);
	m_btn_liquid.SetIcon(hIconOK);
	m_btn_attribute.SetIcon(hIconOK);
	m_btn_formula.SetIcon(hIconOK);
	m_btn_equipment.SetIcon(hIconOK);
	m_btn_user.SetIcon(hIconOK);
	m_btn_failure.SetIcon(hIconOK);
	m_btn_compound.SetIcon(hIconOK);
	m_btn_overdue.SetIcon(hIconOK);
	m_btn_edit.SetIcon(hIconOK);
	m_btn_fault.SetIcon(hIconOK);
	m_btn_delivery.SetIcon(hIconOK);
	m_btn_prove.SetIcon(hIconOK);
	m_btn_history.SetIcon(hIconOK);
	m_btn_liquid_report.SetIcon(hIconOK);
	m_btn_stuff_report.SetIcon(hIconOK);
	m_btn_formula_report.SetIcon(hIconOK);
	m_btn_bottle_report.SetIcon(hIconOK);
	m_btn_pic_report.SetIcon(hIconOK);
	m_btn_edit_report.SetIcon(hIconOK);
	m_btn_correct_report.SetIcon(hIconOK);
	m_btn_failure_report.SetIcon(hIconOK);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Dlg_Item::OnPaint() 
{
	CRect   rect;
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint().

	GetClientRect(rect);
	dc.FillSolidRect(rect, RGB(255, 255, 255));//对话框背景设置为白色
}


void Dlg_Item::OnBnClickedButtonCompound()
{
	// TODO: 在此添加控件通知处理程序代码
	Dlg_Compound  *pDlg = new Dlg_Compound;
	pDlg->Create(IDD_DLG_COMPOUND, this);
	pDlg->ShowWindow(SW_SHOW);
}


void Dlg_Item::OnBnClickedButtonOverdue()
{
	// TODO: 在此添加控件通知处理程序代码
	Dlg_Overdue  *pDlg = new Dlg_Overdue;
	pDlg->Create(IDD_DLG_OVERDUE, this);
	pDlg->ShowWindow(SW_SHOW);
}


void Dlg_Item::OnBnClickedButtonEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	Dlg_New  *pDlg = new Dlg_New;
	pDlg->Create(IDD_DIALOG_NEW, this);
	pDlg->ShowWindow(SW_SHOW);
}


void Dlg_Item::OnBnClickedButtonStuff()
{
	// TODO: 在此添加控件通知处理程序代码
	
	

	Dlg_Stuff  *pDlg = new Dlg_Stuff;
	pDlg->Create(IDD_DLG_STUFF, this);
	pDlg->ShowWindow(SW_SHOW);

}


void Dlg_Item::OnBnClickedButtonLiquid()
{
	// TODO: 在此添加控件通知处理程序代码
	Dlg_Liquid  *pDlg = new Dlg_Liquid;
	pDlg->Create(IDD_DLG_LIQUID, this);
	pDlg->ShowWindow(SW_SHOW);
}


void Dlg_Item::OnBnClickedButtonAttribute()
{
	// TODO: 在此添加控件通知处理程序代码
	Dlg_Attribute  *pDlg = new Dlg_Attribute;
	pDlg->Create(IDD_DLG_ATTRIBUTE, this);
	pDlg->ShowWindow(SW_SHOW);
}




void Dlg_Item::OnBnClickedButtonFormula()
{
	// TODO: 在此添加控件通知处理程序代码
	Dlg_Formula  *pDlg = new Dlg_Formula;
	pDlg->Create(IDD_DLG_FORMULA, this);
	pDlg->ShowWindow(SW_SHOW);
}
