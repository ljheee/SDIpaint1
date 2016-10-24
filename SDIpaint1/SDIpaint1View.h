
// SDIpaint1View.h : CSDIpaint1View 类的接口
//

#pragma once


class CSDIpaint1View : public CEditView
{
protected: // 仅从序列化创建
	CSDIpaint1View();
	DECLARE_DYNCREATE(CSDIpaint1View)

// 特性
public:
	CSDIpaint1Doc* GetDocument() const;

	COLORREF   m_clrText;       //记录文本颜色 
	CBrush   m_brBkgnd;     //用于绘制背景的刷子 

	CFont m_font;
// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSDIpaint1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSetColor();
	afx_msg void OnSetFont();
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};

#ifndef _DEBUG  // SDIpaint1View.cpp 中的调试版本
inline CSDIpaint1Doc* CSDIpaint1View::GetDocument() const
   { return reinterpret_cast<CSDIpaint1Doc*>(m_pDocument); }
#endif

