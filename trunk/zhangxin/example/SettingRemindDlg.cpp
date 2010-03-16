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
extern CNECTestPatternApp theApp;

CSettingRemindDlg::CSettingRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingRemindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingRemindDlg)
	m_Str = _T("");
	//}}AFX_DATA_INIT
	mo_No=0;
}


void CSettingRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingRemindDlg)
	DDX_Text(pDX, IDC_STATIC_STR, m_Str);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingRemindDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingRemindDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingRemindDlg メッセージ ハンドラ
void CSettingRemindDlg::OnCancel()
{

}

void CSettingRemindDlg::OnOK()
{

}

BOOL CSettingRemindDlg::Create(UINT nIDTemplate, CWnd* pParentWnd)
{
	return CDialog::Create(nIDTemplate,pParentWnd);
}

BOOL CSettingRemindDlg::Create(UINT nIDTemplate, CWnd* pParentWnd,CRect moni_rect,int No)
{
	mo_rect=moni_rect;
	mo_No=No;
	int ret = CDialog::Create(nIDTemplate,pParentWnd);

	return ret;
}

//画面初期化
BOOL CSettingRemindDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//モニター番号を表示場合
	if(mo_No!=0)
	{
		::SetWindowPos(m_hWnd,HWND_TOP,
			mo_rect.left,
			mo_rect.top,
			mo_rect.Width(),
			mo_rect.Height(),
			SWP_SHOWWINDOW|SWP_NOACTIVATE
			);
		GetDlgItem(IDC_STATIC_REMIND1)->MoveWindow(
			0,
			0,
			mo_rect.Width(),
			mo_rect.Height(),
			true
			);	
		GetDlgItem(IDC_STATIC_REMIND2)->MoveWindow(
			0,
			0,
			0,
			0,
			true
			);	

		CFont * pfont_o=AfxGetApp()->m_pMainWnd->GetFont();
		LOGFONT LogFont_o;
		pfont_o->GetLogFont(&LogFont_o);
		LogFont_o.lfHeight=mo_rect.Height()*3/5;

		font_n.CreateFontIndirect(&LogFont_o);
		GetDlgItem(IDC_STATIC_STR)->SetFont(&font_n,true);
		GetDlgItem(IDC_STATIC_STR)->MoveWindow(
			mo_rect.Width()/6,
			mo_rect.Height()/6,
			mo_rect.Width()*2/3,
			mo_rect.Height()*2/3,
			true
			);
		theApp.SetDialogBkColor(RGB(255,255,255));
		m_Str.Format("%d",mo_No);
		UpdateData(FALSE);
		GetDlgItem(IDC_STATIC_STR)->ShowWindow(SW_SHOW);
	}
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}


BOOL CSettingRemindDlg::DestroyWindow() 
{
	theApp.SetDialogBkColor();
	
	return CDialog::DestroyWindow();
}
