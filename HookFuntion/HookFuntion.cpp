#include <windows.h>

#define KEYHOOKLIB_EXPORTS
#include "HookFuntion.h"


// 共享数据段
#pragma data_seg("YCIShared")
HHOOK g_hMouse = NULL;	// 保存主窗口句柄
HHOOK g_hHook = NULL;		// 保存钩子句柄
#pragma data_seg()

// 一个通过内存地址取得模块句柄的帮助函数
HMODULE WINAPI ModuleFromAddress(PVOID pv) 
{
	MEMORY_BASIC_INFORMATION mbi;
	if(::VirtualQuery(pv, &mbi, sizeof(mbi)) != 0)
	{
		return (HMODULE)mbi.AllocationBase;
	}
	else
	{
		return NULL;
	}
}

// 键盘钩子函数
LRESULT CALLBACK KeyHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	return 1;
}
LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	return 1;
}
// 安装、卸载钩子的函数
BOOL WINAPI SetKeyHook(BOOL bInstall)
{
	BOOL bOk;
	
	if(bInstall)
	{
		g_hHook = ::SetWindowsHookEx(WH_KEYBOARD, KeyHookProc, 
					ModuleFromAddress(KeyHookProc),0);
        g_hMouse = ::SetWindowsHookEx(WH_MOUSE, MouseHookProc, 
					ModuleFromAddress(MouseHookProc),0);
		bOk = (g_hHook != NULL)&&(g_hMouse!=NULL);
	} 
	else 
	{
		bOk = (::UnhookWindowsHookEx(g_hHook))&&(::UnhookWindowsHookEx(g_hMouse));
		g_hHook = NULL;
		g_hMouse=NULL;
	}
	
	return bOk;
}