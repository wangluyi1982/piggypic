/*
 *	$Header: $
 *
 *	$History: $
 */
#include "stdafx.h"
#include ".\imageimportdlg.h"
#include <dlgs.h>

#define _countof(array)(sizeof(array)/sizeof(array[0]))
// CImageImportDlg
IMPLEMENT_DYNAMIC(CImageImportDlg, CFileDialog)

static char BASED_CODE szFilter[] = "Picture Files (*.jpg;*.gif;*.bmp;*.png)|*.jpg;*.gif;*.bmp;*.png|All Files (*.*)|*.*||";

//void CImageImportDlg::CHookShellWnd::SetOwner(CImageImportDlg *pOwner)
//{
//	ASSERT(pOwner);
//	ASSERT_KINDOF(CImageImportDlg, pOwner);
//
//	m_pOwner = pOwner;
//}
//
//BOOL CImageImportDlg::CHookShellWnd::OnCommand(WPARAM /*wParam*/, LPARAM lParam)
//{
////	TRACE("wp(%d), lp(%x)\n", wParam, lParam);
//	return CWnd::OnCommand(0, lParam);
//}
//
//BOOL CImageImportDlg::CHookShellWnd::OnNotify(WPARAM, LPARAM lParam, LRESULT *pResult)
//{
//	LPNMLISTVIEW pLVHdr	= reinterpret_cast<LPNMLISTVIEW>(lParam);
//
//	if (pLVHdr->hdr.code ==	LVN_ITEMCHANGED	&& (pLVHdr->uChanged & LVIF_STATE))
//	{
//		if (pLVHdr->iItem != -1)
//		{
//			//	It's a valid listview index	so we attach the
//			//	the	handle of the window that sent the message
//			//	to a local CListCtrl object	for	easy access.
//			CListCtrl	  ctl;
//			LPCITEMIDLIST pidl;
//			TCHAR		  tszBuffer[_MAX_PATH],
//						  tszFileName[_MAX_PATH],
//						  tszExtension[_MAX_EXT];
//			CString		  csTemp;
//
//			ctl.Attach(pLVHdr->hdr.hwndFrom);
//			pidl = (LPCITEMIDLIST) ctl.GetItemData(pLVHdr->iItem);
//			SHGetPathFromIDList(pidl, tszBuffer);
//			_tsplitpath(tszBuffer, NULL, NULL, tszFileName, tszExtension);
//			csTemp.Format(_T("%s%s"), tszFileName, tszExtension);
//
//			//	Update our parent window
//			if (m_pOwner->m_nPrevSelection != pLVHdr->iItem)
//				m_pOwner->UpdatePreview(csTemp);
//
//			//	Be certain we detach the handle	before the CListCtrl
//			//	object goes	out	of scope (else the underlying List View
//			//	will be	deleted, which is NOT what we want).
//			ctl.Detach();
//		}
//		else
//			m_pOwner->UpdatePreview(_T(""));
//	}
//
//	return *pResult	= 0;
//}

CImageImportDlg::CImageImportDlg(LPCTSTR lpszDefExt, LPCTSTR lpszFileName, DWORD dwFlags, CWnd* pParentWnd) : CFileDialog(TRUE, lpszDefExt, lpszFileName, dwFlags, szFilter, pParentWnd)
{
	m_ofn.Flags |= OFN_ENABLETEMPLATE | OFN_ALLOWMULTISELECT | OFN_ENABLESIZING;
	m_ofn.hInstance = AfxGetInstanceHandle();
	m_ofn.lpTemplateName = MAKEINTRESOURCE(IDD_IMAGEPREVIEWDLG);

	//	Provide a big buffer for returned filenames
	m_ofn.lpstrFile = new TCHAR[10000];
	m_ofn.nMaxFile = 10000;
	memset(m_ofn.lpstrFile, 0, _countof(m_ofn.lpstrFile));

	m_nPrevSelection = -1;
}

CImageImportDlg::~CImageImportDlg()
{
	delete m_ofn.lpstrFile;
}

BEGIN_MESSAGE_MAP(CImageImportDlg, CFileDialog)
END_MESSAGE_MAP()

INT_PTR	CImageImportDlg::DoModal()
{
	INT_PTR status = CFileDialog::DoModal();

	return status;
}

BOOL CImageImportDlg::OnNotify(WPARAM, LPARAM lp, LRESULT *pResult)
{
	LPOFNOTIFY of =	(LPOFNOTIFY) lp;
	CString	   csTemp;
	TCHAR	   tszBuffer[_MAX_PATH];

	switch (of->hdr.code)
	{
	case CDN_SELCHANGE:
		if (CommDlg_OpenSave_GetSpec(GetParent()->GetSafeHwnd(), tszBuffer, _countof(tszBuffer)) > 0)
			TRACE("%s\n", tszBuffer);

		break;

	case CDN_FOLDERCHANGE:
		//	Once we	get	this notification our old subclassing of
		//	the	SHELL window is	lost, so we	have to
		//	subclass it	again. (Changing the folder	causes a 
		//	destroy	and	recreate of	the	SHELL window).
		UpdatePreview(_T(""));
		break;
	}

	*pResult = 0;
	return FALSE;
}

void CImageImportDlg::DoDataExchange(CDataExchange *pDX)
{
	CFileDialog::DoDataExchange(pDX);
}

// CImageImportDlg message handlers
BOOL CImageImportDlg::OnInitDialog()
{
	CFileDialog::OnInitDialog();

	//	It's an import dialog so change the button text on 
	//	the open button to say "Import"
	GetParent()->GetDlgItem(IDOK)->SetWindowText(_T("Import"));
	GetParent()->SetWindowText(_T("Import Pictures"));

	return TRUE;
}

void CImageImportDlg::UpdatePreview(LPCTSTR szFilename)
{
	ASSERT(szFilename);
	ASSERT(AfxIsValidString(szFilename));

	m_csPreviewName = szFilename;
	UpdateData(FALSE);
}
