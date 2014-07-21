// LWSDoc.h : interface of the CLWSDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LWSDOC_H__99A9366F_204E_4B37_8539_42674904112B__INCLUDED_)
#define AFX_LWSDOC_H__99A9366F_204E_4B37_8539_42674904112B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLWSDoc : public CDocument
{
protected: // create from serialization only
	CLWSDoc();
	DECLARE_DYNCREATE(CLWSDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLWSDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLWSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLWSDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LWSDOC_H__99A9366F_204E_4B37_8539_42674904112B__INCLUDED_)
