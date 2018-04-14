#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

	void OnQuit(wxCommandEvent& event);

	wxMenuBar *menuBar;
	wxMenu *fileMenu;
};