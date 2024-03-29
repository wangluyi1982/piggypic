// NECTestPatternDlg.cpp : インプリメンテーション ファイル
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
// アプリケーションのバージョン情報で使われている CAboutDlg ダイアログ
extern CNECTestPatternApp theApp;

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ダイアログ データ
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternDlg ダイアログ

CNECTestPatternDlg::CNECTestPatternDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNECTestPatternDlg::IDD, pParent)
{
	InitClass();
}

CNECTestPatternDlg::CNECTestPatternDlg(UINT nIDTemplate, CWnd* pParent /*=NULL*/)
	: CDialog(nIDTemplate, pParent)
{
	InitClass();
}


//クラスのメンバーを初期化
void CNECTestPatternDlg::InitClass()
{
	//{{AFX_DATA_INIT(CNECTestPatternDlg)
	m_FileName = _T("");
	//}}AFX_DATA_INIT
	// メモ: LoadIcon は Win32 の DestroyIcon のサブシーケンスを要求しません。
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	monitor_info_Testadd=NULL;
	monitorselect_tab=NULL;

	CalcPat=
	monitor_info_count=0;
	CheckedRadioID=IDC_RADIO_FirstCen;
	SelectColor_show=SW_SHOW;
	win_show_sta=true;
	Enu_show=
	Enable_Enu=
	Enable_Color=FALSE;
	selectfilename=NULL;
	hBitmap=0;
	SelectedColor=RGB(0,0,0);
	monitorCheckAll=FALSE;
}

void CNECTestPatternDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNECTestPatternDlg)
	DDX_Control(pDX, IDC_BUTTON_PATTERN3, m_Button_Pattern3);
	DDX_Control(pDX, IDC_BUTTON_PATTERN2, m_Button_Pattern2);
	DDX_Control(pDX, IDC_BUTTON_PATTERN_CALC3, m_Button_Pattern_Calc3);
	DDX_Control(pDX, IDC_BUTTON_PATTERN_CALC2, m_Button_Pattern_Calc2);
	DDX_Control(pDX, IDC_BUTTON_PATTERN_CALC1, m_Button_Pattern_Calc1);
	DDX_Control(pDX, IDC_BUTTON_PATTERN1, m_Button_Pattern1);
	DDX_Control(pDX, IDC_LIST_DISPLAY, m_DisplayList);
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_FileName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNECTestPatternDlg, CDialog)
	//{{AFX_MSG_MAP(CNECTestPatternDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FILE, OnButtonFile)
	ON_EN_KILLFOCUS(IDC_EDIT_FILENAME, OnKillfocusEditFilename)
	ON_BN_CLICKED(IDC_EXITDLG, OnExitdlg)
	ON_BN_CLICKED(IDC_BUTTON_FILEDISPLAY, OnButtonFiledisplay)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN1, OnButtonPattern1)
	ON_BN_CLICKED(IDC_RADIO_FirstCen, OnRADIOFirstCen)
	ON_BN_CLICKED(IDC_RADIO_FirstExt, OnRADIOFirstExt)
	ON_BN_CLICKED(IDC_RADIO_FirstEnu, OnRADIOFirstEnu)
	ON_BN_CLICKED(IDC_RADIO_Ext_Pack, OnRADIOExtPack)
	ON_BN_CLICKED(IDC_RADIO_Ext_Width, OnRADIOExtWidth)
	ON_BN_CLICKED(IDC_RADIO_Ext_Height, OnRADIOExtHeight)
	ON_BN_CLICKED(IDC_RADIO_ONE, OnRadioOne)
	ON_BN_CLICKED(IDC_CHECK_ALL, OnCheckAll)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN2, OnButtonPattern2)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN3, OnButtonPattern3)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN_CALC1, OnButtonPatternCalc1)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN_CALC2, OnButtonPatternCalc2)
	ON_BN_CLICKED(IDC_BUTTON_PATTERN_CALC3, OnButtonPatternCalc3)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_COLOR, OnButtonSelectColor)
	ON_BN_CLICKED(IDC_RADIO_COLOR_SELECT, OnRadioColorSelect)
	ON_BN_CLICKED(IDC_RADIO_COLOR_FILE, OnRadioColorFile)
	ON_COMMAND(ID_MENUITEM_EXIT, OnMenuitemExit)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DISPLAY, OnClickListDisplay)
	ON_COMMAND(ID_MENUITEM_OPTION, OnMenuitemOption)
	ON_COMMAND(ID_MENUITEM_LANGUAGE_EN, OnMenuitemLanguageEn)
	ON_COMMAND(ID_MENUITEM_LANGUAGE_JP, OnMenuitemLanguageJp)
	ON_WM_INITMENUPOPUP()
	ON_BN_CLICKED(IDC_BUTTON_MONITORNUMBER, OnButtonMonitornumber)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_MONITOR_UPDATE, OnButtonMonitorUpdate)
	ON_BN_CLICKED(IDC_DESKPROPERTY, OnDeskproperty)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternDlg メッセージ ハンドラ

BOOL CNECTestPatternDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "バージョン情報..." メニュー項目をシステム メニューへ追加します。

	// IDM_ABOUTBOX はコマンド メニューの範囲でなければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログ用のアイコンを設定します。フレームワークはアプリケーションのメイン
	// ウィンドウがダイアログでない時は自動的に設定しません。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンを設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンを設定

	//ダイアログの「X」ボタンを無効化
	pSysMenu->DeleteMenu(SC_CLOSE,MF_BYCOMMAND|MF_GRAYED);
	
	//モニターリストクリック処理関数
// 	do 
// 	{
// 		glhHook_ListCtrl_Mouse=::SetWindowsHook(WH_MOUSE,ListCtrl_MouseProc);
// 	} 
// 	while(glhHook_ListCtrl_Mouse==NULL);

// 	do 
// 	{
// 		glhHook_DisplayChange=::SetWindowsHook(WM_DISPLAYCHANGE,NECTestPattern_DisplayChange);
// 	} 
// 	while(glhHook_DisplayChange==NULL);

	SetDisplayList();
	InitDlg();
	UpdateData(FALSE);
	
	return TRUE;  // TRUE を返すとコントロールに設定したフォーカスは失われません。
}

//ダイアログ表示位置を設定
//1番目モニターの真ん中
void CNECTestPatternDlg::SetDlgPos(CWnd * pDlg)
{
	//移動画面引数処理
	pDlg==NULL?pDlg=this:0;

	CRect rect_t;
	pDlg->GetWindowRect(&rect_t);

	//ダイアログの表示位置を計算
	int x0=((CNECTestPatternDlg*)theApp.m_pMainWnd)->monitor_info_Testadd[0].DesktopOfMonitor.left+(((CNECTestPatternDlg*)theApp.m_pMainWnd)->monitor_info_Testadd[0].DesktopOfMonitor.Width()-rect_t.Width())/2,
		y0=((CNECTestPatternDlg*)theApp.m_pMainWnd)->monitor_info_Testadd[0].DesktopOfMonitor.top+(((CNECTestPatternDlg*)theApp.m_pMainWnd)->monitor_info_Testadd[0].DesktopOfMonitor.Height()-rect_t.Height())/2;
	HWND hWnd=*pDlg;

	//画面を移動
	::SetWindowPos(hWnd,HWND_TOPMOST ,
		((CNECTestPatternDlg*)theApp.m_pMainWnd)->monitor_info_Testadd[0].DesktopOfMonitor.left,//x0,
		((CNECTestPatternDlg*)theApp.m_pMainWnd)->monitor_info_Testadd[0].DesktopOfMonitor.top,//y0,
		0,0,SWP_SHOWWINDOW);
	::MoveWindow(hWnd,
		x0,
		y0,
		rect_t.Width(),
		rect_t.Height(),
		true);
}

