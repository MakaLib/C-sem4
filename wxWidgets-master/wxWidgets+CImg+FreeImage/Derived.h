#pragma once
#include <wx/wxprec.h>
#include "noname.h"
#include <wx/colordlg.h>
#include <wx/dc.h>
#include "CImg.h"
#include <wx/dcbuffer.h>
#include <vector>
#include "FreeImage.h"






class MyOwnFrame : public MyFrame 
{
public:
	MyOwnFrame(wxWindow* parent);




protected:

	void Wczytaj(wxCommandEvent& event);
	void Cenzura(wxCommandEvent& event);
	void Erode(wxCommandEvent& event);
	void OnUpdate(wxUpdateUIEvent& event);
	void Animacja(wxCommandEvent& event);
	void Animuj_maske();
	void MalyPanelUp(wxUpdateUIEvent& event);
	//void SizeChange(wxSizeEvent& event);

	void Rysuj();
	//void Form_Resize(wxSizeEvent & e);


	//wxFileDialog *OtwarciePliku;
	wxImage Obrazek;
	wxImage Obrazek_cpy;
	wxBitmap bitmapa;
	bool rozmiar = false;
	wxString nazwa_pliku;
	FIBITMAP *freebitmapa;


	std::vector <int> w_x1;
	std::vector<int> w_y1;
	std::vector <int> w_x2;
	std::vector<int> w_y2;
	std::vector<wxBitmap> obrazki;
	bool czy_animowac = false;
	int numer;
	bool check = false;

	

};


