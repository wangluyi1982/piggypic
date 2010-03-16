
#ifndef _NECTESTPATTERN_LIB_H
#define _NECTESTPATTERN_LIB_H

#include "stdafx.h"

class CTestPatternDlg;
class CSetTestPatternDlg;
class CNECTestPatternDlg;

extern CTestPatternDlg ** TestDlg;
extern CSetTestPatternDlg ** TestSetDlg;
extern CNECTestPatternDlg * SetDlg;

//画像表示画面初期化
void setprosize(CWnd* pdlg,						//ダイアログ
					 CRect display_rect,				//モニター位置
					 int nID,							//画像（ビットマップ）ボックスのID
					 char * filename,					//画像ファイル名前
					 bool Resize=false,				//画像表示引数：サイズ変化
					 bool Center=false);				//画像表示引数：真ん中表示

void setprosize(CWnd* pdlg,						//ダイアログ
					 CRect display_rect,				//モニター位置
					 int nID,							//画像（ビットマップ）ボックスのID
					 int bmpID,							//ビットマップID
					 bool Resize=false,				//画像表示引数：サイズ変化
					 bool Center=false);				//画像表示引数：真ん中表示

void setprosize(CWnd* pdlg,						//ダイアログ
					 CRect display_rect,				//モニター位置
					 int nID,							//画像（ビットマップ）ボックスのID
					 HBITMAP hBitmap,					//画像ハンド
					 bool Resize=false,				//画像表示引数：サイズ変化
					 bool Center=false);				//画像表示引数：真ん中表示

void setprosize(CWnd* pdlg,						//ダイアログ
					 XYandWH display_size,			//モニター位置（左上角の位置、幅、長さ）
					 int nID,							//画像（ビットマップ）ボックスのID
					 char * filename,					//画像ファイル名前
					 bool Resize=false,				//画像表示引数：サイズ変化
					 bool Center=false);				//画像表示引数：真ん中表示

void setprosize(CWnd* pdlg,						//ダイアログ
					 XYandWH display_size,			//モニター位置（左上角の位置、幅、長さ）
					 int nID,							//画像（ビットマップ）ボックスのID
					 int bmpID,							//ビットマップID
					 bool Resize=false,				//画像表示引数：サイズ変化
					 bool Center=false);				//画像表示引数：真ん中表示

void setprosize(CWnd* pdlg,						//ダイアログ
					 XYandWH display_size,			//モニター位置（左上角の位置、幅、長さ）
					 int nID,							//画像（ビットマップ）ボックスのID
					 HBITMAP hBitmap,					//画像ハンド
					 bool Resize=false,				//画像表示引数：サイズ変化
					 bool Center=false);				//画像表示引数：真ん中表示

void SetBitmapBoxSize(CWnd* pdlg,				//ダイアログ
							 CRect display_rect,		//モニター位置
							 int nID,					//画像（ビットマップ）ボックスのID
							 HBITMAP hBmp,				//画像ハンド
							 bool Resize=false);		//画像表示引数：サイズ変化

void SetBitmapBoxSize(CWnd* pdlg,				//ダイアログ
							 XYandWH display_size,	//モニター位置（左上角の位置、幅、長さ）
							 int nID,					//画像（ビットマップ）ボックスのID
							 HBITMAP hBmp,				//画像ハンド
							 bool Resize=false);		//画像表示引数：サイズ変化

//モノクロ用画像を表示するために、一時画像を作成する関数
HBITMAP & CreateNewHBitmap_GrayScale_to_RGB(char * filename,HBITMAP & hBmp);

//ビットマップのハンドを作成関数
HBITMAP & CreateNewHBitmap(char * filename,HBITMAP & hBmp);
HBITMAP & CreateNewHBitmap(int bmpID,HBITMAP & hBmp);

//補充色の画像を作成関数
HBITMAP & CreateNewHBitmap_BK(COLORREF in_color,HBITMAP & hBmp);
HBITMAP & CreateNewHBitmap_SELCOLOR(COLORREF in_color,HBITMAP & hBmp);

//作成画像のビットマップを作成関数
HBITMAP & CreateNewHBitmap_Calc(COLORREF * in_color,DWORD width,DWORD length,HBITMAP & hBmp);

//ビットマップファイルを作成関数
void CreateNewBitmapFile(char * filename,
								 DWORD width,
								 DWORD length,
								 COLORREF * colors);

//スレッド関数
UINT th(LPVOID p);

//作成画像を作成関数
HBITMAP & CreateCalcBitmap_Colors1(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors2(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors3(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);

//BitmapのColorバッファに線を描く
void SetBitmapColor_Line(COLORREF * colors,			//色バッファ
								 DWORD width,					//色バッファの幅
								 DWORD length,					//色バッファの高さ
								 CRect rect,					//線の位置
								 COLORREF setcolor,			//線の色
								 bool width_first=FALSE);	//幅優先

//BitmapのColorバッファに長方形を描く
void SetBitmapColor_RectBk(COLORREF * colors,			//色バッファ
									DWORD width,					//色バッファの幅
									DWORD length,					//色バッファの高さ
									CRect rect,						//長方形の位置
									COLORREF setcolor);			//長方形の色

//BitmapのColorバッファに長方形の枠を描く
void SetBitmapColor_RectLine(COLORREF * colors,			//色バッファ
									DWORD width,					//色バッファの幅
									DWORD length,					//色バッファの高さ
									CRect rect,						//長方形の枠の位置
									COLORREF setcolor);			//長方形の枠の色

//モニター対応最大値（未使用）
#define MAX_MONITOR_NUM	8

#include <AFXPRIV.H>
#include <fstream.H>


#endif 