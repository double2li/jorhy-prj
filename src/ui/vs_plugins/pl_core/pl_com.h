#pragma once
#include "pl_core.h"

struct JoInterfaceEntry
{
	const GUID* piid;
	DWORD dw;

	typedef INT (*JoFQueryInterface)(void* pv, const GUID& guid, void*& pObj, DWORD dw);
	JoFQueryInterface pFunc; // NULL-�Ǽǲ�����, 1-offset, ����-����ָ��
};
extern "C" PL_API INT JoQueryInterface(void* pThis, const JoInterfaceEntry* entries, const GUID& iid, void*& pObj);

// �򵥶���
#define _JO_SIMPLEMAPENTRY ((JoInterfaceEntry::JoFQueryInterface)1)

// ����ƫ����
#define JO_OFFSET_OF_CLASS(base, derived)	 ((DWORD)(static_cast<base*>((derived*)8))-8)

#define _JO_RETURN_QI_ENTRY()	return _entries

/// ��ʼ���ֽӿڵĵǼǲ�
/// @param[in] x ����
#define JO_INTERFACE_BEGIN(x)								\
	typedef x _class;												\
	static const JoInterfaceEntry* _GetEntries(){					\
	static const JoInterfaceEntry _entries[] = {				\

/// �Ǽǽӿ�
/// @param[in] iclass �ӿ���
#define POSA_SIMPLE_INTERFACE_ENTRY(iclass)							\
{&IID_##iclass, JO_OFFSET_OF_CLASS(iclass, _class), _JO_SIMPLEMAPENTRY },

/// �������ֽӿڵĵǼǲ�
#define JO_INTERFACE_END()										\
{ NULL, 0, NULL }										\
};															\
	_JO_RETURN_QI_ENTRY();									\
}																\
	virtual INT QueryInterface(const GUID& iid, void*& pObj)		\
{ return JoQueryInterface(this, _GetEntries(), iid, pObj); }