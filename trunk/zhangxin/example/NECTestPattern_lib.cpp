#include "StdAfx.h"
/*
#ifdef _NECTESTPATTERN_LIB_CPP
#define _NECTESTPATTERN_LIB_CPP

*/
#include "NECTestPattern_LIB.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

ULONG_PTR gdiplusToken;

CTestPatternDlg ** TestDlg=NULL;
CSetTestPatternDlg ** TestSetDlg=NULL;
CNECTestPatternDlg * SetDlg=NULL;

//�摜�\����ʏ�����
void setprosize(CWnd* pdlg,						//�_�C�A���O
					 XYandWH display_size,			//���j�^�[�ʒu�i����p�̈ʒu�A���A�����j
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 char * filename,					//�摜�t�@�C�����O
					 bool Resize,						//�摜�\�������F�T�C�Y�ω�
					 bool Center)						//�摜�\�������F�^�񒆕\��
{

	HWND hWnd=*pdlg;//HWND_TOPMOST//HWND_NOTOPMOST
	::SetWindowPos(hWnd,
		HWND_TOP ,
		display_size.x0,
		display_size.y0,
		display_size.width,
		display_size.height,
		SWP_SHOWWINDOW);
	CStatic *pwnd;
	pwnd=(CStatic *)pdlg->GetDlgItem(nID);

	//�����\����ݒ�
	if(Center)
	{
		pwnd->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);// |SS_REALSIZEIMAGE  
	}
	else
	{
		pwnd->ModifyStyle(0xF,SS_BITMAP);// |SS_REALSIZEIMAGE  
	}

	//�摜�T�C�Y��s�ϊ�
	if(!Resize)
		pwnd->MoveWindow(0,
		0,
		display_size.width,
		display_size.height);

	HBITMAP hbmp;

	//Bitmap�N���X��GDIPLUS.h�̃����o�[
	USES_CONVERSION;
	Bitmap bmp(A2W(filename));
   Color backColor;
	bmp.GetHBITMAP(backColor,&hbmp);

	pwnd->SetBitmap(hbmp);
//	::DeleteObject(hbmp);
	
	//�摜�T�C�Y��ϊ�
	if(Resize)
		pwnd->MoveWindow(0,
		0,
		display_size.width,
		display_size.height);
	pwnd->RedrawWindow();
	pdlg->EnableWindow();
}
/*
Bitmap * CreateRotateBitmap(Bitmap * pBitmap,
							 IN REAL angle,
							 IN MatrixOrder order = MatrixOrderAppend)
{

	Bitmap * pTemp_in = new Bitmap(pBitmap->GetWidth(),
											pBitmap->GetHeight(),
											pBitmap->GetPixelFormat());
	if( !pTemp_in)
	{
		return NULL;
	}
	Graphics * g_in = Graphics::FromImage(pTemp_in);
	if( !g_in)
	{
		delete pTemp_in;
		return NULL;
	}
//	g_in->SetInterpolationMode(InterpolationModeHighQualityBicubic);
	g_in->DrawImage(pBitmap,0,0,pBitmap->GetWidth(),pBitmap->GetHeight());
	g_in->RotateTransform(angle,order);
	return pTemp_in;
	DWORD Height=pTemp_in->GetHeight(),Width=pTemp_in->GetWidth();

	Bitmap * pTemp_out = new Bitmap(Width,Height,pBitmap->GetPixelFormat());
	if( !pTemp_out)
	{
		delete pTemp_in;
		delete g_in;
		return NULL;
	}

	Graphics * g_out = Graphics::FromImage(pTemp_out);
	if(!g_out)
	{	
		delete pTemp_in;
		delete pTemp_out;
		delete g_in;
		return NULL;
	}

	g_out->SetInterpolationMode(InterpolationModeHighQualityBicubic);
//	g->Clear(Color.White);
	g_out->DrawImage(pTemp_in,0,0,Width,Height);
	g_out->DrawEllipse(new Pen(Color.Blue, 3), 0, 0, 200, 80);
	g_out->RotateTransform(90, MatrixOrderAppend);

	if(pTemp_in)
		delete pTemp_in;
//	if(pTemp_out)
		delete pTemp_out;
	if(g_in)
		delete g_in;
	if(g_out)
		delete g_out;
	return pTemp_out;
}
*/

