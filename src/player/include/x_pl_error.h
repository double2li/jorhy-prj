#pragma once

enum J_PL_ERROR_e
{
J_PL_NO_ERROR	= 0,			//�޴�
J_PL_ERROR_MRL,					//�����mrl
J_PL_ERROR_PTR,					//�����point
J_PL_ERROR_WINDOW_HWND,			//�����window���
J_PL_ERROR_UNKNOW,				//δ֪�Ĵ���
J_PL_ERROR_FFMPEG,				//ffmpeg�ڲ�����
J_PL_ERROR_LIVE555,				//live555�ڲ�����


//net work
J_PL_ERROR_SOCKET = 100,			//Socket����
J_PL_ERROR_CONNECT,				//����Զ�̳���
J_PL_ERROR_RECEIVE,				//socket���ܳ���
J_PL_ERROR_WRITE,				//socketд����
J_PL_ERROR_RECEIVE_TIMEOUT,		//�������ݳ�ʱ
J_PL_ERROR_WRITE_TIMEOUT,		//�������ݳ�ʱ

//input
J_PL_ERROR_ACCESS_CREATE = 200,	//access ����error
J_PL_ERROR_THREAD_CREATE,		//thread create failed
J_PL_ERROR_DEMUX_CREATE,			//demux����error
J_PL_ERROR_CONTROL,				//control error
J_PL_ERROR_AUDIO_DECODE,			//audio decode create error
J_PL_ERROR_VIDEO_DECODE,			//video decode create error
J_PL_ERROR_NO_RENDER,			//no render
J_PL_ERROR_VARIABLE,				//var error
J_PL_ERROR_DEMUX_CONTROL,		// demux control error

//draw
J_PL_ERROR_INIT_DDRAW = 300,		//��ʼ��DDRAWʧ��
J_PL_ERROR_NO_CAPS,				//û��DDcaps
J_PL_ERROR_NO_CLIPPER,			//û��cliper
J_PL_ERROR_PRIMARY_SURFACE,		//û����ҳ��
J_PL_ERROR_CREATE_SURFACE,		//��������surfaceʧ��
J_PL_ERROR_SURFACE_LOCK,			//lock surface error
J_PL_ERROR_MISMATCH_PLANE,		//û�ж�Ӧ��ƽ��
J_PL_ERROR_SURFACE_BLT,			//blt picture error
J_PL_ERROR_NO_SURFACE,			//û��surface

//decoder
J_PL_ERROR_DECODE_INIT = 400,	//��ʼ��decoderʧ��
J_PL_ERROR_DECODE,				//decode ʧ��

//network
J_PL_ERROR_NO_NETWORK = 500,		//û����ȷ������input

//buffer
J_PL_ERROR_EMPTY_BUFFER = 600,	//��buffer
J_PL_ERROR_FULL_BUFFER,			//buffer ����

//access
J_PL_ERROR_ACCESS_END,			//access����
J_PL_ERROR_ACCESS_ERROR,			//access����
J_PL_ERROR_ACCESS_CONTROL,		//access control error

//picture
J_PL_ERROR_NO_PICTURE,			//û��ͼ��
J_PL_ERROR_FILENAME,				//������ļ���
J_PL_ERROR_PICTURE_SUPPORT,		//��֧�ֵ�ͼ���ʽ
J_PL_ERROR_OPEN_FILE,			//���ļ�����
J_PL_ERROR_LIBPNG,				//libpng ����

//record
J_PL_ERROR_STREAM,				//û����ȷ��stream
};	
