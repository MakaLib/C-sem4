
#include "noname.h"
#include "Derived.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MyOwnFrame *frame = new MyOwnFrame(NULL);
	frame->Show(true);
	return true;
}