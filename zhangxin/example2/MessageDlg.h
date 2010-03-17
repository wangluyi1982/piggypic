#if !defined(AFX_MESSAGEDLG_H__CF696752_1674_4B1E_B527_82802A3D6940__INCLUDED_)
#define AFX_MESSAGEDLG_H__CF696752_1674_4B1E_B527_82802A3D6940__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MessageDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CMessageDlg �_�C�A���O

class CMessageDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CMessageDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	CMessageDlg(CString in_str,int in_nType=MB_OK,CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	CMessageDlg(CString in_str,int in_nType=MB_OK, BOOL * in_Checked=NULL, CWnd * in_pDlg=NULL , CRect * in_pmoni_rect=NULL ,CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	CMessageDlg(UINT in_strID,int in_nType=MB_OK, BOOL * in_Checked=NULL, CWnd * in_pDlg=NULL , CRect * in_pmoni_rect=NULL ,CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	int nType;
	BOOL * Checked;
	CWnd * pDlg;
	CRect * pmoni_rect;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CMessageDlg)
	enum { IDD = IDD_MESSAGE_DIALOG };
	CString	m_String;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CMessageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CMessageDlg)
	virtual void OnOK();
	afx_msg void OnYes();
	afx_msg void OnNo();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MESSAGEDLG_H__CF696752_1674_4B1E_B527_82802A3D6940__INCLUDED_)
