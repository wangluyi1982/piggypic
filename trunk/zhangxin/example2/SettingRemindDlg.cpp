// SettingRemindDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "SettingRemindDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingRemindDlg ダイアログ


CSettingRemindDlg::CSettingRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingRemindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingRemindDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void CSettingRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingRemindDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingRemindDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingRemindDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingRemindDlg メッセージ ハンドラ
void CSettingRemindDlg::OnCancel(){
}

void CSettingRemindDlg::OnOK(){
}
