#if !defined(AFX_SETTINGREMINDDLG_H__CA1AA36E_F9C7_4378_98F7_90A0B48B6499__INCLUDED_)
#define AFX_SETTINGREMINDDLG_H__CA1AA36E_F9C7_4378_98F7_90A0B48B6499__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingRemindDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CSettingRemindDlg �_�C�A���O

class CSettingRemindDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CSettingRemindDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	void OnCancel();
	void OnOK();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingRemindDlg)
	enum { IDD = IDD_SETTING_REMIND_DIALOG };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSettingRemindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSettingRemindDlg)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ����܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SETTINGREMINDDLG_H__CA1AA36E_F9C7_4378_98F7_90A0B48B6499__INCLUDED_)
