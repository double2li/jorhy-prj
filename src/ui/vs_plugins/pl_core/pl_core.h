#pragma once
#include "Windows.h"

// {00000000-0000-0000-0000-000000000000}
static const GUID JO_INVALID_GUID =
{ 0x00000000, 0x0000, 0x0000, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } };

typedef INT (*JoFMaker)(void);

/// �������Ǽ���
struct JoMakerEntry
{
	enum
	{
		FLAG_REGISTERED				=(1<<0),
		FLAG_UINT64_DATA				=(1<<1),
		FLAG_TSTRING_DATA			=(1<<2),
		FLAG_GUID_DATA					=(1<<3),
		FLAG_STREAM_TYPE_DATA	=(1<<4),
	};

	const GUID* clsid; ///< ����������Ķ�����CLSID
	INT retcode;  ///< ע���entryʱ�ķ���ֵ(RMIPֵ)������CLSID==IID_POMODULE_INIT������Ӧ��ʼ�������ķ���ֵ)
	JoFMaker fMaker; ///< �����һ��ʱ�ǹ���������, ���һ��ʱָ���¸��Ǽǲ�

	/// �����һ��ʱ��ѡ��(�μ�FLAG_xxxö��)
	/// - ��0λ: 1-�Ѿ�ע��, 0-��δע��
	/// - ��1λ: 1-dataʵ����UINT64����, 0-����
	/// - ��2λ: 1-dataʵ����const TCHAR*����, 0-����
	/// - ��3λ: 1-dataʵ����const GUID*����, 0-����
	/// - ��4λ: 1-dataʵ����PoStreamType����, 0-����
	/// - ����λ����
	DWORD flags;

	UINT64 data; ///< ����clsid�в�ͬ����˼
	const DWORD* subclasses; ///< �����ӷ���, ��һ��DWORD��FourCC�����, ��0����; ���һ��ʱ�ǲ�������
};

template<typename InT>
inline JoFMaker JoMakerCast(InT t) { return reinterpret_cast<JoFMaker>(t); }

template<typename InT>
inline UINT64 JoMakerDataCast(InT t) { return reinterpret_cast<UINT64>(t); }

/// �Ǽǻ���const TCHAR*�����Ĺ�����
/// @param[in] clsid ���CLSID
/// @param[in] MakerT ������������
/// @param[in] maker ������
/// @param[in] tstringKey �����ؼ���
/// @param[in] subclasses �ӷ���(����ΪNULL)
#define JO_ENTRY_BY_TSTRING(clsid, MakerT, maker, tstringKey, subclasses) \
{ clsid, 0,JoMakerCast<MakerT>(maker), JoMakerEntry::FLAG_TSTRING_DATA, JoMakerDataCast<const TCHAR*>(tstringKey), (subclasses) },

/// ��ʼ���ֹ������ĵǼǲ�
#define JO_BEGIN_MAKER() \
	static JoMakerEntry s_joMakers[] = {

/// Host������.
/// @param[in] iid ����ӿ�IID
/// @param[out] pObj ����õĶ���
/// @param[in] hostUrl Host��url
/// @return 0-�ɹ�, <0-RMIP������
typedef INT (*JoFMakeHost)(const GUID& iid, void*& pObj, const TCHAR* hostUrl);

/// �Ǽ�Host
/// @param[in] prefix urlǰ׺(NULL��ʾ֧������ǰ׺)
/// @param[in] maker Host�Ĺ�����
/// @param[in] subclasses �ӷ���(����ΪNULL)
#define JO_ENTRY_HOST(prefix, maker, subclasses) \
	JO_ENTRY_BY_TSTRING(&CLSID_JoHost, JoFMakeHost, (maker), (prefix), (subclasses))

/// �������ֹ������ĵǼǲ�
/// @param[in] partName ������(һ����ǲ���ȫ·������չ�����ļ���)
#define JO_END_MAKER(partName) \
{ &JO_INVALID_GUID, 0,NULL, 0, 0, (const DWORD*)partName }	\
};											\
static INT s_jo_dummy_init = JO_LINK_MODULE_MAKERS(s_poMakers);