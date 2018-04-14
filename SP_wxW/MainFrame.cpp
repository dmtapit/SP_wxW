#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 250))
{
	menuBar = new wxMenuBar;
	
	fileMenu = new wxMenu;
	fileMenu->Append(wxID_EXIT, wxT("&Quit"));
	
	menuBar->Append(fileMenu, wxT("&File"));
	
	SetMenuBar(menuBar);
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnQuit));
	Centre();
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}