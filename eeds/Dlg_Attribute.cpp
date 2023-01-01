// Dlg_Attribute.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Attribute.h"
#include "afxdialogex.h"
#define IDC_EDIT_CREATEID  3003//用于定义List 
#define IDC_COMBOX_CREATEID  3004//用于下拉列表

// Dlg_Attribute 对话框

IMPLEMENT_DYNAMIC(Dlg_Attribute, CDialogEx)

Dlg_Attribute::Dlg_Attribute(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_ATTRIBUTE, pParent)
{

}

Dlg_Attribute::~Dlg_Attribute()
{
}

void Dlg_Attribute::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ATTRIBUTE, m_list_liquidAttr);
}


BEGIN_MESSAGE_MAP(Dlg_Attribute, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST_ATTRIBUTE, &Dlg_Attribute::OnNMClickList1)
	//	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_ATTRIBUTE, &Dlg_Attribute::OnNMCustomdrawList1)
	//	ON_COMMAND(TB_STUFF_DELETE, &Dlg_Attribute::OnTbAttributeDelete)
	//	ON_COMMAND(TB_STUFF_REFRESH, &Dlg_Attribute::OnTbAttributeRefresh)
	//	ON_COMMAND(TB_STUFF_SAVE, &Dlg_Attribute::OnTbAttributeSave)
	ON_WM_CLOSE()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_ATTRIBUTE, &Dlg_Attribute::OnNMCustomdrawListAttribute)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_ATTRIBUTE, &Dlg_Attribute::OnNMDblclkListAttribute)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &Dlg_Attribute::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, &Dlg_Attribute::OnBnClickedButtonRefresh)
END_MESSAGE_MAP()


// Dlg_Attribute 消息处理程序


void Dlg_Attribute::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//点击到非工作区
	{
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_liquidAttr, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if (pEditCtrl->iSubItem == 3 || pEditCtrl->iSubItem == 4 || pEditCtrl->iSubItem == 5)//
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyCcombobox(&m_list_liquidAttr, &m_comBox, e_Item, e_SubItem);
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
		//hang[k] = pEditCtrl->iItem;
		//lie[k] = pEditCtrl->iSubItem;
		//k++;
		//m_list_liquidAttr.SetFocus();
		//m_list_liquidAttr.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		//if (haveccomboboxcreate == true)//如果之前创建了编辑框就销毁掉
		//{
		//	distroyCcombobox(&m_list_liquidAttr, &m_comBox, e_Item, e_SubItem);
		//	haveccomboboxcreate = false;
		//}
		//if (haveeditcreate == true)
		//{
		//	if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
		//	{
		//		distroyEdit(&m_list_liquidAttr, &m_Edit, e_Item, e_SubItem);
		//		haveeditcreate = false;
		//		createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
		//	}
		//	else//点中的单元格是之前创建好的
		//	{
		//		m_Edit.SetFocus();//设置为焦点 
		//	}
		//}
		//else
		//{
		//	e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
		//	e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
		//	createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
		//}
	}
}

//void Dlg_Attribute::OnTbAttributeDelete()
//{
//	// TODO: 在此添加命令处理程序代码
//	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
//	{
//		distroyEdit(&m_list_liquidAttr, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
//		haveeditcreate = false;
//	}
//	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
//	{
//		distroyCcombobox(&m_list_liquidAttr, &m_comBox, e_Item, e_SubItem);
//		haveccomboboxcreate = false;
//	}
//
//	mc = m_list_liquidAttr.GetItemText(hang[k - 1], 0);
//	nd = m_list_liquidAttr.GetItemText(hang[k - 1], 1);
//	hang[10000] = {};
//	k = 0;
//	DeleteData();
//	CheckData();
//}


//void Dlg_Attribute::OnTbAttributeRefresh()
//{
//	// TODO: 在此添加命令处理程序代码
//	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
//	{
//		distroyEdit(&m_list_liquidAttr, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
//		haveeditcreate = false;
//	}
//	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
//	{
//		distroyCcombobox(&m_list_liquidAttr, &m_comBox, e_Item, e_SubItem);
//		haveccomboboxcreate = false;
//	}
//	hang[10000] = {};
//	k = 0;
//	CheckData();
//}


