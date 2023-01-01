#pragma once
#include "afxcmn.h"
//#include "stdafx.h"
//#include "afxdialogex.h"
//#include "afxwin.h"
//#include "afxcmn.h"

// Dlg_Stuff �Ի���

class Dlg_Stuff : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Stuff)

public:
	Dlg_Stuff(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg_Stuff();
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STUFF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CToolBar m_toolbar;
	DECLARE_MESSAGE_MAP()
public:

	//�������ݿ�����//
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;
	//Listcontrol�ؼ����
	int e_Item;    //�ձ༭����  
	int e_SubItem; //�ձ༭����  

	CEdit m_Edit;  //���ɵ�Ԫ�༭�����
	bool haveeditcreate;//��־�༭���Ѿ�������
	void createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat);//������Ԫ��༭����
	void distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem);//���ٵ�Ԫ��༭�����

	CComboBox m_comBox;//������Ԫ�������б����
	bool haveccomboboxcreate;//��־�����б���Ѿ�������
	void createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat);//������Ԫ�������б����
	void distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem);//���ٵ�Ԫ�������б��


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
