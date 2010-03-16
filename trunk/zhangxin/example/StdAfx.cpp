// stdafx.cpp : 標準インクルードファイルを含むソース ファイル
//              NECTestPattern.pch : 生成されるプリコンパイル済ヘッダー
//              stdafx.obj : 生成されるプリコンパイル済タイプ情報

#include "stdafx.h"
#include "NECTestPattern.h"
#include <WINBASE.h>

extern CNECTestPatternApp theApp;									//アプリケーションの対象

CRemindDlg * pRemindDlg=NULL;
//CButton bu;
//#define IDB_SANJIN 2000

//WM_MOVEのHOOK関数
LRESULT   WINAPI   WinMoveProc(int   nCode,WPARAM   wParam,LPARAM   lParam)
{
	if(pwnd!=NULL&&
		pth!=NULL&&
		NECAfxMessageBox_Ser_Runing)
	{
		pth->ResumeThread();
	}
	return CallNextHookEx(glhHook_WinMove,nCode,wParam,lParam);
} 

//WH_MOUSEのHOOK関数
LRESULT   WINAPI   MouseProc(int   nCode,WPARAM   wParam,LPARAM   lParam)
{

	if(pwnd!=NULL&&
		pth!=NULL&&
		NECAfxMessageBox_Ser_Runing)
	{//
		if(pRemindDlg->showing)
		{
			CPoint * pMousePoint=(CPoint *)lParam;
			CRect rem_rect;
			
			CButton * pbut=(CButton *)pRemindDlg->GetDlgItem(IDC_CHECK_SHOW);
			pbut->GetWindowRect(&rem_rect);
			if(rem_rect.PtInRect(*pMousePoint)&&
				(wParam^0x2a0)==WM_LBUTTONDOWN)
			{
				SetForegroundWindow(pRemindDlg->m_hWnd);
				pRemindDlg->m_Check=pRemindDlg->m_Check?false:true;
				pbut->SetCheck(pRemindDlg->m_Check);
				return 0;
			}
		}
	}
	return CallNextHookEx(glhHook_Mouse,nCode,wParam,lParam);
} 

//WH_MOUSEのHOOK関数
//この関数は、モニターリストのチェック処理関数
// LRESULT   WINAPI   ListCtrl_MouseProc(int   nCode,WPARAM   wParam,LPARAM   lParam)
// {
// 
// 
// 	if(MainWndsta==TRUE)
// 	{
// 		theApp.m_pMainWnd->
// 
// 	}
// 	else
// 	{
// 		if(Ctrl_vi==1)
// 		{
// 			Ctrl_vi=0;
// 			::keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
// 		}
// 	}
// 	return CallNextHookEx(glhHook_ListCtrl_Mouse,nCode,wParam,lParam);
// } 

//WM_DISPLAYCHANGE
// LRESULT   WINAPI   NECTestPattern_DisplayChange(int   nCode,WPARAM   wParam,LPARAM   lParam)
// {
// 
// 	_asm{
// 		nop;
// 	}
// 	AfxMessageBox("WM_DISPLAYCHANGE");
// 	return CallNextHookEx(glhHook_DisplayChange,nCode,wParam,lParam);
// } 

