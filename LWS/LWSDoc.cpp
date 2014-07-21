// LWSDoc.cpp : implementation of the CLWSDoc class
//

#include "stdafx.h"
#include "LWS.h"

#include "LWSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLWSDoc

IMPLEMENT_DYNCREATE(CLWSDoc, CDocument)

BEGIN_MESSAGE_MAP(CLWSDoc, CDocument)
	//{{AFX_MSG_MAP(CLWSDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLWSDoc construction/destruction

CLWSDoc::CLWSDoc()
{
	// TODO: add one-time construction code here

}

CLWSDoc::~CLWSDoc()
{
}

BOOL CLWSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLWSDoc serialization

void CLWSDoc::Serialize(CArchive& ar)
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

/////////////////////////////////////////////////////////////////////////////
// CLWSDoc diagnostics

#ifdef _DEBUG
void CLWSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLWSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLWSDoc commands