//初期化ダイアログ
//CSetTestPatternDlgクラスにもこの関数でダイアログを初期化
void CNECTestPatternDlg::InitDlg()
{
	//プレビュー部分
	XYandWH xywhItem;
	XYandWH BitPreGro_XyWh;
	GetDlgItemXYandWH(this,IDC_STATIC_PREVIEW,xywhItem);
	GetDlgItemXYandWH(this,IDC_STATIC_PREVIEW_GROUP,BitPreGro_XyWh);
	BitPreGro_XyWh.x0=xywhItem.x0-12;
	BitPreGro_XyWh.y0=xywhItem.y0-17;
	BitPreGro_XyWh.width=xywhItem.width+23;
	BitPreGro_XyWh.height=xywhItem.height+28;
	GetDlgItem(IDC_STATIC_PREVIEW_GROUP)->MoveWindow(BitPreGro_XyWh.x0,BitPreGro_XyWh.y0,BitPreGro_XyWh.width,BitPreGro_XyWh.height,TRUE);

	OldSetDlg=SetDlg;
	SetDlg=this;

	//チェックしたボタンID。ユーザ設定なしの時に、使い
	UINT Checkstate[7]=
	{
		IDC_RADIO_ALL,IDC_RADIO_Enu_cen,IDC_RADIO_Enu_ccen,
		IDC_RADIO_Ext_Pack,IDC_RADIO_Color_leftup,IDC_RADIO_COLOR_SELECT,
		IDC_RADIO_FirstCen
	};

	//先回のユーザ設定を読み込む
	if(OldSeted)
	{
		int in;
		m_FileName=AfxGetApp()->GetProfileString(_T("MainDialog"),_T("m_FileName"),NULL);
		if(!m_FileName.IsEmpty())
		{
			SelectFile();
		}
		
		for(int i=0;i<7;i++)
		{
			char temp[100];
			sprintf(temp,"%s[%d]","Checkstate",i);
			in=AfxGetApp()->GetProfileInt(_T("MainDialog"),temp,-1);
			if(in!=-1)
				Checkstate[i]=in;
		}

		in=AfxGetApp()->GetProfileInt(_T("MainDialog"),_T("Enu_show"),-1);
		if(in!=-1)
			Enu_show=in!=0?true:false;
		in=AfxGetApp()->GetProfileInt(_T("MainDialog"),_T("Enable_Color"),-1);
		if(in!=-1)
			Enable_Color=in!=0?true:false;
		in=AfxGetApp()->GetProfileInt(_T("MainDialog"),_T("Enable_Enu"),-1);
		if(in!=-1)
			Enable_Enu=in!=0?true:false;
		in=AfxGetApp()->GetProfileInt(_T("MainDialog"),_T("SelectColor_show"),-1);
		if(in!=-1)
			SelectColor_show=in!=0?true:false;
		in=AfxGetApp()->GetProfileInt(_T("MainDialog"),_T("SelectedColor"),-1);
		if(in!=-1)
			SelectedColor=in;
		CString temp=AfxGetApp()->GetProfileString(_T("MainDialog"),_T("IdentifyTime"),NULL);
		if(!temp.IsEmpty())
		{
			IdentifyTime=(float)atof(temp) ;
		}
	}
	else
	{
		m_FileName=selectfilename;
	}

	//ラジオボタンにチェックした状態を設定
	CheckRadioButton(IDC_RADIO_ALL,IDC_RADIO_ONE,Checkstate[0]);
	CheckRadioButton(IDC_RADIO_Enu_left,IDC_RADIO_Enu_right,Checkstate[1]);
	CheckRadioButton(IDC_RADIO_Enu_up,IDC_RADIO_Enu_down,Checkstate[2]);
	CheckRadioButton(IDC_RADIO_Ext_Width,IDC_RADIO_Ext_Pack,Checkstate[3]);
	CheckRadioButton(IDC_RADIO_Color_leftup,IDC_RADIO_Color_rightdown,Checkstate[4]);
	CheckRadioButton(IDC_RADIO_COLOR_SELECT,IDC_RADIO_COLOR_FILE,Checkstate[5]);
	CheckDlgButton(IDC_CHECK_ALL,monitorCheckAll);
//	if(CheckedRadioID!=0)
//		CheckRadioButton(IDC_RADIO_FirstCen,IDC_RADIO_FirstEnu,CheckedRadioID);
//	else
		CheckRadioButton(IDC_RADIO_FirstCen,IDC_RADIO_FirstEnu,Checkstate[6]);

	//標準画面テストのボタンにアイコンを追加
	m_Button_Pattern1.SetIcon(IDI_ICON_PATTERN7);
	m_Button_Pattern1.SetFlat(FALSE);
	m_Button_Pattern2.SetIcon(IDI_ICON_PATTERN8);
	m_Button_Pattern2.SetFlat(FALSE);
	m_Button_Pattern3.SetIcon(IDI_ICON_PATTERN9);
	m_Button_Pattern3.SetFlat(FALSE);
	m_Button_Pattern_Calc1.SetIcon(IDI_ICON_PATTERN_CALC1);
	m_Button_Pattern_Calc1.SetFlat(FALSE);
	m_Button_Pattern_Calc2.SetIcon(IDI_ICON_PATTERN_CALC2);
	m_Button_Pattern_Calc2.SetFlat(FALSE);
	m_Button_Pattern_Calc3.SetIcon(IDI_ICON_PATTERN_CALC3);
	m_Button_Pattern_Calc3.SetFlat(FALSE);

	//ダイアログの表示されるボックスを設定
	SetEnableWindow();

	//ダイアログを移動
	SetDlgPos();
}

void CNECTestPatternDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// もしダイアログボックスに最小化ボタンを追加するならば、アイコンを描画する
// コードを以下に記述する必要があります。MFC アプリケーションは document/view
// モデルを使っているので、この処理はフレームワークにより自動的に処理されます。

void CNECTestPatternDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画用のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// クライアントの矩形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンを描画します。
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		MainWndsta=TRUE;
		SetEnableWindow();
		CDialog::OnPaint();
	}
}

