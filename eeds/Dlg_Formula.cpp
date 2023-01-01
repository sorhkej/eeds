// Dlg_Formula.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Formula.h"
#include "afxdialogex.h"

#define IDC_EDIT_CREATEID  3033//���ڶ���List 
#define IDC_COMBOX_CREATEID  3044//���������б�
// Dlg_Formula �Ի���

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


// Dlg_Formula ��Ϣ�������


void Dlg_Formula::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void Dlg_Formula::OnTbFormulaDelete()
{
	// TODO: �ڴ���������������
	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
	{
		distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	// TODO: �ڴ���������������
	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
	{
		distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	// TODO: �ڴ���������������
	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
	{
		distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	//		strTime = tm.Format("%y��%m��%d�� %X");
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
	strTime = tm.Format("%y��%m��%d�� %X");
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
//	// TODO: �ڴ���������������
//	MessageBox(_T("ckzxjc"));
//}


BOOL Dlg_Formula::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	haveeditcreate = false;//��ʼ����־λ����ʾ��û�д����༭��
	haveccomboboxcreate = false;//��ʼ����־λ����ʾ��û�д��������б��
	RECT  m_rect;

	m_list_form.GetClientRect(&m_rect); //��ȡlist�Ŀͻ���,�������ÿһ�еĿ��

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

	//���ع�����
	m_toolbar.Create(this);
	m_toolbar.LoadToolBar(IDR_STUFF_TOOLBAR);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	CString sql;
	sql.Format(_T("select* from Stuff order by ���� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);
	rnum = 0;

	//CFont m_font;
	//m_font.CreatePointFont(100, _T("΢���ź�"));
	//m_cb_liqu.SetFont(&m_font);

	while (m_pRecordset->adoEOF == 0)
	{
		CString s = m_pRecordset->GetCollect(_T("����"));
		m_cb_liqu.AddString(s);
		m_pRecordset->MoveNext();
	}
	m_cb_liqu.SetCurSel(0);
	m_cb_unit.AddString(_T("%"));
	m_cb_unit.SetCurSel(0);
	//daima = _T("111");
	//SearchData();
	//CString abc = m_pRecordset->GetCollect(_T("Ũ��1"));
	//MessageBox(abc);


	m_list_orde.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	m_list_orde.DeleteAllItems();

	////CFont m_font;
	////m_font.CreatePointFont(100, _T("΢���ź�"));
	////m_list_orde.SetFont(&m_font);

	m_list_orde.InsertColumn(0, _T("������"), LVCFMT_LEFT, 200, 2);         //Ϊ�б�������У��������ֻ����룬��ϵ����ע
	m_list_orde.InsertColumn(1, _T("Ũ��"), LVCFMT_LEFT, 200, 2);
	m_list_orde.InsertColumn(2, _T("��λ"), LVCFMT_LEFT, 150, 2);
	m_list_orde.InsertColumn(3, _T("����"), LVCFMT_LEFT, 100, 2);

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
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void Dlg_Formula::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ExitConn();
	hang[10000] = {};
	k = 0;
	CDialogEx::OnClose();
}

BOOL Dlg_Formula::ExitConn()
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

void Dlg_Formula::CheckData()//�����ݿ���в�ѯ����
{
	CString sql;
	sql.Format(_T("select* from Formula order by ���� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);



	rnum = 0;

	m_list_form.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_form.DeleteColumn(0));	//������б�ͷ
	m_list_form.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_list_form.SetFont(&m_font);

	m_list_form.InsertColumn(0, _T("����"), LVCFMT_LEFT, 200, 2);         //Ϊ�б�������У��������ֻ����룬��ϵ����ע
	m_list_form.InsertColumn(1, _T("����"), LVCFMT_LEFT, 200, 2);
	m_list_form.InsertColumn(2, _T("����ʱ��"), LVCFMT_LEFT, 300, 2);
	m_list_form.InsertColumn(3, _T("�޸�ʱ��"), LVCFMT_LEFT, 300, 2);
	

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
		m_list_form.InsertItem(0, _T(""));
		m_list_form.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
		m_list_form.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));      //��¼��ѡ����б��������ݿ��б����ܹ��ҵ�����Ȼ����
		m_list_form.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����ʱ��")));
		m_list_form.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("�޸�ʱ��")));


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

void Dlg_Formula::DeleteData()//�����ݰ���ÿһ�е���д�����ݿ⵽ʱ����ô˺����ͺ�
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Delete_Formula";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_dm;
		Param_dm.CreateInstance("ADODB.Parameter");
		Param_dm = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)dm);
		m_pCommand->Parameters->Append(Param_dm);



		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}

