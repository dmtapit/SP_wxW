#include "main.h"
#include "MainFrame.h"

IMPLEMENT_APP(SP_wxWApp)

bool SP_wxWApp::OnInit()
{
	MainFrame *mf = new MainFrame(wxT("Main Frame"));
	mf->Show(true);

	return true;
}