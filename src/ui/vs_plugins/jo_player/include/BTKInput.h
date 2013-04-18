#pragma once
#include "btkbase.h"
#include "BTKDemux.h"
#include "BTKAccess.h"
#include "BTKThread.h"
#include "BTKBuffer.h"
#include "BTKTransform.h"

class BTKInput : public BTKBase
{
public:
	BTKInput(void);
	~BTKInput(void);

	BTK_RESULT Init(btk_cfg_t &cfg,void *control);		//init access
	BTK_RESULT Run();									//��ʼ�߳�	
	BTK_RESULT ControlAccess(int type,va_list args);

private:
	BTK_RESULT InitDemux();				//init demux
	BTK_RESULT InitDecoder();			//init decoder

	static unsigned BTKAPI Thread(void *pdata);			//main loop
	BTK_RESULT ThreadLoopPush();						//�߳�ִ�к���(��ģʽ)
	BTK_RESULT ThreadLoopPull();						//�߳�ִ�к���(��ģʽ)

private:		
	BTKDemux	*m_demux;
	BTKAccess	*m_access;
	BTKThread	m_thread;
	btk_thread_t m_threadParm;

protected:
	void		*m_control;
	BTKBuffer	*m_buffer;				//share with decoder
	BTKCond		m_pullSwitch;				//��ͣ���ſ���(��ģʽ)

	friend class BTKTransform;
};
