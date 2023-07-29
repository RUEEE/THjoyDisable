// dllmain.cpp : 定义 DLL 应用程序的入口点。

#include "pch.h"
#include<tchar.h>
//#include <mmiscapi.h>
//#include <mmeapi.h>
//#include <timeapi.h>
//#include <joystickapi.h>
//#include <mmsystem.h>
// 
//joyGetDevCapsA
//timeEndPeriod
//timeBeginPeriod
//timeGetTime
//joyGetPosEx


typedef void* LPJOYINFOEX;
typedef void* LPJOYCAPSA;
typedef UINT MMRESULT;
typedef MMRESULT(WINAPI* TimeEndPeriodType)(UINT);
typedef MMRESULT(WINAPI* TimeBeginPeriodType)(UINT);
typedef DWORD(WINAPI* TimeGetTimeType)();
typedef MMRESULT (WINAPI* TimeGetDevCapsType)(void* ptc,UINT cbtc);



typedef UINT    (WINAPI* MidiOutGetNumDevsType)             ();

typedef MMRESULT(WINAPI* TimeKillEventType)                 (UINT timerid);
typedef MMRESULT(WINAPI* MidiOutCloseType)                  (DWORD hmo);
typedef MMRESULT(WINAPI* MidiOutResetType)                  (DWORD hmo);

typedef MMRESULT(WINAPI* MmioCloseType)                     (DWORD hmmio,       UINT fuclose);
typedef MMRESULT(WINAPI* MidiOutShortMsgType)               (DWORD hmo,         DWORD  dwmsg);

typedef LONG    (WINAPI* MmioSeekType)                      (DWORD hmmio,       LONG  lOffset,      int iOrigin);
typedef MMRESULT(WINAPI* MmioGetInfoType)                   (DWORD hmmio,       DWORD  pmmioinfo,   UINT fuInfo);
typedef MMRESULT(WINAPI* MmioSetInfoType)                   (DWORD hmmio,       DWORD  pmmioinfo,   UINT fuInfo);
typedef LONG    (WINAPI* MmioReadType)                      (DWORD hmmio,       char*  lOffset,     LONG iOrigin);
typedef MMRESULT(WINAPI* MmioAscendType)                    (DWORD hmmio,       DWORD  pmmcki,      UINT fudesend);
typedef DWORD   (WINAPI* MmioOpenAType)                     (LPSTR pszFileName, LONG  pmmioinfo,    DWORD fdwOpen);
typedef MMRESULT(WINAPI* MidiOutUnprepareHeaderType)        (DWORD hmo  ,       DWORD  pmh,         UINT cbmh);
typedef MMRESULT(WINAPI* MidiOutLongMsgType)                (DWORD hmo,         DWORD  pmh,         UINT cbmh);
typedef MMRESULT(WINAPI* MidiOutPrepareHeaderType)          (DWORD hmo,         DWORD  pmh,         UINT cbmh);
typedef MMRESULT(WINAPI* MmioAdvanceType)                   (DWORD hmmio,       DWORD  pmmioinfo,   UINT fuadvance);
typedef MMRESULT(WINAPI* MidiOutGetDevCapsAType)            (UINT_PTR deviceid, DWORD  pmoc,        UINT cbmoc);

typedef MMRESULT(WINAPI* MmioDescendType)                   (DWORD hmmio,       DWORD  pmmcki,      DWORD  pmmckiparent,    UINT fudesend);
typedef MMRESULT(WINAPI* TimeSetEventType)                  (UINT udelay,       UINT  uresolution,  DWORD fptc,             DWORD dwUser,       UINT fuevent );

typedef MMRESULT(WINAPI* MidiOutOpenType)                   (DWORD phmo,        UINT  deviceid,     DWORD_PTR dwcallback,   DWORD_PTR dwinstance,   DWORD fdwopen);




HMODULE                       g_winmmModule                 ;

TimeEndPeriodType             g_timeEndPeriod               ;
TimeBeginPeriodType           g_timeBeginPeriod             ;
TimeGetTimeType               g_timeGetTime                 ;
TimeGetDevCapsType            g_timeGetDevCaps              ;
MmioSeekType                  g_mmioSeek                    ;
MmioGetInfoType               g_mmioGetInfo                 ;
MmioSetInfoType               g_mmioSetInfo                 ;
MmioDescendType               g_mmioDescend                 ;
MmioReadType                  g_mmioRead                    ;
MmioAscendType                g_mmioAscend                  ;
MmioOpenAType                 g_mmioOpenA                   ;
MmioCloseType                 g_mmioClose                   ;
MidiOutUnprepareHeaderType    g_midiOutUnprepareHeader      ;
TimeKillEventType             g_timeKillEvent               ;
TimeSetEventType              g_timeSetEvent                ;
MidiOutShortMsgType           g_midiOutShortMsg             ;
MidiOutPrepareHeaderType      g_midiOutPrepareHeader        ;
MidiOutLongMsgType            g_midiOutLongMsg              ;
MidiOutResetType              g_midiOutReset                ;
MidiOutCloseType              g_midiOutClose                ;
MidiOutOpenType               g_midiOutOpen                 ;
MidiOutGetNumDevsType         g_midiOutGetNumDevs           ;
MmioAdvanceType               g_mmioAdvance                 ;
MidiOutGetDevCapsAType        g_midiOutGetDevCapsA;

