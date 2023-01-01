// DIALOG_POSI.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "DIALOG_POSI.h"
#include "afxdialogex.h"
#include"Dlg_Pos_Attr.h"
#include "Dlg_Compound_Liquid.h"
#include "Dlg_Place_Bottle.h"

/*CString LiquidPosi */;
 CString LiquidPosi, LiquPos, LiquVol, MaxVol, MinVol, OverTim;

//CString asdasd = ("woca");
// DIALOG_POSI 对话框

#define SCROLLBAR_JUMP 10

IMPLEMENT_DYNAMIC(DIALOG_POSI, CDialogEx)

DIALOG_POSI::DIALOG_POSI(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_POSI, pParent)
{

}

DIALOG_POSI::~DIALOG_POSI()
{
}

void DIALOG_POSI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_PIC_T1A1, m_pic_t1[0][0]);
	//DDX_Control(pDX, IDC_PIC_T1A2, m_pic_t1[0][1]);
	//DDX_Control(pDX, IDC_PIC_T1A3, m_pic_t1[0][2]);
}


BEGIN_MESSAGE_MAP(DIALOG_POSI, CDialogEx)
	//ON_STN_CLICKED(IDC_STATIC_T1A3, &DIALOG_POSI::OnStnClickedStaticT1a3)
	//ON_STN_CLICKED(IDC_STATIC_T1A2, &DIALOG_POSI::OnStnClickedStaticT1a2)
	//ON_STN_CLICKED(IDC_STATIC_T1A1, &DIALOG_POSI::OnStnClickedStaticT1a1)
	ON_COMMAND(ID_EXIST_32786, &DIALOG_POSI::OnExist32786)
	ON_COMMAND(ID_EMPTY_32792, &DIALOG_POSI::OnEmpty32792)
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_STN_CLICKED(211, &DIALOG_POSI::OnStnClickedStaticT211)
	ON_STN_CLICKED(212, &DIALOG_POSI::OnStnClickedStaticT212)
	ON_STN_CLICKED(213, &DIALOG_POSI::OnStnClickedStaticT213)
	ON_STN_CLICKED(214, &DIALOG_POSI::OnStnClickedStaticT214)
	ON_STN_CLICKED(215, &DIALOG_POSI::OnStnClickedStaticT215)
	ON_STN_CLICKED(216, &DIALOG_POSI::OnStnClickedStaticT216)
	ON_STN_CLICKED(221, &DIALOG_POSI::OnStnClickedStaticT221)
	ON_STN_CLICKED(222, &DIALOG_POSI::OnStnClickedStaticT222)
	ON_STN_CLICKED(223, &DIALOG_POSI::OnStnClickedStaticT223)
	ON_STN_CLICKED(224, &DIALOG_POSI::OnStnClickedStaticT224)
	ON_STN_CLICKED(225, &DIALOG_POSI::OnStnClickedStaticT225)
	ON_STN_CLICKED(226, &DIALOG_POSI::OnStnClickedStaticT226)
	ON_STN_CLICKED(231, &DIALOG_POSI::OnStnClickedStaticT231)
	ON_STN_CLICKED(232, &DIALOG_POSI::OnStnClickedStaticT232)
	ON_STN_CLICKED(233, &DIALOG_POSI::OnStnClickedStaticT233)
	ON_STN_CLICKED(234, &DIALOG_POSI::OnStnClickedStaticT234)
	ON_STN_CLICKED(235, &DIALOG_POSI::OnStnClickedStaticT235)
	ON_STN_CLICKED(236, &DIALOG_POSI::OnStnClickedStaticT236)
	ON_STN_CLICKED(241, &DIALOG_POSI::OnStnClickedStaticT241)
	ON_STN_CLICKED(242, &DIALOG_POSI::OnStnClickedStaticT242)
	ON_STN_CLICKED(243, &DIALOG_POSI::OnStnClickedStaticT243)
	ON_STN_CLICKED(244, &DIALOG_POSI::OnStnClickedStaticT244)
	ON_STN_CLICKED(245, &DIALOG_POSI::OnStnClickedStaticT245)
	ON_STN_CLICKED(246, &DIALOG_POSI::OnStnClickedStaticT246)
	ON_STN_CLICKED(251, &DIALOG_POSI::OnStnClickedStaticT251)
	ON_STN_CLICKED(252, &DIALOG_POSI::OnStnClickedStaticT252)
	ON_STN_CLICKED(253, &DIALOG_POSI::OnStnClickedStaticT253)
	ON_STN_CLICKED(254, &DIALOG_POSI::OnStnClickedStaticT254)
	ON_STN_CLICKED(255, &DIALOG_POSI::OnStnClickedStaticT255)
	ON_STN_CLICKED(256, &DIALOG_POSI::OnStnClickedStaticT256)
	ON_STN_CLICKED(261, &DIALOG_POSI::OnStnClickedStaticT261)
	ON_STN_CLICKED(262, &DIALOG_POSI::OnStnClickedStaticT262)
	ON_STN_CLICKED(263, &DIALOG_POSI::OnStnClickedStaticT263)
	ON_STN_CLICKED(264, &DIALOG_POSI::OnStnClickedStaticT264)
	ON_STN_CLICKED(265, &DIALOG_POSI::OnStnClickedStaticT265)
	ON_STN_CLICKED(266, &DIALOG_POSI::OnStnClickedStaticT266)
	ON_STN_CLICKED(311, &DIALOG_POSI::OnStnClickedStaticT311)
	ON_STN_CLICKED(312, &DIALOG_POSI::OnStnClickedStaticT312)
	ON_STN_CLICKED(313, &DIALOG_POSI::OnStnClickedStaticT313)
	ON_STN_CLICKED(314, &DIALOG_POSI::OnStnClickedStaticT314)
	ON_STN_CLICKED(315, &DIALOG_POSI::OnStnClickedStaticT315)
	ON_STN_CLICKED(316, &DIALOG_POSI::OnStnClickedStaticT316)
	ON_STN_CLICKED(321, &DIALOG_POSI::OnStnClickedStaticT321)
	ON_STN_CLICKED(322, &DIALOG_POSI::OnStnClickedStaticT322)
	ON_STN_CLICKED(323, &DIALOG_POSI::OnStnClickedStaticT323)
	ON_STN_CLICKED(324, &DIALOG_POSI::OnStnClickedStaticT324)
	ON_STN_CLICKED(325, &DIALOG_POSI::OnStnClickedStaticT325)
	ON_STN_CLICKED(326, &DIALOG_POSI::OnStnClickedStaticT326)
	ON_STN_CLICKED(331, &DIALOG_POSI::OnStnClickedStaticT331)
	ON_STN_CLICKED(332, &DIALOG_POSI::OnStnClickedStaticT332)
	ON_STN_CLICKED(333, &DIALOG_POSI::OnStnClickedStaticT333)
	ON_STN_CLICKED(334, &DIALOG_POSI::OnStnClickedStaticT334)
	ON_STN_CLICKED(335, &DIALOG_POSI::OnStnClickedStaticT335)
	ON_STN_CLICKED(336, &DIALOG_POSI::OnStnClickedStaticT336)
	ON_STN_CLICKED(341, &DIALOG_POSI::OnStnClickedStaticT341)
	ON_STN_CLICKED(342, &DIALOG_POSI::OnStnClickedStaticT342)
	ON_STN_CLICKED(343, &DIALOG_POSI::OnStnClickedStaticT343)
	ON_STN_CLICKED(344, &DIALOG_POSI::OnStnClickedStaticT344)
	ON_STN_CLICKED(345, &DIALOG_POSI::OnStnClickedStaticT345)
	ON_STN_CLICKED(346, &DIALOG_POSI::OnStnClickedStaticT346)
	ON_STN_CLICKED(351, &DIALOG_POSI::OnStnClickedStaticT351)
	ON_STN_CLICKED(352, &DIALOG_POSI::OnStnClickedStaticT352)
	ON_STN_CLICKED(353, &DIALOG_POSI::OnStnClickedStaticT353)
	ON_STN_CLICKED(354, &DIALOG_POSI::OnStnClickedStaticT354)
	ON_STN_CLICKED(355, &DIALOG_POSI::OnStnClickedStaticT355)
	ON_STN_CLICKED(356, &DIALOG_POSI::OnStnClickedStaticT356)
	ON_STN_CLICKED(361, &DIALOG_POSI::OnStnClickedStaticT361)
	ON_STN_CLICKED(362, &DIALOG_POSI::OnStnClickedStaticT362)
	ON_STN_CLICKED(363, &DIALOG_POSI::OnStnClickedStaticT363)
	ON_STN_CLICKED(364, &DIALOG_POSI::OnStnClickedStaticT364)
	ON_STN_CLICKED(365, &DIALOG_POSI::OnStnClickedStaticT365)
	ON_STN_CLICKED(366, &DIALOG_POSI::OnStnClickedStaticT366)
	ON_STN_CLICKED(411, &DIALOG_POSI::OnStnClickedStaticT411)
	ON_STN_CLICKED(412, &DIALOG_POSI::OnStnClickedStaticT412)
	ON_STN_CLICKED(413, &DIALOG_POSI::OnStnClickedStaticT413)
	ON_STN_CLICKED(414, &DIALOG_POSI::OnStnClickedStaticT414)
	ON_STN_CLICKED(415, &DIALOG_POSI::OnStnClickedStaticT415)
	ON_STN_CLICKED(416, &DIALOG_POSI::OnStnClickedStaticT416)
	ON_STN_CLICKED(421, &DIALOG_POSI::OnStnClickedStaticT421)
	ON_STN_CLICKED(422, &DIALOG_POSI::OnStnClickedStaticT422)
	ON_STN_CLICKED(423, &DIALOG_POSI::OnStnClickedStaticT423)
	ON_STN_CLICKED(424, &DIALOG_POSI::OnStnClickedStaticT424)
	ON_STN_CLICKED(425, &DIALOG_POSI::OnStnClickedStaticT425)
	ON_STN_CLICKED(426, &DIALOG_POSI::OnStnClickedStaticT426)
	ON_STN_CLICKED(431, &DIALOG_POSI::OnStnClickedStaticT431)
	ON_STN_CLICKED(432, &DIALOG_POSI::OnStnClickedStaticT432)
	ON_STN_CLICKED(433, &DIALOG_POSI::OnStnClickedStaticT433)
	ON_STN_CLICKED(434, &DIALOG_POSI::OnStnClickedStaticT434)
	ON_STN_CLICKED(435, &DIALOG_POSI::OnStnClickedStaticT435)
	ON_STN_CLICKED(436, &DIALOG_POSI::OnStnClickedStaticT436)
	ON_STN_CLICKED(441, &DIALOG_POSI::OnStnClickedStaticT441)
	ON_STN_CLICKED(442, &DIALOG_POSI::OnStnClickedStaticT442)
	ON_STN_CLICKED(443, &DIALOG_POSI::OnStnClickedStaticT443)
	ON_STN_CLICKED(444, &DIALOG_POSI::OnStnClickedStaticT444)
	ON_STN_CLICKED(445, &DIALOG_POSI::OnStnClickedStaticT445)
	ON_STN_CLICKED(446, &DIALOG_POSI::OnStnClickedStaticT446)
	ON_STN_CLICKED(451, &DIALOG_POSI::OnStnClickedStaticT451)
	ON_STN_CLICKED(452, &DIALOG_POSI::OnStnClickedStaticT452)
	ON_STN_CLICKED(453, &DIALOG_POSI::OnStnClickedStaticT453)
	ON_STN_CLICKED(454, &DIALOG_POSI::OnStnClickedStaticT454)
	ON_STN_CLICKED(455, &DIALOG_POSI::OnStnClickedStaticT455)
	ON_STN_CLICKED(456, &DIALOG_POSI::OnStnClickedStaticT456)
	ON_STN_CLICKED(461, &DIALOG_POSI::OnStnClickedStaticT461)
	ON_STN_CLICKED(462, &DIALOG_POSI::OnStnClickedStaticT462)
	ON_STN_CLICKED(463, &DIALOG_POSI::OnStnClickedStaticT463)
	ON_STN_CLICKED(464, &DIALOG_POSI::OnStnClickedStaticT464)
	ON_STN_CLICKED(465, &DIALOG_POSI::OnStnClickedStaticT465)
	ON_STN_CLICKED(466, &DIALOG_POSI::OnStnClickedStaticT466)
	ON_STN_CLICKED(511, &DIALOG_POSI::OnStnClickedStaticT511)
	ON_STN_CLICKED(512, &DIALOG_POSI::OnStnClickedStaticT512)
	ON_STN_CLICKED(513, &DIALOG_POSI::OnStnClickedStaticT513)
	ON_STN_CLICKED(514, &DIALOG_POSI::OnStnClickedStaticT514)
	ON_STN_CLICKED(515, &DIALOG_POSI::OnStnClickedStaticT515)
	ON_STN_CLICKED(516, &DIALOG_POSI::OnStnClickedStaticT516)
	ON_STN_CLICKED(521, &DIALOG_POSI::OnStnClickedStaticT521)
	ON_STN_CLICKED(522, &DIALOG_POSI::OnStnClickedStaticT522)
	ON_STN_CLICKED(523, &DIALOG_POSI::OnStnClickedStaticT523)
	ON_STN_CLICKED(524, &DIALOG_POSI::OnStnClickedStaticT524)
	ON_STN_CLICKED(525, &DIALOG_POSI::OnStnClickedStaticT525)
	ON_STN_CLICKED(526, &DIALOG_POSI::OnStnClickedStaticT526)
	ON_STN_CLICKED(531, &DIALOG_POSI::OnStnClickedStaticT531)
	ON_STN_CLICKED(532, &DIALOG_POSI::OnStnClickedStaticT532)
	ON_STN_CLICKED(533, &DIALOG_POSI::OnStnClickedStaticT533)
	ON_STN_CLICKED(534, &DIALOG_POSI::OnStnClickedStaticT534)
	ON_STN_CLICKED(535, &DIALOG_POSI::OnStnClickedStaticT535)
	ON_STN_CLICKED(536, &DIALOG_POSI::OnStnClickedStaticT536)
	ON_STN_CLICKED(541, &DIALOG_POSI::OnStnClickedStaticT541)
	ON_STN_CLICKED(542, &DIALOG_POSI::OnStnClickedStaticT542)
	ON_STN_CLICKED(543, &DIALOG_POSI::OnStnClickedStaticT543)
	ON_STN_CLICKED(544, &DIALOG_POSI::OnStnClickedStaticT544)
	ON_STN_CLICKED(545, &DIALOG_POSI::OnStnClickedStaticT545)
	ON_STN_CLICKED(546, &DIALOG_POSI::OnStnClickedStaticT546)
	ON_STN_CLICKED(551, &DIALOG_POSI::OnStnClickedStaticT551)
	ON_STN_CLICKED(552, &DIALOG_POSI::OnStnClickedStaticT552)
	ON_STN_CLICKED(553, &DIALOG_POSI::OnStnClickedStaticT553)
	ON_STN_CLICKED(554, &DIALOG_POSI::OnStnClickedStaticT554)
	ON_STN_CLICKED(555, &DIALOG_POSI::OnStnClickedStaticT555)
	ON_STN_CLICKED(556, &DIALOG_POSI::OnStnClickedStaticT556)
	ON_STN_CLICKED(561, &DIALOG_POSI::OnStnClickedStaticT561)
	ON_STN_CLICKED(562, &DIALOG_POSI::OnStnClickedStaticT562)
	ON_STN_CLICKED(563, &DIALOG_POSI::OnStnClickedStaticT563)
	ON_STN_CLICKED(564, &DIALOG_POSI::OnStnClickedStaticT564)
	ON_STN_CLICKED(565, &DIALOG_POSI::OnStnClickedStaticT565)
	ON_STN_CLICKED(566, &DIALOG_POSI::OnStnClickedStaticT566)
	ON_STN_CLICKED(611, &DIALOG_POSI::OnStnClickedStaticT611)
	ON_STN_CLICKED(612, &DIALOG_POSI::OnStnClickedStaticT612)
	ON_STN_CLICKED(613, &DIALOG_POSI::OnStnClickedStaticT613)
	ON_STN_CLICKED(614, &DIALOG_POSI::OnStnClickedStaticT614)
	ON_STN_CLICKED(615, &DIALOG_POSI::OnStnClickedStaticT615)
	ON_STN_CLICKED(616, &DIALOG_POSI::OnStnClickedStaticT616)
	ON_STN_CLICKED(621, &DIALOG_POSI::OnStnClickedStaticT621)
	ON_STN_CLICKED(622, &DIALOG_POSI::OnStnClickedStaticT622)
	ON_STN_CLICKED(623, &DIALOG_POSI::OnStnClickedStaticT623)
	ON_STN_CLICKED(624, &DIALOG_POSI::OnStnClickedStaticT624)
	ON_STN_CLICKED(625, &DIALOG_POSI::OnStnClickedStaticT625)
	ON_STN_CLICKED(626, &DIALOG_POSI::OnStnClickedStaticT626)
	ON_STN_CLICKED(631, &DIALOG_POSI::OnStnClickedStaticT631)
	ON_STN_CLICKED(632, &DIALOG_POSI::OnStnClickedStaticT632)
	ON_STN_CLICKED(633, &DIALOG_POSI::OnStnClickedStaticT633)
	ON_STN_CLICKED(634, &DIALOG_POSI::OnStnClickedStaticT634)
	ON_STN_CLICKED(635, &DIALOG_POSI::OnStnClickedStaticT635)
	ON_STN_CLICKED(636, &DIALOG_POSI::OnStnClickedStaticT636)
	ON_STN_CLICKED(641, &DIALOG_POSI::OnStnClickedStaticT641)
	ON_STN_CLICKED(642, &DIALOG_POSI::OnStnClickedStaticT642)
	ON_STN_CLICKED(643, &DIALOG_POSI::OnStnClickedStaticT643)
	ON_STN_CLICKED(644, &DIALOG_POSI::OnStnClickedStaticT644)
	ON_STN_CLICKED(645, &DIALOG_POSI::OnStnClickedStaticT645)
	ON_STN_CLICKED(646, &DIALOG_POSI::OnStnClickedStaticT646)
	ON_STN_CLICKED(651, &DIALOG_POSI::OnStnClickedStaticT651)
	ON_STN_CLICKED(652, &DIALOG_POSI::OnStnClickedStaticT652)
	ON_STN_CLICKED(653, &DIALOG_POSI::OnStnClickedStaticT653)
	ON_STN_CLICKED(654, &DIALOG_POSI::OnStnClickedStaticT654)
	ON_STN_CLICKED(655, &DIALOG_POSI::OnStnClickedStaticT655)
	ON_STN_CLICKED(656, &DIALOG_POSI::OnStnClickedStaticT656)
	ON_STN_CLICKED(661, &DIALOG_POSI::OnStnClickedStaticT661)
	ON_STN_CLICKED(662, &DIALOG_POSI::OnStnClickedStaticT662)
	ON_STN_CLICKED(663, &DIALOG_POSI::OnStnClickedStaticT663)
	ON_STN_CLICKED(664, &DIALOG_POSI::OnStnClickedStaticT664)
	ON_STN_CLICKED(665, &DIALOG_POSI::OnStnClickedStaticT665)
	ON_STN_CLICKED(666, &DIALOG_POSI::OnStnClickedStaticT666)








		ON_WM_LBUTTONDOWN()
		ON_WM_LBUTTONUP()
		ON_COMMAND(ID_EXIST_32778, &DIALOG_POSI::OnExist32778)
		ON_COMMAND(ID_EMPTY_32787, &DIALOG_POSI::OnEmpty32787)
		ON_COMMAND(ID_EXIST_32780, &DIALOG_POSI::OnExistPlaceBottle)
		ON_COMMAND(ID_EXIST_32783, &DIALOG_POSI::OnExistLockPosition)
		ON_COMMAND(ID_EXIST_32782, &DIALOG_POSI::OnExistWasteSolution)
		ON_COMMAND(ID_EXIST_32781, &DIALOG_POSI::OnExistTakeOutTheBottle)
		ON_COMMAND(ID_EMPTY_32788, &DIALOG_POSI::OnEmptyPlaceBottle)
		END_MESSAGE_MAP()


