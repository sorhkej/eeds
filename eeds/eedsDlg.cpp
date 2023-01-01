
// eedsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "eeds.h"
#include "eedsDlg.h"
#include "afxdialogex.h"
#include "Dlg_Guide.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CeedsDlg �Ի���
_RecordsetPtr CeedsDlg::DBRecordSetGet(LPCTSTR sql)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	m_pRec.CreateInstance("ADODB.Recordset");
	m_pRec = m_pCon->Execute((_bstr_t)sql, NULL, adCmdText);

	return m_pRec;
}

BOOL CeedsDlg::GetCollect(LPCTSTR Name, _variant_t& OutCol)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	_variant_t vt;
	vt = m_pRec->GetCollect(Name);
	if (vt.vt != VT_NULL)
	{
		OutCol = vt;
		return TRUE;
	}
	else
		return FALSE;
}



CeedsDlg::CeedsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EEDS_DIALOG, pParent)
	, m_Acc(_T(""))
	, m_Pwd(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CeedsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Acc);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
}

BEGIN_MESSAGE_MAP(CeedsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CeedsDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CeedsDlg ��Ϣ�������

BOOL CeedsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CeedsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CeedsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CeedsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CeedsDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);			//���ؼ���ֵ��ֵ����Ա����

	CString sql;				//��ȡ��ѧ���������ƥ��
	sql.Format(L"exec Login_Account '%s','%s'", m_Acc, m_Pwd);
	m_pRec = DBRecordSetGet(sql);		//ִ��SQL���

	_variant_t var;
	GetCollect(L"nums", var);
	int temp = var.intVal;

	//ExitConn();
	m_pRec = NULL;
	//ѧ��������ȷ����ʾѧ����Ϣ
	if (temp)
	{
		ExitConn();
		OnCancel();
		Dlg_Guide dlg_guide;
		//dlg_guide.m_pCon = m_pCon;	//ע��m_pCon�Ĵ���
		//dlg_guide.m_Acc = m_Acc;
		dlg_guide.DoModal();
		//CDialogEx::OnOK();
	}
	else
	{
		CString str;
		str.Format(L"error");
		MessageBox(str);
	}
}

BOOL CeedsDlg::ExitConn()
{
	//�رռ�¼��������
	if (m_pRec != NULL)
	{
		m_pRec->Close();
	}
	m_pRec = NULL;
	m_pCon->Close();
	::CoUninitialize(); //�������Ϊ�ر�COM�����

	return TRUE;
}