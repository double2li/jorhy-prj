#pragma once
#include "btkbase.h"
#include "BTKCommon.h"
#include "DataStruct.h"

class BTKVideoDecode : public BTKBase
{
public:
	static BTKVideoDecode* CreateInstance(int nCode);		//���codec_id_e
	static void ReleaseInstance(BTKVideoDecode **pInstance);

public:
	BTKVideoDecode(void);
	~BTKVideoDecode(void);
	
	//������Ҫ��д
	virtual BTK_RESULT InitDecode() = 0;
	virtual BTK_RESULT Decode(char *IN_buf,int In_len,char *OUT_buf,int *OUT_len) = 0;
	virtual BTK_RESULT GetOutputType(btk_video_out_t &t) = 0;

protected:
	virtual BTK_RESULT SetOutputType(btk_video_out_t &t) = 0;			//decode�������Զ�����

protected:
	int m_codeID;			//��־�����Ľ�������
	btk_video_out_t m_voutT;
};
