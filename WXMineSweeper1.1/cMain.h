#pragma once
#include "wx/wx.h"
/*////////////////
Source code adapted from Javidx9's Cross Platform Graphical User Interfaces in C++ Tutorial video
https://www.youtube.com/watch?v=FOIbK4bJKS8
(June 15th, 2019)
///////////////*/
class cMain : public wxFrame
{
public: 
	
	cMain();
	~cMain();
public:
	int Height = 10;
	int Width = 10;
	wxButton** btn;
	int* minefield = nullptr;
	bool FirstClick = true;

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

