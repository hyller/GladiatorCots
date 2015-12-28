#ifndef _DDEML_H
#define _DDEML_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define EXPENTRY    CALLBACK
#define CP_WINANSI    1004
#define CP_WINUNICODE    1200
#define XTYPF_NOBLOCK    2
#define XTYPF_NODATA    4
#define XTYPF_ACKREQ    8
#define XCLASS_MASK    0xFC00
#define XCLASS_BOOL    0x1000
#define XCLASS_DATA    0x2000
#define XCLASS_FLAGS    0x4000
#define XCLASS_NOTIFICATION    0x8000
#define XST_NULL    0
#define XST_INCOMPLETE    1
#define XST_CONNECTED    2
#define XST_INIT1    3
#define XST_INIT2    4
#define XST_REQSENT    5
#define XST_DATARCVD    6
#define XST_POKESENT    7
#define XST_POKEACKRCVD    8
#define XST_EXECSENT    9
#define XST_EXECACKRCVD    10
#define XST_ADVSENT 11
#define XST_UNADVSENT 12
#define XST_ADVACKRCVD 13
#define XST_UNADVACKRCVD 14
#define XST_ADVDATASENT 15
#define XST_ADVDATAACKRCVD 16
#define XTYP_ERROR    (XCLASS_NOTIFICATION|XTYPF_NOBLOCK)
#define XTYP_ADVDATA    (16|XCLASS_FLAGS)
#define XTYP_ADVREQ    (32|XCLASS_DATA|XTYPF_NOBLOCK)
#define XTYP_ADVSTART    (0x30|XCLASS_BOOL)
#define XTYP_ADVSTOP    (0x0040|XCLASS_NOTIFICATION)
#define XTYP_EXECUTE    (0x0050|XCLASS_FLAGS)
#define XTYP_CONNECT    (0x0060|XCLASS_BOOL|XTYPF_NOBLOCK)
#define XTYP_CONNECT_CONFIRM    (0x0070|XCLASS_NOTIFICATION|XTYPF_NOBLOCK)
#define XTYP_XACT_COMPLETE    (0x0080|XCLASS_NOTIFICATION)
#define XTYP_POKE    (0x0090|XCLASS_FLAGS)
#define XTYP_REGISTER    (0x00A0|XCLASS_NOTIFICATION|XTYPF_NOBLOCK)
#define XTYP_REQUEST    (0x00B0|XCLASS_DATA)
#define XTYP_DISCONNECT    (0x00C0|XCLASS_NOTIFICATION|XTYPF_NOBLOCK)
#define XTYP_UNREGISTER    (0x00D0|XCLASS_NOTIFICATION|XTYPF_NOBLOCK)
#define XTYP_WILDCONNECT    (0x00E0|XCLASS_DATA|XTYPF_NOBLOCK)
#define XTYP_MASK    0xF0
#define XTYP_SHIFT    4
#define TIMEOUT_ASYNC    0xFFFFFFFF
#define QID_SYNC    0xFFFFFFFF
#define ST_CONNECTED    1
#define ST_ADVISE    2
#define ST_ISLOCAL    4
#define ST_BLOCKED    8
#define ST_CLIENT    16
#define ST_TERMINATED    32
#define ST_INLIST    64
#define ST_BLOCKNEXT    128
#define ST_ISSELF    256
#define CADV_LATEACK 0xFFFF
#define DMLERR_NO_ERROR    0
#define DMLERR_FIRST    0x4000
#define DMLERR_ADVACKTIMEOUT    0x4000
#define DMLERR_BUSY    0x4001
#define DMLERR_DATAACKTIMEOUT    0x4002
#define DMLERR_DLL_NOT_INITIALIZED    0x4003
#define    DMLERR_DLL_USAGE    0x4004
#define DMLERR_EXECACKTIMEOUT    0x4005
#define DMLERR_INVALIDPARAMETER    0x4006
#define DMLERR_LOW_MEMORY    0x4007
#define DMLERR_MEMORY_ERROR    0x4008
#define DMLERR_NOTPROCESSED    0x4009
#define DMLERR_NO_CONV_ESTABLISHED    0x400a
#define DMLERR_POKEACKTIMEOUT    0x400b
#define DMLERR_POSTMSG_FAILED    0x400c
#define DMLERR_REENTRANCY    0x400d
#define DMLERR_SERVER_DIED    0x400e
#define DMLERR_SYS_ERROR    0x400f
#define DMLERR_UNADVACKTIMEOUT    0x4010
#define DMLERR_UNFOUND_QUEUE_ID    0x4011
#define DMLERR_LAST    0x4011
#define DDE_FACK    0x8000
#define DDE_FBUSY    0x4000
#define DDE_FDEFERUPD    0x4000
#define DDE_FACKREQ    0x8000
#define DDE_FRELEASE    0x2000
#define DDE_FREQUESTED    0x1000
#define DDE_FAPPSTATUS    0x00ff
#define DDE_FNOTPROCESSED    0
#define DDE_FACKRESERVED    (~(DDE_FACK|DDE_FBUSY|DDE_FAPPSTATUS))
#define DDE_FADVRESERVED    (~(DDE_FACKREQ|DDE_FDEFERUPD))
#define DDE_FDATRESERVED    (~(DDE_FACKREQ|DDE_FRELEASE|DDE_FREQUESTED))
#define DDE_FPOKRESERVED    (~DDE_FRELEASE)
#define MSGF_DDEMGR    0x8001
#define CBR_BLOCK    ((HDDEDATA)0xffffffff)
#define CBF_FAIL_SELFCONNECTIONS    0x1000
#define CBF_FAIL_CONNECTIONS    0x2000
#define CBF_FAIL_ADVISES    0x4000
#define CBF_FAIL_EXECUTES    0x8000
#define CBF_FAIL_POKES    0x10000
#define CBF_FAIL_REQUESTS    0x20000
#define CBF_FAIL_ALLSVRXACTIONS    0x3f000
#define CBF_SKIP_CONNECT_CONFIRMS    0x40000
#define CBF_SKIP_REGISTRATIONS    0x80000
#define CBF_SKIP_UNREGISTRATIONS    0x100000
#define CBF_SKIP_DISCONNECTS    0x200000
#define CBF_SKIP_ALLNOTIFICATIONS    0x3c0000
#define APPCMD_CLIENTONLY    0x10L
#define APPCMD_FILTERINITS    0x20L
#define APPCMD_MASK    0xFF0L
#define APPCLASS_STANDARD    0
#define APPCLASS_MASK    0xFL
#define EC_ENABLEALL    0
#define EC_ENABLEONE    ST_BLOCKNEXT
#define EC_DISABLE    ST_BLOCKED
#define EC_QUERYWAITING    2
#define DNS_REGISTER    1
#define DNS_UNREGISTER    2
#define DNS_FILTERON    4
#define DNS_FILTEROFF    8
#define HDATA_APPOWNED    1
#define MAX_MONITORS    4
#define APPCLASS_MONITOR    1L
#define XTYP_MONITOR    (XCLASS_NOTIFICATION|XTYPF_NOBLOCK|0xF0)
#define MF_HSZ_INFO    0x1000000
#define MF_SENDMSGS    0x2000000
#define MF_POSTMSGS    0x4000000
#define MF_CALLBACKS    0x8000000
#define MF_ERRORS    0x10000000
#define MF_LINKS    0x20000000
#define MF_CONV    0x40000000
#define MF_MASK 0xFF000000
#define MH_CREATE    1
#define MH_KEEP    2
#define MH_DELETE    3
#define MH_CLEANUP    4

