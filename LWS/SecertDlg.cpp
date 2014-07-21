// SecertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LWS.h"
#include "SecertDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CSecertDlg dialog

#define HW_ONYES WM_USER + 102
CSecertDlg::CSecertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSecertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSecertDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	Sercet="";
	Queren="";
	m_zhu=NULL;
}


void CSecertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSecertDlg)
	DDX_Control(pDX, IDC_EDIT4, m_mimaqueren);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSecertDlg, CDialog)
	//{{AFX_MSG_MAP(CSecertDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSecertDlg message handlers


void CSecertDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
    m_mimaqueren.GetWindowText(Queren);
	if(Queren=="")
	{
		return;
	}
	if(Queren!=Sercet)
	{
		MessageBox("ÃÜÂë´íÎó");
		return;
	}
	else
	{
		WinExec("C:\\WINDOWS\\explorer.exe",0);
		::SendMessage(m_zhu,HW_ONYES,NULL,NULL);
		Sleep(1000);
		KillTimer(1);
		CDialog::OnOK();
	}

}


BOOL CSecertDlg::PreTranslateMessage(MSG* pMsg) 
{
if(pMsg->message   ==   WM_KEYDOWN   &&   pMsg->wParam   ==   0x1b)   
   return   TRUE;   
if(pMsg->message   ==   WM_KEYDOWN   &&   pMsg->wParam   ==   0x0d   )   
   return   TRUE;  
	return CDialog::PreTranslateMessage(pMsg);
}

void CSecertDlg::OnTimer(UINT nIDEvent) 
{
	RECT a;
	GetWindowRect(&a);
	ClipCursor(&a);
	
	CDialog::OnTimer(nIDEvent);
}

BOOL CSecertDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetTimer(1,1000,NULL);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
