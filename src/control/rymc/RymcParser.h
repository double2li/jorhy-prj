#ifndef __RYMC_PARSER_H_
#define __RYMC_PARSER_H_
#include "x_http_helper.h"
#include "DeviceControl.h"
#include "ModuleManagerDef.h"

class CRymcParser : public J_CommandParser
{
	public:
		CRymcParser();
		~CRymcParser();
		
		static int Maker(J_Obj *&pObj)
		{
			pObj = new CRymcParser();
			return J_OK;
		}

	public:
		virtual int AddUser(int nSocket, const char *pAddr, short nPort);
		virtual	int ProcessRequest(int nSocket, char *&pResponse, int &nRespLen);
		virtual	int DelUser(int nSocket);

	private:
		int PtzControl(const char *pResid, int nCmd, int nParam);
		int RecordControl(const char *pResid, int nCmd, int nStreamType);

	private:
		CDeviceControl m_deviceControl;
};

PARSER_BEGIN_MAKER(mcsp)
	PARSER_ENTER_MAKER("mcsp", CRymcParser::Maker)
PARSER_END_MAKER()

#endif //~__RYMC_PARSER_H_