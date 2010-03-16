#if !defined(AFX_SETTESTPATTERNDLG_H__E481D64F_8884_47B5_B08E_2701A67616B1__INCLUDED_)
#define AFX_SETTESTPATTERNDLG_H__E481D64F_8884_47B5_B08E_2701A67616B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetTestPatternDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CSetTestPatternDlg ダイアログ
#include "NECTestPatternDlg.h"

class CSetTestPatternDlg : public CNECTestPatternDlg
{
// コンストラクション
public:

	//設定してるモニタが閃く
	friend UINT th(LPVOID p);

	CSetTestPatternDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ

	//各モニター表示の標準画像表示処理
	virtual void OnButtonDisplay(int PatternBmpID);

	//各モニター表示の作成画像表示処理関数
	virtual void OnButtonCalcDisplay();

	//モニター番号
	int add;

	//次の画面
	CDialog * pNextWnd;

	//テスト画面
	CTestPatternDlg * TestDlg_one;

	//設定するときにモニター情報を表示画面
	CSettingMsgDlg * SetTextDlg;

	//モニターひらめく画面
	CSettingRemindDlg * SetRemindDlg;

// ダイアログ データ
	//{{AFX_DATA(CSetTestPatternDlg)
	enum { IDD = IDD_SETTESTPATTERN };
//	CButtonST	m_Button_Pattern1;
//	CString	m_FileName;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSetTestPatternDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CSetTestPatternDlg)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonFiledisplay();
	afx_msg void OnDonot();
	afx_msg void OnBack();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SETTESTPATTERNDLG_H__E481D64F_8884_47B5_B08E_2701A67616B1__INCLUDED_)