DECLARE_HANDLE(HCONVLIST);
DECLARE_HANDLE(HCONV);
DECLARE_HANDLE(HSZ);
DECLARE_HANDLE(HDDEDATA);
typedef HDDEDATA CALLBACK FNCALLBACK(UINT,UINT,HCONV,HSZ,HSZ,HDDEDATA,DWORD,DWORD);
typedef HDDEDATA(CALLBACK *PFNCALLBACK)(UINT,UINT,HCONV,HSZ,HSZ,HDDEDATA,DWORD,DWORD);
typedef struct tagHSZPAIR {
    HSZ    hszSvc;
    HSZ    hszTopic;
} HSZPAIR, *PHSZPAIR;
typedef struct tagCONVCONTEXT {
    UINT    cb;
    UINT    wFlags;
    UINT    wCountryID;
    int    iCodePage;
    DWORD    dwLangID;
    DWORD    dwSecurity;
    SECURITY_QUALITY_OF_SERVICE qos;
} CONVCONTEXT,*PCONVCONTEXT;
typedef struct tagCONVINFO {
    DWORD    cb;
    DWORD    hUser;
    HCONV    hConvPartner;
    HSZ    hszSvcPartner;
    HSZ    hszServiceReq;
    HSZ    hszTopic;
    HSZ    hszItem;
    UINT    wFmt;
    UINT    wType;
    UINT    wStatus;
    UINT    wConvst;
    UINT    wLastError;
    HCONVLIST    hConvList;
    CONVCONTEXT ConvCtxt;
    HWND    hwnd;
    HWND    hwndPartner;
} CONVINFO,*PCONVINFO;
typedef struct tagDDEML_MSG_HOOK_DATA {
    UINT    uiLo;
    UINT    uiHi;
    DWORD    cbData;
    DWORD    Data[8];
} DDEML_MSG_HOOK_DATA;
typedef struct tagMONHSZSTRUCT {
    UINT    cb;
    BOOL    fsAction;
    DWORD    dwTime;
    HSZ    hsz;
    HANDLE    hTask;
    TCHAR    str[1];
} MONHSZSTRUCT, *PMONHSZSTRUCT;
typedef struct tagMONLINKSTRUCT {
    UINT    cb;
    DWORD    dwTime;
    HANDLE    hTask;
    BOOL    fEstablished;
    BOOL    fNoData;
    HSZ    hszSvc;
    HSZ    hszTopic;
    HSZ    hszItem;
    UINT    wFmt;
    BOOL    fServer;
    HCONV    hConvServer;
    HCONV    hConvClient;
} MONLINKSTRUCT, *PMONLINKSTRUCT;
typedef struct tagMONCONVSTRUCT {
    UINT    cb;
    BOOL    fConnect;
    DWORD    dwTime;
    HANDLE    hTask;
    HSZ    hszSvc;
    HSZ    hszTopic;
    HCONV    hConvClient;
    HCONV    hConvServer;
} MONCONVSTRUCT, *PMONCONVSTRUCT;
typedef struct tagMONCBSTRUCT {
    UINT    cb;
    DWORD    dwTime;
    HANDLE    hTask;
    DWORD    dwRet;
    UINT    wType;
    UINT    wFmt;
    HCONV    hConv;
    HSZ    hsz1;
    HSZ    hsz2;
    HDDEDATA    hData;
    ULONG_PTR    dwData1;
    ULONG_PTR    dwData2;
    CONVCONTEXT    cc;
    DWORD    cbData;
    DWORD    Data[8];
} MONCBSTRUCT, *PMONCBSTRUCT;
typedef struct tagMONERRSTRUCT {
    UINT    cb;
    UINT    wLastError;
    DWORD    dwTime;
    HANDLE    hTask;
} MONERRSTRUCT, *PMONERRSTRUCT;
typedef struct tagMONMSGSTRUCT {
    UINT    cb;
    HWND    hwndTo;
    DWORD    dwTime;
    HANDLE    hTask;
    UINT    wMsg;
    WPARAM    wParam;
    LPARAM    lParam;
    DDEML_MSG_HOOK_DATA dmhd;
} MONMSGSTRUCT, *PMONMSGSTRUCT;

