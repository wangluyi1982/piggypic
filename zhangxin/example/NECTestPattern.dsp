# Microsoft Developer Studio Project File - Name="NECTestPattern" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=NECTestPattern - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "NECTestPattern.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "NECTestPattern.mak" CFG="NECTestPattern - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "NECTestPattern - Win32 Release" ("Win32 (x86) Application" 用)
!MESSAGE "NECTestPattern - Win32 Debug" ("Win32 (x86) Application" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "NECTestPattern - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"exe/NECTestPattern.exe"

!ELSEIF  "$(CFG)" == "NECTestPattern - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"exe/NECTestPattern.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "NECTestPattern - Win32 Release"
# Name "NECTestPattern - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BCMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\BtnST.cpp
# End Source File
# Begin Source File

SOURCE=.\CalcDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EnumMonitors.cpp
# End Source File
# Begin Source File

SOURCE=.\MessageDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NECTestPattern.cpp
# End Source File
# Begin Source File

SOURCE=.\NECTestPattern.rc
# End Source File
# Begin Source File

SOURCE=.\NECTestPattern_lib.cpp
# End Source File
# Begin Source File

SOURCE=.\NECTestPatternDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RemindDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SetTestPatternDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SettingMsgDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SettingRemindDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SoftOptionDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TestPatternDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TesttingMsgDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BCMenu.h
# End Source File
# Begin Source File

SOURCE=.\BtnST.h
# End Source File
# Begin Source File

SOURCE=.\CalcDlg.h
# End Source File
# Begin Source File

SOURCE=.\EnumMonitors.h
# End Source File
# Begin Source File

SOURCE=.\MessageDlg.h
# End Source File
# Begin Source File

SOURCE=.\monitor_info_TestPattern.h
# End Source File
# Begin Source File

SOURCE=.\mylib.h
# End Source File
# Begin Source File

SOURCE=.\NECTestPattern.h
# End Source File
# Begin Source File

SOURCE=.\NECTestPattern_lib.h
# End Source File
# Begin Source File

SOURCE=.\NECTestPatternDlg.h
# End Source File
# Begin Source File

SOURCE=.\RemindDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SetTestPatternDlg.h
# End Source File
# Begin Source File

SOURCE=.\SettingMsgDlg.h
# End Source File
# Begin Source File

SOURCE=.\SettingRemindDlg.h
# End Source File
# Begin Source File

SOURCE=.\SoftOptionDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TestPatternDlg.h
# End Source File
# Begin Source File

SOURCE=.\TesttingMsgDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\exe\TestPattern\7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\About.ico
# End Source File
# Begin Source File

SOURCE=.\res\ASTERISK.ico
# End Source File
# Begin Source File

SOURCE=.\exe\TestPattern\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_p.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_r.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_remind1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap_remind2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\EXCLAMATION.ico
# End Source File
# Begin Source File

SOURCE=.\res\HAND.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00002.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00003.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon_ast.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon_pat.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon_pat_Calc1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon_pat_Calc2.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon_pat_Calc3.ico
# End Source File
# Begin Source File

SOURCE=.\res\iconinfo.ico
# End Source File
# Begin Source File

SOURCE=.\res\idr_main.ico
# End Source File
# Begin Source File

SOURCE=.\res\NECTestPattern.ico
# End Source File
# Begin Source File

SOURCE=.\res\NECTestPattern.rc2
# End Source File
# Begin Source File

SOURCE=.\res\QUESTION.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\mylib.lib
# End Source File
# End Target
# End Project
