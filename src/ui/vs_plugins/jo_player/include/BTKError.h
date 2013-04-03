#pragma once

enum btk_error_e
{
BTK_NO_ERROR	= 0,			//�޴�
BTK_ERROR_MRL,					//�����mrl
BTK_ERROR_PTR,					//�����point
BTK_ERROR_WINDOW_HWND,			//�����window���
BTK_ERROR_UNKNOW,				//δ֪�Ĵ���
BTK_ERROR_FFMPEG,				//ffmpeg�ڲ�����
BTK_ERROR_LIVE555,				//live555�ڲ�����


//net work
BTK_ERROR_SOCKET = 100,			//Socket����
BTK_ERROR_CONNECT,				//����Զ�̳���
BTK_ERROR_RECEIVE,				//socket���ܳ���
BTK_ERROR_WRITE,				//socketд����
BTK_ERROR_RECEIVE_TIMEOUT,		//�������ݳ�ʱ
BTK_ERROR_WRITE_TIMEOUT,		//�������ݳ�ʱ

//input
BTK_ERROR_ACCESS_CREATE = 200,	//access ����error
BTK_ERROR_THREAD_CREATE,		//thread create failed
BTK_ERROR_DEMUX_CREATE,			//demux����error
BTK_ERROR_CONTROL,				//control error
BTK_ERROR_AUDIO_DECODE,			//audio decode create error
BTK_ERROR_VIDEO_DECODE,			//video decode create error
BTK_ERROR_NO_RENDER,			//no render
BTK_ERROR_VARIABLE,				//var error
BTK_ERROR_DEMUX_CONTROL,		// demux control error

//draw
BTK_ERROR_INIT_DDRAW = 300,		//��ʼ��DDRAWʧ��
BTK_ERROR_NO_CAPS,				//û��DDcaps
BTK_ERROR_NO_CLIPPER,			//û��cliper
BTK_ERROR_PRIMARY_SURFACE,		//û����ҳ��
BTK_ERROR_CREATE_SURFACE,		//��������surfaceʧ��
BTK_ERROR_SURFACE_LOCK,			//lock surface error
BTK_ERROR_MISMATCH_PLANE,		//û�ж�Ӧ��ƽ��
BTK_ERROR_SURFACE_BLT,			//blt picture error
BTK_ERROR_NO_SURFACE,			//û��surface

//decoder
BTK_ERROR_DECODE_INIT = 400,	//��ʼ��decoderʧ��
BTK_ERROR_DECODE,				//decode ʧ��

//network
BTK_ERROR_NO_NETWORK = 500,		//û����ȷ������input

//buffer
BTK_ERROR_EMPTY_BUFFER = 600,	//��buffer
BTK_ERROR_FULL_BUFFER,			//buffer ����

//access
BTK_ERROR_ACCESS_END,			//access����
BTK_ERROR_ACCESS_ERROR,			//access����
BTK_ERROR_ACCESS_CONTROL,		//access control error

//picture
BTK_ERROR_NO_PICTURE,			//û��ͼ��
BTK_ERROR_FILENAME,				//������ļ���
BTK_ERROR_PICTURE_SUPPORT,		//��֧�ֵ�ͼ���ʽ
BTK_ERROR_OPEN_FILE,			//���ļ�����
BTK_ERROR_LIBPNG,				//libpng ����

//record
BTK_ERROR_STREAM,				//û����ȷ��stream
};	
