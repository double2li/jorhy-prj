

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Nov 14 11:01:16 2013
 */
/* Compiler settings for .\active_plugin.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_active_pluginLib,0xBFB3815B,0xC1D5,0x4E82,0x9C,0x1F,0xCF,0x58,0x33,0x0B,0x42,0x17);


MIDL_DEFINE_GUID(IID, DIID__Dactive_plugin,0xEE693F3B,0x1B36,0x422B,0xA1,0x18,0xA6,0x4A,0xC2,0xFA,0x0C,0xF2);


MIDL_DEFINE_GUID(IID, DIID__Dactive_pluginEvents,0x97F111A3,0x770F,0x4A79,0xA2,0xB4,0x46,0x49,0x88,0x84,0x6A,0xC3);


MIDL_DEFINE_GUID(CLSID, CLSID_active_plugin,0x50D171AE,0x0536,0x4FB6,0xBB,0x9D,0x6C,0x7E,0xDD,0xF0,0x20,0x6B);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



