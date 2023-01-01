// Dlg_Overdue.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Overdue.h"
#include "afxdialogex.h"


// Dlg_Overdue 对话框

IMPLEMENT_DYNAMIC(Dlg_Overdue, CDialogEx)

Dlg_Overdue::Dlg_Overdue(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_OVERDUE, pParent)
{

}

Dlg_Overdue::~Dlg_Overdue()
{
}

void Dlg_Overdue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dlg_Overdue, CDialogEx)
END_MESSAGE_MAP()


// Dlg_Overdue 消息处理程序
