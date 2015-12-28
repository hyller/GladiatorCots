#ifndef _IMM_H
#define _IMM_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif
#define WM_CONVERTREQUESTEX 0x108
#define WM_IME_STARTCOMPOSITION 0x10D
#define WM_IME_ENDCOMPOSITION 0x10E
#define WM_IME_COMPOSITION 0x10F
#define WM_IME_KEYLAST 0x10F
#define WM_IME_SETCONTEXT 0x281
#define WM_IME_NOTIFY 0x282
#define WM_IME_CONTROL 0x283
#define WM_IME_COMPOSITIONFULL 0x284
#define WM_IME_SELECT 0x285
#define WM_IME_CHAR 0x286
#define WM_IME_KEYDOWN 0x290
#define WM_IME_KEYUP 0x291
#if (_WIN32_WINNT >= 0x0500)
#define WM_IME_REQUEST 0x0288
#endif
#define IMC_GETCANDIDATEPOS 7
#define IMC_SETCANDIDATEPOS 8
#define IMC_GETCOMPOSITIONFONT 9
#define IMC_SETCOMPOSITIONFONT 10
#define IMC_GETCOMPOSITIONWINDOW 11
#define IMC_SETCOMPOSITIONWINDOW 12
#define IMC_GETSTATUSWINDOWPOS 15
#define IMC_SETSTATUSWINDOWPOS 16
#define IMC_CLOSESTATUSWINDOW 0x21
#define IMC_OPENSTATUSWINDOW 0x22
#define IMN_CLOSESTATUSWINDOW 1
#define IMN_OPENSTATUSWINDOW 2
#define IMN_CHANGECANDIDATE 3
#define IMN_CLOSECANDIDATE 4
#define IMN_OPENCANDIDATE 5
#define IMN_SETCONVERSIONMODE 6
#define IMN_SETSENTENCEMODE 7
#define IMN_SETOPENSTATUS 8
#define IMN_SETCANDIDATEPOS 9
#define IMN_SETCOMPOSITIONFONT 10
#define IMN_SETCOMPOSITIONWINDOW 11
#define IMN_SETSTATUSWINDOWPOS 12
#define IMN_GUIDELINE 13
#define IMN_PRIVATE 14
#define NI_OPENCANDIDATE 16
#define NI_CLOSECANDIDATE 17
#define NI_SELECTCANDIDATESTR 18
#define NI_CHANGECANDIDATELIST 19
#define NI_FINALIZECONVERSIONRESULT 20
#define NI_COMPOSITIONSTR 21
#define NI_SETCANDIDATE_PAGESTART 22
#define NI_SETCANDIDATE_PAGESIZE 23
#define NI_IMEMENUSELECTED 24
#define ISC_SHOWUICANDIDATEWINDOW 1
#define ISC_SHOWUICOMPOSITIONWINDOW 0x80000000
#define ISC_SHOWUIGUIDELINE 0x40000000
#define ISC_SHOWUIALLCANDIDATEWINDOW 15
#define ISC_SHOWUIALL 0xC000000F
#define CPS_COMPLETE 1
#define CPS_CONVERT 2
#define CPS_REVERT 3
#define CPS_CANCEL 4
#define IME_CHOTKEY_IME_NONIME_TOGGLE 16
#define IME_CHOTKEY_SHAPE_TOGGLE 17
#define IME_CHOTKEY_SYMBOL_TOGGLE 18
#define IME_JHOTKEY_CLOSE_OPEN 0x30
#define IME_KHOTKEY_SHAPE_TOGGLE 0x50
#define IME_KHOTKEY_HANJACONVERT 0x51
#define IME_KHOTKEY_ENGLISH 0x52
#define IME_THOTKEY_IME_NONIME_TOGGLE 0x70
#define IME_THOTKEY_SHAPE_TOGGLE 0x71
#define IME_THOTKEY_SYMBOL_TOGGLE 0x72
#define IME_HOTKEY_DSWITCH_FIRST 256
#define IME_HOTKEY_DSWITCH_LAST 0x11F
#define IME_ITHOTKEY_RESEND_RESULTSTR 512
#define IME_ITHOTKEY_PREVIOUS_COMPOSITION 513
#define IME_ITHOTKEY_UISTYLE_TOGGLE 514
#define GCS_COMPREADSTR 1
#define GCS_COMPREADATTR 2
#define GCS_COMPREADCLAUSE 4
#define GCS_COMPSTR 8
#define GCS_COMPATTR 16
#define GCS_COMPCLAUSE 32
#define GCS_CURSORPOS 128
#define GCS_DELTASTART 256
#define GCS_RESULTREADSTR 512
#define GCS_RESULTREADCLAUSE 1024
#define GCS_RESULTSTR 2048
#define GCS_RESULTCLAUSE 4096
#define CS_INSERTCHAR 0x2000
#define CS_NOMOVECARET 0x4000
#define IMEVER_0310 0x3000A
#define IMEVER_0400 0x40000
#define IME_PROP_AT_CARET 0x10000
#define IME_PROP_SPECIAL_UI 0x20000
#define IME_PROP_CANDLIST_START_FROM_1 0x40000
#define IME_PROP_UNICODE 0x80000
#define UI_CAP_2700 1
#define UI_CAP_ROT90 2
#define UI_CAP_ROTANY 4
#define SCS_CAP_COMPSTR 1
#define SCS_CAP_MAKEREAD 2
#define SELECT_CAP_CONVERSION 1
#define SELECT_CAP_SENTENCE 2
#define GGL_LEVEL 1
#define GGL_INDEX 2
#define GGL_STRING 3
#define GGL_PRIVATE 4
#define GL_LEVEL_NOGUIDELINE 0
#define GL_LEVEL_FATAL 1
#define GL_LEVEL_ERROR 2
#define GL_LEVEL_WARNING 3
#define GL_LEVEL_INFORMATION 4
#define GL_ID_UNKNOWN 0
#define GL_ID_NOMODULE 1
#define GL_ID_NODICTIONARY 16
#define GL_ID_CANNOTSAVE 17
#define GL_ID_NOCONVERT 32
#define GL_ID_TYPINGERROR 33
#define GL_ID_TOOMANYSTROKE 34
#define GL_ID_READINGCONFLICT 35
#define GL_ID_INPUTREADING 36
#define GL_ID_INPUTRADICAL 37
#define GL_ID_INPUTCODE 38
#define GL_ID_INPUTSYMBOL 39
#define GL_ID_CHOOSECANDIDATE 40
#define GL_ID_REVERSECONVERSION 41
#define GL_ID_PRIVATE_FIRST 0x8000
#define GL_ID_PRIVATE_LAST 0xFFFF
#define IGP_GETIMEVERSION (DWORD)(-4)
#define IGP_PROPERTY 4
#define IGP_CONVERSION 8
#define IGP_SENTENCE 12
#define IGP_UI 16
#define IGP_SETCOMPSTR 0x14
#define IGP_SELECT 0x18
#define SCS_SETSTR (GCS_COMPREADSTR|GCS_COMPSTR)
#define SCS_CHANGEATTR (GCS_COMPREADATTR|GCS_COMPATTR)
#define SCS_CHANGECLAUSE (GCS_COMPREADCLAUSE|GCS_COMPCLAUSE)
#define ATTR_INPUT 0
#define ATTR_TARGET_CONVERTED 1
#define ATTR_CONVERTED 2
#define ATTR_TARGET_NOTCONVERTED 3
#define ATTR_INPUT_ERROR 4
#define ATTR_FIXEDCONVERTED 5
#define CFS_DEFAULT 0
#define CFS_RECT 1
#define CFS_POINT 2
#define CFS_SCREEN 4
#define CFS_FORCE_POSITION 32
#define CFS_CANDIDATEPOS 64
#define CFS_EXCLUDE 128
#define GCL_CONVERSION 1
#define GCL_REVERSECONVERSION 2
#define GCL_REVERSE_LENGTH 3
#define IME_CMODE_ALPHANUMERIC 0
#define IME_CMODE_NATIVE 1
#define IME_CMODE_CHINESE IME_CMODE_NATIVE
#define IME_CMODE_HANGEUL IME_CMODE_NATIVE
#define IME_CMODE_HANGUL IME_CMODE_NATIVE
#define IME_CMODE_JAPANESE IME_CMODE_NATIVE
#define IME_CMODE_KATAKANA 2
#define IME_CMODE_LANGUAGE 3
#define IME_CMODE_FULLSHAPE 8
#define IME_CMODE_ROMAN 16
#define IME_CMODE_CHARCODE 32
#define IME_CMODE_HANJACONVERT 64
#define IME_CMODE_SOFTKBD 128
#define IME_CMODE_NOCONVERSION 256
#define IME_CMODE_EUDC 512
#define IME_CMODE_SYMBOL 1024
#define IME_CMODE_FIXED 2048
#define IME_SMODE_NONE 0
#define IME_SMODE_PLAURALCLAUSE 1
#define IME_SMODE_SINGLECONVERT 2
#define IME_SMODE_AUTOMATIC 4
#define IME_SMODE_PHRASEPREDICT 8
#define IME_CAND_UNKNOWN 0
#define IME_CAND_READ 1
#define IME_CAND_CODE 2
#define IME_CAND_MEANING 3
#define IME_CAND_RADICAL 4
#define IME_CAND_STROKE 5
#define IMM_ERROR_NODATA (-1)
#define IMM_ERROR_GENERAL (-2)
#define IME_CONFIG_GENERAL 1
#define IME_CONFIG_REGISTERWORD 2
#define IME_CONFIG_SELECTDICTIONARY 3
#define IME_ESC_QUERY_SUPPORT 3
#define IME_ESC_RESERVED_FIRST 4
#define IME_ESC_RESERVED_LAST 0x7FF
#define IME_ESC_PRIVATE_FIRST 0x800
#define IME_ESC_PRIVATE_LAST 0xFFF
#define IME_ESC_SEQUENCE_TO_INTERNAL 0x1001
#define IME_ESC_GET_EUDC_DICTIONARY 0x1003
#define IME_ESC_SET_EUDC_DICTIONARY 0x1004
#define IME_ESC_MAX_KEY 0x1005
#define IME_ESC_IME_NAME 0x1006
#define IME_ESC_SYNC_HOTKEY 0x1007
#define IME_ESC_HANJA_MODE 0x1008
#define IME_ESC_AUTOMATA 0x1009
#define IME_REGWORD_STYLE_EUDC 1
#define IME_REGWORD_STYLE_USER_FIRST 0x80000000
#define IME_REGWORD_STYLE_USER_LAST 0xFFFFFFFF
#define IMR_RECONVERTSTRING 4
#define IMR_QUERYCHARPOSITION 6
#define SOFTKEYBOARD_TYPE_T1 1
#define SOFTKEYBOARD_TYPE_C1 2
#define IMEMENUITEM_STRING_SIZE 80
#define MOD_ALT 1
#define MOD_CONTROL 2
#define MOD_SHIFT 4
#define MOD_WIN 8
#define MOD_IGNORE_ALL_MODIFIER 1024
#define MOD_ON_KEYUP  2048
#define MOD_RIGHT 16384
#define MOD_LEFT 32768
#define IACE_CHILDREN 1
#define IACE_DEFAULT 16
#define IACE_IGNORENOCONTEXT 32
#define IGIMIF_RIGHTMENU 1
#define IGIMII_CMODE 1
#define IGIMII_SMODE 2
#define IGIMII_CONFIGURE 4
#define IGIMII_TOOLS 8
#define IGIMII_HELP 16
#define IGIMII_OTHER 32
#define IGIMII_INPUTTOOLS 64
#define IMFT_RADIOCHECK 1
#define IMFT_SEPARATOR 2
#define IMFT_SUBMENU 4
#define IMFS_GRAYED MFS_GRAYED
#define IMFS_DISABLED MFS_DISABLED
#define IMFS_CHECKED MFS_CHECKED
#define IMFS_HILITE MFS_HILITE
#define IMFS_ENABLED MFS_ENABLED
#define IMFS_UNCHECKED MFS_UNCHECKED
#define IMFS_UNHILITE MFS_UNHILITE
#define IMFS_DEFAULT MFS_DEFAULT
#ifndef VK_PROCESSKEY
#define VK_PROCESSKEY 0x0E5
#endif
#define STYLE_DESCRIPTION_SIZE 32
typedef DWORD HIMC;
typedef DWORD HIMCC;
typedef HKL *LPHKL;
typedef struct tagCOMPOSITIONFORM {
    DWORD dwStyle;
    POINT ptCurrentPos;
    RECT rcArea;
} COMPOSITIONFORM,*PCOMPOSITIONFORM,*LPCOMPOSITIONFORM;
typedef struct tagCANDIDATEFORM {
    DWORD dwIndex;
    DWORD dwStyle;
    POINT ptCurrentPos;
    RECT rcArea;
} CANDIDATEFORM,*PCANDIDATEFORM,*LPCANDIDATEFORM;
typedef struct tagCANDIDATELIST {
    DWORD dwSize;
    DWORD dwStyle;
    DWORD dwCount;
    DWORD dwSelection;
    DWORD dwPageStart;
    DWORD dwPageSize;
    DWORD dwOffset[1];
} CANDIDATELIST,*PCANDIDATELIST,*LPCANDIDATELIST;
typedef struct tagIMECHARPOSITION {
  DWORD  dwSize;
  DWORD  dwCharPos;
  POINT  pt;
  UINT   cLineHeight;
  RECT   rcDocument;
} IMECHARPOSITION, *PIMECHARPOSITION;
typedef struct tagRECONVERTSTRING {
  DWORD dwSize;
  DWORD dwVersion;
  DWORD dwStrLen;
  DWORD dwStrOffset;
  DWORD dwCompStrLen;
  DWORD dwCompStrOffset;
  DWORD dwTargetStrLen;
  DWORD dwTargetStrOffset;
} RECONVERTSTRING, *PRECONVERTSTRING;
typedef struct tagREGISTERWORDA {
    LPSTR lpReading;
    LPSTR lpWord;
} REGISTERWORDA,*PREGISTERWORDA,*LPREGISTERWORDA;
typedef struct tagREGISTERWORDW {
    LPWSTR lpReading;
    LPWSTR lpWord;
} REGISTERWORDW,*PREGISTERWORDW,*LPREGISTERWORDW;
typedef struct tagSTYLEBUFA {
    DWORD dwStyle;
    CHAR szDescription[STYLE_DESCRIPTION_SIZE];
} STYLEBUFA,*PSTYLEBUFA,*LPSTYLEBUFA;
typedef struct tagSTYLEBUFW {
    DWORD dwStyle;
    WCHAR szDescription[STYLE_DESCRIPTION_SIZE];
} STYLEBUFW,*PSTYLEBUFW,*LPSTYLEBUFW;
typedef struct tagIMEMENUITEMINFOA {
    UINT cbSize;
    UINT fType;
    UINT fState;
    UINT wID;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    DWORD dwItemData;
    CHAR szString[IMEMENUITEM_STRING_SIZE];
    HBITMAP hbmpItem;
} IMEMENUITEMINFOA,*PIMEMENUITEMINFOA,*LPIMEMENUITEMINFOA;
typedef struct tagIMEMENUITEMINFOW {
    UINT cbSize;
    UINT fType;
    UINT fState;
    UINT wID;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    DWORD dwItemData;
    WCHAR szString[IMEMENUITEM_STRING_SIZE];
    HBITMAP hbmpItem;
} IMEMENUITEMINFOW,*PIMEMENUITEMINFOW,*LPIMEMENUITEMINFOW;
typedef int (CALLBACK *REGISTERWORDENUMPROCA)(LPCSTR, DWORD, LPCSTR, LPVOID);
typedef int (CALLBACK *REGISTERWORDENUMPROCW)(LPCWSTR, DWORD, LPCWSTR, LPVOID);
#ifdef UNICODE
#define REGISTERWORDENUMPROC REGISTERWORDENUMPROCW
typedef REGISTERWORDW REGISTERWORD,*PREGISTERWORD,*LPREGISTERWORD;
typedef STYLEBUFW STYLEBUF,*PSTYLEBUF,*LPSTYLEBUF;
typedef IMEMENUITEMINFOW IMEMENUITEMINFO,*PIMEMENUITEMINFO,*LPIMEMENUITEMINFO;
#else
#define REGISTERWORDENUMPROC REGISTERWORDENUMPROCA
typedef REGISTERWORDA REGISTERWORD,*PREGISTERWORD,*LPREGISTERWORD;
typedef STYLEBUFA STYLEBUF,*PSTYLEBUF,*LPSTYLEBUF;
typedef IMEMENUITEMINFOA IMEMENUITEMINFO,*PIMEMENUITEMINFO,*LPIMEMENUITEMINFO;
#endif
HKL WINAPI ImmInstallIMEA(LPCSTR,LPCSTR);
HKL WINAPI ImmInstallIMEW(LPCWSTR,LPCWSTR);
HWND WINAPI ImmGetDefaultIMEWnd(HWND);
UINT WINAPI ImmGetDescriptionA(HKL,LPSTR,UINT);
UINT WINAPI ImmGetDescriptionW(HKL,LPWSTR,UINT);
UINT WINAPI ImmGetIMEFileNameA(HKL,LPSTR,UINT);
UINT WINAPI ImmGetIMEFileNameW(HKL,LPWSTR,UINT);
DWORD WINAPI ImmGetProperty(HKL,DWORD);
BOOL WINAPI ImmIsIME(HKL);
BOOL WINAPI ImmSimulateHotKey(HWND,DWORD);
HIMC WINAPI ImmCreateContext(void);
BOOL WINAPI ImmDestroyContext(HIMC);
HIMC WINAPI ImmGetContext(HWND);
BOOL WINAPI ImmReleaseContext(HWND,HIMC);
HIMC WINAPI ImmAssociateContext(HWND,HIMC);
LONG WINAPI ImmGetCompositionStringA(HIMC,DWORD,PVOID,DWORD);
LONG WINAPI ImmGetCompositionStringW(HIMC,DWORD,PVOID,DWORD);
BOOL WINAPI ImmSetCompositionStringA(HIMC,DWORD,PCVOID,DWORD,PCVOID,DWORD);
BOOL WINAPI ImmSetCompositionStringW(HIMC,DWORD,PCVOID,DWORD,PCVOID,DWORD);
DWORD WINAPI ImmGetCandidateListCountA(HIMC,PDWORD);
DWORD WINAPI ImmGetCandidateListCountW(HIMC,PDWORD);
DWORD WINAPI ImmGetCandidateListA(HIMC,DWORD,PCANDIDATELIST,DWORD);
DWORD WINAPI ImmGetCandidateListW(HIMC,DWORD,PCANDIDATELIST,DWORD);
DWORD WINAPI ImmGetGuideLineA(HIMC,DWORD,LPSTR,DWORD);
DWORD WINAPI ImmGetGuideLineW(HIMC,DWORD,LPWSTR,DWORD);
BOOL WINAPI ImmGetConversionStatus(HIMC,LPDWORD,PDWORD);
BOOL WINAPI ImmSetConversionStatus(HIMC,DWORD,DWORD);
BOOL WINAPI ImmGetOpenStatus(HIMC);
BOOL WINAPI ImmSetOpenStatus(HIMC,BOOL);
#ifndef NOGDI
BOOL WINAPI ImmGetCompositionFontA(HIMC,LPLOGFONTA);
BOOL WINAPI ImmGetCompositionFontW(HIMC,LPLOGFONTW);
BOOL WINAPI ImmSetCompositionFontA(HIMC,LPLOGFONTA);
BOOL WINAPI ImmSetCompositionFontW(HIMC,LPLOGFONTW);
#endif
BOOL WINAPI ImmConfigureIMEA(HKL,HWND,DWORD,PVOID);
BOOL WINAPI ImmConfigureIMEW(HKL,HWND,DWORD,PVOID);
LRESULT WINAPI ImmEscapeA(HKL,HIMC,UINT,PVOID);
LRESULT WINAPI ImmEscapeW(HKL,HIMC,UINT,PVOID);
DWORD WINAPI ImmGetConversionListA(HKL,HIMC,LPCSTR,PCANDIDATELIST,DWORD,UINT);
DWORD WINAPI ImmGetConversionListW(HKL,HIMC,LPCWSTR,PCANDIDATELIST,DWORD,UINT);
BOOL WINAPI ImmNotifyIME(HIMC,DWORD,DWORD,DWORD);
BOOL WINAPI ImmGetStatusWindowPos(HIMC,LPPOINT);
BOOL WINAPI ImmSetStatusWindowPos(HIMC,LPPOINT);
BOOL WINAPI ImmGetCompositionWindow(HIMC,PCOMPOSITIONFORM);
BOOL WINAPI ImmSetCompositionWindow(HIMC,PCOMPOSITIONFORM);
BOOL WINAPI ImmGetCandidateWindow(HIMC,DWORD,PCANDIDATEFORM);
BOOL WINAPI ImmSetCandidateWindow(HIMC,PCANDIDATEFORM);
BOOL WINAPI ImmIsUIMessageA(HWND,UINT,WPARAM,LPARAM);
BOOL WINAPI ImmIsUIMessageW(HWND,UINT,WPARAM,LPARAM);
UINT WINAPI ImmGetVirtualKey(HWND);
BOOL WINAPI ImmRegisterWordA(HKL,LPCSTR,DWORD,LPCSTR);
BOOL WINAPI ImmRegisterWordW(HKL,LPCWSTR,DWORD,LPCWSTR);
BOOL WINAPI ImmUnregisterWordA(HKL,LPCSTR,DWORD,LPCSTR);
BOOL WINAPI ImmUnregisterWordW(HKL,LPCWSTR,DWORD,LPCWSTR);
UINT WINAPI ImmGetRegisterWordStyleA(HKL,UINT,PSTYLEBUFA);
UINT WINAPI ImmGetRegisterWordStyleW(HKL,UINT,PSTYLEBUFW);
UINT WINAPI ImmEnumRegisterWordA(HKL,REGISTERWORDENUMPROCA,LPCSTR,DWORD,LPCSTR,PVOID);
UINT WINAPI ImmEnumRegisterWordW(HKL,REGISTERWORDENUMPROCW,LPCWSTR,DWORD,LPCWSTR,PVOID);
BOOL WINAPI EnableEUDC(BOOL);
BOOL WINAPI ImmDisableIME(DWORD);
DWORD WINAPI ImmGetImeMenuItemsA(HIMC,DWORD,DWORD,LPIMEMENUITEMINFOA,LPIMEMENUITEMINFOA,DWORD);
DWORD WINAPI ImmGetImeMenuItemsW(HIMC,DWORD,DWORD,LPIMEMENUITEMINFOW,LPIMEMENUITEMINFOW,DWORD);

