#if !defined(AFX_MESSAGEDLG_H__CF696752_1674_4B1E_B527_82802A3D6940__INCLUDED_)
#define AFX_MESSAGEDLG_H__CF696752_1674_4B1E_B527_82802A3D6940__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MessageDlg.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CMessageDlg ダイアログ

class CMessageDlg : public CDialog
{
// コンストラクション
public:
	CMessageDlg(CWnd* pParent = NULL);   

	CMessageDlg(CString in_str,				//メッセージ内容（文字）
		int in_nType=MB_OK,						//メッセージモデル
		CWnd* pParent = NULL);  				//親ダイアログ

	CMessageDlg(CString in_str,				//メッセージ内容（文字）
		int in_nType=MB_OK,						//メッセージモデル
		BOOL * in_Checked=NULL,					//チェックボックスの戻り引数
		CWnd * in_pDlg=NULL ,  					//親ダイアログ
		CRect * in_pmoni_rect=NULL ,			//表示されるモニター位置
		CWnd* pParent = NULL);  				//親ダイアログ

	CMessageDlg(UINT in_strID,					//メッセージ内容（文字ID）
		int in_nType=MB_OK,						//メッセージモデル
		BOOL * in_Checked=NULL,					//チェックボックスの戻り引数
		CWnd * in_pDlg=NULL ,  					//親ダイアログ
		CRect * in_pmoni_rect=NULL ,			//表示されるモニター位置
		CWnd* pParent = NULL);  				//親ダイアログ

	int nType;
	BOOL * Checked;
	CWnd * pDlg;
	CRect * pmoni_rect;

// ダイアログ データ
	//{{AFX_DATA(CMessageDlg)
	enum { IDD = IDD_MESSAGE_DIALOG };
	CString	m_String;
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CMessageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CMessageDlg)
	virtual void OnOK();
	afx_msg void OnYes();
	afx_msg void OnNo();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_MESSAGEDLG_H__CF696752_1674_4B1E_B527_82802A3D6940__INCLUDED_)
