#pragma once

#include "windows.h"
#include "stdint.h"
#include "json.h"
#include "pl_type.h"
#include "pl_core.h"
#include "pl_player.h"
#include "pl_singleton.h"
#include <map>

class PL_API PlManager : public SingletonTmpl<PlManager>
{
	typedef std::map<HWND, PL_PlayerInfo>	PlayerMap;
public:
	PlManager();
	~PlManager();

public:
	BOOL	Play(HWND hWnd, char *pJsUrl, int nPlayMode, int nSteamType);			//��ҳ���� ����
	void		Stop(HWND hWnd = NULL);					//ֹͣ����
	BOOL	Capture(HWND hWnd, char *pPath);								//ץͼ
	BOOL	SetSpeed(HWND hWnd, BOOL bSpeedUp);					//TRUE=�����FALSE=����
	BOOL	Record(HWND hWnd, char *pPath);								//¼��
	void		Pause(HWND hWnd);													//��ͣ
	void		PlayOneByOne(HWND hWnd);									//��֡����
	int		GetVolume(HWND hWnd);										//���������С
	BOOL	SetVolume(HWND hWnd, int nVolume);						//����������С
	BOOL	IsPlaying(HWND hWnd);											//�Ƿ��ڲ���
	BOOL	VodStreamJump(HWND hWnd, char *js_time);				//��ʷ����ת
	BOOL	GetWndPlayParm(HWND hWnd, char *OUT_playerParm);
	void		Play();													//��������
	BOOL	SetOsdText(int stime,char *osdtext);		//osd�ı�����
	BOOL	IsPaused();

	void		VodCallBack(HWND hWnd);											//��ʷ����ʱ�����ص�
	static BOOL RegisterCallBack(CALLBACK_onEvent funcAddr);
	void		onCallBack(unsigned int nType,int args[],unsigned int argCount);
	void		*GetRecntWnd()const;								//�����������
	void		StatusCallBack(HWND hPlayWnd);			//���״̬֪ͨ
	BOOL	SetUserData(HWND hWnd, void *pUser);							//�����û����ݣ����ʵ�����õ�
	void		AspectRatio(int width=0,int height=0);		//����
	void		SleepPlayer(bool bSleep);

private:
	void		CreateMrl(int nPlayMode, int nSteamType,  char *pJsUrl, char *pUrl);					//���ɲ���MRL�ִ�

private:
	PlayerMap m_playerMap;
	static CALLBACK_onEvent m_pFuncCallBk;				//�ص�����ָ��
	int64_t		m_nLastTime;										//��ʷ����ʱ�����ص�����ʱ��ֵ
	static int	m_nPlayerNum;									//Ŀǰ�м��������ڲ���
	void			*m_waitStatus;										//��������
	int			m_videoType;										//��Ƶ����:std, custom
	int			m_nVodEndTime;
	void			*m_pUser;												//ʵ��������ָ��dll
	HWND		m_hPlayWnd;
};
