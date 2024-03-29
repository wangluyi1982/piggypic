// NECTestPattern.h : NECTESTPATTERN アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_NECTESTPATTERN_H__5CE87CA7_3789_4577_B8BB_045D1BEC706B__INCLUDED_)
#define AFX_NECTESTPATTERN_H__5CE87CA7_3789_4577_B8BB_045D1BEC706B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternApp:
// このクラスの動作の定義に関しては NECTestPattern.cpp ファイルを参照してください。
//

class CNECTestPatternApp : public CWinApp
{
public:
	CNECTestPatternApp();
	void SetDialogBkColor(
		COLORREF clrCtlBk = RGB(236, 233, 216),
		COLORREF  clrCtlText= RGB(0, 0, 0))
	{
		CWinApp::SetDialogBkColor(clrCtlBk,clrCtlText);
	}
// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CNECTestPatternApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CNECTestPatternApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_NECTESTPATTERN_H__5CE87CA7_3789_4577_B8BB_045D1BEC706B__INCLUDED_)
