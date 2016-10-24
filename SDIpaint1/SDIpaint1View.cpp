
// SDIpaint1View.cpp : CSDIpaint1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SDIpaint1.h"
#endif

#include "SDIpaint1Doc.h"
#include "SDIpaint1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIpaint1View

IMPLEMENT_DYNCREATE(CSDIpaint1View, CEditView)

BEGIN_MESSAGE_MAP(CSDIpaint1View, CEditView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
	ON_COMMAND(ID_SET_COLOR, &CSDIpaint1View::OnSetColor)
	ON_COMMAND(ID_SET_FONT, &CSDIpaint1View::OnSetFont)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()

// CSDIpaint1View ����/����

CSDIpaint1View::CSDIpaint1View()
{
	// TODO:  �ڴ˴���ӹ������
	m_brBkgnd.CreateSolidBrush(RGB(255, 255, 255));//���컭ˢ
	m_font.CreatePointFont(120, _T("����"));

}

CSDIpaint1View::~CSDIpaint1View()
{
}

BOOL CSDIpaint1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ���û���

	return bPreCreated;
}


// CSDIpaint1View ��ӡ

BOOL CSDIpaint1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ׼��
	return CEditView::OnPreparePrinting(pInfo);
}

void CSDIpaint1View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ��ʼ��ӡ
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CSDIpaint1View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ������ӡ
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CSDIpaint1View ���

#ifdef _DEBUG
void CSDIpaint1View::AssertValid() const
{
	CEditView::AssertValid();
}

void CSDIpaint1View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CSDIpaint1Doc* CSDIpaint1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIpaint1Doc)));
	return (CSDIpaint1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSDIpaint1View ��Ϣ�������


//����˵���---������ɫ
void CSDIpaint1View::OnSetColor()
{
	// TODO:  �ڴ���������������
	COLORREF color = RGB(0,0,0);//Ĭ����ɫ
	CColorDialog cdlg(color, CC_FULLOPEN | CC_RGBINIT); // ����Ĭ����ɫ
	if (cdlg.DoModal() == IDOK)
		m_clrText = cdlg.GetColor();	//m_clrText��ͷ�ļ�����ȫ�ֱ���


//	CDC* dc = GetDC();
//	dc->SelectObject(&color);
//	dc->SetTextColor(RGB( 255, 0, 0)); //�˷���û��ʵ����ɫ�ı�
}

//����˵���---��������
void CSDIpaint1View::OnSetFont()
{
	// TODO:  �ڴ���������������
	LOGFONT lf;

	CFont *ft = this->GetEditCtrl().GetFont();
	if (ft == NULL)
	{
		ft = new CFont;
		ft->CreatePointFont(120, _T("����"));
		ft->GetLogFont(&lf);
		delete ft;
	}
	else
	{
		ft->GetLogFont(&lf);
	}

	CFontDialog cf(&lf);
	if (cf.DoModal() == IDOK)
	{
		m_font.DeleteObject();
		m_font.CreateFontIndirect(&lf);
		CEditView::SetFont(&m_font);
	}

}

//ʵ����ͼ��---- =WM_CTLCOLOR   ������Ϣ
HBRUSH CSDIpaint1View::CtlColor(CDC* pDC, UINT /*nCtlColor*/)
{
	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetTextColor(m_clrText);         //   text 

	return   m_brBkgnd;                               

	// TODO:  �����Ӧ���ø����Ĵ�������򷵻ط� null ����
//	return NULL;
}
