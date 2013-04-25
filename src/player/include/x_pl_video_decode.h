#pragma once
#include "x_pl_base.h"
#include "x_pl_common.h"
#include "x_pl_data_struct.h"

class J_PlVideoDecode : public J_PlBase
{
public:
	static J_PlVideoDecode* CreateInstance(int nCode);		//���codec_id_e
	static void ReleaseInstance(J_PlVideoDecode **pInstance);

public:
	J_PlVideoDecode(void);
	~J_PlVideoDecode(void);
	
	//������Ҫ��д
	virtual J_PL_RESULT InitDecode() = 0;
	virtual J_PL_RESULT Decode(char *IN_buf,int In_len,char *OUT_buf,int *OUT_len) = 0;
	virtual J_PL_RESULT FlushBuffer() = 0;
	virtual J_PL_RESULT GetOutputType(j_pl_video_out_t &t) = 0;

protected:
	virtual J_PL_RESULT SetOutputType(j_pl_video_out_t &t) = 0;			//decode�������Զ�����

protected:
	int m_codeID;			//��־�����Ľ�������
	j_pl_video_out_t m_voutT;
};