// システムは、ユーザーが最小化ウィンドウをドラッグしている間、
// カーソルを表示するためにここを呼び出します。
HCURSOR CNECTestPatternDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNECTestPatternDlg::OnButtonFile() 
{
	//対応ファイル：BMP、TIF、JPG、PNG、ICON
	pfiledlg=new CFileDialog(TRUE,"Display FILE",m_FileName,OFN_HIDEREADONLY,
		"Display FILE|*.BMP; *.JPG; *.JPEG; *.JPE; *.JPIF; *.GIF;*.TIF; *.TIFF; *.PNG; *.ICO|BMP FILE(*.BMP)|*.BMP|JPEG FILE(*.JPG; *.JPEG; *.JPE; *.JPIF;)|*.JPG; *.JPEG; *.JPE; *.JPIF|GIF FILE(*.GIF;)|*.GIF|TIFF FILE(*.TIF; *.TIFF)|*.TIF; *.TIFF|PNG FILE(*.PNG)|*.PNG|ICO FILE(*.ICO)|*.ICO|All Files(*.*)|*.*||",this);
	int OkCancel = pfiledlg->DoModal();
	if (OkCancel == IDCANCEL)
		return ;

	m_FileName = pfiledlg->GetPathName();
	UpdateData(FALSE);
	SelectFile();
}

//ユーザ選択したテストパターンファイルに必要な処理する
void CNECTestPatternDlg::SelectFile()
{
	//プレビュー画像を設定
	XYandWH xywhItem;
	UpdateData(FALSE);
	GetDlgItemXYandWH(this,IDC_STATIC_PREVIEW,xywhItem);
	if(hBitmap!=0)
	{
		::DeleteObject(hBitmap);
	}

	//ファイルをチェックして、プレビュー画像を作る
	hBitmap=CreateNewHBitmap(m_FileName.GetBuffer(m_FileName.GetLength()),hBitmap);

	//プレビュー画像を表示
	SetBitmapBoxSize(this,xywhItem,IDC_STATIC_PREVIEW,hBitmap,true);
	XYandWH BitPreGro_XyWh;
	GetDlgItemXYandWH(this,IDC_STATIC_PREVIEW_GROUP,BitPreGro_XyWh);
	BitPreGro_XyWh.x0=xywhItem.x0-12;
	BitPreGro_XyWh.y0=xywhItem.y0-17;
	BitPreGro_XyWh.width=xywhItem.width+23;
	BitPreGro_XyWh.height=xywhItem.height+28;
	GetDlgItem(IDC_STATIC_PREVIEW_GROUP)->MoveWindow(BitPreGro_XyWh.x0,BitPreGro_XyWh.y0,BitPreGro_XyWh.width,BitPreGro_XyWh.height,TRUE);

	SetEnableWindow();
}

//EDITボックス、編集してしまう処理
void CNECTestPatternDlg::OnKillfocusEditFilename() 
{
	UpdateData();
	if(m_FileName.IsEmpty())
	{
		selectfilename=NULL;
		SetEnableWindow();
		return;
	}
	SelectFile();
}

//EXITボタン
void CNECTestPatternDlg::OnExitdlg() 
{
	CDialog::OnOK();	
}

//「Esc」と「Enter」ボタンを無効
void CNECTestPatternDlg::OnCancel()
{

}

void CNECTestPatternDlg::OnOK()
{

}

//モニターリストに情報を書き込む
void CNECTestPatternDlg::SetDisplayList()
{
	//モニターの情報を読み込む
	//有効のモニター
	theEnumMonitors.Enumerate(true);

	int loop;
	monitor_info the_monitor_info;
	CString tempString;

	//モニターの台数
	monitor_info_count=theEnumMonitors.GetNumEnumerated();
	monitor_info_Testadd=new monitor_info_TestPattern[monitor_info_count];
	
	//モニター情報を読み込む
	for (loop=0; loop<monitor_info_count; loop++)
	{
		
		if (theEnumMonitors.GetDisplayInfoByEnum(loop,&the_monitor_info)==0)
		{

			monitor_info_Testadd[loop].MonitorName=the_monitor_info.m_sMonitorName;
			int Length_temp=the_monitor_info.m_sAdapterDevname.GetLength();
			char * temp=the_monitor_info.m_sAdapterDevname.GetBuffer(Length_temp);
			monitor_info_Testadd[loop].SystemNo=atoi(&temp[Length_temp-1]);
			monitor_info_Testadd[loop].DesktopOfMonitor=the_monitor_info.m_rectDisplayArea;
		}
	}

	//モニター情報の順番を調整
	int MonitorNoMax=ReSetMonitorInfo();

	//モニターリストのモデルを設定
	monitorselect_tab=new char[monitor_info_count];//MonitorNoMax
	CFont * pfont=GetFont();
	m_DisplayList.SetFont(pfont);
	m_DisplayList.SetExtendedStyle(WS_VSCROLL|WS_HSCROLL|LVS_EX_FULLROWSELECT);//|LVS_EX_CHECKBOXES
	m_DisplayList.SetColumnWidth(0,10000);
	int mo_loop=0;
//	monitor_info_Testadd[1].DesktopOfMonitor.right=monitor_info_Testadd[1].DesktopOfMonitor.left+monitor_info_Testadd[1].DesktopOfMonitor.Width()/2;

	//先回選択されたモニターを読み込む
	int old_seledmax;
	char * in_tab=NULL;
	char * in_Sel_tab=NULL;
	if(OldSeted)
	{
		old_seledmax=AfxGetApp()->GetProfileInt(_T("MainDialog"),_T("monitorselect"),-1);
		if(old_seledmax!=-1)
		{
			in_tab=new char [old_seledmax];
			in_Sel_tab=new char [old_seledmax];
			int i=old_seledmax;
			while(i--)
			{
				char temp[100];
				sprintf(temp,"%s%d",_T("monitorselect_"),i);
				in_tab[i]=AfxGetApp()->GetProfileInt(_T("MainDialog"),temp,-1);
				in_Sel_tab[i]=-1;
			}
		}
	}

	//モニターリストに書き込む
	for (loop=0; loop<monitor_info_count; loop++)
	{//MonitorNoMax
		monitorselect_tab[loop]=0;
		CString tempstr;
//		if(monitor_info_Testadd[mo_loop].SystemNo==loop+1){
			tempstr.Format("Display%d: %s ;  Resolution: %d * %d",
				monitor_info_Testadd[mo_loop].SystemNo,
				monitor_info_Testadd[mo_loop].MonitorName,
				monitor_info_Testadd[mo_loop].DesktopOfMonitor.Width(),
				monitor_info_Testadd[mo_loop].DesktopOfMonitor.Height()
				);
/*			CRect Listrect;
			GetDlgItem(IDC_LIST_DISPLAY)->GetWindowRect(&Listrect);
			CDC * Listpdc=m_DisplayList.GetDC();
			while ((Listpdc->GetTextExtent(tempstr)).cx<Listrect.right)
			{
				tempstr+=" ";
			}*/
			m_DisplayList.InsertItem(mo_loop,tempstr);
			if(OldSeted)
			{
				for(int j=0;j<old_seledmax;j++)
				{
					if(monitor_info_Testadd[mo_loop].SystemNo==in_tab[j])
					{
						in_Sel_tab[j]=loop;
					}
				}
			}
			mo_loop++;
//		}
	}

	//選択されたモニターを選択状態に表示
	if(FristRun!=-1&&OldSeted)
	{
		for(int j=0;j<old_seledmax;j++)
		{
			if(in_Sel_tab[j]!=-1)
			{
				m_DisplayList.SetItemState(in_Sel_tab[j], LVIS_FOCUSED |LVIS_SELECTED   , LVIS_FOCUSED | LVIS_SELECTED  );
				monitorselect_tab[ in_Sel_tab[j] ]=1;
			}
		}
	}
	else
	{
		m_DisplayList.SetItemState(0, LVIS_FOCUSED |LVIS_SELECTED   , LVIS_FOCUSED | LVIS_SELECTED  );
		monitorselect_tab[0]=1;
	}
//	SetTimer(1,1,NULL);

	//終了
	if(in_tab!=NULL)
	{
		delete [] in_tab;
	}
	return ;
}

