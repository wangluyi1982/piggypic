// NECTestPattern.h : NECTESTPATTERN �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_NECTESTPATTERN_H__5CE87CA7_3789_4577_B8BB_045D1BEC706B__INCLUDED_)
#define AFX_NECTESTPATTERN_H__5CE87CA7_3789_4577_B8BB_045D1BEC706B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� NECTestPattern.cpp �t�@�C�����Q�Ƃ��Ă��������B
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
// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CNECTestPatternApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CNECTestPatternApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_NECTESTPATTERN_H__5CE87CA7_3789_4577_B8BB_045D1BEC706B__INCLUDED_)
