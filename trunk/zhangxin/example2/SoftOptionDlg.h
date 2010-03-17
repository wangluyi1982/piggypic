#if !defined(AFX_SOFTOPTIONDLG_H__FFB3E67B_A02C_49B3_B215_1D0138B8B49B__INCLUDED_)
#define AFX_SOFTOPTIONDLG_H__FFB3E67B_A02C_49B3_B215_1D0138B8B49B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SoftOptionDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CSoftOptionDlg ダイアログ

class CSoftOptionDlg : public CDialog
{
// コンストラクション
public:
	CSoftOptionDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ
	CSoftOptionDlg(BOOL * inCheck1,BOOL * inCheck2,BOOL * inCheck3,BOOL * inCheck4,CWnd* pParent =NULL);
// ダイアログ データ
	//{{AFX_DATA(CSoftOptionDlg)
	enum { IDD = IDD_SOFT_OPTION };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA

	BOOL * Check1;
	BOOL * Check2;
	BOOL * Check3;
	BOOL * Check4;

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSoftOptionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CSoftOptionDlg)
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheck4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SOFTOPTIONDLG_H__FFB3E67B_A02C_49B3_B215_1D0138B8B49B__INCLUDED_)
