// SetTestPatternDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "SetTestPatternDlg.h"
#include "TestPatternDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetTestPatternDlg ダイアログ
extern CNECTestPatternApp theApp;

CSetTestPatternDlg::CSetTestPatternDlg(CWnd* pParent /*=NULL*/)
	:CNECTestPatternDlg(CSetTestPatternDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetTestPatternDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
	add=0;
	pNextWnd=NULL;
	SetTextDlg=NULL;
	SetRemindDlg=NULL;
	TestDlg_one=NULL;
}


void CSetTestPatternDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetTestPatternDlg)
	DDX_Control(pDX, IDC_BUTTON_PATTERN_CALC1, m_Button_Pattern_Calc1);
	DDX_Control(pDX, IDC_BUTTON_PATTERN_CALC2, m_Button_Pattern_Calc2);
	DDX_Control(pDX, IDC_BUTTON_PATTERN_CALC3, m_Button_Pattern_Calc3);
	DDX_Control(pDX, IDC_BUTTON_PATTERN1, m_Button_Pattern1);
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_FileName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetTestPatternDlg, CDialog)
	//{{AFX_MSG_MAP(CSetTestPatternDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_FILEDISPLAY, OnButtonFiledisplay)
	ON_BN_CLICKED(IDC_DONOT, OnDonot)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	ON_BN_CLICKED(IDC_BUTTON_FILE, OnButtonFile)
	ON_EN_KILLFOCUS(IDC_EDIT_FILENAME, OnKillfocusEditFilename)
	ON_BN_CLICKED(IDC_EXITDLG, OnExitdlg)
	ON_BN_CLICKED(IDC_RADIO_FirstCen, OnRADIOFirstCen)
	ON_BN_CLICKED(IDC_RADIO_FirstExt, OnRADIOFirstExt)
	ON_BN_CLICKED(IDC_RADIO_FirstEnu, OnRADIOFirstEnu)
	ON_BN_CLICKED(IDC_RADIO_Ext_Pack, OnRADIOExtPack)
	ON_BN_CLICKED(IDC_RADIO_Ext_Width, OnRADIOExtWidth)
	ON_BN_CLICKED(IDC_RADIO_Ext_Height, OnRADIOExtHeight)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN1, OnButtonPattern1)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN2, OnButtonPattern2)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN3, OnButtonPattern3)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN_CALC1, OnButtonPatternCalc1)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN_CALC2, OnButtonPatternCalc2)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN_CALC3, OnButtonPatternCalc3)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_COLOR, OnButtonSelectColor)
	ON_BN_CLICKED(IDC_RADIO_COLOR_SELECT, OnRadioColorSelect)
	ON_BN_CLICKED(IDC_RADIO_COLOR_FILE, OnRadioColorFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
//	ON_BN_CLICKED(IDC_BUTTON_FILEDISPLAY, OnButtonFiledisplay)

/////////////////////////////////////////////////////////////////////////////
// CSetTestPatternDlg メッセージ ハンドラ

BOOL CSetTestPatternDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CString str,temp;
	CString text,temp1;
	CRect rc;

	temp.LoadString(IDS_SETTESTPATTERN_TI);
	str.Format(temp,monitor_info_Testadd[0].SystemNo,Count-add,Count);
	SetWindowText(str);

	InitDlg();
	
	if(SetTextDlg!=NULL){
		SetTextDlg->DestroyWindow();
	}
	SetTextDlg=new CSettingMsgDlg;
	SetTextDlg->Create(CSettingMsgDlg::IDD,this);

	if(SetRemindDlg!=NULL){
		SetRemindDlg->DestroyWindow();
	}
	SetRemindDlg=new CSettingRemindDlg;
	SetRemindDlg->Create(CSettingRemindDlg::IDD,this);

	::SetWindowPos(*SetRemindDlg,HWND_TOP,
		monitor_info_Testadd[0].DesktopOfMonitor.left,
		monitor_info_Testadd[0].DesktopOfMonitor.top,
		monitor_info_Testadd[0].DesktopOfMonitor.Width(),
		monitor_info_Testadd[0].DesktopOfMonitor.Height(),
		SWP_SHOWWINDOW|SWP_NOACTIVATE
		);
	SetRemindDlg->GetDlgItem(IDC_STATIC_REMIND1)->MoveWindow(
		0,
		0,
		monitor_info_Testadd[0].DesktopOfMonitor.Width(),
		monitor_info_Testadd[0].DesktopOfMonitor.Height(),
		true
		);	
	SetRemindDlg->GetDlgItem(IDC_STATIC_REMIND2)->MoveWindow(
		0,
		0,
		monitor_info_Testadd[0].DesktopOfMonitor.Width(),
		monitor_info_Testadd[0].DesktopOfMonitor.Height(),
		true
		);	

	::SetForegroundWindow(m_hWnd);
	
	temp1.LoadString(IDS_MSG_SETTING);
	text.Format(temp1,monitor_info_Testadd[0].SystemNo,
		monitor_info_Testadd[0].MonitorName,
		monitor_info_Testadd[0].DesktopOfMonitor.Width(),
		monitor_info_Testadd[0].DesktopOfMonitor.Height());
	SetTextDlg->GetDlgItem(IDC_STATIC_TEXT)->SetWindowText(text);
	temp.LoadString(IDS_MSG_SETTING_TI);
	SetTextDlg->SetWindowText(temp);

	SetTextDlg->GetWindowRect(&rc);
	::SetWindowPos(*SetTextDlg,HWND_TOP,
		monitor_info_Testadd[0].DesktopOfMonitor.left,
		monitor_info_Testadd[0].DesktopOfMonitor.top,
		monitor_info_Testadd[0].DesktopOfMonitor.Width(),
		monitor_info_Testadd[0].DesktopOfMonitor.Height(),
		SWP_SHOWWINDOW|SWP_NOACTIVATE
		);
	::MoveWindow(*SetTextDlg,
		monitor_info_Testadd[0].DesktopOfMonitor.right-rc.Width(),
		monitor_info_Testadd[0].DesktopOfMonitor.top,
		rc.Width(),
		rc.Height(),
		TRUE
		);

	::SetForegroundWindow(m_hWnd);
	AfxBeginThread(th,this);
//	SetTextDlg->ShowWindow(SW_SHOWNOACTIVATE);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CSetTestPatternDlg::OnPaint() 
{
	CPaintDC dc(this); // 描画用のデバイス コンテキスト

	SetEnableWindow();
	// 描画用メッセージとして CDialog::OnPaint() を呼び出してはいけません
}

void CSetTestPatternDlg::OnButtonDisplay(int PatternBmpID){

	HBITMAP hBmp=::LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(PatternBmpID));

	TestDlg_one=new CTestPatternDlg;

	TestDlg_one->CenShow=true;
	TestDlg_one->ReSize=false;

	TestDlg_one->add=add;
	TestDlg_one->filename=selectfilename;
	TestDlg_one->hBitmap=hBmp;
	TestDlg_one->pNextWnd=pNextWnd;
	TestDlg_one->SetDlgRect(monitor_info_Testadd->DesktopOfMonitor);

	ShowWindow(SW_HIDE);
	SetTextDlg->ShowWindow(SW_HIDE);
	int dlg_ok=TestDlg_one->DoModal();//SW_SHOWNOACTIVATE

	delete TestDlg_one;
	::DeleteObject(hBmp);

	if(dlg_ok==IDOK){
		CDialog::OnOK();
		return;
	}
	SetTextDlg->ShowWindow(SW_SHOW);
	ShowWindow(SW_SHOW);
	return;
}