void setprosize(CWnd* pdlg,						//�_�C�A���O
					 XYandWH display_size,			//���j�^�[�ʒu�i����p�̈ʒu�A���A�����j
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 HBITMAP hBitmap,					//�摜�n���h
					 bool Resize,						//�摜�\�������F�T�C�Y�ω�
					 bool Center)						//�摜�\�������F�^�񒆕\��
{

	HWND hWnd=*pdlg;//HWND_TOPMOST//HWND_NOTOPMOST
	::SetWindowPos(hWnd,
		HWND_TOP ,
		display_size.x0,
		display_size.y0,
		display_size.width,
		display_size.height,
		SWP_SHOWWINDOW);
	CStatic *pwnd;
	pwnd=(CStatic *)pdlg->GetDlgItem(nID);

	//�����\����ݒ�
	if(Center)
	{
		pwnd->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);// |SS_REALSIZEIMAGE  
	}
	else
	{
		pwnd->ModifyStyle(0xF,SS_BITMAP);// |SS_REALSIZEIMAGE  
	}

	//�摜�T�C�Y��s�ϊ�
	if(!Resize)
		pwnd->MoveWindow(0,
		0,
		display_size.width,
		display_size.height);
	pwnd->SetBitmap(hBitmap);
//	::DeleteObject(hBitmap);
	
	//�摜�T�C�Y��ϊ�
	if(Resize)
		pwnd->MoveWindow(0,
		0,
		display_size.width,
		display_size.height);

	pwnd->RedrawWindow();
	pdlg->EnableWindow();
}

void setprosize(CWnd* pdlg,						//�_�C�A���O
					 XYandWH display_size,			//���j�^�[�ʒu�i����p�̈ʒu�A���A�����j
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 int bmpID,							//�r�b�g�}�b�vID
					 bool Resize,						//�摜�\�������F�T�C�Y�ω�
					 bool Center)						//�摜�\�������F�^�񒆕\��
{

	HWND hWnd=*pdlg;//HWND_TOPMOST
	::SetWindowPos(hWnd,
		HWND_TOP ,
		display_size.x0,
		display_size.y0,
		display_size.width,
		display_size.height,
		SWP_SHOWWINDOW);
	CStatic *pwnd;
	pwnd=(CStatic *)pdlg->GetDlgItem(nID);

	//�����\����ݒ�
	if(Center)
	{
		pwnd->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);// |SS_REALSIZEIMAGE  
	}
	else
	{
		pwnd->ModifyStyle(0xF,SS_BITMAP);// |SS_REALSIZEIMAGE  
	}

	//�摜�T�C�Y��s�ϊ�
	if(!Resize)
		pwnd->MoveWindow(0,
		0,
		display_size.width,
		display_size.height);

	HBITMAP hbmp;
	hbmp = (HBITMAP)::LoadBitmap( AfxGetInstanceHandle(),MAKEINTRESOURCE(bmpID));
	pwnd->SetBitmap(hbmp);
//	::DeleteObject(hbmp);

	//�摜�T�C�Y��ϊ�
	if(Resize)
		pwnd->MoveWindow(0,
		0,
		display_size.width,
		display_size.height);
	pwnd->RedrawWindow();
	pdlg->EnableWindow();

}

void SetBitmapBoxSize(CWnd* pdlg,				//�_�C�A���O
							 XYandWH display_size,	//���j�^�[�ʒu�i����p�̈ʒu�A���A�����j
							 int nID,					//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
							 HBITMAP hBmp,				//�摜�n���h
							 bool Resize)				//�摜�\�������F�T�C�Y�ω�
{

	CStatic *pwnd=(CStatic *)pdlg->GetDlgItem(nID);

	//�����\����ݒ�
	if(Resize)
	{
		pwnd->ModifyStyle(0xF,SS_BITMAP);// |SS_REALSIZEIMAGE  
	}

	//�摜�T�C�Y��s�ϊ�
	if(!Resize)
		pwnd->MoveWindow(display_size.x0,
		display_size.y0,
		display_size.width,
		display_size.height);
	pwnd->SetBitmap(hBmp);

	//�摜�T�C�Y��ϊ�
	if(Resize)
		pwnd->MoveWindow(display_size.x0,
		display_size.y0,
		display_size.width,
		display_size.height);
	pwnd->RedrawWindow();
}

