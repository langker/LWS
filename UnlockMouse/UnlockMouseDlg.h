// UnlockMouseDlg.h : header file
//

#if !defined(AFX_UNLOCKMOUSEDLG_H__D9ED1AE6_40EB_433B_B3C6_2B12F8BB8DDD__INCLUDED_)
#define AFX_UNLOCKMOUSEDLG_H__D9ED1AE6_40EB_433B_B3C6_2B12F8BB8DDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUnlockMouseDlg dialog

class CUnlockMouseDlg : public CDialog
{
// Construction
public:
	CUnlockMouseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUnlockMouseDlg)
	enum { IDD = IDD_UNLOCKMOUSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUnlockMouseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUnlockMouseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UNLOCKMOUSEDLG_H__D9ED1AE6_40EB_433B_B3C6_2B12F8BB8DDD__INCLUDED_)
