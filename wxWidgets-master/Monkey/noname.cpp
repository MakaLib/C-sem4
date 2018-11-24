///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 91, false, wxEmptyString ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel3->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	m_panel3->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	
	bSizer1->Add( m_panel3, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	Zapis = new wxButton( this, wxID_ANY, wxT("Zapis do pliku"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( Zapis, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	banan = new wxCheckBox( this, wxID_ANY, wxT("banan"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( banan, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	scroll = new wxScrollBar( this, wxID_ANY, wxDefaultPosition, wxSize( 250,18 ), wxSB_HORIZONTAL );
	bSizer7->Add( scroll, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	suwak = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( -1,-1 ), wxGA_HORIZONTAL );
	suwak->SetValue( 0 ); 
	bSizer7->Add( suwak, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	kolor = new wxButton( this, wxID_ANY, wxT("kolor gwiazdki"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( kolor, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	text = new wxTextCtrl( this, wxID_ANY, wxT("tekst"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( text, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxArrayString wyborChoices;
	wybor = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wyborChoices, 0 );
	wybor->SetSelection( 0 );
	bSizer7->Add( wybor, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer1->Add( bSizer7, 0, 0, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_panel3->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::OnUpdateUI ), NULL, this );
	Zapis->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::Zapisz ), NULL, this );
	banan->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::Check ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	kolor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::Wybor_kolor ), NULL, this );
	text->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::OnText ), NULL, this );
	text->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame::TextEntered ), NULL, this );
	wybor->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame::Choice ), NULL, this );
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	m_panel3->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::OnUpdateUI ), NULL, this );
	Zapis->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::Zapisz ), NULL, this );
	banan->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::Check ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	scroll->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::Scroll ), NULL, this );
	kolor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::Wybor_kolor ), NULL, this );
	text->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::OnText ), NULL, this );
	text->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyFrame::TextEntered ), NULL, this );
	wybor->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame::Choice ), NULL, this );
	
}
