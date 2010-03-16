// NECTestPatternDlg.h : �w�b�_�[ �t�@�C��
//

#if !defined(AFX_NECTESTPATTERNDLG_H__BA051C0C_11B8_4E5A_8EE2_34F598AB9BED__INCLUDED_)
#define AFX_NECTESTPATTERNDLG_H__BA051C0C_11B8_4E5A_8EE2_34F598AB9BED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNECTestPatternDlg �_�C�A���O

//�쐬�摜�̌v�Z�֐�
HBITMAP & CreateCalcBitmap_Colors1(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors2(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors3(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);

#include "SettingRemindDlg.h"
extern int Ctrl_vi;

class CNECTestPatternDlg : public CDialog
{
// �\�z
public:
	CNECTestPatternDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^
	CNECTestPatternDlg(UINT nIDTemplate, CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

	//�_�C�A���O�\����Ԃ�؂�ւ��āA�\����Ԃ�ۑ�
	BOOL ShowWindow(int nCmdShow)
	{
		if(nCmdShow==SW_HIDE)
		{
			MainWndsta=FALSE;
			win_show_sta=FALSE;
			GetWindowRect(&MainDlgRect);
		}
		else
		{
			MainWndsta=TRUE;
			win_show_sta=true;
		}

		if(Ctrl_vi==1)
		{
			Ctrl_vi=-1;
			::keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
		}
		else
		{
			if(Ctrl_vi==-1)
			{
				Ctrl_vi=1;
				::keybd_event(VK_CONTROL,0,0,0);
			}
		}
		return CWnd::ShowWindow(nCmdShow);
	}

	//���j�^�[���X�g��ݒ�
	void SetDisplayList();
	
	//���j�^�[���X�g�̏������v�Z
	int ReSetMonitorInfo();

	//�uEsc�v�ƁuEnter�v�{�^���𖳌�
	void OnCancel();
	void OnOK();
	
	//�e�X�g�p�^�[���t�@�C����I������
	void SelectFile();

	//��ʃ{�b�N�X�̏�Ԃ�ݒ�
	void SetEnableWindow();
	void EnableEnuRadio_Color();

	//�\������郉�W�I�{�b�N�X��ݒ�
	void ShowEnuRadio();
	void ShowEnuRadio_Color();

	//�������N���X
	void InitClass();

	//�������_�C�A���O
	void InitDlg();

	//�_�C�A���O�̈ʒu��ݒ�
	void SetDlgPos(CWnd * pDlg=NULL);

	//���[�U�ݒ��ۑ�
	void SaveSeted();

	//���[�U�I���e�X�g�p�^�[���t�@�C����\��
	virtual void OnButtonDisplay(int PatternBmpID);

	//�쐬�摜��\��
	virtual void OnButtonCalcDisplay();

	//�쐬�摜�̍���
	HBITMAP & (*CreateCalcBitmap_Colors)(COLORREF * colors,
		CRect monitor_Rect,HBITMAP & hBmp);
	HBITMAP & (*CreateCalcBitmap_Colors_Ci)(COLORREF * colors,
		CRect monitor_Rect,HBITMAP & hBmp);

	HBITMAP hBitmap;
	//���j�^�[���
	EnumMonitors theEnumMonitors;
	monitor_info_TestPattern * monitor_info_Testadd;
	//�L�����j�^�[�̑䐔
	int monitor_info_count;
	
	//�_�C�A���O�̃{�b�N�X���
	bool Enu_show;
	bool Enable_Enu;
	bool Enable_Color;
	bool monitorCheckAll;
	int SelectColor_show;
	
	//�_�C�A���O�̕\�����
	bool win_show_sta;

	//�쐬�摜�̎��
	int CalcPat;

	//��[�F
	COLORREF SelectedColor;
	
	int CheckedRadioID;
	char * monitorselect_tab;
	char * selectfilename;

	CNECTestPatternDlg * OldSetDlg;
	CFileDialog * pfiledlg;
	CSettingRemindDlg ** pMonitorNum;

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CNECTestPatternDlg)
	enum { IDD = IDD_NECTESTPATTERN_DIALOG };
	CButtonST	m_Button_Pattern3;
	CButtonST	m_Button_Pattern2;
	CButtonST	m_Button_Pattern_Calc3;
	CButtonST	m_Button_Pattern_Calc2;
	CButtonST	m_Button_Pattern_Calc1;
	CButtonST	m_Button_Pattern1;
	CListCtrl	m_DisplayList;
	CString	m_FileName;
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CNECTestPatternDlg)
	public:
	virtual BOOL DestroyWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CNECTestPatternDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonFile();
	afx_msg void OnKillfocusEditFilename();
	afx_msg void OnExitdlg();
	afx_msg void OnButtonFiledisplay();
	afx_msg void OnButtonPattern1();
	afx_msg void OnRADIOFirstCen();
	afx_msg void OnRADIOFirstExt();
	afx_msg void OnRADIOFirstEnu();
	afx_msg void OnRADIOExtPack();
	afx_msg void OnRADIOExtWidth();
	afx_msg void OnRADIOExtHeight();
	afx_msg void OnRadioOne();
	afx_msg void OnCheckAll();
	afx_msg void OnButtonPattern2();
	afx_msg void OnButtonPattern3();
	afx_msg void OnButtonPatternCalc1();
	afx_msg void OnButtonPatternCalc2();
	afx_msg void OnButtonPatternCalc3();
	afx_msg void OnButtonSelectColor();
	afx_msg void OnRadioColorSelect();
	afx_msg void OnRadioColorFile();
	afx_msg void OnMenuitemExit();
	afx_msg void OnAppAbout();
	afx_msg void OnClickListDisplay(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuitemOption();
	afx_msg void OnMenuitemLanguageEn();
	afx_msg void OnMenuitemLanguageJp();
	afx_msg void OnInitMenuPopup(CMenu *pPopupMenu, UINT nIndex,BOOL bSysMenu);
	afx_msg void OnButtonMonitornumber();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonMonitorUpdate();
	afx_msg void OnDeskproperty();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_NECTESTPATTERNDLG_H__BA051C0C_11B8_4E5A_8EE2_34F598AB9BED__INCLUDED_)