// DIALOG_POSI 消息处理程序


BOOL DIALOG_POSI::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// TODO:  在此添加额外的初始化
	CoInitialize(NULL);
	m_pConnection.CreateInstance(__uuidof(Connection));
	try
	{
		m_pConnection->Open("driver={SQL Server};Server=127.0.0.1;Database=Eeds;UID=sa;PWD=123456", "", "", adModeUnknown);
	}
	catch (_com_error e)//捕捉异常
	{
		CString errormessage;
		errormessage.Format(_T("连接数据库失败！错误信息：%s"), e.ErrorMessage());
		AfxMessageBox(errormessage);//显示错误信息 
	}
	

	/*m_pBtns = NULL;
	if (NULL == m_pBtns)
	{
		int iBtnNum = 10, iMax = 0;
		m_pBtns = new CButton[iBtnNum];
		CString strBtnText = _T("");
		for (int i = 0; i < iBtnNum; i++)
		{
			strBtnText.Format(_T("Button %.2d"), i);
			m_pBtns[i].Create(strBtnText, WS_VISIBLE | WS_CHILD, CRect(50, 50 + 100 * i, 150, 130 + 100 * i), this, 3000 + i);
			m_pBtns[i].ShowWindow(SW_SHOW);			
		}*/

		int iMax = 3000;
		SCROLLINFO info;
		info.cbSize = sizeof(SCROLLINFO);
		info.fMask = SIF_ALL;
		info.nMin = 0;
		info.nMax = iMax;
		info.nPage = 325;//每页的高度也就是窗口高度，滚动条的长度=nPage/nMax
		info.nPos = 0;
		SetScrollInfo(SB_VERT, &info, TRUE);
		
		int i=2, j=0, k=0;
		while (i <= 6)
		{
			j=1;
			while (j <= 6)
			{
				k = 1;
				while (k <= 6)
				{
					NewSt(i*100+j*10+k, CRect(20, 20, 310, 40));
					GetDlgItem(i * 100 + j * 10 + k)->MoveWindow(75 + (k - 1) * 290, 120+j*45+(i-2)*300, 250, 40);
					NewPic(2000+i * 100 + j * 10 + k, CRect(20, 20, 25, 40));
					GetDlgItem(2000 + i * 100 + j * 10 + k)->MoveWindow(35 + (k - 1) * 290, 115+ j * 45 + (i - 2) * 300, 25, 30);
					int b = i * 100 + j * 10 + k;
					k++;
				
				}
				j++;
			}
			i++;
		}


		i = 1; j = 0; k = 0; 
		int c = 0;
		while (i <= 4)
		{
			j = 1;
			c = 1;
			while (j <= 2)
			{
				k = 1;
				while (k <= 3)
				{

					NewSt(3000 + i * 100 + j * 10 + k, CRect(20, 20, 295, 40));
					if (GetDlgItem(3000 + i * 100 + j * 10 + k))
					{
						GetDlgItem(3000 + i * 100 + j * 10 + k)->MoveWindow(75 + (c - 1) * 295, 1700 + (i - 1) * 45, 150, 40);
					}
					int b = 3000 + i * 100 + j * 10 + k; 
					k++;
					c++;
				}
				j++;
			}
			i++;
		}
		//k = 1;
		//while (k <= 6)
		//{
		//	//int a = 310;
		//	//NewSt(StPos[2][1][k], CRect(75+(k-1)*310,150,225,30));
		//	NewSt(210+k, CRect(20, 20, 225, 40));
		//	GetDlgItem(210 + k)->MoveWindow(75 + (k - 1) * 235, 150, 150, 40);
		//	NewPic(2210 + k, CRect(20, 20, 25, 40));
		//	GetDlgItem(2210 + k)->MoveWindow(35 + (k - 1) * 235, 145, 25, 40);
		//	k++;
		//}
		//NewSt(211, CRect(20,20,225,60));

	/*	CheckState();*/


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
//void DIALOG_POSI::OnStnClickedStaticT1a3()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CheckState();
//	bottle = _T("T1A3");
//	LiquidPosi = bottle;
//	DisplayMenu();
//	if (LiquFlag == 1)
//	{
//		LiquPos = _T("T1A3");
//		LiquVol = m_pRecordset->GetCollect(_T("容积"));
//		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
//		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
//		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
//	}
//	else
//	{
//		LiquPos = _T("");
//		LiquVol = _T("");
//		MaxVol = _T("");
//		MinVol = _T("");
//		OverTim = _T("");
//	}
//}
//
//
//void DIALOG_POSI::OnStnClickedStaticT1a2()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CheckState();
//	bottle = _T("T1A2");
//	LiquidPosi = bottle;
//	DisplayMenu();
//	if (LiquFlag == 1)
//	{
//		LiquPos = _T("T1A2");
//		LiquVol = m_pRecordset->GetCollect(_T("容积"));
//		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
//		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
//		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
//	}
//	else
//	{
//		LiquPos = _T("");
//		LiquVol = _T("");
//		MaxVol = _T("");
//		MinVol = _T("");
//		OverTim = _T("");
//	}
//}
//
//
//void DIALOG_POSI::OnStnClickedStaticT1a1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CheckState();
//	//bottle = _T("T1A1");
//	//LiquidPosi = bottle;
//	//DisplayMenu();
//	//if (LiquFlag == 1)
//	//{
//	//	LiquPos = _T("T1A1");
//	//	LiquVol = m_pRecordset->GetCollect(_T("容积"));
//	//	MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
//	//	MinVol = m_pRecordset->GetCollect(_T("最小容积"));
//	//	OverTim = m_pRecordset->GetCollect(_T("终止时间"));
//	//}
//	//else
//	//{
//	//	LiquPos = _T("");
//	//	LiquVol = _T("");
//	//	MaxVol = _T("");
//	//	MinVol = _T("");
//	//	OverTim = _T("");
//	//}
//}