//読み込むモニター情報のい順番を調整する
int  CNECTestPatternDlg::ReSetMonitorInfo()
{
	int MonitorNoMax=monitor_info_Testadd[0].SystemNo;
	if(monitor_info_count<=1)return MonitorNoMax;

	int loop;
	int * temp_No[2];
	temp_No[0]=new int[monitor_info_count];
	temp_No[1]=new int[monitor_info_count];

	//モニター番号を一時バッファに保存
	for(loop=0;loop<monitor_info_count;loop++)
	{
		temp_No[0][loop]=loop;
		temp_No[1][loop]=monitor_info_Testadd[loop].SystemNo;
		if(monitor_info_Testadd[loop].SystemNo>MonitorNoMax)
			MonitorNoMax=monitor_info_Testadd[loop].SystemNo;
	}

	//モニター番号の順番を調整
	int chench=0;
	for(loop=1;loop<monitor_info_count-1;loop++)
	{
		int hch=0;
		for(int j=monitor_info_count-1;j>loop;j--)
		{
			if(temp_No[1][j]<temp_No[1][j-1])
			{
				
				temp_No[1][j]+=temp_No[1][j-1];
				temp_No[1][j-1]=temp_No[1][j]-temp_No[1][j-1];
				temp_No[1][j]-=temp_No[1][j-1];

				temp_No[0][j]+=temp_No[0][j-1];
				temp_No[0][j-1]=temp_No[0][j]-temp_No[1][j-1];
				temp_No[0][j]-=temp_No[0][j-1];
				hch=1;chench++;
			}
		}
		if(hch==0)break;
	}

	//モニター情報の順番を調整
	if(chench!=0)
	{
		monitor_info_TestPattern * temp_moninfo=new monitor_info_TestPattern[monitor_info_count];
		memcpy(temp_moninfo,monitor_info_Testadd,sizeof(monitor_info_TestPattern)*monitor_info_count);
		for (loop=0;loop<monitor_info_count;loop++)
		{
			if(temp_No[0][loop]!=loop)
			{
				memcpy(&monitor_info_Testadd[loop],&monitor_info_Testadd[temp_No[0][loop]],sizeof(monitor_info_TestPattern));
			}
		}
		delete [] temp_moninfo;
	}
	delete [] temp_No[1];
	delete [] temp_No[0];
	return MonitorNoMax;
}

//ユーザ選択のファイルを表示する
void CNECTestPatternDlg::OnButtonFiledisplay() 
{


	//選択したモニター台数
	Count=m_DisplayList.GetSelectedCount();
	if(Count<1)
	{
		NECAfxMessageBox(IDS_ERR_SELECTMONITOR);
		return;
	}

	//選択したモニター
	POSITION pos=m_DisplayList.GetFirstSelectedItemPosition();

	//テスト画面を作り
	TestDlg=new CTestPatternDlg *[Count];
	int cou=Count;
	while (cou--)
	{
		int sel=m_DisplayList.GetNextSelectedItem(pos);
	
		CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_FirstCen,IDC_RADIO_FirstEnu);

		TestDlg[cou]=new CTestPatternDlg;
		
		//表示モデルの判断
		switch(CheckedRadioID)
		{
			case IDC_RADIO_FirstExt:
			case IDC_RADIO_FirstEnu:
				switch(CheckedRadioID)
				{
					case IDC_RADIO_FirstExt:
						TestDlg[cou]->CenShow=false;
						TestDlg[cou]->ReSize=true;
						CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_Ext_Width,IDC_RADIO_Ext_Pack);
						TestDlg[cou]->Ext=CheckedRadioID-IDC_RADIO_Ext_Width;
						break;
					case IDC_RADIO_FirstEnu:
						TestDlg[cou]->CenShow=false;
						TestDlg[cou]->ReSize=false;
						CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_Enu_left,IDC_RADIO_Enu_right);
						TestDlg[cou]->Enu_Hor_pos=CheckedRadioID-IDC_RADIO_Enu_left;
						CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_Enu_up,IDC_RADIO_Enu_down);
						TestDlg[cou]->Enu_Ver_pos=CheckedRadioID-IDC_RADIO_Enu_up;

						break;
				}
				CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_Color_leftup,IDC_RADIO_Color_rightdown);
				TestDlg[cou]->Color_pos=CheckedRadioID-IDC_RADIO_Color_leftup;
				CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_COLOR_SELECT,IDC_RADIO_COLOR_FILE);
				if(CheckedRadioID==IDC_RADIO_COLOR_SELECT)
				{
					TestDlg[cou]->Color_pos=-1;
					TestDlg[cou]->SelectedCol=SelectedColor;
				}
				break;
			case IDC_RADIO_FirstCen:
			default:
				TestDlg[cou]->CenShow=true;
				TestDlg[cou]->ReSize=false;
				break;
		}

		//画面引数を初期
		TestDlg[cou]->add=cou;
		TestDlg[cou]->filename=selectfilename;
		TestDlg[cou]->hBitmap=hBitmap;
		
		//次の画面を設定
		if(cou<Count-1)
			TestDlg[cou+1]->pNextWnd=TestDlg[cou];
		
		//モニターの位置
		TestDlg[cou]->SetDlgRect(monitor_info_Testadd[sel].DesktopOfMonitor);
//		TestDlg[cou]->Create(IDD_TEST_PATTERN,this);
	}

	//テスト画面を表示された。
	ShowWindow(SW_HIDE);
	TestDlg[Count-1]->DoModal();//SW_SHOWNOACTIVATE
	ShowWindow(SW_SHOW);

	//テスト画面を削除
	if(TestDlg)
	{
		for(int i=0;i<Count;i++)
		{
			delete TestDlg[i];
		}
		delete [] TestDlg;
		TestDlg=NULL;
	}
}

