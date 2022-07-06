#pragma once
#include "wx/wx.h"
#include "cMain.h"
/*////////////////
Source code adapted from Javidx9's Cross Platform Graphical User Interfaces in C++ Tutorial video
https://www.youtube.com/watch?v=FOIbK4bJKS8
(June 15th, 2019)
///////////////*/
class cApp :public wxApp
{
public:	
	cApp();
	~cApp();

private: 
	cMain* m_frame1 = nullptr;

public:
	virtual bool OnInit();
};

