// Dlg_Formula.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Formula.h"
#include "afxdialogex.h"

#define IDC_EDIT_CREATEID  3033//用于定义List 
#define IDC_COMBOX_CREATEID  3044//用于下拉列表
// Dlg_Formula 对话框

IMPLEMENT_DYNAMIC(Dlg_Formula, CDialogEx)

Dlg_Formula::Dlg_Formula(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_FORMULA, pParent)
{

}

Dlg_Formula::~Dlg_Formula()
{
}

void Dlg_Formula::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FORMULA, m_list_form);
	DDX_Control(pDX, IDC_COMBO_LIQUID, m_cb_liqu);
	DDX_Control(pDX, IDC_LIST_ORDER, m_list_orde);
	DDX_Control(pDX, IDC_EDIT_POTENCY, m_edit_pote);
	DDX_Control(pDX, IDC_COMBO_UNIT, m_cb_unit);
	DDX_Control(pDX, IDC_EDIT_ORDER, m_edit_orde);
}


BEGIN_MESSAGE_MAP(Dlg_Formula, CDialogEx)
	ON_BN_CLICKED(IDOK, &Dlg_Formula::OnBnClickedOk)
	ON_COMMAND(TB_STUFF_DELETE, &Dlg_Formula::OnTbFormulaDelete)
	ON_COMMAND(TB_STUFF_REFRESH, &Dlg_Formula::OnTbFormulaRefresh)
	ON_COMMAND(TB_STUFF_SAVE, &Dlg_Formula::OnTbFormulaSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST_FORMULA, &Dlg_Formula::OnNMClickListFormula)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_FORMULA, &Dlg_Formula::OnNMCustomdrawListFormula)
	ON_CBN_SELCHANGE(IDC_COMBO_LIQUID, &Dlg_Formula::OnCbnSelchangeComboLiquid)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_FORMULA, &Dlg_Formula::OnNMDblclkListFormula)
	ON_BN_CLICKED(IDC_BTN_FORM_ADD, &Dlg_Formula::OnBnClickedBtnFormAdd)
	ON_COMMAND(TB_STUFF_NEW, &Dlg_Formula::OnTbFormulaNew)
	ON_EN_CHANGE(IDC_EDIT_POTENCY, &Dlg_Formula::OnEnChangeEditPotency)
	ON_BN_CLICKED(IDC_BTN_DELETE, &Dlg_Formula::OnBnClickedBtnDelete)
END_MESSAGE_MAP()


// Dlg_Formula 消息处理程序