//ダイアログ退出処理
BOOL CNECTestPatternDlg::DestroyWindow() 
{
	if(OldSeted)
	{
		SaveSeted();
	}
	if(monitor_info_Testadd)
		delete []monitor_info_Testadd	;
	if(monitorselect_tab)
		delete []monitorselect_tab	;
	SetDlg=OldSetDlg;
	if(hBitmap!=0)
	{
		::DeleteObject(hBitmap);
		hBitmap=0;
	}
// 	if(glhHook_ListCtrl_Mouse!=NULL)
// 		UnhookWindowsHookEx(glhHook_ListCtrl_Mouse);
// 	if(glhHook_DisplayChange!=NULL)
// 		UnhookWindowsHookEx(glhHook_DisplayChange);
	return CDialog::DestroyWindow();
}

//ユーザのソフト設定を保存
void CNECTestPatternDlg::SaveSeted()
{
	//testパターンファイル名前
	if(selectfilename!=NULL)
		AfxGetApp()->WriteProfileString(_T("MainDialog"),_T("m_FileName"),m_FileName);

	//表示されたボックス
	AfxGetApp()->WriteProfileInt(_T("MainDialog"),_T("Enu_show"),Enu_show);
	AfxGetApp()->WriteProfileInt(_T("MainDialog"),_T("Enable_Color"),Enable_Color);
	AfxGetApp()->WriteProfileInt(_T("MainDialog"),_T("Enable_Enu"),Enable_Enu);
	AfxGetApp()->WriteProfileInt(_T("MainDialog"),_T("SelectColor_show"),SelectColor_show);

	//補充色
	AfxGetApp()->WriteProfileInt(_T("MainDialog"),_T("SelectedColor"),SelectedColor);

	//モニター識別時間
	CString temp;
	temp.Format("%f",IdentifyTime);
	AfxGetApp()->WriteProfileString(_T("MainDialog"),_T("IdentifyTime"),temp);

	//選択されたモニター番号
	POSITION pos=m_DisplayList.GetFirstSelectedItemPosition();
	int i=m_DisplayList.GetSelectedCount();
	AfxGetApp()->WriteProfileInt(_T("MainDialog"),_T("monitorselect"),i);
	while(i--)
	{
		int sel=m_DisplayList.GetNextSelectedItem(pos);
		char temp[100];
		sprintf(temp,"%s%d",_T("monitorselect_"),i);
		AfxGetApp()->WriteProfileInt(_T("MainDialog"),temp,monitor_info_Testadd[sel].SystemNo);
	}
	
	//ラジオボックスの状態
	int out [7];
	out[0]=GetCheckedRadioButton(IDC_RADIO_ALL,IDC_RADIO_ONE);
	out[1]=GetCheckedRadioButton(IDC_RADIO_Enu_left,IDC_RADIO_Enu_right);
	out[2]=GetCheckedRadioButton(IDC_RADIO_Enu_up,IDC_RADIO_Enu_down);
	out[3]=GetCheckedRadioButton(IDC_RADIO_Ext_Width,IDC_RADIO_Ext_Pack);
	out[4]=GetCheckedRadioButton(IDC_RADIO_Color_leftup,IDC_RADIO_Color_rightdown);
	out[5]=GetCheckedRadioButton(IDC_RADIO_COLOR_SELECT,IDC_RADIO_COLOR_FILE);
	out[6]=GetCheckedRadioButton(IDC_RADIO_FirstCen,IDC_RADIO_FirstEnu);
	for(i=0;i<7;i++)
	{
		char temp[100];
		sprintf(temp,"%s[%d]","Checkstate",i);
		AfxGetApp()->WriteProfileInt(_T("MainDialog"),temp,out[i]);
	}

}

//画面ボックスの状態を設定
void CNECTestPatternDlg::SetEnableWindow()
{
	if(selectfilename!=NULL)
	{
		GetDlgItem(IDC_BUTTON_FILEDISPLAY)->EnableWindow(true);
		GetDlgItem(IDC_RADIO_FirstCen)->EnableWindow(true);
		GetDlgItem(IDC_RADIO_FirstExt)->EnableWindow(true);
		GetDlgItem(IDC_RADIO_FirstEnu)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_BUTTON_FILEDISPLAY)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_FirstCen)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_FirstExt)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_FirstEnu)->EnableWindow(FALSE);
	}
	ShowEnuRadio();
}

//表示されるラジオボックスを設定
void CNECTestPatternDlg::ShowEnuRadio()
{
	//ラジオボックスの有効化に設定
	bool temp=FALSE;
	if(selectfilename!=NULL&&Enable_Enu)
	{
		temp=TRUE;
	}
	GetDlgItem(IDC_STATIC_Enu)->EnableWindow(temp);
	GetDlgItem(IDC_RADIO_Enu_left)->EnableWindow(temp);
	GetDlgItem(IDC_RADIO_Enu_cen)->EnableWindow(temp);
	GetDlgItem(IDC_RADIO_Enu_right)->EnableWindow(temp);
	GetDlgItem(IDC_RADIO_Enu_up)->EnableWindow(temp);
	GetDlgItem(IDC_RADIO_Enu_ccen)->EnableWindow(temp);
	GetDlgItem(IDC_RADIO_Enu_down)->EnableWindow(temp);

	GetDlgItem(IDC_STATIC_Ext)->EnableWindow(temp);
	GetDlgItem(IDC_RADIO_Ext_Width)->EnableWindow(temp);
	GetDlgItem(IDC_RADIO_Ext_Height)->EnableWindow(temp);
	GetDlgItem(IDC_RADIO_Ext_Pack)->EnableWindow(temp);

	//表示されたラジオボックスを設定
	int ShowEnu=SW_HIDE;
	int ShowExt=SW_SHOW;
	if(Enu_show)
	{
		ShowEnu=SW_SHOW;
		ShowExt=SW_HIDE;
	}
	GetDlgItem(IDC_STATIC_Enu)->ShowWindow(ShowEnu);
	GetDlgItem(IDC_RADIO_Enu_left)->ShowWindow(ShowEnu);
	GetDlgItem(IDC_RADIO_Enu_cen)->ShowWindow(ShowEnu);
	GetDlgItem(IDC_RADIO_Enu_right)->ShowWindow(ShowEnu);
	GetDlgItem(IDC_RADIO_Enu_up)->ShowWindow(ShowEnu);
	GetDlgItem(IDC_RADIO_Enu_ccen)->ShowWindow(ShowEnu);
	GetDlgItem(IDC_RADIO_Enu_down)->ShowWindow(ShowEnu);

	GetDlgItem(IDC_STATIC_Ext)->ShowWindow(ShowExt);
	GetDlgItem(IDC_RADIO_Ext_Width)->ShowWindow(ShowExt);
	GetDlgItem(IDC_RADIO_Ext_Height)->ShowWindow(ShowExt);
	GetDlgItem(IDC_RADIO_Ext_Pack)->ShowWindow(ShowExt);

	EnableEnuRadio_Color();
}

void CNECTestPatternDlg::OnButtonPattern1() 
{
// 	OnButtonDisplay("TestPattern\\7.bmp");
	OnButtonDisplay(IDB_BITMAP_PATTERN7);
}