void Dlg_Formula::SaveToDatabase()//�����ݰ���ÿһ�е���д�����ݿ⵽ʱ����ô˺����ͺ�
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Add_Formula";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_dm;
		Param_dm.CreateInstance("ADODB.Parameter");
		Param_dm = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)dm);
		m_pCommand->Parameters->Append(Param_dm);

		_ParameterPtr Param_mc;
		Param_mc.CreateInstance("ADODB.Parameter");
		Param_mc = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)mc);
		m_pCommand->Parameters->Append(Param_mc);

		_ParameterPtr Paramcjsj;
		Paramcjsj.CreateInstance("ADODB.Parameter");
		Paramcjsj = m_pCommand->CreateParameter("@����ʱ��", adVarWChar, adParamInput, 50, (_variant_t)cjsj);
		m_pCommand->Parameters->Append(Paramcjsj);

		_ParameterPtr Param_xgsj;
		Param_xgsj.CreateInstance("ADODB.Parameter");
		Param_xgsj = m_pCommand->CreateParameter("@�޸�ʱ��", adVarWChar, adParamInput, 50, (_variant_t)xgsj);
		m_pCommand->Parameters->Append(Param_xgsj);

		_ParameterPtr Param_xl;
		Param_xl.CreateInstance("ADODB.Parameter");
		Param_xl = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)xl);
		m_pCommand->Parameters->Append(Param_xl);

		_ParameterPtr Param_xl1;
		Param_xl1.CreateInstance("ADODB.Parameter");
		Param_xl1 = m_pCommand->CreateParameter("@����1", adVarWChar, adParamInput, 50, (_variant_t)xl1);
		m_pCommand->Parameters->Append(Param_xl1);

		_ParameterPtr Param_nd1;
		Param_nd1.CreateInstance("ADODB.Parameter");
		Param_nd1 = m_pCommand->CreateParameter("@Ũ��1", adVarWChar, adParamInput, 50, (_variant_t)nd1);
		m_pCommand->Parameters->Append(Param_nd1);

		_ParameterPtr Param_xl2;
		Param_xl2.CreateInstance("ADODB.Parameter");
		Param_xl2 = m_pCommand->CreateParameter("@����2", adVarWChar, adParamInput, 50, (_variant_t)xl2);
		m_pCommand->Parameters->Append(Param_xl2);

		_ParameterPtr Param_nd2;
		Param_nd2.CreateInstance("ADODB.Parameter");
		Param_nd2 = m_pCommand->CreateParameter("@Ũ��2", adVarWChar, adParamInput, 50, (_variant_t)nd2);
		m_pCommand->Parameters->Append(Param_nd2);

		_ParameterPtr Param_xl3;
		Param_xl3.CreateInstance("ADODB.Parameter");
		Param_xl3 = m_pCommand->CreateParameter("@����3", adVarWChar, adParamInput, 50, (_variant_t)xl3);
		m_pCommand->Parameters->Append(Param_xl3);

		_ParameterPtr Param_nd3;
		Param_nd3.CreateInstance("ADODB.Parameter");
		Param_nd3 = m_pCommand->CreateParameter("@Ũ��3", adVarWChar, adParamInput, 50, (_variant_t)nd3);
		m_pCommand->Parameters->Append(Param_nd3);

		_ParameterPtr Param_xl4;
		Param_xl4.CreateInstance("ADODB.Parameter");
		Param_xl4 = m_pCommand->CreateParameter("@����4", adVarWChar, adParamInput, 50, (_variant_t)xl4);
		m_pCommand->Parameters->Append(Param_xl4);

		_ParameterPtr Param_nd4;
		Param_nd4.CreateInstance("ADODB.Parameter");
		Param_nd4 = m_pCommand->CreateParameter("@Ũ��4", adVarWChar, adParamInput, 50, (_variant_t)nd4);
		m_pCommand->Parameters->Append(Param_nd4);

		_ParameterPtr Param_xl5;
		Param_xl5.CreateInstance("ADODB.Parameter");
		Param_xl5 = m_pCommand->CreateParameter("@����5", adVarWChar, adParamInput, 50, (_variant_t)xl5);
		m_pCommand->Parameters->Append(Param_xl5);

		_ParameterPtr Param_nd5;
		Param_nd5.CreateInstance("ADODB.Parameter");
		Param_nd5 = m_pCommand->CreateParameter("@Ũ��5", adVarWChar, adParamInput, 50, (_variant_t)nd5);
		m_pCommand->Parameters->Append(Param_nd5);

		_ParameterPtr Param_xl6;
		Param_xl6.CreateInstance("ADODB.Parameter");
		Param_xl6 = m_pCommand->CreateParameter("@����6", adVarWChar, adParamInput, 50, (_variant_t)xl6);
		m_pCommand->Parameters->Append(Param_xl6);

		_ParameterPtr Param_nd6;
		Param_nd6.CreateInstance("ADODB.Parameter");
		Param_nd6 = m_pCommand->CreateParameter("@Ũ��6", adVarWChar, adParamInput, 50, (_variant_t)nd6);
		m_pCommand->Parameters->Append(Param_nd6);

		_ParameterPtr Param_xl7;
		Param_xl7.CreateInstance("ADODB.Parameter");
		Param_xl7 = m_pCommand->CreateParameter("@����7", adVarWChar, adParamInput, 50, (_variant_t)xl7);
		m_pCommand->Parameters->Append(Param_xl7);

		_ParameterPtr Param_nd7;
		Param_nd7.CreateInstance("ADODB.Parameter");
		Param_nd7 = m_pCommand->CreateParameter("@Ũ��7", adVarWChar, adParamInput, 50, (_variant_t)nd7);
		m_pCommand->Parameters->Append(Param_nd7);

		_ParameterPtr Param_xl8;
		Param_xl8.CreateInstance("ADODB.Parameter");
		Param_xl8 = m_pCommand->CreateParameter("@����8", adVarWChar, adParamInput, 50, (_variant_t)xl8);
		m_pCommand->Parameters->Append(Param_xl8);

		_ParameterPtr Param_nd8;
		Param_nd8.CreateInstance("ADODB.Parameter");
		Param_nd8 = m_pCommand->CreateParameter("@Ũ��8", adVarWChar, adParamInput, 50, (_variant_t)nd8);
		m_pCommand->Parameters->Append(Param_nd8);

		_ParameterPtr Param_xl9;
		Param_xl9.CreateInstance("ADODB.Parameter");
		Param_xl9 = m_pCommand->CreateParameter("@����9", adVarWChar, adParamInput, 50, (_variant_t)xl9);
		m_pCommand->Parameters->Append(Param_xl9);

		_ParameterPtr Param_nd9;
		Param_nd9.CreateInstance("ADODB.Parameter");
		Param_nd9 = m_pCommand->CreateParameter("@Ũ��9", adVarWChar, adParamInput, 50, (_variant_t)nd9);
		m_pCommand->Parameters->Append(Param_nd9);

		_ParameterPtr Param_xl10;
		Param_xl10.CreateInstance("ADODB.Parameter");
		Param_xl10 = m_pCommand->CreateParameter("@����10", adVarWChar, adParamInput, 50, (_variant_t)xl10);
		m_pCommand->Parameters->Append(Param_xl10);

		_ParameterPtr Param_nd10;
		Param_nd10.CreateInstance("ADODB.Parameter");
		Param_nd10 = m_pCommand->CreateParameter("@Ũ��10", adVarWChar, adParamInput, 50, (_variant_t)nd10);
		m_pCommand->Parameters->Append(Param_nd10);



		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}


