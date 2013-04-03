#pragma once


// CScreenWnd

class CScreenWnd : public CWnd
{
	DECLARE_DYNAMIC(CScreenWnd)

public:
	CScreenWnd();
	virtual ~CScreenWnd();

protected:
	DECLARE_MESSAGE_MAP()

private:
	BOOL m_bFullScreen;
	WINDOWPLACEMENT m_OldWndPlacement; //��������ԭ����λ��
	HWND m_oldParent;
	HWND m_hNeedFullWnd;		//Ҫȫ������

public:
	void onFullScreen(HWND hNeedFullWnd);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


