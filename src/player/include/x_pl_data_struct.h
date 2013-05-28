#pragma once
#include "x_pl_data_def.h"

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
								{J_PL_SPEED_SLOWEST,	0.125},
								{J_PL_SPEED_SLOWER,	0.25},
								{J_PL_SPEED_SLOW,	0.5},
								{J_PL_SPEED_NORMAL,	1.0},
								{J_PL_SPEED_FAST,	2.0},
								{J_PL_SPEED_FASTER,	4.0},
								{J_PL_SPEED_FASTEST,	8.0},
								};

struct j_pl_cfg_t
{
	int i_protocol;			//protocol_type_e
	j_pl_work_type i_real;	//�Ƿ���ʵʱ��accessģ����Ժ��Ըò���
	int i_port;
	char psz_ip[16];

	char psz_resource[256];		//file path or net resource
	unsigned int begin_time;
	unsigned int end_time;
};


struct j_pl_access_t
{
	int media_type;			//ý���װ��ʽ,ѡ����ʵ�demux
};

struct j_pl_buffer_t
{
	int datatype;			//0-ԭ���ݣ�1-��Ƶ����(�����)��2-��Ƶ����(�����)
	int datasize;			//ʵ������
	int extrasize;			//�������������
};

struct j_pl_demux_t
{
	int media_type;			//ý���װ��ʽ,ѡ����ʵ�demux,���demux_id_e
	int fps;
	j_pl_work_type i_real;	//�Ƿ���ʵʱ��accessģ����Ժ��Ըò���

	//��Ƶ
	unsigned int width;		//��
	unsigned int height;	//��
	int iframe_interval;	//I֡���

};

//input->decode�������ͷ
struct j_pl_decode_t			
{
	long long timestamp;
	int type;				//�Ƿ�����Ƶ������Ƶ �μ�decode_type_e
	int size;
	int fps;
};

struct j_pl_transform_t
{	
	//��Ƶ
	int vType;			//�μ�codec_id_e
	unsigned int width;		//��
	unsigned int height;	//��
	int iframe_interval;	//I֡���


	int aType;

};

//decode->output�������ͷ
struct j_pl_audio_format_t
{
	long long timestamp;
	int size;
};

//decode->output�������ͷ
struct j_pl_video_format_t
{
	long long timestamp;
	int size;
	int fps;
};

struct j_pl_audio_out_t		//for init audio output
{
	int type;
	int bit;
	int rate;
	int sample;
};

struct j_pl_video_out_t		//for init video output
{
	int VoutDev;			//��ʾģ�� ddraw��
	int FourCCType;				//fourcc code
	int width;
	int height;
};
