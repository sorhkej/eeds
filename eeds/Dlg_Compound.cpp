// Dlg_Compound.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Compound.h"
#include "afxdialogex.h"


// Dlg_Compound 对话框

IMPLEMENT_DYNAMIC(Dlg_Compound, CDialogEx)

Dlg_Compound::Dlg_Compound(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_COMPOUND, pParent)
{

}

Dlg_Compound::~Dlg_Compound()
{
}

void Dlg_Compound::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dlg_Compound, CDialogEx)
END_MESSAGE_MAP()


// Dlg_Compound 消息处理程序
