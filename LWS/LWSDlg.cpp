// LWSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LWS.h"
#include "LWSDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLWSDlg dialog

CLWSDlg::CLWSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLWSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLWSDlg)
	m_bIsOn = -1;
	m_bIsOnForChild = -1;
	m_ForHour = 0;
	m_ForMinute = 0;
	m_Tosuo = 0;
	m_long = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    m_bIsOn=FALSE;
    m_bIsOnForChild=FALSE;
    bisshow=FALSE;
}

void CLWSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLWSDlg)
	DDX_Control(pDX, IDC_EDIT2, m_mima2);
	DDX_Control(pDX, IDC_EDIT1, m_mima);
	DDX_Control(pDX, LWS_nowtime, m_nowtime);
	DDX_Radio(pDX, LWS_MIMA, m_bIsOn);
	DDX_Radio(pDX, IDC_RADIO4, m_bIsOnForChild);
	DDX_Text(pDX, IDC_EDIT5, m_ForHour);
	DDX_Text(pDX, IDC_EDIT6, m_ForMinute);
	DDX_Text(pDX, IDC_EDIT3, m_Tosuo);
	DDX_Text(pDX, IDC_EDIT4, m_long);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLWSDlg, CDialog)
	//{{AFX_MSG_MAP(CLWSDlg)
	ON_MESSAGE(HW_ONYES,ToShow)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(LWS_about, Onabout)
	ON_BN_CLICKED(LWS_MIMA, OnMima)
	ON_BN_CLICKED(LWS_Time, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(LWS_yes, Onyes)
	ON_WM_TIMER()

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLWSDlg message handlers

BOOL CLWSDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);// Set small icon
	SetTimer(1,500,NULL);
	UpdateData(FALSE);
	OnMima(); 
	pdlg.m_zhu=m_hWnd;
            
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLWSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLWSDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLWSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLWSDlg::Onabout() 
{
	CAboutDlg aboutdlg;
	aboutdlg.DoModal();
}

void CAboutDlg::OnOK() 
{
	MessageBox("那是");
	CDialog::OnOK();
}

void CLWSDlg::OnMima() 
{
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(true);
	GetDlgItem(IDC_EDIT2)->EnableWindow(true);
	GetDlgItem(IDC_RADIO4)->EnableWindow(false);
    GetDlgItem(IDC_RADIO5)->EnableWindow(false);
    GetDlgItem(IDC_EDIT3)->EnableWindow(false);
    GetDlgItem(IDC_EDIT4)->EnableWindow(false);
    GetDlgItem(IDC_EDIT5)->EnableWindow(false);
    GetDlgItem(IDC_EDIT6)->EnableWindow(false);
}

void CLWSDlg::OnRadio2() 
{
    UpdateData(TRUE);
    GetDlgItem(IDC_RADIO4)->EnableWindow(true);
    GetDlgItem(IDC_RADIO5)->EnableWindow(true);
    GetDlgItem(IDC_EDIT3)->EnableWindow(true);
    GetDlgItem(IDC_EDIT4)->EnableWindow(true);
    GetDlgItem(IDC_EDIT5)->EnableWindow(true);
    GetDlgItem(IDC_EDIT6)->EnableWindow(true);
    GetDlgItem(IDC_EDIT1)->EnableWindow(false);
    GetDlgItem(IDC_EDIT2)->EnableWindow(false);
    OnRadio4();
}

void CLWSDlg::OnRadio4() 
{
    UpdateData(TRUE);
    GetDlgItem(IDC_EDIT3)->EnableWindow(true);
    GetDlgItem(IDC_EDIT4)->EnableWindow(true);
    GetDlgItem(IDC_EDIT5)->EnableWindow(false);
    GetDlgItem(IDC_EDIT6)->EnableWindow(false);
}

void CLWSDlg::OnRadio5() 
{
    UpdateData(TRUE);
    GetDlgItem(IDC_EDIT5)->EnableWindow(true);
    GetDlgItem(IDC_EDIT6)->EnableWindow(true);
    GetDlgItem(IDC_EDIT3)->EnableWindow(false);
    GetDlgItem(IDC_EDIT4)->EnableWindow(false);

	
}

