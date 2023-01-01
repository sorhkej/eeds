// Dlg_Preparae_Solution.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Preparae_Solution.h"
#include "afxdialogex.h"


// Dlg_Preparae_Solution 对话框

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


// Dlg_Preparae_Solution 消息处理程序


BOOL Dlg_Preparae_Solution::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CoInitialize(NULL);
	m_pConnection.CreateInstance(__uuidof(Connection));
	try
	{
		m_pConnection->Open("driver={SQL Server};Server=127.0.0.1;Database=Eeds;UID=sa;PWD=123456", "", "", adModeUnknown);
	}
	catch (_com_error e)//捕捉异常
	{
		CString errormessage;
		errormessage.Format(_T("连接数据库失败！错误信息：%s"), e.ErrorMessage());
		AfxMessageBox(errormessage);//显示错误信息 
	}

	

	//liquid = m_pRecordset->GetCollect(_T("溶液"));
	//concentration = m_pRecordset->GetCollect(_T("浓度"));


	int length = LiquidName.Find(_T(":"));
	liquid = LiquidName.Left(length);
	CString cs_concentration = LiquidName.Right(LiquidName.GetLength() - length - 1);
	concentration = _ttof(cs_concentration);

	//CString t = m_pRecordset->GetCollect(_T("浓度"));
	//t = liquid + _T(":") + t;
	GetDlgItem(IDC_EDIT_LIQUID)->SetWindowText(LiquidName);

	max_concentration = concentration * 0.9;
	min_concentration = concentration * 0.7;
	target_concentration = concentration * 0.8;
	
	target_weight.Format(_T("%f"), target_concentration);
	GetDlgItem(IDC_EDIT_WEIGHT)->SetWindowText(target_weight);






	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_edit_liquid.SetFont(&m_font);





	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Dlg_Preparae_Solution::OnBnClickedBtnBegin()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(1, 100, NULL);

}


void Dlg_Preparae_Solution::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
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
	// TODO: 在此添加控件通知处理程序代码
	

	CString rj;
	GetDlgItem(IDC_EDIT_CURRENT_WEIGHT)->GetWindowText(rj);
	target_concentration = _ttof(rj);
	if(target_concentration<= max_concentration && target_concentration >= min_concentration)
	{
		KillTimer(1);//通过定时器不断刷新天平读数，关闭定时器

	concentration = (target_concentration / concentration) * 1000;//实际容积

	actual_volume.Format(_T("%f"), concentration);
	volume = actual_volume;
	bottle = LiquidPosi;

	CString temp;
	GetDlgItem(IDC_EDIT_LIQUID)->GetWindowText(temp);

	int length = temp.Find(_T(":"));
	liquid = temp.Left(length);
	cs_concentration = temp.Right(temp.GetLength() - length - 1);

	SearchLiquid();
	int over_time = m_pRecordset->GetCollect(_T("多久后终止"));
	min_weighing = m_pRecordset->GetCollect(_T("最小配送量"));
	min_volume = m_pRecordset->GetCollect(_T("最小容积"));
	max_volume = m_pRecordset->GetCollect(_T("最大容积"));

	CString strTime;
	CTime tm;
	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	tm = CTime::GetCurrentTime();
	CTimeSpan timeSpan(0, over_time, 0, 0);
	tm += timeSpan;
	strTime = tm.Format("%y年%m月%d日 %X");

	endtime = strTime;
	AddData();


	CDialogEx::OnOK();
	}
	else
	{
		MessageBox(_T("请加入适量化工料"));
	}
}