//標準画像表示処理
void CNECTestPatternDlg::OnButtonDisplay(int PatternBmpID)
{

	//選択されたモニター台数を判断
	Count=m_DisplayList.GetSelectedCount();
	if(Count<1)
	{
		NECAfxMessageBox(IDS_ERR_SELECTMONITOR);
		return;
	}
	POSITION pos=m_DisplayList.GetFirstSelectedItemPosition();

	HBITMAP hBmp=::LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(PatternBmpID));

	//test画面初期化
	TestDlg=new CTestPatternDlg *[Count];
	int cou=Count;
	while (cou--)
	{
		int sel=m_DisplayList.GetNextSelectedItem(pos);
	
		TestDlg[cou]=new CTestPatternDlg;
		TestDlg[cou]->add=cou;
		TestDlg[cou]->CenShow=true;
		TestDlg[cou]->ReSize=false;
		TestDlg[cou]->filename=selectfilename;
		TestDlg[cou]->hBitmap=hBmp;
		TestDlg[cou]->SetDlgRect(monitor_info_Testadd[sel].DesktopOfMonitor);
		if(cou<Count-1)
			TestDlg[cou+1]->pNextWnd=TestDlg[cou];
//		TestDlg[cou]->Create(IDD_TEST_PATTERN,this);
//		TestDlg[cou]->ShowWindow(SW_SHOWNOACTIVATE);
	}

	//画面を出す
	ShowWindow(SW_HIDE);
	TestDlg[Count-1]->DoModal();//SW_SHOWNOACTIVATE
	ShowWindow(SW_SHOW);

	//画面を削除
	if(TestDlg)
	{
		for(int i=0;i<Count;i++)
		{
			delete TestDlg[i];
		}
		delete [] TestDlg;
		TestDlg=NULL;
	}
	::DeleteObject(hBmp);
	return;
}

//モニターリストをクリック関数
void CNECTestPatternDlg::OnClickListDisplay(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 1;
//	int NextItemID=IDC_BUTTON_PATTERN1;

	//「すべて」を選択された状態の処理
	if(monitorCheckAll==TRUE)
	{
		NECAfxMessageBox(IDS_WAR_SELECTMONITOR_ALL);
		for(int i=0;i<monitor_info_count;i++)
		{
			monitorselect_tab[i]=monitorCheckAll;
			m_DisplayList.SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
		}
//		GetDlgItem(NextItemID)->SetFocus();
		return;
	}
}
/*//	int i;
//	NM_LISTVIEW * pNMListView = (NM_LISTVIEW*)pNMHDR;
//	if(pNMListView->iItem != -1){
//		monitorselect_tab[pNMListView->iItem]=monitorselect_tab[pNMListView->iItem]?0:1;
//	}
//	for( i=0;i<monitor_info_count;i++){
//		if(monitorselect_tab[i]==0){
//			m_DisplayList.SetItemState(i, 0, LVIS_SELECTED);
//		}
//	}
////	GetDlgItem(NextItemID)->SetFocus();
//	for( i=0;i<monitor_info_count;i++){
//		if(monitorselect_tab[i]!=0){
//			m_DisplayList.SetItemState(i, LVIS_FOCUSED |LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
//		}
//	}
//	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);
//	if(pLVCD->nmcd.dwDrawStage==CDDS_PREPAINT)
//
//		pLVCD->nmcd.dwDrawStage=CDDS_POSTPAINT;
//	else
//		pLVCD->nmcd.dwDrawStage=CDRF_SKIPDEFAULT;

}
*/

//ラジオボタンチェック処理
void CNECTestPatternDlg::OnRADIOFirstCen() 
{
	Enable_Enu=Enable_Color=FALSE;	
	ShowEnuRadio();
}

//ラジオボタンチェック処理
void CNECTestPatternDlg::OnRADIOFirstExt() 
{
	Enable_Color=
	Enable_Enu=TRUE;	
	Enu_show	=FALSE;
	int CheckedRadioID=GetCheckedRadioButton(IDC_RADIO_Ext_Width,IDC_RADIO_Ext_Pack);
	if(CheckedRadioID==IDC_RADIO_Ext_Pack)Enable_Color=FALSE;
	ShowEnuRadio();
}

//ラジオボタンチェック処理
void CNECTestPatternDlg::OnRADIOFirstEnu() 
{
	Enable_Enu=
	Enable_Color=
	Enu_show	=TRUE;	
	ShowEnuRadio();
}

//ラジオボタンチェック処理
void CNECTestPatternDlg::OnRADIOExtPack(){
	Enable_Color=FALSE;
	EnableEnuRadio_Color();

}

//ラジオボタンチェック処理
void CNECTestPatternDlg::OnRADIOExtWidth() 
{
	Enable_Color=TRUE;
	EnableEnuRadio_Color();
	
}

//ラジオボタンチェック処理
void CNECTestPatternDlg::OnRADIOExtHeight() 
{
	Enable_Color=TRUE;
	EnableEnuRadio_Color();
	
}

//ラジオボタンの状態を設定
void CNECTestPatternDlg::EnableEnuRadio_Color()
{
	GetDlgItem(IDC_STATIC_Color)->EnableWindow(Enable_Color);
	GetDlgItem(IDC_RADIO_COLOR_SELECT)->EnableWindow(Enable_Color);
	GetDlgItem(IDC_RADIO_COLOR_FILE)->EnableWindow(Enable_Color);

	GetDlgItem(IDC_STATIC_COLOR_FILE)->EnableWindow(Enable_Color);
	GetDlgItem(IDC_RADIO_Color_leftup)->EnableWindow(Enable_Color);
	GetDlgItem(IDC_RADIO_Color_leftdown)->EnableWindow(Enable_Color);
	GetDlgItem(IDC_RADIO_Color_cen)->EnableWindow(Enable_Color);
	GetDlgItem(IDC_RADIO_Color_rightup)->EnableWindow(Enable_Color);
	GetDlgItem(IDC_RADIO_Color_rightdown)->EnableWindow(Enable_Color);
	
	GetDlgItem(IDC_STATIC_SELECTED_COLOR)->EnableWindow(Enable_Color);
	GetDlgItem(IDC_BUTTON_SELECT_COLOR)->EnableWindow(Enable_Color);
	GetDlgItem(IDC_STATIC_COLOR_SELECT)->EnableWindow(Enable_Color);

	//カラーについて部分
	ShowEnuRadio_Color();
}