void Dlg_Formula::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void Dlg_Formula::OnTbFormulaDelete()
{
	// TODO: 在此添加命令处理程序代码
	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
	{
		distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
	{
		distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
		haveccomboboxcreate = false;
	}
	//int i = k - 1;
	dm = m_list_form.GetItemText(hang[k - 1], 0);
	//nd = m_list_form.GetItemText(hang[i - 1], 1);
	hang[10000] = {};
	k = 0;
	DeleteData();
	CheckData();

}


void Dlg_Formula::OnTbFormulaRefresh()
{
	// TODO: 在此添加命令处理程序代码
	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
	{
		distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
	{
		distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
		haveccomboboxcreate = false;
	}
	hang[10000] = {};
	k = 0;
	CheckData();
	m_list_orde.DeleteAllItems();

}


void Dlg_Formula::OnTbFormulaSave()
{
	// TODO: 在此添加命令处理程序代码
	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
	{
		distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
	{
		distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
		haveccomboboxcreate = false;
	}
	//int i = k;
	//while (i> 0)
	//{
	//	if (m_list_form.GetItemText(hang[i - 1], 0) == (""))
	//	{
	//	}
	//	else
	//	{
	//		dm = m_list_form.GetItemText(hang[i - 1], 0);
	//		mc = m_list_form.GetItemText(hang[i - 1], 1);
	//		CString strTime;
	//		CTime tm;
	//		SYSTEMTIME sysTime;
	//		GetLocalTime(&sysTime);
	//		tm = CTime::GetCurrentTime();
	//		strTime = tm.Format("%y年%m月%d日 %X");
	//		cjsj = strTime;

	//		xgsj = m_list_form.GetItemText(hang[i - 1], 3);
	//		//xygcxry = m_list_form.GetItemText(hang[i - 1], 4);
	//		//zczrry = m_list_form.GetItemText(hang[i - 1], 5);
	//		SaveToDatabase();
	//	}
	//	i--;
	//}
	//int cnum= m_list_orde.GetItemCount();
	//dm = m_list_form.GetItemText(hang[k - 1], 0);
	//xl.Format(_T("%d"), cnum);
	//if (cnum >= 1)
	//{
	//	xl1 = m_list_orde.GetItemText(0, 0);
	//	nd1 = m_list_orde.GetItemText(0, 1);
	//	SaveOne();
	//}
	//if (cnum >= 2)
	//{
	//	xl2 = m_list_orde.GetItemText(1, 0);
	//	nd2 = m_list_orde.GetItemText(1, 1);
	//	SaveTwo();
	//}
	//hang[10000] = {};
	//k = 0;
	dm = m_list_form.GetItemText(hang[k - 1], 0);
	mc = m_list_form.GetItemText(hang[k - 1], 1);
	CString strTime;
	CTime tm;
	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	tm = CTime::GetCurrentTime();
	strTime = tm.Format("%y年%m月%d日 %X");
	xgsj = cjsj = strTime;


	int sum = m_list_orde.GetItemCount();;
	xl.Format(_T("%d"), sum);

	xl1 = m_list_orde.GetItemText(0, 0);
	nd1 = m_list_orde.GetItemText(0, 1);
	xl2 = m_list_orde.GetItemText(1, 0);
	nd2 = m_list_orde.GetItemText(1, 1);
	xl3 = m_list_orde.GetItemText(2, 0);
	nd3 = m_list_orde.GetItemText(2, 1);
	xl4 = m_list_orde.GetItemText(3, 0);
	nd4 = m_list_orde.GetItemText(3, 1);
	xl5 = m_list_orde.GetItemText(4, 0);
	nd5 = m_list_orde.GetItemText(4, 1);
	xl6 = m_list_orde.GetItemText(5, 0);
	nd6 = m_list_orde.GetItemText(5, 1);
	xl7 = m_list_orde.GetItemText(6, 0);
	nd7 = m_list_orde.GetItemText(6, 1);
	xl8 = m_list_orde.GetItemText(7, 0);
	nd8 = m_list_orde.GetItemText(7, 1);
	xl9 = m_list_orde.GetItemText(8, 0);
	nd9 = m_list_orde.GetItemText(8, 1);
	xl10 = m_list_orde.GetItemText(9, 0);
	nd10 = m_list_orde.GetItemText(9, 1);
			
	SaveToDatabase();

	int cnum = m_list_orde.GetItemCount();
	dm = m_list_form.GetItemText(hang[k - 1], 0);




	CheckData();
}

//void Dlg_Formula::OnTbFormulaNew()
//{
//	// TODO: 在此添加命令处理程序代码
//	MessageBox(_T("ckzxjc"));
//}


BOOL Dlg_Formula::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	haveeditcreate = false;//初始化标志位，表示还没有创建编辑框
	haveccomboboxcreate = false;//初始化标志位，表示还没有创建下拉列表框
	RECT  m_rect;

	m_list_form.GetClientRect(&m_rect); //获取list的客户区,方便调节每一列的宽度

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
	CheckData();

	//加载工具栏
	m_toolbar.Create(this);
	m_toolbar.LoadToolBar(IDR_STUFF_TOOLBAR);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	CString sql;
	sql.Format(_T("select* from Stuff order by 代码 desc"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);
	rnum = 0;

	//CFont m_font;
	//m_font.CreatePointFont(100, _T("微软雅黑"));
	//m_cb_liqu.SetFont(&m_font);

	while (m_pRecordset->adoEOF == 0)
	{
		CString s = m_pRecordset->GetCollect(_T("代码"));
		m_cb_liqu.AddString(s);
		m_pRecordset->MoveNext();
	}
	m_cb_liqu.SetCurSel(0);
	m_cb_unit.AddString(_T("%"));
	m_cb_unit.SetCurSel(0);
	//daima = _T("111");
	//SearchData();
	//CString abc = m_pRecordset->GetCollect(_T("浓度1"));
	//MessageBox(abc);


	m_list_orde.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	m_list_orde.DeleteAllItems();

	////CFont m_font;
	////m_font.CreatePointFont(100, _T("微软雅黑"));
	////m_list_orde.SetFont(&m_font);

	m_list_orde.InsertColumn(0, _T("化工料"), LVCFMT_LEFT, 200, 2);         //为列表加入四列：姓名，手机号码，关系，备注
	m_list_orde.InsertColumn(1, _T("浓度"), LVCFMT_LEFT, 200, 2);
	m_list_orde.InsertColumn(2, _T("单位"), LVCFMT_LEFT, 150, 2);
	m_list_orde.InsertColumn(3, _T("序列"), LVCFMT_LEFT, 100, 2);

	//m_list_orde.InsertItem(0, _T("%"));
	//m_list_orde.SetItemText(0, 0, _T("%"));
	//m_list_orde.SetItemText(0, 1, _T("%"));
	//m_list_orde.SetItemText(0, 2, _T("%"));
	//m_list_orde.SetItemText(0, 3, _T("%"));
	//m_list_orde.InsertItem(1, _T("%"));
	//m_list_orde.SetItemText(1, 1, _T("%"));
	//m_list_orde.SetItemText(1, 2, _T("%"));
	//m_list_orde.SetItemText(1, 3, _T("%"));


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void Dlg_Formula::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ExitConn();
	hang[10000] = {};
	k = 0;
	CDialogEx::OnClose();
}

BOOL Dlg_Formula::ExitConn()
{
	//关闭记录集和连接
	if (m_pRecordset != NULL)
	{
		m_pRecordset->Close();
	}
	m_pRecordset = NULL;
	m_pConnection->Close();
	::CoUninitialize(); //可以理解为关闭COM库组件

	return TRUE;
}

void Dlg_Formula::CheckData()//对数据库进行查询操做
{
	CString sql;
	sql.Format(_T("select* from Formula order by 代码 desc"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);



	rnum = 0;

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

	m_list_form.InsertColumn(0, _T("代码"), LVCFMT_LEFT, 200, 2);         //为列表加入四列：姓名，手机号码，关系，备注
	m_list_form.InsertColumn(1, _T("名称"), LVCFMT_LEFT, 200, 2);
	m_list_form.InsertColumn(2, _T("创建时间"), LVCFMT_LEFT, 300, 2);
	m_list_form.InsertColumn(3, _T("修改时间"), LVCFMT_LEFT, 300, 2);
	

	m_pRecordset->MoveFirst();
	while (m_pRecordset->adoEOF == 0)
	{
		rnum++;
		m_pRecordset->MoveNext();
	}
	sum = rnum - 1;
	rnum = 0;
	m_pRecordset->MoveFirst();

	while (m_pRecordset->adoEOF == 0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		m_list_form.InsertItem(0, _T(""));
		m_list_form.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("代码")));
		m_list_form.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("名称")));      //记录集选择的列表名在数据库中必须能够找到，不然出错。
		m_list_form.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("创建时间")));
		m_list_form.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("修改时间")));


		m_pRecordset->MoveNext();
		rnum++;
	}
	//sum = rnum-1;
	//rnum++;

	m_pRecordset->MoveFirst();

	m_list_form.InsertItem(sum + 1, _T(""));
	//////m_list_form.SetItemText(sum+1, 0, _T(""));
	//////m_list_form.SetItemText(sum+1, 1, _T(""));
	//////m_list_form.SetItemText(sum+1, 2, _T(""));
	//////m_list_form.SetItemText(sum+1, 3, _T(""));
	//////m_list_form.SetItemText(sum+1, 4, _T(""));
	//////m_list_form.SetItemText(sum+1, 5, _T(""));
}