_RecordsetPtr& Dlg_Formula::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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

void Dlg_Formula::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)//������Ԫ��༭����
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, IDC_EDIT_CREATEID);//�����༭�����,IDC_EDIT_CREATEIDΪ�ؼ�ID��3000�������¿�ͷ����
	havecreat = true;
	createdit->SetFont(&m_font);//��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createdit->SetParent(&m_list_form);//��list control����Ϊ������,���ɵ�Edit������ȷ��λ,���Ҳ����Ҫ
	CRect  EditRect;
	m_list_form.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//��ȡ��Ԫ��Ŀռ�λ����Ϣ
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_form.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1��-1�����ñ༭�����ڵ�ס�б���е�������
	CString strItem = m_list_form.GetItemText(e_Item, e_SubItem);//�����Ӧ��Ԫ���ַ�
	createdit->SetWindowText(strItem);//����Ԫ���ַ���ʾ�ڱ༭����
	createdit->MoveWindow(&EditRect);//���༭��λ�÷�����Ӧ��Ԫ����
	createdit->ShowWindow(SW_SHOW);//��ʾ�༭���ڵ�Ԫ������
	createdit->SetFocus();//����Ϊ���� 
	createdit->SetSel(-1);//���ù�����ı������ֵ����
}

void Dlg_Formula::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//�����Ӧ��Ԫ���ַ�
	distroyedit->DestroyWindow();//���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
}

