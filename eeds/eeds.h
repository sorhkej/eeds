
// eeds.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CeedsApp: 
// �йش����ʵ�֣������ eeds.cpp
//

class CeedsApp : public CWinApp
{
public:
	CeedsApp();
	_ConnectionPtr m_pCon;
	BOOL ConnectDataBase(CString strLinkWord);
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CeedsApp theApp;