
// MFC_0317_1View.cpp : CMFC_0317_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_0317_1.h"
#endif

#include "MFC_0317_1Doc.h"
#include "MFC_0317_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0317_1View

IMPLEMENT_DYNCREATE(CMFC_0317_1View, CView)

BEGIN_MESSAGE_MAP(CMFC_0317_1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC_0317_1View 构造/析构

CMFC_0317_1View::CMFC_0317_1View()
{
	// TODO: 在此处添加构造代码
	count = 0; acount = 0;
}

CMFC_0317_1View::~CMFC_0317_1View()
{
}

BOOL CMFC_0317_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0317_1View 绘制

void CMFC_0317_1View::OnDraw(CDC* /*pDC*/)
{
	CMFC_0317_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0317_1View 诊断

#ifdef _DEBUG
void CMFC_0317_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0317_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0317_1Doc* CMFC_0317_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0317_1Doc)));
	return (CMFC_0317_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0317_1View 消息处理程序


void CMFC_0317_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC_0317_1Doc* pDoc = GetDocument();
	GetCapture();
	pDoc->x = point.x;
	pDoc->y = point.y;
	acount = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC_0317_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC_0317_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	acount = 0;
	ReleaseCapture();
	CClientDC dc(this);
	int a;
	int sum = 0;
	sum += point.x - pDoc->x;
	a = sum / count;
	CString ss,aa;
	ss.Format(_T("平均每次横向移动%d个像素"), a);
	aa.Format(_T("point.x=%d,pDoc->x=%d"), point.x, pDoc->x);
	dc.TextOutW(200, 20, ss);
	dc.TextOutW(300, 50, aa);
	CView::OnLButtonUp(nFlags, point);
}


void CMFC_0317_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC_0317_1Doc* pDoc = GetDocument();

	if (acount == 1)
		count++;
	CClientDC dc(this);
	CString s;
	s.Format(_T("移动次数：%d"), count);
	dc.TextOutW(20, 20, s);
	CView::OnMouseMove(nFlags, point);
}
