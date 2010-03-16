// MessageDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "MessageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMessageDlg ダイアログ


CMessageDlg::CMessageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMessageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMessageDlg)
	m_String = _T("");
	//}}AFX_DATA_INIT
	nType=0;
	Checked=NULL;
	pDlg=NULL;
	pmoni_rect=NULL;
}

CMessageDlg::CMessageDlg(CString in_str,int in_nType,CWnd* pParent /*=NULL*/)
	: CDialog(CMessageDlg::IDD, pParent)
{
	nType= in_nType;
	m_String=in_str;
	Checked=NULL;
	pDlg=NULL;
	pmoni_rect=NULL;
}

CMessageDlg::CMessageDlg(CString in_str,int in_nType, BOOL * in_Checked, CWnd * in_pDlg, CRect * in_pmoni_rec,CWnd* pParent /*=NULL*/)
	: CDialog(CMessageDlg::IDD, pParent)
{
	nType= in_nType;
	m_String=in_str;
	Checked=in_Checked;
	pDlg=in_pDlg;
	pmoni_rect=in_pmoni_rec;
}

CMessageDlg::CMessageDlg(UINT nIDPrompt,int in_nType, BOOL * in_Checked, CWnd * in_pDlg, CRect * in_pmoni_rec,CWnd* pParent /*=NULL*/)
	: CDialog(CMessageDlg::IDD, pParent)
{
	nType= in_nType;
	if (!m_String.LoadString(nIDPrompt))
	{
		TRACE1("Error: failed to load message box prompt string 0x%04x.\n",
			nIDPrompt);
		ASSERT(FALSE);
	}
	Checked=in_Checked;
	pDlg=in_pDlg;
	pmoni_rect=in_pmoni_rec;
}

void CMessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMessageDlg)
	DDX_Text(pDX, IDC_STATIC_STRING, m_String);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMessageDlg, CDialog)
	//{{AFX_MSG_MAP(CMessageDlg)
	ON_BN_CLICKED(IDYES, OnYes)
	ON_BN_CLICKED(IDNO, OnNo)
	ON_BN_CLICKED(IDC_CHECK_SHOW, OnCheckShow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMessageDlg メッセージ ハンドラ

void CMessageDlg::OnOK() 
{
	CDialog::OnOK();
}

void CMessageDlg::OnYes() 
{
	CDialog::EndDialog(IDYES);
	
}

void CMessageDlg::OnNo() 
{
	CDialog::EndDialog(IDNO);
	
}

//画面初期化
BOOL CMessageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	char * IconID;

	//アイコンの選択
	switch(nType&0x70)
	{
		case MB_ICONQUESTION:
			IconID=IDI_QUESTION;
			break;
		case MB_ICONHAND:
			IconID=IDI_HAND;
			break;
		case MB_ICONEXCLAMATION:
			IconID=IDI_EXCLAMATION;
			break;
		default:
		case MB_ICONASTERISK:
			IconID=IDI_ASTERISK;
			break;
	}

	//システムアイコンを読み込む
	HICON hicon = ::LoadIcon(NULL, IconID);
	CStatic * pStatic=(CStatic *)GetDlgItem(IDC_STATIC_ICON);
	pStatic->SetIcon(hicon);
	pStatic->RedrawWindow();

	//チェックボタンを初期化
	CButton * pBut=(CButton *)GetDlgItem(IDC_CHECK_SHOW);
	if(Checked!=NULL)
	{
		if(*Checked)
		{
			pBut->SetCheck(2);
		}
	}
	else
	{
		pBut->ShowWindow(SW_HIDE);
	}

	//ダイアログサイズを初期化
	CRect rc;
	GetWindowRect(&rc);
	if(Checked==NULL)
	{
		CRect che_rect;
		pBut->GetWindowRect(&che_rect);
		rc.bottom-=che_rect.Height()/2;
		rc.top+=che_rect.Height()/2;
		MoveWindow(rc,true);

		XYandWH but_xywh;
		GetDlgItemXYandWH(this,IDOK,but_xywh);
		but_xywh.y0-=che_rect.Height();
		GetDlgItem(IDOK)->MoveWindow((CRect)but_xywh,true);

		GetDlgItemXYandWH(this,IDYES,but_xywh);
		but_xywh.y0-=che_rect.Height();
		GetDlgItem(IDYES)->MoveWindow((CRect)but_xywh,true);

		GetDlgItemXYandWH(this,IDNO,but_xywh);
		but_xywh.y0-=che_rect.Height();
		GetDlgItem(IDNO)->MoveWindow((CRect)but_xywh,true);
	}

	//ボタン初期化
	switch(nType&0x7)
	{
		case MB_YESNO:
			GetDlgItem(IDYES)->ShowWindow(SW_SHOW);
			GetDlgItem(IDYES)->SetFocus();
			GetDlgItem(IDNO)->ShowWindow(SW_SHOW);
			GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
			break;
		case MB_OK:
		default:
			GetDlgItem(IDYES)->ShowWindow(SW_HIDE);
			GetDlgItem(IDNO)->ShowWindow(SW_HIDE);
			GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
			GetDlgItem(IDOK)->SetFocus();
			IconID=IDI_HAND;
			break;
	}

	//ダイアログを移動
	if(pDlg!=NULL&&pmoni_rect!=NULL)
	{
		CRect dlgrect;
		pDlg->GetWindowRect(&dlgrect);

		::SetWindowPos(m_hWnd,HWND_TOP ,
			pmoni_rect->left,
			pmoni_rect->top,
			0,0,SWP_SHOWWINDOW);
		MoveWindow(dlgrect.left+(dlgrect.Width()-rc.Width())/2,dlgrect.top+(dlgrect.Height()-rc.Height())/2,rc.Width(),rc.Height(),true);
		RedrawWindow();
	}

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CMessageDlg::OnCheckShow() 
{
	//チェックボタンの処理関数
	if(Checked!=NULL)
		*Checked=*Checked?false:true;
}
