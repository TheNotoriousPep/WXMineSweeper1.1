#pragma once
#include "wx/wx.h"
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

