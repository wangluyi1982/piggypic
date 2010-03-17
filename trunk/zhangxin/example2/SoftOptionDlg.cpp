// SoftOptionDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "SoftOptionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSoftOptionDlg �_�C�A���O


CSoftOptionDlg::CSoftOptionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSoftOptionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSoftOptionDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
	Check1=Check2=Check3=Check4=NULL;
}

CSoftOptionDlg::CSoftOptionDlg(BOOL * inCheck1,BOOL * inCheck2,BOOL * inCheck3,BOOL * inCheck4,CWnd* pParent /*=NULL*/)
	: CDialog(CSoftOptionDlg::IDD, pParent)
{
	Check1=inCheck1;
	Check2=inCheck2;
	Check3=inCheck3;
	Check4=inCheck4;
}


void CSoftOptionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSoftOptionDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSoftOptionDlg, CDialog)
	//{{AFX_MSG_MAP(CSoftOptionDlg)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoftOptionDlg ���b�Z�[�W �n���h��

void CSoftOptionDlg::OnCheck1() 
{
	if(Check1!=NULL){
		*Check1=*Check1?false:true;
	}
	
}

void CSoftOptionDlg::OnCheck2() 
{
	if(Check2!=NULL){
		*Check2=*Check2?false:true;
	}
	
}

void CSoftOptionDlg::OnCheck3() 
{
	if(Check3!=NULL){
		*Check3=*Check3?false:true;
	}
	
}

BOOL CSoftOptionDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	HICON hicon = ::LoadIcon(NULL, IDI_QUESTION);
	CStatic * pStatic=(CStatic *)GetDlgItem(IDC_STATIC_ICON);
	pStatic->SetIcon(hicon);

	
	CButton * pBut;

	pBut=(CButton *)GetDlgItem(IDC_CHECK1);
	if(Check1!=NULL){
		pBut->SetCheck(*Check1);
	}else{
		pBut->EnableWindow(FALSE);
	}
	
	pBut=(CButton *)GetDlgItem(IDC_CHECK2);
	if(Check2!=NULL){
		pBut->SetCheck(*Check2);
	}else{
		pBut->EnableWindow(FALSE);
	}
	
	pBut=(CButton *)GetDlgItem(IDC_CHECK3);
	if(Check3!=NULL){
		pBut->SetCheck(*Check3);
	}else{
		pBut->EnableWindow(FALSE);
	}

	pBut=(CButton *)GetDlgItem(IDC_CHECK4);
	if(Check4!=NULL){
		pBut->SetCheck(*Check4);
	}else{
		pBut->EnableWindow(FALSE);
	}
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CSoftOptionDlg::OnCheck4() 
{
	if(Check4!=NULL){
		*Check4=*Check4?false:true;
	}
	
}
