#include "VoiceIcomObj.h"
#include "x_socket.h"

CVoiceIcomObj::CVoiceIcomObj(int nSocket, J_Obj *pObj)
{
	m_pObj = pObj;
}

CVoiceIcomObj::~CVoiceIcomObj()
{

}

int CVoiceIcomObj::Process(int nIoType)
{
	int nRet = J_OK;
	J_CommandFilter *videoCommand = dynamic_cast<J_CommandFilter *>(m_pObj);
	if (videoCommand != NULL)
	{
		if (nIoType == J_IoRead)
		{
			m_resid = videoCommand->GetResid();
			switch (videoCommand->GetCommandType())
			{
			case J_START_VOICE:
				nRet = StartVoice();
				J_OS::LOGINFO("CNVRRealClient::Process StartVoice socket =  %d ret = %d", m_nSocket, nRet);
				break;
			case J_STOP_VOICE:
			{
				nRet = StopVoice();
				J_OS::LOGINFO("CVoiceIcomObj::Process StopVoice socket =  %d ret = %d", m_nSocket, nRet);
				break;
			}
			default:
				J_OS::LOGINFO("CVoiceIcomObj::Process CommandType unkown type =  %d", videoCommand->GetCommandType());
				break;
			}
		}
		else if (nIoType == J_IoWrite)
		{
			if (!m_bStart)
				return J_OK;

			J_RequestFilter *pAccess = dynamic_cast<J_RequestFilter *>(m_pObj);
			int nRet = m_pRingBuffer->PopBuffer(m_pDataBuff/* + sizeof(PackHeader)*/, m_streamHeader);
			if (nRet == J_OK)
			{
				int nDataLen = 0;
				pAccess->Convert(m_pDataBuff, m_streamHeader, m_pConvetBuff, nDataLen);

				if (m_sendSocket.Write_n(m_pConvetBuff, (uint32_t)nDataLen) < 0)
				{
					J_OS::LOGERROR("CVoiceIcomObj::OnWrite Data error");
					return J_SOCKET_ERROR;
				}
			}
			else
			{
				usleep(1);
				return J_OK;
			}
		}
	}

	return nRet;
}

int CVoiceIcomObj::Clearn()
{
	StopVoice();
	J_OS::LOGINFO("CVoiceIcomObj::OnBroken socket =  %d broken", m_nSocket);

	return J_OK;
}

int CVoiceIcomObj::Run(bool bFlag)
{
	m_bStart = bFlag;

	return J_OK;
}

int CVoiceIcomObj::StartVoice()
{
	int nRet = CAdapterManager::Instance()->StartVoice(m_resid.c_str(), m_nSocket);
	if (nRet < 0)
	{
		J_OS::LOGINFO("CVoiceIcomObj::StartVoice StartVoice error ret = %d", nRet);
		return nRet;
	}

	nRet = CAdapterManager::Instance()->GetRingBuffer(m_resid.c_str(), 0, m_nSocket, m_pRingBuffer);
	if (nRet < 0)
	{
		J_OS::LOGINFO("CVoiceIcomObj::StartVoice GetRingBuffer error ret = %d", nRet);
		return nRet;
	}
	//m_bStart = true;

	J_OS::LOGINFO("CVoiceIcomObj::StartVoice socket =  %d start", m_nSocket);

	return J_OK;
}

int CVoiceIcomObj::StopVoice()
{
	if (m_bStart)
	{
		m_bStart = false;
		int nRet = CAdapterManager::Instance()->StopVoice(m_resid.c_str(), m_nSocket);
		if (nRet < 0)
		{
			J_OS::LOGINFO("CVoiceIcomObj::StopVoice StopVoice error ret = %d", nRet);
			return nRet;
		}
		J_OS::LOGINFO("CNVRRealClient::StopVoice socket =  %d stop", m_nSocket);
	}

	return J_OK;
}