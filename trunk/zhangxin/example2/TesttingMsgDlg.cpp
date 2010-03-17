// TesttingMsgDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "TesttingMsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTesttingMsgDlg ダイアログ
extern CNECTestPatternApp theApp;

CTesttingMsgDlg::CTesttingMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTesttingMsgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTesttingMsgDlg)
	m_Timer = 10;
	m_String = _T("");
	//}}AFX_DATA_INIT
	TestMsgState=0;
	AutoJumpState=TRUE;
	time_min=m_Timer;
	monitorRect=CRect(0,0,0,0);
	setfout=0;
}

CTesttingMsgDlg::CTesttingMsgDlg(CRect inpRect,CWnd* pParent /*=NULL*/)
	: CDialog(CTesttingMsgDlg::IDD, pParent)
{
	m_Timer = 10;
	m_String = _T("");
	TestMsgState=0;
	AutoJumpState=TRUE;
	time_min=m_Timer;
	monitorRect=inpRect;
	setfout=0;
}

void CTesttingMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTesttingMsgDlg)
	DDX_Text(pDX, IDC_EDIT_TIME, m_Timer);
	DDV_MinMaxInt(pDX, m_Timer, 1, MAXINT_PTR);
	DDX_Text(pDX, IDC_STATIC_STRING, m_String);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTesttingMsgDlg, CDialog)
	//{{AFX_MSG_MAP(CTesttingMsgDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_BACK, OnButtonBack)
	ON_BN_CLICKED(IDC_RADIO_M, OnRadioM)
	ON_BN_CLICKED(IDC_RADIO_A, OnRadioA)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT_TIME, OnChangeEditTime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTesttingMsgDlg メッセージ ハンドラ

BOOL CTesttingMsgDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetDlgPos();
	
	HICON hicon = ::LoadIcon(NULL, IDI_ASTERISK);
	CStatic * pStatic=(CStatic *)GetDlgItem(IDC_STATIC_ICON);
	pStatic->SetIcon(hicon);
	if(OldSeted){
		int in;
		in=AfxGetApp()->GetProfileInt(_T("TestingMsgDlg"),_T("AutoJumpState"),-1);
		if(in!=-1){
			AutoJumpState=in!=0?TRUE:FALSE;
		}
		in=AfxGetApp()->GetProfileInt(_T("TestingMsgDlg"),_T("m_Timer"),-1);
		if(in>0){
			time_min=
			m_Timer=in;
			UpdateData(FALSE);
		}
	}
	EndbleTime();
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CTesttingMsgDlg::EndbleTime(){
	if(!AutoJumpState){
		CheckRadioButton(IDC_RADIO_M,IDC_RADIO_A,IDC_RADIO_M);
		GetDlgItem(IDC_EDIT_TIME)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_TIME)->EnableWindow(FALSE);
	}else{
		SetTimer(100,1000,NULL);
		CheckRadioButton(IDC_RADIO_M,IDC_RADIO_A,IDC_RADIO_A);
		GetDlgItem(IDC_EDIT_TIME)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATIC_TIME)->EnableWindow(TRUE);
	}
}

void CTesttingMsgDlg::OnPaint() 
{
	CPaintDC dc(this); // 描画用のデバイス コンテキスト
	
	if(setfout==0){
		CFont * pfont_o=theApp.m_pMainWnd->GetFont();
		LOGFONT LogFont_o;
		pfont_o->GetLogFont(&LogFont_o);
		switch(soft_Lang){
			case LANG_ENGLISH:
			default:
				LogFont_o.lfHeight=10;
				break;
			case LANG_JAPANESE:
				LogFont_o.lfHeight=15;
				break;
		}
	//	LogFont_o.lfWidth=14;
		CFont font_n;
		font_n.CreateFontIndirect(&LogFont_o);
		GetDlgItem(IDC_STATIC_STRING)->SetFont(&font_n,true);
		setfout=1;
	}
	CString temp;
	temp.LoadString(IDS_MSG_TI_TESTING1+TestMsgState);
	if(AutoJumpState){
		CString temp_time;
		temp_time.LoadString(IDS_MSG_TI_TESTING_TIME);
		temp+=temp_time;
		temp_time=temp;
		temp.Format(temp_time,time_min);
	}
	SetWindowText(temp);
	temp.LoadString(IDS_MSG_TESTTING1+TestMsgState);
	GetDlgItem(IDC_STATIC_STRING)->SetWindowText(temp);

	
	switch(TestMsgState){
		case 0:
			GetDlgItem(IDC_BUTTON_BACK)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_NEXT)->EnableWindow(TRUE);
			break;
		case MaxState:
			GetDlgItem(IDC_BUTTON_BACK)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_NEXT)->EnableWindow(FALSE);
			break;
		default:
			GetDlgItem(IDC_BUTTON_BACK)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_NEXT)->EnableWindow(TRUE);
	}
	
	// 描画用メッセージとして CDialog::OnPaint() を呼び出してはいけません
}

