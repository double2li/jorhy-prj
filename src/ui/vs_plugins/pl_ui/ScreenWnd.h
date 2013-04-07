#pragma once
#include "pl_player.h"
#include "pl_err.h"
#include "pl_factory.h"

// CScreenWnd
class CScreenWnd	 : public CWnd
							 , public PlFullScreen
{
	DECLARE_DYNAMIC(CScreenWnd)

public:
	CScreenWnd(HWND hParent = NULL, UINT nID = 0);
	virtual ~CScreenWnd();

	static int Maker(CWnd *&pObj, HWND hParent,UINT nID)
	{
		pObj = new CScreenWnd(hParent, nID);
		return PL_OK;
	}
	WINDOW_ENTER_MAKER("f_paly", CScreenWnd::Maker)

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