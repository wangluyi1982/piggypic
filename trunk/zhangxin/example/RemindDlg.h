#if !defined(AFX_REMINDDLG_H__3AB12ABF_7322_4883_97C4_BC019DABFFDA__INCLUDED_)
#define AFX_REMINDDLG_H__3AB12ABF_7322_4883_97C4_BC019DABFFDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RemindDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CRemindDlg �_�C�A���O

class CRemindDlg : public CDialog
{
// �R���X�g���N�V����
public:
	bool showing;
	CRemindDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	BOOL ShowWindow(int nCmdShow)
	{
		if(nCmdShow==SW_HIDE)
		{
			showing=FALSE;
			GetWindowRect(&MainDlgRect);
		}
		else
		{
			showing=true;
		}
		return CWnd::ShowWindow(nCmdShow);
	}
// �_�C�A���O �f�[�^
	//{{AFX_DATA(CRemindDlg)
	enum { IDD = IDD_REMIND_DIALOG };
	BOOL	m_Check;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CRemindDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CRemindDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_REMINDDLG_H__3AB12ABF_7322_4883_97C4_BC019DABFFDA__INCLUDED_)