void Dlg_Formula::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)//������Ԫ�������б����
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, IDC_COMBOX_CREATEID);
	createccomboboxobj->SetFont(&m_font);//��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createccomboboxobj->SetParent(&m_list_form);//��list control����Ϊ������,���ɵ�Ccombobox������ȷ��λ,���Ҳ����Ҫ
	CRect  EditRect;
	m_list_form.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//��ȡ��Ԫ��Ŀռ�λ����Ϣ
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_form.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1��-1�����ñ༭�����ڵ�ס�б���е�������
	CString strItem = m_list_form.GetItemText(e_Item, e_SubItem);//�����Ӧ��Ԫ���ַ�
	createccomboboxobj->SetWindowText(strItem);//����Ԫ���ַ���ʾ�ڱ༭����
	createccomboboxobj->MoveWindow(&EditRect);//���༭��λ�÷�����Ӧ��Ԫ����
	createccomboboxobj->ShowWindow(SW_SHOW);//��ʾ�༭���ڵ�Ԫ������
}

void Dlg_Formula::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//������Ӧ��Ԫ���ַ�
	distroyccomboboxobj->DestroyWindow();//���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
}


void Dlg_Formula::OnNMClickListFormula(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//������ǹ�����
	{
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
		if (haveccomboboxcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);
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
	else
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;

		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
		{
			distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		//ѡ�к���ʾ�䷽
		//CString sql;
		//sql.Format(_T("select* from Formula order by ���� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
		//GetRecordSet((_bstr_t)sql);

		daima = m_list_form.GetItemText(pEditCtrl->iItem, 0);
		mingcheng = m_list_form.GetItemText(pEditCtrl->iItem, 1);
		SearchData();

		m_list_orde.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
			| LVS_EX_FULLROWSELECT
			| LVS_EX_HEADERDRAGDROP
			| LVS_EX_ONECLICKACTIVATE
			| LVS_EX_GRIDLINES);
		while (m_list_orde.DeleteColumn(0));	//������б�ͷ
		m_list_orde.DeleteAllItems();

		CFont m_font;
		m_font.CreatePointFont(100, _T("΢���ź�"));
		m_list_orde.SetFont(&m_font);

		m_list_orde.InsertColumn(0, _T("������"), LVCFMT_LEFT, 200, 2);         //Ϊ�б�������У��������ֻ����룬��ϵ����ע
		m_list_orde.InsertColumn(1, _T("Ũ��"), LVCFMT_LEFT, 200, 2);
		m_list_orde.InsertColumn(2, _T("��λ"), LVCFMT_LEFT, 150, 2);
		m_list_orde.InsertColumn(3, _T("����"), LVCFMT_LEFT, 100, 2);

		int a = m_pRecordset->GetCollect(_T("����"));
		
		
		int i = 1;
		while (i <= a)
		{
			CString xl, nd, xh;
			xh.Format(_T("%d"), i);
			xl = _T("����");
			nd = _T("Ũ��");
			xl = xl + xh;
			nd = nd + xh;
			m_list_orde.InsertItem(i-1, _T(""));
			m_list_orde.SetItemText(i - 1, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_variant_t(xl)));
			m_list_orde.SetItemText(i - 1, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_variant_t(nd)));
			m_list_orde.SetItemText(i - 1, 2, _T("%"));
			m_list_orde.SetItemText(i - 1, 3, (LPCTSTR)(LPTSTR)(_bstr_t)i);
			i++;
		}
		//CString a1 = m_pRecordset->GetCollect(_T("����4"));

			//m_list_orde.InsertItem(0, _T(""));
			//m_list_orde.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));



	}
	*pResult = 0;
}


