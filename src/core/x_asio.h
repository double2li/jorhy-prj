#ifndef __X_RD_ASIO_H_
#define __X_RD_ASIO_H_
#include "j_includes.h"
#include "j_type.h"
#include "x_singleton.h"
#include "x_lock.h"
#include "x_socket.h"
#include "x_thread.h"

/// �첽Ioʹ����.
typedef j_uint32_t JoAsIoUser;

/// ��Ч���첽Ioʹ����
const JoAsIoUser JO_INVALID_ASIO_USER = 0xffffffff;

struct J_AsioDataBase
#ifdef WIN32
: public OVERLAPPED
#endif
{
	/// ִ�е��첽Io����
	enum J_IoCall
	{
		J_ACCEPT = 1,
		J_CONNECT,
		J_DISCONNECT,
		J_READ,
		J_RECEIVEFROM,
		J_WRITE,
		J_SENDTO,
		J_IOCTL
	};

	struct J_IoAccept
	{
		j_asio_handle subHandle;		///< Accept������ɺ�õ���handle
		j_uint32_t peerIP;				///< �Զ�IP��ַ
		j_int32_t peerPort;				///< �Զ˶˿�
	};

	struct J_IoRead
	{
		j_char_t *buf;				///< �������ݻ�����
		j_int32_t bufLen;		///< �������ݻ������ֽ���
		j_boolean_t whole;	///< TRUE-�ȵ�ȫ�����ݽ��������ɹ�, FALSE-���յ����������ɹ�

		j_boolean_t peerClosed;	///< TRUE-�Զ��Ѿ��ر�, FALSE-û��
		j_int32_t finishedLen;			///< �Ѿ����յ������ֽ���
	};

	struct J_IoReceiveFrom
	{
		j_char_t *buf;					///< ���ջ�����
		j_int32_t bufLen;			///< ���ջ������ֽ���

		j_int32_t finishedLen;		 ///< �Ѿ����յ������ֽ���
		sockaddr_in sender;		///< �����ߵķ�����IP��ַ�Ͷ˿�
	};

	struct J_IoConnect
	{
		struct sockaddr_in server;	///< Ҫ���ӵķ�����IP��ַ�Ͷ˿�
	};

	struct J_IoWrite
	{
		j_boolean_t whole;	///< TRUE-�ȵ�ȫ�����ݷ��������ɹ�, FALSE-���Ͳ��������������ɹ�
		const j_char_t *buf;	///< �������ݻ�����
		j_int32_t bufLen; ///< �������ݻ������ֽ���

		j_int32_t finishedLen; ///< �Ѿ����͵������ֽ���
	};

	struct J_IoSendTo
	{
		struct sockaddr_in receiver;	///< �����ߵķ�����IP��ַ�Ͷ˿�
		const j_char_t *buf;				///< �������ݻ�����
		j_int32_t bufLen;					///< �������ݻ������ֽ���

		j_int32_t finishedLen;				///< �Ѿ����͵������ֽ���
	};

	struct J_IoIoctl
	{
		j_int32_t cmd;			///< Ioctl������
#if defined(WIN32)
		const j_char_t *req;	///< ���󻺳���
		j_uint32_t reqLen;		///< ���󻺳����ֽ���
		j_char_t *reply;			///< Ӧ�𻺳���
		j_uint32_t replyLen; ///< Ӧ�𻺳����ֽ���

		j_uint32_t finishedLen; ///< ʵ��Ӧ����ֽ���
#elif defined(__linux__)
		j_int16_t pollEvents; ///< Ioctl��Ҫpollʲô�¼�(POLLIN/POLLOUT/POLLPRI֮һ)
		j_void_t *ioctlParm;  ///< Ioctl�Ĳ���
#endif
	};

	enum { MAX_CALL_DATA=64, MAX_AGENT_DATA=128 };

	/// Io��ɡ���ʱ��ʧ�ܺ����.
	/// ���뾡�췵�ز����������������Ӱ������ʹ���������������.
	/// @param[in] ioData �첽Io��Ϣ��
	/// @param[in] ret 0-���, <0-ʧ��(��j_errtype.h), 1-��ʱ, >1-��������ʹ��
	typedef void (*JoFIoCallback)(J_AsioDataBase& ioData, j_result_t ret);

	JoAsIoUser ioUser;			///< �첽Ioʹ����
	J_IoCall ioCall;					/// ִ�е��첽Io����
	j_int32_t ioTimeOut;			///< ��ʱ�趨, -1��ʾ�����, ��λ:����
	JoFIoCallback ioCallback;	///< Io��ɡ���ʱ��ʧ�ܺ����
	union
	{
		J_IoAccept ioAccept;
		J_IoRead ioRead;
		J_IoReceiveFrom ioReceiveFrom;
		J_IoConnect ioConnect;
		J_IoWrite ioWrite;
		J_IoSendTo ioSendTo;
		J_IoIoctl ioIoctl;
		j_char_t ioCallData[MAX_CALL_DATA];
	};
};

class JO_API CRdAsio : public SingletonTmpl<CRdAsio>
{
public:
	CRdAsio(int);
	~CRdAsio();

private:
	CRdAsio();

public:
	int Init();
	void Deinit();
	int AddUser(j_socket_t nSocket, J_AsioUser *pUser);
	void DelUser(j_socket_t nSocket);

private:
#ifdef WIN32
	static unsigned X_JO_API WorkThread(void *param)
#else
	static void *WorkThread(void *param)
#endif
	{
		(static_cast<CRdAsio *>(param))->OnWork();
		return 0;
	}
	void OnWork();
	void EnableKeepalive(j_socket_t nSocket);

private:
	typedef std::map<j_socket_t, J_AsioUser *> AsioMap;
	AsioMap m_asioMap;

	CJoThread m_workThread;
	J_OS::CTLock m_locker;

	j_boolean_t m_bStarted;
#ifdef WIN32
	fd_set m_fdSet;
	struct timeval m_timeout;
#else
	int m_epoll_fd;
	struct epoll_event m_evAsio;
	struct epoll_event m_evConnect[JO_MAX_ASIOSIZE];
#endif
};

#endif //~__X_RD_ASIO_H_
