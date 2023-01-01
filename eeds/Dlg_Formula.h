#pragma once
#include "afxcmn.h"
#include "NEWLISTCTRL.h"


// Dlg_Formula �Ի���

class Dlg_Formula : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Formula)

public:
	Dlg_Formula(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg_Formula();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FORMULA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CToolBar m_toolbar;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	NEWLISTCTRL m_list_form;
	CComboBox m_cb_liqu;
	NEWLISTCTRL m_list_orde;
	CEdit m_edit_pote;
	CComboBox m_cb_unit;
	CEdit m_edit_orde;

	CString Liquid_Search;



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
	CString dm;
	CString mc;
	CString cjsj;
	CString xgsj;
	CString daima,mingcheng;

	//CString xl, xl1, nd1;
	CString xl,xl1,xl2, xl3,xl4,xl5,xl6,xl7,xl8,xl9,xl10;
	CString nd1,nd2,nd3,nd4,nd5,nd6,nd7,nd8,nd9,nd10;




	int rnum = 0;
	int sum = 0;
	void CheckData();
	void SaveToDatabase();
	void DeleteData();
	void SearchData();
	BOOL ExitConn();
	
	void SaveOne();
	void SaveTwo();

	afx_msg void OnTbFormulaDelete();
	afx_msg void OnTbFormulaRefresh();
	afx_msg void OnTbFormulaSave();
	//afx_msg void OnTbFormulaNew();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnNMClickListFormula(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListFormula(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeComboLiquid();
	afx_msg void OnNMDblclkListFormula(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnFormAdd();
	afx_msg void OnTbFormulaNew();
	afx_msg void OnEnChangeEditPotency();
	afx_msg void OnBnClickedBtnDelete();
};
