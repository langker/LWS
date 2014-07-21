// LWS.h : main header file for the LWS application
//

#if !defined(AFX_LWS_H__EE632EA4_16E0_41A0_9580_E061C4FA7DF8__INCLUDED_)
#define AFX_LWS_H__EE632EA4_16E0_41A0_9580_E061C4FA7DF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLWSApp:
// See LWS.cpp for the implementation of this class
//

class CLWSApp : public CWinApp
{
public:
	CLWSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLWSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLWSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LWS_H__EE632EA4_16E0_41A0_9580_E061C4FA7DF8__INCLUDED_)
