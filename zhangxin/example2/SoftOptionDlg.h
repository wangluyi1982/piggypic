#if !defined(AFX_SOFTOPTIONDLG_H__FFB3E67B_A02C_49B3_B215_1D0138B8B49B__INCLUDED_)
#define AFX_SOFTOPTIONDLG_H__FFB3E67B_A02C_49B3_B215_1D0138B8B49B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SoftOptionDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CSoftOptionDlg �_�C�A���O

class CSoftOptionDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CSoftOptionDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	CSoftOptionDlg(BOOL * inCheck1,BOOL * inCheck2,BOOL * inCheck3,BOOL * inCheck4,CWnd* pParent =NULL);
// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSoftOptionDlg)
	enum { IDD = IDD_SOFT_OPTION };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA

	BOOL * Check1;
	BOOL * Check2;
	BOOL * Check3;
	BOOL * Check4;

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSoftOptionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSoftOptionDlg)
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheck4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SOFTOPTIONDLG_H__FFB3E67B_A02C_49B3_B215_1D0138B8B49B__INCLUDED_)
