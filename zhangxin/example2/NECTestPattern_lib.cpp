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

int Count=0;
CTestPatternDlg ** TestDlg=NULL;
CSetTestPatternDlg ** TestSetDlg=NULL;
CNECTestPatternDlg * SetDlg=NULL;
char filepath[MAX_PATH];
char my_name[MAX_PATH];
char * namebeg=NULL;


void setprosize(CWnd* pdlg,XYandWH display_size,int nID,char * filename,bool Resize,bool Center){

	HWND hWnd=*pdlg;//HWND_TOPMOST//HWND_NOTOPMOST
	::SetWindowPos(hWnd,HWND_TOP ,display_size.x0,display_size.y0,display_size.width,display_size.height,SWP_SHOWWINDOW);
	CStatic *pwnd;
	pwnd=(CStatic *)pdlg->GetDlgItem(nID);

	if(Center){
		pwnd->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);// |SS_REALSIZEIMAGE  
	}else{
		pwnd->ModifyStyle(0xF,SS_BITMAP);// |SS_REALSIZEIMAGE  
	}
	if(!Resize)
		pwnd->MoveWindow(0,0,display_size.width,display_size.height);

	HBITMAP hbmp;

	USES_CONVERSION;
	Bitmap bmp(A2W(filename));
   Color backColor;
	bmp.GetHBITMAP(backColor,&hbmp);

	pwnd->SetBitmap(hbmp);
//	::DeleteObject(hbmp);
	
	if(Resize)
		pwnd->MoveWindow(0,0,display_size.width,display_size.height);
	pwnd->RedrawWindow();
	pdlg->EnableWindow();
}
/*
Bitmap * CreateRotateBitmap(Bitmap * pBitmap,
							 IN REAL angle,
							 IN MatrixOrder order = MatrixOrderAppend){

	Bitmap * pTemp_in = new Bitmap(pBitmap->GetWidth(),pBitmap->GetHeight(),pBitmap->GetPixelFormat());
	if( !pTemp_in){
		return NULL;
	}
	Graphics * g_in = Graphics::FromImage(pTemp_in);
	if( !g_in){
		delete pTemp_in;
		return NULL;
	}
//	g_in->SetInterpolationMode(InterpolationModeHighQualityBicubic);
	g_in->DrawImage(pBitmap,0,0,pBitmap->GetWidth(),pBitmap->GetHeight());
	g_in->RotateTransform(angle,order);
	return pTemp_in;
	DWORD Height=pTemp_in->GetHeight(),Width=pTemp_in->GetWidth();

	Bitmap * pTemp_out = new Bitmap(Width,Height,pBitmap->GetPixelFormat());
	if( !pTemp_out){
		delete pTemp_in;
		delete g_in;
		return NULL;
	}

	Graphics * g_out = Graphics::FromImage(pTemp_out);
	if(!g_out){	
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

	if(pTemp_in)	delete pTemp_in;
//	if(pTemp_out)	delete pTemp_out;
	if(g_in)	delete g_in;
	if(g_out)	delete g_out;
	return pTemp_out;
}
*/
void setprosize(CWnd* pdlg,XYandWH display_size,int nID,HBITMAP hBitmap,bool Resize,bool Center){

	HWND hWnd=*pdlg;//HWND_TOPMOST//HWND_NOTOPMOST
	::SetWindowPos(hWnd,HWND_TOP ,display_size.x0,display_size.y0,display_size.width,display_size.height,SWP_SHOWWINDOW);
	CStatic *pwnd;
	pwnd=(CStatic *)pdlg->GetDlgItem(nID);

	if(Center){
		pwnd->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);// |SS_REALSIZEIMAGE  
	}else{
		pwnd->ModifyStyle(0xF,SS_BITMAP);// |SS_REALSIZEIMAGE  
	}
	if(!Resize)
		pwnd->MoveWindow(0,0,display_size.width,display_size.height);
	pwnd->SetBitmap(hBitmap);
//	::DeleteObject(hBitmap);
	
	if(Resize)
		pwnd->MoveWindow(0,0,display_size.width,display_size.height);

	pwnd->RedrawWindow();
	pdlg->EnableWindow();
}

