// RemindDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "RemindDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRemindDlg �_�C�A���O


CRemindDlg::CRemindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRemindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRemindDlg)
	m_Check = FALSE;
	//}}AFX_DATA_INIT
}


void CRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRemindDlg)
	DDX_Check(pDX, IDC_CHECK_SHOW, m_Check);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRemindDlg, CDialog)
	//{{AFX_MSG_MAP(CRemindDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRemindDlg ���b�Z�[�W �n���h��

void CRemindDlg::OnOK() 
{

}

void CRemindDlg::OnCancel() 
{

}
