#pragma once
#define VM_SCROLLRAG 3015

// NEWLISTCTRL
extern int flagnum;
class NEWLISTCTRL : public CListCtrl
{
	DECLARE_DYNAMIC(NEWLISTCTRL)

public:
	NEWLISTCTRL();
	virtual ~NEWLISTCTRL();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};


