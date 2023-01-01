#pragma once
#include "afxcmn.h"
//#include "stdafx.h"
//#include "afxdialogex.h"
//#include "afxwin.h"
//#include "afxcmn.h"

// Dlg_Stuff 对话框

class Dlg_Stuff : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Stuff)

public:
	Dlg_Stuff(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_Stuff();
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STUFF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CToolBar m_toolbar;
	DECLARE_MESSAGE_MAP()
public:

	//用于数据库连接//
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;
	//Listcontrol控件相关
	int e_Item;    //刚编辑的行  
	int e_SubItem; //刚编辑的列  

	CEdit m_Edit;  //生成单元编辑框对象
	bool haveeditcreate;//标志编辑框已经被创建
	void createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat);//创建单元格编辑框函数
	void distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem);//销毁单元格编辑框对象

	CComboBox m_comBox;//生产单元格下拉列表对象
	bool haveccomboboxcreate;//标志下拉列表框已经被创建
	void createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat);//创建单元格下拉列表框函数
	void distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem);//销毁单元格下拉列表框


	virtual BOOL OnInitDialog();


	int hang[10000];
	int lie[10000];
	int k = 0;
	CString dm;
	CString mc;
	CString hgllx;
	CString md;
	CString hgllb;
	CString dw;
	CString ys;
	int rnum = 0;
	int sum = 0;
	COLORREF Rgb[10000];
	void CheckData();
	void SaveToDatabase();
	void DeleteData();
	BOOL ExitConn();

	CListCtrl m_list_stuff;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMClickListStuff(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTbStuffDelete();
	afx_msg void OnTbStuffRefresh();
	afx_msg void OnTbStuffSave();
	afx_msg void OnNMCustomdrawListStuff(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	afx_msg void OnNMDblclkListStuff(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTbStuffNew();
};