BOOL WINAPI DdeAbandonTransaction(DWORD,HCONV,DWORD);
PBYTE WINAPI DdeAccessData(HDDEDATA,PDWORD);
HDDEDATA WINAPI DdeAddData(HDDEDATA,PBYTE,DWORD,DWORD);
HDDEDATA WINAPI DdeClientTransaction(PBYTE,DWORD,HCONV,HSZ,UINT,UINT,DWORD,PDWORD);
int WINAPI DdeCmpStringHandles(HSZ,HSZ);
HCONV WINAPI DdeConnect(DWORD,HSZ,HSZ,PCONVCONTEXT);
HCONVLIST WINAPI DdeConnectList(DWORD,HSZ,HSZ,HCONVLIST,PCONVCONTEXT);
HDDEDATA WINAPI DdeCreateDataHandle(DWORD,PBYTE,DWORD,DWORD,HSZ,UINT,UINT);
HSZ WINAPI DdeCreateStringHandleA(DWORD,LPCSTR,int);
HSZ WINAPI DdeCreateStringHandleW(DWORD,LPCWSTR,int);
BOOL WINAPI DdeDisconnect(HCONV);
BOOL WINAPI DdeDisconnectList(HCONVLIST);
BOOL WINAPI DdeEnableCallback(DWORD,HCONV,UINT);
BOOL WINAPI DdeFreeDataHandle(HDDEDATA);
BOOL WINAPI DdeFreeStringHandle(DWORD,HSZ);
DWORD WINAPI DdeGetData(HDDEDATA,PBYTE,DWORD,DWORD);
UINT WINAPI DdeGetLastError(DWORD);
BOOL WINAPI DdeImpersonateClient(HCONV);
UINT WINAPI DdeInitializeA(PDWORD,PFNCALLBACK,DWORD,DWORD);
UINT WINAPI DdeInitializeW(PDWORD,PFNCALLBACK,DWORD,DWORD);
BOOL WINAPI DdeKeepStringHandle(DWORD,HSZ);
HDDEDATA WINAPI DdeNameService(DWORD,HSZ,HSZ,UINT);
BOOL WINAPI DdePostAdvise(DWORD,HSZ,HSZ);
UINT WINAPI DdeQueryConvInfo(HCONV,DWORD,PCONVINFO);
HCONV WINAPI DdeQueryNextServer(HCONVLIST,HCONV);
DWORD WINAPI DdeQueryStringA(DWORD,HSZ,LPSTR,DWORD,int);
DWORD WINAPI DdeQueryStringW(DWORD,HSZ,LPWSTR,DWORD,int);
HCONV WINAPI DdeReconnect(HCONV);
BOOL WINAPI DdeSetUserHandle(HCONV,DWORD,DWORD);
BOOL WINAPI DdeUnaccessData(HDDEDATA);
BOOL WINAPI DdeUninitialize(DWORD);

