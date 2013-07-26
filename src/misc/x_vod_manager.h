#ifndef __X_VOD_MANAGER_H_
#define __X_VOD_MANAGER_H_
#include "j_includes.h"

class JO_API CXVodManager
{
public:
	CXVodManager();
	~CXVodManager();

public:
	///��ѯ��ʷ�ļ���Ϣ
	///@param[in]		pResid ��ԴID
	///@param[in]		begin_time ��ʼʱ��
	///@param[in]		end_time ����ʱ��
	///@param[out]	vecFileInfo �ļ���Ϣ
	///@return			�μ�j_errtype.h
	j_result_t SearchVodFiles(const j_char_t *pResid, j_time_t begin_time, j_time_t end_time, j_vec_file_info_t &vecFileInfo);

	///ͳ����ʷ�ļ���Ϣ
	///@param[in]		pResid ��ԴID
	///@param[out]	begin_time ��ʼʱ��
	///@param[out]	end_time ����ʱ��
	///@param[out]	nSize �ļ���С(��λKB)
	///@return			�μ�j_errtype.h
	j_result_t GetRecordInfo(const j_char_t *pResid, j_time_t &begin_time, j_time_t &end_time, j_int64_t &nSize);

	///ͳ��¼����Դ��Ϣ
	///@param[in]		vecResid ¼���ļ���ԴID
	///@return			�μ�j_errtype.h
	j_result_t GetRecordResid(j_vec_resid_t &vecResid);

	///ɾ��¼���ļ�
	///@param[in]		delRecordCtrl ¼����Դ��Ϣ
	///@return			�μ�j_errtype.h
	j_result_t DelFiles(J_DelRecordCtrl &delRecordCtrl);

private:
	void FillFileInfo(const char *pFileName, J_FileInfo &fileInfo);
	int SearchOneDayFiles(const j_char_t *pResid, const char *pDate, j_time_t begin_time, j_time_t end_time, j_vec_file_info_t &vecFileInfo);
	int DeleteFilesByResid(const j_char_t *pResid, j_time_t begin_time, j_time_t end_time);
	int DeleteDirectory(char *DirName);
};
JO_DECLARE_SINGLETON(XVodManager)
#endif //~__X_VOD_MANAGER_H_