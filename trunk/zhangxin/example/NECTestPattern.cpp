// NECTestPattern.cpp : �A�v���P�[�V�����p�N���X�̒�`���s���܂��B
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "NECTestPatternDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternApp

BEGIN_MESSAGE_MAP(CNECTestPatternApp, CWinApp)
	//{{AFX_MSG_MAP(CNECTestPatternApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternApp �N���X�̍\�z

CNECTestPatternApp::CNECTestPatternApp()
{
	// TODO: ���̈ʒu�ɍ\�z�p�̃R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}

/////////////////////////////////////////////////////////////////////////////
// �B��� CNECTestPatternApp �I�u�W�F�N�g

CNECTestPatternApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternApp �N���X�̏�����

BOOL CNECTestPatternApp::InitInstance()
{
	AfxEnableControlContainer();

	GdiplusStartupInput gdiplusStartupInput;

	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	HWND hWnd;
	CString window_name;
	
	//�A�v���P�[�V�����B��
	window_name.LoadString(AFX_IDS_APP_TITLE);
	hWnd=FindWindow(NULL,window_name);
	if (hWnd)
	{
		ShowWindow(hWnd,SW_RESTORE);
		BringWindowToTop(hWnd);
		::SetForegroundWindow(hWnd);
		return FALSE;
	}
	// �W���I�ȏ���������
	// ���������̋@�\���g�p�����A���s�t�@�C���̃T�C�Y��������������
	//  ��Έȉ��̓���̏��������[�`���̒�����s�K�v�Ȃ��̂��폜����
	//  ���������B

#ifdef _AFXDLL
	Enable3dControls();			// ���L DLL ���� MFC ���g���ꍇ�͂������R�[�����Ă��������B
#else
	Enable3dControlsStatic();	// MFC �ƐÓI�Ƀ����N����ꍇ�͂������R�[�����Ă��������B
#endif

	//���[�U�g�p�ݒ��ǂݍ��ޕK�v�𔻒f
	SetRegistryKey(window_name);
	int soft_save;
//	soft_save=GetProfileInt(_T("Language"),_T("LangID"),-1);
	soft_save=GetProfileInt(_T("Option"),_T("OldSeted"),-1);
	FristRun=soft_save;
	if(soft_save==0)
	{
		OldSeted=FALSE;
	}

	//���[�U�g�p�ݒ��ǂݍ���
	if(soft_save==1)
	{
		soft_save=GetProfileInt(_T("Option"),_T("ExitMessageNoShow"),-1);
		if(soft_save!=-1)
		{
			ExitMessageNoShow=soft_save;
		}
		soft_save=GetProfileInt(_T("Option"),_T("TesttingMsg"),-1);
		if(soft_save!=-1)
		{
			TesttingMsg=soft_save;
		}
		soft_save=GetProfileInt(_T("Option"),_T("TesttingMsg_ALL"),-1);
		if(soft_save!=-1)
		{
			TesttingMsg_ALL=soft_save;
		}
	}

	//�\�t�g�����ǂݍ���
	soft_save=GetProfileInt(_T("Language"),_T("LangID"),-1);
	if(soft_save!=-1)
	{
		soft_Lang=soft_save;
		switch(soft_save)
		{
			case LANG_JAPANESE://���{��F0x11
				SetThreadLocale(LANG_JAPANESE);
				break;
			case LANG_ENGLISH://�p��F0x09
			default://�ق��̌���
				SetThreadLocale(LANG_ENGLISH);
				break;
		}
		WriteProfileInt(_T("Language"),_T("LangID"),soft_Lang);
	}
	
	//�ꎞ�t�H���_���쐬
	GetSystemDirectory(my_name, MAX_PATH);
	GetFullPathName(my_name,MAX_PATH,filepath,&namebeg);
	strcpy(namebeg,"temp\\NECTestPattern\\");
	namebeg+=20;
	CreateDirectory(filepath,0);

	TestDlg=NULL;
	CNECTestPatternDlg dlg;
	m_pMainWnd = &dlg;

	//�}�C���_�C�A���O��\��
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �_�C�A���O�� <OK> �ŏ����ꂽ���̃R�[�h��
		//       �L�q���Ă��������B
	}
	else if (nResponse == IDCANCEL)
	{
		//�����؂�ւ��āA�\�t�g���ċN��
		char ReRun[MAX_PATH+1];
		GetModuleFileName(0, ReRun, MAX_PATH);
		ShellExecute(NULL,_T("open"),ReRun,NULL,NULL,SW_SHOW);
		// TODO: �_�C�A���O�� <��ݾ�> �ŏ����ꂽ���̃R�[�h��
		//       �L�q���Ă��������B
	}

	// �_�C�A���O�������Ă���A�v���P�[�V�����̃��b�Z�[�W �|���v���J�n������́A
	// �A�v���P�[�V�������I�����邽�߂� FALSE ��Ԃ��Ă��������B
	return FALSE;
}

int CNECTestPatternApp::ExitInstance() 
{

	//�A�v���P�[�V��������
	WriteProfileInt(_T("Language"),_T("LangID"),soft_Lang);

	//���[�U�g�p�ݒ��ۑ�
	WriteProfileInt(_T("Option"),_T("OldSeted"),OldSeted);
	
	if(OldSeted)
	{
		WriteProfileInt(_T("Option"),_T("ExitMessageNoShow"),ExitMessageNoShow);
		WriteProfileInt(_T("Option"),_T("TesttingMsg"),TesttingMsg);
		WriteProfileInt(_T("Option"),_T("TesttingMsg_ALL"),TesttingMsg_ALL);

	}

	//GDI+�N���X�̏I������
	Gdiplus::GdiplusShutdown(gdiplusToken);

	return CWinApp::ExitInstance();
}
