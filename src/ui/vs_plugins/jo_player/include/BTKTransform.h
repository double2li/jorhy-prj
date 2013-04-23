#pragma once
#include "btkbase.h"
#include "BTKBuffer.h"
#include "BTKThread.h"
#include "BTKAudioDecode.h"
#include "BTKVideoDecode.h"
#include "BTKRender.h"
#include "BTKCpuUseage.h"

class BTKTransform : public BTKBase
{
public:
	BTKTransform(btk_transform_t &t,void *control);
	~BTKTransform(void);

	BTK_RESULT Run();			//����A/V���������߳�
	BTK_RESULT SwitchBuffer();
	BTK_RESULT SetDirection(bool bFront);
	BTK_BOOL ConsiderVDecoder(btk_decode_t format, bool &bNeedDec, bool &bNeedIframe, bool &bIsIFrame);		//ʵʱ

protected:
	
	//video stuff
	BTKBuffer		*m_vbuffer;	
	//vod only
	BTKBuffer		*m_vbufferEX;			//for background run decode

	//audio stuff
	BTKBuffer		*m_abuffer;
	BTKBuffer		*m_abufferEX;			//���û��棻��ʷ��ʱ������

	friend class BTKRender;

private:
	//audio stuff
	BTKThread		m_aThread;
	BTKAudioDecode	*m_aDecoder;

	//video stuff
	BTKThread		m_vThread;
	BTKVideoDecode	*m_vDecoder;
	btk_transform_t m_decoders;
	BTKSem		m_sem;
	BTKCpuInfo m_cpuInfo;

	void *m_control;			//control
	btk_thread_t m_vThreadParm;
	btk_thread_t m_aThreadParm;

	BTKCond			m_pullSwitch;	//only for pullswitch

private:
	BTK_RESULT AudioLoopPush();						//����audio output thread
	BTK_RESULT AudioLoopPull();						//����audio output thread
	static unsigned BTKAPI AudioThread(void *parm);
	BTK_RESULT InitAudio();

	BTK_RESULT VideoLoopPush();						//����video output thread
	BTK_RESULT VideoLoopPull();						//����video output thread
	static unsigned BTKAPI VideoThread(void *parm);
	BTK_RESULT InitVideo();

};
