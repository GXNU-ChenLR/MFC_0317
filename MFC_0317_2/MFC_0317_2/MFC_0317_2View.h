
// MFC_0317_2View.h : CMFC_0317_2View ��Ľӿ�
//

#pragma once


class CMFC_0317_2View : public CView
{
protected: // �������л�����
	CMFC_0317_2View();
	DECLARE_DYNCREATE(CMFC_0317_2View)

// ����
public:
	CMFC_0317_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC_0317_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_0317_2View.cpp �еĵ��԰汾
inline CMFC_0317_2Doc* CMFC_0317_2View::GetDocument() const
   { return reinterpret_cast<CMFC_0317_2Doc*>(m_pDocument); }
#endif
