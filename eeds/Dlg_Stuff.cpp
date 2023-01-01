// Dlg_Stuff.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Stuff.h"
#include "afxdialogex.h"
//#include"Dlg_Item.h"

// Dlg_Stuff �Ի���

IMPLEMENT_DYNAMIC(Dlg_Stuff, CDialogEx)

Dlg_Stuff::Dlg_Stuff(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_STUFF, pParent)
{

}

Dlg_Stuff::~Dlg_Stuff()
{
}

#define IDC_EDIT_CREATEID  3000//���ڶ���List 
#define IDC_COMBOX_CREATEID  3000//���������б�


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


// Dlg_Stuff ��Ϣ�������


BOOL Dlg_Stuff::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	haveeditcreate = false;//��ʼ����־λ����ʾ��û�д����༭��
	haveccomboboxcreate = false;//��ʼ����־λ����ʾ��û�д��������б��
	RECT  m_rect;

	m_list_stuff.GetClientRect(&m_rect); //��ȡlist�Ŀͻ���,�������ÿһ�еĿ��

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

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void Dlg_Stuff::CheckData()//�����ݿ���в�ѯ����
{
	CString sql;
	sql.Format(_T("select* from Stuff order by ���� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);

	rnum = 0;
	Rgb[10000] = {};

	m_list_stuff.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_stuff.DeleteColumn(0));	//������б�ͷ
	m_list_stuff.DeleteAllItems();
	//CImageList   m_l;
	//m_l.Create(18, 18, TRUE | ILC_COLOR32, 1, 0);
	//m_list_stuff.SetImageList(&m_l, LVSIL_SMALL);
	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_list_stuff.SetFont(&m_font);

	m_list_stuff.InsertColumn(0, _T("����"), LVCFMT_LEFT, 200,2 );         //Ϊ�б�������У��������ֻ����룬��ϵ����ע
	m_list_stuff.InsertColumn(1, _T("����"), LVCFMT_LEFT, 200, 2);
	m_list_stuff.InsertColumn(2, _T("����������"), LVCFMT_LEFT, 150, 4);
	m_list_stuff.InsertColumn(3, _T("�ܶ�g/L"), LVCFMT_LEFT, 100, 2);
	m_list_stuff.InsertColumn(4, _T("�������б�"), LVCFMT_LEFT, 150, 4);
	m_list_stuff.InsertColumn(5, _T("��λ"), LVCFMT_LEFT, 100, 2);
	m_list_stuff.InsertColumn(6, _T("��ɫ"), LVCFMT_LEFT, 200, 2);

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
		m_list_stuff.InsertItem(0, _T(""));
		m_list_stuff.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
		m_list_stuff.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));      //��¼��ѡ����б��������ݿ��б����ܹ��ҵ�����Ȼ����
		m_list_stuff.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����������")));
		m_list_stuff.SetItemText(0, 3, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("�ܶ�")));
		m_list_stuff.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("�������б�")));
		m_list_stuff.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��λ")));
		//m_list_stuff.SetItemText(0, 6, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��ɫ")));

		Rgb[sum - rnum] = m_pRecordset->GetCollect(_T("��ɫ"));
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

_RecordsetPtr& Dlg_Stuff::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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

