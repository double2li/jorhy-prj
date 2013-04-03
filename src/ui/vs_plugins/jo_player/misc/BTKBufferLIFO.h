#pragma once
#include "..\include\BTKBuffer.h"

class BTKBufferLIFO : public BTKBuffer
{
public:
	BTKBufferLIFO(int size);
	~BTKBufferLIFO(void);

	virtual BTK_RESULT Read(char *OUT_Buffer,char *OUT_extra,btk_buffer_t &OUT_Header);
	virtual BTK_RESULT Write(char *IN_Buffer,char *IN_extra,btk_buffer_t &IN_Header);
	virtual BTK_RESULT MoveNext();
	virtual BTK_RESULT DropData(int num = 1);
	virtual BTK_RESULT Flush();
	virtual void WaitData();
	virtual int GetReadableSize();
	virtual int GetReadableNum();
	virtual BTK_RESULT SetReadType(bool bFront=true);
	virtual BTK_RESULT SetReadPoint(bool bEnd=false);

private:
	int		m_nBuffSize;		//�ܹ�buffer��С
	char	*m_pBegin;
	char	*m_pEnd;
	char	*m_pReadPoint;
	char	*m_pWritePoint;
	char	*m_pSetpPoint;		//�ϴ�Read()�ƶ�readpointλ��  for MoveNext����
	int		m_nStepSize;		//�ϴ�Read�������Ĵ�С for MoveNext����
	int		m_nReadableSize;	//�ɶ�buffer��С
	int		m_nReadableNum;		//�ж��ٸ��ɶ�����
};