// EnumMonitors1.cpp: implementation of the EnumMonitors class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EnumMonitors.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// EnumMonitors
// Purpose: Enumerates all display monitors and fills structure with data
// by William Hollingworth
// March 05 2004
// revision history:
// March 05 2004 - Initial creation
// July 25 2004 - fixed bug that caused only EDID for 1st monitor to be read if 2 or more identical model monitors exist


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/* Child device state */
#define DISPLAY_DEVICE_ACTIVE              0x00000001
#define DISPLAY_DEVICE_ATTACHED            0x00000002


#define DISPLAY_DEVICE_ATTACHED_TO_DESKTOP 0x00000001
#define DISPLAY_DEVICE_MULTI_DRIVER        0x00000002
#define DISPLAY_DEVICE_PRIMARY_DEVICE      0x00000004
#define DISPLAY_DEVICE_MIRRORING_DRIVER    0x00000008
#define DISPLAY_DEVICE_VGA_COMPATIBLE      0x00000010
#define DISPLAY_DEVICE_REMOVABLE           0x00000020
#define DISPLAY_DEVICE_MODESPRUNED         0x08000000
#define DISPLAY_DEVICE_REMOTE              0x04000000  
#define DISPLAY_DEVICE_DISCONNECT          0x02000000 

EnumMonitors::EnumMonitors(bool active_only)
{
	Enumerate(active_only);	
}

EnumMonitors::~EnumMonitors()
{
	
}