void Dlg_Formula::DeleteData()//将数据按照每一行单行写入数据库到时候调用此函数就好
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Delete_Formula";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_dm;
		Param_dm.CreateInstance("ADODB.Parameter");
		Param_dm = m_pCommand->CreateParameter("@代码", adVarWChar, adParamInput, 50, (_variant_t)dm);
		m_pCommand->Parameters->Append(Param_dm);



		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}

void Dlg_Formula::SaveToDatabase()//将数据按照每一行单行写入数据库到时候调用此函数就好
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Add_Formula";//存储过程为Corn_ADD
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

		_ParameterPtr Paramcjsj;
		Paramcjsj.CreateInstance("ADODB.Parameter");
		Paramcjsj = m_pCommand->CreateParameter("@创建时间", adVarWChar, adParamInput, 50, (_variant_t)cjsj);
		m_pCommand->Parameters->Append(Paramcjsj);

		_ParameterPtr Param_xgsj;
		Param_xgsj.CreateInstance("ADODB.Parameter");
		Param_xgsj = m_pCommand->CreateParameter("@修改时间", adVarWChar, adParamInput, 50, (_variant_t)xgsj);
		m_pCommand->Parameters->Append(Param_xgsj);

		_ParameterPtr Param_xl;
		Param_xl.CreateInstance("ADODB.Parameter");
		Param_xl = m_pCommand->CreateParameter("@序列", adVarWChar, adParamInput, 50, (_variant_t)xl);
		m_pCommand->Parameters->Append(Param_xl);

		_ParameterPtr Param_xl1;
		Param_xl1.CreateInstance("ADODB.Parameter");
		Param_xl1 = m_pCommand->CreateParameter("@序列1", adVarWChar, adParamInput, 50, (_variant_t)xl1);
		m_pCommand->Parameters->Append(Param_xl1);

		_ParameterPtr Param_nd1;
		Param_nd1.CreateInstance("ADODB.Parameter");
		Param_nd1 = m_pCommand->CreateParameter("@浓度1", adVarWChar, adParamInput, 50, (_variant_t)nd1);
		m_pCommand->Parameters->Append(Param_nd1);

		_ParameterPtr Param_xl2;
		Param_xl2.CreateInstance("ADODB.Parameter");
		Param_xl2 = m_pCommand->CreateParameter("@序列2", adVarWChar, adParamInput, 50, (_variant_t)xl2);
		m_pCommand->Parameters->Append(Param_xl2);

		_ParameterPtr Param_nd2;
		Param_nd2.CreateInstance("ADODB.Parameter");
		Param_nd2 = m_pCommand->CreateParameter("@浓度2", adVarWChar, adParamInput, 50, (_variant_t)nd2);
		m_pCommand->Parameters->Append(Param_nd2);

		_ParameterPtr Param_xl3;
		Param_xl3.CreateInstance("ADODB.Parameter");
		Param_xl3 = m_pCommand->CreateParameter("@序列3", adVarWChar, adParamInput, 50, (_variant_t)xl3);
		m_pCommand->Parameters->Append(Param_xl3);

		_ParameterPtr Param_nd3;
		Param_nd3.CreateInstance("ADODB.Parameter");
		Param_nd3 = m_pCommand->CreateParameter("@浓度3", adVarWChar, adParamInput, 50, (_variant_t)nd3);
		m_pCommand->Parameters->Append(Param_nd3);

		_ParameterPtr Param_xl4;
		Param_xl4.CreateInstance("ADODB.Parameter");
		Param_xl4 = m_pCommand->CreateParameter("@序列4", adVarWChar, adParamInput, 50, (_variant_t)xl4);
		m_pCommand->Parameters->Append(Param_xl4);

		_ParameterPtr Param_nd4;
		Param_nd4.CreateInstance("ADODB.Parameter");
		Param_nd4 = m_pCommand->CreateParameter("@浓度4", adVarWChar, adParamInput, 50, (_variant_t)nd4);
		m_pCommand->Parameters->Append(Param_nd4);

		_ParameterPtr Param_xl5;
		Param_xl5.CreateInstance("ADODB.Parameter");
		Param_xl5 = m_pCommand->CreateParameter("@序列5", adVarWChar, adParamInput, 50, (_variant_t)xl5);
		m_pCommand->Parameters->Append(Param_xl5);

		_ParameterPtr Param_nd5;
		Param_nd5.CreateInstance("ADODB.Parameter");
		Param_nd5 = m_pCommand->CreateParameter("@浓度5", adVarWChar, adParamInput, 50, (_variant_t)nd5);
		m_pCommand->Parameters->Append(Param_nd5);

		_ParameterPtr Param_xl6;
		Param_xl6.CreateInstance("ADODB.Parameter");
		Param_xl6 = m_pCommand->CreateParameter("@序列6", adVarWChar, adParamInput, 50, (_variant_t)xl6);
		m_pCommand->Parameters->Append(Param_xl6);

		_ParameterPtr Param_nd6;
		Param_nd6.CreateInstance("ADODB.Parameter");
		Param_nd6 = m_pCommand->CreateParameter("@浓度6", adVarWChar, adParamInput, 50, (_variant_t)nd6);
		m_pCommand->Parameters->Append(Param_nd6);

		_ParameterPtr Param_xl7;
		Param_xl7.CreateInstance("ADODB.Parameter");
		Param_xl7 = m_pCommand->CreateParameter("@序列7", adVarWChar, adParamInput, 50, (_variant_t)xl7);
		m_pCommand->Parameters->Append(Param_xl7);

		_ParameterPtr Param_nd7;
		Param_nd7.CreateInstance("ADODB.Parameter");
		Param_nd7 = m_pCommand->CreateParameter("@浓度7", adVarWChar, adParamInput, 50, (_variant_t)nd7);
		m_pCommand->Parameters->Append(Param_nd7);

		_ParameterPtr Param_xl8;
		Param_xl8.CreateInstance("ADODB.Parameter");
		Param_xl8 = m_pCommand->CreateParameter("@序列8", adVarWChar, adParamInput, 50, (_variant_t)xl8);
		m_pCommand->Parameters->Append(Param_xl8);

		_ParameterPtr Param_nd8;
		Param_nd8.CreateInstance("ADODB.Parameter");
		Param_nd8 = m_pCommand->CreateParameter("@浓度8", adVarWChar, adParamInput, 50, (_variant_t)nd8);
		m_pCommand->Parameters->Append(Param_nd8);

		_ParameterPtr Param_xl9;
		Param_xl9.CreateInstance("ADODB.Parameter");
		Param_xl9 = m_pCommand->CreateParameter("@序列9", adVarWChar, adParamInput, 50, (_variant_t)xl9);
		m_pCommand->Parameters->Append(Param_xl9);

		_ParameterPtr Param_nd9;
		Param_nd9.CreateInstance("ADODB.Parameter");
		Param_nd9 = m_pCommand->CreateParameter("@浓度9", adVarWChar, adParamInput, 50, (_variant_t)nd9);
		m_pCommand->Parameters->Append(Param_nd9);

		_ParameterPtr Param_xl10;
		Param_xl10.CreateInstance("ADODB.Parameter");
		Param_xl10 = m_pCommand->CreateParameter("@序列10", adVarWChar, adParamInput, 50, (_variant_t)xl10);
		m_pCommand->Parameters->Append(Param_xl10);

		_ParameterPtr Param_nd10;
		Param_nd10.CreateInstance("ADODB.Parameter");
		Param_nd10 = m_pCommand->CreateParameter("@浓度10", adVarWChar, adParamInput, 50, (_variant_t)nd10);
		m_pCommand->Parameters->Append(Param_nd10);



		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}


