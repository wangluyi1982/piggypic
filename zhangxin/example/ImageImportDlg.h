/*
 *	$Header: $
 *
 *	$History: $
 */
#pragma once

class CImageImportDlg;

// CImageImportDlg
class CImageImportDlg :	public CFileDialog
{

	DECLARE_DYNAMIC(CImageImportDlg)
public:
					CImageImportDlg(LPCTSTR	lpszDefExt = NULL, LPCTSTR lpszFileName	= NULL,	DWORD dwFlags =	OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,	CWnd* pParentWnd = NULL);
	virtual			~CImageImportDlg();

	virtual	void	DoDataExchange(CDataExchange *pDX);
	virtual	BOOL	OnNotify(WPARAM	wParam,	LPARAM lParam, LRESULT*	pResult);
	virtual INT_PTR	DoModal();

	void			UpdatePreview(LPCTSTR szFilename);

protected:
	CString			m_csPreviewName;
	int				m_nPrevSelection;

	virtual	BOOL	OnInitDialog();
	DECLARE_MESSAGE_MAP()
};