void Dlg_Stuff::OnNMClickListStuff(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//������ǹ�����
	{
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
		{
			distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if (pEditCtrl->iSubItem != 2 && pEditCtrl->iSubItem != 4 && pEditCtrl->iSubItem != 5 && pEditCtrl->iSubItem != 6)//��������Ա�ѡ��
	{
	//	hang[k] = pEditCtrl->iItem;
	//	lie[k] = pEditCtrl->iSubItem;
	//	k++;
	//	m_list_stuff.SetFocus();
	//	m_list_stuff.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	//	if (haveccomboboxcreate == true)//���֮ǰ�����˱༭������ٵ�
	//	{
	//		distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
	//		haveccomboboxcreate = false;
	//	}
	//	if (haveeditcreate == true)
	//	{
	//		if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
	//		{
	//			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
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
	}
	else if (pEditCtrl->iSubItem == 2)//������Ա�ѡ��
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
				m_comBox.AddString(L"AUXL");
				m_comBox.AddString(L"COLP");
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
			m_comBox.AddString(L"AUXL");
			m_comBox.AddString(L"COLP");
			m_comBox.ShowDropDown();//�Զ�����
		}
	}
	else if (pEditCtrl->iSubItem == 4)//������Ա�ѡ��
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
				m_comBox.AddString(L"B");
				m_comBox.AddString(L"");
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
			m_comBox.AddString(L"B");
			m_comBox.AddString(L"");
			m_comBox.ShowDropDown();//�Զ�����
		}
	}
	else if (pEditCtrl->iSubItem == 5)//������Ա�ѡ��
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
				m_comBox.AddString(L"cc");
				m_comBox.AddString(L"g");
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
			m_comBox.AddString(L"cc");
			m_comBox.AddString(L"g");
			m_comBox.ShowDropDown();//�Զ�����
		}
	}
	else /*if (pEditCtrl->iSubItem == 6)*///������Ա�ѡ��
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		COLORREF color;      // ��ɫ�Ի���ĳ�ʼ��ɫΪ��ɫ   
		CColorDialog colorDlg;         // ������ɫ�Ի��򣬴����ʼ��ɫֵ   
		if (IDOK == colorDlg.DoModal())       // ��ʾ��ɫ�Ի��򣬲��ж��Ƿ����ˡ�ȷ����   
		{
			color = colorDlg.GetColor();      // ��ȡ��ɫ�Ի�����ѡ�����ɫֵ   
			Rgb[pEditCtrl->iItem] = color;
			SetDlgItemInt(IDC_EDIT1, color);
		}

	}


	*pResult = 0;
}

void Dlg_Stuff::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)//������Ԫ��༭����
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, IDC_EDIT_CREATEID);//�����༭�����,IDC_EDIT_CREATEIDΪ�ؼ�ID��3000�������¿�ͷ����
	havecreat = true;
	createdit->SetFont(&m_font);//��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createdit->SetParent(&m_list_stuff);//��list control����Ϊ������,���ɵ�Edit������ȷ��λ,���Ҳ����Ҫ
	CRect  EditRect;
	m_list_stuff.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//��ȡ��Ԫ��Ŀռ�λ����Ϣ
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_stuff.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1��-1�����ñ༭�����ڵ�ס�б���е�������
	CString strItem = m_list_stuff.GetItemText(e_Item, e_SubItem);//�����Ӧ��Ԫ���ַ�
	createdit->SetWindowText(strItem);//����Ԫ���ַ���ʾ�ڱ༭����
	createdit->MoveWindow(&EditRect);//���༭��λ�÷�����Ӧ��Ԫ����
	createdit->ShowWindow(SW_SHOW);//��ʾ�༭���ڵ�Ԫ������
	createdit->SetFocus();//����Ϊ���� 
	createdit->SetSel(-1);//���ù�����ı������ֵ����
}

void Dlg_Stuff::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//�����Ӧ��Ԫ���ַ�
	distroyedit->DestroyWindow();//���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
}

void Dlg_Stuff::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)//������Ԫ�������б����
{
	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, IDC_COMBOX_CREATEID);
	createccomboboxobj->SetFont(&m_font);//��������,����������Ļ�������ֻ��ͻأ�ĸо�
	createccomboboxobj->SetParent(&m_list_stuff);//��list control����Ϊ������,���ɵ�Ccombobox������ȷ��λ,���Ҳ����Ҫ
	CRect  EditRect;
	m_list_stuff.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//��ȡ��Ԫ��Ŀռ�λ����Ϣ
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_list_stuff.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1��-1�����ñ༭�����ڵ�ס�б���е�������
	CString strItem = m_list_stuff.GetItemText(e_Item, e_SubItem);//�����Ӧ��Ԫ���ַ�
	createccomboboxobj->SetWindowText(strItem);//����Ԫ���ַ���ʾ�ڱ༭����
	createccomboboxobj->MoveWindow(&EditRect);//���༭��λ�÷�����Ӧ��Ԫ����
	createccomboboxobj->ShowWindow(SW_SHOW);//��ʾ�༭���ڵ�Ԫ������
}

void Dlg_Stuff::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//������Ӧ��Ԫ���ַ�
	distroyccomboboxobj->DestroyWindow();//���ٶ����д�����Ҫ�����٣���Ȼ�ᱨ��
}

