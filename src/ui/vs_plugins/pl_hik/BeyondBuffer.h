#pragma once
#include "PlayerDataCenter.h"
#include "BeyondLock.h"

class BeyondBuffer
{
public:
	BeyondBuffer(int nBuffSize = REAL_BUFFSIZE);
	~BeyondBuffer(void);

public:
	BOOL PopBuffer(char *OUT_Buffer,StreamHeader &OUT_Header);		//TRUE=�ɹ�,FALSE=û����
	BOOL PushBuffer(char *IN_Buffer,StreamHeader &IN_Header);		//TRUE=�ɹ�,FALSE=buffer����
	BOOL ResetBuffSize(int nSize);					//����buffer,���ݽ���ʧ
	BOOL IncreaseBuffSize(int nSize);				//����buffer��С������δ������
	BOOL FlushBuff();

private:
	int m_nBuffSize;		//�ܹ�buffer��С
	char *m_pBegin;
	char *m_pEnd;
	char *m_pReadPoint;
	char *m_pWritePoint;
	int m_nReadableSize;	//�ɶ�buffer��С

	BeyondLock m_lock;
};