void setprosize(CWnd* pdlg,						//�_�C�A���O
					 CRect display_rect,				//���j�^�[�ʒu
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 HBITMAP hBitmap,					//�摜�n���h
					 bool Resize,						//�摜�\�������F�T�C�Y�ω�
					 bool Center)						//�摜�\�������F�^�񒆕\��
{
	setprosize(pdlg,
		XYandWH(display_rect.left,
		display_rect.top,
		display_rect.Width(),
		display_rect.Height()),
		nID,
		hBitmap,
		Resize,
		Center);
}

void setprosize(CWnd* pdlg,						//�_�C�A���O
					 CRect display_rect,				//���j�^�[�ʒu
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 char * filename,					//�摜�t�@�C�����O
					 bool Resize,						//�摜�\�������F�T�C�Y�ω�
					 bool Center)						//�摜�\�������F�^�񒆕\��
{
	setprosize(pdlg,
		XYandWH(display_rect.left,
		display_rect.top,
		display_rect.Width(),
		display_rect.Height()),
		nID,
		filename,
		Resize,
		Center);
}

void setprosize(CWnd* pdlg,						//�_�C�A���O
					 CRect display_rect,				//���j�^�[�ʒu
					 int nID,							//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
					 int bmpID,							//�r�b�g�}�b�vID
					 bool Resize,						//�摜�\�������F�T�C�Y�ω�
					 bool Center)						//�摜�\�������F�^�񒆕\��
{
	setprosize(pdlg,
		XYandWH(display_rect.left,
		display_rect.top,
		display_rect.Width(),
		display_rect.Height()),
		nID,bmpID,
		Resize,
		Center);
}

void SetBitmapBoxSize(CWnd* pdlg,				//�_�C�A���O
							 CRect display_rect,		//���j�^�[�ʒu
							 int nID,					//�摜�i�r�b�g�}�b�v�j�{�b�N�X��ID
							 HBITMAP hBmp,				//�摜�n���h
							 bool Resize)				//�摜�\�������F�T�C�Y�ω�
{
	SetBitmapBoxSize(pdlg,
		XYandWH(display_rect.left,
		display_rect.top,
		display_rect.Width(),
		display_rect.Height()),
		nID,
		hBmp,
		Resize);
}

//�r�b�g�}�b�v�̃n���h���쐬�֐�
HBITMAP & CreateNewHBitmap(int bmpID,HBITMAP & hBmp)
{
	hBmp = (HBITMAP)::LoadBitmap( AfxGetInstanceHandle(),MAKEINTRESOURCE(bmpID));
	return hBmp;
}


//���m�N���p�摜��\�����邽�߂ɁA�ꎞ�摜���쐬����֐�
HBITMAP & CreateNewHBitmap_GrayScale_to_RGB(char * filename,HBITMAP & hBmp)
{

	DWORD width=0,length=0;

	COLORREF * colors=NULL;
	unsigned short int * buf_temp=NULL;
	if(ReadGrayScaleFileToColor(filename,width,length,&colors,&buf_temp))
		return hBmp=0;

	//�ꎞ�t�@�C�����쐬
	strcpy(namebeg,"temp.dat");
	CreateNewBitmapFile(filepath,width,length,colors);

	USES_CONVERSION;
	Bitmap bmp1(A2W(filepath));
	Color backColor;
	bmp1.GetHBITMAP(backColor,&hBmp);
	SetDlg->selectfilename=filepath;

	delete [] buf_temp;
	delete [] colors;
	return hBmp;
}

//��[�F�̉摜���쐬�֐�
HBITMAP & CreateNewHBitmap_BK(COLORREF in_color,
										HBITMAP & hBmp)
{

	strcpy(namebeg,"temp_bk.dat");
	CreateNewBitmapFile(filepath,1,1,&in_color);

	USES_CONVERSION;
	Bitmap bmp1(A2W(filepath));
   Color backColor;
	bmp1.GetHBITMAP(backColor,&hBmp);

	return hBmp;
}

//��[�F�̉摜���쐬�֐�
HBITMAP & CreateNewHBitmap_SELCOLOR(COLORREF in_color,
												HBITMAP & hBmp)
{

	strcpy(namebeg,"temp_col.dat");
	CreateNewBitmapFile(filepath,1,1,&in_color);

	USES_CONVERSION;
	Bitmap bmp1(A2W(filepath));
   Color backColor;
	bmp1.GetHBITMAP(backColor,&hBmp);

	return hBmp;
}

