// SettingRemindDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "SettingRemindDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingRemindDlg �_�C�A���O


CSettingRemindDlg::CSettingRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingRemindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingRemindDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CSettingRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingRemindDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingRemindDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingRemindDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingRemindDlg ���b�Z�[�W �n���h��
void CSettingRemindDlg::OnCancel(){
}

void CSettingRemindDlg::OnOK(){
}
