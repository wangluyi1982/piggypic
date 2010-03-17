// CalcDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "CalcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg �_�C�A���O


CCalcDlg::CCalcDlg(UINT in /*= 0*/,CWnd* pParent /*=NULL*/)
	: CDialog(CCalcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalcDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
	Dlgcase=in;
}


void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalcDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCalcDlg, CDialog)
	//{{AFX_MSG_MAP(CCalcDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg ���b�Z�[�W �n���h��

BOOL CCalcDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	switch(Dlgcase){
		case 0:
		default:
			CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);
			break;
		case 1:
			CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO2);
			GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
			break;
		case 2:
			CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);
			GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
			break;
		case 3:
			CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);
			GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
			break;
	}
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CCalcDlg::OnOK() 
{
	CheckID=GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO3)-IDC_RADIO1;
	CDialog::OnOK();
}
