// Dlg_Dilute_Solution.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Dilute_Solution.h"
#include "afxdialogex.h"


// Dlg_Dilute_Solution �Ի���

IMPLEMENT_DYNAMIC(Dlg_Dilute_Solution, CDialogEx)

Dlg_Dilute_Solution::Dlg_Dilute_Solution(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_DILUTE_SOLUTION, pParent)
{

}

Dlg_Dilute_Solution::~Dlg_Dilute_Solution()
{
}

void Dlg_Dilute_Solution::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CB_LIQUID, m_cb_liquid);
}


BEGIN_MESSAGE_MAP(Dlg_Dilute_Solution, CDialogEx)
	ON_CBN_SELCHANGE(IDC_CB_LIQUID, &Dlg_Dilute_Solution::OnCbnSelchangeCbLiquid)
END_MESSAGE_MAP()


// Dlg_Dilute_Solution ��Ϣ�������


void Dlg_Dilute_Solution::OnCbnSelchangeCbLiquid()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL Dlg_Dilute_Solution::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
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

	bottle = LiquidPosi;
	SearchData();

	liquid = m_pRecordset->GetCollect(_T("��Һ"));
	concentration = m_pRecordset->GetCollect(_T("Ũ��"));
	cs_concentration = m_pRecordset->GetCollect(_T("Ũ��"));

	SearchLiquid();

	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_cb_liquid.SetFont(&m_font);

	int pos= -1;
	while (m_pRecordset->adoEOF == 0)
	{
		CString s = m_pRecordset->GetCollect(_T("����"));
		CString t = m_pRecordset->GetCollect(_T("Ũ��"));
		float liquid_concentration = m_pRecordset->GetCollect(_T("Ũ��"));
		if (liquid_concentration > concentration)
		{
			s = s + _T(":") + t;
			m_cb_liquid.AddString(s);
			pos++;
		}
		m_pRecordset->MoveNext();
	}


	((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->SetCurSel(pos);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

_RecordsetPtr& Dlg_Dilute_Solution::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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

void Dlg_Dilute_Solution::SearchData()
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Search_Position";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_bottle;
		Param_bottle.CreateInstance("ADODB.Parameter");
		Param_bottle = m_pCommand->CreateParameter("@ƿ��", adVarWChar, adParamInput, 50, (_variant_t)bottle);
		m_pCommand->Parameters->Append(Param_bottle);

		m_pRecordset = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}

void Dlg_Dilute_Solution::SearchLiquid()
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Search_Liquid_Concentration";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_liquid;
		Param_liquid.CreateInstance("ADODB.Parameter");
		Param_liquid = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)liquid);
		m_pCommand->Parameters->Append(Param_liquid);

		m_pRecordset = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}