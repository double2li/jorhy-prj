#pragma once
#include "x_pl_base.h"
#include "x_pl_buffer.h"
#include "x_pl_thread.h"
#include "x_pl_audio_decode.h"
#include "x_pl_video_decode.h"
#include "x_pl_render.h"
#include "x_pl_record.h"
#include "x_pl_cpu_useage.h"

class CXPlTransform : public J_PlBase
{
public:
	CXPlTransform(j_pl_transform_t &t,void *control);
	~CXPlTransform(void);

	J_PL_RESULT Run();			//����A/V���������߳�
	J_PL_RESULT SwitchBuffer();
	J_PL_RESULT SetDirection(bool bFront);
	J_PL_RESULT ToggelRecord(char *path_name);
	J_PL_BOOL ConsiderVDecoder(j_pl_decode_t format, bool &bNeedDec, bool &bNeedIframe, bool &bIsIFrame);		//ʵʱ

protected:
	
	//video stuff
	J_PlBuffer		*m_vbuffer;	
	//vod only
	J_PlBuffer		*m_vbufferEX;			//for background run decode

	//audio stuff
	J_PlBuffer		*m_abuffer;
	J_PlBuffer		*m_abufferEX;			//���û��棻��ʷ��ʱ������

	friend class CXPlRender;

private:
	//record stuff
	CXPlRecord *m_recorder;
	//audio stuff
	J_PlThread		m_aThread;
	CXPlAudioDecode	*m_aDecoder;

	//video stuff
	J_PlThread		m_vThread;
	J_PlVideoDecode	*m_vDecoder;
	j_pl_transform_t m_decoders;
	J_PlSem		m_sem;
	J_PlCpuInfo m_cpuInfo;

	void *m_control;			//control
	j_pl_thread_t m_vThreadParm;
	j_pl_thread_t m_aThreadParm;

	J_PlCond			m_pullSwitch;	//only for pullswitch

private:
	J_PL_RESULT AudioLoopPush();						//����audio output thread
	J_PL_RESULT AudioLoopPull();						//����audio output thread
	static unsigned X_PL_API AudioThread(void *parm);
	J_PL_RESULT InitAudio();

	J_PL_RESULT VideoLoopPush();						//����video output thread
	J_PL_RESULT VideoLoopPull();						//����video output thread
	static unsigned X_PL_API VideoThread(void *parm);
	J_PL_RESULT InitVideo();

};