int EnumMonitors::Enumerate(bool active_only)
{
	monitor_info the_monitor_info;	
	DISPLAY_DEVICE dd;
	
	monitor_info_array.RemoveAll();	
	
	dd.cb = sizeof(dd);
	DWORD dev = 0; // device index
	int id = 1; // monitor number, as used by Display Properties > Settings
	
	while (EnumDisplayDevices(0, dev, &dd, 0))
	{
		if (!(dd.StateFlags & DISPLAY_DEVICE_MIRRORING_DRIVER))
		{			
			// ignore virtual mirror displays			
			
			// get information about the monitor attached to this display adapter. dualhead cards
			// and laptop video cards can have multiple monitors attached
			
			_TCHAR  AdapterDeviceName[32];			
			_tcsncpy(AdapterDeviceName,dd.DeviceName,32);
			
			DISPLAY_DEVICE ddMon;
			ZeroMemory(&ddMon, sizeof(ddMon));
			ddMon.cb = sizeof(ddMon);
			DWORD devMon = 0;
			
			// please note that this enumeration may not return the correct monitor if multiple monitors
			// are attached. this is because not all display drivers return the ACTIVE flag for the monitor
			// that is actually active
			
			//			while (EnumDisplayDevices(dd.DeviceName, devMon, &ddMon, 0))
			while (EnumDisplayDevices(AdapterDeviceName, devMon, &ddMon, 0))
			{
				//				if (ddMon.StateFlags & DISPLAY_DEVICE_ACTIVE)
				//					break;
				
//				if (ddMon.StateFlags & DISPLAY_DEVICE_ACTIVE)
				{										
					the_monitor_info.hMonitor=0;
					the_monitor_info.id=0;
					the_monitor_info.m_bDisplayActive=0;
					the_monitor_info.m_bDisplayDeviceAttachedToDesktop=0;
					the_monitor_info.m_bDisplayDevicePrimary=0;
					the_monitor_info.m_bDisplayDeviceRemovable=0;
					the_monitor_info.m_bReadEDID=0;
					the_monitor_info.m_dwBitsPerPixel=0;
					the_monitor_info.m_dwDisplayFrequency=0;
					the_monitor_info.m_dwAdapterStateFlags=0;
					the_monitor_info.m_dwDisplayStateFlags=0;
					the_monitor_info.m_fMonitorINFMaxHorizontalFrequency=0;
					the_monitor_info.m_fMonitorINFMaxVerticalFrequency=0;
					the_monitor_info.m_fMonitorINFMinHorizontalFrequency=0;
					the_monitor_info.m_fMonitorINFMinVerticalFrequency=0;
					the_monitor_info.m_iMonitorINF2MaxXRes=0;
					the_monitor_info.m_iMonitorINF2MaxYRes=0;
					the_monitor_info.m_iMonitorINFMaxXRes=0;
					the_monitor_info.m_iMonitorINFMaxYRes=0;
					the_monitor_info.m_iXResolution=0;
					the_monitor_info.m_iYResolution=0;
					the_monitor_info.m_rectDisplayArea.bottom=0;
					the_monitor_info.m_rectDisplayArea.left=0;
					the_monitor_info.m_rectDisplayArea.right=0;
					the_monitor_info.m_rectDisplayArea.top=0;
					the_monitor_info.m_rectWorkspaceArea.bottom=0;
					the_monitor_info.m_rectWorkspaceArea.left=0;
					the_monitor_info.m_rectWorkspaceArea.right=0;
					the_monitor_info.m_rectWorkspaceArea.top=0;
					the_monitor_info.m_sAdapterDevname="";
					the_monitor_info.m_sBoardINFManufacturer="";
					the_monitor_info.m_sMonitorDevname="";
					the_monitor_info.m_sMonitorINFDriverDesc="";
					the_monitor_info.m_sMonitorINFICMProfile="";
					the_monitor_info.m_sMonitorINFINFPath="";
					the_monitor_info.m_sMonitorINFInfSection="";
					the_monitor_info.m_sMonitorINFProviderName="";
					the_monitor_info.m_sMonitorName="";
					
					
					the_monitor_info.id=id;
					the_monitor_info.m_sMonitorName=ddMon.DeviceString;
					the_monitor_info.m_sAdapterName=dd.DeviceString;

					if (*ddMon.DeviceName)
						the_monitor_info.m_sMonitorDevname=ddMon.DeviceName;
					
					the_monitor_info.m_sAdapterDevname=dd.DeviceName;

					the_monitor_info.m_sMonitorDeviceID=ddMon.DeviceID;
					the_monitor_info.m_sAdapterDeviceID=dd.DeviceID;
					


					the_monitor_info.m_dwAdapterStateFlags=dd.StateFlags;
					the_monitor_info.m_dwDisplayStateFlags=ddMon.StateFlags;
			
					the_monitor_info.m_bDisplayActive=ddMon.StateFlags & DISPLAY_DEVICE_ACTIVE;

					the_monitor_info.m_bDisplayDeviceAttachedToDesktop=dd.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP;
					the_monitor_info.m_bDisplayDevicePrimary=(dd.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE)?true:false;
					the_monitor_info.m_bDisplayDeviceRemovable=(dd.StateFlags & DISPLAY_DEVICE_REMOVABLE)?true:false;
					
										
					// status flags: primary, disabled, removable			
//					the_monitor_info.m_dwStateFlags=dd.StateFlags;
					
					TRACE("ddMon.DeviceString=%s",ddMon.DeviceString);	
					TRACE("ddMon.DeviceName=%s",ddMon.DeviceName);	
					TRACE("ddMon.DeviceKey=%s",ddMon.DeviceKey);	
					TRACE("ddMon.DeviceID=%s",ddMon.DeviceID);	
										
					TRACE("dd.DeviceString=%s",dd.DeviceString);			
					TRACE("dd.DeviceName=%s",dd.DeviceName);			
					TRACE("dd.DeviceKey=%s",dd.DeviceKey);	
					TRACE("dd.DeviceID=%s",dd.DeviceID);	


/*
					if (!*ddMon.DeviceString)
					{
						EnumDisplayDevices(dd.DeviceName, 0, &ddMon, 0);
						if (!*ddMon.DeviceString)
							lstrcpy(ddMon.DeviceString, _T("Default Monitor"));
					}
*/					
					// get information about the display's position and the current display mode
					DEVMODE dm;
					ZeroMemory(&dm, sizeof(dm));
					dm.dmSize = sizeof(dm);
					
					int success;
					success=EnumDisplaySettingsEx(dd.DeviceName, ENUM_CURRENT_SETTINGS, &dm, 0);
					if (!success)
						success=EnumDisplaySettingsEx(dd.DeviceName, ENUM_REGISTRY_SETTINGS, &dm, 0);
					
					if (success)
					{
						// width x height @ x,y - bpp - refresh rate
			
						the_monitor_info.m_iXResolution=dm.dmPelsWidth;
						the_monitor_info.m_iYResolution=dm.dmPelsHeight;
						the_monitor_info.m_dwDisplayFrequency=dm.dmDisplayFrequency;
						the_monitor_info.m_dwBitsPerPixel=dm.dmBitsPerPel;
					}
															
					// get the monitor handle and workspace
					HMONITOR hm = 0;
					MONITORINFO mi;
					ZeroMemory(&mi, sizeof(mi));
					mi.cbSize = sizeof(mi);
					if (dd.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP)
					{
						// display is enabled. only enabled displays have a monitor handle
						POINT pt = { dm.dmPosition.x, dm.dmPosition.y };
						hm = MonitorFromPoint(pt, MONITOR_DEFAULTTONULL);
						if (hm)
						{
							if (GetMonitorInfo(hm, &mi))
							{								
								// workspace and monitor handle				
								// workspace: x,y - x,y HMONITOR: handle				
								the_monitor_info.m_rectDisplayArea.left=mi.rcMonitor.left;
								the_monitor_info.m_rectDisplayArea.top=mi.rcMonitor.top;
								the_monitor_info.m_rectDisplayArea.right=mi.rcMonitor.right;
								the_monitor_info.m_rectDisplayArea.bottom=mi.rcMonitor.bottom;
								
								the_monitor_info.m_rectWorkspaceArea.left=mi.rcWork.left;
								the_monitor_info.m_rectWorkspaceArea.top=mi.rcWork.top;
								the_monitor_info.m_rectWorkspaceArea.right=mi.rcWork.right;
								the_monitor_info.m_rectWorkspaceArea.bottom=mi.rcWork.bottom;
								
								the_monitor_info.hMonitor=hm;
							}							
						}
					}
					

					
					GetVideoCardInfo(dd.DeviceID,&the_monitor_info);
					
					if (GetEDIDFromRegistry(ddMon.DeviceID,the_monitor_info.m_bEDID)==0)
						the_monitor_info.m_bReadEDID=true;
					else
						the_monitor_info.m_bReadEDID=false;
					
					GetINFInfo(ddMon.DeviceKey,&the_monitor_info);
					GetINFModes(ddMon.DeviceKey,&the_monitor_info);
										

					
					if (active_only)
					{
						if (the_monitor_info.m_bDisplayActive&&the_monitor_info.m_bDisplayDeviceAttachedToDesktop)
							monitor_info_array.Add(the_monitor_info);
					}
					else
						monitor_info_array.Add(the_monitor_info);
					
					id++;										
				}
				devMon++;
				_tcsncpy(AdapterDeviceName,dd.DeviceName,32);
				ZeroMemory(&ddMon, sizeof(ddMon));
				ddMon.cb = sizeof(ddMon);
				DWORD devMon = 0;				
			}						
		}
		dev++;
	}	
	return monitor_info_array.GetSize();
}


