
// SrvrItem.h : interface of the CAntiVirusBenchSrvrItem class
//

#pragma once

class CAntiVirusBenchSrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CAntiVirusBenchSrvrItem)

// Constructors
public:
	CAntiVirusBenchSrvrItem(CAntiVirusBenchDoc* pContainerDoc);

// Attributes
	CAntiVirusBenchDoc* GetDocument() const
		{ return reinterpret_cast<CAntiVirusBenchDoc*>(COleServerItem::GetDocument()); }

// Overrides
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

// Implementation
public:
	~CAntiVirusBenchSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

