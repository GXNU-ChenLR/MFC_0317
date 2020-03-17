
// MFC_0317_1View.cpp : CMFC_0317_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC_0317_1View ����/����

CMFC_0317_1View::CMFC_0317_1View()
{
	// TODO: �ڴ˴���ӹ������
	count = 0; a = 0;
}

CMFC_0317_1View::~CMFC_0317_1View()
{
}

BOOL CMFC_0317_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_0317_1View ����

void CMFC_0317_1View::OnDraw(CDC* /*pDC*/)
{
	CMFC_0317_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_0317_1View ���

#ifdef _DEBUG
void CMFC_0317_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0317_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0317_1Doc* CMFC_0317_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0317_1Doc)));
	return (CMFC_0317_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0317_1View ��Ϣ�������


void CMFC_0317_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC_0317_1Doc* pDoc = GetDocument();
	GetCapture();
	pDoc->x = point.x;
	pDoc->y = point.y;
	a = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC_0317_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC_0317_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	ReleaseCapture();
	CClientDC dc(this);
	int a;
	a = (point.x - pDoc->x) / count;
	CString ss;
	ss.Format(_T("ƽ��ÿ�κ����ƶ�%d������"), a);
	dc.TextOutW(200, 20, ss);
	CView::OnLButtonUp(nFlags, point);
}


void CMFC_0317_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC_0317_1Doc* pDoc = GetDocument();

	/*CString s;
	s.Format(_T("X=%d Y=%d"), point.x, point.y);
	CClientDC dc(this);
	dc.TextOutW(20, 20, s);

	if (point.x - pDoc->x == 10 && point.y - pDoc->y == 10)
	{
		pDoc->countx+=1;
		pDoc->county+=1;
	}
	CString ss;
	ss.Format(_T("�ƶ�������X=%d Y=%d"), pDoc->countx,pDoc->county);
	dc.TextOutW(200, 20, ss);*/
	if (a == 1)
		count++;
	CClientDC dc(this);
	CString s;
	s.Format(_T("�ƶ�������%d"), count);
	dc.TextOutW(20, 20, s);
	CView::OnMouseMove(nFlags, point);
}