void setprosize(CWnd* pdlg,XYandWH display_size,int nID,int bmpID,bool Resize,bool Center){

	HWND hWnd=*pdlg;//HWND_TOPMOST
	::SetWindowPos(hWnd,HWND_TOP ,display_size.x0,display_size.y0,display_size.width,display_size.height,SWP_SHOWWINDOW);
	CStatic *pwnd;
	pwnd=(CStatic *)pdlg->GetDlgItem(nID);

	if(Center){
		pwnd->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);// |SS_REALSIZEIMAGE  
	}else{
		pwnd->ModifyStyle(0xF,SS_BITMAP);// |SS_REALSIZEIMAGE  
	}
	if(!Resize)
		pwnd->MoveWindow(0,0,display_size.width,display_size.height);

	HBITMAP hbmp;
	hbmp = (HBITMAP)::LoadBitmap( AfxGetInstanceHandle(),MAKEINTRESOURCE(bmpID));
	pwnd->SetBitmap(hbmp);
//	::DeleteObject(hbmp);

	if(Resize)
		pwnd->MoveWindow(0,0,display_size.width,display_size.height);
	pwnd->RedrawWindow();
	pdlg->EnableWindow();

}

void SetBitmapBoxSize(CWnd* pdlg,XYandWH display_size,int nID,HBITMAP hBmp,bool Resize){

	CStatic *pwnd=(CStatic *)pdlg->GetDlgItem(nID);

	if(Resize){
		pwnd->ModifyStyle(0xF,SS_BITMAP);// |SS_REALSIZEIMAGE  
	}
	if(!Resize)
		pwnd->MoveWindow(display_size.x0,display_size.y0,display_size.width,display_size.height);
	pwnd->SetBitmap(hBmp);
	if(Resize)
		pwnd->MoveWindow(display_size.x0,display_size.y0,display_size.width,display_size.height);
	pwnd->RedrawWindow();
}

void setprosize(CWnd* pdlg,CRect display_rect,int nID,HBITMAP hBitmap,bool Resize,bool Center){
	setprosize(pdlg,XYandWH(display_rect.left,display_rect.top,display_rect.Width(),display_rect.Height()),nID,hBitmap,Resize,Center);
}

void setprosize(CWnd* pdlg,CRect display_rect,int nID,char * filename,bool Resize,bool Center){
	setprosize(pdlg,XYandWH(display_rect.left,display_rect.top,display_rect.Width(),display_rect.Height()),nID,filename,Resize,Center);
}

void setprosize(CWnd* pdlg,CRect display_rect,int nID,int bmpID,bool Resize,bool Center){
	setprosize(pdlg,XYandWH(display_rect.left,display_rect.top,display_rect.Width(),display_rect.Height()),nID,bmpID,Resize,Center);
}

void SetBitmapBoxSize(CWnd* pdlg,CRect display_rect,int nID,HBITMAP hBmp,bool Resize){
	SetBitmapBoxSize(pdlg,XYandWH(display_rect.left,display_rect.top,display_rect.Width(),display_rect.Height()),nID,hBmp,Resize);
}

HBITMAP & CreateNewHBitmap(int bmpID,HBITMAP & hBmp){
	hBmp = (HBITMAP)::LoadBitmap( AfxGetInstanceHandle(),MAKEINTRESOURCE(bmpID));
	return hBmp;
}

