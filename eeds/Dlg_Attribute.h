#pragma once
#include "afxcmn.h"
#include "NEWLISTCTRL.h"

// Dlg_Attribute 对话框

class Dlg_Attribute : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Attribute)

public:
	Dlg_Attribute(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_Attribute();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ATTRIBUTE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CToolBar m_toolbar;
	DECLARE_MESSAGE_MAP()
public:
	NEWLISTCTRL m_list_liquidAttr;

	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;
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
	int hang[10000];
	int lie[10000];
	int k = 0;
	CString mc;
	CString nd;
	CString md;
	CString jzry;
	CString xygcxry;
	CString zczrry;



	int rnum = 0;
	int sum = 0;
	void CheckData();
	void SaveToDatabase();
	void DeleteData();
	BOOL ExitConn();



	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	//afx_msg void OnNMCustomdrawList1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnTbAttributeDelete();
//	afx_msg void OnTbAttributeRefresh();
//	afx_msg void OnTbAttributeSave();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	void OnNMCustomdrawListAttribute(NMHDR * pNMHDR, LRESULT * pResult);
	afx_msg void OnNMDblclkListAttribute(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonRefresh();
};
