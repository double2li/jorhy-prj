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
	BOOL	Play(HWND hWnd, const PL_PlayInfo &playInfo);			//��ҳ���� ����
	void		Stop(HWND hWnd);											//ֹͣ����
	BOOL	Capture(HWND hWnd, char *pPath);								//ץͼ
	BOOL	SetSpeed(HWND hWnd, BOOL bSpeedUp);					//TRUE=�����FALSE=����
	BOOL	Record(HWND hWnd, char *pPath);								//¼��
	void		Pause(HWND hWnd);													//��ͣ
	void		PlayOneByOne(HWND hWnd);										//��֡����
	int		GetVolume(HWND hWnd);											//���������С
	BOOL	SetVolume(HWND hWnd, int nVolume);						//����������С
	BOOL	IsPlaying(HWND hWnd);												//�Ƿ��ڲ���
	BOOL	VodStreamJump(HWND hWnd, const PL_PlayInfo &playInfo);				//��ʷ����ת
	BOOL	GetWndPlayParm(HWND hWnd, char *pPlayerParm);
	BOOL	GetPlayInfo(HWND hWnd, PL_PlayInfo &playInfo);
	void		Play(HWND hWnd);																			//��������
	BOOL	SetOsdText(HWND hWnd, int stime,char *osdtext);								//osd�ı�����
	BOOL	IsPaused(HWND hWnd);

	void		VodCallBack(HWND hWnd);											//��ʷ����ʱ�����ص�
	BOOL	RegisterCallBack(NpnNotifyFunc funcAddr);
	void		NotifyNpn(HWND hWnd, UINT nType, int args[], UINT argCount);
	HWND	GetRecntWnd(HWND hWnd);								//�����������
	void		StatusCallBack(HWND hPlayWnd);			//���״̬֪ͨ
	BOOL	SetUserData(HWND hWnd, void *pUser);							//�����û����ݣ����ʵ�����õ�
	void		AspectRatio(HWND hWnd, int width=0,int height=0);		//����
	void		SleepPlayer(HWND hWnd, bool bSleep);

private:
	void		CreateMrl(const PL_PlayInfo &playInfo);					//���ɲ���MRL�ִ�

private:
	PlayerMap m_playerMap;
	NpnNotifyFunc m_pFuncCallBk;						//�ص�����ָ��
	int64_t		m_nLastTime;									//��ʷ����ʱ�����ص�����ʱ��ֵ
	int			m_nPlayNum;									//Ŀǰ�м��������ڲ���
	int			m_nVodEndTime;
};
