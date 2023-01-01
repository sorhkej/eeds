// DIALOG_CURR.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "DIALOG_CURR.h"
#include "afxdialogex.h"


// DIALOG_CURR �Ի���

IMPLEMENT_DYNAMIC(DIALOG_CURR, CDialogEx)

DIALOG_CURR::DIALOG_CURR(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CURR, pParent)
{

}

DIALOG_CURR::~DIALOG_CURR()
{
}

void DIALOG_CURR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FOR, m_list_for);
	DDX_Control(pDX, IDC_LIST_LIQU, m_list_liqu);
}


BEGIN_MESSAGE_MAP(DIALOG_CURR, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST_FOR, &DIALOG_CURR::OnNMClickListFor)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_FOR, &DIALOG_CURR::OnNMRClickListFor)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_FOR, &DIALOG_CURR::OnNMCustomdrawListFor)
END_MESSAGE_MAP()


// DIALOG_CURR ��Ϣ�������


BOOL DIALOG_CURR::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void DIALOG_CURR::OnNMClickListFor(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void DIALOG_CURR::OnNMRClickListFor(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void DIALOG_CURR::OnNMCustomdrawListFor(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	*pResult = 0;
}

_RecordsetPtr& DIALOG_CURR::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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

void DIALOG_CURR::CheckData()//�����ݿ���в�ѯ����
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

void DIALOG_CURR::SearchData()
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

void DIALOG_CURR::DeleteData()
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