int EnumMonitors::GetTotalDesktopSize(int* x, int* y)
{

	int num_enumerated;
	int loop;
	int min_x=0,min_y=0,max_x=0,max_y=0;
	monitor_info the_monitor_info;
	num_enumerated=monitor_info_array.GetSize();
	if (num_enumerated==0) return -1;
	for (loop=0; loop<num_enumerated; loop++)
	{
		the_monitor_info=monitor_info_array.GetAt(loop);
		if(the_monitor_info.m_bDisplayActive&&the_monitor_info.m_bDisplayDeviceAttachedToDesktop)
		{
			if (the_monitor_info.m_rectDisplayArea.left<min_x)
				min_x=the_monitor_info.m_rectDisplayArea.left;
			if (the_monitor_info.m_rectDisplayArea.right>max_x)
				max_x=the_monitor_info.m_rectDisplayArea.right;
			
			if (the_monitor_info.m_rectDisplayArea.top<min_y)
				min_y=the_monitor_info.m_rectDisplayArea.top;
			if (the_monitor_info.m_rectDisplayArea.bottom>max_y)
				max_y=the_monitor_info.m_rectDisplayArea.bottom;
		}
		
	}
	*x=max_x-min_x;
	*y=max_y-min_y;
	return 0;
}



int EnumMonitors::GetTotalDesktopExtents(RECT* theRect)
{
	int num_enumerated;
	int loop;
	int min_x=0,min_y=0,max_x=0,max_y=0;
	monitor_info the_monitor_info;
	num_enumerated=monitor_info_array.GetSize();
	if (num_enumerated==0) return -1;
	for (loop=0; loop<num_enumerated; loop++)
	{
		the_monitor_info=monitor_info_array.GetAt(loop);
		if(the_monitor_info.m_bDisplayActive&&the_monitor_info.m_bDisplayDeviceAttachedToDesktop)
		{
			if (the_monitor_info.m_rectDisplayArea.left<min_x)
				min_x=the_monitor_info.m_rectDisplayArea.left;
			if (the_monitor_info.m_rectDisplayArea.right>max_x)
				max_x=the_monitor_info.m_rectDisplayArea.right;
			
			if (the_monitor_info.m_rectDisplayArea.top<min_y)
				min_y=the_monitor_info.m_rectDisplayArea.top;
			if (the_monitor_info.m_rectDisplayArea.bottom>max_y)
				max_y=the_monitor_info.m_rectDisplayArea.bottom;
		}
		
	}
	theRect->left=min_x;
	theRect->right=max_x;
	theRect->top=min_y;
	theRect->bottom=max_y;
	return 0;
}



