#if !defined(AFX_CALCDLG_H__41D7E0B6_B1B3_4514_9803_A26DFC27299F__INCLUDED_)
#define AFX_CALCDLG_H__41D7E0B6_B1B3_4514_9803_A26DFC27299F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CalcDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg ダイアログ

class CCalcDlg : public CDialog
{
// コンストラクション
public:
	CCalcDlg(UINT in = 0,CWnd* pParent = NULL);   // 標準のコンストラクタ
	UINT Dlgcase;
	int CheckID;
// ダイアログ データ
	//{{AFX_DATA(CCalcDlg)
	enum { IDD = IDD_CALC_DIALOG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CCalcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CCalcDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CALCDLG_H__41D7E0B6_B1B3_4514_9803_A26DFC27299F__INCLUDED_)
