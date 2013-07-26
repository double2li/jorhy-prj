#ifndef _X_SDK_H_
#define _X_SDK_H_
#include "json.h"
#include "x_sdk_def.h"
#include "j_includes.h"
#include "x_http.h"

class JO_API CXSdk
{
public:
	CXSdk() {}
	~CXSdk() {}

public:
	///��¼���������
	///@param[in]		nId ý���豸ID
	///@param[in]		pUrl ���������URL
	///@param[out]	resInfo ��Դ��Ϣ
	///@return			�μ�j_errtype.h
	j_result_t Login(j_int32_t nId, j_char_t *pUrl, ResourceMap &resInfo);
	///��ȡ��Դ��Ϣ
	///@param[in]		pResid ��ԴID
	///@param[in]		pUrl ���������URL
	///@param[out]	resInfo ��Դ��Ϣ
	///@return			�μ�j_errtype.h
	j_result_t GetResourceInfo(j_char_t *pResid, j_char_t *pUrl, J_ResourceInfo &resInfo);
	///��ȡ��ý���������Ϣ
	///@param[in]		pResid ��ԴID
	///@param[in]		pUrl ���������URL
	///@param[out]	ssInfo ��ý���������Ϣ
	///@return			�μ�j_errtype.h
	j_result_t GetStreamServerInfo(j_char_t *pResid, j_char_t *pUrl, J_StreamServerInfo &ssInfo);
	///���ͱ�������
	///@param[in]		nStreamServerId ��ý�������ID
	///@param[in]		pUrl ���������URL
	///@return			�μ�j_errtype.h
	j_result_t KeepAlive(j_int32_t nStreamServerId, j_char_t *pUrl);

	///����¼�������Ϣ
	///@param[in]		pJsonStr Json��������ַ���
	///@param[out]	ctrlObj �������
	///@return			�μ�j_errtype.h
	j_result_t ParserRecordCtrl(const char *pJsonStr, J_ControlObj &ctrlObj);

private:
	char *HttpCommunicate(char *body,char *uri);
	int JsonGetInt(json_object *p_object, const char *p_key);
	char *JsonGetString(json_object *p_object, const char *p_key);
	json_object *JsonGetObj(json_object *p_object, const char *p_key);

private:
	CXHttp m_httpHelper;
};

JO_DECLARE_SINGLETON(XSdk)

#endif //~_X_SDK_H_
