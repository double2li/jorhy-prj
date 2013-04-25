#pragma once
#include "x_pl_common.h"

typedef struct
{
	FOURCC fcc;	// ����Ϊ��avih��
	DWORD  cb;			// �����ݽṹ�Ĵ�С�������������8���ֽڣ�fcc��cb������
	DWORD  dwMicroSecPerFrame;   // ��Ƶ֡���ʱ�䣨�Ժ���Ϊ��λ��  
	DWORD  dwMaxBytesPerSec;     // ���AVI�ļ������������    
	DWORD  dwPaddingGranularity; // ������������     
	DWORD  dwFlags;				// AVI�ļ���ȫ�ֱ�ǣ������Ƿ���������� 
	DWORD  dwTotalFrames;		// ��֡��     
	DWORD  dwInitialFrames;		// Ϊ������ʽָ����ʼ֡�����ǽ�����ʽӦ��ָ��Ϊ0�� 
	DWORD  dwStreams;			// ���ļ����������ĸ���  
	DWORD  dwSuggestedBufferSize; // �����ȡ���ļ��Ļ����С��Ӧ���������Ŀ飩  
	DWORD  dwWidth;				// ��Ƶͼ��Ŀ�������Ϊ��λ��  
	DWORD  dwHeight;			// ��Ƶͼ��ĸߣ�������Ϊ��λ��   
	DWORD  dwReserved[4];		// ����
} MainAVIHeader;

typedef struct 
{
	FOURCC fcc;				// ����Ϊ��strh��      
	DWORD  cb;				// �����ݽṹ�Ĵ�С�������������8���ֽڣ�fcc��cb������ 
	FOURCC fccType;			// �������ͣ���auds������Ƶ��������vids������Ƶ������                    //��mids����MIDI��������txts������������
	FOURCC fccHandler;		// ָ�����Ĵ����ߣ���������Ƶ��˵���ǽ�����   
	DWORD  dwFlags;			// ��ǣ��Ƿ�����������������ɫ���Ƿ�仯��     
	WORD   wPriority;		// �������ȼ������ж����ͬ���͵���ʱ���ȼ���ߵ�ΪĬ������  
	WORD   wLanguage;      
	DWORD  dwInitialFrames;	// Ϊ������ʽָ����ʼ֡��     
	DWORD  dwScale;			// �����ʹ�õ�ʱ��߶�      
	DWORD  dwRate;     
	DWORD  dwStart;			// ���Ŀ�ʼʱ��     
	DWORD  dwLength;		// ���ĳ��ȣ���λ��dwScale��dwRate�Ķ����йأ�    
	DWORD  dwSuggestedBufferSize; // ��ȡ��������ݽ���ʹ�õĻ����С     
	DWORD  dwQuality;		// �����ݵ�����ָ�꣨0 ~ 10,000��     
	DWORD  dwSampleSize;	// Sample�Ĵ�С      
	struct 
	{         
		short int left;         
		short int top;          
		short int right;          
		short int bottom; 
	}rcFrame;					// ָ�����������Ƶ����������������Ƶ�������е���ʾλ��              
								// ��Ƶ��������AVIMAINHEADER�ṹ�е�dwWidth��dwHeight����
} AVIStreamHeader;

typedef struct 
{   
	WORD  wFormatTag;    
	WORD  nChannels;    
	DWORD nSamplesPerSec;    
	DWORD nAvgBytesPerSec;    
	WORD  nBlockAlign;    
	WORD  wBitsPerSample;    
	WORD  cbSize;  
}WaveFormatEX;