HBITMAP & CreateNewHBitmap_Calc(COLORREF * in_color,
										  DWORD width,
										  DWORD length,
										  HBITMAP & hBmp)
{

	strcpy(namebeg,"temp_Calc.dat");
	CreateNewBitmapFile(filepath,width,length,in_color);

	USES_CONVERSION;
	Bitmap bmp1(A2W(filepath));
   Color backColor;
	bmp1.GetHBITMAP(backColor,&hBmp);

	return hBmp;
}

HBITMAP & CreateNewHBitmap(char * filename,HBITMAP & hBmp)
{
	//���ʂȉ摜�t�@�C��
	hBmp=0;
	USES_CONVERSION;
	Bitmap bmp(A2W(filename));
   Color backColor;
	bmp.GetHBITMAP(backColor,&hBmp);
	SetDlg->selectfilename=filename;
	
	//���m�N���̉摜����
	if(hBmp==0)
	{
		hBmp=CreateNewHBitmap_GrayScale_to_RGB(filename,hBmp);
	}

	//�摜�t�@�C���ǂݍ��ގ��s
	if(hBmp==0)
	{
		hBmp=CreateNewHBitmap(IDB_BITMAP_PREVIEW,hBmp);
		SetDlg->selectfilename=NULL;
		NECAfxMessageBox(IDS_ERR_PATTERNFILE);
	}
	return hBmp;
}

//�X���b�h�֐�
//�e���j�^�[�\������Ƃ��A���j�^�[��M��
UINT th(LPVOID p)
{

	CSetTestPatternDlg * SetDlg=(CSetTestPatternDlg *)p;
	int sat=2;
	for(int time_count=0;time_count<sat*2;time_count++)
	{
		switch(time_count%sat)
		{
			default:
			case 0:
//				SetDlg->SetRemindDlg->ShowWindow(SW_HIDE);
//				break;
//			case 1:
				SetDlg->SetRemindDlg->ShowWindow(SW_SHOW);
				SetDlg->SetRemindDlg->GetDlgItem(IDC_STATIC_REMIND1)->ShowWindow(SW_SHOW);
				SetDlg->SetRemindDlg->GetDlgItem(IDC_STATIC_REMIND2)->ShowWindow(SW_HIDE);
				break;
			case 1:
				SetDlg->SetRemindDlg->ShowWindow(SW_SHOW);
				SetDlg->SetRemindDlg->GetDlgItem(IDC_STATIC_REMIND2)->ShowWindow(SW_SHOW);
				SetDlg->SetRemindDlg->GetDlgItem(IDC_STATIC_REMIND1)->ShowWindow(SW_HIDE);
				break;
		}
		Sleep(400);
	}
	SetDlg->SetRemindDlg->ShowWindow(SW_HIDE);
	if(SetDlg->win_show_sta==true)
		::SetForegroundWindow(SetDlg->m_hWnd);

	return 0;
}

//�쐬�摜���쐬�֐�
HBITMAP & CreateCalcBitmap_Colors1(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp)
{
	DWORD width=monitor_Rect.Width();
	DWORD length=monitor_Rect.Height();
	DWORD size=width*length;
	colors=new  COLORREF[size];


	SetBitmapColor_RectLine(colors,width,length,CRect(0,0,width-1,length-1),RGB(255,255,255));
	SetBitmapColor_RectLine(colors,width,length,CRect(1,1,width-2,length-2),RGB(255,255,255));
	SetBitmapColor_RectLine(colors,width,length,CRect(2,2,width-3,length-3),RGB(255,255,255));

	SetBitmapColor_RectLine(colors,width,length,CRect(3,3,width-4,length-4),RGB(0,0,0));
	SetBitmapColor_RectLine(colors,width,length,CRect(4,4,width-5,length-5),RGB(0,0,0));

	SetBitmapColor_RectBk(colors,width,length,CRect(5,5,width-5,40),RGB(0,0,0));
	SetBitmapColor_RectBk(colors,width,length,CRect(5,length-40,width-5,length-5),RGB(0,0,0));

	SetBitmapColor_RectBk(colors,width,length,

		CRect(5,
		40,
		5+(width-10)/4+1,
		40+(length-80)/3+1),

		RGB(0,0,255));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(5,
		length-41-(length-80)/3,
		5+(width-10)/4+1,
		length-40),

		RGB(255,0,0));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(width-6-(width-10)/4,
		length-41-(length-80)/3,
		width-5,
		length-40),
		
		RGB(0,255,0));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(width-6-(width-10)/4,
		40,
		width-5,
		40+(length-80)/3+1),
		
		RGB(0,0,0));
	SetBitmapColor_RectLine(colors,width,length,

		CRect(width-6-(width-10)/4,
		40,
		width-5-1,
		40+(length-80)/3),
		
		RGB(255,255,255));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(5+(width-10)/4+1,
		40,
		width-6-(width-10)/4,
		40+(length-80)/3+1),
		
		RGB(255,255,255));
