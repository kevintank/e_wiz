# Microsoft Developer Studio Project File - Name="TestDlg" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TestDlg - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TestDlg.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TestDlg.mak" CFG="TestDlg - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TestDlg - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TestDlg - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TestDlg - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "TestDlg - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TestDlg - Win32 Release"
# Name "TestDlg - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Ado.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SubFormCollection.cpp
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg1.cpp
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg2.cpp
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg3.cpp
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg4.cpp
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg5.cpp
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg6.cpp
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg7.cpp
# End Source File
# Begin Source File

SOURCE=.\TestDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TestDlg.rc
# End Source File
# Begin Source File

SOURCE=.\TestDlgDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\xSkinButton.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Ado.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SubFormCollection.h
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg1.h
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg2.h
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg3.h
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg4.h
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg5.h
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg6.h
# End Source File
# Begin Source File

SOURCE=.\SubFormDlg7.h
# End Source File
# Begin Source File

SOURCE=.\TestDlg.h
# End Source File
# Begin Source File

SOURCE=.\TestDlgDlg.h
# End Source File
# Begin Source File

SOURCE=.\xSkinButton.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\back.bmp
# End Source File
# Begin Source File

SOURCE=.\res\back_new.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dap_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dap_nor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dap_over.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mini_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mini_nor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mini_over.bmp
# End Source File
# Begin Source File

SOURCE=.\res\quit_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\quit_nor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\quit_over.bmp
# End Source File
# Begin Source File

SOURCE=.\res\start_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\start_nor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\start_over.bmp
# End Source File
# Begin Source File

SOURCE=.\res\test_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\test_nor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\test_over.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TestDlg.ico
# End Source File
# Begin Source File

SOURCE=.\res\TestDlg.rc2
# End Source File
# Begin Source File

SOURCE=.\res\title_bar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\Debug\msado15.tlh
# End Source File
# Begin Source File

SOURCE=.\Debug\msadox.tli
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\xptheme.xml
# End Source File
# End Target
# End Project