#ifdef UNICODE
#define ImmEnumRegisterWord ImmEnumRegisterWordW
#define ImmGetRegisterWordStyle ImmGetRegisterWordStyleW
#define ImmUnregisterWord ImmUnregisterWordW
#define ImmRegisterWord ImmRegisterWordW
#define ImmInstallIME ImmInstallIMEW
#define ImmIsUIMessage ImmIsUIMessageW
#define ImmGetConversionList ImmGetConversionListW
#define ImmEscape ImmEscapeW
#define ImmConfigureIME ImmConfigureIMEW
#ifndef NOGDI
#define ImmSetCompositionFont ImmSetCompositionFontW
#define ImmGetCompositionFont ImmGetCompositionFontW
#endif
#define ImmGetGuideLine ImmGetGuideLineW
#define ImmGetCandidateList ImmGetCandidateListW
#define ImmGetCandidateListCount ImmGetCandidateListCountW
#define ImmSetCompositionString ImmSetCompositionStringW
#define ImmGetCompositionString ImmGetCompositionStringW
#define ImmGetDescription ImmGetDescriptionW
#define ImmGetIMEFileName ImmGetIMEFileNameW
#define ImmGetImeMenuItems ImmGetImeMenuItemsW
#else
#define ImmEnumRegisterWord ImmEnumRegisterWordA
#define ImmGetRegisterWordStyle ImmGetRegisterWordStyleA
#define ImmUnregisterWord ImmUnregisterWordA
#define ImmRegisterWord ImmRegisterWordA
#define ImmInstallIME ImmInstallIMEA
#define ImmIsUIMessage ImmIsUIMessageA
#define ImmGetConversionList ImmGetConversionListA
#define ImmEscape ImmEscapeA
#define ImmConfigureIME ImmConfigureIMEA
#ifndef NOGDI
#define ImmSetCompositionFont ImmSetCompositionFontA
#define ImmGetCompositionFont ImmGetCompositionFontA
#endif
#define ImmGetGuideLine ImmGetGuideLineA
#define ImmGetCandidateList ImmGetCandidateListA
#define ImmGetCandidateListCount ImmGetCandidateListCountA
#define ImmSetCompositionString ImmSetCompositionStringA
#define ImmGetCompositionString ImmGetCompositionStringA
#define ImmGetDescription ImmGetDescriptionA
#define ImmGetIMEFileName ImmGetIMEFileNameA
#define ImmGetImeMenuItems ImmGetImeMenuItemsW
#endif
#ifdef __cplusplus
}
#endif
#endif
