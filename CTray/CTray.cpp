#include "CTray.h"
#include "res\TimeManger.rc2"
CTray::CTray(void)
{ 
	m_bIsEnable=FALSE;

}
CTray::~CTray(void)
{
    DelTray();
}

void CTray::CreateTray(UINT nMenuId, CWnd* pWnd, UINT uCallbackMessage, LPCTSTR szTip, HICON icon)
{
	m_NotifyIconData.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
    m_NotifyIconData.hWnd = pWnd->GetSafeHwnd();
    m_NotifyIconData.uID = nMenuId;
    m_NotifyIconData.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP;
    m_NotifyIconData.uCallbackMessage = uCallbackMessage;
    m_NotifyIconData.hIcon = icon;
    strcpy(m_NotifyIconData.szTip,szTip);
    Shell_NotifyIcon(NIM_ADD, &m_NotifyIconData);
	dlg=pWnd;
    m_bIsEnable = true;
}
//删除托盘
void CTray::DelTray()
{
    if(m_bIsEnable)
    {
        Shell_NotifyIcon(NIM_DELETE,&m_NotifyIconData);
        m_bIsEnable = false;
    }
}
LRESULT CTray::OnShowTask(WPARAM wParam, LONG lParam)
{
    if(wParam != m_NotifyIconData.uID)
        return 1;
    else
    {
        if(LOWORD(lParam) == WM_LBUTTONDOWN)
        { 
			//左键消息
        }
        if (LOWORD(lParam) == WM_RBUTTONUP)
        {   //右键弹出菜单
            //加载菜单
            CMenu menu, *pSubMenu;
			if(!menu.LoadMenu(m_NotifyIconData.uID))
            {
               return 1;
            }
				
                //加载菜单中的第一项
             if(!(pSubMenu = menu.GetSubMenu(0)))
             {
               return 1;
             }

             CPoint pos;
             ::GetCursorPos(&pos);
             ::SetForegroundWindow(m_NotifyIconData.hWnd);
             pSubMenu->CheckMenuItem(ID_MENUITEMSHUTUP,MF_UNCHECKED);
             ::TrackPopupMenu(pSubMenu->m_hMenu,0,pos.x,pos.y,0,m_NotifyIconData.hWnd,NULL);
             menu.DestroyMenu();
        }
    }
    return 0;
}
