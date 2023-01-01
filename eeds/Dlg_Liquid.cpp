// Dlg_Liquid.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Liquid.h"
#include "afxdialogex.h"
#include "NEWLISTCTRL.h"
#define IDC_EDIT_CREATEID  3001//用于定义List 
#define IDC_COMBOX_CREATEID  3002//用于下拉列表

// Dlg_Liquid 对话框

IMPLEMENT_DYNAMIC(Dlg_Liquid, CDialogEx)

Dlg_Liquid::Dlg_Liquid(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_LIQUID, pParent)
{

}

Dlg_Liquid::~Dlg_Liquid()
{
}

void Dlg_Liquid::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_LIQUID, m_list_liquid);
}


BEGIN_MESSAGE_MAP(Dlg_Liquid, CDialogEx, CEdit)
	ON_COMMAND(TB_STUFF_DELETE, &Dlg_Liquid::OnTbLiquidDelete)
	ON_COMMAND(TB_STUFF_REFRESH, &Dlg_Liquid::OnTbLiquidRefresh)
	ON_COMMAND(TB_STUFF_SAVE, &Dlg_Liquid::OnTbLiquidSave)
	ON_WM_CLOSE()
//	ON_WM_VSCROLL()
//	ON_WM_HSCROLL()
	ON_NOTIFY(NM_CLICK, IDC_LIST_LIQUID, &Dlg_Liquid::OnNMClickListLiquid)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_LIQUID, &Dlg_Liquid::OnNMCustomdrawListLiquid)
	ON_NOTIFY(LVN_BEGINSCROLL, IDC_LIST_LIQUID, &Dlg_Liquid::OnLvnBeginScrollListLiquid)
//	ON_WM_KILLFOCUS()
ON_NOTIFY(NM_DBLCLK, IDC_LIST_LIQUID, &Dlg_Liquid::OnNMDblclkListLiquid)
ON_COMMAND(TB_STUFF_NEW, &Dlg_Liquid::OnTbLiquidNew)
END_MESSAGE_MAP()


// Dlg_Liquid 消息处理程序


