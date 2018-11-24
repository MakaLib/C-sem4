///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/gauge.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame 
{
	private:
	
	protected:
		wxButton* WczytajObraz;
		wxButton* Cenzur;
		wxButton* Erod;
		wxCheckBox* Animuj;
		wxGauge* m_gauge1;
		wxPanel* m_panel3;
		wxPanel* m_panel2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void Wczytaj( wxCommandEvent& event ) { event.Skip(); }
		virtual void Cenzura( wxCommandEvent& event ) { event.Skip(); }
		virtual void Erode( wxCommandEvent& event ) { event.Skip(); }
		virtual void Animacja( wxCommandEvent& event ) { event.Skip(); }
		virtual void MalyPanelUp( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnUpdate( wxUpdateUIEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1118,580 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame();
	
};

#endif //__NONAME_H__
