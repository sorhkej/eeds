// DIALOG_FUNC.cpp : 实现文件
//

#include "stdafx.h"
#include "eeds.h"
#include "DIALOG_FUNC.h"
#include "afxdialogex.h"


// DIALOG_FUNC 对话框

IMPLEMENT_DYNAMIC(DIALOG_FUNC, CDialogEx)

DIALOG_FUNC::DIALOG_FUNC(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_FUNC, pParent)
{

}

DIALOG_FUNC::~DIALOG_FUNC()
{
}

void DIALOG_FUNC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FORM, m_list_for);
	DDX_Control(pDX, IDC_LIST_LIQU, m_list_liqu);
}


BEGIN_MESSAGE_MAP(DIALOG_FUNC, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST_FORM, &DIALOG_FUNC::OnNMClickListForm)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_FORM, &DIALOG_FUNC::OnNMCustomdrawListForm)
END_MESSAGE_MAP()


// DIALOG_FUNC 消息处理程序


void DIALOG_FUNC::OnNMClickListForm(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	if (formulaNum == 1)
	{
		CheckData();
		formulaNum = 0;
	}
	if (pEditCtrl->iItem == -1)//点击到非工作区
	{

	}
	else
	{
		float nongdu, weight;
		CString nD, wT;
		dm = m_list_for.GetItemText(pEditCtrl->iItem, 0);
		mc = m_list_for.GetItemText(pEditCtrl->iItem, 1);
		wT = m_list_for.GetItemText(pEditCtrl->iItem, 4);
		weight = _ttof(wT);
		SearchData();

		m_list_liqu.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
			| LVS_EX_FULLROWSELECT
			| LVS_EX_HEADERDRAGDROP
			| LVS_EX_ONECLICKACTIVATE
			| LVS_EX_GRIDLINES);
		while (m_list_liqu.DeleteColumn(0));	//清空所有表头
		m_list_liqu.DeleteAllItems();

		CFont m_font;
		m_font.CreatePointFont(100, _T("微软雅黑"));
		m_list_liqu.SetFont(&m_font);

		m_list_liqu.InsertColumn(0, _T("化工料"), LVCFMT_LEFT, 200, 2);         //为列表加入四列：姓名，手机号码，关系，备注
		m_list_liqu.InsertColumn(1, _T("配方重量[g]"), LVCFMT_LEFT, 200, 2);
		m_list_liqu.InsertColumn(2, _T("配方代码"), LVCFMT_LEFT, 150, 2);
		m_list_liqu.InsertColumn(3, _T("配方名称"), LVCFMT_LEFT, 100, 2);
		m_list_liqu.InsertColumn(4, _T("配方浓度"), LVCFMT_LEFT, 100, 2);
		m_list_liqu.InsertColumn(5, _T("配方单位"), LVCFMT_LEFT, 100, 2);

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
			m_list_liqu.InsertItem(i - 1, _T(""));
			m_list_liqu.SetItemText(i - 1, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_variant_t(xl)));
			nD = m_pRecordset->GetCollect(_variant_t(nd));
			m_list_liqu.SetItemText(i - 1, 4, nD);
			nongdu = _tstof(nD);
			nd.Format(_T("%f"), nongdu*weight*0.01);
			m_list_liqu.SetItemText(i - 1, 1, nd);
			m_list_liqu.SetItemText(i - 1, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("代码")));
			m_list_liqu.SetItemText(i - 1, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("名称")));
			m_list_liqu.SetItemText(i - 1, 5, _T("%"));

			i++;
		}
	}

	*pResult = 0;
}


void DIALOG_FUNC::OnNMCustomdrawListForm(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (functionNum == 1)
	{
		CheckData();
		functionNum = 0;
	}
	*pResult = 0;
}


BOOL DIALOG_FUNC::OnInitDialog()
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
	CheckData();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

_RecordsetPtr& DIALOG_FUNC::GetRecordSet(_bstr_t bstrSQL)           //打开记录集，初始化Listcontrol控件关于数据库内容
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

void DIALOG_FUNC::CheckData()//对数据库进行查询操做
{
	CString sql;
	sql.Format(_T("select* from Formula_Position order by 代码 desc "));            //使用sql代表SQL语句表名为contact。通过列“手机号码”按升序排列（asc），按降序排列（desc）
	GetRecordSet((_bstr_t)sql);




	m_list_for.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_for.DeleteColumn(0));	//清空所有表头
	m_list_for.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("微软雅黑"));
	m_list_for.SetFont(&m_font);

	m_list_for.InsertColumn(0, _T("代码"), LVCFMT_LEFT, 200, 2);
	m_list_for.InsertColumn(1, _T("名称"), LVCFMT_LEFT, 200, 2);
	m_list_for.InsertColumn(2, _T("备注"), LVCFMT_LEFT, 300, 2);
	m_list_for.InsertColumn(3, _T("配送位置"), LVCFMT_LEFT, 300, 2);
	m_list_for.InsertColumn(4, _T("重量[g]"), LVCFMT_LEFT, 300, 2);
	m_list_for.InsertColumn(5, _T("容量[l]"), LVCFMT_LEFT, 300, 2);

	
		m_pRecordset->MoveFirst();
		CString temp;
		while (m_pRecordset->adoEOF == 0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
		{
			
			temp = m_pRecordset->GetCollect(_T("代码"));
			if ( temp != _T("")) 
			{
				m_list_for.InsertItem(0, _T(""));
				m_list_for.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("代码")));
				m_list_for.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("名称")));
				m_list_for.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("备注")));
				m_list_for.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("位置")));
				m_list_for.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("重量")));
				m_list_for.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("容量")));
				
			}
			m_pRecordset->MoveNext();
		}
	}


void DIALOG_FUNC::SearchData()
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Search_Formula";//存储过程为Corn_ADD
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

void DIALOG_FUNC::DeleteData()
{
	m_pCommand.CreateInstance("ADODB.Command");//实例
	m_pCommand->ActiveConnection = m_pConnection;//设置连接，别忘了啊
	m_pCommand->CommandText = "Delete_Formula_Detailed";//存储过程为Corn_ADD
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

		/*	_ParameterPtr Param_bz;
		Param_bz.CreateInstance("ADODB.Parameter");
		Param_bz = m_pCommand->CreateParameter("@备注", adVarWChar, adParamInput, 50, (_variant_t)bz);
		m_pCommand->Parameters->Append(Param_bz);

		_ParameterPtr Param_zl;
		Param_zl.CreateInstance("ADODB.Parameter");
		Param_zl = m_pCommand->CreateParameter("@重量", adVarWChar, adParamInput, 50, (_variant_t)zl);
		m_pCommand->Parameters->Append(Param_zl);*/


		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);

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