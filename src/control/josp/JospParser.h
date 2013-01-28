#ifndef __JOSPPARSER_H_
#define __JOSPPARSER_H_
#include "j_includes.h"
#include "JoissManager.h"
#include "MCManager.h"
#include "DeviceControl.h"
#include "ModuleManagerDef.h"

class CJospParser : public J_CommandParser
{
    public:
        CJospParser();
        ~CJospParser();
		
		static int Maker(J_Obj *&pObj)
		{
			pObj = new CJospParser();
			return J_OK;
		}

	public:
		virtual int AddUser(int nSocket, const char *pAddr, short nPort);
		virtual	int ProcessRequest(int nSocket, char *&pResponse, int &nRespLen);
		virtual	int DelUser(int nSocket);

    private:
        int MakeHeader(char *pBuffer, char *pUserID, unsigned char byCmd, unsigned char byFlag, unsigned short sqNum, unsigned short exLength, unsigned char byRet = 0x00);
        int OnLogin(int nSocket, const char *pRequest, char *&pResponse, int &nRespLen);
        int OnLogout(const char *pRequest, char *&pResponse, int &nRespLen);
        int OnGetResList(const char *pRequest, char *&pResponse, int &nRespLen);
        int OnPtzControl(const char *pRequest, char *&pResponse, int &nRespLen);
		int OnRcdSearch(const char *pRequest, char *&pResponse, int &nRespLen);

    private:
        //CJoissManager m_ivsManager;
		CMCManager m_ivsManager;
        CDeviceControl m_deviceControl;
        std::map<std::string, J_UserInfo> m_userMap;
		std::map<int, J_NetWorkInfo> m_networkMap;
};


PARSER_BEGIN_MAKER(josp)
	PARSER_ENTER_MAKER("josp", CJospParser::Maker)
PARSER_END_MAKER()

#endif // __JOSPPARSER_H_