void CTesttingMsgDlg::OnButtonNext() 
{
	TestMsgState++;
	time_min=m_Timer;
	RedrawWindow();
	
}

void CTesttingMsgDlg::OnButtonBack() 
{
	TestMsgState--;
	time_min=m_Timer;
	RedrawWindow();
	
}

void CTesttingMsgDlg::OnRadioM() 
{
	if(AutoJumpState){
		AutoJumpState=FALSE;
		EndbleTime();
		KillTimer(100);
		RedrawWindow();
	}
}

void CTesttingMsgDlg::OnRadioA() 
{
	if(!AutoJumpState){
		AutoJumpState=TRUE;
		EndbleTime();
		SetTimer(100,1000,NULL);
	}
}

void CTesttingMsgDlg::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent==100){
		if(time_min==0){
			time_min=m_Timer;
			TestMsgState++;
			if(TestMsgState>MaxState){
				OnOK();
			}
			RedrawWindow();
			time_min--;
		}else{
			CString temp,temp_time;
			temp_time.LoadString(IDS_MSG_TI_TESTING_TIME);
			temp.LoadString(IDS_MSG_TI_TESTING1+TestMsgState);
			temp+=temp_time;
			temp_time.Format(temp,time_min);
			SetWindowText(temp_time);		
			time_min--;
		}
	}
	
	CDialog::OnTimer(nIDEvent);
}

void CTesttingMsgDlg::OnChangeEditTime() 
{
	// TODO: これが RICHEDIT コントロールの場合、コントロールは、 lParam マスク
	// 内での論理和の ENM_CHANGE フラグ付きで CRichEditCrtl().SetEventMask()
	// メッセージをコントロールへ送るために CDialog::OnInitDialog() 関数をオーバー
	// ライドしない限りこの通知を送りません。
	
	UpdateData();
	time_min=m_Timer;	
	
}

void CTesttingMsgDlg::SetDlgPos(CWnd * pDlg){
	if(monitorRect.Width()==0&&monitorRect.Height()==0)return;
	if(pDlg==NULL){
		pDlg=this;
	}
	CRect rect_t;
	pDlg->GetWindowRect(&rect_t);

	int x0=monitorRect.left+(monitorRect.Width()-rect_t.Width())/2,
		y0=0;
	HWND hWnd=*pDlg;
	::SetWindowPos(hWnd,HWND_TOP ,
		monitorRect.left,//x0,
		monitorRect.top,//y0,
		0,0,SWP_SHOWWINDOW);
//		monitorRect.Width(),monitorRect.Height(),SWP_SHOWWINDOW);
	::MoveWindow(hWnd,
		x0,
		y0,
		rect_t.Width(),
		rect_t.Height(),
		true);
}

BOOL CTesttingMsgDlg::DestroyWindow() 
{
	AfxGetApp()->WriteProfileInt(_T("TestingMsgDlg"),_T("AutoJumpState"),AutoJumpState);
	AfxGetApp()->WriteProfileInt(_T("TestingMsgDlg"),_T("m_Timer"),m_Timer);
	
	return CDialog::DestroyWindow();
}
