
#ifndef _NECTESTPATTERN_LIB_H
#define _NECTESTPATTERN_LIB_H

#include "stdafx.h"

class CTestPatternDlg;
class CSetTestPatternDlg;
class CNECTestPatternDlg;

extern CTestPatternDlg ** TestDlg;
extern CSetTestPatternDlg ** TestSetDlg;
extern CNECTestPatternDlg * SetDlg;

//�摜�\����ʏ�����
void setprosize(CWnd* pdlg,						//�_�C�A���O
					 CRect display_rect,				//���j�^�[�ʒu
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 char * filename,					//�摜�t�@�C�����O
					 bool Resize=false,				//�摜�\�������F�T�C�Y�ω�
					 bool Center=false);				//�摜�\�������F�^�񒆕\��

void setprosize(CWnd* pdlg,						//�_�C�A���O
					 CRect display_rect,				//���j�^�[�ʒu
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 int bmpID,							//�r�b�g�}�b�vID
					 bool Resize=false,				//�摜�\�������F�T�C�Y�ω�
					 bool Center=false);				//�摜�\�������F�^�񒆕\��

void setprosize(CWnd* pdlg,						//�_�C�A���O
					 CRect display_rect,				//���j�^�[�ʒu
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 HBITMAP hBitmap,					//�摜�n���h
					 bool Resize=false,				//�摜�\�������F�T�C�Y�ω�
					 bool Center=false);				//�摜�\�������F�^�񒆕\��

void setprosize(CWnd* pdlg,						//�_�C�A���O
					 XYandWH display_size,			//���j�^�[�ʒu�i����p�̈ʒu�A���A�����j
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 char * filename,					//�摜�t�@�C�����O
					 bool Resize=false,				//�摜�\�������F�T�C�Y�ω�
					 bool Center=false);				//�摜�\�������F�^�񒆕\��

void setprosize(CWnd* pdlg,						//�_�C�A���O
					 XYandWH display_size,			//���j�^�[�ʒu�i����p�̈ʒu�A���A�����j
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 int bmpID,							//�r�b�g�}�b�vID
					 bool Resize=false,				//�摜�\�������F�T�C�Y�ω�
					 bool Center=false);				//�摜�\�������F�^�񒆕\��

void setprosize(CWnd* pdlg,						//�_�C�A���O
					 XYandWH display_size,			//���j�^�[�ʒu�i����p�̈ʒu�A���A�����j
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 HBITMAP hBitmap,					//�摜�n���h
					 bool Resize=false,				//�摜�\�������F�T�C�Y�ω�
					 bool Center=false);				//�摜�\�������F�^�񒆕\��

void SetBitmapBoxSize(CWnd* pdlg,				//�_�C�A���O
							 CRect display_rect,		//���j�^�[�ʒu
							 int nID,					//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
							 HBITMAP hBmp,				//�摜�n���h
							 bool Resize=false);		//�摜�\�������F�T�C�Y�ω�

void SetBitmapBoxSize(CWnd* pdlg,				//�_�C�A���O
							 XYandWH display_size,	//���j�^�[�ʒu�i����p�̈ʒu�A���A�����j
							 int nID,					//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
							 HBITMAP hBmp,				//�摜�n���h
							 bool Resize=false);		//�摜�\�������F�T�C�Y�ω�

//���m�N���p�摜��\�����邽�߂ɁA�ꎞ�摜���쐬����֐�
HBITMAP & CreateNewHBitmap_GrayScale_to_RGB(char * filename,HBITMAP & hBmp);

//�r�b�g�}�b�v�̃n���h���쐬�֐�
HBITMAP & CreateNewHBitmap(char * filename,HBITMAP & hBmp);
HBITMAP & CreateNewHBitmap(int bmpID,HBITMAP & hBmp);

//��[�F�̉摜���쐬�֐�
HBITMAP & CreateNewHBitmap_BK(COLORREF in_color,HBITMAP & hBmp);
HBITMAP & CreateNewHBitmap_SELCOLOR(COLORREF in_color,HBITMAP & hBmp);

//�쐬�摜�̃r�b�g�}�b�v���쐬�֐�
HBITMAP & CreateNewHBitmap_Calc(COLORREF * in_color,DWORD width,DWORD length,HBITMAP & hBmp);

//�r�b�g�}�b�v�t�@�C�����쐬�֐�
void CreateNewBitmapFile(char * filename,
								 DWORD width,
								 DWORD length,
								 COLORREF * colors);

//�X���b�h�֐�
UINT th(LPVOID p);

//�쐬�摜���쐬�֐�
HBITMAP & CreateCalcBitmap_Colors1(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors2(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);
HBITMAP & CreateCalcBitmap_Colors3(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp);

//Bitmap��Color�o�b�t�@�ɐ���`��
void SetBitmapColor_Line(COLORREF * colors,			//�F�o�b�t�@
								 DWORD width,					//�F�o�b�t�@�̕�
								 DWORD length,					//�F�o�b�t�@�̍���
								 CRect rect,					//���̈ʒu
								 COLORREF setcolor,			//���̐F
								 bool width_first=FALSE);	//���D��

//Bitmap��Color�o�b�t�@�ɒ����`��`��
void SetBitmapColor_RectBk(COLORREF * colors,			//�F�o�b�t�@
									DWORD width,					//�F�o�b�t�@�̕�
									DWORD length,					//�F�o�b�t�@�̍���
									CRect rect,						//�����`�̈ʒu
									COLORREF setcolor);			//�����`�̐F

//Bitmap��Color�o�b�t�@�ɒ����`�̘g��`��
void SetBitmapColor_RectLine(COLORREF * colors,			//�F�o�b�t�@
									DWORD width,					//�F�o�b�t�@�̕�
									DWORD length,					//�F�o�b�t�@�̍���
									CRect rect,						//�����`�̘g�̈ʒu
									COLORREF setcolor);			//�����`�̘g�̐F

//���j�^�[�Ή��ő�l�i���g�p�j
#define MAX_MONITOR_NUM	8

#include <AFXPRIV.H>
#include <fstream.H>


#endif 