#pragma once
#include "afxcmn.h"
#include "NEWLISTCTRL.h"

// Dlg_Attribute �Ի���

class Dlg_Attribute : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Attribute)

public:
	Dlg_Attribute(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg_Attribute();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ATTRIBUTE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CToolBar m_toolbar;
	DECLARE_MESSAGE_MAP()
public:
	NEWLISTCTRL m_list_liquidAttr;

	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_ConnectionPtr m_pConnection;
	_CommandPtr   m_pCommand;
	_RecordsetPtr m_pRecordset;
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
