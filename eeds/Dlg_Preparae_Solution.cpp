// Dlg_Preparae_Solution.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Preparae_Solution.h"
#include "afxdialogex.h"


// Dlg_Preparae_Solution �Ի���

IMPLEMENT_DYNAMIC(Dlg_Preparae_Solution, CDialogEx)

Dlg_Preparae_Solution::Dlg_Preparae_Solution(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_PREPARAE_SOLUTION, pParent)
{

}

Dlg_Preparae_Solution::~Dlg_Preparae_Solution()
{
}

void Dlg_Preparae_Solution::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CURRENT_WEIGHT, m_edit_current_weight);
	DDX_Control(pDX, IDC_EDIT_LIQUID, m_edit_liquid);
}


BEGIN_MESSAGE_MAP(Dlg_Preparae_Solution, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_BEGIN, &Dlg_Preparae_Solution::OnBnClickedBtnBegin)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK, &Dlg_Preparae_Solution::OnBnClickedOk)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Dlg_Preparae_Solution ��Ϣ�������


BOOL Dlg_Preparae_Solution::OnInitDialog()
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

	

	//liquid = m_pRecordset->GetCollect(_T("��Һ"));
	//concentration = m_pRecordset->GetCollect(_T("Ũ��"));


	int length = LiquidName.Find(_T(":"));
	liquid = LiquidName.Left(length);
	CString cs_concentration = LiquidName.Right(LiquidName.GetLength() - length - 1);
	concentration = _ttof(cs_concentration);

	//CString t = m_pRecordset->GetCollect(_T("Ũ��"));
	//t = liquid + _T(":") + t;
	GetDlgItem(IDC_EDIT_LIQUID)->SetWindowText(LiquidName);

	max_concentration = concentration * 0.9;
	min_concentration = concentration * 0.7;
	target_concentration = concentration * 0.8;
	
	target_weight.Format(_T("%f"), target_concentration);
	GetDlgItem(IDC_EDIT_WEIGHT)->SetWindowText(target_weight);






	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_edit_liquid.SetFont(&m_font);





	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void Dlg_Preparae_Solution::OnBnClickedBtnBegin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetTimer(1, 100, NULL);

}


void Dlg_Preparae_Solution::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	switch (nIDEvent)
	{
	case 1:
		current_weight.Format(_T("%d"), currentweight);
		GetDlgItem(IDC_EDIT_CURRENT_WEIGHT)->SetWindowText(current_weight);
		break;
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void Dlg_Preparae_Solution::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	

	CString rj;
	GetDlgItem(IDC_EDIT_CURRENT_WEIGHT)->GetWindowText(rj);
	target_concentration = _ttof(rj);
	if(target_concentration<= max_concentration && target_concentration >= min_concentration)
	{
		KillTimer(1);//ͨ����ʱ������ˢ����ƽ�������رն�ʱ��

	concentration = (target_concentration / concentration) * 1000;//ʵ���ݻ�

	actual_volume.Format(_T("%f"), concentration);
	volume = actual_volume;
	bottle = LiquidPosi;

	CString temp;
	GetDlgItem(IDC_EDIT_LIQUID)->GetWindowText(temp);

	int length = temp.Find(_T(":"));
	liquid = temp.Left(length);
	cs_concentration = temp.Right(temp.GetLength() - length - 1);

	SearchLiquid();
	int over_time = m_pRecordset->GetCollect(_T("��ú���ֹ"));
	min_weighing = m_pRecordset->GetCollect(_T("��С������"));
	min_volume = m_pRecordset->GetCollect(_T("��С�ݻ�"));
	max_volume = m_pRecordset->GetCollect(_T("����ݻ�"));

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
		MessageBox(_T("���������������"));
	}
}

_RecordsetPtr& Dlg_Preparae_Solution::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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

void Dlg_Preparae_Solution::SearchData()
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

void Dlg_Preparae_Solution::SearchLiquid()
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

		_ParameterPtr Param_cs_concentration;
		Param_cs_concentration.CreateInstance("ADODB.Parameter");
		Param_cs_concentration = m_pCommand->CreateParameter("@Ũ��", adVarWChar, adParamInput, 50, (_variant_t)cs_concentration);
		m_pCommand->Parameters->Append(Param_cs_concentration);

		m_pRecordset = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}

HBRUSH Dlg_Preparae_Solution::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// ����������ʱ��Ϊ��ɫ
	if (pWnd == &m_edit_current_weight && colornum ==1)
	{
		pDC->SetTextColor(RGB(255, 255, 0));
	}
	//����������ʱ��Ϊ��ɫ
	if (pWnd == &m_edit_current_weight && colornum == 2)
	{
		pDC->SetTextColor(RGB(128, 255, 0));
	}
	//����������ʱ��Ϊ��ɫ
	if (pWnd == &m_edit_current_weight && colornum == 3)
	{
		pDC->SetTextColor(RGB(255, 0, 0));
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

void Dlg_Preparae_Solution::AddData()
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
