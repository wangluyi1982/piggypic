// NECTestPattern.cpp : アプリケーション用クラスの定義を行います。
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "NECTestPatternDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternApp

BEGIN_MESSAGE_MAP(CNECTestPatternApp, CWinApp)
	//{{AFX_MSG_MAP(CNECTestPatternApp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternApp クラスの構築

CNECTestPatternApp::CNECTestPatternApp()
{
	// TODO: この位置に構築用のコードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}

/////////////////////////////////////////////////////////////////////////////
// 唯一の CNECTestPatternApp オブジェクト

CNECTestPatternApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternApp クラスの初期化

BOOL CNECTestPatternApp::InitInstance()
{
	AfxEnableControlContainer();

	GdiplusStartupInput gdiplusStartupInput;

	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	HWND hWnd;
	CString window_name;
	
	window_name.LoadString(AFX_IDS_APP_TITLE);
	hWnd=FindWindow(NULL,window_name);
	if (hWnd)
	{

		ShowWindow(hWnd,SW_RESTORE);
		BringWindowToTop(hWnd);
		::SetForegroundWindow(hWnd);
		return FALSE;
	}
	// 標準的な初期化処理
	// もしこれらの機能を使用せず、実行ファイルのサイズを小さくしたけ
	//  れば以下の特定の初期化ルーチンの中から不必要なものを削除して
	//  ください。

#ifdef _AFXDLL
	Enable3dControls();			// 共有 DLL 内で MFC を使う場合はここをコールしてください。
#else
	Enable3dControlsStatic();	// MFC と静的にリンクする場合はここをコールしてください。
#endif

	SetRegistryKey(window_name);
	int soft_save;
//	soft_save=GetProfileInt(_T("Language"),_T("LangID"),-1);
	soft_save=GetProfileInt(_T("Option"),_T("OldSeted"),-1);
	FristRun=soft_save;
	if(soft_save==0){
		OldSeted=FALSE;
	}
	if(soft_save==1){
		soft_save=GetProfileInt(_T("Option"),_T("ExitMessageNoShow"),-1);
		if(soft_save!=-1){
			ExitMessageNoShow=soft_save;
		}
		soft_save=GetProfileInt(_T("Option"),_T("TesttingMsg"),-1);
		if(soft_save!=-1){
			TesttingMsg=soft_save;
		}
		soft_save=GetProfileInt(_T("Option"),_T("TesttingMsg_ALL"),-1);
		if(soft_save!=-1){
			TesttingMsg_ALL=soft_save;
		}
	}
	soft_save=GetProfileInt(_T("Language"),_T("LangID"),-1);
	if(soft_save!=-1){
		soft_Lang=soft_save;
		switch(soft_save){
			case LANG_JAPANESE://日本語：0x11
				SetThreadLocale(LANG_JAPANESE);
				break;
			case LANG_ENGLISH://英語：0x09
			default://ほかの言語
				SetThreadLocale(LANG_ENGLISH);
				break;
		}
		WriteProfileInt(_T("Language"),_T("LangID"),soft_Lang);
	}
	
	GetSystemDirectory(my_name, MAX_PATH);
	GetFullPathName(my_name,MAX_PATH,filepath,&namebeg);
	strcpy(namebeg,"temp\\");
	namebeg+=5;

	TestDlg=NULL;
	CNECTestPatternDlg dlg;
	m_pMainWnd = &dlg;

	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ダイアログが <OK> で消された時のコードを
		//       記述してください。
	}
	else if (nResponse == IDCANCEL)
	{
		char ReRun[MAX_PATH+1];
		GetModuleFileName(0, ReRun, MAX_PATH);
		ShellExecute(NULL,_T("open"),ReRun,NULL,NULL,SW_SHOW);
		// TODO: ダイアログが <ｷｬﾝｾﾙ> で消された時のコードを
		//       記述してください。
	}

	// ダイアログが閉じられてからアプリケーションのメッセージ ポンプを開始するよりは、
	// アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}

int CNECTestPatternApp::ExitInstance() 
{

	WriteProfileInt(_T("Option"),_T("OldSeted"),OldSeted);
	WriteProfileInt(_T("Language"),_T("LangID"),soft_Lang);
	if(OldSeted){
		WriteProfileInt(_T("Option"),_T("ExitMessageNoShow"),ExitMessageNoShow);
		WriteProfileInt(_T("Option"),_T("TesttingMsg"),TesttingMsg);
		WriteProfileInt(_T("Option"),_T("TesttingMsg_ALL"),TesttingMsg_ALL);

	}

	Gdiplus::GdiplusShutdown(gdiplusToken);

	return CWinApp::ExitInstance();
}

void CNECTestPatternDlg::OnMenuitemLanguageEn() 
{
	if(soft_Lang != LANG_ENGLISH){
		soft_Lang=LANG_ENGLISH;
		SetThreadLocale(soft_Lang);
		CDialog::OnCancel();
	}
	
}

void CNECTestPatternDlg::OnMenuitemLanguageJp() 
{
	if(soft_Lang != LANG_JAPANESE){
		soft_Lang=LANG_JAPANESE;
		SetThreadLocale(soft_Lang);
		CDialog::OnCancel();
	}

}

void CNECTestPatternDlg::OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex,BOOL bSysMenu)
{
	ASSERT(pPopupMenu != NULL);
	// Check the enabled state of various menu items.

	CCmdUI state;
	state.m_pMenu = pPopupMenu;
	ASSERT(state.m_pOther == NULL);
	ASSERT(state.m_pParentMenu == NULL);

	// Determine if menu is popup in top-level menu and set m_pOther to
	// it if so (m_pParentMenu == NULL indicates that it is secondary popup).
	HMENU hParentMenu;
	if (AfxGetThreadState()->m_hTrackingMenu == pPopupMenu->m_hMenu)
		state.m_pParentMenu = pPopupMenu;	// Parent == child for tracking popup.
	else if ((hParentMenu = ::GetMenu(m_hWnd)) != NULL)
	{
		CWnd* pParent = this;
			// Child windows don't have menus--need to go to the top!
		if (pParent != NULL &&
			(hParentMenu = ::GetMenu(pParent->m_hWnd)) != NULL)
		{
			int nIndexMax = ::GetMenuItemCount(hParentMenu);
			for (int nIndex = 0; nIndex < nIndexMax; nIndex++)
			{
			if (::GetSubMenu(hParentMenu, nIndex) == pPopupMenu->m_hMenu)
			{
				// When popup is found, m_pParentMenu is containing menu.
				state.m_pParentMenu = CMenu::FromHandle(hParentMenu);
				break;
			}
			}
		}
	}

	state.m_nIndexMax = pPopupMenu->GetMenuItemCount();
	for (state.m_nIndex = 0; state.m_nIndex < state.m_nIndexMax;
	  state.m_nIndex++)
	{
		state.m_nID = pPopupMenu->GetMenuItemID(state.m_nIndex);
		if (state.m_nID == 0)
			continue; // Menu separator or invalid cmd - ignore it.

		ASSERT(state.m_pOther == NULL);
		ASSERT(state.m_pMenu != NULL);
		if (state.m_nID == (UINT)-1)
		{
			// Possibly a popup menu, route to first item of that popup.
			state.m_pSubMenu = pPopupMenu->GetSubMenu(state.m_nIndex);
			if (state.m_pSubMenu == NULL ||
			(state.m_nID = state.m_pSubMenu->GetMenuItemID(0)) == 0 ||
			state.m_nID == (UINT)-1)
			{
			continue;		// First item of popup can't be routed to.
			}
			state.DoUpdate(this, TRUE);	// Popups are never auto disabled.
		}
		else
		{
			// Normal menu item.
			// Auto enable/disable if frame window has m_bAutoMenuEnable
			// set and command is _not_ a system command.
			state.m_pSubMenu = NULL;
			state.DoUpdate(this, FALSE);
		}

		// Adjust for menu deletions and additions.
		UINT nCount = pPopupMenu->GetMenuItemCount();
		if (nCount < state.m_nIndexMax)
		{
			state.m_nIndex -= (state.m_nIndexMax - nCount);
			while (state.m_nIndex < nCount &&
			pPopupMenu->GetMenuItemID(state.m_nIndex) == state.m_nID)
			{
			state.m_nIndex++;
			}
		}
		state.m_nIndexMax = nCount;
	}
	switch(soft_Lang) {
		case LANG_JAPANESE:
			pPopupMenu->CheckMenuItem(ID_MENUITEM_LANGUAGE_EN,MF_BYCOMMAND|MF_UNCHECKED);
			pPopupMenu->CheckMenuItem(ID_MENUITEM_LANGUAGE_JP,MF_BYCOMMAND|MF_CHECKED);
			break;
		case LANG_ENGLISH:
			pPopupMenu->CheckMenuItem(ID_MENUITEM_LANGUAGE_EN,MF_BYCOMMAND|MF_CHECKED);
			pPopupMenu->CheckMenuItem(ID_MENUITEM_LANGUAGE_JP,MF_BYCOMMAND|MF_UNCHECKED);
			break;
	}
}
