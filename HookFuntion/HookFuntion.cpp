#include <windows.h>

#define KEYHOOKLIB_EXPORTS
#include "HookFuntion.h"


// �������ݶ�
#pragma data_seg("YCIShared")
HHOOK g_hMouse = NULL;	// ���������ھ��
HHOOK g_hHook = NULL;		// ���湳�Ӿ��
#pragma data_seg()

// һ��ͨ���ڴ��ַȡ��ģ�����İ�������
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

// ���̹��Ӻ���
LRESULT CALLBACK KeyHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	return 1;
}
LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	return 1;
}
// ��װ��ж�ع��ӵĺ���
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