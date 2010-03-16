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
	
	//アプリケーション唯一
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

	//ユーザ使用設定を読み込む必要を判断
	SetRegistryKey(window_name);
	int soft_save;
//	soft_save=GetProfileInt(_T("Language"),_T("LangID"),-1);
	soft_save=GetProfileInt(_T("Option"),_T("OldSeted"),-1);
	FristRun=soft_save;
	if(soft_save==0)
	{
		OldSeted=FALSE;
	}

	//ユーザ使用設定を読み込む
	if(soft_save==1)
	{
		soft_save=GetProfileInt(_T("Option"),_T("ExitMessageNoShow"),-1);
		if(soft_save!=-1)
		{
			ExitMessageNoShow=soft_save;
		}
		soft_save=GetProfileInt(_T("Option"),_T("TesttingMsg"),-1);
		if(soft_save!=-1)
		{
			TesttingMsg=soft_save;
		}
		soft_save=GetProfileInt(_T("Option"),_T("TesttingMsg_ALL"),-1);
		if(soft_save!=-1)
		{
			TesttingMsg_ALL=soft_save;
		}
	}

	//ソフト言語を読み込む
	soft_save=GetProfileInt(_T("Language"),_T("LangID"),-1);
	if(soft_save!=-1)
	{
		soft_Lang=soft_save;
		switch(soft_save)
		{
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
	
	//一時フォルダを作成
	GetSystemDirectory(my_name, MAX_PATH);
	GetFullPathName(my_name,MAX_PATH,filepath,&namebeg);
	strcpy(namebeg,"temp\\NECTestPattern\\");
	namebeg+=20;
	CreateDirectory(filepath,0);

	TestDlg=NULL;
	CNECTestPatternDlg dlg;
	m_pMainWnd = &dlg;

	//マインダイアログを表示
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ダイアログが <OK> で消された時のコードを
		//       記述してください。
	}
	else if (nResponse == IDCANCEL)
	{
		//言語を切り替えて、ソフトを再起動
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

	//アプリケーション言語
	WriteProfileInt(_T("Language"),_T("LangID"),soft_Lang);

	//ユーザ使用設定を保存
	WriteProfileInt(_T("Option"),_T("OldSeted"),OldSeted);
	
	if(OldSeted)
	{
		WriteProfileInt(_T("Option"),_T("ExitMessageNoShow"),ExitMessageNoShow);
		WriteProfileInt(_T("Option"),_T("TesttingMsg"),TesttingMsg);
		WriteProfileInt(_T("Option"),_T("TesttingMsg_ALL"),TesttingMsg_ALL);

	}

	//GDI+クラスの終了処理
	Gdiplus::GdiplusShutdown(gdiplusToken);

	return CWinApp::ExitInstance();
}
