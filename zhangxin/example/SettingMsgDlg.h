#if !defined(AFX_SETTINGMSGDLG_H__6D3FDDA1_BE05_4B43_9746_DC790035F29F__INCLUDED_)
#define AFX_SETTINGMSGDLG_H__6D3FDDA1_BE05_4B43_9746_DC790035F29F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingMsgDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CSettingMsgDlg �_�C�A���O

class CSettingMsgDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CSettingMsgDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	//�uEsc�v�ƁuEnter�v�{�^���𖳌�
	void OnCancel();
	void OnOK();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSettingMsgDlg)
	enum { IDD = IDD_SETTING_MSG_DIALOG };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSettingMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSettingMsgDlg)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ����܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SETTINGMSGDLG_H__6D3FDDA1_BE05_4B43_9746_DC790035F29F__INCLUDED_)
