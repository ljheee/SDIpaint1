
// SDIpaint1.h : SDIpaint1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSDIpaint1App:
// �йش����ʵ�֣������ SDIpaint1.cpp
//

class CSDIpaint1App : public CWinApp
{
public:
	CSDIpaint1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIpaint1App theApp;
