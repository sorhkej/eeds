// NEWLISTCTRL.cpp : ʵ���ļ�
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



// NEWLISTCTRL ��Ϣ�������



int flagnum = 0;
void NEWLISTCTRL::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//::PostMessage(GetSafeHwnd(), VM_SCROLLRAG,nPos, 0);
	flagnum=1;
	CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);
}


void NEWLISTCTRL::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flagnum=1;
	CListCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL NEWLISTCTRL::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flagnum=1;
	return CListCtrl::OnMouseWheel(nFlags, zDelta, pt);
}
