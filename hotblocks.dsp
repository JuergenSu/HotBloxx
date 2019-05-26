# Microsoft Developer Studio Project File - Name="hotblocks" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** NICHT BEARBEITEN **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=hotblocks - Win32 Debug
!MESSAGE Dies ist kein gültiges Makefile. Zum Erstellen dieses Projekts mit NMAKE
!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und führen Sie den Befehl
!MESSAGE 
!MESSAGE NMAKE /f "hotblocks.mak".
!MESSAGE 
!MESSAGE Sie können beim Ausführen von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "hotblocks.mak" CFG="hotblocks - Win32 Debug"
!MESSAGE 
!MESSAGE Für die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "hotblocks - Win32 Release" (basierend auf  "Win32 (x86) Application")
!MESSAGE "hotblocks - Win32 Debug" (basierend auf  "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/c++/hotblocks", FOAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "hotblocks - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "hotblocks - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "hotblocks - Win32 Release"
# Name "hotblocks - Win32 Debug"
# Begin Group "Quellcodedateien"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\block.cpp
# End Source File
# Begin Source File

SOURCE=.\highscore.cpp
# End Source File
# Begin Source File

SOURCE=.\hotblocks.cpp
# End Source File
# Begin Source File

SOURCE=.\image.cpp
# End Source File
# Begin Source File

SOURCE=.\ki.cpp
# End Source File
# Begin Source File

SOURCE=.\menu.cpp
# End Source File
# Begin Source File

SOURCE=.\SDL_audio.cpp
# End Source File
# Begin Source File

SOURCE=.\SDL_Font.cpp
# End Source File
# Begin Source File

SOURCE=.\SDL_random.cpp
# End Source File
# Begin Source File

SOURCE=.\spielfeld.cpp
# End Source File
# Begin Source File

SOURCE=.\surfaces.cpp
# End Source File
# End Group
# Begin Group "Header-Dateien"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\block.h
# End Source File
# Begin Source File

SOURCE=.\common.h
# End Source File
# Begin Source File

SOURCE=.\global.h
# End Source File
# Begin Source File

SOURCE=.\highscore.h
# End Source File
# Begin Source File

SOURCE=.\image.h
# End Source File
# Begin Source File

SOURCE=.\ki.h
# End Source File
# Begin Source File

SOURCE=.\menu.h
# End Source File
# Begin Source File

SOURCE=.\SDL_audio.h
# End Source File
# Begin Source File

SOURCE=.\SDL_Font.h
# End Source File
# Begin Source File

SOURCE=.\SDL_random.h
# End Source File
# Begin Source File

SOURCE=.\spielfeld.h
# End Source File
# Begin Source File

SOURCE=.\surfaces.h
# End Source File
# End Group
# Begin Group "Ressourcendateien"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\0.bmp
# End Source File
# Begin Source File

SOURCE=..\1.bmp
# End Source File
# Begin Source File

SOURCE=..\2.bmp
# End Source File
# Begin Source File

SOURCE=..\3.bmp
# End Source File
# Begin Source File

SOURCE=..\4.bmp
# End Source File
# Begin Source File

SOURCE=..\5.bmp
# End Source File
# Begin Source File

SOURCE=..\6.bmp
# End Source File
# Begin Source File

SOURCE=..\7.bmp
# End Source File
# Begin Source File

SOURCE=..\8.bmp
# End Source File
# Begin Source File

SOURCE=..\9.bmp
# End Source File
# Begin Source File

SOURCE=..\alpha0.bmp
# End Source File
# Begin Source File

SOURCE=..\alpha1.bmp
# End Source File
# Begin Source File

SOURCE=..\alpha2.bmp
# End Source File
# Begin Source File

SOURCE=..\alpha3.bmp
# End Source File
# Begin Source File

SOURCE=..\alpha4.bmp
# End Source File
# Begin Source File

SOURCE=..\alpha5.bmp
# End Source File
# Begin Source File

SOURCE=..\alpha6.bmp
# End Source File
# Begin Source File

SOURCE=..\alpha7.bmp
# End Source File
# Begin Source File

SOURCE=..\alpha8.bmp
# End Source File
# Begin Source File

SOURCE=..\alpha9.bmp
# End Source File
# Begin Source File

SOURCE=..\AMOEBE.WAV
# End Source File
# Begin Source File

SOURCE=..\APPLAUSE.WAV
# End Source File
# Begin Source File

SOURCE=..\bg.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_bb1.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_bb2.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_bb3.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_bb4.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_ch1.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_ch2.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_ch3.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_ch4.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_cl1.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_cl2.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_cl3.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_cl4.bmp
# End Source File
# Begin Source File

SOURCE=..\Bl_fs1.bmp
# End Source File
# Begin Source File

SOURCE=..\Bl_fs2.bmp
# End Source File
# Begin Source File

SOURCE=..\Bl_fs3.bmp
# End Source File
# Begin Source File

SOURCE=..\Bl_fs4.bmp
# End Source File
# Begin Source File

SOURCE=..\Bl_fz1.bmp
# End Source File
# Begin Source File

SOURCE=..\Bl_fz2.bmp
# End Source File
# Begin Source File

SOURCE=..\Bl_fz3.bmp
# End Source File
# Begin Source File

SOURCE=..\Bl_fz4.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_gs1.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_gs2.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_gs3.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_gs4.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_ks1.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_ks2.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_ks3.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_ks4.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_rt1.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_rt2.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_rt3.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_rt4.bmp
# End Source File
# Begin Source File

SOURCE=..\BL_sf1.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_sf2.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_sf3.bmp
# End Source File
# Begin Source File

SOURCE=..\bl_sf4.bmp
# End Source File
# Begin Source File

SOURCE=..\block1.bmp
# End Source File
# Begin Source File

SOURCE=..\blockl.bmp
# End Source File
# Begin Source File

SOURCE=..\COMIC.TTF
# End Source File
# Begin Source File

SOURCE=..\credits.bmp
# End Source File
# Begin Source File

SOURCE=..\expl1.bmp
# End Source File
# Begin Source File

SOURCE=..\expl10.bmp
# End Source File
# Begin Source File

SOURCE=..\expl2.bmp
# End Source File
# Begin Source File

SOURCE=..\expl3.bmp
# End Source File
# Begin Source File

SOURCE=..\expl4.bmp
# End Source File
# Begin Source File

SOURCE=..\expl5.bmp
# End Source File
# Begin Source File

SOURCE=..\expl6.bmp
# End Source File
# Begin Source File

SOURCE=..\expl7.bmp
# End Source File
# Begin Source File

SOURCE=..\expl8.bmp
# End Source File
# Begin Source File

SOURCE=..\expl9.bmp
# End Source File
# Begin Source File

SOURCE=..\EXPLODE.WAV
# End Source File
# Begin Source File

SOURCE=..\help.bmp
# End Source File
# Begin Source File

SOURCE=..\highscore.dat
# End Source File
# Begin Source File

SOURCE=..\hsbg.bmp
# End Source File
# Begin Source File

SOURCE=..\KABUMM.WAV
# End Source File
# Begin Source File

SOURCE=..\menue.wav
# End Source File
# Begin Source File

SOURCE=..\pause.bmp
# End Source File
# Begin Source File

SOURCE=..\RICOCHET.WAV
# End Source File
# Begin Source File

SOURCE=.\SDL.dll
# End Source File
# Begin Source File

SOURCE=.\SDL_ttf.dll
# End Source File
# Begin Source File

SOURCE=..\Sound07.wav
# End Source File
# Begin Source File

SOURCE=..\spielfeld.bmp
# End Source File
# Begin Source File

SOURCE=..\tap.wav
# End Source File
# Begin Source File

SOURCE=..\WHOOSH.WAV
# End Source File
# Begin Source File

SOURCE=..\yippie.wav
# End Source File
# Begin Source File

SOURCE=..\yo.wav
# End Source File
# Begin Source File

SOURCE=.\SDL_ttf.lib
# End Source File
# Begin Source File

SOURCE=.\SDL.lib
# End Source File
# End Group
# End Target
# End Project
