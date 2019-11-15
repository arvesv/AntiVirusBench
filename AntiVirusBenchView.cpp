
// AntiVirusBenchView.cpp : implementation of the CAntiVirusBenchView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "AntiVirusBench.h"
#endif

#include "AntiVirusBenchDoc.h"
#include "AntiVirusBenchView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAntiVirusBenchView

IMPLEMENT_DYNCREATE(CAntiVirusBenchView, CView)

BEGIN_MESSAGE_MAP(CAntiVirusBenchView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, &CAntiVirusBenchView::OnCancelEditSrvr)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CAntiVirusBenchView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CAntiVirusBenchView construction/destruction

CAntiVirusBenchView::CAntiVirusBenchView() noexcept
{
	// TODO: add construction code here

}

CAntiVirusBenchView::~CAntiVirusBenchView()
{
}

BOOL CAntiVirusBenchView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CAntiVirusBenchView drawing

void CAntiVirusBenchView::OnDraw(CDC* /*pDC*/)
{
	CAntiVirusBenchDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CAntiVirusBenchView printing


void CAntiVirusBenchView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CAntiVirusBenchView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAntiVirusBenchView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAntiVirusBenchView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CAntiVirusBenchView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAntiVirusBenchView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation
void CAntiVirusBenchView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}


// CAntiVirusBenchView diagnostics

#ifdef _DEBUG
void CAntiVirusBenchView::AssertValid() const
{
	CView::AssertValid();
}

void CAntiVirusBenchView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAntiVirusBenchDoc* CAntiVirusBenchView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAntiVirusBenchDoc)));
	return (CAntiVirusBenchDoc*)m_pDocument;
}
#endif //_DEBUG


// CAntiVirusBenchView message handlers
