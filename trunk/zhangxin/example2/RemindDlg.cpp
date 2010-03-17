// RemindDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "RemindDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRemindDlg ダイアログ


CRemindDlg::CRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRemindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRemindDlg)
	m_Check = FALSE;
	//}}AFX_DATA_INIT
}


void CRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRemindDlg)
	DDX_Check(pDX, IDC_CHECK_SHOW, m_Check);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRemindDlg, CDialog)
	//{{AFX_MSG_MAP(CRemindDlg)
	ON_BN_CLICKED(IDC_CHECK_SHOW, OnCheckShow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemindDlg メッセージ ハンドラ

void CRemindDlg::OnOK() 
{
}

void CRemindDlg::OnCancel() 
{

}

LRESULT CRemindDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if(message==WM_LBUTTONDOWN)	{
		CPoint * a=(CPoint *)lParam;
		_asm{
			nop;
		}
	}
	return CDialog::WindowProc(message, wParam, lParam);
}

void CRemindDlg::OnCheckShow() 
{
	_asm{
		nop;
	}
	
}
