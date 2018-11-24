#include "Derived.h"
#include <wx/clipbrd.h>

MyOwnFrame::MyOwnFrame(wxWindow* parent)
	:MyFrame(parent)
{
	
	SetTitle("Lab03");
	SetIcon(wxNullIcon);
	SetSize(8, 8, 800, 650);
	Center();
	scroll->Enable(false);
	banana = false;
	ksztalt = 0;
	odswiez = false;
	kat = 0;
	m_panel3->GetClientSize(&X, &Y);
	
	wybor->Append("gwiazdka");
	wybor->Append("ksiê¿yc");
	wybor->Append("s³onko");
	wybor->SetSelection(0);
	scroll->SetScrollbar(10, 15, 100, 10);
	DC = new wxClientDC(m_panel3);

	MyImage.AddHandler(new wxPNGHandler);
	//Bind(wxEVT_SIZE, &MyOwnFrame::Resize, this);


}

void MyOwnFrame::Zapisz(wxCommandEvent& event)
{
	wxFileDialog *FileDialog = new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_SAVE);
	
	if (FileDialog->ShowModal() == wxID_OK)
	{
		wxMemoryDC memory;
		int w, h;
		m_panel3->GetClientSize(&w, &h);
		SaveBitMap = new wxBitmap(w, h);
		memory.SelectObject(*SaveBitMap);
		memory.Blit(0, 0, w, h, DC, 0, 0, wxCOPY, true);
		wxString PlaceName = FileDialog->GetPath();
		wxImage saveimage = SaveBitMap->ConvertToImage();
		saveimage.InitStandardHandlers();
		saveimage.SaveFile(PlaceName);
	}
	
}

void MyOwnFrame::Check(wxCommandEvent& event)
{
	if (scroll->IsEnabled())
	{
		scroll->Enable(false);
		banana = false;
	}
	else
	{
		scroll->Enable(true);
		banana = true;
		MyImage.LoadFile("banan.png", wxBITMAP_TYPE_PNG);
		MyImage.Rescale(50, 50);
		MyBitmap = wxBitmap(MyImage);
	}
	odswiez = true;
	
	
}

void MyOwnFrame::Scroll(wxScrollEvent& event)
{
	kat = scroll->GetThumbPosition();
	suwak->SetValue(1.2*kat);
	odswiez = true;
	Draw();
}

void MyOwnFrame::Wybor_kolor(wxCommandEvent& event)
{
	m_ColourData = new wxColourData;
	m_ColourDialog = new wxColourDialog(this);
	if (m_ColourDialog->ShowModal() == wxID_OK)
	{
		*m_ColourData = m_ColourDialog->GetColourData();
		kolor_gwiazd = m_ColourData->GetColour();
		m_ColourDialog->Destroy();
		odswiez = true;
	}
}

void MyOwnFrame::TextEntered(wxCommandEvent& event)
{
	
	odswiez = true;

}

void MyOwnFrame::OnText(wxCommandEvent& event)
{
	odswiez = true;
}

void MyOwnFrame::Choice(wxCommandEvent& event)
{
	ksztalt = wybor->GetSelection();
	odswiez = true;
}

