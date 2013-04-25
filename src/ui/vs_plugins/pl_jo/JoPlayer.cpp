#include "StdAfx.h"
#include "JoPlayer.h"
#include "pl_manager.h"
#include "pl_reconn.h"

/*********************�ص�����*******************/
void X_PL_API JoPlayer::EndCBK(void *pdata)
{
	JoPlayer *user = reinterpret_cast<JoPlayer*>(pdata);
	if(user)
	{
		if(user->m_Model == STREAME_REALTIME)
		{
			user->Stop();
			PostMessage(PlManager::Instance()->GetRecntWnd(user->m_pPlWnd),WM_OWN_START_WAIT,(WPARAM)user->m_pPlWnd,0);
		}
		else
		{
			PostMessage(user->m_pPlWnd,WM_MEDIA_END_REACHED,0,0);
		}
	}
}

/*********************��ʵ��*********************/
JoPlayer::JoPlayer(int nWorkMode, HWND hWnd)
{
	m_player		= new J_PlControl();
	m_Model		= nWorkMode;
	m_pPlWnd	= hWnd;
}

JoPlayer::~JoPlayer(void)
{
	if(m_player)
		delete m_player;
}

BOOL JoPlayer::Play(HWND hPlayWnd, const PL_PlayInfo &playInfo)
{
	J_PL_RESULT br;
	char *beg = strstr((char *)playInfo.pUrl, "//");
	char *end = NULL;
	int len = 0;
	char mrl[128] = {0};
	char ip[16] = {0};
	char resid[16] = {0};
	if(beg)
	{
		beg += strlen("//");
		end = strchr(beg,':');
		memcpy(ip,beg,end-beg);
		
		beg = end;
		beg = strstr(beg,"resid=");
		beg += strlen("resid=");
		end = strchr(beg,'&');
		memcpy(resid,beg,end-beg);

		sprintf(mrl,"RYSP://%s:%d/%s", playInfo.strIpaddr, 8002, playInfo.strResid);
		m_lastMrl = mrl;
		//sprintf(mrl,"RYSP://192.168.1.10:8002/44");
		br = m_player->InitPlayByNetwork(mrl);
		if(br != J_PL_NO_ERROR)
			return FALSE;
		br = m_player->SetHwnd(hPlayWnd);
		if(br != J_PL_NO_ERROR)
			return FALSE;
		br = m_player->Run();
		if(br != J_PL_NO_ERROR)
			return FALSE;
		
		m_pPlWnd = hPlayWnd;

		m_player->SetEndCBK(EndCBK,this);
	}
	return TRUE;
}

BOOL JoPlayer::RePlay()
{
	m_lock.Lock();
	if(m_player)
	{
		J_PL_RESULT br;
		delete m_player;
		m_player = NULL;
		m_player = new J_PlControl();
	
		br = m_player->InitPlayByNetwork(m_lastMrl.c_str());
		if(br != J_PL_NO_ERROR)
		{
			m_lock.Unlock();
			return FALSE;
		}
		br = m_player->SetHwnd(m_pPlWnd);
		if(br != J_PL_NO_ERROR)
		{
			m_lock.Unlock();
			return FALSE;
		}
		br = m_player->Run();
		if(br != J_PL_NO_ERROR)
		{
			m_lock.Unlock();
			return FALSE;
		}

		m_player->SetEndCBK(EndCBK,this);
	}
	m_lock.Unlock();
	return TRUE;
}

void JoPlayer::Stop()
{
	if(m_player)
	{
		m_player->Stop();
	}
}

void JoPlayer::Pause()
{

}

void JoPlayer::PlayOneByOne()
{

}

int JoPlayer::GetVolume()
{
	return 0;
}

BOOL JoPlayer::SetVolume(int nVolume)
{
	return TRUE;
}

BOOL JoPlayer::IsPlaying()
{
	BOOL bRet = FALSE;
	m_lock.Lock();
	if(m_player)
	{
		bRet = m_player->IsPlaying();
	}
	m_lock.Unlock();
	return bRet;
}

BOOL JoPlayer::SetSpeed(BOOL bSpeedUp)
{
	return TRUE;
}

BOOL JoPlayer::Capture(char *path)
{
	if(m_player)
	{
		m_player->Snapshot(path);
	}
	return TRUE;
}

BOOL JoPlayer::Record(char *path)
{
	return TRUE;
}

int JoPlayer::GetPlayStatus()
{
	int state = J_PL_NORMAL;
	if(m_player)
	{
		m_player->GetState(state);
	}
	return state;
}

HWND JoPlayer::GetPlayHwnd()
{
	return m_pPlWnd;
}

BOOL JoPlayer::VodStreamJump(const PL_PlayInfo &playInfo)
{
	return TRUE;
}

BOOL JoPlayer::SetOSDText(int stime,char *osdText)
{
	return TRUE;
}

BOOL JoPlayer::IsPaused()
{
	return TRUE;
}

void JoPlayer::AspectRatio(int width,int height)
{

}

void JoPlayer::SleepPlayer(bool bSleep)
{
	if(m_player)
	{
		m_player->SleepPlayer(bSleep);
	}
}

PLAYER_BEGIN_MAKER(pl_jo)
	PLAYER_ENTER_MAKER("pl_jo", JoPlayer::Maker)
PLAYER_END_MAKER()