BOOL Dlg_Liquid::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	haveeditcreate = false;//初始化标志位，表示还没有创建编辑框
	haveccomboboxcreate = false;//初始化标志位，表示还没有创建下拉列表框
	RECT  m_rect;

	m_list_liquid.GetClientRect(&m_rect); //获取list的客户区,方便调节每一列的宽度
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
	m_toolbar.Create(this);
	// 将变量与创建的Toolbar资源绑定
	m_toolbar.LoadToolBar(IDR_STUFF_TOOLBAR);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);


	//m_list_liquid.SendMessage(WM_HSCROLL, SB_BOTTOM, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Dlg_Liquid::OnTbLiquidDelete()
{
	// TODO: 在此添加命令处理程序代码
	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
	{
		distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
	{
		distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
		haveccomboboxcreate = false;
	}
	//int i = k - 1;
	//while (i> 0)
	//{
	//	if (m_list_liquid.GetItemText(hang[i - 1], 0) == (""))
	//	{
	//		break;
	//	}
	//	else
	//	{
	//		mc = m_list_liquid.GetItemText(hang[i - 1], 0);
	//		nd = m_list_liquid.GetItemText(hang[i - 1], 1);
	//		ryrj = m_list_liquid.GetItemText(hang[i - 1], 2);
	//		rysjrj = m_list_liquid.GetItemText(hang[i - 1], 3);
	//		zxpsl = m_list_liquid.GetItemText(hang[i - 1], 4);
	//		zdpsl = m_list_liquid.GetItemText(hang[i - 1], 5);
	//		zxrj = m_list_liquid.GetItemText(hang[i - 1], 6);
	//		zdrj = m_list_liquid.GetItemText(hang[i - 1], 7);
	//		mrrj = m_list_liquid.GetItemText(hang[i - 1], 8);
	//		djhzz = m_list_liquid.GetItemText(hang[i - 1], 9);
	//		dycsfjrs = m_list_liquid.GetItemText(hang[i - 1], 10);
	//		decsfjrs = m_list_liquid.GetItemText(hang[i - 1], 11);
	//		dyczrl = m_list_liquid.GetItemText(hang[i - 1], 12);
	//		jbsj = m_list_liquid.GetItemText(hang[i - 1], 13);
	//		cxxyg = m_list_liquid.GetItemText(hang[i - 1], 14);
	//		xygcxry = m_list_liquid.GetItemText(hang[i - 1], 15);

	//		SaveToDatabase();
	//	}
	//	i--;
	//}
	mc = m_list_liquid.GetItemText(hang[k - 1], 0);
	nd = m_list_liquid.GetItemText(hang[k - 1], 1);
	hang[10000] = {};
	k = 0;
	DeleteData();
	CheckData();
}


void Dlg_Liquid::OnTbLiquidRefresh()
{
	// TODO: 在此添加命令处理程序代码
	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
	{
		distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
	{
		distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
		haveccomboboxcreate = false;
	}
	hang[10000] = {};
	k = 0;
	CheckData();
}


void Dlg_Liquid::OnTbLiquidSave()
{


	// TODO: 在此添加命令处理程序代码
	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
	{
		distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
	{
		distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
		haveccomboboxcreate = false;
	}
	int i = k;
	while (i> 0)
	{
		if (m_list_liquid.GetItemText(hang[i - 1], 0) == (""))
		{
			break;
		}
		else
		{
			mc = m_list_liquid.GetItemText(hang[i - 1], 0);
			nd = m_list_liquid.GetItemText(hang[i - 1], 1);
			ryrj = m_list_liquid.GetItemText(hang[i - 1], 2);
			rysjrj = m_list_liquid.GetItemText(hang[i - 1], 3);
			zxpsl = m_list_liquid.GetItemText(hang[i - 1], 4);
			zdpsl = m_list_liquid.GetItemText(hang[i - 1], 5);
			zxrj = m_list_liquid.GetItemText(hang[i - 1], 6);
			zdrj = m_list_liquid.GetItemText(hang[i - 1], 7);
			mrrj = m_list_liquid.GetItemText(hang[i - 1], 8);
			djhzz = m_list_liquid.GetItemText(hang[i - 1], 9);
			dycsfjrs = m_list_liquid.GetItemText(hang[i - 1], 10);
			decsfjrs = m_list_liquid.GetItemText(hang[i - 1], 11);
			dyczrl = m_list_liquid.GetItemText(hang[i - 1], 12);
			jbsj = m_list_liquid.GetItemText(hang[i - 1], 13);
			cxxyg = m_list_liquid.GetItemText(hang[i - 1], 14);
			xygcxry = m_list_liquid.GetItemText(hang[i - 1], 15);
			SaveToDatabase();
		}
		i--;
	}
	hang[10000] = {};
	k = 0;
	CheckData();
}


void Dlg_Liquid::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ExitConn();
	hang[10000] = {};
	k = 0;
	CDialogEx::OnClose();
}



void Dlg_Liquid::OnNMCustomdrawListLiquid(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (flagnum > 0)
	{
		flagnum=0;
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	*pResult = 0;
}

BOOL Dlg_Liquid::ExitConn()
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

void Dlg_Liquid::CheckData()//对数据库进行查询操做
{
	CString sql;
	sql.Format(_T("select* from Liquid order by 名称 desc"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);

	m_list_liquid.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_liquid.DeleteColumn(0));	//清空所有表头
	m_list_liquid.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_list_liquid.SetFont(&m_font);

	m_list_liquid.InsertColumn(0, _T("化工料"), LVCFMT_LEFT, 200, 2);         //为列表加入四列：姓名，手机号码，关系，备注
	m_list_liquid.InsertColumn(1, _T("浓度"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(2, _T("溶液容积"), LVCFMT_LEFT, 150, 2);
	m_list_liquid.InsertColumn(3, _T("溶液实际容积"), LVCFMT_LEFT, 100, 2);
	m_list_liquid.InsertColumn(4, _T("最小配送量"), LVCFMT_LEFT, 150, 2);
	m_list_liquid.InsertColumn(5, _T("最大配送量"), LVCFMT_LEFT, 100, 2);
	m_list_liquid.InsertColumn(6, _T("最小容积"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(7, _T("最大容积"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(8, _T("默认容积"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(9, _T("多久后过期[h]"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(10, _T("第一次是否加热水"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(11, _T("第二次是否加热水"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(12, _T("第一次注入量"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(13, _T("搅拌时间[s]"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(14, _T("冲洗吸液管"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(15, _T("吸液管冲洗溶液"), LVCFMT_LEFT, 200, 2);



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
		m_list_liquid.InsertItem(0, _T(""));
		m_list_liquid.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("名称")));
		m_list_liquid.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("浓度")));      //记录集选择的列表名在数据库中必须能够找到，不然出错。
		m_list_liquid.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("溶液容积")));
		m_list_liquid.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("溶液实际容积")));
		m_list_liquid.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("最小配送量")));
		m_list_liquid.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("最大配送量")));
		m_list_liquid.SetItemText(0, 6, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("最小容积")));
		m_list_liquid.SetItemText(0, 7, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("最大容积")));
		m_list_liquid.SetItemText(0, 8, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("默认容积")));
		m_list_liquid.SetItemText(0, 9, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("多久后终止")));
		m_list_liquid.SetItemText(0, 10, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("第一次是否加热水")));
		m_list_liquid.SetItemText(0, 11, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("第二次是否加热水")));
		m_list_liquid.SetItemText(0, 12, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("第一次注入量")));
		m_list_liquid.SetItemText(0, 13, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("搅拌时间")));
		m_list_liquid.SetItemText(0, 14, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("冲洗吸液管")));
		m_list_liquid.SetItemText(0, 15, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("吸液管冲洗溶液")));
	

		m_pRecordset->MoveNext();
		rnum++;
	}
	//sum = rnum-1;
	//rnum++;

	m_pRecordset->MoveFirst();

	m_list_liquid.InsertItem(sum + 1, _T(""));
	//////m_list_liquid.SetItemText(sum+1, 0, _T(""));
	//////m_list_liquid.SetItemText(sum+1, 1, _T(""));
	//////m_list_liquid.SetItemText(sum+1, 2, _T(""));
	//////m_list_liquid.SetItemText(sum+1, 3, _T(""));
	//////m_list_liquid.SetItemText(sum+1, 4, _T(""));
	//////m_list_liquid.SetItemText(sum+1, 5, _T(""));
}