_RecordsetPtr& Dlg_Formula::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
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

void Dlg_Formula::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)//创建单元格编辑框函数
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, IDC_EDIT_CREATEID);//创建编辑框对象,IDC_EDIT_CREATEID为控件ID号3000，在文章开头定义
	havecreat = true;
	createdit->SetFont(&m_font);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createdit->SetParent(&m_list_form);//将list control设置为父窗口,生成的Edit才能正确定位,这个也很重要
	CRect  EditRect;
	m_list_form.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_form.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_list_form.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createdit->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createdit->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createdit->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
	createdit->SetFocus();//设置为焦点 
	createdit->SetSel(-1);//设置光标在文本框文字的最后
}

void Dlg_Formula::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//获得相应单元格字符
	distroyedit->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}

void Dlg_Formula::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)//创建单元格下拉列表框函数
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, IDC_COMBOX_CREATEID);
	createccomboboxobj->SetFont(&m_font);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createccomboboxobj->SetParent(&m_list_form);//将list control设置为父窗口,生成的Ccombobox才能正确定位,这个也很重要
	CRect  EditRect;
	m_list_form.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_form.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_list_form.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createccomboboxobj->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createccomboboxobj->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createccomboboxobj->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
}

void Dlg_Formula::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//更新相应单元格字符
	distroyccomboboxobj->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}