void CLWSDlg::Onyes() 
{

	
	if(!m_bIsOn)
	{
			m_mima.GetWindowText(mima);
			m_mima2.GetWindowText(mima2);
			if(mima==""||mima2=="")
			{
				MessageBox("请输入密码！");
				return;
			}

            if(mima!=mima2)
			{
				MessageBox("两个密码不一样？");
				return;
			}
			else
			{
				pdlg.Sercet=mima;
				ShowWindow(SW_HIDE);
                reTaskmgr();
				WinExec("taskkill /f /im explorer.exe",0);
				keybd_event(VK_LWIN,0,0,0);  
               keybd_event('D',0,0,0);  
               keybd_event(VK_LWIN,0,KEYEVENTF_KEYUP,0);  
               keybd_event('D',0,KEYEVENTF_KEYUP,0);
			   Sleep(500);
				pdlg.DoModal();
			}

	}
	else if(m_bIsOn)
	{
		UpdateData(TRUE);
		if(!m_bIsOnForChild)
		{
            ShowWindow(SW_HIDE);
			SetTimer(3,m_Tosuo*60*1000,NULL);
		}
		else
		{
            reTaskmgr();
            ShowWindow(SW_HIDE);
			SetKeyHook(TRUE);
            WinExec("taskkill /f /im explorer.exe",0);
			SetTimer(2,1000*m_ForHour*60+1000*m_ForMinute,NULL);

		}
	}
    
   
}

void CLWSDlg::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent==1)
	{
    time_t t; 
    time(&t); 
    struct tm * local_time = localtime(&t);
	CString a;
	a.Format("当前时间:%d年%2d月%2d日 %02d点 %02d分 %02d秒",
		local_time->tm_year + 1900,
		local_time->tm_mon+1,
        local_time->tm_mday ,
        local_time->tm_hour ,
        local_time->tm_min ,
        local_time->tm_sec);
	m_nowtime.SetWindowText(a);
           
	CDialog::OnTimer(nIDEvent);
	}
	else if(nIDEvent==2)
	{
		KillTimer(nIDEvent);
		SetKeyHook(FALSE);
	    CDialog::OnTimer(nIDEvent);
        ToTaskmgr();
        ShowWindow(SW_SHOW);
		bisshow=TRUE;
        WinExec("C:\\WINDOWS\\explorer.exe",0);
		MessageBox("锁屏结束！");
	}
	else if(nIDEvent==3)
	{
        reTaskmgr();
        keybd_event(VK_LWIN,0,0,0);  
               keybd_event('D',0,0,0);  
               keybd_event(VK_LWIN,0,KEYEVENTF_KEYUP,0);  
               keybd_event('D',0,KEYEVENTF_KEYUP,0);  
		WinExec("taskkill /f /im explorer.exe",0);
		KillTimer(nIDEvent);
        SetKeyHook(TRUE);
		SetTimer(4,m_long*60*1000,NULL);
	}
	else if(nIDEvent==4)
	{
		SetKeyHook(FALSE);
        ToTaskmgr();
		ShowWindow(SW_SHOW);
		WinExec("C:\\WINDOWS\\explorer.exe",0);
		KillTimer(nIDEvent);
	}


}

void CLWSDlg::ToShow()
{
	ToTaskmgr();
	ShowWindow(SW_SHOW);
}

void CLWSDlg::reTaskmgr()
{
	HKEY hkey=NULL;
	int a=1;
	if(::RegOpenKeyEx(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",0,KEY_ALL_ACCESS,&hkey)!=ERROR_SUCCESS)
	{
		::RegCreateKey(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",&hkey);
	}
	::RegSetValueEx(hkey,"DisableTaskMgr",0,REG_DWORD,(BYTE*)&a,sizeof(a));
}

void CLWSDlg::ToTaskmgr()
{
	HKEY hkey=NULL;
	int a=0;
	::RegOpenKeyEx(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",0,KEY_ALL_ACCESS,&hkey);
	::RegSetValueEx(hkey,"DisableTaskMgr",0,REG_DWORD,(BYTE *)&a,sizeof(a));
}



void CAboutDlg::OnButton1() 
{
HINSTANCE hRun = ShellExecute(GetParent()->GetSafeHwnd(), _T("open"), 
(CString)"http://hi.baidu.com/笑叹红尘破", NULL, NULL, SW_SHOW); 


} 

