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

int NECAfxMessageBox(LPCTSTR lpszText,						//���b�Z�[�W���e�i�����j
							BOOL * Checked=NULL,					//�`�F�b�N�{�b�N�X�̖߂����
							CWnd * pDlg=NULL ,					//�e�_�C�A���O
							CRect * pmoni_rect=NULL ,			//�\������郂�j�^�[�ʒu
							UINT nType = MB_OK,					//���b�Z�[�W���f��
							UINT nIDHelp = 0);					//���b�Z�[�W�w���vID

int NECAfxMessageBox(UINT nIDPrompt,						//���b�Z�[�W���e�i����ID�j
							BOOL * Checked=NULL,					//�`�F�b�N�{�b�N�X�̖߂����
							CWnd * pDlg=NULL ,					//�e�_�C�A���O
							CRect * pmoni_rect=NULL ,			//�\������郂�j�^�[�ʒu
							UINT nType = MB_OK,					//���b�Z�[�W���f��
							UINT nIDHelp = (UINT)-1);			//���b�Z�[�W�w���vID

#include "NECTestPattern_LIB.h"

#include <Gdiplus.h>
#pragma comment( lib, "gdiplus.lib" ) 
using namespace Gdiplus;
#define ULONG_PTR unsigned long
extern ULONG_PTR gdiplusToken;


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_STDAFX_H__8596FD00_CB8A_4E81_B54F_34F934DDE677__INCLUDED_)