void Dlg_Liquid::DeleteData()//将数据按照每一行单行写入数据库到时候调用此函数就好
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Delete_Liquid";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_mc;
		Param_mc.CreateInstance("ADODB.Parameter");
		Param_mc = m_pCommand->CreateParameter("@名称", adVarWChar, adParamInput, 50, (_variant_t)mc);
		m_pCommand->Parameters->Append(Param_mc);

		_ParameterPtr Param_nd;
		Param_nd.CreateInstance("ADODB.Parameter");
		Param_nd = m_pCommand->CreateParameter("@浓度", adVarWChar, adParamInput, 50, (_variant_t)nd);
		m_pCommand->Parameters->Append(Param_nd);

		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}

void Dlg_Liquid::SaveToDatabase()//将数据按照每一行单行写入数据库到时候调用此函数就好
{



	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Add_Liquid";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_mc;
		Param_mc.CreateInstance("ADODB.Parameter");
		Param_mc = m_pCommand->CreateParameter("@名称", adVarWChar, adParamInput, 50, (_variant_t)mc);
		m_pCommand->Parameters->Append(Param_mc);

		_ParameterPtr Param_nd;
		Param_nd.CreateInstance("ADODB.Parameter");
		Param_nd = m_pCommand->CreateParameter("@浓度", adVarWChar, adParamInput, 50, (_variant_t)nd);
		m_pCommand->Parameters->Append(Param_nd);

		_ParameterPtr Param_ryrj;
		Param_ryrj.CreateInstance("ADODB.Parameter");
		Param_ryrj = m_pCommand->CreateParameter("@溶液容积", adVarWChar, adParamInput, 50, (_variant_t)ryrj);
		m_pCommand->Parameters->Append(Param_ryrj);

		_ParameterPtr Param_rysjrj;
		Param_rysjrj.CreateInstance("ADODB.Parameter");
		Param_rysjrj = m_pCommand->CreateParameter("@溶液实际容积", adVarChar, adParamInput, 50, (_variant_t)rysjrj);
		m_pCommand->Parameters->Append(Param_rysjrj);

		_ParameterPtr Param_zxpsl;
		Param_zxpsl.CreateInstance("ADODB.Parameter");
		Param_zxpsl = m_pCommand->CreateParameter("@最小配送量", adVarWChar, adParamInput, 50, (_variant_t)zxpsl);
		m_pCommand->Parameters->Append(Param_zxpsl);

		_ParameterPtr Param_zdpsl;
		Param_zdpsl.CreateInstance("ADODB.Parameter");
		Param_zdpsl = m_pCommand->CreateParameter("@最大配送量", adVarWChar, adParamInput, 50, (_variant_t)zdpsl);
		m_pCommand->Parameters->Append(Param_zdpsl);

		_ParameterPtr Param_zxrj;
		Param_zxrj.CreateInstance("ADODB.Parameter");
		Param_zxrj = m_pCommand->CreateParameter("@最小容积", adVarChar, adParamInput, 50, (_variant_t)zxrj);
		m_pCommand->Parameters->Append(Param_zxrj);

		_ParameterPtr Param_zdrj;
		Param_zdrj.CreateInstance("ADODB.Parameter");
		Param_zdrj = m_pCommand->CreateParameter("@最大容积", adVarChar, adParamInput, 50, (_variant_t)zdrj);
		m_pCommand->Parameters->Append(Param_zdrj);

		_ParameterPtr Param_mrrj;
		Param_mrrj.CreateInstance("ADODB.Parameter");
		Param_mrrj = m_pCommand->CreateParameter("@默认容积", adVarChar, adParamInput, 50, (_variant_t)mrrj);
		m_pCommand->Parameters->Append(Param_mrrj);

		_ParameterPtr Param_djhzz;
		Param_djhzz.CreateInstance("ADODB.Parameter");
		Param_djhzz = m_pCommand->CreateParameter("@多久后终止", adVarChar, adParamInput, 50, (_variant_t)djhzz);
		m_pCommand->Parameters->Append(Param_djhzz);

		_ParameterPtr Param_dycsfjrs;
		Param_dycsfjrs.CreateInstance("ADODB.Parameter");
		Param_dycsfjrs = m_pCommand->CreateParameter("@第一次是否加热水", adVarChar, adParamInput, 50, (_variant_t)dycsfjrs);
		m_pCommand->Parameters->Append(Param_dycsfjrs);

		_ParameterPtr Param_decsfjrs;
		Param_decsfjrs.CreateInstance("ADODB.Parameter");
		Param_decsfjrs = m_pCommand->CreateParameter("@第二次是否加热水", adVarChar, adParamInput, 50, (_variant_t)decsfjrs);
		m_pCommand->Parameters->Append(Param_decsfjrs);

		_ParameterPtr Param_dyczrl;
		Param_dyczrl.CreateInstance("ADODB.Parameter");
		Param_dyczrl = m_pCommand->CreateParameter("@第一次注入量", adVarChar, adParamInput, 50, (_variant_t)dyczrl);
		m_pCommand->Parameters->Append(Param_dyczrl);

		_ParameterPtr Param_jbsj;
		Param_jbsj.CreateInstance("ADODB.Parameter");
		Param_jbsj = m_pCommand->CreateParameter("@搅拌时间", adVarChar, adParamInput, 50, (_variant_t)jbsj);
		m_pCommand->Parameters->Append(Param_jbsj);

		_ParameterPtr Param_cxxyg;
		Param_cxxyg.CreateInstance("ADODB.Parameter");
		Param_cxxyg = m_pCommand->CreateParameter("@冲洗吸液管", adVarChar, adParamInput, 50, (_variant_t)cxxyg);
		m_pCommand->Parameters->Append(Param_cxxyg);

		_ParameterPtr Param_xygcxry;
		Param_xygcxry.CreateInstance("ADODB.Parameter");
		Param_xygcxry = m_pCommand->CreateParameter("@吸液管冲洗溶液", adVarChar, adParamInput, 50, (_variant_t)xygcxry);
		m_pCommand->Parameters->Append(Param_xygcxry);

		CString align, again;
		align = again = _T("N");
		_ParameterPtr Param_align;
		Param_align.CreateInstance("ADODB.Parameter");
		Param_align = m_pCommand->CreateParameter("@吸液管冲洗溶液", adVarChar, adParamInput, 50, (_variant_t)align);
		m_pCommand->Parameters->Append(Param_align);

		_ParameterPtr Param_again;
		Param_again.CreateInstance("ADODB.Parameter");
		Param_again = m_pCommand->CreateParameter("@吸液管冲洗溶液", adVarChar, adParamInput, 50, (_variant_t)again);
		m_pCommand->Parameters->Append(Param_again);

		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}

