#if !defined(AFX_NTPNEWFILEDIALOG_H__79C5057D_DFB5_420E_9852_28B0F6FEA06D__INCLUDED_)
#define AFX_NTPNEWFILEDIALOG_H__79C5057D_DFB5_420E_9852_28B0F6FEA06D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NTPNewFileDialog.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CNTPNewFileDialog �_�C�A���O

class CNTPNewFileDialog : public CFileDialog
{
	DECLARE_DYNAMIC(CNTPNewFileDialog)

public:
	CNTPNewFileDialog(BOOL bOpenFileDialog, // TRUE �Ȃ�� FileOpen�A FALSE �Ȃ�� FileSaveAs
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);

	CRect monitor_rect;
	CWnd * pPra;

	void SetDesktopRect(CRect in_rect);
	int DoModal();


protected:
	//{{AFX_MSG(CNTPNewFileDialog)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_NTPNEWFILEDIALOG_H__79C5057D_DFB5_420E_9852_28B0F6FEA06D__INCLUDED_)
