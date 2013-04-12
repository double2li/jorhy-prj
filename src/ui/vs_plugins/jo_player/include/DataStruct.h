#pragma once
#include "DataDef.h"


struct protocol_t
{
	char *psz_name;
	int i_name;
}static const btk_protocol_values[] = {
								{"RYSP",PROTOCOL_RYSP},
								{"HTTP",PROTOCOL_HTTP},
								{"RTSP",PROTOCOL_RTSP},
								{0,	PROTOCOL_NONE},
								};
struct play_speed_t
{
	int key;
	float value;
}static const btk_speed_values[] = {
								{BTK_SPEED_SLOWEST,	0.125},
								{BTK_SPEED_SLOWER,	0.25},
								{BTK_SPEED_SLOW,	0.5},
								{BTK_SPEED_NORMAL,	1.0},
								{BTK_SPEED_FAST,	2.0},
								{BTK_SPEED_FASTER,	4.0},
								{BTK_SPEED_FASTEST,	8.0},
								};

struct btk_cfg_t
{
	int i_protocol;			//protocol_type_e
	btk_work_type i_real;	//�Ƿ���ʵʱ��accessģ����Ժ��Ըò���
	int i_port;
	char psz_ip[16];

	char psz_resource[256];		//file path or net resource 
};


struct btk_access_t
{
	int media_type;			//ý���װ��ʽ,ѡ����ʵ�demux
};

struct btk_buffer_t
{
	int datatype;			//0-ԭ���ݣ�1-��Ƶ����(�����)��2-��Ƶ����(�����)
	int datasize;			//ʵ������
	int extrasize;			//�������������
};

struct btk_demux_t
{
	int media_type;			//ý���װ��ʽ,ѡ����ʵ�demux,���demux_id_e
	int fps;
	btk_work_type i_real;	//�Ƿ���ʵʱ��accessģ����Ժ��Ըò���

	//��Ƶ
	unsigned int width;		//��
	unsigned int height;	//��
	int iframe_interval;	//I֡���

};

//input->decode�������ͷ
struct btk_decode_t			
{
	long long timestamp;
	int type;				//�Ƿ�����Ƶ������Ƶ �μ�decode_type_e
	int size;
	int fps;
};

struct btk_transform_t
{	
	//��Ƶ
	int vType;			//�μ�codec_id_e
	unsigned int width;		//��
	unsigned int height;	//��
	int iframe_interval;	//I֡���


	int aType;

};

//decode->output�������ͷ
struct btk_audio_format_t
{
	long long timestamp;
	int size;
};

//decode->output�������ͷ
struct btk_video_format_t
{
	long long timestamp;
	int size;
	int fps;
};

struct btk_audio_out_t		//for init audio output
{
	int type;
	int bit;
	int rate;
	int sample;
};

struct btk_video_out_t		//for init video output
{
	int VoutDev;			//��ʾģ�� ddraw��
	int FourCCType;				//fourcc code
	int width;
	int height;
};
