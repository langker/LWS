; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLWSDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "LWS.h"

ClassCount=4
Class1=CLWSApp
Class2=CLWSDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_LWS_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CSecertDlg
Resource4=IDD_DIALOG1

[CLS:CLWSApp]
Type=0
HeaderFile=LWS.h
ImplementationFile=LWS.cpp
Filter=N

[CLS:CLWSDlg]
Type=0
HeaderFile=LWSDlg.h
ImplementationFile=LWSDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=LWS_MIMA

[CLS:CAboutDlg]
Type=0
HeaderFile=LWSDlg.h
ImplementationFile=LWSDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDOK,button,1342373889
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTTON1,button,1342242816

[DLG:IDD_LWS_DIALOG]
Type=1
Class=CLWSDlg
ControlCount=22
Control1=LWS_MIMA,button,1342308361
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342177793
Control4=IDC_STATIC,static,1342177793
Control5=IDC_EDIT1,edit,1350631584
Control6=IDC_EDIT2,edit,1350631584
Control7=LWS_Time,button,1342177289
Control8=IDC_STATIC,button,1342308359
Control9=IDC_EDIT3,edit,1350631552
Control10=IDC_STATIC,static,1342177793
Control11=IDC_EDIT4,edit,1350631552
Control12=IDC_STATIC,static,1342177792
Control13=LWS_nowtime,static,1342308865
Control14=LWS_yes,button,1342242816
Control15=LWS_about,button,1342242816
Control16=IDC_STATIC,static,1342308353
Control17=IDC_RADIO4,button,1342308361
Control18=IDC_RADIO5,button,1342177289
Control19=IDC_EDIT5,edit,1350631552
Control20=IDC_EDIT6,edit,1350631552
Control21=IDC_STATIC,static,1342177793
Control22=IDC_STATIC,static,1342177792

[DLG:IDD_DIALOG1]
Type=1
Class=CSecertDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308865
Control2=IDC_RADIO2,button,1342177289
Control3=IDC_RADIO3,button,1342177289
Control4=IDC_STATIC,static,1342308865
Control5=IDC_EDIT4,edit,1350631552
Control6=IDC_BUTTON1,button,1342242816
Control7=IDC_STATIC,static,1342308865

[CLS:CSecertDlg]
Type=0
HeaderFile=SecertDlg.h
ImplementationFile=SecertDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSecertDlg
VirtualFilter=dWC

