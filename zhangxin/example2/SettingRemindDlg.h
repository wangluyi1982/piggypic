#if !defined(AFX_SETTINGREMINDDLG_H__CA1AA36E_F9C7_4378_98F7_90A0B48B6499__INCLUDED_)
#define AFX_SETTINGREMINDDLG_H__CA1AA36E_F9C7_4378_98F7_90A0B48B6499__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingRemindDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CSettingRemindDlg ダイアログ

class CSettingRemindDlg : public CDialog
{
// コンストラクション
public:
	CSettingRemindDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ
	void OnCancel();
	void OnOK();

// ダイアログ データ
	//{{AFX_DATA(CSettingRemindDlg)
	enum { IDD = IDD_SETTING_REMIND_DIALOG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CSettingRemindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CSettingRemindDlg)
		// メモ: ClassWizard はこの位置にメンバ関数を追加します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_SETTINGREMINDDLG_H__CA1AA36E_F9C7_4378_98F7_90A0B48B6499__INCLUDED_)