void Dlg_Formula::OnNMClickListFormula(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//点击到非工作区
	{
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if(pEditCtrl->iItem == sum+1)
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		m_list_orde.DeleteAllItems();

		m_list_form.SetFocus();
		m_list_form.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		if (haveccomboboxcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);
				haveeditcreate = false;
				createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
			}
			else//点中的单元格是之前创建好的
			{
				m_Edit.SetFocus();//设置为焦点 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
		}
	}
	else
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;

		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		//选中后显示配方
		//CString sql;
		//sql.Format(_T("select* from Formula order by 名称 desc"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
		//GetRecordSet((_bstr_t)sql);

		daima = m_list_form.GetItemText(pEditCtrl->iItem, 0);
		mingcheng = m_list_form.GetItemText(pEditCtrl->iItem, 1);
		SearchData();

		m_list_orde.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
			| LVS_EX_FULLROWSELECT
			| LVS_EX_HEADERDRAGDROP
			| LVS_EX_ONECLICKACTIVATE
			| LVS_EX_GRIDLINES);
		while (m_list_orde.DeleteColumn(0));	//清空所有表头
		m_list_orde.DeleteAllItems();

		CFont m_font;
		m_font.CreatePointFont(100, _T("微软雅黑"));
		m_list_orde.SetFont(&m_font);

		m_list_orde.InsertColumn(0, _T("化工料"), LVCFMT_LEFT, 200, 2);         //为列表加入四列：姓名，手机号码，关系，备注
		m_list_orde.InsertColumn(1, _T("浓度"), LVCFMT_LEFT, 200, 2);
		m_list_orde.InsertColumn(2, _T("单位"), LVCFMT_LEFT, 150, 2);
		m_list_orde.InsertColumn(3, _T("序列"), LVCFMT_LEFT, 100, 2);

		int a = m_pRecordset->GetCollect(_T("序列"));
		
		
		int i = 1;
		while (i <= a)
		{
			CString xl, nd, xh;
			xh.Format(_T("%d"), i);
			xl = _T("序列");
			nd = _T("浓度");
			xl = xl + xh;
			nd = nd + xh;
			m_list_orde.InsertItem(i-1, _T(""));
			m_list_orde.SetItemText(i - 1, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_variant_t(xl)));
			m_list_orde.SetItemText(i - 1, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_variant_t(nd)));
			m_list_orde.SetItemText(i - 1, 2, _T("%"));
			m_list_orde.SetItemText(i - 1, 3, (LPCTSTR)(LPTSTR)(_bstr_t)i);
			i++;
		}
		//CString a1 = m_pRecordset->GetCollect(_T("序列4"));

			//m_list_orde.InsertItem(0, _T(""));
			//m_list_orde.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("名称")));



	}
	*pResult = 0;
}


