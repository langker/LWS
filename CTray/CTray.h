
#include <string.h>
#include <afxwin.h>

#define WM_SHOW_TASK WM_USER+100

class CTray
{
public:
    CTray(void);
    ~CTray(void);

private:
    NOTIFYICONDATA m_NotifyIconData; //�����ʶ�����Ƿ����
    bool m_bIsEnable;//�����Ի������
	CWnd *dlg;
public:
  
    void CreateTray(UINT nMenuId, // ���̲˵�ID
		CWnd* pWnd,               //���򴰿�ָ��(��thisָ�뼴��)
		UINT uCallbackMessage,    //������ϢID
		LPCTSTR szTip,            //��꾭������ʱ��ʾ������
		HICON icon);              //����ͼ��
    
    LRESULT CTray::OnShowTask(WPARAM wParam, LONG lParam);
   //ɾ������
	void DelTray();
};

