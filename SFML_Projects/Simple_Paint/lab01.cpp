// Calosc mozna dowolnie edytowac wedle uznania. 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "font.h"
#include "Draw.h"

class Menu : public sf::Drawable
{
private:
	sf::Font font;
	sf::Text *text;
	sf::RectangleShape *rectangle;

	sf::Texture *colors_texture;
	sf::Sprite *colors_sprite;
	sf::Uint8 *colors_pixels;
	const unsigned int colors_size_x = 765;
	const unsigned int colors_size_y = 60;
	inline void draw_to_color_pixels(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b)
	{
		colors_pixels[4 * (y * colors_size_x + x) + 0] = r;
		colors_pixels[4 * (y * colors_size_x + x) + 1] = g;
		colors_pixels[4 * (y * colors_size_x + x) + 2] = b;
		colors_pixels[4 * (y * colors_size_x + x) + 3] = 255;
	}

public:
	Menu()
	{
		font.loadFromMemory(font_data, font_data_size);
		text = new sf::Text;
		text->setFont(font);
		text->setCharacterSize(12);
		text->setFillColor(sf::Color::White);

		rectangle = new sf::RectangleShape(sf::Vector2f(796, 536));
		rectangle->setFillColor(sf::Color::Transparent);
		rectangle->setOutlineColor(sf::Color::White);
		rectangle->setOutlineThickness(1.0f);
		rectangle->setPosition(2, 62);

		unsigned int x, y;
		colors_pixels = new sf::Uint8[colors_size_x * colors_size_y * 4];
		for (x = 0; x<255; x++)
			for (y = 0; y < 30; y++)
			{
				draw_to_color_pixels(x, y, x, 255, 0);
				draw_to_color_pixels(x + 255, y, 255, 255 - x, 0);
				draw_to_color_pixels(x + 510, y, 255, 0, x);
				draw_to_color_pixels(254 - x, y + 30, 0, 255, 255 - x);
				draw_to_color_pixels(509 - x, y + 30, 0, x, 255);
				draw_to_color_pixels(764 - x, y + 30, 255 - x, 0, 255);
			}

		colors_texture = new sf::Texture();
		colors_texture->create(colors_size_x, colors_size_y);
		colors_texture->update(colors_pixels);

		colors_sprite = new sf::Sprite();
		colors_sprite->setTexture(*colors_texture);
		colors_sprite->setPosition(1, 1);
	}

	void outtextxy(sf::RenderTarget& target, float x, float y, const wchar_t *str) const
	{
		text->setPosition(x, y);
		text->setString(str);
		target.draw(*text);
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		outtextxy(target, 5, 600, L"f - wybór koloru rysowania");
		outtextxy(target, 5, 615, L"b - wybór koloru wype³niania");
		outtextxy(target, 5, 630, L"l - rysowanie linii");

		outtextxy(target, 200, 600, L"r - rysowanie prostok¹ta");
		outtextxy(target, 200, 615, L"a - rysowanie wype³nionego prostok¹ta");
		outtextxy(target, 200, 630, L"c - rysowanie okrêgu");

		outtextxy(target, 470, 600, L"w - zapis do pliku");
		outtextxy(target, 470, 615, L"o - odczyt z pliku");
		outtextxy(target, 470, 630, L"esc - wyjœcie");

		outtextxy(target, 650, 615, L"Aktualne:");

		target.draw(*rectangle);
		target.draw(*colors_sprite);
	}
};