void MyOwnFrame::Draw()
{
	m_panel3->GetClientSize(&re_X, &re_Y);
	if (re_X - X != 0 && re_Y - Y != 0)
	{
		DC->SetDeviceOrigin((re_X - X) / 2, (re_Y - Y) / 2);
		X = re_X;
		Y = re_Y;
		odswiez = true;
	}
	
	//czyszczenie
	if (odswiez)
	{
		DC->Clear();
	}
	


	//rysowanie wzystkiego

	DC->SetPen(wxPen(*wxBLACK, 2));
	DC->SetBrush(wxBrush(*wxWHITE, wxTRANSPARENT));
	//stale elementy
	DC->DrawCircle(320, 310, 30); //glowa
	DC->DrawLine(320, 340, 320, 470); //cialo
	DC->DrawLine(320, 470, 290, 530); // prawa noga
	DC->DrawLine(320, 470, 350, 530); //lewa noga
	DC->DrawLine(320, 380, 370, 420); // nie ruszajaca reka
	DC->DrawEllipse(300, 300, 13, 9);

	//ruszajace elementy
	 
	

	if (!banana)
	{
		DC->DrawEllipticArc(310, 320 , 20, 20, 0, 180);
		DC->DrawEllipse(325, 295, 9, 13);
	}
	else
	{
		DC->DrawEllipticArc(310, 310, 20, 20, -180, 0);
		DC->DrawEllipse(320, 300, 13, 9);
		//banan
		if (MyBitmap.Ok()) DC->DrawBitmap(MyBitmap, 260 - 0.3 * kat, 400 - kat);
	}

	// ruszajaca reka
	DC->DrawLine(320, 380, 270 - 0.2 * kat, 420 - kat);

	if (ksztalt == 2)
	{
		// MyDC->SetBrush(wxBrush(wxColour(192, 192, 192), wxSOLID));
		DC->SetPen(wxPen(*wxYELLOW, 2));
		DC->SetBrush(wxBrush(*wxYELLOW, wxSOLID));
		DC->DrawCircle(240, 200, 50);
		
	}
	else if (ksztalt == 0)
	{
		DC->SetPen(wxPen(kolor_gwiazd, 2));
		DC->SetBrush(wxBrush(kolor_gwiazd, wxSOLID));
		wxPoint a[3];
		//1
		a[0] = wxPoint(240, 200);
		a[1] = wxPoint(250, 180);
		a[2] = wxPoint(260, 200);
		DC->DrawPolygon(3, a);
		//2
		a[0] = wxPoint(240, 200 );
		a[1] = wxPoint(220, 210);
		a[2] = wxPoint(240, 220);
		DC->DrawPolygon(3, a);
		//3
		a[0] = wxPoint(240, 220);
		a[1] = wxPoint(250, 240);
		a[2] = wxPoint(260, 220);
		DC->DrawPolygon(3, a);
		//4
		a[0] = wxPoint(260, 200);
		a[1] = wxPoint(280, 210);
		a[2] = wxPoint(260, 220);
		DC->DrawPolygon(3, a);
		//5
		/*a[0] = wxPoint(240, 200);
		a[1] = wxPoint(250, 190);
		a[2] = wxPoint(260, 200);
		DC.DrawPolygon(3, a);*/
	}
	else
	{
		DC->SetPen(wxPen(*wxLIGHT_GREY, 2));
		DC->SetBrush(wxBrush(*wxLIGHT_GREY, wxSOLID));
		DC->DrawCircle(240, 200, 60);
		DC->SetPen(wxPen(*wxWHITE, 2));
		DC->SetBrush(wxBrush(*wxWHITE, wxSOLID));
		DC->DrawCircle(230, 190, 50);
		DC->SetPen(wxPen(*wxBLACK, 2));
		DC->SetBrush(wxBrush(*wxBLACK, wxSOLID));
		DC->DrawCircle(270, 220, 7);
		DC->DrawLine(245, 235, 265, 240);

	}
	
	//tekst
	DC->SetTextBackground(*wxWHITE);
	DC->SetBrush(wxBrush(*wxBLACK));
	DC->SetFont(wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT, false, "Arial"));
	DC->DrawText(text->GetValue(), 230, 530);
	DC->SetFont(wxFont(40, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false,"Comic Sans"));
	DC->DrawRotatedText(text->GetValue(), 410, 470, 90);

	
	odswiez = false;
	
}

void MyOwnFrame::OnUpdateUI(wxUpdateUIEvent& event)
{
	Draw();
}

/*void MyOwnFrame::Resize(wxSizeEvent & e)
{
	m_panel3->GetClientSize(&re_X, &re_Y);
	DC->SetDeviceOrigin(re_X - X, re_Y - Y);
}*/
