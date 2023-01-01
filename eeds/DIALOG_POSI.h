#pragma once
#include "afxwin.h"


// DIALOG_POSI 对话框
extern CString LiquidPosi, LiquPos, LiquVol, MaxVol, MinVol, OverTim;
class DIALOG_POSI : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_POSI)

public:
	DIALOG_POSI(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DIALOG_POSI();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_POSI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;



	//int LiquPos;
	CString bottle;
	CString ry, nd,rj,sj,zt,zzsj,zxczl,zxrj,zdrj,sjrj,pz,ybrj;
	int LiquFlag;
	int StPos[5][6][6] = {};
	int PicPos[5][6][6] = {};

	CStatic* NewSt(int nID, CRect rect);
	CStatic* NewPic(int nID, CRect rect);
	BOOL ExitConn();
	void CheckState();
	void DisplayMenu();
	void SearchData();
	void AddData();



	virtual BOOL OnInitDialog();

	afx_msg void OnStnClickedStaticT211();
	afx_msg void OnStnClickedStaticT212();
	afx_msg void OnStnClickedStaticT213();
	afx_msg void OnStnClickedStaticT214();
	afx_msg void OnStnClickedStaticT215();
	afx_msg void OnStnClickedStaticT216();
	afx_msg void OnStnClickedStaticT221();
	afx_msg void OnStnClickedStaticT222();
	afx_msg void OnStnClickedStaticT223();
	afx_msg void OnStnClickedStaticT224();
	afx_msg void OnStnClickedStaticT225();
	afx_msg void OnStnClickedStaticT226();
	afx_msg void OnStnClickedStaticT231();
	afx_msg void OnStnClickedStaticT232();
	afx_msg void OnStnClickedStaticT233();
	afx_msg void OnStnClickedStaticT234();
	afx_msg void OnStnClickedStaticT235();
	afx_msg void OnStnClickedStaticT236();
	afx_msg void OnStnClickedStaticT241();
	afx_msg void OnStnClickedStaticT242();
	afx_msg void OnStnClickedStaticT243();
	afx_msg void OnStnClickedStaticT244();
	afx_msg void OnStnClickedStaticT245();
	afx_msg void OnStnClickedStaticT246();
	afx_msg void OnStnClickedStaticT251();
	afx_msg void OnStnClickedStaticT252();
	afx_msg void OnStnClickedStaticT253();
	afx_msg void OnStnClickedStaticT254();
	afx_msg void OnStnClickedStaticT255();
	afx_msg void OnStnClickedStaticT256();
	afx_msg void OnStnClickedStaticT261();
	afx_msg void OnStnClickedStaticT262();
	afx_msg void OnStnClickedStaticT263();
	afx_msg void OnStnClickedStaticT264();
	afx_msg void OnStnClickedStaticT265();
	afx_msg void OnStnClickedStaticT266();
	afx_msg void OnStnClickedStaticT311();
	afx_msg void OnStnClickedStaticT312();
	afx_msg void OnStnClickedStaticT313();
	afx_msg void OnStnClickedStaticT314();
	afx_msg void OnStnClickedStaticT315();
	afx_msg void OnStnClickedStaticT316();
	afx_msg void OnStnClickedStaticT321();
	afx_msg void OnStnClickedStaticT322();
	afx_msg void OnStnClickedStaticT323();
	afx_msg void OnStnClickedStaticT324();
	afx_msg void OnStnClickedStaticT325();
	afx_msg void OnStnClickedStaticT326();
	afx_msg void OnStnClickedStaticT331();
	afx_msg void OnStnClickedStaticT332();
	afx_msg void OnStnClickedStaticT333();
	afx_msg void OnStnClickedStaticT334();
	afx_msg void OnStnClickedStaticT335();
	afx_msg void OnStnClickedStaticT336();
	afx_msg void OnStnClickedStaticT341();
	afx_msg void OnStnClickedStaticT342();
	afx_msg void OnStnClickedStaticT343();
	afx_msg void OnStnClickedStaticT344();
	afx_msg void OnStnClickedStaticT345();
	afx_msg void OnStnClickedStaticT346();
	afx_msg void OnStnClickedStaticT351();
	afx_msg void OnStnClickedStaticT352();
	afx_msg void OnStnClickedStaticT353();
	afx_msg void OnStnClickedStaticT354();
	afx_msg void OnStnClickedStaticT355();
	afx_msg void OnStnClickedStaticT356();
	afx_msg void OnStnClickedStaticT361();
	afx_msg void OnStnClickedStaticT362();
	afx_msg void OnStnClickedStaticT363();
	afx_msg void OnStnClickedStaticT364();
	afx_msg void OnStnClickedStaticT365();
	afx_msg void OnStnClickedStaticT366();
	afx_msg void OnStnClickedStaticT411();
	afx_msg void OnStnClickedStaticT412();
	afx_msg void OnStnClickedStaticT413();
	afx_msg void OnStnClickedStaticT414();
	afx_msg void OnStnClickedStaticT415();
	afx_msg void OnStnClickedStaticT416();
	afx_msg void OnStnClickedStaticT421();
	afx_msg void OnStnClickedStaticT422();
	afx_msg void OnStnClickedStaticT423();
	afx_msg void OnStnClickedStaticT424();
	afx_msg void OnStnClickedStaticT425();
	afx_msg void OnStnClickedStaticT426();
	afx_msg void OnStnClickedStaticT431();
	afx_msg void OnStnClickedStaticT432();
	afx_msg void OnStnClickedStaticT433();
	afx_msg void OnStnClickedStaticT434();
	afx_msg void OnStnClickedStaticT435();
	afx_msg void OnStnClickedStaticT436();
	afx_msg void OnStnClickedStaticT441();
	afx_msg void OnStnClickedStaticT442();
	afx_msg void OnStnClickedStaticT443();
	afx_msg void OnStnClickedStaticT444();
	afx_msg void OnStnClickedStaticT445();
	afx_msg void OnStnClickedStaticT446();
	afx_msg void OnStnClickedStaticT451();
	afx_msg void OnStnClickedStaticT452();
	afx_msg void OnStnClickedStaticT453();
	afx_msg void OnStnClickedStaticT454();
	afx_msg void OnStnClickedStaticT455();
	afx_msg void OnStnClickedStaticT456();
	afx_msg void OnStnClickedStaticT461();
	afx_msg void OnStnClickedStaticT462();
	afx_msg void OnStnClickedStaticT463();
	afx_msg void OnStnClickedStaticT464();
	afx_msg void OnStnClickedStaticT465();
	afx_msg void OnStnClickedStaticT466();
	afx_msg void OnStnClickedStaticT511();
	afx_msg void OnStnClickedStaticT512();
	afx_msg void OnStnClickedStaticT513();
	afx_msg void OnStnClickedStaticT514();
	afx_msg void OnStnClickedStaticT515();
	afx_msg void OnStnClickedStaticT516();
	afx_msg void OnStnClickedStaticT521();
	afx_msg void OnStnClickedStaticT522();
	afx_msg void OnStnClickedStaticT523();
	afx_msg void OnStnClickedStaticT524();
	afx_msg void OnStnClickedStaticT525();
	afx_msg void OnStnClickedStaticT526();
	afx_msg void OnStnClickedStaticT531();
	afx_msg void OnStnClickedStaticT532();
	afx_msg void OnStnClickedStaticT533();
	afx_msg void OnStnClickedStaticT534();
	afx_msg void OnStnClickedStaticT535();
	afx_msg void OnStnClickedStaticT536();
	afx_msg void OnStnClickedStaticT541();
	afx_msg void OnStnClickedStaticT542();
	afx_msg void OnStnClickedStaticT543();
	afx_msg void OnStnClickedStaticT544();
	afx_msg void OnStnClickedStaticT545();
	afx_msg void OnStnClickedStaticT546();
	afx_msg void OnStnClickedStaticT551();
	afx_msg void OnStnClickedStaticT552();
	afx_msg void OnStnClickedStaticT553();
	afx_msg void OnStnClickedStaticT554();
	afx_msg void OnStnClickedStaticT555();
	afx_msg void OnStnClickedStaticT556();
	afx_msg void OnStnClickedStaticT561();
	afx_msg void OnStnClickedStaticT562();
	afx_msg void OnStnClickedStaticT563();
	afx_msg void OnStnClickedStaticT564();
	afx_msg void OnStnClickedStaticT565();
	afx_msg void OnStnClickedStaticT566();
	afx_msg void OnStnClickedStaticT611();
	afx_msg void OnStnClickedStaticT612();
	afx_msg void OnStnClickedStaticT613();
	afx_msg void OnStnClickedStaticT614();
	afx_msg void OnStnClickedStaticT615();
	afx_msg void OnStnClickedStaticT616();
	afx_msg void OnStnClickedStaticT621();
	afx_msg void OnStnClickedStaticT622();
	afx_msg void OnStnClickedStaticT623();
	afx_msg void OnStnClickedStaticT624();
	afx_msg void OnStnClickedStaticT625();
	afx_msg void OnStnClickedStaticT626();
	afx_msg void OnStnClickedStaticT631();
	afx_msg void OnStnClickedStaticT632();
	afx_msg void OnStnClickedStaticT633();
	afx_msg void OnStnClickedStaticT634();
	afx_msg void OnStnClickedStaticT635();
	afx_msg void OnStnClickedStaticT636();
	afx_msg void OnStnClickedStaticT641();
	afx_msg void OnStnClickedStaticT642();
	afx_msg void OnStnClickedStaticT643();
	afx_msg void OnStnClickedStaticT644();
	afx_msg void OnStnClickedStaticT645();
	afx_msg void OnStnClickedStaticT646();
	afx_msg void OnStnClickedStaticT651();
	afx_msg void OnStnClickedStaticT652();
	afx_msg void OnStnClickedStaticT653();
	afx_msg void OnStnClickedStaticT654();
	afx_msg void OnStnClickedStaticT655();
	afx_msg void OnStnClickedStaticT656();
	afx_msg void OnStnClickedStaticT661();
	afx_msg void OnStnClickedStaticT662();
	afx_msg void OnStnClickedStaticT663();
	afx_msg void OnStnClickedStaticT664();
	afx_msg void OnStnClickedStaticT665();
	afx_msg void OnStnClickedStaticT666();








	CStatic m_pic_t1[5][5];
	afx_msg void OnExist32786();
	afx_msg void OnEmpty32792();


	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);



	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnExist32778();
	afx_msg void OnEmpty32787();
	afx_msg void OnExistPlaceBottle();
	afx_msg void OnExistLockPosition();
	afx_msg void OnExistWasteSolution();
	afx_msg void OnExistTakeOutTheBottle();
	afx_msg void OnEmptyPlaceBottle();
};
