// NECTestPatternDlg.h : ヘッダー ファイル
//

#if !defined(AFX_NECTESTPATTERNDLG_H__BA051C0C_11B8_4E5A_8EE2_34F598AB9BED__INCLUDED_)
#define AFX_NECTESTPATTERNDLG_H__BA051C0C_11B8_4E5A_8EE2_34F598AB9BED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternDlg ダイアログ

//作成画像の計算関数
HBITMAP & CreateCalcBitmap_Colors1(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors2(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors3(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);

#include "SettingRemindDlg.h"
extern int Ctrl_vi;

class CNECTestPatternDlg : public CDialog
{
// 構築
public:
	CNECTestPatternDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ
	CNECTestPatternDlg(UINT nIDTemplate, CWnd* pParent = NULL);	// 標準のコンストラクタ

	//ダイアログ表示状態を切り替えて、表示状態を保存
	BOOL ShowWindow(int nCmdShow)
	{
		if(nCmdShow==SW_HIDE)
		{
			MainWndsta=FALSE;
			win_show_sta=FALSE;
			GetWindowRect(&MainDlgRect);
		}
		else
		{
			MainWndsta=TRUE;
			win_show_sta=true;
		}

		if(Ctrl_vi==1)
		{
			Ctrl_vi=-1;
			::keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
		}
		else
		{
			if(Ctrl_vi==-1)
			{
				Ctrl_vi=1;
				::keybd_event(VK_CONTROL,0,0,0);
			}
		}
		return CWnd::ShowWindow(nCmdShow);
	}

	//モニターリストを設定
	void SetDisplayList();
	
	//モニターリストの順調を計算
	int ReSetMonitorInfo();

	//「Esc」と「Enter」ボタンを無効
	void OnCancel();
	void OnOK();
	
	//テストパターンファイルを選択処理
	void SelectFile();

	//画面ボックスの状態を設定
	void SetEnableWindow();
	void EnableEnuRadio_Color();

	//表示されるラジオボックスを設定
	void ShowEnuRadio();
	void ShowEnuRadio_Color();

	//初期化クラス
	void InitClass();

	//初期化ダイアログ
	void InitDlg();

	//ダイアログの位置を設定
	void SetDlgPos(CWnd * pDlg=NULL);

	//ユーザ設定を保存
	void SaveSeted();

	//ユーザ選択テストパターンファイルを表示
	virtual void OnButtonDisplay(int PatternBmpID);

	//作成画像を表示
	virtual void OnButtonCalcDisplay();

	//作成画像の作り方
	HBITMAP & (*CreateCalcBitmap_Colors)(COLORREF * colors,
		CRect monitor_Rect,HBITMAP & hBmp);
	HBITMAP & (*CreateCalcBitmap_Colors_Ci)(COLORREF * colors,
		CRect monitor_Rect,HBITMAP & hBmp);

	HBITMAP hBitmap;
	//モニター情報
	EnumMonitors theEnumMonitors;
	monitor_info_TestPattern * monitor_info_Testadd;
	//有効モニターの台数
	int monitor_info_count;
	
	//ダイアログのボックス状態
	bool Enu_show;
	bool Enable_Enu;
	bool Enable_Color;
	bool monitorCheckAll;
	int SelectColor_show;
	
	//ダイアログの表示状態
	bool win_show_sta;

	//作成画像の種類
	int CalcPat;

	//補充色
	COLORREF SelectedColor;
	
	int CheckedRadioID;
	char * monitorselect_tab;
	char * selectfilename;

	CNECTestPatternDlg * OldSetDlg;
	CFileDialog * pfiledlg;
	CSettingRemindDlg ** pMonitorNum;

// ダイアログ データ
	//{{AFX_DATA(CNECTestPatternDlg)
	enum { IDD = IDD_NECTESTPATTERN_DIALOG };
	CButtonST	m_Button_Pattern3;
	CButtonST	m_Button_Pattern2;
	CButtonST	m_Button_Pattern_Calc3;
	CButtonST	m_Button_Pattern_Calc2;
	CButtonST	m_Button_Pattern_Calc1;
	CButtonST	m_Button_Pattern1;
	CListCtrl	m_DisplayList;
	CString	m_FileName;
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CNECTestPatternDlg)
	public:
	virtual BOOL DestroyWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CNECTestPatternDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonFile();
	afx_msg void OnKillfocusEditFilename();
	afx_msg void OnExitdlg();
	afx_msg void OnButtonFiledisplay();
	afx_msg void OnButtonPattern1();
	afx_msg void OnRADIOFirstCen();
	afx_msg void OnRADIOFirstExt();
	afx_msg void OnRADIOFirstEnu();
	afx_msg void OnRADIOExtPack();
	afx_msg void OnRADIOExtWidth();
	afx_msg void OnRADIOExtHeight();
	afx_msg void OnRadioOne();
	afx_msg void OnCheckAll();
	afx_msg void OnButtonPattern2();
	afx_msg void OnButtonPattern3();
	afx_msg void OnButtonPatternCalc1();
	afx_msg void OnButtonPatternCalc2();
	afx_msg void OnButtonPatternCalc3();
	afx_msg void OnButtonSelectColor();
	afx_msg void OnRadioColorSelect();
	afx_msg void OnRadioColorFile();
	afx_msg void OnMenuitemExit();
	afx_msg void OnAppAbout();
	afx_msg void OnClickListDisplay(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuitemOption();
	afx_msg void OnMenuitemLanguageEn();
	afx_msg void OnMenuitemLanguageJp();
	afx_msg void OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex,BOOL bSysMenu);
	afx_msg void OnButtonMonitornumber();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonMonitorUpdate();
	afx_msg void OnDeskproperty();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_NECTESTPATTERNDLG_H__BA051C0C_11B8_4E5A_8EE2_34F598AB9BED__INCLUDED_)
