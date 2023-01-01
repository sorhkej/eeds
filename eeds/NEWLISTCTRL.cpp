// NEWLISTCTRL.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "NEWLISTCTRL.h"

// NEWLISTCTRL


IMPLEMENT_DYNAMIC(NEWLISTCTRL, CListCtrl)

NEWLISTCTRL::NEWLISTCTRL()
{
}

NEWLISTCTRL::~NEWLISTCTRL()
{
}


BEGIN_MESSAGE_MAP(NEWLISTCTRL, CListCtrl)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()



// NEWLISTCTRL 消息处理程序



int flagnum = 0;
void NEWLISTCTRL::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//::PostMessage(GetSafeHwnd(), VM_SCROLLRAG,nPos, 0);
	flagnum=1;
	CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);
}


void NEWLISTCTRL::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flagnum=1;
	CListCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL NEWLISTCTRL::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flagnum=1;
	return CListCtrl::OnMouseWheel(nFlags, zDelta, pt);
}
