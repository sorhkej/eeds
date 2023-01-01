// Dlg_New.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_New.h"
#include "afxdialogex.h"


// Dlg_New 对话框
int formulaNum;
IMPLEMENT_DYNAMIC(Dlg_New, CDialog)

Dlg_New::Dlg_New(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_NEW, pParent)
{

}

Dlg_New::~Dlg_New()
{
}

void Dlg_New::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_COMBO_STUFF, m_cbb_stuff);
	DDX_Control(pDX, IDC_COMBO_FORM, m_cbb_form);
	//  DDX_Control(pDX, IDC_EDIT_ORDE, m_edit_orde);
	//  DDX_Control(pDX, IDC_EDIT_QUALITY, m_edit_qual);
	DDX_Control(pDX, IDC_LIST_NEW_FORM, m_list_form);
	DDX_Control(pDX, IDC_EDIT_WEIGHT, m_edit_wei);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_btn_save);
}


BEGIN_MESSAGE_MAP(Dlg_New, CDialog)
	ON_BN_CLICKED(IDC_BTN_GETFORM, &Dlg_New::OnBnClickedBtnGetform)
	ON_CBN_SELCHANGE(IDC_COMBO_FORM, &Dlg_New::OnCbnSelchangeComboForm)
//	ON_BN_CLICKED(IDC_BTN_ADD, &Dlg_New::OnBnClickedBtnAdd)
ON_BN_CLICKED(IDC_BUTTON_SAVE, &Dlg_New::OnBnClickedButtonSave)
END_MESSAGE_MAP()


// Dlg_New 消息处理程序


BOOL Dlg_New::OnInitDialog()
{
	CDialog::OnInitDialog();
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
	sql.Format(_T("select* from Formula order by 代码 desc"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);

	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_list_form.SetFont(&m_font);


	while (m_pRecordset->adoEOF == 0)
	{
		CString s = m_pRecordset->GetCollect(_T("代码"));
		CString t = m_pRecordset->GetCollect(_T("名称"));
		s = s + _T(":") + t;
		m_cbb_form.AddString(s);
		m_pRecordset->MoveNext();
	}

	
	m_cbb_form.SetFont(&m_font);
	m_edit_wei.SetFont(&m_font);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

_RecordsetPtr& Dlg_New::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
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

void Dlg_New::OnBnClickedBtnGetform()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString weight;
	//GetDlgItem(IDC_EDIT_WEIGHT)->GetWindowText(weight);
	//int weig = _ttoi(weight);
	CString str;
	GetDlgItem(IDC_COMBO_FORM)->GetWindowText(str);

	int length = str.Find(_T(":"));
	daima = str.Left(length);
	mingcheng = str.Right(str.GetLength() - length - 1);
	SearchData();

	m_list_form.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_form.DeleteColumn(0));	//清空所有表头
	m_list_form.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_list_form.SetFont(&m_font);

	m_list_form.InsertColumn(0, _T("化工料"), LVCFMT_LEFT, 200, 2);         //为列表加入四列：姓名，手机号码，关系，备注
	m_list_form.InsertColumn(1, _T("要求的量(g)"), LVCFMT_LEFT, 200, 2);
	m_list_form.InsertColumn(2, _T("序列"), LVCFMT_LEFT, 150, 2);
	m_list_form.InsertColumn(3, _T("配方代码"), LVCFMT_LEFT, 100, 2);
	m_list_form.InsertColumn(4, _T("配方名称"), LVCFMT_LEFT, 100, 2);
	m_list_form.InsertColumn(5, _T("配方重量"), LVCFMT_LEFT, 100, 2);
	m_list_form.InsertColumn(6, _T("配方单位"), LVCFMT_LEFT, 100, 2);

	int a = m_pRecordset->GetCollect(_T("序列"));
	GetDlgItem(IDC_EDIT_WEIGHT)->GetWindowText(zl);

	float weight = _ttof(zl);
	int i = 1;
	while (i <= a)
	{
		CString xl, nd, xh;
		xh.Format(_T("%d"), i);
		xl = _T("序列");
		nd = _T("浓度");
		xl = xl + xh;
		nd = nd + xh;
		m_list_form.InsertItem(i - 1, _T(""));
		m_list_form.SetItemText(i - 1, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_variant_t(xl)));
		m_list_form.SetItemText(i - 1,5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_variant_t(nd)));
		float nongdu = m_pRecordset->GetCollect(_variant_t(nd));
		CString yqdl;
		yqdl.Format(_T("%f"), nongdu*weight*0.01);
		m_list_form.SetItemText(i - 1, 1, yqdl);
		m_list_form.SetItemText(i - 1, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("代码")));
		m_list_form.SetItemText(i - 1, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("名称")));
		m_list_form.SetItemText(i - 1, 6, _T("%"));
		m_list_form.SetItemText(i - 1, 2, (LPCTSTR)(LPTSTR)(_bstr_t)i);
		i++;
	}

	//if (a >= 10)
	//{
	//	m_list_form.InsertItem(0, _T(""));
	//	m_list_form.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("序列10")));
	//	float nongdu = m_pRecordset->GetCollect(_T("浓度10"));
	//	CString yqdl;
	//	yqdl.Format(_T("%f"), nongdu*weig*0.01);
	//	m_list_form.SetItemText(0, 1, yqdl);
	//	m_list_form.SetItemText(0, 2, _T("10"));
	//	m_list_form.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("代码")));
	//	m_list_form.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("名称")));
	//	m_list_form.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("浓度10")));
	//	m_list_form.SetItemText(0, 2, _T("%"));
	//}
	

}


