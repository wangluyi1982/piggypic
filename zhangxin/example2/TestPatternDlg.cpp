// TestPatternDlg.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "TestPatternDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestPatternDlg ダイアログ
extern CNECTestPatternApp theApp;

CTestPatternDlg::CTestPatternDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestPatternDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestPatternDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
	pNextWnd=NULL;
	filename=NULL;
	hBitmap=0;
	CenShow=true;
	pParentWnd=pParent;
	add=0;
	Enu_Hor_pos=Enu_Ver_pos=Ext=Color_pos=-1;
}


void CTestPatternDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestPatternDlg)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestPatternDlg, CDialog)
	//{{AFX_MSG_MAP(CTestPatternDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestPatternDlg メッセージ ハンドラ

BOOL CTestPatternDlg::Create(UINT nID,CWnd* pParent) 
{
	pParentWnd=pParent;
	
	return CDialog::Create(IDD, pParentWnd);
}

BOOL CTestPatternDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();


	((CStatic *)GetDlgItem(IDC_STATIC_BMPBK1))->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);// |SS_REALSIZEIMAGE  
//	((CStatic *)GetDlgItem(IDC_STATIC_BMPBK2))->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);// |SS_REALSIZEIMAGE  
//	((CStatic *)GetDlgItem(IDC_STATIC_BMPBK3))->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);// |SS_REALSIZEIMAGE  
//	((CStatic *)GetDlgItem(IDC_STATIC_BMPBK4))->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);// |SS_REALSIZEIMAGE  
	((CStatic *)GetDlgItem(IDC_STATIC_BMPBK1))->ShowWindow(SW_HIDE);
//	((CStatic *)GetDlgItem(IDC_STATIC_BMPBK2))->ShowWindow(SW_HIDE);
//	((CStatic *)GetDlgItem(IDC_STATIC_BMPBK3))->ShowWindow(SW_HIDE);
//	((CStatic *)GetDlgItem(IDC_STATIC_BMPBK4))->ShowWindow(SW_HIDE);
	
	if(hBitmap==0)
		setprosize(this,rect,IDC_STATIC_PATTERN,filename,ReSize,CenShow);
	else{
		setprosize(this,rect,IDC_STATIC_PATTERN,hBitmap,ReSize,CenShow);
	}
	if(CenShow==false){
		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK1))->ShowWindow(SW_SHOW);
//		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK2))->ShowWindow(SW_SHOW);
//		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK3))->ShowWindow(SW_SHOW);
//		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK4))->ShowWindow(SW_SHOW);
		BITMAP bmp;
		::GetObject(hBitmap,sizeof(bmp),&bmp);
		
		CBitmap *pCBmp=CBitmap::FromHandle(hBitmap);
		CDC memDC;
		memDC.CreateCompatibleDC(GetDC());
		CBitmap *pOldMemBmp=NULL;
		pOldMemBmp=memDC.SelectObject(pCBmp);

		DWORD Color_x,Color_y;
		switch(Color_pos){
			default:
			case 0:
				Color_x=0,Color_y=0;
				break;
			case 1:
				Color_x=0,Color_y=bmp.bmHeight-1;
				break;
			case 2:
				Color_x=(bmp.bmWidth-1)/2,Color_y=(bmp.bmHeight-1)/2;
				break;
			case 3:
				Color_x=bmp.bmWidth-1,Color_y=0;
				break;
			case 4:
				Color_x=bmp.bmWidth-1,Color_y=bmp.bmHeight-1;
				break;
		}
		COLORREF color=Color_pos==-1?SelectedCol:memDC.GetPixel(Color_x, Color_y);
		memDC.SelectObject(pOldMemBmp);
		HBITMAP hbmp;
		hbmp=CreateNewHBitmap_BK(color,hbmp);

		CRect rect_bmp;
		if(ReSize){
			int temp;
			switch(Ext){
				case 0:
					rect_bmp.left=0;
					rect_bmp.right=rect.Width();
					temp=rect_bmp.right*bmp.bmHeight/bmp.bmWidth;
					rect_bmp.top=(int)(rect.Height()-temp)/2;
					rect_bmp.bottom=rect_bmp.top+temp;
					break;
				case 1:
					rect_bmp.top=0;
					rect_bmp.bottom=rect.Height();

					temp=rect_bmp.bottom*bmp.bmWidth/bmp.bmHeight;
					rect_bmp.left=(int)(rect.Width()-temp)/2;
					rect_bmp.right=rect_bmp.left+temp;
					break;
				default:
				case 2:
					rect_bmp=CRect(0,0,rect.Width(),rect.Height());
					break;
			}
		}else{
			switch(Enu_Hor_pos){
				case 0:
				default:
					rect_bmp.left=0;
					rect_bmp.right=bmp.bmWidth;
					break;
				case 1:
					rect_bmp.left=(rect.Width()-bmp.bmWidth)/2;
					rect_bmp.right=rect_bmp.left+bmp.bmWidth;
					break;
				case 2:
					rect_bmp.right=rect.Width();
					rect_bmp.left=rect_bmp.right-bmp.bmWidth;
					break;
			}
			switch(Enu_Ver_pos){
				case 0:
				default:
					rect_bmp.top=0;
					rect_bmp.bottom=bmp.bmHeight;
					break;
				case 1:
					rect_bmp.top=(rect.Height()-bmp.bmHeight)/2;
					rect_bmp.bottom=rect_bmp.top+bmp.bmHeight;
					break;
				case 2:
					rect_bmp.bottom=rect.Height();
					rect_bmp.top=rect_bmp.bottom-bmp.bmHeight;
					break;
			}
		}

		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK1))->SetBitmap(hbmp);
