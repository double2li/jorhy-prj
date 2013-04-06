#pragma once

#include "pl_type.h"

// {BC81BC53-0189-4bbf-9970-62311AD1C1FC}
static const GUID IID_JoObj =
{ 0xbc81bc53, 0x189, 0x4bbf, { 0x99, 0x70, 0x62, 0x31, 0x1a, 0xd1, 0xc1, 0xfc } };

/// PowerOn��������ӿ�.
struct JoObj
{
	/// ��ýӿ�ָ��(������ʹ��,��ʹ�ø���ȫ��POSA_QI��).
	/// @param[in] iid �ӿڱ��
	/// @param[out] pObj �õ��ӿ�ָ��
	/// @return RMIP������
	virtual INT QueryInterface(const GUID& iid, void*& pObj) = 0;

	virtual ~JoObj(){};	
};

// {913FFF1A-8CAF-4893-856F-C935A1B7F474}
static const GUID IID_JoPlayer = 
{ 0x913fff1a, 0x8caf, 0x4893, { 0x85, 0x6f, 0xc9, 0x35, 0xa1, 0xb7, 0xf4, 0x74 } };

///�������ӿڶ���
struct JoPlayer : public JoObj
{
	///����
	virtual BOOL Play(HWND hPlayWnd,char *psz_mrl) = 0;
	virtual void Play() = 0;							//�����ز�
	virtual void Stop() = 0;							//����ڲ��ţ���ֹͣ��ǰ���ţ�����ʼ�µĲ���
	virtual void Pause() = 0;
	virtual void PlayOneByOne() = 0;
	virtual int GetVolume() = 0;
	virtual BOOL SetVolume(int nVolume) = 0;			// nVolume:0~~100
	virtual BOOL IsPlaying() = 0;
	virtual BOOL SetSpeed(BOOL bSpeedUp) = 0;
	virtual BOOL Capture(char *path) = 0;
	virtual BOOL Record(char *path) = 0;
	virtual int GetPlayStatus() = 0;
	virtual HWND GetPlayHwnd() = 0;
	virtual BOOL VodStreamJump(char *pNewTime_MRL) = 0;
	virtual BOOL SetOSDText(int stime,char *osdText) = 0;
	virtual BOOL IsPaused() = 0;
	virtual void AspectRatio(int width=0,int height=0) = 0;
	virtual void SleepPlayer(bool bSleep) = 0;

public:	
	int m_Model;													//����ģʽ
};

// {DE02101F-B275-4b56-875B-CD3B121ECE55}
static const GUID IID_JoFullScreen = 
{ 0xde02101f, 0xb275, 0x4b56, { 0x87, 0x5b, 0xcd, 0x3b, 0x12, 0x1e, 0xce, 0x55 } };

///ȫ���ӿ�
struct JoFullScreen : public JoObj
{
	virtual void onFullScreen(HWND hNeedFullWnd) = 0;
};

// {C9D0792E-A4E1-42da-B509-D9BE61C426C8}
static const GUID IID_JoToolWin = 
{ 0xc9d0792e, 0xa4e1, 0x42da, { 0xb5, 0x9, 0xd9, 0xbe, 0x61, 0xc4, 0x26, 0xc8 } };

struct JoToolWin : public JoObj
{
	virtual void ShowControls(BOOL bShow) = 0;
	//virtual BOOL AttachPlayer(PlayParm *pPlayParm,CWnd *parent) = 0;
};