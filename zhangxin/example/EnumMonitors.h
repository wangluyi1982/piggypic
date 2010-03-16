// EnumMonitors1.h: interface for the EnumMonitors class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENUMMONITORS1_H__B4FF639E_DC34_41F7_BE66_05DF7DE35306__INCLUDED_)
#define AFX_ENUMMONITORS1_H__B4FF639E_DC34_41F7_BE66_05DF7DE35306__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

struct monitor_info
{
	int id;
	CString m_sMonitorName;
	CString m_sAdapterName;
	CString m_sMonitorDevname;
	CString m_sAdapterDevname;
	CString m_sMonitorDeviceID;
	CString m_sAdapterDeviceID;
	unsigned long m_iXResolution,m_iYResolution;
	HMONITOR hMonitor;
	DWORD m_dwDisplayFrequency;
	DWORD m_dwBitsPerPixel;
	RECT m_rectDisplayArea;
	RECT m_rectWorkspaceArea;
	DWORD m_dwAdapterStateFlags;
	DWORD m_dwDisplayStateFlags;
	bool m_bReadEDID;
	unsigned char m_bEDID[256];
	CString m_sMonitorINFDriverDesc;
	CString m_sMonitorINFProviderName;
	CString m_sMonitorINFDriverVersion;
	CString m_sMonitorINFInfSection;
	CString m_sMonitorINFICMProfile;
	CString m_sMonitorINFINFPath;
	int m_iMonitorINFMaxXRes;
	int m_iMonitorINFMaxYRes;
	int m_iMonitorINF2MaxXRes;
	int m_iMonitorINF2MaxYRes;
	float m_fMonitorINFMinHorizontalFrequency;
	float m_fMonitorINFMaxHorizontalFrequency;
	float m_fMonitorINFMinVerticalFrequency;
	float m_fMonitorINFMaxVerticalFrequency;
	CString m_sBoardINFManufacturer;

	bool m_bDisplayDeviceRemovable;
	bool m_bDisplayActive;
	bool m_bDisplayDevicePrimary;
	bool m_bDisplayDeviceAttachedToDesktop;

};


class EnumMonitors  
{
public:
	EnumMonitors(bool active_only=TRUE);
	virtual ~EnumMonitors();
	virtual int Enumerate(bool active_only);
	virtual int GetTotalDesktopSize(int* x, int* y);
	virtual int GetTotalDesktopExtents(RECT* theRect);
	virtual int GetDisplayInfoByID(int id,monitor_info* the_monitor_info);
	virtual int GetDisplayInfoByEnum(int number,monitor_info* the_monitor_info);
	virtual int GetNumEnumerated(void);
	
private:
	virtual int GetEDIDFromRegistry(char monitor_name[], unsigned char EDID[]);
	virtual int GetINFInfo(char in_theKeyString[],monitor_info* the_monitor_info);
	virtual int GetINFModes(char in_theKeyString[],monitor_info* the_monitor_info);
	virtual int GetVideoCardInfo(char in_theKeyString[],monitor_info* the_monitor_info);
	CArray <monitor_info,monitor_info> monitor_info_array;	
};

#endif // !defined(AFX_ENUMMONITORS1_H__B4FF639E_DC34_41F7_BE66_05DF7DE35306__INCLUDED_)
