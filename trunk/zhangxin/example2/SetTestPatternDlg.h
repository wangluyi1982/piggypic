#if !defined(AFX_SETTESTPATTERNDLG_H__E481D64F_8884_47B5_B08E_2701A67616B1__INCLUDED_)
#define AFX_SETTESTPATTERNDLG_H__E481D64F_8884_47B5_B08E_2701A67616B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetTestPatternDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CSetTestPatternDlg �_�C�A���O
#include "NECTestPatternDlg.h"

class CSetTestPatternDlg : public CNECTestPatternDlg
{
// �R���X�g���N�V����
public:
	friend UINT th(LPVOID p);
	CSetTestPatternDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	virtual void OnButtonDisplay(int PatternBmpID);
	virtual void OnButtonCalcDisplay();
	int add;
	CDialog * pNextWnd;
	CTestPatternDlg * TestDlg_one;
	CSettingMsgDlg * SetTextDlg;
	CSettingRemindDlg * SetRemindDlg;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSetTestPatternDlg)
	enum { IDD = IDD_SETTESTPATTERN };
//	CButtonST	m_Button_Pattern1;
//	CString	m_FileName;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSetTestPatternDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSetTestPatternDlg)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonFiledisplay();
	afx_msg void OnDonot();
	afx_msg void OnBack();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SETTESTPATTERNDLG_H__E481D64F_8884_47B5_B08E_2701A67616B1__INCLUDED_)
