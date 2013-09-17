#include "x_log.h"
#include "x_loadso.h"
#include "x_config.h"
#include "PlayManager.h"

#include <wx/wx.h>
#include <wx/statline.h>

//����̳�wxApp 
class MyApp : public wxApp 
{ 
public: 
	//��ں���
	virtual bool OnInit();  
}; 

//����MyAppʵ���Ĵ�����������
IMPLEMENT_APP(MyApp) 
DECLARE_APP(MyApp) 

//����̳�wxFrame 
class CStreamPlayer : public wxDialog
{ 
public: 
	CStreamPlayer(const wxString& title);  
	~CStreamPlayer();
private: 
	//�������䣬������Ϣӳ��ر���
	DECLARE_EVENT_TABLE() 
	void OnPlay(wxMouseEvent& evnet);
	void OnStop(wxMouseEvent& evnet);
	//wxObjectEventFunction

private:
	wxBoxSizer m_sizer;
	wxBoxSizer m_displaySizer;
	wxBoxSizer m_ctrlSizer;
	wxButton m_btnPlay;
	wxButton m_btnStop;
	wxWindow m_displayWindow;
	wxStaticText m_urlDesc;
	wxTextCtrl m_textUrl;

	CPlayManager m_playManager;
	j_int32_t m_streamId;
}; 

bool MyApp::OnInit() 
{ 
	//��ʼ�����ò���
	CXConfig::Init();

	///����ģ��
	CXLoadso loadSo;
	if (loadSo.JoLoadSo() != J_OK)
	{
		J_OS::LOGINFO("main loadSo JoLoadSo error");
		return 0;
	}
	//����һ���̳���wxFrame�Ĵ��ڶ���
	CStreamPlayer *dlg = new CStreamPlayer(wxT("StreamPlayer")); 
	dlg->Show(true); 

	return true; 
} 

CStreamPlayer::CStreamPlayer(const wxString& title)
: wxDialog(NULL,wxID_ANY,title) 
, m_sizer(wxVERTICAL)
, m_displaySizer(wxHORIZONTAL)
, m_ctrlSizer(wxHORIZONTAL)
, m_btnPlay(this, wxID_ANY, wxT("Play"))
, m_btnStop(this, wxID_ANY, wxT("Stop"))
, m_textUrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(500, 20))
, m_urlDesc(this, wxID_ANY, wxT("���ŵ�ַ:"))
, m_displayWindow(this, wxID_ANY)
{ 
	m_displayWindow.GetHandle();
	SetSize(wxSize(800, 800));
	CentreOnScreen();
	/* ��ӡ���ʼ�����ڿؼ��ĵط�*/ 
	m_ctrlSizer.AddSpacer(10);
	m_urlDesc.SetSize(wxSize(50, 15));
	m_ctrlSizer.Add(&m_urlDesc);
	m_ctrlSizer.AddSpacer(10);
	m_textUrl.SetValue(wxT("joh://192.168.1.12:8002?resid=121&username=admin&passwd=12345&stream_type=0"));
	m_ctrlSizer.Add(&m_textUrl);
	m_ctrlSizer.AddSpacer(60);
	m_ctrlSizer.Add(&m_btnPlay);
	m_ctrlSizer.AddSpacer(10);
	m_ctrlSizer.Add(&m_btnStop);

	m_displayWindow.SetSize(800, 600);
	m_displayWindow.SetBackgroundColour(wxColour(0, 0, 0));
	m_displaySizer.Add(&m_displayWindow);

	m_sizer.Add(&m_displaySizer);
	m_sizer.AddSpacer(50);
	m_sizer.Add(&m_ctrlSizer);
	SetSizer(&m_sizer);

	m_playManager.Init();
	m_btnPlay.Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CStreamPlayer::OnPlay));
	m_btnStop.Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CStreamPlayer::OnStop));
} 

CStreamPlayer::~CStreamPlayer()
{
	m_playManager.Deinit();
}

void CStreamPlayer::OnPlay(wxMouseEvent& evnet)
{
	char desUrl[256] = {0};
	CStreamPlayer *pStreamPlayer = (CStreamPlayer *)GetParent();
	sprintf(desUrl, "jo_player://%d", (j_wnd_t)pStreamPlayer->m_displayWindow.GetHandle());
	pStreamPlayer->m_streamId = pStreamPlayer->m_playManager.OpenStream(pStreamPlayer->m_textUrl.GetValue(), desUrl);
}

void CStreamPlayer::OnStop(wxMouseEvent &evnet)
{
	((CStreamPlayer *)GetParent())->m_playManager.CloseStream(((CStreamPlayer *)GetParent())->m_streamId);
}
BEGIN_EVENT_TABLE(CStreamPlayer, wxDialog) 

/* �����Ϣӳ��ĵط�������˵���Ӧ
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout) 
MyFrame::OnAbout��������ʽ�ǣ�
void OnAbout(wxCommandEvent& event); 
*/ 

END_EVENT_TABLE() 