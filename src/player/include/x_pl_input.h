#pragma once
#include "x_pl_base.h"
#include "x_pl_demux.h"
#include "x_pl_access.h"
#include "x_pl_thread.h"
#include "x_pl_buffer.h"
#include "x_pl_transform.h"

class CXPlInput : public J_PlBase
{
public:
	CXPlInput(void);
	~CXPlInput(void);

	J_PL_RESULT Init(j_pl_cfg_t &cfg,void *control);		//init access
	J_PL_RESULT Run();									//��ʼ�߳�	
	J_PL_RESULT ControlAccess(int type,va_list args);

private:
	J_PL_RESULT InitDemux();				//init demux
	J_PL_RESULT InitDecoder();			//init decoder
	J_PL_RESULT RequestData();

	static unsigned X_PL_API Thread(void *pdata);			//main loop
	J_PL_RESULT ThreadLoopPush();						//�߳�ִ�к���(��ģʽ)
	J_PL_RESULT ThreadLoopPull();						//�߳�ִ�к���(��ģʽ)

private:		
	J_PlDemux	*m_demux;
	J_PlAccess	*m_access;
	J_PlThread	m_thread;
	j_pl_thread_t m_threadParm;

protected:
	void		*m_control;
	J_PlBuffer	*m_buffer;				//share with decoder
	J_PlCond		m_pullSwitch;				//��ͣ���ſ���(��ģʽ)

	friend class CXPlTransform;
};