//NECAfxMessageBox関数のために、メッセージダイアログを移動
UINT NECAfxMessageBox_Ser(LPVOID p)
{

	NECAfxMessageBox_Ser_Runing=1;
	CRemindDlg * pRemindDlg=(CRemindDlg *)p;
	CWinApp* pApp = AfxGetApp();
	LPCTSTR pszAppName ;

	if (pApp != NULL)
	{
		pszAppName=pApp->m_pszAppName;
	}
	else
	{
		TCHAR szAppName[_MAX_PATH];
		pszAppName = szAppName;
		GetModuleFileName(NULL, szAppName, _MAX_PATH);
	}

	//ダイアログを探す
	do 
	{
		pwnd=SetDlg->FindWindow(NULL,pszAppName);
	}
	while(pwnd==NULL);

	static CRect rc_old;
	static CRect rc_init,rem_rect_init,rem_check_rect_init;
	static CSize rem_si(0,0),rem_che_si(0,0),rem_pos(0,0);
	CRect rc,rem_rect,rem_check_rect;

	//ダイアログを移動
	while (NECAfxMessageBox_Ser_Runing==1)
	{
		pwnd->GetWindowRect(&rc);
		if(rc!=rc_old)
		{
			rc_old=rc;
			pRemindDlg->GetWindowRect(&rem_rect);
			pRemindDlg->GetDlgItem(IDC_CHECK_SHOW)->GetWindowRect(&rem_check_rect);

			if (rem_che_si.cx==0)
			{
				pwnd->GetWindowRect(&rc_init);
				pRemindDlg->GetWindowRect(&rem_rect_init);
				pRemindDlg->GetDlgItem(IDC_CHECK_SHOW)->GetWindowRect(&rem_check_rect_init);
				rem_si.cy=rem_rect_init.Height();
				rem_che_si.cy=rem_check_rect_init.Height();

				rem_si.cx=rc_init.Width();
				rem_che_si.cx=rc_init.Width()-rc_init.Width()*2/10;

				rem_pos.cx=0;
				rem_pos.cy=rc_init.Height()-GetWindowUpWidth(pRemindDlg)+GetWindowDownWidth(pRemindDlg);
				pwnd->MoveWindow(rc_init.left,rc_init.top-rem_si.cy/2,rc_init.Width(),rc_init.Height(),true);
				pwnd->GetWindowRect(&rc);
//				bu.Create(NULL,WS_VISIBLE, 
//					CRect(50,50,100,100), pwnd, IDB_SANJIN);
//				bu.SetWindowText(_T("Control created"));
			}
			pRemindDlg->MoveWindow(rc.left,rc.top+rem_pos.cy,rem_si.cx,rem_si.cy,true);
			pRemindDlg->GetDlgItem(IDC_CHECK_SHOW)->MoveWindow((rem_si.cx-rem_che_si.cx)/2,0,rem_che_si.cx,rem_che_si.cy,true);
			pRemindDlg->RedrawWindow();
		}
		pth->SuspendThread();
	}
	NECAfxMessageBox_Ser_Runing=0;
	return 0;
}

//ダイアログを選択したモニターに移動
UINT NECAfxMessageBox_Ser_MoveMessageBox(LPVOID p)
{
	CDialog * pdlg=(CDialog *)p;
	CRect dlgrect;
	pdlg->GetWindowRect(&dlgrect);

	NECAfxMessageBox_Ser_MoveMessageBox_Runing=1;
	CWinApp* pApp = AfxGetApp();
	LPCTSTR pszAppName ;
	if (pApp != NULL)
	{
		pszAppName=pApp->m_pszAppName;
	}
	else
	{
		TCHAR szAppName[_MAX_PATH];
		pszAppName = szAppName;
		GetModuleFileName(NULL, szAppName, _MAX_PATH);
	}

	do 
	{
		pwnd=SetDlg->FindWindow(NULL,pszAppName);
	}
	while(pwnd==NULL&&NECAfxMessageBox_Ser_MoveMessageBox_Runing);

	CRect rc;
	pwnd->GetWindowRect(&rc);
	::SetWindowPos(pwnd->m_hWnd,HWND_TOP ,
		monitorRect.left,
		monitorRect.top,
		0,0,SWP_SHOWWINDOW);
	pwnd->MoveWindow(dlgrect.left+(dlgrect.Width()-rc.Width())/2,dlgrect.top+(dlgrect.Height()-rc.Height())/2,rc.Width(),rc.Height(),true);
	pwnd->RedrawWindow();
	NECAfxMessageBox_Ser_MoveMessageBox_Runing=0;
	return 0;
}