extern "C" {
    MMRESULT WINAPI m_timeGetDevCaps        (void* ptc, UINT cbtc) {return g_timeGetDevCaps(ptc, cbtc);}
    MMRESULT WINAPI m_timeEndPeriod         (UINT a) {return g_timeEndPeriod (a);}
    MMRESULT WINAPI m_timeBeginPeriod       (UINT a) {return g_timeBeginPeriod(a);}
    DWORD WINAPI m_timeGetTime              () { return g_timeGetTime();}
    MMRESULT WINAPI m_joyGetDevCapsA        (UINT uJoyID,LPJOYCAPSA pjc,UINT cbjc){return 6;}
    MMRESULT WINAPI m_joyGetPosEx           (UINT uJoyID, LPJOYINFOEX pji) { return 6;}

    UINT     WINAPI m_midiOutGetNumDevs     ()	{return g_midiOutGetNumDevs();}

    MMRESULT WINAPI m_timeKillEvent         (UINT timerid){return g_timeKillEvent(timerid);}
    MMRESULT WINAPI m_midiOutClose          (DWORD hmo){return g_midiOutClose(hmo);}
    MMRESULT WINAPI m_midiOutReset          (DWORD hmo){return g_midiOutReset(hmo);}
    
    MMRESULT WINAPI m_mmioClose             (DWORD hmmio,       UINT fuclose){return g_mmioClose(hmmio,fuclose);}
    MMRESULT WINAPI m_midiOutShortMsg       (DWORD hmo,         DWORD  dwmsg){return g_midiOutShortMsg(hmo,dwmsg);}
    
    LONG     WINAPI m_mmioSeek              (DWORD hmmio,       LONG  lOffset,      int iOrigin)		{return g_mmioSeek          (hmmio,lOffset,iOrigin);}
    MMRESULT WINAPI m_mmioGetInfo           (DWORD hmmio,       DWORD  pmmioinfo,   UINT fuInfo)		{return g_mmioGetInfo       (hmmio,pmmioinfo,fuInfo);}
    MMRESULT WINAPI m_mmioSetInfo           (DWORD hmmio,       DWORD  pmmioinfo,   UINT fuInfo)		{return g_mmioSetInfo       (hmmio,pmmioinfo,fuInfo);}
    LONG     WINAPI m_mmioRead              (DWORD hmmio,       char*  lOffset,     LONG iOrigin)		{return g_mmioRead          (hmmio,lOffset,iOrigin);}
    MMRESULT WINAPI m_mmioAscend            (DWORD hmmio,       DWORD  pmmcki,      UINT fudesend)	{return g_mmioAscend            (hmmio,pmmcki,fudesend);}
    DWORD    WINAPI m_mmioOpenA             (LPSTR pszFileName, LONG  pmmioinfo,    DWORD fdwOpen)	{return g_mmioOpenA             (pszFileName,pmmioinfo,fdwOpen);}
    MMRESULT WINAPI m_midiOutUnprepareHeader(DWORD hmo  ,       DWORD  pmh,         UINT cbmh)		{return g_midiOutUnprepareHeader(hmo,pmh,cbmh);}
    MMRESULT WINAPI m_midiOutLongMsg        (DWORD hmo,         DWORD  pmh,         UINT cbmh)		{return g_midiOutLongMsg        (hmo,pmh,cbmh);}
    MMRESULT WINAPI m_midiOutPrepareHeader  (DWORD hmo,         DWORD  pmh,         UINT cbmh)		{return g_midiOutPrepareHeader  (hmo,pmh,cbmh);}
    MMRESULT WINAPI m_mmioAdvance           (DWORD hmmio,       DWORD  pmmioinfo,   UINT fuadvance)	{return g_mmioAdvance           (hmmio,pmmioinfo,fuadvance);}
    MMRESULT WINAPI m_midiOutGetDevCapsA    (UINT_PTR deviceid, DWORD  pmoc,        UINT cbmoc)     {return g_midiOutGetDevCapsA(deviceid,pmoc,cbmoc); }
    
    MMRESULT WINAPI m_mmioDescend           (DWORD hmmio,       DWORD  pmmcki,      DWORD  pmmckiparent,    UINT fudesend){return g_mmioDescend(hmmio,pmmcki,pmmckiparent,fudesend);}
   
    MMRESULT WINAPI m_timeSetEvent          (UINT udelay,       UINT  uresolution,  DWORD fptc,             DWORD dwUser,           UINT fuevent ){return g_timeSetEvent(udelay,uresolution,fptc,dwUser,fuevent);}
    MMRESULT WINAPI m_midiOutOpen           (DWORD phmo,        UINT  deviceid,     DWORD_PTR dwcallback,   DWORD_PTR dwinstance,   DWORD fdwopen){return g_midiOutOpen(phmo,deviceid,dwcallback,dwinstance, fdwopen);}

}
#pragma comment(linker, "/EXPORT:timeGetTime=_m_timeGetTime@0")
#pragma comment(linker, "/EXPORT:timeEndPeriod=_m_timeEndPeriod@4")
#pragma comment(linker, "/EXPORT:timeBeginPeriod=_m_timeBeginPeriod@4")
#pragma comment(linker, "/EXPORT:joyGetPosEx=_m_joyGetPosEx@8")
#pragma comment(linker, "/EXPORT:timeGetDevCaps=_m_timeGetDevCaps@8")
#pragma comment(linker, "/EXPORT:joyGetDevCapsA=_m_joyGetDevCapsA@12")


