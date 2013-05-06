#pragma once


#include "x_pl_base.h"
#include "x_pl_input.h"
#include "x_pl_transform.h"
#include "x_pl_render.h"
#include "x_pl_thread.h"
#include "x_pl_variable.h"
#include "x_pl_error.h"

class J_PlControl : public J_PlBase
{
public:
	JO_PL_API J_PlControl(void);
	JO_PL_API ~J_PlControl(void);
				
	//��������ý��
	JO_PL_API J_PL_RESULT InitPlayByNetwork(const char *psz_mrl,j_pl_work_type model=J_PL_PLAY_REALTIME);		
	//���ű���ý��
	JO_PL_API J_PL_RESULT InitPlayByPath(const char *psz_mrl,j_pl_work_type model=J_PL_PLAY_REALTIME);

	JO_PL_API J_PL_RESULT SetHwnd(HWND hwnd);
	JO_PL_API J_PL_RESULT GetHwnd(HWND &hwnd);
	JO_PL_API J_PL_RESULT Run();
	JO_PL_API J_PL_RESULT Pause();
	JO_PL_API J_PL_RESULT Stop();
	JO_PL_API J_PL_RESULT SetSpeed(j_pl_speed e);
	JO_PL_API J_PL_RESULT ToggelBackRun(bool bEnable);
	JO_PL_API J_PL_RESULT PlayNextFrame();
	JO_PL_API J_PL_RESULT SetVolume(int volume);
	JO_PL_API J_PL_RESULT GetVolume(int &volume);
	JO_PL_API J_PL_RESULT GetState(int &state);
	JO_PL_API J_PL_RESULT Snapshot(char *path_name);			//���Ը��ݺ�׺���ж���Ӧ��ģ��
	JO_PL_API J_PL_RESULT ToggelRecord(char *path_name);
	JO_PL_API J_PL_RESULT SetDisplayCBK(j_pl_entry_display_t pCBK,void *pUser);
	JO_PL_API J_PL_RESULT SetEndCBK(j_pl_entry_end_t pCBK,void *pUser);
	JO_PL_API J_PL_RESULT SetPlayDirection(bool bFront=true);
	JO_PL_API J_PL_RESULT SetTime(j_pl_mtime_t time);

	JO_PL_API J_PL_BOOL	IsPlaying();
	JO_PL_API void		ResetCBK();
	JO_PL_API void		SleepPlayer(bool bEnable);			//˯�߲��������������Сcpu����

protected:
	J_PL_RESULT CallBackStop();				//�߳��˳�ʱ���ã������˳�ʱ�����

protected:
	CXPlInput		*m_input;
	CXPlTransform	*m_tansfm;				//input create Transform
	CXPlRender		*m_render;				//decoder create render
	J_PlCond			m_switch;				//��ͣ���ſ���
	J_PlCond			m_FrameSwitch;			//��֡�����ź�

	J_PlVariable		*m_state;				//����״̬	int
	J_PlVariable		*m_displayTime;			//��ʾʱ��	int64
	J_PlVariable		*m_bForward;			//���ŷ���	bool
	J_PlVariable		*m_speed;				//�����ٶ�	int
	J_PlVariable		*m_bSleep;				//˯�߲���	bool

	J_PlSem			m_AllClose;				//�����̶߳��رգ�
	J_PlSem			m_SafeClose;			//�ⲿStop��ʱ��Player��ȫ�ر�
	J_PlVariable		*m_ThreadNumer;			//�����������߳����� int 

	j_pl_work_type	m_WorkModel;			//����������ģʽ

	friend class CXPlInput;
	friend class CXPlTransform;
	friend class CXPlRender;

protected:
	
	//display callback
	j_pl_entry_display_t	m_pDisplayCBK;
	void				*m_pDisplayData;

	//end callback
	j_pl_entry_end_t		m_pEndCBK;
	void				*m_pEndData;
};
