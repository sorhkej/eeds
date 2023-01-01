// Dlg_Compound_Liquid.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Compound_Liquid.h"
#include "afxdialogex.h"
#include"Dlg_Dilute_Solution.h"
#include"Dlg_Preparae_Solution.h"


// Dlg_Compound_Liquid �Ի���

IMPLEMENT_DYNAMIC(Dlg_Compound_Liquid, CDialogEx)
CString LiquidName;
Dlg_Compound_Liquid::Dlg_Compound_Liquid(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_COMPOUND_LIQUID, pParent)
{

}

Dlg_Compound_Liquid::~Dlg_Compound_Liquid()
{
}

void Dlg_Compound_Liquid::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CB_LIQUID, m_cb_liquid);
}


BEGIN_MESSAGE_MAP(Dlg_Compound_Liquid, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_MIX, &Dlg_Compound_Liquid::OnBnClickedBtnMix)
	ON_BN_CLICKED(IDC_BTN_DILUTE, &Dlg_Compound_Liquid::OnBnClickedBtnDilute)
	ON_CBN_SELCHANGE(IDC_CB_LIQUID, &Dlg_Compound_Liquid::OnCbnSelchangeCbLiquid)
END_MESSAGE_MAP()


// Dlg_Compound_Liquid ��Ϣ�������


void Dlg_Compound_Liquid::OnBnClickedBtnMix()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->GetWindowText(LiquidName);
	if (LiquidName == _T(""))
	{
		MessageBox(_T("��ѡ����Һ�����"));
	}
	else
	{
	Dlg_Preparae_Solution *pDlg = new Dlg_Preparae_Solution;
	pDlg->Create(IDD_DLG_PREPARAE_SOLUTION, this);
	pDlg->ShowWindow(SW_SHOW);
	}
	CDialogEx::OnOK();
}


void Dlg_Compound_Liquid::OnBnClickedBtnDilute()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->GetWindowText(LiquidName);

	if (LiquidName == _T(""))
	{
		MessageBox(_T("��ѡ����Һ�����"));
	}
	else
	{
	Dlg_Dilute_Solution *pDlg = new Dlg_Dilute_Solution;
	pDlg->Create(IDD_DLG_DILUTE_SOLUTION, this);
	pDlg->ShowWindow(SW_SHOW);
	}
	CDialogEx::OnOK();
}


void Dlg_Compound_Liquid::OnCbnSelchangeCbLiquid()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int iPos;
	iPos = ((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->GetCurSel();//��ǰѡ�е��С�
	((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->SetCurSel(iPos);//���õ�n������Ϊ��ʾ�����ݡ�

}


BOOL Dlg_Compound_Liquid::OnInitDialog()
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

	bottle = LiquidPosi;
	SearchData();
	liquid = m_pRecordset->GetCollect(_T("��Һ"));
	concentration = m_pRecordset->GetCollect(_T("Ũ��"));


	CString sql;
	sql.Format(_T("select* from Liquid order by ���� desc, Ũ�� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);

	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_cb_liquid.SetFont(&m_font);
	int i = 0,cbnum=-1;
	while (m_pRecordset->adoEOF == 0)
	{
		CString s = m_pRecordset->GetCollect(_T("����"));
		CString t = m_pRecordset->GetCollect(_T("Ũ��"));
		if (s == liquid && t == concentration)
		{
			cbnum = i;
		}
		s = s + _T(":") + t;
		m_cb_liquid.AddString(s);
		m_pRecordset->MoveNext();
		i++;
	}
	if (cbnum != -1)
	{
		((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->SetCurSel(i -1- cbnum);
		//((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->SetCurSel(3);
	}


	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

_RecordsetPtr& Dlg_Compound_Liquid::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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

void Dlg_Compound_Liquid::SearchData()
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
		/*	m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(),
		adOpenDynamic, adLockOptimistic, adCmdText);*/
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}

void Dlg_Compound_Liquid::AddData()
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Add_Position";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_bottle;
		Param_bottle.CreateInstance("ADODB.Parameter");
		Param_bottle = m_pCommand->CreateParameter("@ƿ��", adVarWChar, adParamInput, 50, (_variant_t)bottle);
		m_pCommand->Parameters->Append(Param_bottle);

		m_pRecordset = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
		/*	m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(),
		adOpenDynamic, adLockOptimistic, adCmdText);*/
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}