int EnumMonitors::GetDisplayInfoByID(int id,monitor_info* in_monitor_info)
{
	int num_enumerated;
	int loop;
	bool found=0;
	monitor_info the_monitor_info;
	num_enumerated=monitor_info_array.GetSize();
	if (num_enumerated==0) return -1;
	for (loop=0; loop<num_enumerated; loop++)
	{
		the_monitor_info=monitor_info_array.GetAt(loop);
		if (id==the_monitor_info.id)
		{
			*in_monitor_info=the_monitor_info;
			found=true;
		}
	}
	if (!found) return -2;

	return 0;
}

int EnumMonitors::GetDisplayInfoByEnum(int number,monitor_info* in_monitor_info)
{
	int num_enumerated;
	bool found=0;
	monitor_info the_monitor_info;
	num_enumerated=monitor_info_array.GetSize();
	if (num_enumerated==0) return -1;

	if (number>num_enumerated) return -1;

	the_monitor_info=monitor_info_array.GetAt(number);
	*in_monitor_info=the_monitor_info;
	return 0;
}


int EnumMonitors::GetNumEnumerated(void)
{
	return monitor_info_array.GetSize();
}




int EnumMonitors::GetEDIDFromRegistry(char in_monitor_name[], unsigned char EDID[]) 
{
	long error,error2;
	int found_one=0;
	char monitor_name[1024];
	HKEY theSecondRegKey;
	HKEY theRegKey;
	char theKeyString[1024];
	char theSubKeyString[1024];
	char theSecondKeyString[1024];
	DWORD theIndex;

	bool matched;
	
	TRACE("GetEDIDFromRegistry in_monitor_name=%s",in_monitor_name);	
	
	if (sscanf(in_monitor_name,"Monitor\\%s\\",monitor_name)==0) return -1;
	
	CString tempString;
	CString driverNameString;
	tempString=in_monitor_name;
	int pos=tempString.Find("{");
	driverNameString=tempString.Mid(pos);
	
	TRACE("GetEDIDFromRegistry driverNameString=%s",driverNameString);	
	
	pos=0;
	do {
		pos++;
	}while (monitor_name[pos-1]!='\\'&&monitor_name[pos-1]!='\0');
	monitor_name[pos-1]='\0';
				
	TRACE("GetEDIDFromRegistry monitor_name=%s",monitor_name);	
				
	sprintf(theKeyString,"SYSTEM\\CurrentControlSet\\Enum\\DISPLAY\\%s",monitor_name);
	
	error=RegOpenKeyEx(HKEY_LOCAL_MACHINE,theKeyString,0,KEY_READ,&theRegKey);
	if (error==ERROR_SUCCESS)
	{
		theIndex=0;
		DWORD cName;            // size of subkey buffer
		FILETIME ftLastWriteTime; // last write time
		
		matched=false;
		do 
		{
			cName=1024;
			error=RegEnumKeyEx(theRegKey,theIndex,theSubKeyString,&cName,NULL,NULL,NULL,&ftLastWriteTime);
			
			if (error==ERROR_SUCCESS)
			{
				TRACE("GetEDIDFromRegistry theKeyString=%s",theKeyString);	
				
				////////////////////
				// check to see if the "Driver" value matches to the string extracted from the device info
				if (driverNameString.GetLength()>0)
				{				
					sprintf(theSecondKeyString,"%s\\%s",theKeyString,theSubKeyString);
					cName=1024;

					error2=RegOpenKeyEx(HKEY_LOCAL_MACHINE,theSecondKeyString,0,KEY_READ,&theSecondRegKey);
					{
						
						TRACE("GetEDIDFromRegistry theKeyString=%s",theKeyString);	
						
						unsigned char theDriver[1024];
						DWORD theSize;
						theSize=1024;
						error2=RegQueryValueEx(theSecondRegKey,"Driver",NULL,NULL,theDriver,&theSize);
						if (error2==ERROR_SUCCESS)
						{
							TRACE("Driver=%s",theDriver);	
							if (driverNameString==theDriver)
							{
								TRACE("MATCHED!!");
								matched=true;
							}
							
						}
						else
						{
							TRACE("Driver query %s failed",theSecondKeyString);	
							
						}
						RegCloseKey(theSecondRegKey);
					}
					
				}
				else
					matched=true;	// no driver info so no choice 
				////////////////////
				
				
				if (matched)
				{
					
					// check to see if DeviceParameters exists
					
					sprintf(theSecondKeyString,"%s\\%s\\Control",theKeyString,theSubKeyString);
					cName=1024;
					error2=RegOpenKeyEx(HKEY_LOCAL_MACHINE,theSecondKeyString,0,KEY_READ,&theSecondRegKey);
					if (error2==ERROR_SUCCESS)					
					{
						RegCloseKey(theSecondRegKey);
						
						
						sprintf(theSecondKeyString,"%s\\%s\\Device Parameters",theKeyString,theSubKeyString);
						found_one=1;
						TRACE("GetEDIDFromRegistry theSecondKeyString=%s",theSecondKeyString);	
						
						cName=1024;
						HKEY theThirdRegKey;
						error2=RegOpenKeyEx(HKEY_LOCAL_MACHINE,theSecondKeyString,0,KEY_READ,&theThirdRegKey);
						if (error2==ERROR_SUCCESS)
						{	
							unsigned char theEDID[256];
							DWORD theSize;
							theSize=256;
							
							error2=RegQueryValueEx(theThirdRegKey,"EDID",NULL,NULL,theEDID,&theSize);
							//						if (error2!=ERROR_SUCCESS)
							if (error2==ERROR_SUCCESS)
							{
								TRACE("GetEDIDFromRegistry Raw EDID Data:");	
								int loop;
								for (loop=0; loop<128; loop++)
								{
									TRACE("GetEDIDFromRegistry %2X = %2X",loop,theEDID[loop]);	
									EDID[loop]=theEDID[loop];
								}														
							}
							else
							{
								TRACE("GetEDIDFromRegistry Unable to find any EDID");								
							}												
							RegCloseKey(theThirdRegKey);
						}
						
					}								
				}
				matched=false;
			}			
			theIndex++;
			
		} while (error==ERROR_SUCCESS&&found_one==0);
		
		RegCloseKey(theRegKey);			
	}
	else
	{
		TRACE("GetEDIDFromRegistry FAILED");		
	}	
	return 0;
}




