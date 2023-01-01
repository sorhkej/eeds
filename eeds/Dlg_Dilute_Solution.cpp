// Dlg_Dilute_Solution.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Dilute_Solution.h"
#include "afxdialogex.h"


// Dlg_Dilute_Solution 对话框

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


// Dlg_Dilute_Solution 消息处理程序


void Dlg_Dilute_Solution::OnCbnSelchangeCbLiquid()
{
	// TODO: 在此添加控件通知处理程序代码
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
	catch (_com_error e)//捕捉异常
	{
		CString errormessage;
		errormessage.Format(_T("连接数据库失败！错误信息：%s"), e.ErrorMessage());
		AfxMessageBox(errormessage);//显示错误信息 
	}

	bottle = LiquidPosi;
	SearchData();

	liquid = m_pRecordset->GetCollect(_T("溶液"));
	concentration = m_pRecordset->GetCollect(_T("浓度"));
	cs_concentration = m_pRecordset->GetCollect(_T("浓度"));

	SearchLiquid();

	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_cb_liquid.SetFont(&m_font);

	int pos= -1;
	while (m_pRecordset->adoEOF == 0)
	{
		CString s = m_pRecordset->GetCollect(_T("名称"));
		CString t = m_pRecordset->GetCollect(_T("浓度"));
		float liquid_concentration = m_pRecordset->GetCollect(_T("浓度"));
		if (liquid_concentration > concentration)
		{
			s = s + _T(":") + t;
			m_cb_liquid.AddString(s);
			pos++;
		}
		m_pRecordset->MoveNext();
	}


	((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->SetCurSel(pos);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

_RecordsetPtr& Dlg_Dilute_Solution::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
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

void Dlg_Dilute_Solution::SearchData()
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

void Dlg_Dilute_Solution::SearchLiquid()
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Search_Liquid_Concentration";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_liquid;
		Param_liquid.CreateInstance("ADODB.Parameter");
		Param_liquid = m_pCommand->CreateParameter("@名称", adVarWChar, adParamInput, 50, (_variant_t)liquid);
		m_pCommand->Parameters->Append(Param_liquid);

		m_pRecordset = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}