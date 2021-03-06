#ifndef __HIKSTREAM_H_
#define __HIKSTREAM_H_
#ifdef WIN32
#include "x_asio_win.h"
#else
#include "x_asio.h"
#endif
#include "HikParser.h"
#include "HikParser2.h"

class CHikStreamBase : public J_MediaStream
                     , public J_AsioUser
{};

class CHikStream : public J_BaseVideoStream<CHikStreamBase>
{
public:
	CHikStream(void *pTCPSocket, j_string_t resid);
	~CHikStream();

public:
	///J_VideoStream
	virtual int Startup();
	virtual int Shutdown();
	///AsioUser
	virtual j_result_t OnAccept(const J_AsioDataBase *pAsioData, int nRet) { return 0; }
	virtual j_result_t OnRead(const J_AsioDataBase *pAsioData, int nRet);
	virtual j_result_t OnWrite(const J_AsioDataBase *pAsioData, int nRet) { return 0; }
	virtual j_result_t OnBroken(const J_AsioDataBase *pAsioData, int nRet);
private:
	enum 
	{
		HIK_READ_HEAD = 1,
		HIK_READ_PS_HEAD,
		HIK_READ_DATA,
	};
	j_socket_t m_nSocket;

	CJoThread m_recvThread;
	j_boolean_t m_bStartup;
	char *m_pRecvBuff;//[100 * 1024];
	char *m_pDataBuff;
	void *m_pTCPSocket;

	CHikParser2 m_parser;
	j_string_t m_resid;

	J_OS::TLocker_t m_locker;
	J_AsioDataBase *m_asioData;
	j_int32_t m_nState;
	j_int32_t m_nOffset;
};

#endif //~__HIKSTREAM_H_