int EnumMonitors::GetINFInfo(char in_theKeyString[],monitor_info* the_monitor_info)
{
	long error,error2;
	HKEY theRegKey;
	char theKeyString[1024];
	char theSubKeyString[1024];
	
	if (sscanf(in_theKeyString,"\\Registry\\Machine\\%s",theKeyString)!=1)
		return -1;

	TRACE("GetINFInfo theKeyString = %s",theKeyString);	

	error=RegOpenKeyEx(HKEY_LOCAL_MACHINE,theKeyString,0,KEY_READ,&theRegKey);
	if (error==ERROR_SUCCESS)
	{
		
		char unsigned theString[1024];
		DWORD theSize;				
		theSize=1024;	
		strcpy(theSubKeyString,"DriverDesc");		
		error2=RegQueryValueEx(theRegKey,theSubKeyString,NULL,NULL,theString,&theSize);
		if (error2==ERROR_SUCCESS)
		{
			the_monitor_info->m_sMonitorINFDriverDesc=theString;
			TRACE("GetINFInfo DriverDesc = %s",theString);				
		}	
					
		theSize=1024;	
		strcpy(theSubKeyString,"ProviderName");		
		error2=RegQueryValueEx(theRegKey,theSubKeyString,NULL,NULL,theString,&theSize);
		if (error2==ERROR_SUCCESS)
		{
			the_monitor_info->m_sMonitorINFProviderName=theString;
			TRACE("GetINFInfo Driver ProviderName = %s",theString);	
		}	
				
		theSize=1024;	
		strcpy(theSubKeyString,"DriverVersion");		
		error2=RegQueryValueEx(theRegKey,theSubKeyString,NULL,NULL,theString,&theSize);
		if (error2==ERROR_SUCCESS)
		{
			the_monitor_info->m_sMonitorINFDriverVersion=theString;
			TRACE("GetINFInfo DriverVersion = %s",theString);	
		}	
				
		theSize=1024;	
		strcpy(theSubKeyString,"InfSection");		
		error2=RegQueryValueEx(theRegKey,theSubKeyString,NULL,NULL,theString,&theSize);
		if (error2==ERROR_SUCCESS)
		{
			the_monitor_info->m_sMonitorINFInfSection=theString;
			TRACE("GetINFInfo InfSection = %s",theString);	
		}	
				
		theSize=1024;	
		strcpy(theSubKeyString,"ICMProfile");
		DWORD type;	
		error2=RegQueryValueEx(theRegKey,theSubKeyString,NULL,&type,theString,&theSize);
		if (error2==ERROR_SUCCESS)
		{			
			if (type==REG_SZ)
			{
				the_monitor_info->m_sMonitorINFICMProfile=theString;
				TRACE("GetINFInfo ICM Profile Name = %s",theString);				
			}
			else
			{
				the_monitor_info->m_sMonitorINFICMProfile="Preset";
				if (type==REG_BINARY)
				{

				TRACE("GetINFInfo ICM Profile Name = Preset");			
				TRACE("GetINFInfo ICM Profile type = %i size = %i",type,theSize);

				char outString[1025];
				WideCharToMultiByte(CP_ACP,0,(unsigned short*)theString,-1,outString,1024,NULL,NULL);
				the_monitor_info->m_sMonitorINFICMProfile=outString;
				TRACE("GetINFInfo ICM Profile Name = %s",outString);				
				}
			}
		}	
				
		theSize=1024;	
		strcpy(theSubKeyString,"INFPath");		
		error2=RegQueryValueEx(theRegKey,theSubKeyString,NULL,NULL,theString,&theSize);
		if (error2==ERROR_SUCCESS)
		{
			the_monitor_info->m_sMonitorINFINFPath=theString;
			TRACE("GetINFInfo INFPath = %s",theString);	
		}	
				
		theSize=1024;	
		strcpy(theSubKeyString,"MaxResolution");		
		error2=RegQueryValueEx(theRegKey,theSubKeyString,NULL,NULL,theString,&theSize);
		if (error2==ERROR_SUCCESS)
		{			
			int x_res,y_res;
			if (sscanf((char*)theString,"%u,%u",&x_res,&y_res)==2)
			{
				the_monitor_info->m_iMonitorINFMaxXRes=x_res;
				the_monitor_info->m_iMonitorINFMaxYRes=y_res;

				TRACE("GetINFInfo Maximum Resolution #1:%u x %u",x_res,y_res);							
			}
		}	
		RegCloseKey(theRegKey);
	}
	else
	{
		TRACE("GetINFInfo FAILED");	
		return -1;
	}
	return 0;	
}



