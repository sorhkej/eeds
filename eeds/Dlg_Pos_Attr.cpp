// Dlg_Pos_Attr.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Pos_Attr.h"
#include "afxdialogex.h"


// Dlg_Pos_Attr �Ի���
extern CString LiquidPosi, LiquPos, LiquVol, MaxVol, MinVol, OverTim;
IMPLEMENT_DYNAMIC(Dlg_Pos_Attr, CDialog)

Dlg_Pos_Attr::Dlg_Pos_Attr(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_POSATTR, pParent)
{

}

Dlg_Pos_Attr::~Dlg_Pos_Attr()
{
}

void Dlg_Pos_Attr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LIQUATTR, m_edit_liquattr);
	DDX_Control(pDX, IDC_COMBO_LIQU, m_cb_liqu);
	DDX_Control(pDX, IDC_EDIT_VOLUME, m_edit_volume);
	DDX_Control(pDX, IDC_EDIT_MAX_VOLUME, m_edit_max);
	DDX_Control(pDX, IDC_EDIT_MIN_VOLUME, m_edit_min);
	DDX_Control(pDX, IDC_EDIT_LIQU_OVER, m_edit_overdue);
}


BEGIN_MESSAGE_MAP(Dlg_Pos_Attr, CDialog)
	ON_BN_CLICKED(IDOK, &Dlg_Pos_Attr::OnBnClickedOk)
END_MESSAGE_MAP()


// Dlg_Pos_Attr ��Ϣ�������


BOOL Dlg_Pos_Attr::OnInitDialog()
{
	CDialog::OnInitDialog();


	this->SetWindowText(LiquidPosi);
	m_edit_liquattr.SetWindowTextW(LiquidPosi);
	m_edit_volume.SetWindowTextW(LiquVol);
	m_edit_max.SetWindowTextW(MaxVol);
	m_edit_min.SetWindowTextW(MinVol);
	m_edit_overdue.SetWindowTextW(OverTim);

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
	cs_concentration = m_pRecordset->GetCollect(_T("Ũ��"));

	
	CString sql;
	sql.Format(_T("select* from Liquid order by ���� desc, Ũ�� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);

	int i = 0, cbnum = -1;
	while (m_pRecordset->adoEOF == 0)
	{
		CString s = m_pRecordset->GetCollect(_T("����"));
		CString t = m_pRecordset->GetCollect(_T("Ũ��"));
		if (s == liquid && t == cs_concentration)
		{
			cbnum = i;
		}
		s = s + _T(":") + t;
		m_cb_liqu.AddString(s);
		m_pRecordset->MoveNext();
		i++;
	}
	if (cbnum != -1)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_LIQU))->SetCurSel(i - 1 - cbnum);

	}

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

_RecordsetPtr& Dlg_Pos_Attr::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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


void Dlg_Pos_Attr::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString temp;
	GetDlgItem(IDC_COMBO_LIQU)->GetWindowText(temp);

	int length = temp.Find(_T(":"));
	liquid = temp.Left(length);
	cs_concentration = temp.Right(temp.GetLength() - length - 1);

	
	volume = endtime = min_weighing = min_volume = max_volume = actual_volume = _T("");
	AddData();

	CDialog::OnOK();
}

void Dlg_Pos_Attr::AddData()
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

		_ParameterPtr Param_liquid;
		Param_liquid.CreateInstance("ADODB.Parameter");
		Param_liquid = m_pCommand->CreateParameter("@��Һ", adVarWChar, adParamInput, 50, (_variant_t)liquid);
		m_pCommand->Parameters->Append(Param_liquid);

		_ParameterPtr Param_cs_concentration;
		Param_cs_concentration.CreateInstance("ADODB.Parameter");
		Param_cs_concentration = m_pCommand->CreateParameter("@Ũ��", adVarWChar, adParamInput, 50, (_variant_t)cs_concentration);
		m_pCommand->Parameters->Append(Param_cs_concentration);

		_ParameterPtr Param_volume;
		Param_volume.CreateInstance("ADODB.Parameter");
		Param_volume = m_pCommand->CreateParameter("@�ݻ�", adVarWChar, adParamInput, 50, (_variant_t)volume);
		m_pCommand->Parameters->Append(Param_volume);

		_ParameterPtr Param_endtime;
		Param_endtime.CreateInstance("ADODB.Parameter");
		Param_endtime = m_pCommand->CreateParameter("@��ֹʱ��", adVarWChar, adParamInput, 50, (_variant_t)endtime);
		m_pCommand->Parameters->Append(Param_endtime);

		_ParameterPtr Param_min_weighing;
		Param_min_weighing.CreateInstance("ADODB.Parameter");
		Param_min_weighing = m_pCommand->CreateParameter("@��С������", adVarWChar, adParamInput, 50, (_variant_t)min_weighing);
		m_pCommand->Parameters->Append(Param_min_weighing);

		_ParameterPtr Param_min_volume;
		Param_min_volume.CreateInstance("ADODB.Parameter");
		Param_min_volume = m_pCommand->CreateParameter("@��С�ݻ�", adVarWChar, adParamInput, 50, (_variant_t)min_volume);
		m_pCommand->Parameters->Append(Param_min_volume);

		_ParameterPtr Param_max_volume;
		Param_max_volume.CreateInstance("ADODB.Parameter");
		Param_max_volume = m_pCommand->CreateParameter("@����ݻ�", adVarWChar, adParamInput, 50, (_variant_t)max_volume);
		m_pCommand->Parameters->Append(Param_max_volume);

		_ParameterPtr Param_actual_volume;
		Param_actual_volume.CreateInstance("ADODB.Parameter");
		Param_actual_volume = m_pCommand->CreateParameter("@ʵ���ݻ�", adVarWChar, adParamInput, 50, (_variant_t)actual_volume);
		m_pCommand->Parameters->Append(Param_actual_volume);


		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}

void Dlg_Pos_Attr::SearchData()
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

		m_pRecordset	 =	m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}