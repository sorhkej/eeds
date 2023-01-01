// DIALOG_LIQU.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "DIALOG_LIQU.h"
#include "afxdialogex.h"
#include "DIALOG_POSI.h"

// DIALOG_LIQU �Ի���


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


// DIALOG_LIQU ��Ϣ�������


BOOL DIALOG_LIQU::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//MessageBox(asdasd);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

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



	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

_RecordsetPtr& DIALOG_LIQU::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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

void DIALOG_LIQU::CheckData()//�����ݿ���в�ѯ����
{
	CString sql;
	sql.Format(_T("select* from Position  order by ƿ�� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);



	//rnum = 0;

	m_list_pos.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list_pos.DeleteColumn(0));	//������б�ͷ
	m_list_pos.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_list_pos.SetFont(&m_font);

	m_list_pos.InsertColumn(0, _T("ƿ��"), LVCFMT_LEFT, 200, 2);         //Ϊ�б�������У��������ֻ����룬��ϵ����ע
	m_list_pos.InsertColumn(1, _T("��Һ"), LVCFMT_LEFT, 200, 2);
	m_list_pos.InsertColumn(2, _T("Ũ��"), LVCFMT_LEFT, 150, 2);
	m_list_pos.InsertColumn(3, _T("�ݻ�"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(4, _T("ʱ��"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(5, _T("״̬"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(6, _T("��ֹʱ��"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(7, _T("��С������"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(8, _T("��С�ݻ�"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(9, _T("����ݻ�"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(10, _T("ʵ���ݻ�"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(11, _T("Ƥ��"), LVCFMT_LEFT, 100, 2);
	m_list_pos.InsertColumn(12, _T("Ԥ���ݻ�"), LVCFMT_LEFT, 100, 2);


	m_pRecordset->MoveFirst();
	//while (m_pRecordset->adoEOF == 0)
	//{
	//	rnum++;
	//	m_pRecordset->MoveNext();
	//}
	//sum = rnum - 1;
	//rnum = 0;
	//m_pRecordset->MoveFirst();

	while (m_pRecordset->adoEOF == 0)                   //���δ��������¼�����һ�У���Ϊ�б�����Ӽ����������ݡ�������¼����
	{
		CString ry = m_pRecordset->GetCollect(_T("��Һ"));
		if(ry != _T(""))
		{
			m_list_pos.InsertItem(0, _T(""));
			m_list_pos.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("ƿ��")));
			m_list_pos.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��Һ")));      //��¼��ѡ����б��������ݿ��б����ܹ��ҵ�����Ȼ����
			m_list_pos.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("�ݻ�")));
			m_list_pos.SetItemText(0, 4, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("ʱ��")));
			m_list_pos.SetItemText(0, 5, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("״̬")));
			m_list_pos.SetItemText(0, 6, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��ֹʱ��")));
			m_list_pos.SetItemText(0, 7, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��С������")));
			m_list_pos.SetItemText(0, 8, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("��С�ݻ�")));
			m_list_pos.SetItemText(0, 9, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����ݻ�")));
			m_list_pos.SetItemText(0, 10, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("ʵ���ݻ�")));
			m_list_pos.SetItemText(0, 11, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("Ƥ��")));
			m_list_pos.SetItemText(0, 12, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("Ԥ���ݻ�")));
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