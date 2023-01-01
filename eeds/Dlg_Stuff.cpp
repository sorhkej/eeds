// Dlg_Stuff.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Stuff.h"
#include "afxdialogex.h"
//#include"Dlg_Item.h"

// Dlg_Stuff 对话框

IMPLEMENT_DYNAMIC(Dlg_Stuff, CDialogEx)

Dlg_Stuff::Dlg_Stuff(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_STUFF, pParent)
{

}

Dlg_Stuff::~Dlg_Stuff()
{
}

#define IDC_EDIT_CREATEID  3000//用于定义List 
#define IDC_COMBOX_CREATEID  3000//用于下拉列表


void Dlg_Stuff::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STUFF, m_list_stuff);
}


BEGIN_MESSAGE_MAP(Dlg_Stuff, CDialogEx)

	ON_NOTIFY(NM_CLICK, IDC_LIST_STUFF, &Dlg_Stuff::OnNMClickListStuff)
	ON_COMMAND(TB_STUFF_DELETE, &Dlg_Stuff::OnTbStuffDelete)
	ON_COMMAND(TB_STUFF_REFRESH, &Dlg_Stuff::OnTbStuffRefresh)
	ON_COMMAND(TB_STUFF_SAVE, &Dlg_Stuff::OnTbStuffSave)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_STUFF, &Dlg_Stuff::OnNMCustomdrawListStuff)
	ON_WM_CLOSE()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_STUFF, &Dlg_Stuff::OnNMDblclkListStuff)
	ON_COMMAND(TB_STUFF_NEW, &Dlg_Stuff::OnTbStuffNew)
END_MESSAGE_MAP()


// Dlg_Stuff 消息处理程序


BOOL Dlg_Stuff::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	haveeditcreate = false;//初始化标志位，表示还没有创建编辑框
	haveccomboboxcreate = false;//初始化标志位，表示还没有创建下拉列表框
	RECT  m_rect;

	m_list_stuff.GetClientRect(&m_rect); //获取list的客户区,方便调节每一列的宽度

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

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void Dlg_Stuff::CheckData()//对数据库进行查询操做
{
	CString sql;
	sql.Format(_T("select* from Stuff order by 代码 desc"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);

	rnum = 0;
	Rgb[10000] = {};

	m_list_stuff.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_stuff.DeleteColumn(0));	//清空所有表头
	m_list_stuff.DeleteAllItems();
	//CImageList   m_l;
	//m_l.Create(18, 18, TRUE | ILC_COLOR32, 1, 0);
	//m_list_stuff.SetImageList(&m_l, LVSIL_SMALL);
	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_list_stuff.SetFont(&m_font);

	m_list_stuff.InsertColumn(0, _T("代码"), LVCFMT_LEFT, 200,2 );         //为列表加入四列：姓名，手机号码，关系，备注
	m_list_stuff.InsertColumn(1, _T("名称"), LVCFMT_LEFT, 200, 2);
	m_list_stuff.InsertColumn(2, _T("化工料类型"), LVCFMT_LEFT, 150, 4);
	m_list_stuff.InsertColumn(3, _T("密度g/L"), LVCFMT_LEFT, 100, 2);
	m_list_stuff.InsertColumn(4, _T("化工料列表"), LVCFMT_LEFT, 150, 4);
	m_list_stuff.InsertColumn(5, _T("单位"), LVCFMT_LEFT, 100, 2);
	m_list_stuff.InsertColumn(6, _T("颜色"), LVCFMT_LEFT, 200, 2);

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
		m_list_stuff.InsertItem(0, _T(""));
		m_list_stuff.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("代码")));
		m_list_stuff.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("名称")));      //记录集选择的列表名在数据库中必须能够找到，不然出错。
		m_list_stuff.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("化工料类型")));
		m_list_stuff.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("密度")));
		m_list_stuff.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("化工料列表")));
		m_list_stuff.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("单位")));
		//m_list_stuff.SetItemText(0, 6, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("颜色")));

		Rgb[sum - rnum] = m_pRecordset->GetCollect(_T("颜色"));
		m_pRecordset->MoveNext();
		rnum++;
	}
	//sum = rnum-1;
	//rnum++;

	m_pRecordset->MoveFirst();

	m_list_stuff.InsertItem(sum + 1, _T(""));
	//////m_list_stuff.SetItemText(sum+1, 0, _T(""));
	//////m_list_stuff.SetItemText(sum+1, 1, _T(""));
	//////m_list_stuff.SetItemText(sum+1, 2, _T(""));
	//////m_list_stuff.SetItemText(sum+1, 3, _T(""));
	//////m_list_stuff.SetItemText(sum+1, 4, _T(""));
	//////m_list_stuff.SetItemText(sum+1, 5, _T(""));
	Rgb[sum + 1] = 16777215;
}

