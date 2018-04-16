#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////////
// Event Table
///////////////////////////////////////////////////////////////////////////////
wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(MainMenu_Quit, MainFrame::OnQuit)

wxEND_EVENT_TABLE()

///////////////////////////////////////////////////////////////////////////////
//
// Main Frame
//
///////////////////////////////////////////////////////////////////////////////
MainFrame::MainFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1000, 750))
{
	menuBar = new wxMenuBar;
	
	fileMenu = new wxMenu;
	fileMenu->Append(wxID_EXIT, wxT("&Quit"));
	
	menuBar->Append(fileMenu, wxT("&File"));
	
	SetMenuBar(menuBar);
	
	//Moved the same functionality to the Event Table
	//Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MainFrame::OnQuit));

	// Panel which will contain the two halves: upper, lower /////////////////////////
	mainPanel = new wxPanel(this, wxID_ANY);
	wxSizer * sizerUpper = new wxBoxSizer(wxVERTICAL);

	wxSizer * sizerUpperControls = new wxBoxSizer(wxHORIZONTAL);

	int style = wxBK_DEFAULT; // Style for a wxNotebook

	driveBook = new DriverNotebook(mainPanel, DriveBook_MainBook,
		wxDefaultPosition, wxDefaultSize, style, "Drive - MainBook");

	wxStaticBox *box = new wxStaticBox(mainPanel, wxID_ANY, wxT("Buttons For Notebook"));
	wxSizer *sizerUpperBtns = new wxStaticBoxSizer(box, wxVERTICAL);
	wxButton * btn;
	btn = new wxButton(mainPanel, wxID_ANY, wxT("Test 1"));
	sizerUpperBtns->Add(btn);
	btn = new wxButton(mainPanel, wxID_ANY, wxT("Test 2"));
	sizerUpperBtns->Add(btn);

	sizerUpperControls->Add(driveBook, 1, wxGROW | (wxALL & ~(wxTOP | wxBOTTOM)), 10);
	sizerUpperControls->Add(sizerUpperBtns);

	// Bottom portion ////////////////////////////////////////////////////////////////
	//wxSizer * sizerLower = new wxBoxSizer(wxVERTICAL);

	wxStaticBox *box2 = new wxStaticBox(mainPanel, wxID_ANY, wxT("Master List"));
	wxSizer *sizerLowerBtns = new wxStaticBoxSizer(box2, wxVERTICAL);

	wxBoxSizer * sizerBtns = new wxBoxSizer(wxHORIZONTAL);

	btn = new wxButton(mainPanel, DriveBook_QuitBtn, wxT("Exit"));
	sizerBtns->Add(btn);
	sizerLowerBtns->Add(sizerBtns, 0, wxALL | wxALIGN_RIGHT, 5);

	// Combine both upper and lower parts together (notice how everything is
	// technically all contents are in sizerUpper, which in turn will be in the mainPanel)
	sizerUpper->Add(sizerUpperControls, 1, wxGROW | (wxALL & ~(wxTOP | wxBOTTOM)), 10);
	sizerUpper->Add(0, 5, 0, wxGROW); // Add spaced between the halves
	sizerUpper->Add(sizerLowerBtns, 0, wxGROW | (wxALL & ~wxTOP), 10);

	mainPanel->SetSizer(sizerUpper);

	Centre(); // Still not sure the difference between Centre() and Center(), if any...
}


// Main Frame's destructor
MainFrame::~MainFrame()
{

}

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}