void CSetTestPatternDlg::OnButtonFiledisplay() 
{
	TestDlg_one=new CTestPatternDlg;
	
	CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_FirstCen,IDC_RADIO_FirstEnu);

	switch(CheckedRadioID){
		case IDC_RADIO_FirstExt:
		case IDC_RADIO_FirstEnu:
			switch(CheckedRadioID){
				case IDC_RADIO_FirstExt:
					TestDlg_one->CenShow=false;
					TestDlg_one->ReSize=true;
					CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_Ext_Width,IDC_RADIO_Ext_Pack);
					TestDlg_one->Ext=CheckedRadioID-IDC_RADIO_Ext_Width;
					break;
				case IDC_RADIO_FirstEnu:
					TestDlg_one->CenShow=false;
					TestDlg_one->ReSize=false;
					CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_Enu_left,IDC_RADIO_Enu_right);
					TestDlg_one->Enu_Hor_pos=CheckedRadioID-IDC_RADIO_Enu_left;
					CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_Enu_up,IDC_RADIO_Enu_down);
					TestDlg_one->Enu_Ver_pos=CheckedRadioID-IDC_RADIO_Enu_up;

					break;
			}
			CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_Color_leftup,IDC_RADIO_Color_rightdown);
			TestDlg_one->Color_pos=CheckedRadioID-IDC_RADIO_Color_leftup;
			CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_COLOR_SELECT,IDC_RADIO_COLOR_FILE);
			if(CheckedRadioID==IDC_RADIO_COLOR_SELECT){
				TestDlg_one->Color_pos=-1;
				TestDlg_one->SelectedCol=SelectedColor;
			}
			break;
		case IDC_RADIO_FirstCen:
		default:
			TestDlg_one->CenShow=true;
			TestDlg_one->ReSize=false;
			break;
	}
	TestDlg_one->add=add;
	TestDlg_one->filename=selectfilename;
	TestDlg_one->hBitmap=hBitmap;
	TestDlg_one->pNextWnd=pNextWnd;
	TestDlg_one->SetDlgRect(monitor_info_Testadd->DesktopOfMonitor);
//	TestDlg_one->Create(IDD_TEST_PATTERN,this);
	
	ShowWindow(SW_HIDE);
	SetTextDlg->ShowWindow(SW_HIDE);
	int dlg_ok=TestDlg_one->DoModal();//SW_SHOW

	delete TestDlg_one;

	if(dlg_ok==IDOK){
		CDialog::OnOK();
		return;
	}
	SetTextDlg->ShowWindow(SW_SHOW);
	ShowWindow(SW_SHOW);
	return ;
}