void Dlg_Stuff::OnTbStuffDelete()
{
	// TODO: �ڴ���������������
	if(haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
	{
		distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	// TODO: �ڴ���������������
	CheckData();
}


void Dlg_Stuff::OnTbStuffSave()
{
	// TODO: �ڴ���������������
	if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
	{
		distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
		haveeditcreate = false;
	}
	if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
			if (pLVCD->iSubItem == 6)//������ѡ��ÿһ�еĵ�7��
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

void Dlg_Stuff::DeleteData()//�����ݰ���ÿһ�е���д�����ݿ⵽ʱ����ô˺����ͺ�
{
	////AfxOleInit();
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Delete_Stuff";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_dempono;
		Param_dempono.CreateInstance("ADODB.Parameter");
		Param_dempono = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)dm);
		m_pCommand->Parameters->Append(Param_dempono);

		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}


void Dlg_Stuff::SaveToDatabase()//�����ݰ���ÿһ�е���д�����ݿ⵽ʱ����ô˺����ͺ�
{
	////AfxOleInit();
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Add_Stuff";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_dempono;
		Param_dempono.CreateInstance("ADODB.Parameter");
		Param_dempono = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)dm);
		m_pCommand->Parameters->Append(Param_dempono);

		_ParameterPtr Param_dempname;
		Param_dempname.CreateInstance("ADODB.Parameter");
		Param_dempname = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)mc);
		m_pCommand->Parameters->Append(Param_dempname);

		_ParameterPtr Param_location;
		Param_location.CreateInstance("ADODB.Parameter");
		Param_location = m_pCommand->CreateParameter("@����������", adVarWChar, adParamInput, 50, (_variant_t)hgllx);
		m_pCommand->Parameters->Append(Param_location);

		_ParameterPtr Param_md;
		Param_md.CreateInstance("ADODB.Parameter");
		Param_md = m_pCommand->CreateParameter("@�ܶ�", adVarChar, adParamInput, 50, (_variant_t)md);
		m_pCommand->Parameters->Append(Param_md);

		_ParameterPtr Param_hgllb;
		Param_hgllb.CreateInstance("ADODB.Parameter");
		Param_hgllb = m_pCommand->CreateParameter("@�������б�", adVarWChar, adParamInput, 50, (_variant_t)hgllb);
		m_pCommand->Parameters->Append(Param_hgllb);

		_ParameterPtr Param_dw;
		Param_dw.CreateInstance("ADODB.Parameter");
		Param_dw = m_pCommand->CreateParameter("@��λ", adVarWChar, adParamInput, 50, (_variant_t)dw);
		m_pCommand->Parameters->Append(Param_dw);

		_ParameterPtr Param_ys;
		Param_ys.CreateInstance("ADODB.Parameter");
		Param_ys = m_pCommand->CreateParameter("@��ɫ", adVarChar, adParamInput, 50, (_variant_t)ys);
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ExitConn();
	hang[10000] = {};
	k = 0;
	CDialogEx::OnClose();
}

BOOL Dlg_Stuff::ExitConn()
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


