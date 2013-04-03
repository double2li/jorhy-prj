#pragma once
#include "..\include\BTKBuffer.h"
#include <vector>
using namespace std;

/*����һ�β��룬�����������Ҷ� ֻ����һ��д�����һ�ζ���*/
class BTKBufferLIST : public BTKBuffer
{
public:
	BTKBufferLIST(int size);
	~BTKBufferLIST(void);

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
	vector<char*> m_readers;
	int		m_nBuffSize;		//�ܹ�buffer��С
	char	*m_pBegin;
	char	*m_pEnd;
	int		m_readPoint;		//for vector
	char	*m_pWritePoint;
	int		m_nReadableSize;	//�ɶ�buffer��С
	bool	m_bFront;			//�������ǵ���
};