//	SetBitmapColor_RectBk(colors,width,length,CRect(5,5,width-5,5+35),RGB(0,0,0));
//	SetBitmapColor_RectBk(colors,width,length,CRect(5,length-40,width-5,length-5),RGB(0,0,0));
//	SetBitmapColor_RectBk(colors,width,length,CRect(5,length-40,width-5,length-5),RGB(0,0,0));
//	length-40*2/3
	DWORD i;
	DWORD rect_cun=16-1;
	for(i=0;i<rect_cun+1;i++)
	{
		SetBitmapColor_RectBk(colors,width,length,

			CRect(5+(width-10)/4+1+(width-10)*i/2/(rect_cun+1),
			length-41-(length-80)/3,
			5+(width-10)/4+1+(width-10)/2*(i+1)/(rect_cun+1),
			length-40),
			
			RGB(255*i/rect_cun,255*i/rect_cun,255*i/rect_cun));
	}
//	SetBitmapColor_RectBk(colors,width,length,CRect(0,0,width/2,length),RGB(0,255,0));
//	SetBitmapColor_RectBk(colors,width,length,CRect(width/2,0,width,length),RGB(0,0,255));
//	SetBitmapColor_RectLine(colors,width,length,CRect(0,0,width-1,length-1),RGB(0,255,255));
	for(i=0;i<width-10;i+=2)
	{
		SetBitmapColor_Line(colors,width,length,CRect(i+5,41+(length-80)/3,i+5,41+(length-80)/3*2),RGB(255,255,255));
		SetBitmapColor_Line(colors,width,length,CRect(i+6,41+(length-80)/3,i+6,41+(length-80)/3*2),RGB(0,0,0));
	}
	CreateNewHBitmap_Calc(colors,width,length,hBmp);
	return hBmp;
}

//�쐬�摜���쐬�֐�
HBITMAP & CreateCalcBitmap_Colors2(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp)
{
	DWORD width=monitor_Rect.Width();
	DWORD length=monitor_Rect.Height();
	DWORD size=width*length;
	colors=new  COLORREF[size];


	SetBitmapColor_RectLine(colors,width,length,CRect(0,0,width-1,length-1),RGB(255,255,255));
	SetBitmapColor_RectLine(colors,width,length,CRect(1,1,width-2,length-2),RGB(255,255,255));
	SetBitmapColor_RectLine(colors,width,length,CRect(2,2,width-3,length-3),RGB(255,255,255));

	SetBitmapColor_RectLine(colors,width,length,CRect(3,3,width-4,length-4),RGB(0,0,0));
	SetBitmapColor_RectLine(colors,width,length,CRect(4,4,width-5,length-5),RGB(0,0,0));

	SetBitmapColor_RectBk(colors,width,length,CRect(5,5,40,length-5),RGB(0,0,0));
	SetBitmapColor_RectBk(colors,width,length,CRect(width-40,5,width-5,length-5),RGB(0,0,0));

	SetBitmapColor_RectBk(colors,width,length,

		CRect(width-41-(width-80)/3,
		5,
		width-40,
		5+(length-10)/4+1),

		RGB(0,255,0));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(width-41-(width-80)/3,
		length-6-(length-10)/4,		
		width-40,
		length-5),
		
		RGB(255,0,0));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(40,
		length-6-(length-10)/4,		
		40+(width-80)/3+1,
		length-5),
		
		RGB(0,0,255));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(40,
		5,
		40+(width-80)/3+1,
		5+(length-10)/4+1),

		RGB(0,0,0));
	SetBitmapColor_RectLine(colors,width,length,

		CRect(40,
		5,
		40+(width-80)/3,
		5+(length-10)/4),
		
		RGB(255,255,255));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(40,
		5+(length-10)/4+1,		
		40+(width-80)/3+1,
		length-6-(length-10)/4),
		
		RGB(255,255,255));
	DWORD i;
	DWORD rect_cun=16-1;
	for(i=0;i<rect_cun+1;i++)
	{
		SetBitmapColor_RectBk(colors,width,length,

			CRect(width-41-(width-80)/3,
			5+(length-10)/4+1+(length-10)*i/2/(rect_cun+1),			
			width-40,
			5+(length-10)/4+1+(length-10)/2*(i+1)/(rect_cun+1)),
			
			RGB(255*(rect_cun-i)/rect_cun,255*(rect_cun-i)/rect_cun,255*(rect_cun-i)/rect_cun));
	}
	for(i=0;i<length-10;i+=2)
	{
		SetBitmapColor_Line(colors,width,length,CRect(41+(width-80)/3,i+5,41+(width-80)/3*2,i+5),RGB(255,255,255));
		SetBitmapColor_Line(colors,width,length,CRect(41+(width-80)/3,i+6,41+(width-80)/3*2,i+6),RGB(0,0,0));
	}
	CreateNewHBitmap_Calc(colors,width,length,hBmp);
	return hBmp;
}

