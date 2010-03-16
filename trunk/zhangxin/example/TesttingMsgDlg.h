#if !defined(AFX_TESTTINGMSGDLG_H__00CF9673_C391_4B6E_A4A0_14DE4813D9D0__INCLUDED_)
#define AFX_TESTTINGMSGDLG_H__00CF9673_C391_4B6E_A4A0_14DE4813D9D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TesttingMsgDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CTesttingMsgDlg ダイアログ

#define 	MaxState 6

class CTesttingMsgDlg : public CDialog
{
// コンストラクション
public:
	CTesttingMsgDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ
	CTesttingMsgDlg(CRect inpRect,
		CWnd* pParent =NULL);
	void EndbleTime();

	//画面表示位置を設定
	void SetDlgPos(CWnd * pDlg=NULL);
	
// ダイアログ データ
	//{{AFX_DATA(CTesttingMsgDlg)
	enum { IDD = IDD_TESTTINGMESSAGE_DIALOG };
	int	m_Timer;
	CString	m_String;
	//}}AFX_DATA
	
	//表示メッセージの番号
	int TestMsgState;

	//自動移動変数
	bool AutoJumpState;

	//残り時間
	int time_min;

	//モニター位置
	CRect monitorRect;

	int setfout;

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CTesttingMsgDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CTesttingMsgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonBack();
	afx_msg void OnRadioM();
	afx_msg void OnRadioA();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChangeEditTime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_TESTTINGMSGDLG_H__00CF9673_C391_4B6E_A4A0_14DE4813D9D0__INCLUDED_)
