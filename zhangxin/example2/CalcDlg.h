#if !defined(AFX_CALCDLG_H__41D7E0B6_B1B3_4514_9803_A26DFC27299F__INCLUDED_)
#define AFX_CALCDLG_H__41D7E0B6_B1B3_4514_9803_A26DFC27299F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CalcDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg �_�C�A���O

class CCalcDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CCalcDlg(UINT in = 0,CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	UINT Dlgcase;
	int CheckID;
// �_�C�A���O �f�[�^
	//{{AFX_DATA(CCalcDlg)
	enum { IDD = IDD_CALC_DIALOG };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CCalcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CCalcDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_CALCDLG_H__41D7E0B6_B1B3_4514_9803_A26DFC27299F__INCLUDED_)
