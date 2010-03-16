#if !defined(AFX_TESTPATTERNDLG_H__445C3A09_50C5_435C_9269_2387DDF2339C__INCLUDED_)
#define AFX_TESTPATTERNDLG_H__445C3A09_50C5_435C_9269_2387DDF2339C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestPatternDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CTestPatternDlg �_�C�A���O
class XYandWH;
class CTestPatternDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CTestPatternDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	void SetDlgRect(CRect rect_in);
	void SetDlgRect(XYandWH xywh_in);

	//�uEsc�v�ƁuEnter�v�{�^���𖳌�
	void OnOK();
	void OnCancel();

	//���ۂ�Cancel
	void OnNewCancel();

	//�\���t�@�C�����O
	char * filename;

	//�r�b�g�}�b�v�̃n���h
	HBITMAP hBitmap;

	//�e���
	CWnd* pParentWnd;

	//���̉��
	CDialog* pNextWnd;

	//���j�^�[�ʒu
	CRect rect;

	//���j�^�[�ԍ�
	int add;

	//��ʕ\�������ݒ�
	bool CenShow;
	bool ReSize;
	int Enu_Hor_pos;
	int Enu_Ver_pos;
	int Ext;

	//��[�F�̕ϐ�
	int Color_pos;
	COLORREF SelectedCol;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CTestPatternDlg)
	enum { IDD = IDD_TEST_PATTERN };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CTestPatternDlg)
	public:
	virtual BOOL Create(UINT nID,CWnd* pParent);
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CTestPatternDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_TESTPATTERNDLG_H__445C3A09_50C5_435C_9269_2387DDF2339C__INCLUDED_)
