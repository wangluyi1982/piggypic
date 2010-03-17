// NECTestPatternDlg.h : ヘッダー ファイル
//

#if !defined(AFX_NECTESTPATTERNDLG_H__BA051C0C_11B8_4E5A_8EE2_34F598AB9BED__INCLUDED_)
#define AFX_NECTESTPATTERNDLG_H__BA051C0C_11B8_4E5A_8EE2_34F598AB9BED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternDlg ダイアログ
HBITMAP & CreateCalcBitmap_Colors1(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors2(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors3(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);

class CNECTestPatternDlg : public CDialog
{
// 構築
public:
	CNECTestPatternDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ
	CNECTestPatternDlg(UINT nIDTemplate, CWnd* pParent = NULL);	// 標準のコンストラクタ
	BOOL ShowWindow(int nCmdShow){
		if(nCmdShow==SW_HIDE){
			MainWndsta=FALSE;
			win_show_sta=FALSE;
			GetWindowRect(&MainDlgRect);
		}else{
			MainWndsta=TRUE;
			win_show_sta=true;
		}
		return CWnd::ShowWindow(nCmdShow);
	}
	void SetDisplayList();
	void OnCancel();
	void OnOK();
	void SelectFile();
	int ReSetMonitorInfo();
	void SetEnableWindow();
	void ShowEnuRadio();
	void ShowEnuRadio_Color();
	void EnableEnuRadio_Color();
	void InitClass();
	void InitDlg();
	void SetDlgPos(CWnd * pDlg=NULL);
	void SaveSeted();
	virtual void OnButtonDisplay(int PatternBmpID);
	virtual void OnButtonCalcDisplay();
	HBITMAP & (*CreateCalcBitmap_Colors)(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
	HBITMAP & (*CreateCalcBitmap_Colors_Ci)(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);

	HBITMAP hBitmap;
	EnumMonitors theEnumMonitors;
	monitor_info_TestPattern * monitor_info_Testadd;
	int monitor_info_count;
	int CheckedRadioID;
	char * monitorselect_tab;
	char * selectfilename;
	bool Enu_show;
	bool Enable_Enu;
	bool Enable_Color;
	bool monitorCheckAll;
	bool win_show_sta;
	int SelectColor_show;
	int CalcPat;
	COLORREF SelectedColor;
	CNECTestPatternDlg * OldSetDlg;
	CFileDialog * pfiledlg;

// ダイアログ データ
	//{{AFX_DATA(CNECTestPatternDlg)
	enum { IDD = IDD_NECTESTPATTERN_DIALOG };
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_NECTESTPATTERNDLG_H__BA051C0C_11B8_4E5A_8EE2_34F598AB9BED__INCLUDED_)