int EnumMonitors::GetINFModes(char in_theKeyString[],monitor_info* the_monitor_info)
{
	long error,error2;
	HKEY theRegKey;
	char theKeyString[1024];
	char theSubKeyString[1024];
	char theSecondKeyString[1024];
	DWORD theIndex;
	
	
	if (sscanf(in_theKeyString,"\\Registry\\Machine\\%s",theKeyString)!=1)
		return -1;
	
	TRACE("GetINFModes theKeyString = %s",theKeyString);	
	
	strcat(theKeyString,"\\MODES");	
	error=RegOpenKeyEx(HKEY_LOCAL_MACHINE,theKeyString,0,KEY_READ,&theRegKey);
	if (error==ERROR_SUCCESS)
	{
		theIndex=0;
		DWORD cName;            // size of subkey buffer
		FILETIME ftLastWriteTime; // last write time
		
//		TRACE("GetINFModes looking for mode theKeyString = %s",theKeyString);	
		
		cName=1024;
		error=RegEnumKeyEx(theRegKey,theIndex,theSubKeyString,&cName,NULL,NULL,NULL,&ftLastWriteTime);
		if (error==ERROR_SUCCESS)
		{			
//			TRACE("GetINFModes found mode theSubKeyString = %s",theSubKeyString);	
						
			int x_res,y_res;
			if (sscanf(theSubKeyString,"%u,%u",&x_res,&y_res)==2)
			{
				TRACE("GetINFModes Maximum Resolution #1:%u x %u",x_res,y_res);
				the_monitor_info->m_iMonitorINF2MaxXRes=x_res;
				the_monitor_info->m_iMonitorINF2MaxYRes=y_res;
			}
						
			sprintf(theSecondKeyString,"%s\\%s",theKeyString,theSubKeyString);
			
			
			
//			{
				// open the modes key and get the "Mode1" string
				cName=1024;
				HKEY theSecondRegKey;
				error2=RegOpenKeyEx(HKEY_LOCAL_MACHINE,theSecondKeyString,0,KEY_READ,&theSecondRegKey);
				if (error2==ERROR_SUCCESS)
				{	
					unsigned char theMode[256];
					DWORD theSize;
					theSize=256;
					
					error2=RegQueryValueEx(theSecondRegKey,"Mode1",NULL,NULL,theMode,&theSize);
					//						if (error2!=ERROR_SUCCESS)
					if (error2==ERROR_SUCCESS)
					{
//						TRACE("GetINFModes found mode info");
						
						
						float fh_min,fv_min,fh_max,fv_max;
						
						if (sscanf((char*)theMode,"%f-%f,%f-%f,",&fh_min,&fh_max,&fv_min,&fv_max)==4)
						{
							TRACE("GetINFModes Vertical Scan Range:\t%3.1f - %3.1f Hz\r\n",fv_min,fv_max);							
							TRACE("GetINFModes Horizontal Scan Range:%3.1f - %3.1f kHz\r\n",fh_min,fh_max);							
							
							the_monitor_info->m_fMonitorINFMinHorizontalFrequency=fh_min;
							the_monitor_info->m_fMonitorINFMaxHorizontalFrequency=fh_max;
							the_monitor_info->m_fMonitorINFMinVerticalFrequency=fv_min;
							the_monitor_info->m_fMonitorINFMaxVerticalFrequency=fv_max;
							
						}						
					}
					RegCloseKey(theSecondRegKey);
				}				
//			}			
		}		
		RegCloseKey(theRegKey);
	}
	else
	{
		TRACE("GetINFInfo FAILED");	
		return -1;
	}
	return 0;	
}




