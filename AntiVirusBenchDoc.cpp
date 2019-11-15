
// AntiVirusBenchDoc.cpp : implementation of the CAntiVirusBenchDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "AntiVirusBench.h"
#endif

#include "AntiVirusBenchDoc.h"
#include "SrvrItem.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAntiVirusBenchDoc

IMPLEMENT_DYNCREATE(CAntiVirusBenchDoc, COleServerDoc)

BEGIN_MESSAGE_MAP(CAntiVirusBenchDoc, COleServerDoc)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAntiVirusBenchDoc, COleServerDoc)
END_DISPATCH_MAP()

// Note: we add support for IID_IAntiVirusBench to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the
//  dispinterface in the .IDL file.

// {ea6a859c-4176-42db-aa0d-8f7419b88902}
static const IID IID_IAntiVirusBench =
{0xea6a859c,0x4176,0x42db,{0xaa,0x0d,0x8f,0x74,0x19,0xb8,0x89,0x02}};

BEGIN_INTERFACE_MAP(CAntiVirusBenchDoc, COleServerDoc)
	INTERFACE_PART(CAntiVirusBenchDoc, IID_IAntiVirusBench, Dispatch)
END_INTERFACE_MAP()


// CAntiVirusBenchDoc construction/destruction

CAntiVirusBenchDoc::CAntiVirusBenchDoc() noexcept
{
	// Use OLE compound files
	EnableCompoundFile();

	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CAntiVirusBenchDoc::~CAntiVirusBenchDoc()
{
	AfxOleUnlockApp();
}

BOOL CAntiVirusBenchDoc::OnNewDocument()
{
	if (!COleServerDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


// CAntiVirusBenchDoc server implementation

COleServerItem* CAntiVirusBenchDoc::OnGetEmbeddedItem()
{
	// OnGetEmbeddedItem is called by the framework to get the COleServerItem
	//  that is associated with the document.  It is only called when necessary.

	CAntiVirusBenchSrvrItem* pItem = new CAntiVirusBenchSrvrItem(this);
	ASSERT_VALID(pItem);
	return pItem;
}




// CAntiVirusBenchDoc serialization

void CAntiVirusBenchDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CAntiVirusBenchDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CAntiVirusBenchDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CAntiVirusBenchDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CAntiVirusBenchDoc diagnostics

#ifdef _DEBUG
void CAntiVirusBenchDoc::AssertValid() const
{
	COleServerDoc::AssertValid();
}

void CAntiVirusBenchDoc::Dump(CDumpContext& dc) const
{
	COleServerDoc::Dump(dc);
}
#endif //_DEBUG


// CAntiVirusBenchDoc commands
