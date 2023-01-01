// Dlg_Attribute.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Attribute.h"
#include "afxdialogex.h"
#define IDC_EDIT_CREATEID  3003//���ڶ���List 
#define IDC_COMBOX_CREATEID  3004//���������б�

// Dlg_Attribute �Ի���

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


// Dlg_Attribute ��Ϣ�������


void Dlg_Attribute::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//������ǹ�����
	{
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyCcombobox(&m_list_liquidAttr, &m_comBox, e_Item, e_SubItem);
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
		//hang[k] = pEditCtrl->iItem;
		//lie[k] = pEditCtrl->iSubItem;
		//k++;
		//m_list_liquidAttr.SetFocus();
		//m_list_liquidAttr.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		//if (haveccomboboxcreate == true)//���֮ǰ�����˱༭������ٵ�
		//{
		//	distroyCcombobox(&m_list_liquidAttr, &m_comBox, e_Item, e_SubItem);
		//	haveccomboboxcreate = false;
		//}
		//if (haveeditcreate == true)
		//{
		//	if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
		//	{
		//		distroyEdit(&m_list_liquidAttr, &m_Edit, e_Item, e_SubItem);
		//		haveeditcreate = false;
		//		createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//�����༭��
		//	}
		//	else//���еĵ�Ԫ����֮ǰ�����õ�
		//	{
		//		m_Edit.SetFocus();//����Ϊ���� 
		//	}
		//}
		//else
		//{
		//	e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
		//	e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
		//	createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//�����༭��
		//}
	}
}

//void Dlg_Attribute::OnTbAttributeDelete()
//{
//	// TODO: �ڴ���������������
//	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
//	{
//		distroyEdit(&m_list_liquidAttr, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
//		haveeditcreate = false;
//	}
//	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
//	// TODO: �ڴ���������������
//	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
//	{
//		distroyEdit(&m_list_liquidAttr, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
//		haveeditcreate = false;
//	}
//	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
//	// TODO: �ڴ���������������
//	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
//	{
//		distroyEdit(&m_list_liquidAttr, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
//		haveeditcreate = false;
//	}
//	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ExitConn();
	hang[10000] = {};
	k = 0;
	CDialogEx::OnClose();
}

BOOL Dlg_Attribute::ExitConn()
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

void Dlg_Attribute::CheckData()//�����ݿ���в�ѯ����
{
	CString sql;
	sql.Format(_T("select* from Liquid order by ���� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);



	rnum = 0;

	m_list_liquidAttr.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_liquidAttr.DeleteColumn(0));	//������б�ͷ
	m_list_liquidAttr.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_list_liquidAttr.SetFont(&m_font);

	m_list_liquidAttr.InsertColumn(0, _T("����"), LVCFMT_LEFT, 200, 2);         //Ϊ�б�������У��������ֻ����룬��ϵ����ע
	m_list_liquidAttr.InsertColumn(1, _T("Ũ��"), LVCFMT_LEFT, 200, 2);
	m_list_liquidAttr.InsertColumn(2, _T("�ܶ�"), LVCFMT_LEFT, 150, 2);
	m_list_liquidAttr.InsertColumn(3, _T("У׼��Һ"), LVCFMT_LEFT, 100, 2);
	m_list_liquidAttr.InsertColumn(4, _T("��Һ�ܳ�ϴ��Һ"), LVCFMT_LEFT, 150, 2);
	m_list_liquidAttr.InsertColumn(5, _T("�ٴ�ע����Һ"), LVCFMT_LEFT, 100, 2);


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
		m_list_liquidAttr.InsertItem(0, _T(""));
		m_list_liquidAttr.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
		m_list_liquidAttr.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("Ũ��")));      //��¼��ѡ����б��������ݿ��б����ܹ��ҵ�����Ȼ����
		m_list_liquidAttr.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��Һʵ���ݻ�")));
		m_list_liquidAttr.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("У׼��Һ")));
		m_list_liquidAttr.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��Һ�ܳ�ϴ��Һ")));
		m_list_liquidAttr.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("�ٴ�ע����Һ")));

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

void Dlg_Attribute::DeleteData()//�����ݰ���ÿһ�е���д�����ݿ⵽ʱ����ô˺����ͺ�
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Delete_Liquid_Attribute";//�洢����ΪCorn_ADD
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