int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	Menu menu;
	//kolor ramki i kolor wypelnienia
	sf::Color non_fill_color(0,0,0,0), fill_color(0,0,0,0);
	sf::Font font;
	sf::Text text;
	sf::Texture result;
	result.create(800, 650);

	sf::Sprite sprite;
	sprite.setTexture(result);
	//prostokaty do wyboru kolorow
	sf::RectangleShape rec_for_non_fill, rec_for_fill;
	//tablica do rysowania linii i ilosc linii w tablicy
	std::vector<sf::VertexArray> lines;
	int lines_size = 0;
	//bufor i ilosc danych w buforze
	std::vector<int> bufor;
	int bufor_size = 0;
	//tablica prostokatow i ilosc 
	std::vector<sf::RectangleShape> rectangle;
	int rec_size = 0;
	//tablica kol i rozmiar
	std::vector<sf::CircleShape> circle;
	int circle_size = 0;

	// wybrana opcja
	int letter = 0;


	font.loadFromMemory(font_data, font_data_size);
	text.setFont(font);
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::White);
	text.setPosition(710, 615);

	rec_for_non_fill.setSize(sf::Vector2f(30.0, 29.0));
	rec_for_non_fill.setOutlineColor(sf::Color::Transparent);
	rec_for_non_fill.setPosition(768, 1);

	rec_for_fill.setSize(sf::Vector2f(30.0, 29.0));
	rec_for_fill.setOutlineColor(sf::Color::Transparent);
	rec_for_fill.setPosition(768, 32);
	

	window.setFramerateLimit(60);
	//poczatkowe wartosci do rysowania
	float start_x, start_y;
	//flaga rysowania
	bool draw_flag = false;

	result.update(window);
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		rec_for_fill.setFillColor(fill_color);
		rec_for_non_fill.setFillColor(non_fill_color);
		result.update(window);

		//zmienne okgreslajace pozycje i flage rysowania
	

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			//Tu trzeba obsluzyc zdarzenia zwiazane z myszka oraz klawiatura.
			if (event.type == sf::Event::MouseMoved)
			{
				std::cout << "x: " << event.mouseMove.x << " y: " << event.mouseMove.y<<std::endl;
			}
			//obsluga klawiszy
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::F)
				{
					text.setString("f");
					letter = 1;
				}
				if (event.key.code == sf::Keyboard::B)
				{
					text.setString("b");
					letter = 2;
				}
				if (event.key.code == sf::Keyboard::L)
				{
					text.setString("l");
					letter = 3;	
				}
				if (event.key.code == sf::Keyboard::R)
				{
					text.setString("r");
					letter = 4;
				}
				if (event.key.code == sf::Keyboard::A)
				{
					text.setString("a");
					letter = 5;
				}
				if (event.key.code == sf::Keyboard::C)
				{
					text.setString("c");
					letter = 6;
				}

				if (event.key.code == sf::Keyboard::W)
				{
					text.setString("w");
					letter = 7;
				}

				if (event.key.code == sf::Keyboard::O)
				{
					text.setString("o");
					letter = 8;
				}
				if (event.key.code == sf::Keyboard::Escape) window.close();
			}
			//wybor kolorow
			if (letter == 1)
				{
				if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					unsigned int x = event.mouseButton.x;
					unsigned int y = event.mouseButton.y;
					getCollor(x, y, non_fill_color);
					rec_for_non_fill.setFillColor(non_fill_color);
				}
			}
			if (letter == 2)
			{
				if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					unsigned int x = event.mouseButton.x;
					unsigned int y = event.mouseButton.y;
					getCollor(x, y, fill_color);
					rec_for_fill.setFillColor(fill_color);
				}
			}
			
			if (letter == 3)
			{
				Draw_Line(start_x, start_y, event, non_fill_color, fill_color, bufor, bufor_size, draw_flag, lines, lines_size, window);
			}

			if (letter == 4)
			{
				Draw_Empty_Rec(start_x, start_y, event, non_fill_color, sf::Color::Transparent, bufor, bufor_size, draw_flag, rectangle, rec_size);
			}
			if (letter == 5)
			{
				Draw_Empty_Rec(start_x, start_y, event, non_fill_color, fill_color, bufor, bufor_size, draw_flag, rectangle, rec_size);
			}
			if (letter == 6)
			{
				Draw_Circle(start_x, start_y, event, non_fill_color, sf::Color::Transparent, circle, circle_size, draw_flag, bufor, bufor_size);
			}
			
		}
		//zmienna do przechodzenia po buforze i tablicach ksztaltow
		int i = 0;
		int curr_line = 0;
		int curr_rec = 0;
		int curr_cir = 0;

		//Draw BEGIN
		// Pomiêdzy "Draw BEGIN" a "Draw End" trzeba "cos" dopisac :-). Na pewno znajd¹ siê tam te dwie linijki:

		//rysowanie z bufora
		while (i < bufor_size)
		{
			if (bufor[i] == 3)
			{ 
				if (lines_size > 0)
				{
					window.draw(lines[curr_line++]);
					i++;
				}
			}
			else if (bufor[i] == 4)
			{
				if (rec_size > 0)
				{
					window.draw(rectangle[curr_rec++]);
					i++;
				}
			}
			else if (bufor[i] == 6)
			{
				if (circle_size > 0)
				{
					window.draw(circle[curr_cir++]);
					i++;
				}
			}
			
		}

		window.draw(menu);
		//wstawianie litery w rog
		window.draw(text);
		//wybor koloru obramowania
		window.draw(rec_for_non_fill);
		//wybor koloru wypelnienia
		window.draw(rec_for_fill);
		result.update(window);
		window.display();
		//Draw END

		if (letter == 7)
		{
			result.copyToImage().saveToFile("result.png");
			letter = 0;
		}
		if (letter == 8)
		{
			result.loadFromFile("result.png");
			window.draw(sprite);
			bufor_size = 0;
			letter = 0;
		}
	}
	return 0;
}