void DIALOG_POSI::CheckState()
{
	CString sql;
	sql.Format(_T("select* from Position order by 瓶子"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);



	//int i = 0, j = 0;

	int i = 2, j = 1, k = 0;
	while (m_pRecordset->adoEOF == 0)
	{
		ry = m_pRecordset->GetCollect(_T("溶液"));
		zzsj = m_pRecordset->GetCollect(_T("终止时间"));
		rj = m_pRecordset->GetCollect(_T("容积"));

		CBitmap bitmap;  // CBitmap对象，用于加载位图
		HBITMAP hBmp;

		
		if (j == 6 && k == 6)
		{
			i++;
			j = k = 1;
		}
		else
		{
			if (k < 6)
			{
				k++;
			}
			else
			{
				j++;
				k = 1;
			}
		}
		int b = 2000 + i * 100 + j * 10 + k;
		int a = i * 100 + j * 10 + k;
		if (ry != _T(""))
		{
			CString position, digit1, digit2, digit3;
			position = _T("T");
			if (j == 1)
			{
				digit2 = _T("A");
			}
			else if (j == 2)
			{
				digit2 = _T("B");
			}
			else if (j == 3)
			{
				digit2 = _T("C");
			}
			else if (j == 4)
			{
				digit2 = _T("D");
			}
			else if (j == 5)
			{
				digit2 = _T("E");
			}
			else if (j == 6)
			{
				digit2 = _T("F");
			}

			digit1.Format(_T("%d"), i - 1);
			digit3.Format(_T("%d"), k);
			nd = m_pRecordset->GetCollect(_T("浓度"));
			position = position + digit1 + digit2 + digit3 + _T("-") + ry + _T("-") + nd + _T("[g/L]");
			GetDlgItem(a)->SetWindowTextW(position);
			
			if (rj != _T(""))
			{
				COleVariant vtime(zzsj);
				vtime.ChangeType(VT_DATE);
				COleDateTime time4 = vtime;
				SYSTEMTIME systime;
				VariantTimeToSystemTime(time4, &systime);
				CTime ddl(systime);

				//获取系统时间
				CTime tm;
				tm = CTime::GetCurrentTime();
				CTimeSpan timeSpan(0, 5, 0, 0);
				tm += timeSpan;
				if (ddl > tm)
				{
					bitmap.LoadBitmap(IDB_BITMAP_SOLUTION);  // 将位图IDB_BITMAP1加载到bitmap
					hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
															 //m_pic_t1[i][j].SetBitmap(hBmp);
					((CStatic*)GetDlgItem(b))->SetBitmap(hBmp);
				}
				else
				{
					bitmap.LoadBitmap(IDB_BITMAP_OVERDUE);  // 将位图IDB_BITMAP1加载到bitmap
					hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
															 //m_pic_t1[i][j].SetBitmap(hBmp);
					((CStatic*)GetDlgItem(b))->SetBitmap(hBmp);
				}
			}
			else
			{
				bitmap.LoadBitmap(IDB_BITMAP_EXIST);  // 将位图IDB_BITMAP1加载到bitmap
				hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
														 //m_pic_t1[i][j].SetBitmap(hBmp);
				((CStatic*)GetDlgItem(b))->SetBitmap(hBmp);
			}
			
		}
		else
		{
			
			bitmap.LoadBitmap(IDB_BITMAP_EMPTY);  // 将位图IDB_BITMAP1加载到bitmap
			hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄
			//m_pic_t1[i][j].SetBitmap(hBmp);
			((CStatic*)GetDlgItem(b))->SetBitmap(hBmp);
		}
		//i++;
		//j++;
		m_pRecordset->MoveNext();
	}

}

_RecordsetPtr& DIALOG_POSI::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
{
	try
	{
		//创建记录集对象
		m_pRecordset.CreateInstance(__uuidof(Recordset));

		//取得表中的记录
		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(),
			adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch (_com_error e)
	{
		e.Description();
	}
	//返回记录集
	return m_pRecordset;
}

BOOL DIALOG_POSI::ExitConn()
{
	//关闭记录集和连接
	if (m_pRecordset != NULL)
	{
		m_pRecordset->Close();
	}
	m_pRecordset = NULL;
	m_pConnection->Close();
	::CoUninitialize(); //可以理解为关闭COM库组件

	return TRUE;
}

void DIALOG_POSI::DisplayMenu()
{
	SearchData();
	CMenu  popup;
	ry = m_pRecordset->GetCollect(_T("溶液"));
	rj = m_pRecordset->GetCollect(_T("容积"));
	//zzsj = m_pRecordset->GetCollect(_T("终止时间"));
	if (rj != _T(""))
	{
		popup.LoadMenu(IDR_MENU_EXIST);
		LiquFlag = 1;
	}
	else
	{
		popup.LoadMenu(IDR_MENU_EMPTY);
		LiquFlag = 0;
	}
	CMenu*   pM = popup.GetSubMenu(0);  //得到菜单项
	CPoint   p;
	GetCursorPos(&p);                    //得到鼠标指针的位置
	pM->TrackPopupMenu(TPM_LEFTALIGN, p.x, p.y, this);
}

void DIALOG_POSI::SearchData()
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Search_Position";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_bottle;
		Param_bottle.CreateInstance("ADODB.Parameter");
		Param_bottle = m_pCommand->CreateParameter("@瓶子", adVarWChar, adParamInput, 50, (_variant_t)bottle);
		m_pCommand->Parameters->Append(Param_bottle);

		m_pRecordset = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}

void DIALOG_POSI::AddData()
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Add_Position";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_bottle;
		Param_bottle.CreateInstance("ADODB.Parameter");
		Param_bottle = m_pCommand->CreateParameter("@瓶子", adVarWChar, adParamInput, 50, (_variant_t)bottle);
		m_pCommand->Parameters->Append(Param_bottle);

		_ParameterPtr Param_ry;
		Param_ry.CreateInstance("ADODB.Parameter");
		Param_ry = m_pCommand->CreateParameter("@溶液", adVarWChar, adParamInput, 50, (_variant_t)ry);
		m_pCommand->Parameters->Append(Param_ry);

		_ParameterPtr Param_nd;
		Param_nd.CreateInstance("ADODB.Parameter");
		Param_nd = m_pCommand->CreateParameter("@浓度", adVarWChar, adParamInput, 50, (_variant_t)nd);
		m_pCommand->Parameters->Append(Param_nd);

		_ParameterPtr Param_rj;
		Param_rj.CreateInstance("ADODB.Parameter");
		Param_rj = m_pCommand->CreateParameter("@容积", adVarWChar, adParamInput, 50, (_variant_t)rj);
		m_pCommand->Parameters->Append(Param_rj);

		_ParameterPtr Param_sj;
		Param_sj.CreateInstance("ADODB.Parameter");
		Param_sj = m_pCommand->CreateParameter("@时间", adVarWChar, adParamInput, 50, (_variant_t)sj);
		m_pCommand->Parameters->Append(Param_sj);

		_ParameterPtr Param_zt;
		Param_zt.CreateInstance("ADODB.Parameter");
		Param_zt = m_pCommand->CreateParameter("@状态", adVarWChar, adParamInput, 50, (_variant_t)zt);
		m_pCommand->Parameters->Append(Param_zt);

		_ParameterPtr Param_zzsj;
		Param_zzsj.CreateInstance("ADODB.Parameter");
		Param_zzsj = m_pCommand->CreateParameter("@终止时间", adVarWChar, adParamInput, 50, (_variant_t)zzsj);
		m_pCommand->Parameters->Append(Param_zzsj);

		_ParameterPtr Param_zxczl;
		Param_zxczl.CreateInstance("ADODB.Parameter");
		Param_zxczl = m_pCommand->CreateParameter("@最小称重量", adVarWChar, adParamInput, 50, (_variant_t)zxczl);
		m_pCommand->Parameters->Append(Param_zxczl);

		_ParameterPtr Param_zxrj;
		Param_zxrj.CreateInstance("ADODB.Parameter");
		Param_zxrj = m_pCommand->CreateParameter("@最小容积", adVarWChar, adParamInput, 50, (_variant_t)zxrj);
		m_pCommand->Parameters->Append(Param_zxrj);

		_ParameterPtr Param_zdrj;
		Param_zdrj.CreateInstance("ADODB.Parameter");
		Param_zdrj = m_pCommand->CreateParameter("@最大容积", adVarWChar, adParamInput, 50, (_variant_t)zdrj);
		m_pCommand->Parameters->Append(Param_zdrj);

		_ParameterPtr Param_sjrj;
		Param_sjrj.CreateInstance("ADODB.Parameter");
		Param_sjrj = m_pCommand->CreateParameter("@实际容积", adVarWChar, adParamInput, 50, (_variant_t)sjrj);
		m_pCommand->Parameters->Append(Param_sjrj);

		_ParameterPtr Param_pz;
		Param_pz.CreateInstance("ADODB.Parameter");
		Param_pz = m_pCommand->CreateParameter("@皮重", adVarWChar, adParamInput, 50, (_variant_t)pz);
		m_pCommand->Parameters->Append(Param_pz);

		_ParameterPtr Param_ybrj;
		Param_ybrj.CreateInstance("ADODB.Parameter");
		Param_ybrj = m_pCommand->CreateParameter("@预备容积", adVarWChar, adParamInput, 50, (_variant_t)ybrj);
		m_pCommand->Parameters->Append(Param_ybrj);

		//m_pRecordset = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	    m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}




void DIALOG_POSI::OnExist32786()
{
	// TODO: 在此添加命令处理程序代码
	Dlg_Pos_Attr  dlg_pos_attr;
	dlg_pos_attr.DoModal();
}


void DIALOG_POSI::OnEmpty32792()
{
	// TODO: 在此添加命令处理程序代码
	Dlg_Pos_Attr  dlg_pos_attr;
	dlg_pos_attr.DoModal();
}





void DIALOG_POSI::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	//CheckState();
	//RedrawWindow();
	switch (nSBCode) {
	case SB_BOTTOM:
	{
		ScrollWindow(0, scrollinfo.nPos - scrollinfo.nMax + scrollinfo.nPage);
		scrollinfo.nPos = scrollinfo.nMax - scrollinfo.nPage;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	}
	break;
	case SB_TOP:
	{
		ScrollWindow(0, scrollinfo.nPos);
		scrollinfo.nPos = 0;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	}
	break;
	case SB_LINEUP://上箭头
	{
		int iLeft = scrollinfo.nPos, iJump = (iLeft > SCROLLBAR_JUMP) ? SCROLLBAR_JUMP : iLeft;
		scrollinfo.nPos -= iJump;
		SetScrollInfo(SB_VERT, &scrollinfo, TRUE);
		ScrollWindow(0, iJump);
	}
	break;
	case SB_LINEDOWN://下箭头
	{
		int iLeft = scrollinfo.nMax - scrollinfo.nPage - scrollinfo.nPos, iJump = (iLeft > SCROLLBAR_JUMP) ? SCROLLBAR_JUMP : iLeft;
		scrollinfo.nPos += iJump;
		SetScrollInfo(SB_VERT, &scrollinfo, TRUE);
		ScrollWindow(0, 0 - iJump);
	}
	break;
	case SB_PAGEUP://上空白
	{
		int iLeft = scrollinfo.nPos, iJump = (iLeft > SCROLLBAR_JUMP*SCROLLBAR_JUMP) ? (SCROLLBAR_JUMP*SCROLLBAR_JUMP) : iLeft;
		scrollinfo.nPos -= iJump;
		SetScrollInfo(SB_VERT, &scrollinfo, TRUE);
		ScrollWindow(0, iJump);
	}
	break;
	case SB_PAGEDOWN://下空白
	{
		int iLeft = scrollinfo.nMax - scrollinfo.nPage - scrollinfo.nPos, iJump = (iLeft > SCROLLBAR_JUMP*SCROLLBAR_JUMP) ? (SCROLLBAR_JUMP*SCROLLBAR_JUMP) : iLeft;
		scrollinfo.nPos += iJump;
		SetScrollInfo(SB_VERT, &scrollinfo, TRUE);
		ScrollWindow(0, 0 - iJump);
	}
	break;
	case SB_ENDSCROLL://结束
					  // MessageBox("SB_ENDSCROLL");
		break;
	case SB_THUMBPOSITION://拖拽的最终位置
						  // ScrollWindow(0,(scrollinfo.nPos-nPos)*SCROLLBAR_STEP);
						  // scrollinfo.nPos = nPos;
						  // SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		break;
	case SB_THUMBTRACK://拖拽过程中的位置
	{
		ScrollWindow(0, scrollinfo.nPos - nPos);
		scrollinfo.nPos = nPos;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	}
	break;
	}
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL DIALOG_POSI::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	//CheckState();
	if (zDelta > 0) { // 向上滚
		int iMulti = zDelta / WHEEL_DELTA;//倍数
		int iLeft = scrollinfo.nPos, iJump = (iLeft > SCROLLBAR_JUMP*SCROLLBAR_JUMP*iMulti) ? (SCROLLBAR_JUMP*SCROLLBAR_JUMP*iMulti) : iLeft;
		scrollinfo.nPos -= iJump;
		SetScrollInfo(SB_VERT, &scrollinfo, TRUE);
		ScrollWindow(0, iJump);
	}
	else { // 向下滚
		int iMulti = zDelta / (0 - WHEEL_DELTA);//倍数
		int iLeft = scrollinfo.nMax - scrollinfo.nPage - scrollinfo.nPos, iJump = (iLeft > SCROLLBAR_JUMP*SCROLLBAR_JUMP*iMulti) ? (SCROLLBAR_JUMP*SCROLLBAR_JUMP*iMulti) : iLeft;
		scrollinfo.nPos += iJump;
		SetScrollInfo(SB_VERT, &scrollinfo, TRUE);
		ScrollWindow(0, 0 - iJump);
	}
	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}


