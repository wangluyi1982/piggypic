// NTPNewFileDialog.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "NECTestPattern.h"
#include "NTPNewFileDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNTPNewFileDialog

IMPLEMENT_DYNAMIC(CNTPNewFileDialog, CFileDialog)

CNTPNewFileDialog::CNTPNewFileDialog(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
	monitor_rect=CRect(0,0,0,0);
	pPra=pParentWnd;
}


BEGIN_MESSAGE_MAP(CNTPNewFileDialog, CFileDialog)
	//{{AFX_MSG_MAP(CNTPNewFileDialog)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CNTPNewFileDialog::SetDesktopRect(CRect in_rect){
	monitor_rect=in_rect;
}

void CNTPNewFileDialog::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	
	
	// �`��p���b�Z�[�W�Ƃ��� CFileDialog::OnPaint() ���Ăяo���Ă͂����܂���
}

int CNTPNewFileDialog::DoModal()
{
	ASSERT_VALID(this);
	ASSERT(m_ofn.Flags & OFN_ENABLEHOOK);
	ASSERT(m_ofn.lpfnHook != NULL); // can still be a user hook

	// zero out the file buffer for consistent parsing later
	ASSERT(AfxIsValidAddress(m_ofn.lpstrFile, m_ofn.nMaxFile));
	DWORD nOffset = lstrlen(m_ofn.lpstrFile)+1;
	ASSERT(nOffset <= m_ofn.nMaxFile);
	memset(m_ofn.lpstrFile+nOffset, 0, (m_ofn.nMaxFile-nOffset)*sizeof(TCHAR));

	// WINBUG: This is a special case for the file open/save dialog,
	//  which sometimes pumps while it is coming up but before it has
	//  disabled the main window.
	HWND hWndFocus = ::GetFocus();
	BOOL bEnableParent = FALSE;
	m_ofn.hwndOwner = PreModal();
	AfxUnhookWindowCreate();
	if (m_ofn.hwndOwner != NULL && ::IsWindowEnabled(m_ofn.hwndOwner))
	{
		bEnableParent = TRUE;
		::EnableWindow(m_ofn.hwndOwner, FALSE);
	}

	_AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
	ASSERT(pThreadState->m_pAlternateWndInit == NULL);

	if (m_ofn.Flags & OFN_EXPLORER)
		pThreadState->m_pAlternateWndInit = this;
	else
		AfxHookWindowCreate(this);

	//060804
//	if(pPra!=NULL){
//		CRect PraRect,theDlgRect_O,theDlgRect_N;
//		pPra->GetWindowRect(&PraRect);
//		this->GetWindowRect(&theDlgRect_O);
//		theDlgRect_N.left	=	PraRect.left	+	(PraRect.Width()	-	theDlgRect_O.Width()	)/2;
//		theDlgRect_N.top	=	PraRect.top		+	(PraRect.Height()	-	theDlgRect_O.Height()	)/2;
//		::SetWindowPos(this->GetSafeHwnd(),HWND_TOP ,
//			monitor_rect.left,//x0,
//			monitor_rect.top,//y0,
//			monitor_rect.Width(),
//			monitor_rect.Height(),
//			SWP_SHOWWINDOW);
//		MessageBox("");
//		::MoveWindow(this->GetSafeHwnd(),
//			theDlgRect_N.left,
//			theDlgRect_N.top,
//			theDlgRect_O.Width(),
//			theDlgRect_O.Height(),
//			true);
//	}
	//060804

	int nResult;
	if (m_bOpenFileDialog)
		nResult = ::GetOpenFileName(&m_ofn);
	else
		nResult = ::GetSaveFileName(&m_ofn);

	if (nResult)
		ASSERT(pThreadState->m_pAlternateWndInit == NULL);
	pThreadState->m_pAlternateWndInit = NULL;

	// WINBUG: Second part of special case for file open/save dialog.
	if (bEnableParent)
		::EnableWindow(m_ofn.hwndOwner, TRUE);
	if (::IsWindow(hWndFocus))
		::SetFocus(hWndFocus);

	PostModal();
	return nResult ? nResult : IDCANCEL;
}

BOOL CNTPNewFileDialog::OnInitDialog() 
{
	CFileDialog::OnInitDialog();
	
	SetWindowText("123");// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}
