// SettingMsgDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "SettingMsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingMsgDlg ダイアログ


CSettingMsgDlg::CSettingMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingMsgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingMsgDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void CSettingMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingMsgDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingMsgDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingMsgDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingMsgDlg メッセージ ハンドラ
void CSettingMsgDlg::OnCancel()
{

}

void CSettingMsgDlg::OnOK()
{

}
