// Dlg_Liquid.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Liquid.h"
#include "afxdialogex.h"
#include "NEWLISTCTRL.h"
#define IDC_EDIT_CREATEID  3001//���ڶ���List 
#define IDC_COMBOX_CREATEID  3002//���������б�

// Dlg_Liquid �Ի���

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


// Dlg_Liquid ��Ϣ�������


BOOL Dlg_Liquid::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	haveeditcreate = false;//��ʼ����־λ����ʾ��û�д����༭��
	haveccomboboxcreate = false;//��ʼ����־λ����ʾ��û�д��������б��
	RECT  m_rect;

	m_list_liquid.GetClientRect(&m_rect); //��ȡlist�Ŀͻ���,�������ÿһ�еĿ��
	CoInitialize(NULL);
	m_pConnection.CreateInstance(__uuidof(Connection));
	try
	{
		m_pConnection->Open("driver={SQL Server};Server=127.0.0.1;Database=Eeds;UID=sa;PWD=123456", "", "", adModeUnknown);
	}
	catch (_com_error e)//��׽�쳣
	{
		CString errormessage;
		errormessage.Format(_T("�������ݿ�ʧ�ܣ�������Ϣ��%s"), e.ErrorMessage());
		AfxMessageBox(errormessage);//��ʾ������Ϣ 
	}


	CheckData();
	m_toolbar.Create(this);
	// �������봴����Toolbar��Դ��
	m_toolbar.LoadToolBar(IDR_STUFF_TOOLBAR);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);


	//m_list_liquid.SendMessage(WM_HSCROLL, SB_BOTTOM, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void Dlg_Liquid::OnTbLiquidDelete()
{
	// TODO: �ڴ���������������
	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
	{
		distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	// TODO: �ڴ���������������
	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
	{
		distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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


	// TODO: �ڴ���������������
	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
	{
		distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ExitConn();
	hang[10000] = {};
	k = 0;
	CDialogEx::OnClose();
}



void Dlg_Liquid::OnNMCustomdrawListLiquid(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (flagnum > 0)
	{
		flagnum=0;
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
		{
			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	*pResult = 0;
}

BOOL Dlg_Liquid::ExitConn()
{
	//�رռ�¼��������
	if (m_pRecordset != NULL)
	{
		m_pRecordset->Close();
	}
	m_pRecordset = NULL;
	m_pConnection->Close();
	::CoUninitialize(); //�������Ϊ�ر�COM�����

	return TRUE;
}

void Dlg_Liquid::CheckData()//�����ݿ���в�ѯ����
{
	CString sql;
	sql.Format(_T("select* from Liquid order by ���� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);

	m_list_liquid.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_liquid.DeleteColumn(0));	//������б�ͷ
	m_list_liquid.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_list_liquid.SetFont(&m_font);

	m_list_liquid.InsertColumn(0, _T("������"), LVCFMT_LEFT, 200, 2);         //Ϊ�б�������У��������ֻ����룬��ϵ����ע
	m_list_liquid.InsertColumn(1, _T("Ũ��"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(2, _T("��Һ�ݻ�"), LVCFMT_LEFT, 150, 2);
	m_list_liquid.InsertColumn(3, _T("��Һʵ���ݻ�"), LVCFMT_LEFT, 100, 2);
	m_list_liquid.InsertColumn(4, _T("��С������"), LVCFMT_LEFT, 150, 2);
	m_list_liquid.InsertColumn(5, _T("���������"), LVCFMT_LEFT, 100, 2);
	m_list_liquid.InsertColumn(6, _T("��С�ݻ�"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(7, _T("����ݻ�"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(8, _T("Ĭ���ݻ�"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(9, _T("��ú����[h]"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(10, _T("��һ���Ƿ����ˮ"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(11, _T("�ڶ����Ƿ����ˮ"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(12, _T("��һ��ע����"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(13, _T("����ʱ��[s]"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(14, _T("��ϴ��Һ��"), LVCFMT_LEFT, 200, 2);
	m_list_liquid.InsertColumn(15, _T("��Һ�ܳ�ϴ��Һ"), LVCFMT_LEFT, 200, 2);



	m_pRecordset->MoveFirst();
	while (m_pRecordset->adoEOF == 0)
	{
		rnum++;
		m_pRecordset->MoveNext();
	}
	sum = rnum - 1;
	rnum = 0;
	m_pRecordset->MoveFirst();

	while (m_pRecordset->adoEOF == 0)                   //���δ��������¼�����һ�У���Ϊ�б�����Ӽ����������ݡ�������¼����
	{
		m_list_liquid.InsertItem(0, _T(""));
		m_list_liquid.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
		m_list_liquid.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("Ũ��")));      //��¼��ѡ����б��������ݿ��б����ܹ��ҵ�����Ȼ����
		m_list_liquid.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��Һ�ݻ�")));
		m_list_liquid.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��Һʵ���ݻ�")));
		m_list_liquid.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��С������")));
		m_list_liquid.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("���������")));
		m_list_liquid.SetItemText(0, 6, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��С�ݻ�")));
		m_list_liquid.SetItemText(0, 7, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����ݻ�")));
		m_list_liquid.SetItemText(0, 8, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("Ĭ���ݻ�")));
		m_list_liquid.SetItemText(0, 9, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��ú���ֹ")));
		m_list_liquid.SetItemText(0, 10, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��һ���Ƿ����ˮ")));
		m_list_liquid.SetItemText(0, 11, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("�ڶ����Ƿ����ˮ")));
		m_list_liquid.SetItemText(0, 12, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��һ��ע����")));
		m_list_liquid.SetItemText(0, 13, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����ʱ��")));
		m_list_liquid.SetItemText(0, 14, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��ϴ��Һ��")));
		m_list_liquid.SetItemText(0, 15, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��Һ�ܳ�ϴ��Һ")));
	

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

void Dlg_Liquid::DeleteData()//�����ݰ���ÿһ�е���д�����ݿ⵽ʱ����ô˺����ͺ�
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Delete_Liquid";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_mc;
		Param_mc.CreateInstance("ADODB.Parameter");
		Param_mc = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)mc);
		m_pCommand->Parameters->Append(Param_mc);

		_ParameterPtr Param_nd;
		Param_nd.CreateInstance("ADODB.Parameter");
		Param_nd = m_pCommand->CreateParameter("@Ũ��", adVarWChar, adParamInput, 50, (_variant_t)nd);
		m_pCommand->Parameters->Append(Param_nd);

		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}

void Dlg_Liquid::SaveToDatabase()//�����ݰ���ÿһ�е���д�����ݿ⵽ʱ����ô˺����ͺ�
{



	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Add_Liquid";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_mc;
		Param_mc.CreateInstance("ADODB.Parameter");
		Param_mc = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)mc);
		m_pCommand->Parameters->Append(Param_mc);

		_ParameterPtr Param_nd;
		Param_nd.CreateInstance("ADODB.Parameter");
		Param_nd = m_pCommand->CreateParameter("@Ũ��", adVarWChar, adParamInput, 50, (_variant_t)nd);
		m_pCommand->Parameters->Append(Param_nd);

		_ParameterPtr Param_ryrj;
		Param_ryrj.CreateInstance("ADODB.Parameter");
		Param_ryrj = m_pCommand->CreateParameter("@��Һ�ݻ�", adVarWChar, adParamInput, 50, (_variant_t)ryrj);
		m_pCommand->Parameters->Append(Param_ryrj);

		_ParameterPtr Param_rysjrj;
		Param_rysjrj.CreateInstance("ADODB.Parameter");
		Param_rysjrj = m_pCommand->CreateParameter("@��Һʵ���ݻ�", adVarChar, adParamInput, 50, (_variant_t)rysjrj);
		m_pCommand->Parameters->Append(Param_rysjrj);

		_ParameterPtr Param_zxpsl;
		Param_zxpsl.CreateInstance("ADODB.Parameter");
		Param_zxpsl = m_pCommand->CreateParameter("@��С������", adVarWChar, adParamInput, 50, (_variant_t)zxpsl);
		m_pCommand->Parameters->Append(Param_zxpsl);

		_ParameterPtr Param_zdpsl;
		Param_zdpsl.CreateInstance("ADODB.Parameter");
		Param_zdpsl = m_pCommand->CreateParameter("@���������", adVarWChar, adParamInput, 50, (_variant_t)zdpsl);
		m_pCommand->Parameters->Append(Param_zdpsl);

		_ParameterPtr Param_zxrj;
		Param_zxrj.CreateInstance("ADODB.Parameter");
		Param_zxrj = m_pCommand->CreateParameter("@��С�ݻ�", adVarChar, adParamInput, 50, (_variant_t)zxrj);
		m_pCommand->Parameters->Append(Param_zxrj);

		_ParameterPtr Param_zdrj;
		Param_zdrj.CreateInstance("ADODB.Parameter");
		Param_zdrj = m_pCommand->CreateParameter("@����ݻ�", adVarChar, adParamInput, 50, (_variant_t)zdrj);
		m_pCommand->Parameters->Append(Param_zdrj);

		_ParameterPtr Param_mrrj;
		Param_mrrj.CreateInstance("ADODB.Parameter");
		Param_mrrj = m_pCommand->CreateParameter("@Ĭ���ݻ�", adVarChar, adParamInput, 50, (_variant_t)mrrj);
		m_pCommand->Parameters->Append(Param_mrrj);

		_ParameterPtr Param_djhzz;
		Param_djhzz.CreateInstance("ADODB.Parameter");
		Param_djhzz = m_pCommand->CreateParameter("@��ú���ֹ", adVarChar, adParamInput, 50, (_variant_t)djhzz);
		m_pCommand->Parameters->Append(Param_djhzz);

		_ParameterPtr Param_dycsfjrs;
		Param_dycsfjrs.CreateInstance("ADODB.Parameter");
		Param_dycsfjrs = m_pCommand->CreateParameter("@��һ���Ƿ����ˮ", adVarChar, adParamInput, 50, (_variant_t)dycsfjrs);
		m_pCommand->Parameters->Append(Param_dycsfjrs);

		_ParameterPtr Param_decsfjrs;
		Param_decsfjrs.CreateInstance("ADODB.Parameter");
		Param_decsfjrs = m_pCommand->CreateParameter("@�ڶ����Ƿ����ˮ", adVarChar, adParamInput, 50, (_variant_t)decsfjrs);
		m_pCommand->Parameters->Append(Param_decsfjrs);

		_ParameterPtr Param_dyczrl;
		Param_dyczrl.CreateInstance("ADODB.Parameter");
		Param_dyczrl = m_pCommand->CreateParameter("@��һ��ע����", adVarChar, adParamInput, 50, (_variant_t)dyczrl);
		m_pCommand->Parameters->Append(Param_dyczrl);

		_ParameterPtr Param_jbsj;
		Param_jbsj.CreateInstance("ADODB.Parameter");
		Param_jbsj = m_pCommand->CreateParameter("@����ʱ��", adVarChar, adParamInput, 50, (_variant_t)jbsj);
		m_pCommand->Parameters->Append(Param_jbsj);

		_ParameterPtr Param_cxxyg;
		Param_cxxyg.CreateInstance("ADODB.Parameter");
		Param_cxxyg = m_pCommand->CreateParameter("@��ϴ��Һ��", adVarChar, adParamInput, 50, (_variant_t)cxxyg);
		m_pCommand->Parameters->Append(Param_cxxyg);

		_ParameterPtr Param_xygcxry;
		Param_xygcxry.CreateInstance("ADODB.Parameter");
		Param_xygcxry = m_pCommand->CreateParameter("@��Һ�ܳ�ϴ��Һ", adVarChar, adParamInput, 50, (_variant_t)xygcxry);
		m_pCommand->Parameters->Append(Param_xygcxry);

		CString align, again;
		align = again = _T("N");
		_ParameterPtr Param_align;
		Param_align.CreateInstance("ADODB.Parameter");
		Param_align = m_pCommand->CreateParameter("@��Һ�ܳ�ϴ��Һ", adVarChar, adParamInput, 50, (_variant_t)align);
		m_pCommand->Parameters->Append(Param_align);

		_ParameterPtr Param_again;
		Param_again.CreateInstance("ADODB.Parameter");
		Param_again = m_pCommand->CreateParameter("@��Һ�ܳ�ϴ��Һ", adVarChar, adParamInput, 50, (_variant_t)again);
		m_pCommand->Parameters->Append(Param_again);

		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}

_RecordsetPtr& Dlg_Liquid::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
{
	try
	{
		//������¼������
		m_pRecordset.CreateInstance(__uuidof(Recordset));

		//ȡ�ñ��еļ�¼
		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(),
			adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch (_com_error e)
	{
		e.Description();
	}
	//���ؼ�¼��
	return m_pRecordset;
}

void Dlg_Liquid::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)//������Ԫ��༭����
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, IDC_EDIT_CREATEID);//�����༭�����,IDC_EDIT_CREATEIDΪ�ؼ�ID��3000�������¿�ͷ����
	havecreat = true;
	createdit->SetFont(&m_font);//��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createdit->SetParent(&m_list_liquid);//��list control����Ϊ������,���ɵ�Edit������ȷ��λ,���Ҳ����Ҫ
	CRect  EditRect;
	m_list_liquid.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//��ȡ��Ԫ��Ŀռ�λ����Ϣ
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_liquid.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1��-1�����ñ༭�����ڵ�ס�б���е�������
	CString strItem = m_list_liquid.GetItemText(e_Item, e_SubItem);//�����Ӧ��Ԫ���ַ�
	createdit->SetWindowText(strItem);//����Ԫ���ַ���ʾ�ڱ༭����
	createdit->MoveWindow(&EditRect);//���༭��λ�÷�����Ӧ��Ԫ����
	createdit->ShowWindow(SW_SHOW);//��ʾ�༭���ڵ�Ԫ������
	createdit->SetFocus();//����Ϊ���� 
	createdit->SetSel(-1);//���ù�����ı������ֵ����
}

void Dlg_Liquid::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//�����Ӧ��Ԫ���ַ�
	distroyedit->DestroyWindow();//���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
}

void Dlg_Liquid::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)//������Ԫ�������б����
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, IDC_COMBOX_CREATEID);
	createccomboboxobj->SetFont(&m_font);//��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createccomboboxobj->SetParent(&m_list_liquid);//��list control����Ϊ������,���ɵ�Ccombobox������ȷ��λ,���Ҳ����Ҫ
	CRect  EditRect;
	m_list_liquid.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//��ȡ��Ԫ��Ŀռ�λ����Ϣ
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_liquid.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1��-1�����ñ༭�����ڵ�ס�б���е�������
	CString strItem = m_list_liquid.GetItemText(e_Item, e_SubItem);//�����Ӧ��Ԫ���ַ�
	createccomboboxobj->SetWindowText(strItem);//����Ԫ���ַ���ʾ�ڱ༭����
	createccomboboxobj->MoveWindow(&EditRect);//���༭��λ�÷�����Ӧ��Ԫ����
	createccomboboxobj->ShowWindow(SW_SHOW);//��ʾ�༭���ڵ�Ԫ������
}

void Dlg_Liquid::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//������Ӧ��Ԫ���ַ�
	distroyccomboboxobj->DestroyWindow();//���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
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
	// �˹���Ҫ�� Internet Explorer 5.5 ����߰汾��
	// ���� _WIN32_IE ������ >= 0x0560��
	LPNMLVSCROLL pStateChanged = reinterpret_cast<LPNMLVSCROLL>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


//void Dlg_Liquid::OnKillFocus(CWnd* pNewWnd)
//{
//	//MessageBox(_T("sdsad"));
//	CDialogEx::OnKillFocus(pNewWnd);
//
//	// TODO: �ڴ˴������Ϣ����������
//}



void Dlg_Liquid::OnNMDblclkListLiquid(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//������ǹ�����
	{
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
		{
			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	//else if (pEditCtrl->iSubItem != 11 && pEditCtrl->iSubItem != 1 && pEditCtrl->iSubItem != 5 && pEditCtrl->iSubItem != 6)//��������Ա�ѡ��
	//{
	//	hang[k] = pEditCtrl->iItem;
	//	lie[k] = pEditCtrl->iSubItem;
	//	k++;
	//	m_list_liquid.SetFocus();
	//	m_list_liquid.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	//	if (haveccomboboxcreate == true)//���֮ǰ�����˱༭������ٵ�
	//	{
	//		distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
	//		haveccomboboxcreate = false;
	//	}
	//	if (haveeditcreate == true)
	//	{
	//		if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
	//		{
	//			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);
	//			haveeditcreate = false;
	//			createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//�����༭��
	//		}
	//		else//���еĵ�Ԫ����֮ǰ�����õ�
	//		{
	//			m_Edit.SetFocus();//����Ϊ���� 
	//		}
	//	}
	//	else
	//	{
	//		e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	//		e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	//		createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//�����༭��
	//	}
	//}
	else if (pEditCtrl->iSubItem == 10 || pEditCtrl->iSubItem == 11)//������Ա�ѡ��
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
				m_comBox.AddString(L"Y");
				m_comBox.AddString(L"N");
				m_comBox.ShowDropDown();//�Զ�����
			}
			else//���еĵ�Ԫ����֮ǰ�����õ�
			{
				m_comBox.SetFocus();//����Ϊ���� 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
			e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
			createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
			m_comBox.AddString(L"Y");
			m_comBox.AddString(L"N");
			m_comBox.ShowDropDown();//�Զ�����
		}
	}
	//else if (pEditCtrl->iSubItem == 11)//������Ա�ѡ��
	//{
	//	hang[k] = pEditCtrl->iItem;
	//	lie[k] = pEditCtrl->iSubItem;
	//	k++;
	//	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
	//	{
	//		distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);
	//		haveeditcreate = false;
	//	}
	//	if (haveccomboboxcreate == true)
	//	{
	//		if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
	//		{
	//			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
	//			haveccomboboxcreate = false;
	//			createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
	//			m_comBox.AddString(L"B");
	//			m_comBox.AddString(L"");
	//			m_comBox.ShowDropDown();//�Զ�����
	//		}
	//		else//���еĵ�Ԫ����֮ǰ�����õ�
	//		{
	//			m_comBox.SetFocus();//����Ϊ���� 
	//		}
	//	}
	//	else
	//	{
	//		e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	//		e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	//		createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
	//		m_comBox.AddString(L"B");
	//		m_comBox.AddString(L"");
	//		m_comBox.ShowDropDown();//�Զ�����
	//	}
	//}
	else if (pEditCtrl->iSubItem == 15)//������Ա�ѡ��
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
				m_comBox.AddString(L"(no selection)");
				m_comBox.AddString(L"HAC");
				m_comBox.ShowDropDown();//�Զ�����
			}
			else//���еĵ�Ԫ����֮ǰ�����õ�
			{
				m_comBox.SetFocus();//����Ϊ���� 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
			e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
			createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
			m_comBox.AddString(L"(no selection)");
			m_comBox.AddString(L"HAC");
			m_comBox.ShowDropDown();//�Զ�����
		}
	}
	else
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		m_list_liquid.SetFocus();
		m_list_liquid.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		if (haveccomboboxcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);
				haveeditcreate = false;
				createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//�����༭��
			}
			else//���еĵ�Ԫ����֮ǰ�����õ�
			{
				m_Edit.SetFocus();//����Ϊ���� 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
			e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
			createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//�����༭��
		}
	}
	*pResult = 0;
}

void Dlg_Liquid::OnNMClickListLiquid(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	if (pEditCtrl->iItem == -1)//������ǹ�����
	{
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_liquid, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
		{
			distroyCcombobox(&m_list_liquid, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}

}


void Dlg_Liquid::OnTbLiquidNew()
{
	// TODO: �ڴ���������������
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
