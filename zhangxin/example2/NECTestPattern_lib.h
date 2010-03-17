
#ifndef _NECTESTPATTERN_LIB_H
#define _NECTESTPATTERN_LIB_H

#include "stdafx.h"

extern int Count;
extern char filepath[MAX_PATH];
extern char my_name[MAX_PATH];
extern char * namebeg;

class CTestPatternDlg;
class CSetTestPatternDlg;
class CNECTestPatternDlg;

extern CTestPatternDlg ** TestDlg;
extern CSetTestPatternDlg ** TestSetDlg;
extern CNECTestPatternDlg * SetDlg;

class XYandWH{
	public:
		int x0;
		int y0;
		int width;
      int height;
		XYandWH(int x0_,int y0_,int width_,int height_):x0(x0_),y0(y0_),width(width_),height(height_){}
		XYandWH():x0(0),y0(0),width(0),height(0){}
		operator CRect(){
			CRect(x0,y0,x0+width,y0+height);
		}
};

void setprosize(CWnd* pdlg,CRect display_rect,int nID,char * filemane,bool Resize=false,bool Center=false);
void setprosize(CWnd* pdlg,CRect display_rect,int nID,int bmpID,bool Resize=false,bool Center=false);
void setprosize(CWnd* pdlg,XYandWH display_size,int nID,char * filemane,bool Resize=false,bool Center=false);
void setprosize(CWnd* pdlg,XYandWH display_size,int nID,int bmpID,bool Resize=false,bool Center=false);
void setprosize(CWnd* pdlg,XYandWH display_size,int nID,HBITMAP hBitmap,bool Resize=false,bool Center=false);
void setprosize(CWnd* pdlg,CRect display_rect,int nID,HBITMAP hBitmap,bool Resize=false,bool Center=false);
void SetBitmapBoxSize(CWnd* pdlg,CRect display_rect,int nID,HBITMAP hBmp,bool Resize=false);
void SetBitmapBoxSize(CWnd* pdlg,XYandWH display_size,int nID,HBITMAP hBmp,bool Resize=false);

HBITMAP & CreateNewHBitmap_GrayScale_to_RGB(char * filemane,HBITMAP & hBmp);
HBITMAP & CreateNewHBitmap(char * filemane,HBITMAP & hBmp);
HBITMAP & CreateNewHBitmap(int bmpID,HBITMAP & hBmp);
HBITMAP & CreateNewHBitmap_BK(COLORREF in_color,HBITMAP & hBmp);
HBITMAP & CreateNewHBitmap_Calc(COLORREF * in_color,DWORD width,DWORD length,HBITMAP & hBmp);
HBITMAP & CreateNewHBitmap_SELCOLOR(COLORREF in_color,HBITMAP & hBmp);

void CreateNewBitmapFile(char * filename,DWORD width,DWORD length,COLORREF * colors);

void GetDlgItemXYandWH(CWnd * pWnd,int nID,XYandWH & retXYandWH);
int GetWindowUpWidth(CWnd * pWnd);
int GetWindowLeftWidth(CWnd * pWnd);
#define GetWindowDownWidth  GetWindowLeftWidth
#define GetWindowRightWidth  GetWindowLeftWidth
UINT th(LPVOID p);

HBITMAP & CreateCalcBitmap_Colors1(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors2(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors3(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);

void SetBitmapColor_Line(COLORREF * colors,DWORD width,DWORD length,CRect rect,COLORREF setcolor,bool width_first=FALSE);
void SetBitmapColor_RectBk(COLORREF * colors,DWORD width,DWORD length,CRect rect,COLORREF setcolor);
void SetBitmapColor_RectLine(COLORREF * colors,DWORD width,DWORD length,CRect rect,COLORREF setcolor);


#define MAX_MONITOR_NUM	8

#include <AFXPRIV.H>
#include <fstream.H>


#endif 