//メッセージボックス
//AfxMessageBoxと違いは、チェックボタンがあり、呼び出す位置を設定できる
int NECAfxMessageBox(LPCTSTR lpszText,						//メッセージ内容（文字）
							BOOL * Checked,						//チェックボックスの戻り引数
							CWnd * pDlg ,							//親ダイアログ
							CRect * pmoni_rect ,					//表示されるモニター位置
							UINT nType  ,							//メッセージモデル
							UINT nIDHelp)							//メッセージヘルプID
{

	//ダイアログの名前を変える
	LPCTSTR temp = AfxGetApp()->m_pszAppName;
	CString temp1 = temp;
	temp1+=" ";
	(AfxGetApp()->m_pszAppName)=temp1.GetBuffer(temp1.GetLength());
	
	//メッセージダイアログの位置を移動
	if(pDlg!=NULL&&pmoni_rect!=NULL)
	{
		do 
		{
			monitorRect=*pmoni_rect;
			pth_move=::AfxBeginThread(NECAfxMessageBox_Ser_MoveMessageBox,pDlg);
		}
		while(pth_move==NULL);
	}
	
	//チェックボックスの処理
	if(Checked!=NULL)
	{
		//チェックダイアログを表示
		pRemindDlg=new CRemindDlg;
		pRemindDlg->Create(CRemindDlg::IDD);
		pRemindDlg->ShowWindow(SW_SHOW);
		
		//ダイアログ再表示
		do 
		{
			pth=::AfxBeginThread(NECAfxMessageBox_Ser,pRemindDlg);
		}
		while(pth==NULL);

		//ダイアログ移動処理
		do 
		{
			glhHook_WinMove=::SetWindowsHook(WM_MOVE,WinMoveProc);
		} 
		while(glhHook_WinMove==NULL);
		
		//マウス処理
		do 
		{
			glhHook_Mouse=::SetWindowsHook(WH_MOUSE,MouseProc);
		} 
		while(glhHook_Mouse==NULL);
	}
	
	//メッセージボックスを呼び出す
	int ret_id=AfxMessageBox(lpszText,nType ,nIDHelp);
	NECAfxMessageBox_Ser_MoveMessageBox_Runing=0;
	if(Checked!=NULL)
	{
		UnhookWindowsHookEx(glhHook_Mouse);
		UnhookWindowsHookEx(glhHook_WinMove);
		pwnd=NULL;
		NECAfxMessageBox_Ser_Runing=0;
		pth->ResumeThread();
		pth=NULL;
		*Checked =pRemindDlg->m_Check;
		pRemindDlg->DestroyWindow();
		pRemindDlg=NULL;
	}

	//アプリケーションの名前を元に変える。
	AfxGetApp()->m_pszAppName=temp;
	
	return ret_id;
}

//メッセージボックス
//AfxMessageBoxと違いは、チェックボタンがあり、呼び出す位置を設定できる
int NECAfxMessageBox(UINT nIDPrompt,						//メッセージ内容（文字ID）
							BOOL * Checked,						//チェックボックスの戻り引数
							CWnd * pDlg ,							//親ダイアログ
							CRect * pmoni_rect ,					//表示されるモニター位置
							UINT nType ,							//メッセージモデル
							UINT nIDHelp )							//メッセージヘルプID
{
	
	CString string;
	if (!string.LoadString(nIDPrompt))
	{
		TRACE1("Error: failed to load message box prompt string 0x%04x.\n",
			nIDPrompt);
		ASSERT(FALSE);
	}
	if (nIDHelp == (UINT)-1)
		nIDHelp = nIDPrompt;	

	return NECAfxMessageBox(string,Checked,pDlg,pmoni_rect,nType,nIDHelp);
}

// test code
//	BOOL a;
//	int ret=NECAfxMessageBox("12312312135465464612\n\n\n\n\n\n\n31231564564564654",&a,MB_SETFOREGROUND);
//	
//	{
//		CString str;
//		switch(ret)
//		{
//			case IDOK:	
//				str.Format("IDOK!");
//				break;
//			case IDYES:
//				str.Format("IDYES!");
//				break;
//			case IDNO:
//				str.Format("IDNO!");
//				break;
//			case IDCANCEL:
//				str.Format("IDCANCEL!");
//				break;
//			case IDRETRY:
//				str.Format("IDRETRY!");
//				break;
//			case IDCONTINUE:
//				str.Format("IDCONTINUE!");
//				break;
//			case IDTRYAGAIN:
//				str.Format("IDTRYAGAIN!");
//				break;
//			case IDHELP:
//				str.Format("IDHELP!");
//				break;
//			case IDCLOSE:
//				str.Format("IDCLOSE!");
//				break;
//			case IDIGNORE:
//				str.Format("IDIGNORE!");
//				break;
//			case IDABORT:
//				str.Format("IDABORT!");
//				break;
//		}
//		str+=a?" true.":" false.";
//		AfxMessageBox(str);
//	}