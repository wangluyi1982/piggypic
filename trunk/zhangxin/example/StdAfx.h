// stdafx.h : 標準のシステム インクルード ファイル、
//            または参照回数が多く、かつあまり変更されない
//            プロジェクト専用のインクルード ファイルを記述します。
//

#if !defined(AFX_STDAFX_H__8596FD00_CB8A_4E81_B54F_34F934DDE677__INCLUDED_)
#define AFX_STDAFX_H__8596FD00_CB8A_4E81_B54F_34F934DDE677__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Windows ヘッダーから殆ど使用されないスタッフを除外します。

#include <afxwin.h>         // MFC のコアおよび標準コンポーネント
#include <afxext.h>         // MFC の拡張部分
#include <afxdisp.h>        // MFC のオートメーション クラス
#include <afxdtctl.h>		// MFC の Internet Explorer 4 コモン コントロール サポート
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC の Windows コモン コントロール サポート
#endif // _AFX_NO_AFXCMN_SUPPORT

// extern HHOOK glhHook_ListCtrl_Mouse; 
// extern HHOOK glhHook_DisplayChange; 

// LRESULT   WINAPI   ListCtrl_MouseProc(int   nCode,WPARAM   wParam,LPARAM   lParam);
// LRESULT   WINAPI   NECTestPattern_DisplayChange(int   nCode,WPARAM   wParam,LPARAM   lParam);
#include "mylib.h"

#include "resource.h"
#include "EnumMonitors.h"
#include "monitor_info_TestPattern.h"
#include "BtnST.h"
#include "NECTestPatternDLG.h"
#include "TestPatternDlg.h"
#include "SettingMsgDlg.h"
#include "SettingRemindDlg.h"
#include "SetTestPatternDlg.h"
#include "NTPNewFileDialog.h"
#include "RemindDlg.h"
#include "CalcDlg.h"
#include "MessageDlg.h"
#include "TesttingMsgDlg.h"
#include "SoftOptionDlg.h"

int NECAfxMessageBox(LPCTSTR lpszText,						//メッセージ内容（文字）
							BOOL * Checked=NULL,					//チェックボックスの戻り引数
							CWnd * pDlg=NULL ,					//親ダイアログ
							CRect * pmoni_rect=NULL ,			//表示されるモニター位置
							UINT nType = MB_OK,					//メッセージモデル
							UINT nIDHelp = 0);					//メッセージヘルプID

int NECAfxMessageBox(UINT nIDPrompt,						//メッセージ内容（文字ID）
							BOOL * Checked=NULL,					//チェックボックスの戻り引数
							CWnd * pDlg=NULL ,					//親ダイアログ
							CRect * pmoni_rect=NULL ,			//表示されるモニター位置
							UINT nType = MB_OK,					//メッセージモデル
							UINT nIDHelp = (UINT)-1);			//メッセージヘルプID

#include "NECTestPattern_LIB.h"

#include <Gdiplus.h>
#pragma comment( lib, "gdiplus.lib" ) 
using namespace Gdiplus;
#define ULONG_PTR unsigned long
extern ULONG_PTR gdiplusToken;


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_STDAFX_H__8596FD00_CB8A_4E81_B54F_34F934DDE677__INCLUDED_)