int EnumMonitors::GetVideoCardInfo(char in_theKeyString[],monitor_info* the_monitor_info)
{
	long error,error2;
	HKEY theRegKey;
	char theKeyString[1024];
	char theSubKeyString[1024];
	char theSecondKeyString[1024];	
	DWORD theIndex;

	sprintf(theKeyString,"SYSTEM\\CurrentControlSet\\Enum\\%s",in_theKeyString);
	
	error=RegOpenKeyEx(HKEY_LOCAL_MACHINE,theKeyString,0,KEY_READ,&theRegKey);
	if (error==ERROR_SUCCESS)
	{
		theIndex=0;
		DWORD cName;            // size of subkey buffer
		FILETIME ftLastWriteTime; // last write time	
		do 
		{
			cName=1024;
			error=RegEnumKeyEx(theRegKey,theIndex,theSubKeyString,&cName,NULL,NULL,NULL,&ftLastWriteTime);
			
			if (error==ERROR_SUCCESS)
			{
				TRACE("GetVideoCardInfo board vendor theKeyString = %s",theKeyString);	
				TRACE("GetVideoCardInfo board vendor theSubKeyString = %s",theSubKeyString);	
								
				char unsigned theString[1024];
				// check to see if DeviceParameters exists				
				sprintf(theSecondKeyString,"%s\\%s",theKeyString,theSubKeyString);
				cName=1024;
				HKEY theSecondRegKey;
				error2=RegOpenKeyEx(HKEY_LOCAL_MACHINE,theSecondKeyString,0,KEY_READ,&theSecondRegKey);
				if (error2==ERROR_SUCCESS)					
				{
					strcpy(theSubKeyString,"Mfg");					
					DWORD theSize;
					theSize=1024;	
					TRACE("GetVideoCardInfo looking in theSecondKeyString= %s",theSecondKeyString);	
															
					error2=RegQueryValueEx(theSecondRegKey,theSubKeyString,NULL,NULL,theString,&theSize);
					if (error2==ERROR_SUCCESS)
					{						
						TRACE("GetVideoCardInfo Mfg = %s",theString);
						the_monitor_info->m_sBoardINFManufacturer=theString;
					}	
					RegCloseKey(theSecondRegKey);					
				}
				theIndex++;
			}
		} while (error==ERROR_SUCCESS);		
		RegCloseKey(theRegKey);				
	}
	else
	{
		TRACE("GetINFInfo FAILED");	
		return -1;
	}
	return 0;	
}

