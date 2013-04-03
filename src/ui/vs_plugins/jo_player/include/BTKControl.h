#pragma once


#include "btkbase.h"
#include "BTKInput.h"
#include "BTKTransform.h"
#include "BTKRender.h"
#include "BTKThread.h"
#include "BTKVariable.h"
#include "BTKError.h"


class BTKControl : public BTKBase
{
public:
	DLL_IMPORT BTKControl(void);
	DLL_IMPORT ~BTKControl(void);
				
	//��������ý��
	DLL_IMPORT BTK_RESULT InitPlayByNetwork(const char *psz_mrl,btk_work_type model=BTK_PLAY_REALTIME);		
	//���ű���ý��
	DLL_IMPORT BTK_RESULT InitPlayByPath(const char *psz_mrl,btk_work_type model=BTK_PLAY_REALTIME);

	DLL_IMPORT BTK_RESULT SetHwnd(HWND hwnd);
	DLL_IMPORT BTK_RESULT GetHwnd(HWND &hwnd);
	DLL_IMPORT BTK_RESULT Run();
	DLL_IMPORT BTK_RESULT Pause();
	DLL_IMPORT BTK_RESULT Stop();
	DLL_IMPORT BTK_RESULT SetSpeed(btk_speed_e e);
	DLL_IMPORT BTK_RESULT ToggelBackRun(bool bEnable);
	DLL_IMPORT BTK_RESULT PlayNextFrame();
	DLL_IMPORT BTK_RESULT SetVolume(int volume);
	DLL_IMPORT BTK_RESULT GetVolume(int &volume);
	DLL_IMPORT BTK_RESULT GetState(int &state);
	DLL_IMPORT BTK_RESULT Snapshot(char *path_name);			//���Ը��ݺ�׺���ж���Ӧ��ģ��
	DLL_IMPORT BTK_RESULT ToggelRecord(char *path_name);
	DLL_IMPORT BTK_RESULT SetDisplayCBK(btk_entry_display_t pCBK,void *pUser);
	DLL_IMPORT BTK_RESULT SetEndCBK(btk_entry_end_t pCBK,void *pUser);
	DLL_IMPORT BTK_RESULT SetPlayDirection(bool bFront=true);
	DLL_IMPORT BTK_RESULT SetTime(btk_mtime_t time);

	DLL_IMPORT BTK_BOOL	IsPlaying();
	DLL_IMPORT void		ResetCBK();
	DLL_IMPORT void		SleepPlayer(bool bEnable);			//˯�߲��������������Сcpu����

protected:
	BTK_RESULT CallBackStop();				//�߳��˳�ʱ���ã������˳�ʱ�����

protected:
	BTKInput		*m_input;
	BTKTransform	*m_tansfm;				//input create Transform
	BTKRender		*m_render;				//decoder create render
	BTKCond			m_switch;				//��ͣ���ſ���
	BTKCond			m_FrameSwitch;			//��֡�����ź�

	BTKVariable		*m_state;				//����״̬	int
	BTKVariable		*m_displayTime;			//��ʾʱ��	int64
	BTKVariable		*m_bForward;			//���ŷ���	bool
	BTKVariable		*m_speed;				//�����ٶ�	int
	BTKVariable		*m_bSleep;				//˯�߲���	bool

	BTKSem			m_AllClose;				//�����̶߳��رգ�
	BTKSem			m_SafeClose;			//�ⲿStop��ʱ��Player��ȫ�ر�
	BTKVariable		*m_ThreadNumer;			//�����������߳����� int 

	btk_work_type	m_WorkModel;			//����������ģʽ

	friend class BTKInput;
	friend class BTKTransform;
	friend class BTKRender;

protected:
	
	//display callback
	btk_entry_display_t	m_pDisplayCBK;
	void				*m_pDisplayData;

	//end callback
	btk_entry_end_t		m_pEndCBK;
	void				*m_pEndData;
};