HBITMAP & CreateNewHBitmap_GrayScale_to_RGB(char * filename,HBITMAP & hBmp){

	DWORD width,length;
	if(filename!=NULL){
		int filelen=strlen(filename);
		char * fileend=&filename[filelen-3];
		if( strcmp(fileend,_T("tif")) ){
			fileend--;
			if( strcmp(fileend,_T("tiff")) ){
				return hBmp=0;
			}
		}
	}

	fstream fin;
	fin.open(filename,1|0x80|0x20,0);
	if(!fin){
		return hBmp=0;
	}
	
	DWORD i,j;
	unsigned char buf[0x400];
	DWORD buf_size=0;
	
	fin.get(buf[0]);
	if(buf[0]==0x4d){
		fin.read(&buf[1],0x300);
		DWORD * t=(DWORD *)&buf[0x1d];
		width=* t-1;
		t=(DWORD *)&buf[0x29];
		length=* t-1;
		buf_size=width*length;
	}else{
		if(buf[0]!=0x49){
			fin.close();
			return hBmp=0;
		}
		fin.read(&buf[1],0x7);
		DWORD * t=(DWORD *)&buf[4];
		buf_size=* t&0xfffffff0;
		buf_size>>=1;
	}
	unsigned short int * buf_temp=new unsigned short int[buf_size];
	unsigned char * ptemp=(unsigned char *)buf_temp;

	fin.read(ptemp,buf_size*2);

	if(buf[0]!=0x4d){
		fin.read(buf,0xb6);
		DWORD * t=(DWORD *)&buf[0xa];
		width=* t;
		t=(DWORD *)&buf[0x16];
		length=* t;
	}

	fin.close();

	COLORREF * colors=new COLORREF[buf_size];
/*	for( j=0;j<length;j++){
		for(i=0;i<width;i++){
			unsigned short int t=buf_temp[(length-1-j)*width+i]>>4;
			colors[(j*width+i)]=RGB(t,t,t);
		}
	}
*/
	for( j=0;j<length;j++){
		for(i=0;i<width;i++){
			unsigned short int t=buf_temp[(j*width+i)]>>4;
			colors[(j*width+i)]=RGB(t,t,t);
		}
	}

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

int GetWindowLeftWidth(CWnd * pWnd){
	CRect rectWnd;
	CRect rectCli;
	pWnd->GetClientRect(&rectCli);
	pWnd->GetWindowRect(&rectWnd);
	return ((rectWnd.Width()-rectCli.Width())>>1);
}

int GetWindowUpWidth(CWnd * pWnd){
	CRect rectWnd;
	CRect rectCli;
	pWnd->GetClientRect(&rectCli);
	pWnd->GetWindowRect(&rectWnd);
	return (rectWnd.Height()-rectCli.Height()-GetWindowDownWidth(pWnd));
}

void GetDlgItemXYandWH(CWnd * pWnd,int nID,XYandWH & retXYandWH){
	CWnd* pItem=pWnd->GetDlgItem(nID);
	CRect rectItem;
	CRect rectWnd;
	CRect rectCli;
	pWnd->GetClientRect(&rectCli);
	pWnd->GetWindowRect(&rectWnd);
	pItem->GetWindowRect(&rectItem);
	retXYandWH.x0=rectItem.left-rectWnd.left-GetWindowLeftWidth(pWnd);
	retXYandWH.y0=rectItem.top-rectWnd.top-GetWindowUpWidth(pWnd);
	retXYandWH.width=rectItem.Width();
	retXYandWH.height=rectItem.Height();
}

HBITMAP & CreateNewHBitmap_BK(COLORREF in_color,HBITMAP & hBmp){

	strcpy(namebeg,"temp_bk.dat");
	CreateNewBitmapFile(filepath,1,1,&in_color);

	USES_CONVERSION;
	Bitmap bmp1(A2W(filepath));
   Color backColor;
	bmp1.GetHBITMAP(backColor,&hBmp);
//	SetDlg->selectfilename=filepath;

	return hBmp;
}

HBITMAP & CreateNewHBitmap_SELCOLOR(COLORREF in_color,HBITMAP & hBmp){

	strcpy(namebeg,"temp_col.dat");
	CreateNewBitmapFile(filepath,1,1,&in_color);

	USES_CONVERSION;
	Bitmap bmp1(A2W(filepath));
   Color backColor;
	bmp1.GetHBITMAP(backColor,&hBmp);

	return hBmp;
}

HBITMAP & CreateNewHBitmap_Calc(COLORREF * in_color,DWORD width,DWORD length,HBITMAP & hBmp){

	strcpy(namebeg,"temp_Calc.dat");
	CreateNewBitmapFile(filepath,width,length,in_color);

	USES_CONVERSION;
	Bitmap bmp1(A2W(filepath));
   Color backColor;
	bmp1.GetHBITMAP(backColor,&hBmp);

	return hBmp;
}

void CreateNewBitmapFile(char * filename,DWORD width,DWORD length,COLORREF * colors_in){

	BYTE * colors_new=new BYTE[width*length*3];
	BYTE * colors_in_B=(BYTE *)colors_in;
	
	for(DWORD j=0;j<length;j++){
		for(DWORD i=0;i<width;i++){
			colors_new[(j*width+i)*3]		=colors_in_B[((length-1-j)*width+i)*4+2];
			colors_new[(j*width+i)*3+1]	=colors_in_B[((length-1-j)*width+i)*4+1];
			colors_new[(j*width+i)*3+2]	=colors_in_B[((length-1-j)*width+i)*4];
		}
	}
/*	for(DWORD i=0,j=0;i<width*length*3;i+=3,j+=4){
		colors_new[i]=colors_in_B[j+2];
		colors_new[i+1]=colors_in_B[j+1];
		colors_new[i+2]=colors_in_B[j];
		//RGB->BGR
	}
*/	
	BITMAPINFOHEADER bi;
	bi.biWidth=width;
	bi.biHeight=length;
	bi.biSize=sizeof(BITMAPINFOHEADER);
	bi.biPlanes=1;
	bi.biBitCount=24;
	bi.biCompression=BI_RGB;
	bi.biSizeImage=(width%4?width/4*4+4:width)*length;
	bi.biXPelsPerMeter=300;
	bi.biYPelsPerMeter=300;
	bi.biClrUsed=0;
	bi.biClrImportant=0;

	BITMAPFILEHEADER bf;
	bf.bfType=0x4D42;
	bf.bfSize=sizeof(bf)+sizeof(bi)+bi.biHeight*bi.biWidth*bi.biBitCount/8;
	bf.bfOffBits=sizeof(BITMAPFILEHEADER)+sizeof(bi);
	bf.bfReserved1=0;
	bf.bfReserved2=0;

	fstream fout;
	fout.open(filename,2|0x80|0x10,0);

	fout.write((LPSTR)&bf,sizeof(bf));
	fout.write((LPSTR)&bi,sizeof(bi));
	fout.write((LPSTR)colors_new,bf.bfSize-sizeof(bf)-sizeof(bi));
	fout.close();
	delete [] colors_new;
}

HBITMAP & CreateNewHBitmap(char * filename,HBITMAP & hBmp){
	hBmp=0;
	USES_CONVERSION;
	Bitmap bmp(A2W(filename));
   Color backColor;
	bmp.GetHBITMAP(backColor,&hBmp);
	SetDlg->selectfilename=filename;
	if(hBmp==0){
		hBmp=CreateNewHBitmap_GrayScale_to_RGB(filename,hBmp);
	}
	if(hBmp==0){
		hBmp=CreateNewHBitmap(IDB_BITMAP_PREVIEW,hBmp);
		SetDlg->selectfilename=NULL;
		NECAfxMessageBox(IDS_ERR_PATTERNFILE);
	}
	return hBmp;
}

UINT th(LPVOID p){

	CSetTestPatternDlg * SetDlg=(CSetTestPatternDlg *)p;
	int sat=2;
	for(int time_count=0;time_count<sat*2;time_count++){
		switch(time_count%sat){
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

HBITMAP & CreateCalcBitmap_Colors1(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp){
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
	for(i=0;i<rect_cun+1;i++){
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
	for(i=0;i<width-10;i+=2){
		SetBitmapColor_Line(colors,width,length,CRect(i+5,41+(length-80)/3,i+5,41+(length-80)/3*2),RGB(255,255,255));
		SetBitmapColor_Line(colors,width,length,CRect(i+6,41+(length-80)/3,i+6,41+(length-80)/3*2),RGB(0,0,0));
	}
	CreateNewHBitmap_Calc(colors,width,length,hBmp);
	return hBmp;
}

HBITMAP & CreateCalcBitmap_Colors2(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp){
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
	for(i=0;i<rect_cun+1;i++){
		SetBitmapColor_RectBk(colors,width,length,

			CRect(width-41-(width-80)/3,
			5+(length-10)/4+1+(length-10)*i/2/(rect_cun+1),			
			width-40,
			5+(length-10)/4+1+(length-10)/2*(i+1)/(rect_cun+1)),
			
			RGB(255*(rect_cun-i)/rect_cun,255*(rect_cun-i)/rect_cun,255*(rect_cun-i)/rect_cun));
	}
	for(i=0;i<length-10;i+=2){
		SetBitmapColor_Line(colors,width,length,CRect(41+(width-80)/3,i+5,41+(width-80)/3*2,i+5),RGB(255,255,255));
		SetBitmapColor_Line(colors,width,length,CRect(41+(width-80)/3,i+6,41+(width-80)/3*2,i+6),RGB(0,0,0));
	}
	CreateNewHBitmap_Calc(colors,width,length,hBmp);
	return hBmp;
}

HBITMAP & CreateCalcBitmap_Colors3(COLORREF * colors,CRect monitor_Rect,HBITMAP & hBmp){
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
	for(i=0;i<rect_cun+1;i++){
		SetBitmapColor_RectBk(colors,width,length,

			CRect(40,
			5+(length-10)/4+1+(length-10)*i/2/(rect_cun+1),			
			40+(width-80)/3+1,
			5+(length-10)/4+1+(length-10)/2*(i+1)/(rect_cun+1)),
			
			RGB(255*i/rect_cun,255*i/rect_cun,255*i/rect_cun));
	}
	for(i=0;i<length-10;i+=2){
		SetBitmapColor_Line(colors,width,length,CRect(41+(width-80)/3,i+5,41+(width-80)/3*2,i+5),RGB(255,255,255));
		SetBitmapColor_Line(colors,width,length,CRect(41+(width-80)/3,i+6,41+(width-80)/3*2,i+6),RGB(0,0,0));
	}
	CreateNewHBitmap_Calc(colors,width,length,hBmp);
	return hBmp;
}

void SetBitmapColor_Line(COLORREF * colors,DWORD width,DWORD length,CRect rect,COLORREF setcolor,bool width_first){
	DWORD deta_w=( (DWORD)rect.right<width?rect.Width():(width-rect.left) );
	DWORD deta_h=( (DWORD)rect.bottom<length?rect.Height():(length-rect.top) );

	DWORD deta_Cunst=deta_h>deta_w&&width_first==FALSE?deta_h:deta_w;
	if(deta_Cunst<=0||deta_w<0||deta_h<0){
		return;
	}

	DWORD begin=rect.top*width+rect.left;
	if(begin>=width*length)
		return;
	for(DWORD i=0;i<deta_Cunst;i++){
		colors[begin+(deta_h>deta_w&&width_first==FALSE?i*width:i)]=setcolor;
	}
}

void SetBitmapColor_RectBk(COLORREF * colors,DWORD width,DWORD length,CRect rect,COLORREF setcolor){

	DWORD deta_w=( (DWORD)rect.right<width?rect.Width():(width-rect.left) );
	DWORD deta_h=( (DWORD)rect.bottom<length?rect.Height():(length-rect.top) );

	if(deta_w<=0||deta_h<=0){
		return;
	}
	SetBitmapColor_Line(colors,width,length,rect,setcolor,true);
	DWORD deta_Cunst=deta_h;

	DWORD begin=rect.top*width+rect.left;
	if(begin>=width*length)
		return;

	for(DWORD i=1;i<deta_Cunst;i++){
		memcpy(&colors[begin+i*width],&colors[begin],deta_w*sizeof(COLORREF));
	}
}

void SetBitmapColor_RectLine(COLORREF * colors,DWORD width,DWORD length,CRect rect,COLORREF setcolor){

	DWORD deta_w=( (DWORD)rect.right<width?rect.Width():(width-rect.left) );
	DWORD deta_h=( (DWORD)rect.bottom<length?rect.Height():(length-rect.top) );

	if(deta_w<=0||deta_h<=0){
		return;
	}
	SetBitmapColor_Line(colors,width,length,CRect(rect.left,rect.top,rect.right,rect.top),setcolor);
	SetBitmapColor_Line(colors,width,length,CRect(rect.left,rect.bottom,rect.right+1,rect.bottom),setcolor);

	SetBitmapColor_Line(colors,width,length,CRect(rect.right,rect.top,rect.right,rect.bottom+1),setcolor);
	SetBitmapColor_Line(colors,width,length,CRect(rect.left,rect.top,rect.left,rect.bottom),setcolor);
}

//#endif
