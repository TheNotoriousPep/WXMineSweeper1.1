#include "cMain.h"
////////////////


///////////////


wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001,OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr,wxID_ANY, "Bernardo San Germano - MineSweeper1.1",wxPoint(100,100), wxSize(500,500)) {
	btn = new wxButton * [Height * Width];
	wxGridSizer* grid = new wxGridSizer(Width, Height, 0, 0);
	
	minefield = new int[Width * Height];

	//Fonts
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);


	for (int x = 0; x < Width; x++)
	{
		for (int y = 0; y < Height; y++)
		{
			btn[y * Width + x] = new wxButton(this, 10000 + (y * Width + x));
			btn[y * Width+x]->SetFont(font);
			grid->Add(btn[y * Width + x], 1, wxEXPAND | wxALL);
			
			btn[y * Width + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
			minefield[y * Width + x] = 0;
		}
	}

	this->SetSizer(grid);
	grid->Layout();
}

cMain::~cMain() {
	delete[] btn;
}

void cMain::OnButtonClicked(wxCommandEvent& evt) {
	
	int xcoord = (evt.GetId() - 10000) % Width;
	int ycoord = (evt.GetId() - 10000) / Width;
	if (FirstClick)
	{
		int mines = 30;
			while (mines)
			{
				int mineX = rand() % Width;
				int mineY = rand() & Height;

				if (minefield[mineY * Width + mineX] == 0 && mineX != xcoord && mineY != ycoord)
				{
					minefield[mineY * Width + mineX] = -1;
					mines--;
				}
			}
			FirstClick = false;	
	}

	btn[ycoord * Width + xcoord]->Enable(false);

	//Check if mine is stepped on
	//if so, reset.
	//iterate through the playing field and reset each button.
	if (minefield[ycoord*Width+xcoord]== -1)
	{
		wxMessageBox("rip, you stepped on a mine. :(");
		FirstClick = true;

		for (int x = 0; x < Width; x++)
		{
			for (int y = 0; y < Height; y++)
			{
				minefield[y * Width + x] = 0;
				btn[y * Width + x]->SetLabel(" ");
				btn[y * Width + x]->Enable(true);
			}
		}

	}
	else
	{
		//count the neighbors of each mine if there even is one.
		int mine_neighbors = 0;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (xcoord + i >= 0 && xcoord + i < Width && ycoord + j >= 0 && ycoord+j < Height)
				{
					if (minefield[(ycoord+j)*Width+(xcoord+i)]==-1)
					{
						mine_neighbors++;
					}
				}
			}
		}
	//checks if there are more than 0 mine neighbors, if so then set the label of that square to the corresponding mines adjacent to that square.
		if (mine_neighbors > 0) {
			btn[ycoord * Width + xcoord]->SetLabel(std::to_string(mine_neighbors));
		}
	}
	evt.Skip();
}