void DIALOG_POSI::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CheckState();
	//CBitmap bitmap;  // CBitmap对象，用于加载位图   
	//HBITMAP hBmp;    // 保存CBitmap加载的位图的句柄   

	//bitmap.LoadBitmap(IDB_BITMAP_EXIST);  // 将位图IDB_BITMAP1加载到bitmap   
	//hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄   
	//										 //m_pic1.SetBitmap(hBmp);
	//((CStatic*)GetDlgItem(2111))->SetBitmap(hBmp);
	//				   // TODO: 在此处添加消息处理程序代码
	//				   // 不为绘图消息调用 CDialogEx::OnPaint()
	//CDialogEx::OnPaint();
}

CStatic* DIALOG_POSI::NewSt(int nID, CRect rect)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //取按钮标题
	//bottle = m_Caption;
	//ry = _T("");
	//nd = _T("");
	//rj = _T("");
	//sj = _T("");
	//zt = _T("");
	//zzsj = _T("");
	//zxczl = _T("");
	//zxrj = _T("");
	//zdrj = _T("");
	//sjrj = _T("");
	//pz = _T("");
	//ybrj = _T("");
	//AddData();
	CStatic *p_Button = new CStatic();
	ASSERT_VALID(p_Button);
	p_Button->Create(m_Caption, WS_CHILD | WS_VISIBLE | SS_NOTIFY, rect, this, nID);  //创建按钮
	return p_Button;
}

