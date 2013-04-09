#pragma once

#include "pl_type.h"
#include "pl_err.h"
#include "pl_factory_wnd.h"
#include "pl_wnd.h"
#include "ScreenWnd.h"
#include "pl_toolbar.h"

// CVPlayWnd
class PL_API CVPlayWnd : public CPlWnd
{
	DECLARE_DYNAMIC(CVPlayWnd)
public:
	CVPlayWnd(HWND hParent,UINT nID);
	virtual ~CVPlayWnd();

	static int Maker(CWnd *&pObj, HWND hParent,UINT nID)
	{
		pObj = new CVPlayWnd(hParent, nID);
		return PL_OK;
	}
protected:
	DECLARE_MESSAGE_MAP()

private:
	void InitParm();

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	LRESULT MediaEnd(WPARAM wParam,LPARAM lParam);
};
