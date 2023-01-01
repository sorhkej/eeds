// Dlg_Place_Bottle.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Place_Bottle.h"
#include "afxdialogex.h"


// Dlg_Place_Bottle 对话框

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


// Dlg_Place_Bottle 消息处理程序


void Dlg_Place_Bottle::OnCbnSelchangeCbLiquid()
{
	// TODO: 在此添加控件通知处理程序代码
	int iPos;
	iPos = ((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->GetCurSel();//当前选中的行。
	((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->SetCurSel(iPos);//设置第n行内容为显示的内容。
}


void Dlg_Place_Bottle::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
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

			int over_time = m_pRecordset->GetCollect(_T("多久后终止"));
			min_weighing = m_pRecordset->GetCollect(_T("最小配送量"));
			min_volume = m_pRecordset->GetCollect(_T("最小容积"));
			max_volume = m_pRecordset->GetCollect(_T("最大容积"));
			actual_volume = cs_volume;


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
			MessageBox(_T("请输入合适的毫升数（大于200且小于900）"));
		}
	}
	else
	{
		MessageBox(_T("请选择溶液"));
	}

}


BOOL Dlg_Place_Bottle::OnInitDialog()
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
	CString sql;
	sql.Format(_T("select* from Liquid order by 名称 desc"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);

	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_cb_liquid.SetFont(&m_font);

	while (m_pRecordset->adoEOF == 0)
	{
		CString s = m_pRecordset->GetCollect(_T("名称"));
		CString t = m_pRecordset->GetCollect(_T("浓度"));
		s = s + _T(":") + t;
		m_cb_liquid.AddString(s);
		m_pRecordset->MoveNext();
	}

	bottle = LiquidPosi;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

_RecordsetPtr& Dlg_Place_Bottle::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
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

void Dlg_Place_Bottle::SearchLiquid()
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

		_ParameterPtr Param_concentration;
		Param_concentration.CreateInstance("ADODB.Parameter");
		Param_concentration = m_pCommand->CreateParameter("@浓度", adVarWChar, adParamInput, 50, (_variant_t)concentration);
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

		_ParameterPtr Param_concentration;
		Param_concentration.CreateInstance("ADODB.Parameter");
		Param_concentration = m_pCommand->CreateParameter("@浓度", adVarWChar, adParamInput, 50, (_variant_t)concentration);
		m_pCommand->Parameters->Append(Param_concentration);

		_ParameterPtr Param_cs_volume;
		Param_cs_volume.CreateInstance("ADODB.Parameter");
		Param_cs_volume = m_pCommand->CreateParameter("@容积", adVarWChar, adParamInput, 50, (_variant_t)cs_volume);
		m_pCommand->Parameters->Append(Param_cs_volume);

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