//void Dlg_Attribute::OnTbAttributeSave()
//{
//	// TODO: 在此添加命令处理程序代码
//	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
//	{
//		distroyEdit(&m_list_liquidAttr, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
//		haveeditcreate = false;
//	}
//	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
//	{
//		distroyCcombobox(&m_list_liquidAttr, &m_comBox, e_Item, e_SubItem);
//		haveccomboboxcreate = false;
//	}
//	int i = k;
//	while (i> 0)
//	{
//		if (m_list_liquidAttr.GetItemText(hang[k - 1], 0) == (""))
//		{
//			break;
//		}
//		else
//		{
//			mc = m_list_liquidAttr.GetItemText(hang[i - 1], 0);
//			nd = m_list_liquidAttr.GetItemText(hang[i - 1], 1);
//			md = m_list_liquidAttr.GetItemText(hang[i - 1], 2);
//			jzry = m_list_liquidAttr.GetItemText(hang[i - 1], 3);
//			xygcxry = m_list_liquidAttr.GetItemText(hang[i - 1], 4);
//			zczrry = m_list_liquidAttr.GetItemText(hang[i - 1], 5);
//			SaveToDatabase();
//		}
//		i--;
//	}
//	hang[10000] = {};
//	k = 0;
//	CheckData();
//}


void Dlg_Attribute::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ExitConn();
	hang[10000] = {};
	k = 0;
	CDialogEx::OnClose();
}

BOOL Dlg_Attribute::ExitConn()
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

void Dlg_Attribute::CheckData()//对数据库进行查询操做
{
	CString sql;
	sql.Format(_T("select* from Liquid order by 名称 desc"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);



	rnum = 0;

	m_list_liquidAttr.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_liquidAttr.DeleteColumn(0));	//清空所有表头
	m_list_liquidAttr.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_list_liquidAttr.SetFont(&m_font);

	m_list_liquidAttr.InsertColumn(0, _T("名称"), LVCFMT_LEFT, 200, 2);         //为列表加入四列：姓名，手机号码，关系，备注
	m_list_liquidAttr.InsertColumn(1, _T("浓度"), LVCFMT_LEFT, 200, 2);
	m_list_liquidAttr.InsertColumn(2, _T("密度"), LVCFMT_LEFT, 150, 2);
	m_list_liquidAttr.InsertColumn(3, _T("校准溶液"), LVCFMT_LEFT, 100, 2);
	m_list_liquidAttr.InsertColumn(4, _T("吸液管冲洗溶液"), LVCFMT_LEFT, 150, 2);
	m_list_liquidAttr.InsertColumn(5, _T("再次注入溶液"), LVCFMT_LEFT, 100, 2);


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
		m_list_liquidAttr.InsertItem(0, _T(""));
		m_list_liquidAttr.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("名称")));
		m_list_liquidAttr.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("浓度")));      //记录集选择的列表名在数据库中必须能够找到，不然出错。
		m_list_liquidAttr.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("溶液实际容积")));
		m_list_liquidAttr.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("校准溶液")));
		m_list_liquidAttr.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("吸液管冲洗溶液")));
		m_list_liquidAttr.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("再次注入溶液")));

		m_pRecordset->MoveNext();
		rnum++;
	}
	//sum = rnum-1;
	//rnum++;

	m_pRecordset->MoveFirst();

	m_list_liquidAttr.InsertItem(sum + 1, _T(""));
	//////m_list_liquidAttr.SetItemText(sum+1, 0, _T(""));
	//////m_list_liquidAttr.SetItemText(sum+1, 1, _T(""));
	//////m_list_liquidAttr.SetItemText(sum+1, 2, _T(""));
	//////m_list_liquidAttr.SetItemText(sum+1, 3, _T(""));
	//////m_list_liquidAttr.SetItemText(sum+1, 4, _T(""));
	//////m_list_liquidAttr.SetItemText(sum+1, 5, _T(""));
}

void Dlg_Attribute::DeleteData()//将数据按照每一行单行写入数据库到时候调用此函数就好
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Delete_Liquid_Attribute";//存储过程为Corn_ADD
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