_RecordsetPtr& Dlg_Liquid::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
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

void Dlg_Liquid::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)//创建单元格编辑框函数
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, IDC_EDIT_CREATEID);//创建编辑框对象,IDC_EDIT_CREATEID为控件ID号3000，在文章开头定义
	havecreat = true;
	createdit->SetFont(&m_font);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createdit->SetParent(&m_list_liquid);//将list control设置为父窗口,生成的Edit才能正确定位,这个也很重要
	CRect  EditRect;
	m_list_liquid.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_liquid.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_list_liquid.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createdit->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createdit->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createdit->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
	createdit->SetFocus();//设置为焦点 
	createdit->SetSel(-1);//设置光标在文本框文字的最后
}

void Dlg_Liquid::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//获得相应单元格字符
	distroyedit->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}

void Dlg_Liquid::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)//创建单元格下拉列表框函数
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, IDC_COMBOX_CREATEID);
	createccomboboxobj->SetFont(&m_font);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createccomboboxobj->SetParent(&m_list_liquid);//将list control设置为父窗口,生成的Ccombobox才能正确定位,这个也很重要
	CRect  EditRect;
	m_list_liquid.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_liquid.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_list_liquid.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createccomboboxobj->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createccomboboxobj->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createccomboboxobj->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
}

void Dlg_Liquid::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//更新相应单元格字符
	distroyccomboboxobj->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}

