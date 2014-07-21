// LWSView.cpp : implementation of the CLWSView class
//

#include "stdafx.h"
#include "LWS.h"

#include "LWSDoc.h"
#include "LWSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLWSView

IMPLEMENT_DYNCREATE(CLWSView, CView)

BEGIN_MESSAGE_MAP(CLWSView, CView)
	//{{AFX_MSG_MAP(CLWSView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLWSView construction/destruction

CLWSView::CLWSView()
{
	// TODO: add construction code here

}

CLWSView::~CLWSView()
{
}

BOOL CLWSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLWSView drawing

void CLWSView::OnDraw(CDC* pDC)
{
	CLWSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLWSView printing

BOOL CLWSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLWSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLWSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLWSView diagnostics

#ifdef _DEBUG
void CLWSView::AssertValid() const
{
	CView::AssertValid();
}

void CLWSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLWSDoc* CLWSView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLWSDoc)));
	return (CLWSDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLWSView message handlers