void Dlg_Formula::OnNMCustomdrawListFormula(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (flagnum > 0)
	{
		flagnum = 0;
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	*pResult = 0;
}

void Dlg_Formula::OnCbnSelchangeComboLiquid()
{

	//CString str;
	//Liquid_Search.Format(_T("select* from Liquid order by 名称 desc"));
	//GetRecordSet((_bstr_t)Liquid_Search);

	int iPos;
	CString str;
	iPos = ((CComboBox*)GetDlgItem(IDC_COMBO_LIQUID))->GetCurSel();//当前选中的行。
	((CComboBox*)GetDlgItem(IDC_COMBO_LIQUID))->SetCurSel(iPos);//设置第n行内容为显示的内容。
	/*GetDlgItem(IDC_COMBO_LIQUID)->GetWindowText(str);
	m_edit_pote.SetWindowText(str);*/

	m_edit_pote.SetWindowText(_T(""));

}

void Dlg_Formula::SearchData()
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
	//(LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("修改时间"))
}

void Dlg_Formula::OnNMDblclkListFormula(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//点击到非工作区
	{
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if (pEditCtrl->iSubItem == 3 || pEditCtrl->iSubItem == 4 || pEditCtrl->iSubItem == 5)//如果是性别选项
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
				m_comBox.AddString(L"Y");
				m_comBox.AddString(L"N");
				m_comBox.ShowDropDown();//自动下拉
			}
			else//点中的单元格是之前创建好的
			{
				m_comBox.SetFocus();//设置为焦点 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
			m_comBox.AddString(L"Y");
			m_comBox.AddString(L"N");
			m_comBox.ShowDropDown();//自动下拉
		}
	}
	else
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		m_list_form.SetFocus();
		m_list_form.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		if (haveccomboboxcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);
				haveeditcreate = false;
				createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
			}
			else//点中的单元格是之前创建好的
			{
				m_Edit.SetFocus();//设置为焦点 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
		}
	}
	*pResult = 0;
}


