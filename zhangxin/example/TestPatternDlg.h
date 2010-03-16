#if !defined(AFX_TESTPATTERNDLG_H__445C3A09_50C5_435C_9269_2387DDF2339C__INCLUDED_)
#define AFX_TESTPATTERNDLG_H__445C3A09_50C5_435C_9269_2387DDF2339C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestPatternDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CTestPatternDlg ダイアログ
class XYandWH;
class CTestPatternDlg : public CDialog
{
// コンストラクション
public:
	CTestPatternDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ
	void SetDlgRect(CRect rect_in);
	void SetDlgRect(XYandWH xywh_in);

	//「Esc」と「Enter」ボタンを無効
	void OnOK();
	void OnCancel();

	//実際のCancel
	void OnNewCancel();

	//表示ファイル名前
	char * filename;

	//ビットマップのハンド
	HBITMAP hBitmap;

	//親画面
	CWnd* pParentWnd;

	//次の画面
	CDialog* pNextWnd;

	//モニター位置
	CRect rect;

	//モニター番号
	int add;

	//画面表示方式設定
	bool CenShow;
	bool ReSize;
	int Enu_Hor_pos;
	int Enu_Ver_pos;
	int Ext;

	//補充色の変数
	int Color_pos;
	COLORREF SelectedCol;

// ダイアログ データ
	//{{AFX_DATA(CTestPatternDlg)
	enum { IDD = IDD_TEST_PATTERN };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CTestPatternDlg)
	public:
	virtual BOOL Create(UINT nID,CWnd* pParent);
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CTestPatternDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_TESTPATTERNDLG_H__445C3A09_50C5_435C_9269_2387DDF2339C__INCLUDED_)
