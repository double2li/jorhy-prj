#pragma once
#include "pl_player.h"
#include "pl_err.h"
#include "pl_factory_wnd.h"

// CPlFullWnd
class CPlFullWnd	 : public CWnd
							 , public PlFullScreen
{
	DECLARE_DYNAMIC(CPlFullWnd)

public:
	CPlFullWnd(HWND hParent = NULL, UINT nID = 0);
	virtual ~CPlFullWnd();

	static int Maker(CWnd *&pObj, HWND hParent,UINT nID)
	{
		pObj = new CPlFullWnd(hParent, nID);
		return PL_OK;
	}
protected:
	DECLARE_MESSAGE_MAP()

private:
	BOOL m_bFullScreen;
	WINDOWPLACEMENT m_OldWndPlacement; //��������ԭ����λ��
	HWND m_oldParent;
	HWND m_hNeedFullWnd;		//Ҫȫ������

public:
	///PlFullScreen
	virtual void onFullScreen(HWND hNeedFullWnd);

public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};