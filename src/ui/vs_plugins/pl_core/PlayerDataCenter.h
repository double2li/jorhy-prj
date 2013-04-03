#pragma once

#define REAL_BUFFSIZE (2 * 1024 * 1024)		//������ݻ�������С:real
#define vod_BUFFSIZE (4 *1024 *1024)		//������ݻ�������С:vod
#define DEFAULT_RECVBUFFSIZE (1024 * 1024)		//recv��������С
#define IO_READ_SIZE 1400				
#define REAL_PLAYERSIZE (1024 * 1024)		//���������뻺������С:real
#define VOD_PLAYERSIZE (4 * 1024 * 1024)	//���������뻺������С:vod

#define REAL_FRAMENUM 10						//�����������С:real
#define VOD_FRAMENUM 25							//�����������С:vod

//fourCC
#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
	((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
	((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))

#define HIKFOURCC MAKEFOURCC('H','I','K','0')

struct StreamHeader
{
	unsigned int datalen;		//֡���ݳ���
	unsigned long VideoTypeFCC;	//��Ƶ����FourCC
	unsigned int datatype;		//��������
};

enum DataType
{
	VIDEO_HEAD = 0,
	VIDEO_DATA,
};
