#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>

#define DriverNotebook wxNotebook

enum 
{
	// Control ID's ///////////////////////////////////////////////////////
	DriveBook_MainBook = wxID_HIGHEST + 1, // ID for the main book in upper panel
	DriveBook_QuitBtn // Quit button in lower panel
};

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

	void OnQuit(wxCommandEvent& event);

	wxMenuBar *menuBar;
	wxMenu *fileMenu;

private:
	// The panel which holds all the contents in the main frame
	wxPanel * mainPanel;

	// This is a notebook which should contain pages of a driver's schedule
	DriverNotebook * driveBook;
};