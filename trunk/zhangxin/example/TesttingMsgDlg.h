#if !defined(AFX_TESTTINGMSGDLG_H__00CF9673_C391_4B6E_A4A0_14DE4813D9D0__INCLUDED_)
#define AFX_TESTTINGMSGDLG_H__00CF9673_C391_4B6E_A4A0_14DE4813D9D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TesttingMsgDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CTesttingMsgDlg �_�C�A���O

#define 	MaxState 6

class CTesttingMsgDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CTesttingMsgDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	CTesttingMsgDlg(CRect inpRect,
		CWnd* pParent =NULL);
	void EndbleTime();

	//��ʕ\���ʒu��ݒ�
	void SetDlgPos(CWnd * pDlg=NULL);
	
// �_�C�A���O �f�[�^
	//{{AFX_DATA(CTesttingMsgDlg)
	enum { IDD = IDD_TESTTINGMESSAGE_DIALOG };
	int	m_Timer;
	CString	m_String;
	//}}AFX_DATA
	
	//�\�����b�Z�[�W�̔ԍ�
	int TestMsgState;

	//�����ړ��ϐ�
	bool AutoJumpState;

	//�c�莞��
	int time_min;

	//���j�^�[�ʒu
	CRect monitorRect;

	int setfout;

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CTesttingMsgDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CTesttingMsgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonBack();
	afx_msg void OnRadioM();
	afx_msg void OnRadioA();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChangeEditTime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_TESTTINGMSGDLG_H__00CF9673_C391_4B6E_A4A0_14DE4813D9D0__INCLUDED_)
