#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 250))
{
	menuBar = new wxMenuBar;
	
	fileMenu = new wxMenu;
	fileMenu->Append(wxID_EXIT, wxT("&Quit"));
	
	menuBar->Append(fileMenu, wxT("&File"));
	
	SetMenuBar(menuBar);
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnQuit));

	// Panel which will contain the two halves: upper, lower /////////////////////////
	mainPanel = new wxPanel(this, wxID_ANY);
	wxSizer * sizerUpper = new wxBoxSizer(wxVERTICAL);

	int style = wxBK_DEFAULT; // Style for a wxNotebook

	driveBook = new DriverNotebook(mainPanel, DriveBook_MainBook,
		wxDefaultPosition, wxDefaultSize, style, "Drive - MainBook");

	// Bottom portion
	wxSizer * sizerLower = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer * sizerBtns = new wxBoxSizer(wxHORIZONTAL);
	wxButton * btn;

	btn = new wxButton(mainPanel, DriveBook_QuitBtn, wxT("Exit"));
	sizerBtns->Add(btn);
	sizerLower->Add(sizerBtns, 0, wxALL | wxALIGN_RIGHT, 5);

	// Combine both upper and lower parts together (notice how everything is
	// technically all in the sizerUpper, which in turn will be in the mainPanel)
	sizerUpper->Add(driveBook, 1, wxGROW | (wxALL & ~(wxTOP | wxBOTTOM)), 10);
	sizerUpper->Add(0, 5, 0, wxGROW); // Add spaced between the halves
	sizerUpper->Add(sizerLower, 0, wxGROW | (wxALL & ~wxTOP), 10);

	mainPanel->SetSizer(sizerUpper);

	Centre(); // Still not sure the difference between Centre() and Center(), if any...
}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}