//		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK2))->SetBitmap(hbmp);
//		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK3))->SetBitmap(hbmp);
//		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK4))->SetBitmap(hbmp);
		::SetWindowPos(((CStatic *)GetDlgItem(IDC_STATIC_BMPBK1))->m_hWnd,HWND_BOTTOM,0,0,rect.Width(),rect.Height(),SWP_SHOWWINDOW);
//		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK1))->SetWindowPos(CRect(0,0,rect.Width(),rect.Height()));
		((CStatic *)GetDlgItem(IDC_STATIC_PATTERN))->MoveWindow(rect_bmp);
//		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK2))->MoveWindow(CRect(0,rect_bmp.bottom,rect.Width(),rect.Height()));
//		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK3))->MoveWindow(CRect(0,0,rect_bmp.left,rect.Height()));
//		((CStatic *)GetDlgItem(IDC_STATIC_BMPBK4))->MoveWindow(CRect(0,0,rect.Width(),rect_bmp.top));
		RedrawWindow();
//		((CStatic *)GetDlgItem(IDC_STATIC_PATTERN))->RedrawWindow();
	}

//	::SetWindowPos(*pParentWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);
	if(pNextWnd!=NULL){
		int dlg_ok=pNextWnd->DoModal();
		if(pNextWnd==NULL)return TRUE;
		if(dlg_ok==IDOK)
			CDialog::OnOK();
		else
			CDialog::OnCancel();
	}else{
		if(TestSetDlg!=NULL){
			int YesNo=NECAfxMessageBox(IDS_MSG_SETEND,
				NULL,theApp.GetMainWnd(),
				&(( (CNECTestPatternDlg *)theApp.GetMainWnd() )->monitor_info_Testadd[0].DesktopOfMonitor ),
				MB_YESNO|MB_ICONQUESTION );
			if(YesNo==IDNO){
				CDialog::OnCancel();
				return true;
			}
		} 
		/*---*/
//		NECAfxMessageBox(IDS_MSG_EXIT,NULL,theApp.GetMainWnd(),
//			&(((CNECTestPatternDlg *)theApp.GetMainWnd())->monitor_info_Testadd[0].DesktopOfMonitor ),
//			MB_ICONASTERISK);
		if(!ExitMessageNoShow){
//			CMessageDlg msgDlg(IDS_MSG_EXIT,MB_ICONASTERISK,NULL,theApp.GetMainWnd(),
			CMessageDlg msgDlg(IDS_MSG_EXIT,MB_ICONASTERISK,&ExitMessageNoShow,theApp.GetMainWnd(),
				&(((CNECTestPatternDlg *)theApp.GetMainWnd())->monitor_info_Testadd[0].DesktopOfMonitor )
				);
			msgDlg.DoModal();
		}
		if(TesttingMsg&&CalcPattern||TesttingMsg_ALL){
			CTesttingMsgDlg Dlg((((CNECTestPatternDlg *)theApp.GetMainWnd())->monitor_info_Testadd[0].DesktopOfMonitor )
				);
			Dlg.DoModal();
		}
	}

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CTestPatternDlg::SetDlgRect(CRect rect_in){
	rect=rect_in;
}

void CTestPatternDlg::SetDlgRect(XYandWH xywh_in){
	rect=(CRect)xywh_in;
}

void CTestPatternDlg::OnOK(){
	CDialog::OnOK();
	return;
}

void CTestPatternDlg::OnCancel(){
	CDialog::OnOK();
	return;
}

void CTestPatternDlg::OnNewCancel(){
	CDialog::OnCancel();
	return;
}

BOOL CTestPatternDlg::DestroyWindow() 
{
	return CDialog::DestroyWindow();
}