//ラジオボタンの状態を設定（カラーについて部分）
void CNECTestPatternDlg::ShowEnuRadio_Color()
{

	//表示されたボックス
	int FileColor_show=SW_HIDE;
	if(SelectColor_show==SW_HIDE)
	{
		FileColor_show=SW_SHOW;
	}
	GetDlgItem(IDC_STATIC_COLOR_FILE)->ShowWindow(FileColor_show);
	GetDlgItem(IDC_RADIO_Color_leftup)->ShowWindow(FileColor_show);
	GetDlgItem(IDC_RADIO_Color_leftdown)->ShowWindow(FileColor_show);
	GetDlgItem(IDC_RADIO_Color_cen)->ShowWindow(FileColor_show);
	GetDlgItem(IDC_RADIO_Color_rightup)->ShowWindow(FileColor_show);
	GetDlgItem(IDC_RADIO_Color_rightdown)->ShowWindow(FileColor_show);

	GetDlgItem(IDC_STATIC_COLOR_SELECT)->ShowWindow(SelectColor_show);
	GetDlgItem(IDC_STATIC_SELECTED_COLOR)->ShowWindow(SelectColor_show);

	//カラーのプレビューを初期
	CStatic * pStaitc=(CStatic *)GetDlgItem(IDC_BUTTON_SELECT_COLOR);
	XYandWH xywhItem;
	GetDlgItemXYandWH(this,IDC_STATIC_SELECTED_COLOR,xywhItem);
	HBITMAP hBmp=CreateNewHBitmap_SELCOLOR(SelectedColor,hBmp);
	SetBitmapBoxSize(this,xywhItem,IDC_STATIC_SELECTED_COLOR,hBmp,true);
	pStaitc->ShowWindow(SelectColor_show);
	
	DeleteObject(hBmp);
}

//各モニター表示処理
void CNECTestPatternDlg::OnRadioOne() 
{
	//モニター選択された台数
	Count=m_DisplayList.GetSelectedCount();

	//選択されたモニターがない場合
	if(Count<1)
	{
		NECAfxMessageBox(IDS_ERR_SELECTMONITOR);
		CheckRadioButton(IDC_RADIO_ALL,IDC_RADIO_ONE,IDC_RADIO_ALL);
		GetDlgItem(IDC_RADIO_ALL)->SetFocus();
		return;
	}

	//選択されたモニターが少ない場合
	if(Count<2)
	{
		NECAfxMessageBox(IDS_WAR_SELECTMONITOR_ONE);
		CheckRadioButton(IDC_RADIO_ALL,IDC_RADIO_ONE,IDC_RADIO_ALL);
		GetDlgItem(IDC_RADIO_ALL)->SetFocus();
		return;
	}

	//テスト画面を作成
	POSITION pos=m_DisplayList.GetFirstSelectedItemPosition();
	TestSetDlg=new CSetTestPatternDlg *[Count];
	int cou=Count;
	while (cou--)
	{
		int sel=m_DisplayList.GetNextSelectedItem(pos);
	
		TestSetDlg[cou]=new CSetTestPatternDlg;
		TestSetDlg[cou]->add=cou;
//		TestSetDlg[cou]->CenShow=true;
//		TestSetDlg[cou]->ReSize=false;
		TestSetDlg[cou]->selectfilename=selectfilename;
//		TestSetDlg[cou]->hBitmap=hBmp;
//		TestSetDlg[cou]->SetDlgRect(monitor_info_Testadd[sel].DesktopOfMonitor);
		if(cou<Count-1)
			TestSetDlg[cou+1]->pNextWnd=TestSetDlg[cou];

		TestSetDlg[cou]->monitor_info_Testadd=new monitor_info_TestPattern[1];
		TestSetDlg[cou]->monitor_info_Testadd->DesktopOfMonitor=monitor_info_Testadd[sel].DesktopOfMonitor;
		TestSetDlg[cou]->monitor_info_Testadd->MonitorName=monitor_info_Testadd[sel].MonitorName;
		TestSetDlg[cou]->monitor_info_Testadd->SystemNo=monitor_info_Testadd[sel].SystemNo;
	}

	//画面を出す
	ShowWindow(SW_HIDE);
	TestSetDlg[Count-1]->DoModal();//SW_SHOWNOACTIVATE
	ShowWindow(SW_SHOW);

	//画面を削除
	if(TestSetDlg)
	{
		for(int i=0;i<Count;i++)
		{
			delete TestSetDlg[i];
		}
		delete [] TestSetDlg;
		TestSetDlg=NULL;
	}

	//ラジオボタンの設定
	CheckRadioButton(IDC_RADIO_ALL,IDC_RADIO_ONE,IDC_RADIO_ALL);
	GetDlgItem(IDC_RADIO_ALL)->SetFocus();
	::SetForegroundWindow(m_hWnd);
	return;	
}

//すべてモニターを選択された処理
void CNECTestPatternDlg::OnCheckAll() 
{

	//すべてのモニターを選択された状態に設定
	monitorCheckAll=monitorCheckAll?false:true;
	if(monitorCheckAll==TRUE)
	{
		for(int i=0;i<monitor_info_count;i++)
		{
			monitorselect_tab[i]=monitorCheckAll;
			m_DisplayList.SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
		}
	}
}

void CNECTestPatternDlg::OnButtonPattern2() 
{
	OnButtonDisplay(IDB_BITMAP_PATTERN8);
}

void CNECTestPatternDlg::OnButtonPattern3() 
{
	OnButtonDisplay(IDB_BITMAP_PATTERN9);
}

//作成画像表示
void CNECTestPatternDlg::OnButtonPatternCalc1() 
{
	CalcPat=1;
	CreateCalcBitmap_Colors=CreateCalcBitmap_Colors1;
	OnButtonCalcDisplay();
}

