
#include <string.h>
#include <afxwin.h>

#define WM_SHOW_TASK WM_USER+100

class CTray
{
public:
    CTray(void);
    ~CTray(void);

private:
    NOTIFYICONDATA m_NotifyIconData; //定义标识托盘是否可用
    bool m_bIsEnable;//弹出对话框变量
	CWnd *dlg;
public:
  
    void CreateTray(UINT nMenuId, // 托盘菜单ID
		CWnd* pWnd,               //程序窗口指针(用this指针即可)
		UINT uCallbackMessage,    //托盘消息ID
		LPCTSTR szTip,            //鼠标经过托盘时显示的文字
		HICON icon);              //托盘图标
    
    LRESULT CTray::OnShowTask(WPARAM wParam, LONG lParam);
   //删除托盘
	void DelTray();
};

