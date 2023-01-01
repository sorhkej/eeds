// Dlg_Formula_Guide.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "Dlg_Formula_Guide.h"
#include "afxdialogex.h"

int functionNum;
// Dlg_Formula_Guide �Ի���

IMPLEMENT_DYNAMIC(Dlg_Formula_Guide, CDialogEx)

Dlg_Formula_Guide::Dlg_Formula_Guide(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_FORMULA_GUIDE, pParent)
{

}

Dlg_Formula_Guide::~Dlg_Formula_Guide()
{
}

void Dlg_Formula_Guide::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FORMULA, m_list);
}


BEGIN_MESSAGE_MAP(Dlg_Formula_Guide, CDialogEx)
	ON_NOTIFY(LVN_BEGINDRAG, IDC_LIST_FORMULA, &Dlg_Formula_Guide::OnLvnBegindragListFormula)
//	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_BN_CLICKED(IDOK, &Dlg_Formula_Guide::OnBnClickedOk)
END_MESSAGE_MAP()


// Dlg_Formula_Guide ��Ϣ�������


void Dlg_Formula_Guide::OnLvnBegindragListFormula(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	
	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;
	if (pEditCtrl->iItem == -1)//������ǹ�����
	{
	}
	else
	{
		formulaFlag = 1;
		code = m_list.GetItemText(pEditCtrl->iItem, 0);
		row = pEditCtrl->iItem;
	}


	*pResult = 0;
}


void Dlg_Formula_Guide::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	formulaFlag = 0;
	code = _T("");

	CDialogEx::OnLButtonDown(nFlags, point);
}


void Dlg_Formula_Guide::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC *pDC = GetDC();
	CString digit1, digit2, digit3;
	if (code != _T("") && formulaFlag == 1)
	{
		int i = 1, j = 0, k = 0, c = 0, flag[4][2][3] = {};
		while (i <= 4)
		{
			j = 1;
			c = 1;
			while (j <= 2)
			{
				k = 1;
				while (k <= 3)
				{
					if (flag[i][j][k] != 1)
					{


						if (point.x > 100 + (c - 1) * 225 && point.x < 100 + (c - 1) * 225 + 255 && point.y > 380 + (i - 1) * 70 && point.y < 420 + (i - 1) * 70)
						{
							bottle = _T("V");
							if (j == 1)
							{
								digit2 = _T("A");
							}
							else
							{
								digit2 = _T("B");
							}
							digit1.Format(_T("%d"), i);
							digit3.Format(_T("%d"), k);
							bottle = bottle + digit1 + digit2 + digit3;
							ClearText();
							m_list.SetItemText(row, 2, bottle);
						}
					}
					k++;
					c++;
				}
				j++;
			}
			i++;
		}

	}


	ReleaseDC(pDC);
	CheckState();
	RefreshText();



	CDialogEx::OnLButtonUp(nFlags, point);
}


BOOL Dlg_Formula_Guide::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	int i = 1, j = 0, k = 0, c = 0;
	while (i <= 4)
	{
		j = 1;
		c = 1;
		while (j <= 2)
		{
			k = 1;
			while (k <= 3)
			{

				/*NewSt(3000 + i * 100 + j * 10 + k, CRect(20, 20, 225, 40));
				GetDlgItem(3000 + i * 100 + j * 10 + k)->MoveWindow(100 + (c - 1) * 225, 380 + (i - 1) * 70, 225, 40);*/
				NewSt(3000 + i * 100 + j * 10 + k, CRect(20, 20, 1, 1));
				if (GetDlgItem(3000 + i * 100 + j * 10 + k))
				{
					GetDlgItem(3000 + i * 100 + j * 10 + k)->MoveWindow(100 + (c - 1) * 225, 380 + (i - 1) * 70, 225, 40);
				}
				int b = 3000 + i * 100 + j * 10 + k;
				k++;
				c++;
			}
			j++;
		}
		i++;
	}


	
	CheckData();

	rowSum = m_list.GetItemCount();


	CheckState();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

_RecordsetPtr& Dlg_Formula_Guide::GetRecordSet(_bstr_t bstrSQL)           //�򿪼�¼������ʼ��Listcontrol�ؼ��������ݿ�����
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

CStatic* Dlg_Formula_Guide::NewSt(int nID, CRect rect)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //ȡ��ť����
	CStatic *p_Button = new CStatic();
	ASSERT_VALID(p_Button);
	p_Button->Create(m_Caption, WS_CHILD | WS_VISIBLE , rect, this, nID);  //������ť
	return p_Button;
}

