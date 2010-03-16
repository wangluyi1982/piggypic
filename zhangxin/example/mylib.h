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
extern CRect monitorRect;														//モニター位置

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
		int x0;								//左上角：横軸位置
		int y0;								//左上角：縦軸位置
		int width;							//幅
      int height;							//長さ
		
		XYandWH(int x0_,
			int y0_,
			int width_,
			int height_):x0(x0_),y0(y0_),width(width_),height(height_)
		{
		
		}
		
		XYandWH():x0(0),y0(0),width(0),height(0)
		{

		}
		
		//CRectクラスに変換
		operator CRect()
		{
			CRect(x0,y0,x0+width,y0+height);
		}
};

//ダイアログのボックスの位置を戻る関数
//GetDlgItem(UINT)->GetWindowRect(CRect &)	この関数との違いは
//GetDlgItemXYandWHは　ダイアログの中に位置を戻る
//GetDlgItem(UINT)->GetWindowRect(CRect &)　デスクトップの中に位置を戻る
void GetDlgItemXYandWH(CWnd * pWnd,int nID,XYandWH & retXYandWH);

//ダイアログの上の枠を高さを戻る
int GetWindowUpWidth(CWnd * pWnd);

//ダイアログの左の枠を高さを戻る
int GetWindowLeftWidth(CWnd * pWnd);

//右と下の枠
#define GetWindowDownWidth  GetWindowLeftWidth
#define GetWindowRightWidth  GetWindowLeftWidth

//ビットマップファイルを作成関数
void CreateBitmapFile(char * filename,
								 DWORD width,
								 DWORD length,
								 COLORREF * colors);

#endif