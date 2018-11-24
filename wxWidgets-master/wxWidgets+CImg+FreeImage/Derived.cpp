#include "Derived.h"
#include <wx/clipbrd.h>

using namespace cimg_library;

MyOwnFrame::MyOwnFrame(wxWindow* parent)
	:MyFrame(parent)
{
	SetTitle("Maka");
	SetIcon(wxNullIcon);
	this->SetBackgroundColour(wxColor(192, 192, 192));
	numer = 0;
	Obrazek.AddHandler(new wxJPEGHandler);
}

void MyOwnFrame::Wczytaj(wxCommandEvent& event)
{
	wxFileDialog *plik = new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);
	plik->SetWildcard("JPG file (*.jpg)|*.jpg");

	

	if (plik->ShowModal() == wxID_OK)
	{
		nazwa_pliku = plik->GetPath();
		if (!Obrazek.LoadFile(nazwa_pliku, wxBITMAP_TYPE_JPEG))
		{
			wxLogError(_("Can't load file"));
		}
		else
		{
			bitmapa = wxBitmap(Obrazek);
			Obrazek_cpy = Obrazek.Copy();
			rozmiar = true;
			FREE_IMAGE_FORMAT format = FreeImage_GetFIFFromFilename(nazwa_pliku);
			freebitmapa = FreeImage_Load(format, nazwa_pliku, JPEG_DEFAULT);
		}
	}
}


void MyOwnFrame::Cenzura(wxCommandEvent& event)
{ 
	if (rozmiar)
	{
		Animuj->SetValue(false);
		Obrazek = Obrazek_cpy.Copy();
		CImg <unsigned char> img(Obrazek.GetWidth(), Obrazek.GetHeight(), 1, 3);
		cimg_forXY(img, x, y)
		{
			img(x, y, 0) = Obrazek.GetRed(x, y);
			img(x, y, 1) = Obrazek.GetGreen(x, y);
			img(x, y, 2) = Obrazek.GetBlue(x, y);
		}
		img.blur(5.);
		cimg_forXY(img, x, y)
		{
			if (x > 440 && x < 570 && y >15 && y < 80)
			{
				Obrazek.SetRGB(x, y, img(x, y, 0), img(x, y, 1), img(x, y, 2));
			}
		}
	}
}


void MyOwnFrame::Erode(wxCommandEvent& event)
{ 
	if (rozmiar)
	{	
		Animuj->SetValue(false);
		Obrazek = Obrazek_cpy.Copy();
		CImg<unsigned char> img(Obrazek.GetWidth(), Obrazek.GetHeight(), 1, 3);

		cimg_forXY(img, x, y)
		{
			img(x, y, 0) = Obrazek.GetRed(x, y);
			img(x, y, 1) = Obrazek.GetGreen(x, y);
			img(x, y, 2) = Obrazek.GetBlue(x, y);
		}
		img.erode(5);

		cimg_forXY(img, x, y)
		{
			Obrazek.SetRGB(x, y, img(x, y, 0), img(x, y, 1), img(x, y, 2));
		}
	}
}

void MyOwnFrame::Animacja(wxCommandEvent& event)
{
	if (rozmiar)
	{

		//check = true;
		obrazki.resize(0);
		const float color = 1.;
		const int a = 200;
		const int b = 150;
		double angle1 = 0.0;
		double angle2 = M_PI;
		while(angle1 < 2* M_PI)
		{
			wxImage zdjecie = Obrazek_cpy.Copy();
			CImg<unsigned char> img(zdjecie.GetWidth(), zdjecie.GetHeight(), 1, 3);
			CImg<float> fimg(zdjecie.GetWidth(), zdjecie.GetHeight());
			CImg<float> f2img(zdjecie.GetWidth(), zdjecie.GetHeight());
			
			int x1 = a * cos(angle1) + 425;
			int y1 = b * sin(angle1) + 226;
			int x2 = a * cos(angle2) + 425;
			int y2 = b * sin(angle2) + 226;
		
			fimg.draw_gaussian(x1, y1, 125, &color, 1);
			cimg_forXY(img, x, y)
			{
				img(x, y, 0) = zdjecie.GetRed(x, y);
				img(x, y, 1) = zdjecie.GetGreen(x, y);
				img(x, y, 2) = zdjecie.GetBlue(x, y);
			}

			f2img.draw_gaussian(x2, y2,125, &color, 1);
			fimg = fimg + f2img;
			img.mul(fimg);
			cimg_forXY(img, x, y)
			{
				zdjecie.SetRGB(x, y, img(x, y, 0), img(x, y, 1), img(x, y, 2));
			}
			obrazki.push_back(wxBitmap(zdjecie));
			angle1 += 0.1;
			angle2 += 0.1;
			m_gauge1->SetValue(angle1 * 5.8 * M_PI);
		}
	}
}


void MyOwnFrame::Animuj_maske()
{
	wxClientDC dc(m_panel2);
	if (rozmiar)
	{
			while (Animuj->GetValue())
			{
				dc.DrawBitmap(obrazki[numer], 0, 0, false);
				numer++;
				if (numer == int(obrazki.size())) numer = 0;
				Sleep(40);
			}	
	}
}

void MyOwnFrame::Rysuj()
{
	wxClientDC dc(m_panel2);
	
	if (Animuj->GetValue()) Animuj_maske();
	else dc.DrawBitmap(bitmapa, 0, 0, false);
}

void MyOwnFrame::OnUpdate(wxUpdateUIEvent& event)
{

	if (rozmiar)
	{
		int x;
		int y;
		m_panel2->GetClientSize(&x, &y);
		Obrazek.Rescale(x, y);
		bitmapa = wxBitmap(Obrazek);

		wxClientDC dc(m_panel3);
		dc.SetPen(wxPen(*wxBLACK, 2));
		dc.SetBrush(wxBrush(*wxBLACK, wxSOLID));
		dc.SetFont(wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT, false, "Tahoma"));

		//Version 2
		dc.DrawText("Rozmiar obrazka: " + std::to_string(Obrazek_cpy.GetWidth()) +"*"+ std::to_string(Obrazek_cpy.GetHeight()), 0, 0);
		dc.DrawText("EXIF Info:", 0, 20);
		FITAG *tag = NULL;
		FIMETADATA *mdhandle = NULL;
		std::string delim = ": ";
		FREE_IMAGE_MDMODEL model = FIMD_EXIF_MAIN;
		std::vector<std::string> metadata;
		mdhandle = FreeImage_FindFirstMetadata(model, freebitmapa, &tag);
		if (mdhandle) 
		{
			int i = 0;
			int y = 40;
			do 
			{
				const char *value = FreeImage_TagToString(model, tag);
				if (FreeImage_GetTagDescription(tag)) {
					std::string s = "";
					s.append(FreeImage_GetTagKey(tag));
					s.append(delim);
					s.append(value);
					metadata.push_back(s);
				}
				else {
					std::string s = "";
					s.append(FreeImage_GetTagKey(tag));
					s.append(delim);
					s.append(value);
					metadata.push_back(s);
				}

				dc.DrawText(metadata[i++], 0, y);
				y += 20;

			} while (FreeImage_FindNextMetadata(mdhandle, &tag));
		}

		FreeImage_FindCloseMetadata(mdhandle);
		Rysuj();
	}
	//if (check) check = false;

}

void MyOwnFrame::MalyPanelUp(wxUpdateUIEvent& event)
{
	
}

/*void MyOwnFrame::SizeChange(wxSizeEvent& event)
{
	if (rozmiar)
	{
		
		bitmapa = wxBitmap(Obrazek);
		Rysuj();
	}
}*/