void Dlg_Stuff::OnNMDblclkListStuff(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;

	if (pEditCtrl->iItem == -1)//������ǹ�����
	{
		if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);//���ٵ�Ԫ��༭�����
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//���֮ǰ�����������б������ٵ�
		{
			distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if (pEditCtrl->iSubItem != 2 && pEditCtrl->iSubItem != 4 && pEditCtrl->iSubItem != 5 && pEditCtrl->iSubItem != 6)//��������Ա�ѡ��
	{
		hang[k] = pEditCtrl->iItem;
		lie[k] = pEditCtrl->iSubItem;
		k++;
		m_list_stuff.SetFocus();
		m_list_stuff.SetItemState(pEditCtrl->iItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
		if (haveccomboboxcreate == true)//���֮ǰ�����˱༭������ٵ�
		{
			distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
			{
				distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
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
	else if (pEditCtrl->iSubItem == 2)//������Ա�ѡ��
	{
		//hang[k] = pEditCtrl->iItem;
		//lie[k] = pEditCtrl->iSubItem;
		//k++;
		//if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		//{
		//	distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
		//	haveeditcreate = false;
		//}
		//if (haveccomboboxcreate == true)
		//{
		//	if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
		//	{
		//		distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
		//		haveccomboboxcreate = false;
		//		createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
		//		m_comBox.AddString(L"AUXL");
		//		m_comBox.AddString(L"COLP");
		//		m_comBox.ShowDropDown();//�Զ�����
		//	}
		//	else//���еĵ�Ԫ����֮ǰ�����õ�
		//	{
		//		m_comBox.SetFocus();//����Ϊ���� 
		//	}
		//}
		//else
		//{
		//	e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
		//	e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
		//	createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
		//	m_comBox.AddString(L"AUXL");
		//	m_comBox.AddString(L"COLP");
		//	m_comBox.ShowDropDown();//�Զ�����
		//}
	}
	else if (pEditCtrl->iSubItem == 4)//������Ա�ѡ��
	{
		//hang[k] = pEditCtrl->iItem;
		//lie[k] = pEditCtrl->iSubItem;
		//k++;
		//if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		//{
		//	distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
		//	haveeditcreate = false;
		//}
		//if (haveccomboboxcreate == true)
		//{
		//	if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
		//	{
		//		distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
		//		haveccomboboxcreate = false;
		//		createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
		//		m_comBox.AddString(L"B");
		//		m_comBox.AddString(L"");
		//		m_comBox.ShowDropDown();//�Զ�����
		//	}
		//	else//���еĵ�Ԫ����֮ǰ�����õ�
		//	{
		//		m_comBox.SetFocus();//����Ϊ���� 
		//	}
		//}
		//else
		//{
		//	e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
		//	e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
		//	createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
		//	m_comBox.AddString(L"B");
		//	m_comBox.AddString(L"");
		//	m_comBox.ShowDropDown();//�Զ�����
		//}
	}
	else if (pEditCtrl->iSubItem == 5)//������Ա�ѡ��
	{
		//hang[k] = pEditCtrl->iItem;
		//lie[k] = pEditCtrl->iSubItem;
		//k++;
		//if (haveeditcreate == true)//���֮ǰ�����˱༭������ٵ�
		//{
		//	distroyEdit(&m_list_stuff, &m_Edit, e_Item, e_SubItem);
		//	haveeditcreate = false;
		//}
		//if (haveccomboboxcreate == true)
		//{
		//	if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//������еĵ�Ԫ����֮ǰ�����õ�
		//	{
		//		distroyCcombobox(&m_list_stuff, &m_comBox, e_Item, e_SubItem);
		//		haveccomboboxcreate = false;
		//		createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
		//		m_comBox.AddString(L"cc");
		//		m_comBox.AddString(L"g");
		//		m_comBox.ShowDropDown();//�Զ�����
		//	}
		//	else//���еĵ�Ԫ����֮ǰ�����õ�
		//	{
		//		m_comBox.SetFocus();//����Ϊ���� 
		//	}
		//}
		//else
		//{
		//	e_Item = pEditCtrl->iItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
		//	e_SubItem = pEditCtrl->iSubItem;//�����еĵ�Ԫ����и�ֵ�����ձ༭�����С��Ա���ڴ���
		//	createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//�����༭��
		//	m_comBox.AddString(L"cc");
		//	m_comBox.AddString(L"g");
		//	m_comBox.ShowDropDown();//�Զ�����
		//}
	}
	else /*if (pEditCtrl->iSubItem == 6)*///������Ա�ѡ��
	{
		//hang[k] = pEditCtrl->iItem;
		//lie[k] = pEditCtrl->iSubItem;
		//k++;
		//COLORREF color;      // ��ɫ�Ի���ĳ�ʼ��ɫΪ��ɫ   
		//CColorDialog colorDlg;         // ������ɫ�Ի��򣬴����ʼ��ɫֵ   
		//if (IDOK == colorDlg.DoModal())       // ��ʾ��ɫ�Ի��򣬲��ж��Ƿ����ˡ�ȷ����   
		//{
		//	color = colorDlg.GetColor();      // ��ȡ��ɫ�Ի�����ѡ�����ɫֵ   
		//	Rgb[pEditCtrl->iItem] = color;
		//	SetDlgItemInt(IDC_EDIT1, color);
		//}

	}

	*pResult = 0;
}


void Dlg_Stuff::OnTbStuffNew()
{
	// TODO: �ڴ���������������
	int nItem = m_list_stuff.GetItemCount();
	//m_list_form.SetItemState(6, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
	m_list_stuff.SetItemState(nItem - 1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_list_stuff.EnsureVisible(nItem - 1, FALSE);
}
