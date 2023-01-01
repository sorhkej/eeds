// Dlg_Compound_Liquid.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Compound_Liquid.h"
#include "afxdialogex.h"
#include"Dlg_Dilute_Solution.h"
#include"Dlg_Preparae_Solution.h"


// Dlg_Compound_Liquid 对话框

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


// Dlg_Compound_Liquid 消息处理程序


void Dlg_Compound_Liquid::OnBnClickedBtnMix()
{
	// TODO: 在此添加控件通知处理程序代码
	
	((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->GetWindowText(LiquidName);
	if (LiquidName == _T(""))
	{
		MessageBox(_T("请选择溶液后操作"));
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
	// TODO: 在此添加控件通知处理程序代码
	((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->GetWindowText(LiquidName);

	if (LiquidName == _T(""))
	{
		MessageBox(_T("请选择溶液后操作"));
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
	// TODO: 在此添加控件通知处理程序代码
	int iPos;
	iPos = ((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->GetCurSel();//当前选中的行。
	((CComboBox*)GetDlgItem(IDC_CB_LIQUID))->SetCurSel(iPos);//设置第n行内容为显示的内容。

}


BOOL Dlg_Compound_Liquid::OnInitDialog()
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

	bottle = LiquidPosi;
	SearchData();
	liquid = m_pRecordset->GetCollect(_T("溶液"));
	concentration = m_pRecordset->GetCollect(_T("浓度"));


	CString sql;
	sql.Format(_T("select* from Liquid order by 名称 desc, 浓度 desc"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);

	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_cb_liquid.SetFont(&m_font);
	int i = 0,cbnum=-1;
	while (m_pRecordset->adoEOF == 0)
	{
		CString s = m_pRecordset->GetCollect(_T("名称"));
		CString t = m_pRecordset->GetCollect(_T("浓度"));
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
				  // 异常: OCX 属性页应返回 FALSE
}

_RecordsetPtr& Dlg_Compound_Liquid::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
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

void Dlg_Compound_Liquid::SearchData()
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
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Add_Position";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_bottle;
		Param_bottle.CreateInstance("ADODB.Parameter");
		Param_bottle = m_pCommand->CreateParameter("@瓶子", adVarWChar, adParamInput, 50, (_variant_t)bottle);
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