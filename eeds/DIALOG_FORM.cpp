// DIALOG_FORM.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "DIALOG_FORM.h"
#include "afxdialogex.h"
#include"Dlg_Formula_Guide.h"

// DIALOG_FORM �Ի���

IMPLEMENT_DYNAMIC(DIALOG_FORM, CDialogEx)
//int formulaNum;
DIALOG_FORM::DIALOG_FORM(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_FORM, pParent)
{

}

DIALOG_FORM::~DIALOG_FORM()
{
}

void DIALOG_FORM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_LIQU, m_list_liqu);
	DDX_Control(pDX, IDC_LIST_FOR, m_list_for);
}


BEGIN_MESSAGE_MAP(DIALOG_FORM, CDialogEx)
//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &DIALOG_FORM::OnLvnItemchangedList1)
ON_NOTIFY(NM_CLICK, IDC_LIST_FOR, &DIALOG_FORM::OnNMClickListFor)
ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_FOR, &DIALOG_FORM::OnNMCustomdrawListFor)
ON_NOTIFY(NM_RCLICK, IDC_LIST_FOR, &DIALOG_FORM::OnNMRClickListFor)
ON_COMMAND(ID_32796, &DIALOG_FORM::On32796)
ON_COMMAND(ID_Menu, &DIALOG_FORM::OnMenu)
ON_COMMAND(ID_32794, &DIALOG_FORM::On32794)
END_MESSAGE_MAP()


// DIALOG_FORM ��Ϣ�������


//void DIALOG_FORM::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	*pResult = 0;
//}


BOOL DIALOG_FORM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CoInitialize(NULL);
	m_pConnection.CreateInstance(__uuidof(Connection));
	try
	{
		m_pConnection->Open("driver={SQL Server};Server=127.0.0.1;Database=Eeds;UID=sa;PWD=123456", "", "", adModeUnknown);
	}
	catch (_com_error e)//��׽�쳣
	{
		CString errormessage;
		errormessage.Format(_T("�������ݿ�ʧ�ܣ�������Ϣ��%s"), e.ErrorMessage());
		AfxMessageBox(errormessage);//��ʾ������Ϣ 
	}
	CheckData();




	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

_RecordsetPtr& DIALOG_FORM::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
{
	try
	{
		//������¼������
		m_pRecordset.CreateInstance(__uuidof(Recordset));

		//ȡ�ñ��еļ�¼
		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(),
			adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch (_com_error e)
	{
		e.Description();
	}
	//���ؼ�¼��
	return m_pRecordset;
}

void DIALOG_FORM::CheckData()//�����ݿ���в�ѯ����
{
	CString sql;
	sql.Format(_T("select* from Formula_Detailed order by ���� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);




	m_list_for.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_for.DeleteColumn(0));	//������б�ͷ
	m_list_for.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_list_for.SetFont(&m_font);

	m_list_for.InsertColumn(0, _T("����"), LVCFMT_LEFT, 200, 2);        
	m_list_for.InsertColumn(1, _T("����"), LVCFMT_LEFT, 200, 2);
	m_list_for.InsertColumn(2, _T("��ע"), LVCFMT_LEFT, 300, 2);
	m_list_for.InsertColumn(3, _T("����λ��"), LVCFMT_LEFT, 300, 2);
	m_list_for.InsertColumn(4, _T("����[g]"), LVCFMT_LEFT, 300, 2);
	m_list_for.InsertColumn(5, _T("����[l]"), LVCFMT_LEFT, 300, 2); 

	try
	{
		(LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����"));
	}
	catch (_com_error e)
	{
		m_pRecordset = NULL;
	}
	if (m_pRecordset != NULL)
	{
		m_pRecordset->MoveFirst();

		while (m_pRecordset->adoEOF == 0)                   //���δ��������¼�����һ�У���Ϊ�б�����Ӽ����������ݡ�������¼����
		{
			m_list_for.InsertItem(0, _T(""));
			m_list_for.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
			m_list_for.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
			m_list_for.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��ע")));
			m_list_for.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����λ��")));
			m_list_for.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
			m_list_for.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
			m_pRecordset->MoveNext();
		}
	}
}

void DIALOG_FORM::OnNMClickListFor(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	if (formulaNum == 1)
	{
		CheckData();
		formulaNum = 0;
	}
	if (pEditCtrl->iItem == -1)//������ǹ�����
	{

	}
	else
	{
		float nongdu, weight;
		CString nD, wT;
		dm = m_list_for.GetItemText(pEditCtrl->iItem, 0);
		mc = m_list_for.GetItemText(pEditCtrl->iItem, 1);
		wT = m_list_for.GetItemText(pEditCtrl->iItem, 4);
		weight = _ttof(wT);
		SearchData();

		m_list_liqu.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
			| LVS_EX_FULLROWSELECT
			| LVS_EX_HEADERDRAGDROP
			| LVS_EX_ONECLICKACTIVATE
			| LVS_EX_GRIDLINES);
		while (m_list_liqu.DeleteColumn(0));	//������б�ͷ
		m_list_liqu.DeleteAllItems();

		CFont m_font;
		m_font.CreatePointFont(100, _T("΢���ź�"));
		m_list_liqu.SetFont(&m_font);

		m_list_liqu.InsertColumn(0, _T("������"), LVCFMT_LEFT, 200, 2);         //Ϊ�б�������У��������ֻ����룬��ϵ����ע
		m_list_liqu.InsertColumn(1, _T("�䷽����[g]"), LVCFMT_LEFT, 200, 2);
		m_list_liqu.InsertColumn(2, _T("�䷽����"), LVCFMT_LEFT, 150, 2);
		m_list_liqu.InsertColumn(3, _T("�䷽����"), LVCFMT_LEFT, 100, 2);
		m_list_liqu.InsertColumn(4, _T("�䷽Ũ��"), LVCFMT_LEFT, 100, 2);
		m_list_liqu.InsertColumn(5, _T("�䷽��λ"), LVCFMT_LEFT, 100, 2);

		int a = m_pRecordset->GetCollect(_T("����"));
		int i = 1;

		while (i <= a)
		{
			CString xl, nd, xh;
			xh.Format(_T("%d"), i);
			xl = _T("����");
			nd = _T("Ũ��");
			xl = xl + xh;
			nd = nd + xh;
			m_list_liqu.InsertItem(i - 1, _T(""));
			m_list_liqu.SetItemText(i - 1, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_variant_t(xl)));
			nD = m_pRecordset->GetCollect(_variant_t(nd));
			m_list_liqu.SetItemText(i - 1, 4, nD);
			nongdu = _tstof(nD);
			nd.Format(_T("%f"), nongdu*weight*0.01);
			m_list_liqu.SetItemText(i - 1, 1, nd);
			m_list_liqu.SetItemText(i - 1, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
			m_list_liqu.SetItemText(i - 1, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
			m_list_liqu.SetItemText(i - 1, 5, _T("%"));

			i++;
		}
	}
	*pResult = 0;
}

void DIALOG_FORM::SearchData()
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Search_Formula";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_dm;
		Param_dm.CreateInstance("ADODB.Parameter");
		Param_dm = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)dm);
		m_pCommand->Parameters->Append(Param_dm);

		_ParameterPtr Param_mc;
		Param_mc.CreateInstance("ADODB.Parameter");
		Param_mc = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)mc);
		m_pCommand->Parameters->Append(Param_mc);

		m_pRecordset = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
		/*	m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(),
		adOpenDynamic, adLockOptimistic, adCmdText);*/
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
	//(LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("�޸�ʱ��"))
}

