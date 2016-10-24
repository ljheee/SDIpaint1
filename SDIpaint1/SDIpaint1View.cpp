
// SDIpaint1View.cpp : CSDIpaint1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
	ON_COMMAND(ID_SET_COLOR, &CSDIpaint1View::OnSetColor)
	ON_COMMAND(ID_SET_FONT, &CSDIpaint1View::OnSetFont)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()

// CSDIpaint1View 构造/析构

CSDIpaint1View::CSDIpaint1View()
{
	// TODO:  在此处添加构造代码
	m_brBkgnd.CreateSolidBrush(RGB(255, 255, 255));//构造画刷
	m_font.CreatePointFont(120, _T("宋体"));

}

CSDIpaint1View::~CSDIpaint1View()
{
}

BOOL CSDIpaint1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// 启用换行

	return bPreCreated;
}


// CSDIpaint1View 打印

BOOL CSDIpaint1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认 CEditView 准备
	return CEditView::OnPreparePrinting(pInfo);
}

void CSDIpaint1View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 开始打印
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CSDIpaint1View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 结束打印
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CSDIpaint1View 诊断

#ifdef _DEBUG
void CSDIpaint1View::AssertValid() const
{
	CEditView::AssertValid();
}

void CSDIpaint1View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CSDIpaint1Doc* CSDIpaint1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIpaint1Doc)));
	return (CSDIpaint1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSDIpaint1View 消息处理程序


//点击菜单项---设置颜色
void CSDIpaint1View::OnSetColor()
{
	// TODO:  在此添加命令处理程序代码
	COLORREF color = RGB(0,0,0);//默认颜色
	CColorDialog cdlg(color, CC_FULLOPEN | CC_RGBINIT); // 设置默认颜色
	if (cdlg.DoModal() == IDOK)
		m_clrText = cdlg.GetColor();	//m_clrText在头文件，是全局变量


//	CDC* dc = GetDC();
//	dc->SelectObject(&color);
//	dc->SetTextColor(RGB( 255, 0, 0)); //此方法没有实现字色改变
}

//点击菜单项---设置字体
void CSDIpaint1View::OnSetFont()
{
	// TODO:  在此添加命令处理程序代码
	LOGFONT lf;

	CFont *ft = this->GetEditCtrl().GetFont();
	if (ft == NULL)
	{
		ft = new CFont;
		ft->CreatePointFont(120, _T("隶书"));
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

//实现视图类---- =WM_CTLCOLOR   反射消息
HBRUSH CSDIpaint1View::CtlColor(CDC* pDC, UINT /*nCtlColor*/)
{
	// TODO:  在此更改 DC 的任何特性
	pDC->SetTextColor(m_clrText);         //   text 

	return   m_brBkgnd;                               

	// TODO:  如果不应调用父级的处理程序，则返回非 null 画笔
//	return NULL;
}