void Dlg_Attribute::SaveToDatabase()//将数据按照每一行单行写入数据库到时候调用此函数就好
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Add_Liquid_Attribute";//存储过程为Corn_ADD
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

		_ParameterPtr Param_jzry;
		Param_jzry.CreateInstance("ADODB.Parameter");
		Param_jzry = m_pCommand->CreateParameter("@校准溶液", adVarWChar, adParamInput, 50, (_variant_t)jzry);
		m_pCommand->Parameters->Append(Param_jzry);

		_ParameterPtr Param_xygcxry;
		Param_xygcxry.CreateInstance("ADODB.Parameter");
		Param_xygcxry = m_pCommand->CreateParameter("@吸液管冲洗溶液", adVarChar, adParamInput, 50, (_variant_t)xygcxry);
		m_pCommand->Parameters->Append(Param_xygcxry);

		_ParameterPtr Param_zczrry;
		Param_zczrry.CreateInstance("ADODB.Parameter");
		Param_zczrry = m_pCommand->CreateParameter("@再次注入溶液", adVarChar, adParamInput, 50, (_variant_t)zczrry);
		m_pCommand->Parameters->Append(Param_zczrry);


		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}

_RecordsetPtr& Dlg_Attribute::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
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

void Dlg_Attribute::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)//创建单元格编辑框函数
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, IDC_EDIT_CREATEID);//创建编辑框对象,IDC_EDIT_CREATEID为控件ID号3000，在文章开头定义
	havecreat = true;
	createdit->SetFont(&m_font);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createdit->SetParent(&m_list_liquidAttr);//将list control设置为父窗口,生成的Edit才能正确定位,这个也很重要
	CRect  EditRect;
	m_list_liquidAttr.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_liquidAttr.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_list_liquidAttr.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createdit->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createdit->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createdit->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
	createdit->SetFocus();//设置为焦点 
	createdit->SetSel(-1);//设置光标在文本框文字的最后
}

void Dlg_Attribute::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//获得相应单元格字符
	distroyedit->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}

void Dlg_Attribute::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)//创建单元格下拉列表框函数
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, IDC_COMBOX_CREATEID);
	createccomboboxobj->SetFont(&m_font);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createccomboboxobj->SetParent(&m_list_liquidAttr);//将list control设置为父窗口,生成的Ccombobox才能正确定位,这个也很重要
	CRect  EditRect;
	m_list_liquidAttr.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_liquidAttr.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_list_liquidAttr.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createccomboboxobj->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createccomboboxobj->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createccomboboxobj->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
}

void Dlg_Attribute::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//更新相应单元格字符
	distroyccomboboxobj->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}


BOOL Dlg_Attribute::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	haveeditcreate = false;//初始化标志位，表示还没有创建编辑框
	haveccomboboxcreate = false;//初始化标志位，表示还没有创建下拉列表框
	RECT  m_rect;

	m_list_liquidAttr.GetClientRect(&m_rect); //获取list的客户区,方便调节每一列的宽度

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
	//m_toolbar.Create(this);
	//// 将变量与创建的Toolbar资源绑定
	//m_toolbar.LoadToolBar(IDR_STUFF_TOOLBAR);
	//RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Dlg_Attribute::OnNMCustomdrawListAttribute(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (flagnum > 0)
	{
		flagnum = 0;
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_liquidAttr, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_liquidAttr, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	*pResult = 0;
}


void Dlg_Attribute::OnNMDblclkListAttribute(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
}


void Dlg_Attribute::OnBnClickedButtonSave()
{
	// TODO: 在此添加控件通知处理程序代码
	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
	{
		distroyCcombobox(&m_list_liquidAttr, &m_comBox, e_Item, e_SubItem);
		haveccomboboxcreate = false;
	}
	int i = k;
	while (i > 0)
	{

		mc = m_list_liquidAttr.GetItemText(hang[i - 1], 0);
		nd = m_list_liquidAttr.GetItemText(hang[i - 1], 1);
		jzry = m_list_liquidAttr.GetItemText(hang[i - 1], 3);
		xygcxry = m_list_liquidAttr.GetItemText(hang[i - 1], 4);
		zczrry = m_list_liquidAttr.GetItemText(hang[i - 1], 5);
		SaveToDatabase();
		i--;
	}
	hang[10000] = {};
	k = 0;
	CheckData();
}


void Dlg_Attribute::OnBnClickedButtonRefresh()
{
	// TODO: 在此添加控件通知处理程序代码
	hang[10000] = {};
	k = 0;
	CheckData();
}
