#pragma once

#include "windows.h"
#include "DataCenter.h"
#include "json.h"
#include "stdint.h"

enum video_type
{
	HIK_VIDEO = 0,		//����������
	VLC_VIDEO ,		//��׼������
};

#include "BeyondPlayer.h"

#ifdef PL_PLAYER_EXPORTS
#define DLLAPI	_declspec(dllexport)
#else
#define DLLAPI	_declspec(dllimport)
#endif

class DLLAPI PlayerFactor
{
public:
	PlayerFactor(enum WorkModel playModel);
	~PlayerFactor(void);

public:
	BOOL Play(HWND hwnd,char *js_playInfo);	//��ҳ���� ����

public:
	void Stop();						//ֹͣ����
	BOOL Capture(char *path);			//ץͼ
	BOOL SetSpeed(BOOL bSpeedUp);		//TRUE=�����FALSE=����
	BOOL Record(char *path);			//¼��
	void Pause();						//��ͣ
	void PlayOneByOne();				//��֡����
	int GetVolume();					//���������С
	BOOL SetVolume(int nVolume);		//����������С
	BOOL IsPlaying();					//�Ƿ��ڲ���
	BOOL VodStreamJump(char *js_time);	//��ʷ����ת
	HWND GetPlayHwnd();					//�õ����Ŵ��ھ��
	BOOL GetWndPlayParm(char *OUT_playerParm);
	void Play();							//��������
	BOOL SetOsdText(int stime,char *osdtext);	//osd�ı�����
	BOOL IsPaused();

	char *GetJSInfo() const;		//���json��ʽ������Ϣ
	void VodCallBack();					//��ʷ����ʱ�����ص�
	static BOOL RegisterCallBack(CALLBACK_onEvent funcAddr);
	void onCallBack(unsigned int nType,int args[],unsigned int argCount);
	void *GetRecntWnd()const;			//�����������
	void StatusCallBack(HWND hPlayWnd);		//���״̬֪ͨ
	BOOL SetUserData(void *pUser);		//�����û����ݣ����ʵ�����õ�
	void AspectRatio(int width=0,int height=0);	//����
	void SleepPlayer(bool bSleep);

private:
	int GetVideoType();					//�ж���������
	void CreateMrl(char *OUT_playInfo);	//���ɲ���MRL�ִ�

private:
	BeyondPlayer *m_pPlayer;			//������ʵ��
	static WorkModel m_playMode;		//����������ģʽ
	char *m_jsPlayInfo;			//������Ϣ
	static CALLBACK_onEvent m_pFuncCallBk;	//�ص�����ָ��
	int64_t m_nLastTime;				//��ʷ����ʱ�����ص�����ʱ��ֵ
	static int m_nPlayerNum;			//Ŀǰ�м��������ڲ���
	void *m_waitStatus;					//��������
	int m_videoType;					//��Ƶ����:std, custom
	int m_nVodEndTime;
	void *m_pUser;						//ʵ��������ָ��dll
};