void Dlg_Formula::OnNMCustomdrawListFormula(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (flagnum > 0)
	{
		flagnum = 0;
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	//Liquid_Search.Format(_T("select* from Liquid order by ���� desc"));
	//GetRecordSet((_bstr_t)Liquid_Search);

	int iPos;
	CString str;
	iPos = ((CComboBox*)GetDlgItem(IDC_COMBO_LIQUID))->GetCurSel();//��ǰѡ�е��С�
	((CComboBox*)GetDlgItem(IDC_COMBO_LIQUID))->SetCurSel(iPos);//���õ�n������Ϊ��ʾ�����ݡ�
	/*GetDlgItem(IDC_COMBO_LIQUID)->GetWindowText(str);
	m_edit_pote.SetWindowText(str);*/

	m_edit_pote.SetWindowText(_T(""));

}

void Dlg_Formula::SearchData()
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Search_Formula";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_daima;
		Param_daima.CreateInstance("ADODB.Parameter");
		Param_daima = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)daima);
		m_pCommand->Parameters->Append(Param_daima);

		_ParameterPtr Param_mingcheng;
		Param_mingcheng.CreateInstance("ADODB.Parameter");
		Param_mingcheng = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)mingcheng);
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
	//(LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("�޸�ʱ��"))
}

void Dlg_Formula::OnNMDblclkListFormula(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//������ǹ�����
	{
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
		{
			distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if (pEditCtrl->iSubItem == 3 || pEditCtrl->iSubItem == 4 || pEditCtrl->iSubItem == 5)//������Ա�ѡ��
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
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
	else
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		m_list_form.SetFocus();
		m_list_form.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		if (haveccomboboxcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyCcombobox(&m_list_form, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyEdit(&m_list_form, &m_Edit, e_Item, e_SubItem);
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
	// TODO: �ڴ���������������
	int nItem = m_list_form.GetItemCount();
	//m_list_form.SetItemState(6, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	m_list_form.SetItemState(nItem-1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_list_form.EnsureVisible(nItem - 1, FALSE);



}


void Dlg_Formula::OnEnChangeEditPotency()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	int sum = m_list_orde.GetItemCount();
	xl.Format(_T("%d"), sum+1);
	m_edit_orde.SetWindowText(xl);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Dlg_Formula::OnBnClickedBtnDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int iItem;
	for (iItem = m_list_orde.GetItemCount() - 1; iItem >= 0; iItem--)
	{
		if (LVIS_SELECTED == m_list_orde.GetItemState(iItem, LVIS_SELECTED))     //����ѡ����
		{
			m_list_orde.DeleteItem(iItem);
		}
	}

}