void Dlg_New::OnCbnSelchangeComboForm()
{
	// TODO: 在此添加控件通知处理程序代码
	int iPos;
	CString str;
	iPos = ((CComboBox*)GetDlgItem(IDC_COMBO_FORM))->GetCurSel();//当前选中的行。
	((CComboBox*)GetDlgItem(IDC_COMBO_FORM))->SetCurSel(iPos);//设置第n行内容为显示的内容。
	GetDlgItem(IDC_COMBO_FORM)->GetWindowText(str);

	int length = str.Find(_T(":"));
	//daima = str.Left(length);
	//mingcheng = str.Right(str.GetLength() - length - 1);
	GetDlgItem(IDC_EDIT_CODE)->SetWindowText(str.Left(length));
	GetDlgItem(IDC_EDIT_NAME)->SetWindowText(str.Right(str.GetLength() - length - 1));

}

void Dlg_New::SearchData()
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Search_Formula";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_daima;
		Param_daima.CreateInstance("ADODB.Parameter");
		Param_daima = m_pCommand->CreateParameter("@代码", adVarWChar, adParamInput, 50, (_variant_t)daima);
		m_pCommand->Parameters->Append(Param_daima);

		_ParameterPtr Param_mingcheng;
		Param_mingcheng.CreateInstance("ADODB.Parameter");
		Param_mingcheng = m_pCommand->CreateParameter("@名称", adVarWChar, adParamInput, 50, (_variant_t)mingcheng);
		m_pCommand->Parameters->Append(Param_mingcheng);

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

//void Dlg_New::OnBnClickedBtnAdd()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CString hgl, nongdu, xulie;
//	GetDlgItem(IDC_COMBO_LIQUID)->GetWindowText(hgl);
//	GetDlgItem(IDC_EDIT_POTENCY)->GetWindowText(nongdu);
//	GetDlgItem(IDC_EDIT_ORDER)->GetWindowText(xulie);
//}


void Dlg_New::OnBnClickedButtonSave()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT_CODE)->GetWindowText(dm);
	GetDlgItem(IDC_EDIT_NAME)->GetWindowText(mc);
	GetDlgItem(IDC_EDIT_REMARK)->GetWindowText(bz);
	GetDlgItem(IDC_EDIT_WEIGHT)->GetWindowText(zl);
	if (zl != _T(""))
	{
		SaveToDatabase();
	}
	formulaNum = 1;
	OnCancel();
}

void Dlg_New::SaveToDatabase()//将数据按照每一行单行写入数据库到时候调用此函数就好
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Add_Formula_Detailed";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_dm;
		Param_dm.CreateInstance("ADODB.Parameter");
		Param_dm = m_pCommand->CreateParameter("@代码", adVarWChar, adParamInput, 50, (_variant_t)dm);
		m_pCommand->Parameters->Append(Param_dm);

		_ParameterPtr Param_mc;
		Param_mc.CreateInstance("ADODB.Parameter");
		Param_mc = m_pCommand->CreateParameter("@名称", adVarWChar, adParamInput, 50, (_variant_t)mc);
		m_pCommand->Parameters->Append(Param_mc);

		_ParameterPtr Param_bz;
		Param_bz.CreateInstance("ADODB.Parameter");
		Param_bz = m_pCommand->CreateParameter("@备注", adVarWChar, adParamInput, 50, (_variant_t)bz);
		m_pCommand->Parameters->Append(Param_bz);

		_ParameterPtr Param_pswz;
		Param_pswz.CreateInstance("ADODB.Parameter");
		Param_pswz = m_pCommand->CreateParameter("@配送位置", adVarWChar, adParamInput, 50, (_variant_t)pswz);
		m_pCommand->Parameters->Append(Param_pswz);

		_ParameterPtr Param_zl;
		Param_zl.CreateInstance("ADODB.Parameter");
		Param_zl = m_pCommand->CreateParameter("@重量", adVarWChar, adParamInput, 50, (_variant_t)zl);
		m_pCommand->Parameters->Append(Param_zl);

		_ParameterPtr Param_rl;
		Param_rl.CreateInstance("ADODB.Parameter");
		Param_rl = m_pCommand->CreateParameter("@容量", adVarWChar, adParamInput, 50, (_variant_t)rl);
		m_pCommand->Parameters->Append(Param_rl);

		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}