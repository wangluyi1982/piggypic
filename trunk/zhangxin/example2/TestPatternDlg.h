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
	char * filename;
	HBITMAP hBitmap;
	CWnd* pParentWnd;
	CDialog* pNextWnd;
	CRect rect;
	void SetDlgRect(CRect rect_in);
	void SetDlgRect(XYandWH xywh_in);
	bool CenShow;
	bool ReSize;
	int add;
	int Enu_Hor_pos;
	int Enu_Ver_pos;
	int Ext;
	int Color_pos;
	COLORREF SelectedCol;
	void OnOK();
	void OnCancel();
	void OnNewCancel();

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