//�쐬�摜���쐬�֐�
HBITMAP & CreateCalcBitmap_Colors3(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp)
{
	DWORD width=monitor_Rect.Width();
	DWORD length=monitor_Rect.Height();
	DWORD size=width*length;
	colors=new  COLORREF[size];


	SetBitmapColor_RectLine(colors,width,length,CRect(0,0,width-1,length-1),RGB(255,255,255));
	SetBitmapColor_RectLine(colors,width,length,CRect(1,1,width-2,length-2),RGB(255,255,255));
	SetBitmapColor_RectLine(colors,width,length,CRect(2,2,width-3,length-3),RGB(255,255,255));

	SetBitmapColor_RectLine(colors,width,length,CRect(3,3,width-4,length-4),RGB(0,0,0));
	SetBitmapColor_RectLine(colors,width,length,CRect(4,4,width-5,length-5),RGB(0,0,0));

	SetBitmapColor_RectBk(colors,width,length,CRect(5,5,40,length-5),RGB(0,0,0));
	SetBitmapColor_RectBk(colors,width,length,CRect(width-40,5,width-5,length-5),RGB(0,0,0));

	SetBitmapColor_RectBk(colors,width,length,

		CRect(width-41-(width-80)/3,
		5,
		width-40,
		5+(length-10)/4+1),

		RGB(0,0,255));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(40,
		length-6-(length-10)/4,		
		40+(width-80)/3+1,
		length-5),
		
		RGB(0,255,0));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(40,
		5,
		40+(width-80)/3+1,
		5+(length-10)/4+1),

		RGB(255,0,0));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(width-41-(width-80)/3,
		length-6-(length-10)/4,		
		width-40,
		length-5),
		
		RGB(0,0,0));
	SetBitmapColor_RectLine(colors,width,length,

		CRect(width-39-(width-80)/3,
		length-6-(length-10)/4,		
		width-41,
		length-6),
		
		RGB(255,255,255));
	SetBitmapColor_RectBk(colors,width,length,

		CRect(width-41-(width-80)/3,
		5+(length-10)/4+1,		
		width-40,
		length-6-(length-10)/4),
		
		RGB(255,255,255));
	DWORD i;
	DWORD rect_cun=16-1;
	for(i=0;i<rect_cun+1;i++)
	{
		SetBitmapColor_RectBk(colors,width,length,

			CRect(40,
			5+(length-10)/4+1+(length-10)*i/2/(rect_cun+1),			
			40+(width-80)/3+1,
			5+(length-10)/4+1+(length-10)/2*(i+1)/(rect_cun+1)),
			
			RGB(255*i/rect_cun,255*i/rect_cun,255*i/rect_cun));
	}
	for(i=0;i<length-10;i+=2)
	{
		SetBitmapColor_Line(colors,width,length,CRect(41+(width-80)/3,i+5,41+(width-80)/3*2,i+5),RGB(255,255,255));
		SetBitmapColor_Line(colors,width,length,CRect(41+(width-80)/3,i+6,41+(width-80)/3*2,i+6),RGB(0,0,0));
	}
	CreateNewHBitmap_Calc(colors,width,length,hBmp);
	return hBmp;
}

