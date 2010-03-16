#include <afxwin.h>

#ifndef _MYLIB_H

#define _MYLIB_H

extern int Count;
extern char filepath[MAX_PATH];
extern char my_name[MAX_PATH];
extern char * namebeg;

extern BOOL OldSeted;
extern BOOL ExitMessageNoShow;
extern BOOL TesttingMsg;
extern BOOL TesttingMsg_ALL;

extern BOOL MainWndsta;
extern BOOL CalcPattern;
extern int FristRun;
extern int soft_Lang;
extern float IdentifyTime;

extern CRect MainDlgRect;
extern CRect monitorRect;														//���j�^�[�ʒu

extern bool NECAfxMessageBox_Ser_Runing;									//NECAfxMessageBox
extern bool NECAfxMessageBox_Ser_MoveMessageBox_Runing;
extern CWinThread * pth;
extern CWinThread * pth_move;

extern HHOOK glhHook_WinMove; 
extern HHOOK glhHook_Mouse; 
// HHOOK glhHook_ListCtrl_Mouse; 

//HHOOK glhHook_DisplayChange; 
extern CWnd * pwnd;

void CallDeskProperty();

int ReadGrayScaleFileToColor(char * filename,DWORD & 	width,DWORD  &length,COLORREF * * pcolors,unsigned short int * * pbuf_temp);
class XYandWH
{
	public:
		int x0;								//����p�F�����ʒu
		int y0;								//����p�F�c���ʒu
		int width;							//��
      int height;							//����
		
		XYandWH(int x0_,
			int y0_,
			int width_,
			int height_):x0(x0_),y0(y0_),width(width_),height(height_)
		{
		
		}
		
		XYandWH():x0(0),y0(0),width(0),height(0)
		{

		}
		
		//CRect�N���X�ɕϊ�
		operator CRect()
		{
			CRect(x0,y0,x0+width,y0+height);
		}
};

//�_�C�A���O�̃{�b�N�X�̈ʒu��߂�֐�
//GetDlgItem(UINT)->GetWindowRect(CRect &)	���̊֐��Ƃ̈Ⴂ��
//GetDlgItemXYandWH�́@�_�C�A���O�̒��Ɉʒu��߂�
//GetDlgItem(UINT)->GetWindowRect(CRect &)�@�f�X�N�g�b�v�̒��Ɉʒu��߂�
void GetDlgItemXYandWH(CWnd * pWnd,int nID,XYandWH & retXYandWH);

//�_�C�A���O�̏�̘g��������߂�
int GetWindowUpWidth(CWnd * pWnd);

//�_�C�A���O�̍��̘g��������߂�
int GetWindowLeftWidth(CWnd * pWnd);

//�E�Ɖ��̘g
#define GetWindowDownWidth  GetWindowLeftWidth
#define GetWindowRightWidth  GetWindowLeftWidth

//�r�b�g�}�b�v�t�@�C�����쐬�֐�
void CreateBitmapFile(char * filename,
								 DWORD width,
								 DWORD length,
								 COLORREF * colors);

#endif