void DIALOG_FORM::OnNMCustomdrawListFor(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (formulaNum == 1)
	{
		CheckData();
		formulaNum = 0;
	}
	*pResult = 0;
}

void DIALOG_FORM::OnNMRClickListFor(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	if (pEditCtrl->iItem == -1)//������ǹ�����
	{

	}
	else
	{
		CMenu  popup;
		popup.LoadMenu(IDR_MENU_FORMULA);
		CMenu*   pM = popup.GetSubMenu(0);  //�õ��˵���
		CPoint   p;
		GetCursorPos(&p);                    //�õ����ָ���λ��
		pM->TrackPopupMenu(TPM_LEFTALIGN, p.x, p.y, this);
	}

	*pResult = 0;
}

void DIALOG_FORM::On32796()
{
	// TODO: �ڴ���������������
	int nItem = m_list_for.GetSelectionMark();   // ��ȡ��������λ��
	dm = m_list_for.GetItemText(nItem, 0);
	mc = m_list_for.GetItemText(nItem, 1);
	//bz = m_list_for.GetItemText(nItem, 2);
	//zl = m_list_for.GetItemText(nItem, 4);
	DeleteData();
	CheckData();
}

void DIALOG_FORM::DeleteData()
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Delete_Formula_Detailed";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_dm;
		Param_dm.CreateInstance("ADODB.Parameter");
		Param_dm = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)dm);
		m_pCommand->Parameters->Append(Param_dm);

		_ParameterPtr Param_mc;
		Param_mc.CreateInstance("ADODB.Parameter");
		Param_mc = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)mc);
		m_pCommand->Parameters->Append(Param_mc);

	/*	_ParameterPtr Param_bz;
		Param_bz.CreateInstance("ADODB.Parameter");
		Param_bz = m_pCommand->CreateParameter("@��ע", adVarWChar, adParamInput, 50, (_variant_t)bz);
		m_pCommand->Parameters->Append(Param_bz);

		_ParameterPtr Param_zl;
		Param_zl.CreateInstance("ADODB.Parameter");
		Param_zl = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)zl);
		m_pCommand->Parameters->Append(Param_zl);*/


		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);

		/*	m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(),
		adOpenDynamic, adLockOptimistic, adCmdText);*/
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
	//(LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("�޸�ʱ��"))
}

void DIALOG_FORM::OnMenu()
{
	// TODO: �ڴ���������������
	CheckData();
}


void DIALOG_FORM::On32794()
{
	// TODO: �ڴ���������������
	//Dlg_Formula_Guide dlg;//��CDIALOG1����������һ����������Ϊdlg
	//dlg.DoModal();
	Dlg_Formula_Guide *pDlg = new Dlg_Formula_Guide;
	pDlg->Create(IDD_DLG_FORMULA_GUIDE, this);
	pDlg->ShowWindow(SW_SHOW);
}
