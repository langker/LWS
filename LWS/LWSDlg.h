// LWSDlg.h : header file
//

#if !defined(AFX_LWSDLG_H__8D9AA121_80BA_4C0D_8A70_095456D33C8C__INCLUDED_)
#define AFX_LWSDLG_H__8D9AA121_80BA_4C0D_8A70_095456D33C8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define HW_ONYES WM_USER + 102
/////////////////////////////////////////////////////////////////////////////
// CLWSDlg dialog
#include "SecertDlg.h"
class CLWSDlg : public CDialog
{
// Construction
public:
	void ToTaskmgr();
	void reTaskmgr();
	void ToShow();
	CLWSDlg(CWnd* pParent = NULL);
	CString mima;
	CString mima2;
    CSecertDlg pdlg;
	bool bisshow;
// Dialog Data
	//{{AFX_DATA(CLWSDlg)
	enum { IDD = IDD_LWS_DIALOG };
	CEdit	m_mima2;
	CEdit	m_mima;
	CStatic	m_nowtime;
	int		m_bIsOn;
	int		m_bIsOnForChild;
	int		m_ForHour;
	int		m_ForMinute;
	int		m_Tosuo;
	int		m_long;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLWSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLWSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onabout();
	afx_msg void OnMima();
	afx_msg void OnRadio2();
	afx_msg void OnRadio4();
	afx_msg void OnRadio5();
	afx_msg void Onyes();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LWSDLG_H__8D9AA121_80BA_4C0D_8A70_095456D33C8C__INCLUDED_)