#ifdef UNICODE
#define SZDDESYS_TOPIC    L"System"
#define SZDDESYS_ITEM_TOPICS    L"Topics"
#define SZDDESYS_ITEM_SYSITEMS    L"SysItems"
#define SZDDESYS_ITEM_RTNMSG    L"ReturnMessage"
#define SZDDESYS_ITEM_STATUS    L"Status"
#define SZDDESYS_ITEM_FORMATS    L"Formats"
#define SZDDESYS_ITEM_HELP    L"Help"
#define SZDDE_ITEM_ITEMLIST    L"TopicItemList"
#define DdeCreateStringHandle DdeCreateStringHandleW
#define DdeInitialize DdeInitializeW
#define DdeQueryString DdeQueryStringW
#else
#define SZDDESYS_TOPIC    "System"
#define SZDDESYS_ITEM_TOPICS    "Topics"
#define SZDDESYS_ITEM_SYSITEMS    "SysItems"
#define SZDDESYS_ITEM_RTNMSG    "ReturnMessage"
#define SZDDESYS_ITEM_STATUS    "Status"
#define SZDDESYS_ITEM_FORMATS    "Formats"
#define SZDDESYS_ITEM_HELP    "Help"
#define SZDDE_ITEM_ITEMLIST    "TopicItemList"
#define DdeCreateStringHandle DdeCreateStringHandleA
#define DdeInitialize DdeInitializeA
#define DdeQueryString DdeQueryStringA
#endif
#ifdef __cplusplus
}
#endif
#endif /* _DDEML_H */