_RecordsetPtr& Dlg_Stuff::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
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

void Dlg_Stuff::OnNMClickListStuff(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//点击到非工作区
	{
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if (pEditCtrl->iSubItem != 2 && pEditCtrl->iSubItem != 4 && pEditCtrl->iSubItem != 5 && pEditCtrl->iSubItem != 6)//如果不是性别选项
	{
	//	hang[k] = pEditCtrl->iItem;
	//	lie[k] = pEditCtrl->iSubItem;
	//	k++;
	//	m_list_stuff.SetFocus();
	//	m_list_stuff.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	//	if (haveccomboboxcreate == true)//如果之前创建了编辑框就销毁掉
	//	{
	//		distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
	//		haveccomboboxcreate = false;
	//	}
	//	if (haveeditcreate == true)
	//	{
	//		if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
	//		{
	//			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
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
	}
	else if (pEditCtrl->iSubItem == 2)//如果是性别选项
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
				m_comBox.AddString(L"AUXL");
				m_comBox.AddString(L"COLP");
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
			m_comBox.AddString(L"AUXL");
			m_comBox.AddString(L"COLP");
			m_comBox.ShowDropDown();//自动下拉
		}
	}
	else if (pEditCtrl->iSubItem == 4)//如果是性别选项
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
				m_comBox.AddString(L"B");
				m_comBox.AddString(L"");
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
			m_comBox.AddString(L"B");
			m_comBox.AddString(L"");
			m_comBox.ShowDropDown();//自动下拉
		}
	}
	else if (pEditCtrl->iSubItem == 5)//如果是性别选项
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
				m_comBox.AddString(L"cc");
				m_comBox.AddString(L"g");
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
			m_comBox.AddString(L"cc");
			m_comBox.AddString(L"g");
			m_comBox.ShowDropDown();//自动下拉
		}
	}
	else /*if (pEditCtrl->iSubItem == 6)*///如果是性别选项
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		COLORREF color;      // 颜色对话框的初始颜色为红色   
		CColorDialog colorDlg;         // 构造颜色对话框，传入初始颜色值   
		if (IDOK == colorDlg.DoModal())       // 显示颜色对话框，并判断是否点击了“确定”   
		{
			color = colorDlg.GetColor();      // 获取颜色对话框中选择的颜色值   
			Rgb[pEditCtrl->iItem] = color;
			SetDlgItemInt(IDC_EDIT1, color);
		}

	}


	*pResult = 0;
}

void Dlg_Stuff::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)//创建单元格编辑框函数
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, IDC_EDIT_CREATEID);//创建编辑框对象,IDC_EDIT_CREATEID为控件ID号3000，在文章开头定义
	havecreat = true;
	createdit->SetFont(&m_font);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createdit->SetParent(&m_list_stuff);//将list control设置为父窗口,生成的Edit才能正确定位,这个也很重要
	CRect  EditRect;
	m_list_stuff.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_stuff.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_list_stuff.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createdit->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createdit->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createdit->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
	createdit->SetFocus();//设置为焦点 
	createdit->SetSel(-1);//设置光标在文本框文字的最后
}