_RecordsetPtr& Dlg_Preparae_Solution::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
{
	try
	{
		//创建记录集对象
		m_pRecordset.CreateInstance(__uuidof(Recordset));

		//取得表中的记录
		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(),
			adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch (_com_error e)
	{
		e.Description();
	}
	//返回记录集
	return m_pRecordset;
}

void Dlg_Preparae_Solution::SearchData()
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Search_Position";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_bottle;
		Param_bottle.CreateInstance("ADODB.Parameter");
		Param_bottle = m_pCommand->CreateParameter("@瓶子", adVarWChar, adParamInput, 50, (_variant_t)bottle);
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
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Search_Liquid";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_liquid;
		Param_liquid.CreateInstance("ADODB.Parameter");
		Param_liquid = m_pCommand->CreateParameter("@名称", adVarWChar, adParamInput, 50, (_variant_t)liquid);
		m_pCommand->Parameters->Append(Param_liquid);

		_ParameterPtr Param_cs_concentration;
		Param_cs_concentration.CreateInstance("ADODB.Parameter");
		Param_cs_concentration = m_pCommand->CreateParameter("@浓度", adVarWChar, adParamInput, 50, (_variant_t)cs_concentration);
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

	// 当重量不足时设为黄色
	if (pWnd == &m_edit_current_weight && colornum ==1)
	{
		pDC->SetTextColor(RGB(255, 255, 0));
	}
	//当重量合适时设为绿色
	if (pWnd == &m_edit_current_weight && colornum == 2)
	{
		pDC->SetTextColor(RGB(128, 255, 0));
	}
	//当重量过大时设为红色
	if (pWnd == &m_edit_current_weight && colornum == 3)
	{
		pDC->SetTextColor(RGB(255, 0, 0));
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void Dlg_Preparae_Solution::AddData()
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Add_Position";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_bottle;
		Param_bottle.CreateInstance("ADODB.Parameter");
		Param_bottle = m_pCommand->CreateParameter("@瓶子", adVarWChar, adParamInput, 50, (_variant_t)bottle);
		m_pCommand->Parameters->Append(Param_bottle);

		_ParameterPtr Param_liquid;
		Param_liquid.CreateInstance("ADODB.Parameter");
		Param_liquid = m_pCommand->CreateParameter("@溶液", adVarWChar, adParamInput, 50, (_variant_t)liquid);
		m_pCommand->Parameters->Append(Param_liquid);

		_ParameterPtr Param_cs_concentration;
		Param_cs_concentration.CreateInstance("ADODB.Parameter");
		Param_cs_concentration = m_pCommand->CreateParameter("@浓度", adVarWChar, adParamInput, 50, (_variant_t)cs_concentration);
		m_pCommand->Parameters->Append(Param_cs_concentration);

		_ParameterPtr Param_volume;
		Param_volume.CreateInstance("ADODB.Parameter");
		Param_volume = m_pCommand->CreateParameter("@容积", adVarWChar, adParamInput, 50, (_variant_t)volume);
		m_pCommand->Parameters->Append(Param_volume);

		_ParameterPtr Param_endtime;
		Param_endtime.CreateInstance("ADODB.Parameter");
		Param_endtime = m_pCommand->CreateParameter("@终止时间", adVarWChar, adParamInput, 50, (_variant_t)endtime);
		m_pCommand->Parameters->Append(Param_endtime);

		_ParameterPtr Param_min_weighing;
		Param_min_weighing.CreateInstance("ADODB.Parameter");
		Param_min_weighing = m_pCommand->CreateParameter("@最小称重量", adVarWChar, adParamInput, 50, (_variant_t)min_weighing);
		m_pCommand->Parameters->Append(Param_min_weighing);

		_ParameterPtr Param_min_volume;
		Param_min_volume.CreateInstance("ADODB.Parameter");
		Param_min_volume = m_pCommand->CreateParameter("@最小容积", adVarWChar, adParamInput, 50, (_variant_t)min_volume);
		m_pCommand->Parameters->Append(Param_min_volume);

		_ParameterPtr Param_max_volume;
		Param_max_volume.CreateInstance("ADODB.Parameter");
		Param_max_volume = m_pCommand->CreateParameter("@最大容积", adVarWChar, adParamInput, 50, (_variant_t)max_volume);
		m_pCommand->Parameters->Append(Param_max_volume);

		_ParameterPtr Param_actual_volume;
		Param_actual_volume.CreateInstance("ADODB.Parameter");
		Param_actual_volume = m_pCommand->CreateParameter("@实际容积", adVarWChar, adParamInput, 50, (_variant_t)actual_volume);
		m_pCommand->Parameters->Append(Param_actual_volume);

		
		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}
