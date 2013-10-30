#ifndef __X_RESOURCE_MANAGER_H_
#define __X_RESOURCE_MANAGER_H_
#include "j_includes.h"
#include "x_timer.h"
#include "x_lock.h"

class JO_API CResourceManager
{
public:
	CResourceManager();
	~CResourceManager();

public:
	///������ʱ��
	///@return 		�ο�x_error_type.h
	int InitResource();
	///ֹͣ��ʱ��
	void ReleaseResource();
	///�����Դ
	///@param[in]		resInfo ��Դ��Ϣ
	///@return 			�ο�x_error_type.h
	j_result_t AddResource(J_ResourceInfo &resInfo);
	///�����Դ��Ϣ
	///@param[in]		pResid ��ԴID
	///@param[out]	resInfo ��Դ��Ϣ
	///@return 			�ο�x_error_type.h
	j_result_t GetResource(const char *pResid, J_ResourceInfo &resInfo);

private:
	static void TimerThread(void *pUser)
	{
		CResourceManager *pThis = static_cast<CResourceManager *>(pUser);
		if (pThis != NULL)
			pThis->OnTimer();
	}
	void OnTimer();

private:
	J_OS::CTLock m_locker;
	J_OS::CTimer m_timer;
	j_boolean_t m_bRegiste;
	ResourceMap m_resMap;
};
JO_DECLARE_SINGLETON(ResourceManager)

#endif //~__X_RESOURCE_MANAGER_H_