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
class CVodPlayer : public wxDialog
{ 
public: 
	CVodPlayer(const wxString& title);  
	~CVodPlayer();
private: 
	//�������䣬������Ϣӳ��ر���
	DECLARE_EVENT_TABLE() 
	void OnMouseLeftDown(wxMouseEvent &event);
	void OnPlay(wxMouseEvent& evnet);
	void OnStop(wxMouseEvent& evnet);

public:
	void Play();
	void Stop();
	void SetForcus(wxObject *window);
	//wxObjectEventFunction

private:
	wxBoxSizer m_sizer;
	wxBoxSizer m_displaySizer1;
	wxBoxSizer m_displaySizer2;
	wxBoxSizer m_displaySizer;
	wxBoxSizer m_ctrlSizer;
	wxButton m_btnPlay;
	wxButton m_btnStop;
	wxWindow m_displayWindow;
	wxWindow *m_displayForcus;
	wxStaticText m_urlDesc;
	wxComboBox m_textUrl;

	CPlayManager m_playManager;
	j_int32_t m_streamId;
	std::map<wxWindow *, j_int32_t> m_playerMap;
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
	CVodPlayer *dlg = new CVodPlayer(wxT("StreamPlayer")); 
	dlg->Show(true); 

	return true; 
} 

CVodPlayer::CVodPlayer(const wxString& title)
: wxDialog(NULL,wxID_ANY,title) 
, m_sizer(wxVERTICAL)
, m_displaySizer1(wxHORIZONTAL)
, m_displaySizer2(wxHORIZONTAL)
, m_displaySizer(wxVERTICAL)
, m_ctrlSizer(wxHORIZONTAL)
, m_btnPlay(this, wxID_ANY, wxT("Play"))
, m_btnStop(this, wxID_ANY, wxT("Stop"))
, m_textUrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(550, 20))
, m_urlDesc(this, wxID_ANY, wxT("���ŵ�ַ:"))
, m_displayWindow(this, wxID_ANY)
, m_displayForcus(NULL)
{
	m_displayWindow.GetHandle();
	SetSize(wxSize(800, 800));
	CentreOnScreen();
	/* ��ӡ���ʼ�����ڿؼ��ĵط�*/ 
	m_ctrlSizer.AddSpacer(10);
	m_urlDesc.SetSize(wxSize(50, 15));
	m_ctrlSizer.Add(&m_urlDesc);
	m_ctrlSizer.AddSpacer(10);
	m_textUrl.Append(wxT("jorf://192.168.1.12:8002?resid=121&username=admin&passwd=12345&start=1381507200&end=1381549188"));
	m_textUrl.Append(wxT("jorf://192.168.1.12:8002?resid=161&username=admin&passwd=12345&start=1381507200&end=1381549188"));

	m_textUrl.SetSelection(0);
	m_ctrlSizer.Add(&m_textUrl);
	m_ctrlSizer.AddSpacer(10);
	m_ctrlSizer.Add(&m_btnPlay);
	m_ctrlSizer.AddSpacer(10);
	m_ctrlSizer.Add(&m_btnStop);

	m_displayWindow.SetSize(800, 600);
	m_displayWindow.SetBackgroundColour(wxColour(0, 0, 0));

	m_sizer.Add(&m_displayWindow);
	m_sizer.AddSpacer(50);
	m_sizer.Add(&m_ctrlSizer);
	SetSizer(&m_sizer);
	
	m_playManager.Init();
	m_btnPlay.Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CVodPlayer::OnPlay));
	m_btnStop.Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CVodPlayer::OnStop));
	m_displayWindow.Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(CVodPlayer::OnMouseLeftDown));
} 

CVodPlayer::~CVodPlayer()
{
	m_playManager.Deinit();
}

void CVodPlayer::OnPlay(wxMouseEvent& evnet)
{
	CVodPlayer *pStreamPlayer = (CVodPlayer *)GetParent();
	pStreamPlayer->Play();
}

void CVodPlayer::OnStop(wxMouseEvent &evnet)
{
	CVodPlayer *pStreamPlayer = (CVodPlayer *)GetParent();
	pStreamPlayer->Stop();
}

void CVodPlayer::OnMouseLeftDown(wxMouseEvent &event)
{
	//event.Skip();
	//wxPostEvent(GetParent(), event);
	CVodPlayer *pStreamPlayer = (CVodPlayer *)GetParent();
	pStreamPlayer->SetForcus(event.GetEventObject());
	//fprintf(stderr, "CVodPlayer::OnMouseLeftDown %d %d\n", event.GetEventObject(), event.GetY());
	//fprintf(stderr, "CVodPlayer::OnMouseLeftDown %d %d\n", &pStreamPlayer->m_displayWindow1, pStreamPlayer->m_displayWindow2.GetId());
}

void CVodPlayer::Play()
{
	if (m_displayForcus != NULL && m_playerMap.find(m_displayForcus) == m_playerMap.end())
	{
		char desUrl[256] = {0};
		sprintf(desUrl, "jo_player://%d", (j_wnd_t)m_displayForcus->GetHandle());
		j_int32_t streamId = -1;
		//��ʷ��Ƶ
		streamId = m_playManager.OpenVod(m_textUrl.GetValue(), desUrl);
		m_displayForcus->SetId(streamId);
		m_playerMap[m_displayForcus] = streamId;
	}
}

void CVodPlayer::Stop()
{
	std::map<wxWindow *, j_int32_t>::iterator it = m_playerMap.find(m_displayForcus);
	if (it != m_playerMap.end())
	{
		//��ʷ��Ƶ
		m_playManager.CloseVod(m_displayForcus->GetId());
		m_playerMap.erase(it);
	}
}

void CVodPlayer::SetForcus(wxObject *window)
{
	m_displayForcus = dynamic_cast<wxWindow *>(window);
}
BEGIN_EVENT_TABLE(CVodPlayer, wxDialog) 
/* �����Ϣӳ��ĵط�������˵���Ӧ*/
//EVT_LEFT_DOWN(CVodPlayer::OnMouseLeftDown)
END_EVENT_TABLE() 