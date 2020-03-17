
// MFC_0317_2View.cpp : CMFC_0317_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_0317_2.h"
#endif

#include "MFC_0317_2Doc.h"
#include "MFC_0317_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0317_2View

IMPLEMENT_DYNCREATE(CMFC_0317_2View, CView)

BEGIN_MESSAGE_MAP(CMFC_0317_2View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC_0317_2View 构造/析构

CMFC_0317_2View::CMFC_0317_2View()
{
	// TODO: 在此处添加构造代码

}

CMFC_0317_2View::~CMFC_0317_2View()
{
}

BOOL CMFC_0317_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0317_2View 绘制

void CMFC_0317_2View::OnDraw(CDC* pDC)
{
	CMFC_0317_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0317_2View 诊断

#ifdef _DEBUG
void CMFC_0317_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0317_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0317_2Doc* CMFC_0317_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0317_2Doc)));
	return (CMFC_0317_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0317_2View 消息处理程序


void CMFC_0317_2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC_0317_2Doc* pDoc = GetDocument();
	CRect c;
	GetClientRect(&c);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->cr.left > 0)
		{
			pDoc->cr.left -= 5;
			pDoc->cr.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->cr.right <= (c.right - c.left))
		{
			pDoc->cr.left += 5;
			pDoc->cr.right += 5;
		}
		break;
	case VK_UP:
		if (pDoc->cr.top > 0)
		{
			pDoc->cr.top -= 5;
			pDoc->cr.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->cr.bottom <= (c.bottom - c.top))
		{
			pDoc->cr.top += 5;
			pDoc->cr.bottom += 5;
		}
		break;
	case VK_HOME:
		if (pDoc->cr.bottom - pDoc->cr.top >= 0 && pDoc->cr.right - pDoc->cr.left >= 0)
		{
			pDoc->cr.left -= 5;
			pDoc->cr.top -= 5;
		}
		break;
	case VK_END:
		if (pDoc->cr.bottom - pDoc->cr.top >= 0 && pDoc->cr.right - pDoc->cr.left >= 0)
		{
			pDoc->cr.left += 5;
			pDoc->cr.top += 5;
		}
		break;
}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC_0317_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC_0317_2Doc* pDoc = GetDocument(); 
	pDoc->cr.left = 30;
	pDoc->cr.top = 30;
	pDoc->cr.right = 80;
	pDoc->cr.bottom = 80;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
