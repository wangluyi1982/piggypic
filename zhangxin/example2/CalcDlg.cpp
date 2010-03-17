// CalcDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "CalcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg ダイアログ


CCalcDlg::CCalcDlg(UINT in /*= 0*/,CWnd* pParent /*=NULL*/)
	: CDialog(CCalcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalcDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
	Dlgcase=in;
}


void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalcDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCalcDlg, CDialog)
	//{{AFX_MSG_MAP(CCalcDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg メッセージ ハンドラ

BOOL CCalcDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	switch(Dlgcase){
		case 0:
		default:
			CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);
			break;
		case 1:
			CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO2);
			GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
			break;
		case 2:
			CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);
			GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
			break;
		case 3:
			CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);
			GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
			break;
	}
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CCalcDlg::OnOK() 
{
	CheckID=GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO3)-IDC_RADIO1;
	CDialog::OnOK();
}
