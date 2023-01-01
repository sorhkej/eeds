// DIALOG_LOGS.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "DIALOG_LOGS.h"
#include "afxdialogex.h"


// DIALOG_LOGS 对话框

IMPLEMENT_DYNAMIC(DIALOG_LOGS, CDialogEx)

DIALOG_LOGS::DIALOG_LOGS(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LOGS, pParent)
{

}

DIALOG_LOGS::~DIALOG_LOGS()
{
}

void DIALOG_LOGS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DIALOG_LOGS, CDialogEx)
END_MESSAGE_MAP()


// DIALOG_LOGS 消息处理程序