#pragma comment(linker, "/EXPORT:midiOutGetNumDevs=_m_midiOutGetNumDevs@0")

#pragma comment(linker, "/EXPORT:timeKillEvent=_m_timeKillEvent@4")
#pragma comment(linker, "/EXPORT:midiOutClose=_m_midiOutClose@4")
#pragma comment(linker, "/EXPORT:midiOutReset=_m_midiOutReset@4")

#pragma comment(linker, "/EXPORT:mmioClose=_m_mmioClose@8")
#pragma comment(linker, "/EXPORT:midiOutShortMsg=_m_midiOutShortMsg@8")

#pragma comment(linker, "/EXPORT:mmioSeek=_m_mmioSeek@12")
#pragma comment(linker, "/EXPORT:mmioGetInfo=_m_mmioGetInfo@12")
#pragma comment(linker, "/EXPORT:mmioSetInfo=_m_mmioSetInfo@12")
#pragma comment(linker, "/EXPORT:mmioRead=_m_mmioRead@12")
#pragma comment(linker, "/EXPORT:mmioAscend=_m_mmioAscend@12")
#pragma comment(linker, "/EXPORT:mmioOpenA=_m_mmioOpenA@12")
#pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=_m_midiOutUnprepareHeader@12")
#pragma comment(linker, "/EXPORT:midiOutLongMsg=_m_midiOutLongMsg@12")
#pragma comment(linker, "/EXPORT:midiOutPrepareHeader=_m_midiOutPrepareHeader@12")
#pragma comment(linker, "/EXPORT:mmioAdvance=_m_mmioAdvance@12")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=_m_midiOutGetDevCapsA@12")

#pragma comment(linker, "/EXPORT:mmioDescend=_m_mmioDescend@16")

#pragma comment(linker, "/EXPORT:timeSetEvent=_m_timeSetEvent@20")
#pragma comment(linker, "/EXPORT:midiOutOpen=_m_midiOutOpen@20")


#define GET_ADDR(x)  g_##x=(decltype(g_##x))GetProcAddress(g_winmmModule,#x);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    TCHAR DLLPath[MAX_PATH];
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        GetEnvironmentVariable(_T("windir"), DLLPath, MAX_PATH);
        _tcscat_s(DLLPath, _T("\\System32\\WINMM.dll"));
        g_winmmModule = LoadLibrary(DLLPath);
        GET_ADDR(timeEndPeriod)
        GET_ADDR(timeBeginPeriod)
        GET_ADDR(timeGetTime)
        GET_ADDR(timeGetDevCaps)
        GET_ADDR(mmioSeek)
        GET_ADDR(mmioGetInfo)
        GET_ADDR(mmioSetInfo)
        GET_ADDR(mmioDescend)
        GET_ADDR(mmioRead)
        GET_ADDR(mmioAscend)
        GET_ADDR(mmioOpenA)
        GET_ADDR(mmioClose)
        GET_ADDR(midiOutUnprepareHeader)
        GET_ADDR(timeKillEvent)
        GET_ADDR(timeSetEvent)
        GET_ADDR(midiOutShortMsg)
        GET_ADDR(midiOutPrepareHeader)
        GET_ADDR(midiOutLongMsg)
        GET_ADDR(midiOutReset)
        GET_ADDR(midiOutClose)
        GET_ADDR(midiOutOpen)
        GET_ADDR(midiOutGetNumDevs)
        GET_ADDR(mmioAdvance)
        GET_ADDR(midiOutGetDevCapsA)
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