CStatic* DIALOG_POSI::NewPic(int nID, CRect rect)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //取按钮标题
	CStatic *pPictureControl = new CStatic();
	ASSERT_VALID(pPictureControl);
	pPictureControl->Create(_T(""), WS_CHILD | WS_VISIBLE | SS_BITMAP, rect, this, nID);  //创建按钮
	return pPictureControl;
}



HBRUSH DIALOG_POSI::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	//switch (nCtlColor)
	//{
	//case CTLCOLOR_DLG:
	//	HBRUSH aBrush;
	//	aBrush = CreateSolidBrush(RGB(255, 255, 255));
	//	hbr = aBrush;
	//	break;
	//}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


BOOL DIALOG_POSI::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CDialogEx::OnEraseBkgnd(pDC);
	//return true;
}

void DIALOG_POSI::OnStnClickedStaticT211()
{
	CheckState();
	bottle = _T("T1A1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1A1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT212()
{
	CheckState();
	bottle = _T("T1A2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1A2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT213()
{
	CheckState();
	bottle = _T("T1A3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1A3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT214()
{
	CheckState();
	bottle = _T("T1A4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1A4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT215()
{
	CheckState();
	bottle = _T("T1A5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1A5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT216()
{
	CheckState();
	bottle = _T("T1A6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1A6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT221()
{
	CheckState();
	bottle = _T("T1B1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1B1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT222()
{
	CheckState();
	bottle = _T("T1B2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1B2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT223()
{
	CheckState();
	bottle = _T("T1B3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1B3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT224()
{
	CheckState();
	bottle = _T("T1B4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1B4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT225()
{
	CheckState();
	bottle = _T("T1B5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1B5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT226()
{
	CheckState();
	bottle = _T("T1B6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1B6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT231()
{
	CheckState();
	bottle = _T("T1C1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1C1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT232()
{
	CheckState();
	bottle = _T("T1C2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1C2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT233()
{
	CheckState();
	bottle = _T("T1C3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1C3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT234()
{
	CheckState();
	bottle = _T("T1C4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1C4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT235()
{
	CheckState();
	bottle = _T("T1C5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1C5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT236()
{
	CheckState();
	bottle = _T("T1C6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1C6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT241()
{
	CheckState();
	bottle = _T("T1D1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1D1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT242()
{
	CheckState();
	bottle = _T("T1D2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1D2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT243()
{
	CheckState();
	bottle = _T("T1D3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1D3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT244()
{
	CheckState();
	bottle = _T("T1D4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1D4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT245()
{
	CheckState();
	bottle = _T("T1D5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1D5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT246()
{
	CheckState();
	bottle = _T("T1D6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1D6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT251()
{
	CheckState();
	bottle = _T("T1E1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1E1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT252()
{
	CheckState();
	bottle = _T("T1E2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1E2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT253()
{
	CheckState();
	bottle = _T("T1E3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1E3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT254()
{
	CheckState();
	bottle = _T("T1E4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1E4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT255()
{
	CheckState();
	bottle = _T("T1E5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1E5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT256()
{
	CheckState();
	bottle = _T("T1E6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1E6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT261()
{
	CheckState();
	bottle = _T("T1F1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1F1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT262()
{
	CheckState();
	bottle = _T("T1F2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1F2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT263()
{
	CheckState();
	bottle = _T("T1F3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1F3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT264()
{
	CheckState();
	bottle = _T("T1F4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1F4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT265()
{
	CheckState();
	bottle = _T("T1F5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1F5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT266()
{
	CheckState();
	bottle = _T("T1F6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T1F6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT311()
{
	CheckState();
	bottle = _T("T2A1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2A1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT312()
{
	CheckState();
	bottle = _T("T2A2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2A2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT313()
{
	CheckState();
	bottle = _T("T2A3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2A3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT314()
{
	CheckState();
	bottle = _T("T2A4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2A4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT315()
{
	CheckState();
	bottle = _T("T2A5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2A5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT316()
{
	CheckState();
	bottle = _T("T2A6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2A6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT321()
{
	CheckState();
	bottle = _T("T2B1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2B1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT322()
{
	CheckState();
	bottle = _T("T2B2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2B2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT323()
{
	CheckState();
	bottle = _T("T2B3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2B3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT324()
{
	CheckState();
	bottle = _T("T2B4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2B4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT325()
{
	CheckState();
	bottle = _T("T2B5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2B5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT326()
{
	CheckState();
	bottle = _T("T2B6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2B6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT331()
{
	CheckState();
	bottle = _T("T2C1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2C1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT332()
{
	CheckState();
	bottle = _T("T2C2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2C2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT333()
{
	CheckState();
	bottle = _T("T2C3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2C3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT334()
{
	CheckState();
	bottle = _T("T2C4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2C4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT335()
{
	CheckState();
	bottle = _T("T2C5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2C5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT336()
{
	CheckState();
	bottle = _T("T2C6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2C6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT341()
{
	CheckState();
	bottle = _T("T2D1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2D1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT342()
{
	CheckState();
	bottle = _T("T2D2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2D2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT343()
{
	CheckState();
	bottle = _T("T2D3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2D3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT344()
{
	CheckState();
	bottle = _T("T2D4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2D4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT345()
{
	CheckState();
	bottle = _T("T2D5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2D5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT346()
{
	CheckState();
	bottle = _T("T2D6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2D6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT351()
{
	CheckState();
	bottle = _T("T2E1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2E1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT352()
{
	CheckState();
	bottle = _T("T2E2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2E2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT353()
{
	CheckState();
	bottle = _T("T2E3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2E3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT354()
{
	CheckState();
	bottle = _T("T2E4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2E4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT355()
{
	CheckState();
	bottle = _T("T2E5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2E5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT356()
{
	CheckState();
	bottle = _T("T2E6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2E6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT361()
{
	CheckState();
	bottle = _T("T2F1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2F1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT362()
{
	CheckState();
	bottle = _T("T2F2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2F2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT363()
{
	CheckState();
	bottle = _T("T2F3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2F3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT364()
{
	CheckState();
	bottle = _T("T2F4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2F4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT365()
{
	CheckState();
	bottle = _T("T2F5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2F5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT366()
{
	CheckState();
	bottle = _T("T2F6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T2F6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT411()
{
	CheckState();
	bottle = _T("T3A1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3A1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT412()
{
	CheckState();
	bottle = _T("T3A2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3A2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT413()
{
	CheckState();
	bottle = _T("T3A3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3A3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT414()
{
	CheckState();
	bottle = _T("T3A4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3A4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT415()
{
	CheckState();
	bottle = _T("T3A5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3A5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT416()
{
	CheckState();
	bottle = _T("T3A6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3A6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT421()
{
	CheckState();
	bottle = _T("T3B1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3B1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT422()
{
	CheckState();
	bottle = _T("T3B2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3B2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT423()
{
	CheckState();
	bottle = _T("T3B3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3B3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT424()
{
	CheckState();
	bottle = _T("T3B4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3B4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT425()
{
	CheckState();
	bottle = _T("T3B5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3B5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT426()
{
	CheckState();
	bottle = _T("T3B6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3B6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT431()
{
	CheckState();
	bottle = _T("T3C1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3C1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT432()
{
	CheckState();
	bottle = _T("T3C2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3C2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT433()
{
	CheckState();
	bottle = _T("T3C3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3C3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT434()
{
	CheckState();
	bottle = _T("T3C4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3C4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT435()
{
	CheckState();
	bottle = _T("T3C5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3C5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT436()
{
	CheckState();
	bottle = _T("T3C6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3C6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT441()
{
	CheckState();
	bottle = _T("T3D1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3D1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT442()
{
	CheckState();
	bottle = _T("T3D2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3D2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT443()
{
	CheckState();
	bottle = _T("T3D3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3D3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT444()
{
	CheckState();
	bottle = _T("T3D4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3D4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT445()
{
	CheckState();
	bottle = _T("T3D5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3D5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT446()
{
	CheckState();
	bottle = _T("T3D6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3D6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT451()
{
	CheckState();
	bottle = _T("T3E1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3E1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT452()
{
	CheckState();
	bottle = _T("T3E2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3E2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT453()
{
	CheckState();
	bottle = _T("T3E3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3E3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT454()
{
	CheckState();
	bottle = _T("T3E4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3E4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT455()
{
	CheckState();
	bottle = _T("T3E5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3E5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT456()
{
	CheckState();
	bottle = _T("T3E6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3E6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT461()
{
	CheckState();
	bottle = _T("T3F1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3F1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT462()
{
	CheckState();
	bottle = _T("T3F2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3F2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT463()
{
	CheckState();
	bottle = _T("T3F3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3F3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT464()
{
	CheckState();
	bottle = _T("T3F4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3F4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT465()
{
	CheckState();
	bottle = _T("T3F5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3F5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT466()
{
	CheckState();
	bottle = _T("T3F6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T3F6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT511()
{
	CheckState();
	bottle = _T("T4A1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4A1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT512()
{
	CheckState();
	bottle = _T("T4A2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4A2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT513()
{
	CheckState();
	bottle = _T("T4A3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4A3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT514()
{
	CheckState();
	bottle = _T("T4A4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4A4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT515()
{
	CheckState();
	bottle = _T("T4A5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4A5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT516()
{
	CheckState();
	bottle = _T("T4A6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4A6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT521()
{
	CheckState();
	bottle = _T("T4B1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4B1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT522()
{
	CheckState();
	bottle = _T("T4B2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4B2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT523()
{
	CheckState();
	bottle = _T("T4B3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4B3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT524()
{
	CheckState();
	bottle = _T("T4B4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4B4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT525()
{
	CheckState();
	bottle = _T("T4B5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4B5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT526()
{
	CheckState();
	bottle = _T("T4B6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4B6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT531()
{
	CheckState();
	bottle = _T("T4C1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4C1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT532()
{
	CheckState();
	bottle = _T("T4C2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4C2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT533()
{
	CheckState();
	bottle = _T("T4C3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4C3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT534()
{
	CheckState();
	bottle = _T("T4C4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4C4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT535()
{
	CheckState();
	bottle = _T("T4C5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4C5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT536()
{
	CheckState();
	bottle = _T("T4C6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4C6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT541()
{
	CheckState();
	bottle = _T("T4D1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4D1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT542()
{
	CheckState();
	bottle = _T("T4D2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4D2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT543()
{
	CheckState();
	bottle = _T("T4D3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4D3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT544()
{
	CheckState();
	bottle = _T("T4D4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4D4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT545()
{
	CheckState();
	bottle = _T("T4D5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4D5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT546()
{
	CheckState();
	bottle = _T("T4D6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4D6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT551()
{
	CheckState();
	bottle = _T("T4E1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4E1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT552()
{
	CheckState();
	bottle = _T("T4E2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4E2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT553()
{
	CheckState();
	bottle = _T("T4E3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4E3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT554()
{
	CheckState();
	bottle = _T("T4E4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4E4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT555()
{
	CheckState();
	bottle = _T("T4E5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4E5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT556()
{
	CheckState();
	bottle = _T("T4E6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4E6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT561()
{
	CheckState();
	bottle = _T("T4F1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4F1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT562()
{
	CheckState();
	bottle = _T("T4F2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4F2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT563()
{
	CheckState();
	bottle = _T("T4F3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4F3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT564()
{
	CheckState();
	bottle = _T("T4F4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4F4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT565()
{
	CheckState();
	bottle = _T("T4F5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4F5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT566()
{
	CheckState();
	bottle = _T("T4F6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T4F6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT611()
{
	CheckState();
	bottle = _T("T5A1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5A1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT612()
{
	CheckState();
	bottle = _T("T5A2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5A2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT613()
{
	CheckState();
	bottle = _T("T5A3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5A3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT614()
{
	CheckState();
	bottle = _T("T5A4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5A4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT615()
{
	CheckState();
	bottle = _T("T5A5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5A5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT616()
{
	CheckState();
	bottle = _T("T5A6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5A6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT621()
{
	CheckState();
	bottle = _T("T5B1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5B1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT622()
{
	CheckState();
	bottle = _T("T5B2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5B2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT623()
{
	CheckState();
	bottle = _T("T5B3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5B3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT624()
{
	CheckState();
	bottle = _T("T5B4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5B4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT625()
{
	CheckState();
	bottle = _T("T5B5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5B5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT626()
{
	CheckState();
	bottle = _T("T5B6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5B6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT631()
{
	CheckState();
	bottle = _T("T5C1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5C1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT632()
{
	CheckState();
	bottle = _T("T5C2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5C2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT633()
{
	CheckState();
	bottle = _T("T5C3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5C3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT634()
{
	CheckState();
	bottle = _T("T5C4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5C4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT635()
{
	CheckState();
	bottle = _T("T5C5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5C5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT636()
{
	CheckState();
	bottle = _T("T5C6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5C6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT641()
{
	CheckState();
	bottle = _T("T5D1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5D1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT642()
{
	CheckState();
	bottle = _T("T5D2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5D2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT643()
{
	CheckState();
	bottle = _T("T5D3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5D3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT644()
{
	CheckState();
	bottle = _T("T5D4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5D4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT645()
{
	CheckState();
	bottle = _T("T5D5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5D5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT646()
{
	CheckState();
	bottle = _T("T5D6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5D6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT651()
{
	CheckState();
	bottle = _T("T5E1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5E1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT652()
{
	CheckState();
	bottle = _T("T5E2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5E2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT653()
{
	CheckState();
	bottle = _T("T5E3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5E3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT654()
{
	CheckState();
	bottle = _T("T5E4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5E4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT655()
{
	CheckState();
	bottle = _T("T5E5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5E5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT656()
{
	CheckState();
	bottle = _T("T5E6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5E6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT661()
{
	CheckState();
	bottle = _T("T5F1");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5F1");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT662()
{
	CheckState();
	bottle = _T("T5F2");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5F2");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT663()
{
	CheckState();
	bottle = _T("T5F3");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5F3");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT664()
{
	CheckState();
	bottle = _T("T5F4");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5F4");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT665()
{
	CheckState();
	bottle = _T("T5F5");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5F5");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}
void DIALOG_POSI::OnStnClickedStaticT666()
{
	CheckState();
	bottle = _T("T5F6");
	LiquidPosi = bottle;
	DisplayMenu();
	if (LiquFlag == 1)
	{
		LiquPos = _T("T5F6");
		LiquVol = m_pRecordset->GetCollect(_T("容积"));
		MaxVol = m_pRecordset->GetCollect(_T("最大容积"));
		MinVol = m_pRecordset->GetCollect(_T("最小容积"));
		OverTim = m_pRecordset->GetCollect(_T("终止时间"));
	}
	else
	{
		LiquPos = _T("");
		LiquVol = _T("");
		MaxVol = _T("");
		MinVol = _T("");
		OverTim = _T("");
	}
}

void DIALOG_POSI::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonDown(nFlags, point);
}


void DIALOG_POSI::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonUp(nFlags, point);
}

//不存在溶液时右键菜单配置溶液
void DIALOG_POSI::OnExist32778()
{
	// TODO: 在此添加命令处理程序代码
	Dlg_Compound_Liquid *pDlg = new Dlg_Compound_Liquid;
	pDlg->Create(IDD_DLG_COMPOUND_LIQUID, this);
	pDlg->ShowWindow(SW_SHOW);
}

//存在溶液时右键菜单配置溶液
void DIALOG_POSI::OnEmpty32787()
{
	// TODO: 在此添加命令处理程序代码
	Dlg_Compound_Liquid *pDlg = new Dlg_Compound_Liquid;
	pDlg->Create(IDD_DLG_COMPOUND_LIQUID, this);
	pDlg->ShowWindow(SW_SHOW);
}

//存在溶液时右键菜单放置一个准备好的瓶子
void DIALOG_POSI::OnExistPlaceBottle()
{
	// TODO: 在此添加命令处理程序代码
	Dlg_Place_Bottle *pDlg = new Dlg_Place_Bottle;
	pDlg->Create(IDD_DLG_PLACE_BOTTLE, this);
	pDlg->ShowWindow(SW_SHOW);
}

//存在溶液时右键菜单锁定位置
void DIALOG_POSI::OnExistLockPosition()
{
	// TODO: 在此添加命令处理程序代码
}

//存在溶液时右键菜单废弃溶液
void DIALOG_POSI::OnExistWasteSolution()
{
	// TODO: 在此添加命令处理程序代码
}

//存在溶液时右键菜单拿出瓶子
void DIALOG_POSI::OnExistTakeOutTheBottle()
{
	// TODO: 在此添加命令处理程序代码
}

//空溶液时右键菜单放置一个准备好的瓶子
void DIALOG_POSI::OnEmptyPlaceBottle()
{
	// TODO: 在此添加命令处理程序代码
	Dlg_Place_Bottle *pDlg = new Dlg_Place_Bottle;
	pDlg->Create(IDD_DLG_PLACE_BOTTLE, this);
	pDlg->ShowWindow(SW_SHOW);
}