void Dlg_Formula_Guide::RefreshText()
{

	int hs = 0;
	CString digit1, digit2, digit3;
	while (hs < rowSum)
	{
		int i = 1, j = 0, k = 0, c = 0;
		 bottle = m_list.GetItemText(hs, 2);
		code = m_list.GetItemText(hs, 0);
		while (i <= 4)
		{
			j = 1;
			c = 1;
			while (j <= 2)
			{
				k = 1;
				while (k <= 3)
				{
					position = _T("V");
					if (j == 1)
					{
						digit2 = _T("A");
					}
					else
					{
						digit2 = _T("B");
					}
					digit1.Format(_T("%d"), i);
					digit3.Format(_T("%d"), k);
					position = position + digit1 + digit2 + digit3;
					if (bottle == position)
					{
						int b = 3000 + i * 100 + j * 10 + k;
						GetDlgItem(b)->SetWindowTextW(position + _T(":") + code);
					}
					
					k++;
				}
				j++;
			}
			i++;
		}
		
		hs++;
	}
}

void Dlg_Formula_Guide::ClearText()
{
	int hs = 0;
	CString digit1, digit2, digit3;
	while (hs < rowSum)
	{

		int i = 1, j = 0, k = 0, c = 0;
		while (i <= 4)
		{
			j = 1;
			c = 1;
			while (j <= 2)
			{
				k = 1;
				while (k <= 3)
				{
							position = _T("V");
							if (j == 1)
							{
								digit2 = _T("A");
							}
							else
							{
								digit2 = _T("B");
							}
							digit1.Format(_T("%d"), i);
							digit3.Format(_T("%d"), k);
							position = position + digit1 + digit2 + digit3;
							if (bottle == position)
							{
								if (m_list.GetItemText(hs, 2) == position)
								{
									m_list.SetItemText(hs, 2, _T(""));
								}
							}
			
							k++;
				}
				j++;
			}
			i++;
		}
		
		hs++;
	}
}

CStatic* Dlg_Formula_Guide::NewPic(int nID, CRect rect)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //ȡ��ť����
	CStatic *pPictureControl = new CStatic();
	ASSERT_VALID(pPictureControl);
	pPictureControl->Create(_T(""), WS_CHILD | WS_VISIBLE | SS_BITMAP, rect, this, nID);  //������ť
	return pPictureControl;
}

void Dlg_Formula_Guide::CheckData()//�����ݿ���в�ѯ����
{
	CString sql;
	sql.Format(_T("select* from Formula_Detailed order by ���� desc"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);

	m_list.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
		| LVS_EX_FULLROWSELECT
		| LVS_EX_HEADERDRAGDROP
		| LVS_EX_ONECLICKACTIVATE
		| LVS_EX_GRIDLINES);
	while (m_list.DeleteColumn(0));	//������б�ͷ
	m_list.DeleteAllItems();

	CFont m_font;
	m_font.CreatePointFont(100, _T("΢���ź�"));
	m_list.SetFont(&m_font);

	m_list.InsertColumn(0, _T("����"), LVCFMT_LEFT, 200, 2);
	m_list.InsertColumn(1, _T("����"), LVCFMT_LEFT, 200, 2);
	m_list.InsertColumn(2, _T("λ��"), LVCFMT_LEFT, 300, 2);




		m_pRecordset->MoveFirst();

	while (m_pRecordset->adoEOF == 0)                   //���δ��������¼�����һ�У���Ϊ�б�����Ӽ����������ݡ�������¼����
	{
		CString position = m_pRecordset->GetCollect(_T("����λ��"));
		if (position == _T(""))
		{
			m_list.InsertItem(0, _T(""));
			m_list.SetItemText(0, 0, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
			m_list.SetItemText(0, 1, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����")));
			m_list.SetItemText(0, 2, (LPCTSTR)(LPTSTR)(_bstr_t)m_pRecordset->GetCollect(_T("����λ��")));
		}
		m_pRecordset->MoveNext();
	}

}

void Dlg_Formula_Guide::CheckState()//�����ݿ���в�ѯ����
{
	CString sql;
	sql.Format(_T("select* from Formula_Position order by λ��"));            //ʹ��sql����SQL������Ϊcontact��ͨ���С��ֻ����롱���������У�asc�������������У�desc��
	GetRecordSet((_bstr_t)sql);

	CString digit1, digit2, digit3;

	//int i = 0, j = 0;
	int i = 1, j = 1, k = 0, c = 1, flag[4][2][3] = {};
	while (m_pRecordset->adoEOF == 0)
	{
		code = m_pRecordset->GetCollect(_T("����"));


		if (j == 2 && k == 3)
		{
			i++;
			j = k = 1;
		}
		else
		{
			if (k < 3)
			{
				k++;
			}
			else
			{
				j++;
				k = 1;
			}
		}
		int b = 3000 + i * 100 + j * 10 + k;

		bottle = _T("V");
		if (j == 1)
		{
			digit2 = _T("A");
		}
		else
		{
			digit2 = _T("B");
		}
		digit1.Format(_T("%d"), i);
		digit3.Format(_T("%d"), k);
		bottle = bottle + digit1 + digit2 + digit3;

		GetDlgItem(b)->SetWindowTextW(bottle);
		if (code != _T(""))
		{
			
			GetDlgItem(b)->SetWindowTextW(bottle + _T(":") + code);
			//flag[i][j][k] = 1;
		}
		//else
		//{
		//	GetDlgItem(b)->SetWindowTextW(bottle);
		//	flag[i][j][k] = 0;
		//}
	

		m_pRecordset->MoveNext();
	}

}

void Dlg_Formula_Guide::AddData()
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Add_Formula_Position";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_bottle;
		Param_bottle.CreateInstance("ADODB.Parameter");
		Param_bottle = m_pCommand->CreateParameter("@λ��", adVarWChar, adParamInput, 50, (_variant_t)bottle);
		m_pCommand->Parameters->Append(Param_bottle);

		_ParameterPtr Param_code;
		Param_code.CreateInstance("ADODB.Parameter");
		Param_code = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)code);
		m_pCommand->Parameters->Append(Param_code);

		_ParameterPtr Param_name;
		Param_name.CreateInstance("ADODB.Parameter");
		Param_name = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)name);
		m_pCommand->Parameters->Append(Param_name);

		_ParameterPtr Param_remark;
		Param_remark.CreateInstance("ADODB.Parameter");
		Param_remark = m_pCommand->CreateParameter("@��ע", adVarWChar, adParamInput, 50, (_variant_t)remark);
		m_pCommand->Parameters->Append(Param_remark);

		_ParameterPtr Param_weight;
		Param_weight.CreateInstance("ADODB.Parameter");
		Param_weight = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)weight);
		m_pCommand->Parameters->Append(Param_weight);

		_ParameterPtr Param_capacity;
		Param_capacity.CreateInstance("ADODB.Parameter");
		Param_capacity = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)capacity);
		m_pCommand->Parameters->Append(Param_capacity);

		//m_pRecordset = m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);
	}
	catch (_com_error&e)
	{
		AfxMessageBox(e.Description());
	}
	m_pCommand.Detach();
}



