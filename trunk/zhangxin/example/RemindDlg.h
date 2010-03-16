#if !defined(AFX_REMINDDLG_H__3AB12ABF_7322_4883_97C4_BC019DABFFDA__INCLUDED_)
#define AFX_REMINDDLG_H__3AB12ABF_7322_4883_97C4_BC019DABFFDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RemindDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CRemindDlg ダイアログ

class CRemindDlg : public CDialog
{
// コンストラクション
public:
	bool showing;
	CRemindDlg(CWnd* pParent = NULL);   // 標準のコンストラクタ
	BOOL ShowWindow(int nCmdShow)
	{
		if(nCmdShow==SW_HIDE)
		{
			showing=FALSE;
			GetWindowRect(&MainDlgRect);
		}
		else
		{
			showing=true;
		}
		return CWnd::ShowWindow(nCmdShow);
	}
// ダイアログ データ
	//{{AFX_DATA(CRemindDlg)
	enum { IDD = IDD_REMIND_DIALOG };
	BOOL	m_Check;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CRemindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CRemindDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_REMINDDLG_H__3AB12ABF_7322_4883_97C4_BC019DABFFDA__INCLUDED_)