//作成画像表示処理関数
void CNECTestPatternDlg::OnButtonCalcDisplay(){

	CalcPattern=TRUE;
	//選択されたモニター台数
	Count=m_DisplayList.GetSelectedCount();
	if(Count<1)
	{
		NECAfxMessageBox(IDS_ERR_SELECTMONITOR);
		return;
	}

	POSITION pos=m_DisplayList.GetFirstSelectedItemPosition();

	HBITMAP * phBmp=new HBITMAP[Count];

	TestDlg=new CTestPatternDlg *[Count];
	int cou=Count;

	//対応できないモニターの処理
	CreateCalcBitmap_Colors_Ci=NULL;
	if(this==theApp.m_pMainWnd&&Count>1)
	{
		if(NECAfxMessageBox(IDS_WAR_CALC1+CalcPat-1,NULL,NULL,NULL,MB_YESNO|MB_ICONQUESTION)==IDYES){
			CCalcDlg CalcDlg(CalcPat);
			CalcDlg.DoModal();
			switch(CalcDlg.CheckID)
			{
				case 0:
				default:
					CreateCalcBitmap_Colors_Ci=CreateCalcBitmap_Colors1;
					break;
				case 1:
					CreateCalcBitmap_Colors_Ci=CreateCalcBitmap_Colors2;
					break;
				case 2:
					CreateCalcBitmap_Colors_Ci=CreateCalcBitmap_Colors3;
					break;
			}	
		}
	}

	//テスト画面を初期化
	while (cou--)
	{
		int sel=m_DisplayList.GetNextSelectedItem(pos);
	
		TestDlg[cou]=new CTestPatternDlg;
		TestDlg[cou]->add=cou;
		TestDlg[cou]->CenShow=true;
		TestDlg[cou]->ReSize=false;
		TestDlg[cou]->filename=selectfilename;
		TestDlg[cou]->SetDlgRect(monitor_info_Testadd[sel].DesktopOfMonitor);

		COLORREF * colors_t=NULL;
		if(NULL == CreateCalcBitmap_Colors_Ci)
		{
			phBmp[cou]=CreateCalcBitmap_Colors(colors_t,monitor_info_Testadd[sel].DesktopOfMonitor,phBmp[cou]);
		}
		else
		{
			if(monitor_info_Testadd[sel].DesktopOfMonitor.Width()>monitor_info_Testadd[sel].DesktopOfMonitor.Height())
			{
				if(CreateCalcBitmap_Colors==CreateCalcBitmap_Colors1)
					phBmp[cou]=CreateCalcBitmap_Colors(colors_t,monitor_info_Testadd[sel].DesktopOfMonitor,phBmp[cou]);
				else
					phBmp[cou]=CreateCalcBitmap_Colors_Ci(colors_t,monitor_info_Testadd[sel].DesktopOfMonitor,phBmp[cou]);
			}
			else
			{
				if(CreateCalcBitmap_Colors==CreateCalcBitmap_Colors1)
					phBmp[cou]=CreateCalcBitmap_Colors_Ci(colors_t,monitor_info_Testadd[sel].DesktopOfMonitor,phBmp[cou]);
				else
					phBmp[cou]=CreateCalcBitmap_Colors(colors_t,monitor_info_Testadd[sel].DesktopOfMonitor,phBmp[cou]);
			}
		}

		TestDlg[cou]->hBitmap=phBmp[cou];
		if(cou<Count-1)
			TestDlg[cou+1]->pNextWnd=TestDlg[cou];
//		TestDlg[cou]->Create(IDD_TEST_PATTERN,this);
//		TestDlg[cou]->ShowWindow(SW_SHOWNOACTIVATE);
		delete [] colors_t;
	}

	//画面を出す
	ShowWindow(SW_HIDE);
	TestDlg[Count-1]->DoModal();//SW_SHOWNOACTIVATE
	ShowWindow(SW_SHOW);

	//画面を削除
	if(TestDlg)
	{
		for(int i=0;i<Count;i++)
		{
			delete TestDlg[i];
		}
		delete [] TestDlg;
		TestDlg=NULL;
	}
	for(int i=0;i<Count;i++)
	{
		::DeleteObject(phBmp[i]);
	}
	CalcPattern=FALSE;
	delete [] phBmp;
	return;
}

void CNECTestPatternDlg::OnButtonPatternCalc2() 
{
	CalcPat=2;
	CreateCalcBitmap_Colors=CreateCalcBitmap_Colors2;
	OnButtonCalcDisplay();
}

void CNECTestPatternDlg::OnButtonPatternCalc3() 
{
	CalcPat=3;
	CreateCalcBitmap_Colors=CreateCalcBitmap_Colors3;
	OnButtonCalcDisplay();
}

//カラーを選択
void CNECTestPatternDlg::OnButtonSelectColor() 
{
	CColorDialog col_dlg(SelectedColor);
	if(col_dlg.DoModal()==IDOK)
	{
		//からーを読み出す
		SelectedColor=col_dlg.GetColor();
		ShowEnuRadio_Color();
	}
}

void CNECTestPatternDlg::OnRadioColorSelect() 
{
	SelectColor_show=SW_SHOW;
	ShowEnuRadio_Color();
}

void CNECTestPatternDlg::OnRadioColorFile() 
{
	SelectColor_show=SW_HIDE;
	ShowEnuRadio_Color();
}


void CNECTestPatternDlg::OnMenuitemExit() 
{
	OnExitdlg();	
}

void CNECTestPatternDlg::OnAppAbout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

//ソフトオプションを設定
void CNECTestPatternDlg::OnMenuitemOption() 
{
	CSoftOptionDlg setDlg(&OldSeted,
		&ExitMessageNoShow,
		&TesttingMsg,
		&TesttingMsg_ALL,
		&IdentifyTime);
	setDlg.DoModal();
	
}

//モニター識別
void CNECTestPatternDlg::OnButtonMonitornumber() 
{
	if(monitor_info_count<1)
	{
		return ;
	}

	//画面を作成
	ShowWindow(SW_HIDE);
	pMonitorNum = new CSettingRemindDlg *[monitor_info_count];

	for(int i=0;i<monitor_info_count;i++)
	{
		pMonitorNum[i]=new CSettingRemindDlg;
		pMonitorNum[i]->Create(CSettingRemindDlg::IDD,this,monitor_info_Testadd[i].DesktopOfMonitor,monitor_info_Testadd[i].SystemNo);
		pMonitorNum[i]->ShowWindow(SW_SHOW);
	}

	//終了時間を設定
	int Identifytime=int(IdentifyTime*1000);
	SetTimer(2,Identifytime,NULL);
}

void CNECTestPatternDlg::OnTimer(UINT nIDEvent) 
{
	//モニター識別終了
	if(nIDEvent==2)
	{
		KillTimer(2);
		for(int i=0;i<monitor_info_count;i++)
		{
			pMonitorNum[i]->DestroyWindow();
			delete pMonitorNum[i];
		}
		delete [] pMonitorNum;
		ShowWindow(SW_SHOW);
	}
	CDialog::OnTimer(nIDEvent);
}

//モニター情報を更新
void CNECTestPatternDlg::OnButtonMonitorUpdate() 
{
	m_DisplayList.SetRedraw(FALSE);
	BOOL OldSeted_t=OldSeted;
	SaveSeted();
	m_DisplayList.DeleteAllItems();
	SetDisplayList();
	OldSeted=OldSeted_t;
	m_DisplayList.SetRedraw();
	
}

//英語に切り替え
void CNECTestPatternDlg::OnMenuitemLanguageEn() 
{
	if(soft_Lang != LANG_ENGLISH)
	{
		soft_Lang=LANG_ENGLISH;
		SetThreadLocale(soft_Lang);
		CDialog::OnCancel();
	}
}

//日本語に切り替え
void CNECTestPatternDlg::OnMenuitemLanguageJp() 
{
	if(soft_Lang != LANG_JAPANESE)
	{
		soft_Lang=LANG_JAPANESE;
		SetThreadLocale(soft_Lang);
		CDialog::OnCancel();
	}
}

//メニューを初期化
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
	
	//言語メニューの該当言語にチェックを表示
	switch(soft_Lang)
	{
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

int Ctrl_vi=0;
BOOL CNECTestPatternDlg::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message==WM_MOUSEMOVE){
		CRect list_rect;
		if(GetDlgItem(IDC_LIST_DISPLAY)!=NULL){
			GetDlgItem(IDC_LIST_DISPLAY)->GetWindowRect(&list_rect);
			CPoint MousePoint;
			GetCursorPos(&MousePoint);
			if(list_rect.PtInRect(MousePoint))
			{
				if(Ctrl_vi!=1)
				{
					Ctrl_vi=1;
					::keybd_event(VK_CONTROL,0,0,0);
				}
			}
			else
			{
				if(Ctrl_vi!=0)
				{
					Ctrl_vi=0;
					::keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
				}
			}
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CNECTestPatternDlg::OnDeskproperty() 
{
	CallDeskProperty();
}
