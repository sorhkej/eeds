// DIALOG_LIQU.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "DIALOG_LIQU.h"
#include "afxdialogex.h"
#include "DIALOG_POSI.h"

// DIALOG_LIQU 对话框


extern CString asdasd;


IMPLEMENT_DYNAMIC(DIALOG_LIQU, CDialogEx)

DIALOG_LIQU::DIALOG_LIQU(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_LIQU, pParent)
{

}

DIALOG_LIQU::~DIALOG_LIQU()
{
}

void DIALOG_LIQU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_POS, m_list_pos);
}


BEGIN_MESSAGE_MAP(DIALOG_LIQU, CDialogEx)
END_MESSAGE_MAP()


// DIALOG_LIQU 消息处理程序


BOOL DIALOG_LIQU::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//MessageBox(asdasd);
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
	CheckData();



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

_RecordsetPtr& DIALOG_LIQU::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
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

void DIALOG_LIQU::CheckData()//对数据库进行查询操做
{
	CString sql;
	sql.Format(_T("select* from Position  order by 瓶子 desc"));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);



	//rnum = 0;

	m_list_pos.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_pos.DeleteColumn(0));	//清空所有表头
	m_list_pos.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_list_pos.SetFont(&m_font);

	m_list_pos.InsertColumn(0, _T("瓶子"), LVCFMT_LEFT, 200, 2);         //为列表加入四列：姓名，手机号码，关系，备注
	m_list_pos.InsertColumn(1, _T("溶液"), LVCFMT_LEFT, 200, 2);
	m_list_pos.InsertColumn(2, _T("浓度"), LVCFMT_LEFT, 150, 2);
	m_list_pos.InsertColumn(3, _T("容积"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(4, _T("时间"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(5, _T("状态"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(6, _T("终止时间"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(7, _T("最小称重量"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(8, _T("最小容积"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(9, _T("最大容积"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(10, _T("实际容积"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(11, _T("皮重"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(12, _T("预备容积"), LVCFMT_LEFT, 100, 2);


	m_pRecordset->MoveFirst();
	//while (m_pRecordset->adoEOF == 0)
	//{
	//	rnum++;
	//	m_pRecordset->MoveNext();
	//}
	//sum = rnum - 1;
	//rnum = 0;
	//m_pRecordset->MoveFirst();

	while (m_pRecordset->adoEOF == 0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		CString ry = m_pRecordset->GetCollect(_T("溶液"));
		if(ry != _T(""))
		{
			m_list_pos.InsertItem(0, _T(""));
			m_list_pos.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("瓶子")));
			m_list_pos.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("溶液")));      //记录集选择的列表名在数据库中必须能够找到，不然出错。
			m_list_pos.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("容积")));
			m_list_pos.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("时间")));
			m_list_pos.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("状态")));
			m_list_pos.SetItemText(0, 6, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("终止时间")));
			m_list_pos.SetItemText(0, 7, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("最小称重量")));
			m_list_pos.SetItemText(0, 8, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("最小容积")));
			m_list_pos.SetItemText(0, 9, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("最大容积")));
			m_list_pos.SetItemText(0, 10, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("实际容积")));
			m_list_pos.SetItemText(0, 11, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("皮重")));
			m_list_pos.SetItemText(0, 12, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("预备容积")));
		}
		else
		{
		}
		m_pRecordset->MoveNext();
	}
	//sum = rnum-1;
	//rnum++;

	m_pRecordset->MoveFirst();

	//m_list_pos.InsertItem(sum + 1, _T(""));
	//////m_list_pos.SetItemText(sum+1, 0, _T(""));
	//////m_list_pos.SetItemText(sum+1, 1, _T(""));
	//////m_list_pos.SetItemText(sum+1, 2, _T(""));
	//////m_list_pos.SetItemText(sum+1, 3, _T(""));
	//////m_list_pos.SetItemText(sum+1, 4, _T(""));
	//////m_list_pos.SetItemText(sum+1, 5, _T(""));
}