//void Dlg_Liquid::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
//{
//	// todo
//	if (nSBCode == SB_ENDSCROLL);
//	MessageBox(_T("aaa"));
//	CWnd::OnVScroll(nSBCode, nPos, pScrollBar);
//	MessageBox(_T("bbb"));
//}
//void Dlg_Liquid::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
//{
//	// todo
//	//CListCtrl clistctrl;
//	if (nSBCode == SB_ENDSCROLL);
//	Dlg_Liquid::OnHScroll(nSBCode, nPos, pScrollBar);
//	MessageBox(_T("bbb"));
//	if ((::GetKeyState(VK_LBUTTON) & 0x8000) != 0)
//	{
//		MessageBox(_T("bbb"));
//	}
//
//}


void Dlg_Liquid::OnLvnBeginScrollListLiquid(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 此功能要求 Internet Explorer 5.5 或更高版本。
	// 符号 _WIN32_IE 必须是 >= 0x0560。
	LPNMLVSCROLL pStateChanged = reinterpret_cast<LPNMLVSCROLL>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


//void Dlg_Liquid::OnKillFocus(CWnd* pNewWnd)
//{
//	//MessageBox(_T("sdsad"));
//	CDialogEx::OnKillFocus(pNewWnd);
//
//	// TODO: 在此处添加消息处理程序代码
//}



void Dlg_Liquid::OnNMDblclkListLiquid(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//点击到非工作区
	{
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	//else if (pEditCtrl->iSubItem != 11 && pEditCtrl->iSubItem != 1 && pEditCtrl->iSubItem != 5 && pEditCtrl->iSubItem != 6)//如果不是性别选项
	//{
	//	hang[k] = pEditCtrl->iItem;
	//	lie[k] = pEditCtrl->iSubItem;
	//	k++;
	//	m_list_liquid.SetFocus();
	//	m_list_liquid.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	//	if (haveccomboboxcreate == true)//如果之前创建了编辑框就销毁掉
	//	{
	//		distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
	//		haveccomboboxcreate = false;
	//	}
	//	if (haveeditcreate == true)
	//	{
	//		if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
	//		{
	//			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);
	//			haveeditcreate = false;
	//			createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
	//		}
	//		else//点中的单元格是之前创建好的
	//		{
	//			m_Edit.SetFocus();//设置为焦点 
	//		}
	//	}
	//	else
	//	{
	//		e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	//		e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	//		createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
	//	}
	//}
	else if (pEditCtrl->iSubItem == 10 || pEditCtrl->iSubItem == 11)//如果是性别选项
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
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
	//else if (pEditCtrl->iSubItem == 11)//如果是性别选项
	//{
	//	hang[k] = pEditCtrl->iItem;
	//	lie[k] = pEditCtrl->iSubItem;
	//	k++;
	//	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
	//	{
	//		distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);
	//		haveeditcreate = false;
	//	}
	//	if (haveccomboboxcreate == true)
	//	{
	//		if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
	//		{
	//			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
	//			haveccomboboxcreate = false;
	//			createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
	//			m_comBox.AddString(L"B");
	//			m_comBox.AddString(L"");
	//			m_comBox.ShowDropDown();//自动下拉
	//		}
	//		else//点中的单元格是之前创建好的
	//		{
	//			m_comBox.SetFocus();//设置为焦点 
	//		}
	//	}
	//	else
	//	{
	//		e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	//		e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	//		createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
	//		m_comBox.AddString(L"B");
	//		m_comBox.AddString(L"");
	//		m_comBox.ShowDropDown();//自动下拉
	//	}
	//}
	else if (pEditCtrl->iSubItem == 15)//如果是性别选项
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
				m_comBox.AddString(L"(no selection)");
				m_comBox.AddString(L"HAC");
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
			m_comBox.AddString(L"(no selection)");
			m_comBox.AddString(L"HAC");
			m_comBox.ShowDropDown();//自动下拉
		}
	}
	else
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		m_list_liquid.SetFocus();
		m_list_liquid.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		if (haveccomboboxcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);
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

void Dlg_Liquid::OnNMClickListLiquid(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	if (pEditCtrl->iItem == -1)//点击到非工作区
	{
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}

}


void Dlg_Liquid::OnTbLiquidNew()
{
	// TODO: 在此添加命令处理程序代码
	int nItem = m_list_liquid.GetItemCount();
	//m_list_form.SetItemState(6, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	m_list_liquid.SetItemState(nItem - 1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_list_liquid.EnsureVisible(nItem - 1, FALSE);


	m_list_liquid.SetItemText(nItem - 1, 2, _T("1000"));
	m_list_liquid.SetItemText(nItem - 1, 3, _T("1000"));
	m_list_liquid.SetItemText(nItem - 1, 6, _T("200"));
	m_list_liquid.SetItemText(nItem - 1, 7, _T("900"));
	m_list_liquid.SetItemText(nItem - 1, 8, _T("800"));
	m_list_liquid.SetItemText(nItem - 1, 9, _T("300"));
	m_list_liquid.SetItemText(nItem - 1, 10, _T("N"));
	m_list_liquid.SetItemText(nItem - 1, 11, _T("Y"));
	m_list_liquid.SetItemText(nItem - 1, 12, _T("300"));
	m_list_liquid.SetItemText(nItem - 1, 13, _T("60"));
	m_list_liquid.SetItemText(nItem - 1, 14, _T("3"));
	m_list_liquid.SetItemText(nItem - 1, 15, _T("N"));
}
