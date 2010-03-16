#if !defined(AFX_SETTINGMSGDLG_H__6D3FDDA1_BE05_4B43_9746_DC790035F29F__INCLUDED_)
#define AFX_SETTINGMSGDLG_H__6D3FDDA1_BE05_4B43_9746_DC790035F29F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingMsgDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CSettingMsgDlg ダイアログ

class CSettingMsgDlg : public CDialog
{
// コンストラクション
public:
	CSettingMsgDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ

	//「Esc」と「Enter」ボタンを無効
	void OnCancel();
	void OnOK();

// ダイアログ データ
	//{{AFX_DATA(CSettingMsgDlg)
	enum { IDD = IDD_SETTING_MSG_DIALOG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSettingMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CSettingMsgDlg)
		// メモ: ClassWizard はこの位置にメンバ関数を追加します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SETTINGMSGDLG_H__6D3FDDA1_BE05_4B43_9746_DC790035F29F__INCLUDED_)
