#pragma once
#include <wx/wxprec.h>
#include "noname.h"
#include <wx/colordlg.h>
#include <wx/dc.h>
#include <wx/dcbuffer.h>




class MyOwnFrame : public MyFrame 
{
public:
	MyOwnFrame(wxWindow* parent);
	void Draw();


protected:
	wxClientDC * DC;
	wxChoice *choice;
	wxImage MyImage;
	wxBitmap *SaveBitMap;
	wxBitmap MyBitmap;
	wxColourData *m_ColourData;
	wxColourDialog *m_ColourDialog;
	wxColour kolor_gwiazd;
	wxFileDialog *FileDialog;


	int re_X;
	int re_Y;
	int X, Y;
	bool banana;
	int ksztalt;
	bool odswiez;
	int kat;
	

	void Zapisz(wxCommandEvent& event);
	void Check(wxCommandEvent& event);
	void Scroll(wxScrollEvent& event);
	void Wybor_kolor(wxCommandEvent& event);
	void TextEntered(wxCommandEvent& event);
	void Choice(wxCommandEvent& event);
	void OnUpdateUI(wxUpdateUIEvent& event);
	void OnText(wxCommandEvent& event);

	//void Resize(wxSizeEvent & e);
	

};


