#if !defined(AFX_SECERTDLG_H__54A08B68_95AA_4038_9D9C_A7F1FC9451F8__INCLUDED_)
#define AFX_SECERTDLG_H__54A08B68_95AA_4038_9D9C_A7F1FC9451F8__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SecertDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSecertDlg dialog

class CSecertDlg : public CDialog
{
// Construction
public:
	CSecertDlg(CWnd* pParent = NULL);
	CString Sercet,Queren;
	HWND m_zhu;
// Dialog Data
	//{{AFX_DATA(CSecertDlg)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_mimaqueren;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSecertDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSecertDlg)
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SECERTDLG_H__54A08B68_95AA_4038_9D9C_A7F1FC9451F8__INCLUDED_)