void Dlg_Formula_Guide::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int hs = 0;
	while (hs < rowSum)
	{
		bottle = m_list.GetItemText(hs, 2);
		if (bottle != _T("")) 
		{
			code = m_list.GetItemText(hs, 0);
			name = m_list.GetItemText(hs, 1);
			

			SearchData();
			remark = m_pRecordset->GetCollect(_T("��ע"));
			weight = m_pRecordset->GetCollect(_T("����"));
			capacity = m_pRecordset->GetCollect(_T("����"));
			idNum = m_pRecordset->GetCollect(_T("ID"));
			AddData();
			DeleteData();
		}

		hs++;
	}

	
	ExitConn();
	formulaNum = functionNum = 1;
	CDialogEx::OnOK();
}


BOOL Dlg_Formula_Guide::ExitConn()
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

void Dlg_Formula_Guide::SearchData()
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Search_Formula_Detailed";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_code;
		Param_code.CreateInstance("ADODB.Parameter");
		Param_code = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)code);
		m_pCommand->Parameters->Append(Param_code);

		_ParameterPtr Param_name;
		Param_name.CreateInstance("ADODB.Parameter");
		Param_name = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)name);
		m_pCommand->Parameters->Append(Param_name);



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

void Dlg_Formula_Guide::DeleteData()
{
	m_pCommand.CreateInstance("ADODB.Command");//ʵ��
	m_pCommand->ActiveConnection = m_pConnection;//�������ӣ������˰�
	m_pCommand->CommandText = "Delete_Formula_Detailed";//�洢����ΪCorn_ADD
	try
	{
		_ParameterPtr Param_code;
		Param_code.CreateInstance("ADODB.Parameter");
		Param_code = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)code);
		m_pCommand->Parameters->Append(Param_code);

		_ParameterPtr Param_name;
		Param_name.CreateInstance("ADODB.Parameter");
		Param_name = m_pCommand->CreateParameter("@����", adVarWChar, adParamInput, 50, (_variant_t)name);
		m_pCommand->Parameters->Append(Param_name);

		_ParameterPtr Param_idNum;
		Param_idNum.CreateInstance("ADODB.Parameter");
		Param_idNum = m_pCommand->CreateParameter("@ID", adInteger, adParamInput, 50, idNum);
		m_pCommand->Parameters->Append(Param_idNum);

		m_pCommand->Execute(NULL, NULL, adCmdStoredProc);

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