void CSetTestPatternDlg::OnDonot() 
{
	ShowWindow(SW_HIDE);
	SetTextDlg->ShowWindow(SW_HIDE);
	if(pNextWnd){
		int OkCancel=pNextWnd->DoModal();
		if(OkCancel==IDCANCEL){
			SetTextDlg->ShowWindow(SW_SHOW);
			ShowWindow(SW_SHOW);
			return;
		}
	}else{
		int YesNO=NECAfxMessageBox(IDS_MSG_SETEND,NULL,NULL,NULL,MB_YESNO|MB_ICONINFORMATION);
		if(YesNO==IDNO){
			SetTextDlg->ShowWindow(SW_SHOW);
			ShowWindow(SW_SHOW);
			return;
		}
		if(add<Count-1){
			TestSetDlg[add+1]->pNextWnd=NULL;
			if(TestSetDlg[add+1]->TestDlg_one!=NULL)
				TestSetDlg[add+1]->TestDlg_one->pNextWnd=NULL;
		}
	}
	CDialog::OnOK();
}

void CSetTestPatternDlg::OnBack() 
{
	if(TestSetDlg[Count-1]==this){
		CDialog::OnOK();
	}else{
		TestSetDlg[add]=new CSetTestPatternDlg;
		TestSetDlg[add]->add			=add;
		TestSetDlg[add]->selectfilename	=selectfilename;
//		TestSetDlg[add]->hBitmap		=hBmp;
//		TestSetDlg[add]->SetDlgRect(monitor_info_Testadd[sel].DesktopOfMonitor);
//		TestSetDlg[add]->CenShow		=true;
//		TestSetDlg[add]->ReSize			=false;

//		if(add<Count-1)
//			TestSetDlg[add+1]->pNextWnd=TestSetDlg[add];
		TestSetDlg[add]->pNextWnd=pNextWnd;

//		TestSetDlg[add]->monitor_info_Testadd=new monitor_info_TestPattern[1];
//		TestSetDlg[add]->monitor_info_Testadd->DesktopOfMonitor=monitor_info_Testadd[sel].DesktopOfMonitor;
//		TestSetDlg[add]->monitor_info_Testadd->MonitorName=monitor_info_Testadd[sel].MonitorName;
//		TestSetDlg[add]->monitor_info_Testadd->SystemNo=monitor_info_Testadd[sel].SystemNo;
		TestSetDlg[add]->monitor_info_Testadd=new monitor_info_TestPattern[1];
		TestSetDlg[add]->monitor_info_Testadd->DesktopOfMonitor	=monitor_info_Testadd->DesktopOfMonitor;
		TestSetDlg[add]->monitor_info_Testadd->MonitorName		=monitor_info_Testadd->MonitorName;
		TestSetDlg[add]->monitor_info_Testadd->SystemNo			=monitor_info_Testadd->SystemNo;

		TestSetDlg[add+1]->pNextWnd								=TestSetDlg[add];
		CDialog::OnCancel();
	}
	return;		
}

BOOL CSetTestPatternDlg::DestroyWindow() 
{
	if(SetTextDlg!=NULL){
		SetTextDlg->DestroyWindow();
		delete SetTextDlg;
	}
	if(SetRemindDlg!=NULL){
		SetRemindDlg->DestroyWindow();
		delete SetRemindDlg;
	}
	
	return CDialog::DestroyWindow();
}

void CSetTestPatternDlg::OnButtonCalcDisplay(){

	HBITMAP * phBmp=new HBITMAP;

	TestDlg_one=new CTestPatternDlg;
	TestDlg_one->add=add;
	TestDlg_one->CenShow=true;
	TestDlg_one->ReSize=false;
	TestDlg_one->filename=selectfilename;
	TestDlg_one->SetDlgRect(monitor_info_Testadd->DesktopOfMonitor);

	COLORREF * colors_t=NULL;
	*phBmp=CreateCalcBitmap_Colors(colors_t,monitor_info_Testadd->DesktopOfMonitor,*phBmp);

	TestDlg_one->hBitmap=*phBmp;
	TestDlg_one->pNextWnd=pNextWnd;
//	TestDlg_one->Create(IDD_TEST_PATTERN,this);
//	TestDlg_one->ShowWindow(SW_SHOWNOACTIVATE);
	delete [] colors_t;

	ShowWindow(SW_HIDE);
	SetTextDlg->ShowWindow(SW_HIDE);
	int dlg_ok=TestDlg_one->DoModal();//SW_SHOWNOACTIVATE

	delete TestDlg_one;
	::DeleteObject(*phBmp);
	delete phBmp;

	if(dlg_ok==IDOK){
		CDialog::OnOK();
		return;
	}
	SetTextDlg->ShowWindow(SW_SHOW);
	ShowWindow(SW_SHOW);
	return;
}
