// Dlg_Place_Bottle.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Place_Bottle.h"
#include "afxdialogex.h"


// Dlg_Place_Bottle �Ի���

IMPLEMENT_DYNAMIC(Dlg_Place_Bottle, CDialogEx)

Dlg_Place_Bottle::Dlg_Place_Bottle(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_PLACE_BOTTLE, pParent)
{

}

Dlg_Place_Bottle::~Dlg_Place_Bottle()
{
}

void Dlg_Place_Bottle::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CB_LIQUID, m_cb_liquid);
	DDX_Control(pDX, IDC_EDIT_VOLUME, m_edit_volume);
}


BEGIN_MESSAGE_MAP(Dlg_Place_Bottle, CDialogEx)
	ON_CBN_SELCHANGE(IDC_CB_LIQUID, &Dlg_Place_Bottle::OnCbnSelchangeCbLiquid)
	ON_BN_CLICKED(IDOK, &Dlg_Place_Bottle::OnBnClickedOk)
END_MESSAGE_MAP()


// Dlg_Place_Bottle ��Ϣ�������


void Dlg_Place_Bottle::OnCbnSelchangeCbLiquid()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int iPos;
	iPos = ((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->GetCurSel();//��ǰѡ�е��С�
	((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->SetCurSel(iPos);//���õ�n������Ϊ��ʾ�����ݡ�
}


void Dlg_Place_Bottle::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	GetDlgItem(IDC_EDIT_VOLUME)->GetWindowText(cs_volume);
	volume = _ttof(cs_volume);

	CString temp;
	GetDlgItem(IDC_CB_LIQUID)->GetWindowText(temp);
	int length = temp.Find(_T(":"));
	liquid = temp.Left(length);
	concentration = temp.Right(temp.GetLength() - length - 1);

	if (temp != _T(""))
	{
		if (volume >= 200 && volume <= 900)
		{
			SearchLiquid();

			int over_time = m_pRecordset->GetCollect(_T("��ú���ֹ"));
			min_weighing = m_pRecordset->GetCollect(_T("��С������"));
			min_volume = m_pRecordset->GetCollect(_T("��С�ݻ�"));
			max_volume = m_pRecordset->GetCollect(_T("����ݻ�"));
			actual_volume = cs_volume;


			CString strTime;
			CTime tm;
			SYSTEMTIME sysTime;
			GetLocalTime(&sysTime);
			tm = CTime::GetCurrentTime();
			CTimeSpan timeSpan(0, over_time, 0, 0);
			tm += timeSpan;
			strTime = tm.Format("%y��%m��%d�� %X");

			endtime = strTime;
			AddData();

			CDialogEx::OnOK();
		}
		else
		{
			MessageBox(_T("��������ʵĺ�����������200��С��900��"));
		}
	}
	else
	{
		MessageBox(_T("��ѡ����Һ"));
	}

}


BOOL Dlg_Place_Bottle::OnInitDialog()
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
	CString sql;
	sql.Format(_T("select* from Liquid order by ���� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);

	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_cb_liquid.SetFont(&m_font);

	while (m_pRecordset->adoEOF == 0)
	{
		CString s = m_pRecordset->GetCollect(_T("����"));
		CString t = m_pRecordset->GetCollect(_T("Ũ��"));
		s = s + _T(":") + t;
		m_cb_liquid.AddString(s);
		m_pRecordset->MoveNext();
	}

	bottle = LiquidPosi;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

_RecordsetPtr& Dlg_Place_Bottle::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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

void Dlg_Place_Bottle::SearchLiquid()
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Search_Liquid";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_liquid;
		Param_liquid.CreateInstance("ADODB.Parameter");
		Param_liquid = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)liquid);
		m_pCommand->Parameters->Append(Param_liquid);

		_ParameterPtr Param_concentration;
		Param_concentration.CreateInstance("ADODB.Parameter");
		Param_concentration = m_pCommand->CreateParameter("@Ũ��", adVarWChar, adParamInput, 50, (_variant_t)concentration);
		m_pCommand->Parameters->Append(Param_concentration);

		m_pRecordset = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}

void Dlg_Place_Bottle::AddData()
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

		_ParameterPtr Param_concentration;
		Param_concentration.CreateInstance("ADODB.Parameter");
		Param_concentration = m_pCommand->CreateParameter("@Ũ��", adVarWChar, adParamInput, 50, (_variant_t)concentration);
		m_pCommand->Parameters->Append(Param_concentration);

		_ParameterPtr Param_cs_volume;
		Param_cs_volume.CreateInstance("ADODB.Parameter");
		Param_cs_volume = m_pCommand->CreateParameter("@�ݻ�", adVarWChar, adParamInput, 50, (_variant_t)cs_volume);
		m_pCommand->Parameters->Append(Param_cs_volume);

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