//Bitmap��Color�o�b�t�@�ɐ���`��
void SetBitmapColor_Line(COLORREF * colors,			//�F�o�b�t�@
								 DWORD width,					//�F�o�b�t�@�̕�
								 DWORD length,					//�F�o�b�t�@�̍���
								 CRect rect,					//���̈ʒu
								 COLORREF setcolor,			//���̐F
								 bool width_first)			//���D��
{

	DWORD deta_w=( (DWORD)rect.right<width?rect.Width():(width-rect.left) );
	DWORD deta_h=( (DWORD)rect.bottom<length?rect.Height():(length-rect.top) );

	DWORD deta_Cunst=deta_h>deta_w&&width_first==FALSE?deta_h:deta_w;
	if(deta_Cunst<=0||deta_w<0||deta_h<0)
	{
		return;
	}

	DWORD begin=rect.top*width+rect.left;
	if(begin>=width*length)
		return;
	for(DWORD i=0;i<deta_Cunst;i++)
	{
		colors[begin+(deta_h>deta_w&&width_first==FALSE?i*width:i)]=setcolor;
	}
}

//Bitmap��Color�o�b�t�@�ɒ����`��`��
void SetBitmapColor_RectBk(COLORREF * colors,			//�F�o�b�t�@
									DWORD width,					//�F�o�b�t�@�̕�
									DWORD length,					//�F�o�b�t�@�̍���
									CRect rect,						//�����`�̈ʒu
									COLORREF setcolor)			//�����`�̐F
{

	DWORD deta_w=( (DWORD)rect.right<width?rect.Width():(width-rect.left) );
	DWORD deta_h=( (DWORD)rect.bottom<length?rect.Height():(length-rect.top) );

	if(deta_w<=0||deta_h<=0)
	{
		return;
	}
	SetBitmapColor_Line(colors,width,length,rect,setcolor,true);
	DWORD deta_Cunst=deta_h;

	DWORD begin=rect.top*width+rect.left;
	if(begin>=width*length)
		return;

	for(DWORD i=1;i<deta_Cunst;i++)
	{
		memcpy(&colors[begin+i*width],&colors[begin],deta_w*sizeof(COLORREF));
	}
}

//Bitmap��Color�o�b�t�@�ɒ����`�̘g��`��
void SetBitmapColor_RectLine(COLORREF * colors,			//�F�o�b�t�@
									DWORD width,					//�F�o�b�t�@�̕�
									DWORD length,					//�F�o�b�t�@�̍���
									CRect rect,						//�����`�̘g�̈ʒu
									COLORREF setcolor)			//�����`�̘g�̐F
{

	DWORD deta_w=( (DWORD)rect.right<width?rect.Width():(width-rect.left) );
	DWORD deta_h=( (DWORD)rect.bottom<length?rect.Height():(length-rect.top) );

	if(deta_w<=0||deta_h<=0)
	{
		return;
	}
	SetBitmapColor_Line(colors,width,length,CRect(rect.left,rect.top,rect.right,rect.top),setcolor);
	SetBitmapColor_Line(colors,width,length,CRect(rect.left,rect.bottom,rect.right+1,rect.bottom),setcolor);

	SetBitmapColor_Line(colors,width,length,CRect(rect.right,rect.top,rect.right,rect.bottom+1),setcolor);
	SetBitmapColor_Line(colors,width,length,CRect(rect.left,rect.top,rect.left,rect.bottom),setcolor);
}

//�r�b�g�}�b�v�t�@�C�����쐬�֐�
void CreateNewBitmapFile(char * filename,
								 DWORD width,
								 DWORD length,
								 COLORREF * colors){
	char *temp=new char [strlen(filepath)+1];
	strcpy(temp,filepath);
	temp[namebeg-filepath]=0;
	CreateDirectory(temp,0);
	delete [] temp;
	CreateBitmapFile(filepath,width,length,colors);
}

//#endif
