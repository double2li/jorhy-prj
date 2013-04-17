#pragma once
#include "pl_type.h"

struct PL_PlayParm
{
	int pVolume;
	BOOL pSound;
	BOOL bRecoder;
	DWORD dwUIT;
	BOOL bNeedShowCTRL;
	BOOL bPlayOneByOne;
};

///������Ϣ
struct PL_LayoutInfo
{
	BOOL bInit;
	int nMod;						//����ģʽ��1ʵʱ��2��ʷ;
	int nLayout;					//���ַ�ʽ�� 1����2����3������;
	int nWindows;				//���ֲ�������Ϊ�����ʱ������Ƶ���ڵ�������Ϊ�����ʱ���ʾ��ͬ����Ĳ��ַ�ʽ��
	//���񲼾�ģʽ��
	//0�������ڡ�
	//1���Ĵ���(2��2)��
	//2��9���ڣ�3*3����
	int nMax;						//������󻯷�ʽ��1���������󻯣�2��ȫ����󻯡�
	int nUid;						//�û�ID��
	char imgPath[512];		//ץͼ���·����
	char mediaPath[512];	//����¼��·��
};

struct PL_PlayInfo
{
	int nStreamType;			//��������,0-������1-��׼
	int nSubStreamType;		//����������,0-��������1-������
	int nPlayMode;				//����ģʽ��0-ʵʱ��1-��ʷ
	int nId;							//Id: ����ID����ID=0�����ոñ������˵�����в��ţ���ID>0����ָ��ID�Ĵ��ڽ��в��š�
	char strResid[256];			//��ԴΨһ����
	int nDevType;				//�豸���� 0-NVR,1-DVR
	INT64 nStartTime;			//��ʼʱ��
	INT64 nEndTime;			//����ʱ��
	char strIpaddr[16];			//SS IP��ַ
	int nPort;						//SS�˿� 
	char	pUrl[512];
};

/// ��������ӿ�.
struct PlObj
{
	virtual ~PlObj(){};	
};

///�������ӿڶ���
struct PlPlayer : public PlObj
{
	///����
	virtual BOOL Play(HWND hPlayWnd, const PL_PlayInfo &playInfo) = 0;
	virtual BOOL	RePlay() = 0;								//�����ز�
	virtual void	Stop() = 0;							//����ڲ��ţ���ֹͣ��ǰ���ţ�����ʼ�µĲ���
	virtual void	Pause() = 0;
	virtual void	PlayOneByOne() = 0;
	virtual int		GetVolume() = 0;
	virtual BOOL SetVolume(int nVolume) = 0;			// nVolume:0~~100
	virtual BOOL IsPlaying() = 0;
	virtual BOOL SetSpeed(BOOL bSpeedUp) = 0;
	virtual BOOL Capture(char *path) = 0;
	virtual BOOL Record(char *path) = 0;
	virtual int		GetPlayStatus() = 0;
	virtual HWND GetPlayHwnd() = 0;
	virtual BOOL VodStreamJump(const PL_PlayInfo &playInfo) = 0;
	virtual BOOL SetOSDText(int stime,char *osdText) = 0;
	virtual BOOL IsPaused() = 0;
	virtual void	AspectRatio(int width=0,int height=0) = 0;
	virtual void	SleepPlayer(bool bSleep) = 0;

public:	
	int m_Model;													//����ģʽ
};

///ȫ���ӿ�
struct PlFullScreen
{
	virtual void onFullScreen(HWND hNeedFullWnd) = 0;
};

struct PlToolWin
{
	virtual void SetModel(int nModel) = 0;
	virtual void ShowControls(BOOL bShow) = 0;
	virtual void StopPlayer() = 0; 
	virtual BOOL AttachPlayer(PL_PlayParm *pPlayParm, void *parent) = 0;
	//virtual HWND GetPlWnd() = 0;
};

///��������Ϣ
class CWnd;
struct PL_PlayerInfo
{
	HWND			hWnd;				//���ھ��
	PlPlayer		*pPlayer;			//������ָ��
	void				*pUser;				//�û�
	CWnd			*pReconnWnd;	//��������
	PL_PlayInfo	playInfo;			//url
	DWORD		dwPlayTime;		//���ų���ʱ��
	BOOL			bPlay;				//���ű�־
};
