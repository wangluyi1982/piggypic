// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���A
//            �܂��͎Q�Ɖ񐔂������A�����܂�ύX����Ȃ�
//            �v���W�F�N�g��p�̃C���N���[�h �t�@�C�����L�q���܂��B
//

#if !defined(AFX_STDAFX_H__8596FD00_CB8A_4E81_B54F_34F934DDE677__INCLUDED_)
#define AFX_STDAFX_H__8596FD00_CB8A_4E81_B54F_34F934DDE677__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Windows �w�b�_�[����w�ǎg�p����Ȃ��X�^�b�t�����O���܂��B

#include <afxwin.h>         // MFC �̃R�A����ѕW���R���|�[�l���g
#include <afxext.h>         // MFC �̊g������
#include <afxdisp.h>        // MFC �̃I�[�g���[�V���� �N���X
#include <afxdtctl.h>		// MFC �� Internet Explorer 4 �R���� �R���g���[�� �T�|�[�g
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC �� Windows �R���� �R���g���[�� �T�|�[�g
#endif // _AFX_NO_AFXCMN_SUPPORT

extern BOOL OldSeted;
extern BOOL ExitMessageNoShow;
extern BOOL TesttingMsg;
extern BOOL TesttingMsg_ALL;

extern BOOL MainWndsta;
extern BOOL CalcPattern;
extern int FristRun;
extern int soft_Lang;

extern CRect MainDlgRect;
extern HHOOK glhHook_ListCtrl_Mouse; 
LRESULT   WINAPI   ListCtrl_MouseProc(int   nCode,WPARAM   wParam,LPARAM   lParam);


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

int NECAfxMessageBox(LPCTSTR lpszText, BOOL * Checked=NULL, CWnd * pDlg=NULL , CRect * pmoni_rect=NULL , UINT nType = MB_OK,
				UINT nIDHelp = 0);
int NECAfxMessageBox(UINT nIDPrompt, BOOL * Checked=NULL, CWnd * pDlg=NULL , CRect * pmoni_rect=NULL , UINT nType = MB_OK,
				UINT nIDHelp = (UINT)-1);

#include "NECTestPattern_LIB.h"
#pragma comment( lib, "NECTestPattern_LIB.lib" ) 

#include <Gdiplus.h>
#pragma comment( lib, "gdiplus.lib" ) 
using namespace Gdiplus;
#define ULONG_PTR unsigned long
extern ULONG_PTR gdiplusToken;


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_STDAFX_H__8596FD00_CB8A_4E81_B54F_34F934DDE677__INCLUDED_)