void Dlg_Stuff::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//获得相应单元格字符
	distroyedit->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}

void Dlg_Stuff::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)//创建单元格下拉列表框函数
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, IDC_COMBOX_CREATEID);
	createccomboboxobj->SetFont(&m_font);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createccomboboxobj->SetParent(&m_list_stuff);//将list control设置为父窗口,生成的Ccombobox才能正确定位,这个也很重要
	CRect  EditRect;
	m_list_stuff.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_stuff.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_list_stuff.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createccomboboxobj->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createccomboboxobj->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createccomboboxobj->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
}

void Dlg_Stuff::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//更新相应单元格字符
	distroyccomboboxobj->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}

void Dlg_Stuff::OnTbStuffDelete()
{
	// TODO: 在此添加命令处理程序代码
	if(haveeditcreate == true)//如果之前创建了编辑框就销毁掉
	{
		distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
	{
		distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
		haveccomboboxcreate = false;
	}
	//int i = k - 1;
	//while (i> 0)
	//{
	//	if (m_list_stuff.GetItemText(hang[i - 1], 0) == (""))
	//	{
	//		break;
	//	}
	//	//else
	//	//{
	//	//	dm = m_list_stuff.GetItemText(hang[i - 1], 0);
	//	//	mc = m_list_stuff.GetItemText(hang[i - 1], 1);
	//	//	hgllx = m_list_stuff.GetItemText(hang[i - 1], 2);
	//	//	md = m_list_stuff.GetItemText(hang[i - 1], 3);
	//	//	hgllb = m_list_stuff.GetItemText(hang[i - 1], 4);
	//	//	dw = m_list_stuff.GetItemText(hang[i - 1], 5);
	//	//	ys.Format(_T("%d"), Rgb[hang[i - 1]]);
	//	//	SaveToDatabase();
	//	//}
	//	i--;
	//}
	dm = m_list_stuff.GetItemText(hang[k - 1], 0);
	hang[10000] = {};
	k = 0;
	DeleteData();
	CheckData();
}


void Dlg_Stuff::OnTbStuffRefresh()
{
	// TODO: 在此添加命令处理程序代码
	CheckData();
}


void Dlg_Stuff::OnTbStuffSave()
{
	// TODO: 在此添加命令处理程序代码
	if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
	{
		distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
	{
		distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
		haveccomboboxcreate = false;
	}
	int i = k;
	while (i> 0)
	{
		if (m_list_stuff.GetItemText(hang[i - 1], 0) == (""))
		{
			break;
		}
		else
		{
			dm = m_list_stuff.GetItemText(hang[i - 1], 0);
			mc = m_list_stuff.GetItemText(hang[i - 1], 1);
			hgllx = m_list_stuff.GetItemText(hang[i - 1], 2);
			md = m_list_stuff.GetItemText(hang[i - 1], 3);
			hgllb = m_list_stuff.GetItemText(hang[i - 1], 4);
			dw = m_list_stuff.GetItemText(hang[i - 1], 5);
			ys.Format(_T("%d"), Rgb[hang[i - 1]]);
			SaveToDatabase();
		}
		i--;
	}
	hang[10000] = {};
	k = 0;
	CheckData();
}


void Dlg_Stuff::OnNMCustomdrawListStuff(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);
	if (CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage)
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if (CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage)
	{
		*pResult = CDRF_NOTIFYSUBITEMDRAW;
	}
	else if ((CDDS_ITEMPREPAINT | CDDS_SUBITEM) == pLVCD->nmcd.dwDrawStage)
	{
		int nItem = static_cast<int>(pLVCD->nmcd.dwItemSpec);
		//CString strTemp = m_list.GetItemText(nItem, 2);
		for (int i = 0; i <= nItem; i++)
		{
			if (pLVCD->iSubItem == 6)//这里是选择每一行的第7列
			{
				COLORREF clrNewTextColor, clrNewBkColor;
				clrNewBkColor = Rgb[nItem];
				pLVCD->clrTextBk = clrNewBkColor;
				*pResult = CDRF_DODEFAULT;
				//m_pRecordset->MoveNext();
			}
			else
			{
				/*pLVCD->clrText = RGB(0, 0, 0);
				pLVCD->clrTextBk = RGB(255, 255, 255);*/
				*pResult = CDRF_DODEFAULT;
				break;
			}
		}

		//*pResult = CDRF_NEWFONT;

	}
}

void Dlg_Stuff::DeleteData()//将数据按照每一行单行写入数据库到时候调用此函数就好
{
	////AfxOleInit();
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Delete_Stuff";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_dempono;
		Param_dempono.CreateInstance("ADODB.Parameter");
		Param_dempono = m_pCommand->CreateParameter("@代码", adVarWChar, adParamInput, 50, (_variant_t)dm);
		m_pCommand->Parameters->Append(Param_dempono);

		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}


void Dlg_Stuff::SaveToDatabase()//将数据按照每一行单行写入数据库到时候调用此函数就好
{
	////AfxOleInit();
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Add_Stuff";//存储过程为Corn_ADD
	try
	{
		_ParameterPtr Param_dempono;
		Param_dempono.CreateInstance("ADODB.Parameter");
		Param_dempono = m_pCommand->CreateParameter("@代码", adVarWChar, adParamInput, 50, (_variant_t)dm);
		m_pCommand->Parameters->Append(Param_dempono);

		_ParameterPtr Param_dempname;
		Param_dempname.CreateInstance("ADODB.Parameter");
		Param_dempname = m_pCommand->CreateParameter("@名称", adVarWChar, adParamInput, 50, (_variant_t)mc);
		m_pCommand->Parameters->Append(Param_dempname);

		_ParameterPtr Param_location;
		Param_location.CreateInstance("ADODB.Parameter");
		Param_location = m_pCommand->CreateParameter("@化工料类型", adVarWChar, adParamInput, 50, (_variant_t)hgllx);
		m_pCommand->Parameters->Append(Param_location);

		_ParameterPtr Param_md;
		Param_md.CreateInstance("ADODB.Parameter");
		Param_md = m_pCommand->CreateParameter("@密度", adVarChar, adParamInput, 50, (_variant_t)md);
		m_pCommand->Parameters->Append(Param_md);

		_ParameterPtr Param_hgllb;
		Param_hgllb.CreateInstance("ADODB.Parameter");
		Param_hgllb = m_pCommand->CreateParameter("@化工料列表", adVarWChar, adParamInput, 50, (_variant_t)hgllb);
		m_pCommand->Parameters->Append(Param_hgllb);

		_ParameterPtr Param_dw;
		Param_dw.CreateInstance("ADODB.Parameter");
		Param_dw = m_pCommand->CreateParameter("@单位", adVarWChar, adParamInput, 50, (_variant_t)dw);
		m_pCommand->Parameters->Append(Param_dw);

		_ParameterPtr Param_ys;
		Param_ys.CreateInstance("ADODB.Parameter");
		Param_ys = m_pCommand->CreateParameter("@颜色", adVarChar, adParamInput, 50, (_variant_t)ys);
		m_pCommand->Parameters->Append(Param_ys);

		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}

void Dlg_Stuff::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ExitConn();
	hang[10000] = {};
	k = 0;
	CDialogEx::OnClose();
}

BOOL Dlg_Stuff::ExitConn()
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


void Dlg_Stuff::OnNMDblclkListStuff(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//点击到非工作区
	{
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if (pEditCtrl->iSubItem != 2 && pEditCtrl->iSubItem != 4 && pEditCtrl->iSubItem != 5 && pEditCtrl->iSubItem != 6)//如果不是性别选项
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		m_list_stuff.SetFocus();
		m_list_stuff.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		if (haveccomboboxcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
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
	else if (pEditCtrl->iSubItem == 2)//如果是性别选项
	{
		//hang[k] = pEditCtrl->iItem;
		//lie[k] = pEditCtrl->iSubItem;
		//k++;
		//if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		//{
		//	distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
		//	haveeditcreate = false;
		//}
		//if (haveccomboboxcreate == true)
		//{
		//	if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
		//	{
		//		distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
		//		haveccomboboxcreate = false;
		//		createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
		//		m_comBox.AddString(L"AUXL");
		//		m_comBox.AddString(L"COLP");
		//		m_comBox.ShowDropDown();//自动下拉
		//	}
		//	else//点中的单元格是之前创建好的
		//	{
		//		m_comBox.SetFocus();//设置为焦点 
		//	}
		//}
		//else
		//{
		//	e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
		//	e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
		//	createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
		//	m_comBox.AddString(L"AUXL");
		//	m_comBox.AddString(L"COLP");
		//	m_comBox.ShowDropDown();//自动下拉
		//}
	}
	else if (pEditCtrl->iSubItem == 4)//如果是性别选项
	{
		//hang[k] = pEditCtrl->iItem;
		//lie[k] = pEditCtrl->iSubItem;
		//k++;
		//if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		//{
		//	distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
		//	haveeditcreate = false;
		//}
		//if (haveccomboboxcreate == true)
		//{
		//	if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
		//	{
		//		distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
		//		haveccomboboxcreate = false;
		//		createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
		//		m_comBox.AddString(L"B");
		//		m_comBox.AddString(L"");
		//		m_comBox.ShowDropDown();//自动下拉
		//	}
		//	else//点中的单元格是之前创建好的
		//	{
		//		m_comBox.SetFocus();//设置为焦点 
		//	}
		//}
		//else
		//{
		//	e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
		//	e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
		//	createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
		//	m_comBox.AddString(L"B");
		//	m_comBox.AddString(L"");
		//	m_comBox.ShowDropDown();//自动下拉
		//}
	}
	else if (pEditCtrl->iSubItem == 5)//如果是性别选项
	{
		//hang[k] = pEditCtrl->iItem;
		//lie[k] = pEditCtrl->iSubItem;
		//k++;
		//if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		//{
		//	distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
		//	haveeditcreate = false;
		//}
		//if (haveccomboboxcreate == true)
		//{
		//	if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
		//	{
		//		distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
		//		haveccomboboxcreate = false;
		//		createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
		//		m_comBox.AddString(L"cc");
		//		m_comBox.AddString(L"g");
		//		m_comBox.ShowDropDown();//自动下拉
		//	}
		//	else//点中的单元格是之前创建好的
		//	{
		//		m_comBox.SetFocus();//设置为焦点 
		//	}
		//}
		//else
		//{
		//	e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
		//	e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
		//	createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
		//	m_comBox.AddString(L"cc");
		//	m_comBox.AddString(L"g");
		//	m_comBox.ShowDropDown();//自动下拉
		//}
	}
	else /*if (pEditCtrl->iSubItem == 6)*///如果是性别选项
	{
		//hang[k] = pEditCtrl->iItem;
		//lie[k] = pEditCtrl->iSubItem;
		//k++;
		//COLORREF color;      // 颜色对话框的初始颜色为红色   
		//CColorDialog colorDlg;         // 构造颜色对话框，传入初始颜色值   
		//if (IDOK == colorDlg.DoModal())       // 显示颜色对话框，并判断是否点击了“确定”   
		//{
		//	color = colorDlg.GetColor();      // 获取颜色对话框中选择的颜色值   
		//	Rgb[pEditCtrl->iItem] = color;
		//	SetDlgItemInt(IDC_EDIT1, color);
		//}

	}

	*pResult = 0;
}


void Dlg_Stuff::OnTbStuffNew()
{
	// TODO: 在此添加命令处理程序代码
	int nItem = m_list_stuff.GetItemCount();
	//m_list_form.SetItemState(6, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	m_list_stuff.SetItemState(nItem - 1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_list_stuff.EnsureVisible(nItem - 1, FALSE);
}
