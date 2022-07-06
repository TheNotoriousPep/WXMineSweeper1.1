#include "cApp.h"
/*////////////////
Source code adapted from Javidx9's Cross Platform Graphical User Interfaces in C++ Tutorial video
https://www.youtube.com/watch?v=FOIbK4bJKS8
(June 15th, 2019)
///////////////*/
wxIMPLEMENT_APP(cApp);

cApp::cApp()
{

}

cApp::~cApp() {

}

bool cApp::OnInit() {
	m_frame1 = new cMain();
	m_frame1->Show();
	return true;
}