void Dlg_Formula::OnBnClickedBtnFormAdd()
{
	CString hgl,nongdu, xulie;
	GetDlgItem(IDC_COMBO_LIQUID)->GetWindowText(hgl);
	GetDlgItem(IDC_EDIT_POTENCY)->GetWindowText(nongdu);
	GetDlgItem(IDC_EDIT_ORDER)->GetWindowText(xulie);
	int a = _ttoi(xulie);

	int cnum = m_list_orde.GetItemCount();
	//m_list_orde.InsertItem(a, _T(""));

	m_list_orde.InsertItem(cnum,hgl);
	//m_list_orde.SetItemText(a - 1, 1, hgl);
	m_list_orde.SetItemText(cnum, 1, nongdu);
	m_list_orde.SetItemText(cnum, 2, _T("%"));

	m_list_orde.SetItemText(cnum, 3, xulie);
	


}


void Dlg_Formula::OnTbFormulaNew()
{
	// TODO: 在此添加命令处理程序代码
	int nItem = m_list_form.GetItemCount();
	//m_list_form.SetItemState(6, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	m_list_form.SetItemState(nItem-1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_list_form.EnsureVisible(nItem - 1, FALSE);



}


void Dlg_Formula::OnEnChangeEditPotency()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	int sum = m_list_orde.GetItemCount();
	xl.Format(_T("%d"), sum+1);
	m_edit_orde.SetWindowText(xl);
	// TODO:  在此添加控件通知处理程序代码
}


void Dlg_Formula::OnBnClickedBtnDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	int iItem;
	for (iItem = m_list_orde.GetItemCount() - 1; iItem >= 0; iItem--)
	{
		if (LVIS_SELECTED == m_list_orde.GetItemState(iItem, LVIS_SELECTED))     //发现选中行
		{
			m_list_orde.DeleteItem(iItem);
		}
	}

}