void Dlg_Attribute::SaveToDatabase()//�����ݰ���ÿһ�е���д�����ݿ⵽ʱ����ô˺����ͺ�
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Add_Liquid_Attribute";//�洢����ΪCorn_ADD
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

		_ParameterPtr Param_jzry;
		Param_jzry.CreateInstance("ADODB.Parameter");
		Param_jzry = m_pCommand->CreateParameter("@У׼��Һ", adVarWChar, adParamInput, 50, (_variant_t)jzry);
		m_pCommand->Parameters->Append(Param_jzry);

		_ParameterPtr Param_xygcxry;
		Param_xygcxry.CreateInstance("ADODB.Parameter");
		Param_xygcxry = m_pCommand->CreateParameter("@��Һ�ܳ�ϴ��Һ", adVarChar, adParamInput, 50, (_variant_t)xygcxry);
		m_pCommand->Parameters->Append(Param_xygcxry);

		_ParameterPtr Param_zczrry;
		Param_zczrry.CreateInstance("ADODB.Parameter");
		Param_zczrry = m_pCommand->CreateParameter("@�ٴ�ע����Һ", adVarChar, adParamInput, 50, (_variant_t)zczrry);
		m_pCommand->Parameters->Append(Param_zczrry);


		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();

}

_RecordsetPtr& Dlg_Attribute::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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

void Dlg_Attribute::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)//������Ԫ��༭����
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, IDC_EDIT_CREATEID);//�����༭�����,IDC_EDIT_CREATEIDΪ�ؼ�ID��3000�������¿�ͷ����
	havecreat = true;
	createdit->SetFont(&m_font);//��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createdit->SetParent(&m_list_liquidAttr);//��list control����Ϊ������,���ɵ�Edit������ȷ��λ,���Ҳ����Ҫ
	CRect  EditRect;
	m_list_liquidAttr.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//��ȡ��Ԫ��Ŀռ�λ����Ϣ
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_liquidAttr.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1��-1�����ñ༭�����ڵ�ס�б���е�������
	CString strItem = m_list_liquidAttr.GetItemText(e_Item, e_SubItem);//�����Ӧ��Ԫ���ַ�
	createdit->SetWindowText(strItem);//����Ԫ���ַ���ʾ�ڱ༭����
	createdit->MoveWindow(&EditRect);//���༭��λ�÷�����Ӧ��Ԫ����
	createdit->ShowWindow(SW_SHOW);//��ʾ�༭���ڵ�Ԫ������
	createdit->SetFocus();//����Ϊ���� 
	createdit->SetSel(-1);//���ù�����ı������ֵ����
}

void Dlg_Attribute::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//�����Ӧ��Ԫ���ַ�
	distroyedit->DestroyWindow();//���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
}

void Dlg_Attribute::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)//������Ԫ�������б����
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, IDC_COMBOX_CREATEID);
	createccomboboxobj->SetFont(&m_font);//��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createccomboboxobj->SetParent(&m_list_liquidAttr);//��list control����Ϊ������,���ɵ�Ccombobox������ȷ��λ,���Ҳ����Ҫ
	CRect  EditRect;
	m_list_liquidAttr.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//��ȡ��Ԫ��Ŀռ�λ����Ϣ
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_liquidAttr.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1��-1�����ñ༭�����ڵ�ס�б���е�������
	CString strItem = m_list_liquidAttr.GetItemText(e_Item, e_SubItem);//�����Ӧ��Ԫ���ַ�
	createccomboboxobj->SetWindowText(strItem);//����Ԫ���ַ���ʾ�ڱ༭����
	createccomboboxobj->MoveWindow(&EditRect);//���༭��λ�÷�����Ӧ��Ԫ����
	createccomboboxobj->ShowWindow(SW_SHOW);//��ʾ�༭���ڵ�Ԫ������
}

void Dlg_Attribute::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//������Ӧ��Ԫ���ַ�
	distroyccomboboxobj->DestroyWindow();//���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
}


BOOL Dlg_Attribute::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	haveeditcreate = false;//��ʼ����־λ����ʾ��û�д����༭��
	haveccomboboxcreate = false;//��ʼ����־λ����ʾ��û�д��������б��
	RECT  m_rect;

	m_list_liquidAttr.GetClientRect(&m_rect); //��ȡlist�Ŀͻ���,�������ÿһ�еĿ��

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
	//m_toolbar.Create(this);
	//// �������봴����Toolbar��Դ��
	//m_toolbar.LoadToolBar(IDR_STUFF_TOOLBAR);
	//RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void Dlg_Attribute::OnNMCustomdrawListAttribute(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (flagnum > 0)
	{
		flagnum = 0;
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_liquidAttr, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	*pResult = 0;
}


void Dlg_Attribute::OnBnClickedButtonSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	hang[10000] = {};
	k = 0;
	CheckData();
}
