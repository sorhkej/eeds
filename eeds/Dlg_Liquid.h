#pragma once
#include "afxcmn.h"
#include "NEWLISTCTRL.h"

// Dlg_Liquid �Ի���


class Dlg_Liquid : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Liquid)

public:
	Dlg_Liquid(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg_Liquid();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_LIQUID };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CToolBar m_toolbar;
	DECLARE_MESSAGE_MAP()
public:
	NEWLISTCTRL m_list_liquid;

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
	CString ryrj;
	CString rysjrj;
	CString zxpsl;
	CString zdpsl;
	CString zxrj;
	CString zdrj;
	CString mrrj;
	CString djhzz;
	CString dycsfjrs;
	CString decsfjrs;
	CString dyczrl;
	CString jbsj;
	CString cxxyg;
	CString xygcxry;


	int rnum = 0;
	int sum = 0;
	void CheckData();
	void SaveToDatabase();
	void DeleteData();
	BOOL ExitConn();

	virtual BOOL OnInitDialog();
	afx_msg void OnTbLiquidDelete();
	afx_msg void OnTbLiquidRefresh();
	afx_msg void OnTbLiquidSave();
	afx_msg void OnClose();
	afx_msg void OnNMClickListLiquid(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawListLiquid(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
//	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLvnBeginScrollListLiquid(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnNMDblclkListLiquid(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTbLiquidNew();
};
