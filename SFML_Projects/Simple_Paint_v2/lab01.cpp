// Calosc mozna dowolnie edytowac wedle uznania. 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "font.h"
#include <cmath>




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
  inline void draw_to_color_pixels(unsigned int x, unsigned int y,unsigned char r, unsigned char g, unsigned char b)
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
      draw_to_color_pixels(x+255, y, 255, 255-x, 0);
      draw_to_color_pixels(x + 510, y, 255, 0, x);
      draw_to_color_pixels(254 - x, y+30, 0, 255, 255-x);
      draw_to_color_pixels(509 - x, y + 30, 0, x, 255 );
      draw_to_color_pixels(764 - x, y + 30, 255-x, 0, 255);
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
   outtextxy(target,5, 600, L"f - wybór koloru rysowania");
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




void getCollor(unsigned int x, unsigned int y, sf::Color &color)
{
	if (y <= 30 && y >= 1)
	{
		if (x <= 255) color = sf::Color(x, 255, 0, 255);
		if (x > 255 && x <= 510) color = sf::Color(255, 510 - x, 0, 255);
		if (x > 510 && x < 766) color = sf::Color(255, 0, x - 510, 255);
	}
	else if (y <= 60 && y > 30)
	{
		if (x <= 255) color = sf::Color(0, 255, x, 255);
		if (x > 255 && x <= 510) color = sf::Color(0, 510 - x, 255, 255);
		if (x > 510 && x < 766) color = sf::Color(x - 510, 0, 255, 255);
	}
}


int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01",sf::Style::Titlebar | sf::Style::Close);
 sf::Event event;
 Menu menu;
 sf::RectangleShape rec_for_non_fill, rec_for_fill, help_rec;
 sf::RectangleShape rectangle;
 sf::VertexArray line(sf::LinesStrip, 2);
 sf::CircleShape circle;
 sf::Color non_fill_color(0, 0, 0, 0), fill_color(0, 0, 0, 0);
 sf::Font font;
 sf::Text text;
 sf::Texture temp, texture;
 texture.create(800, 650);
 temp.create(800, 650);
 temp.update(window);
 
 sf::Sprite sprite, sprite_temp;
 sprite.setTexture(texture);
 sprite_temp.setTexture(temp);

 int letter = 0;
 bool draw_flag = false;
 float start_y, start_x;
 bool change_letter = false;
 
 window.setFramerateLimit(60);
 rec_for_non_fill.setSize(sf::Vector2f(30.0, 29.0));
 rec_for_non_fill.setOutlineColor(sf::Color::Transparent);
 rec_for_non_fill.setPosition(768, 1);

 rec_for_fill.setSize(sf::Vector2f(30.0, 29.0));
 rec_for_fill.setOutlineColor(sf::Color::Transparent);
 rec_for_fill.setPosition(768, 32);

 help_rec.setSize(sf::Vector2f(12,12));
 help_rec.setOutlineColor(sf::Color::Black);
 help_rec.setPosition(706, 617);
 help_rec.setFillColor(sf::Color::Black);

 font.loadFromMemory(font_data, font_data_size);
 text.setFont(font);
 text.setCharacterSize(12);
 text.setFillColor(sf::Color::White);
 text.setPosition(710, 615);

 rec_for_fill.setFillColor(fill_color);
 rec_for_non_fill.setFillColor(non_fill_color);

 while (window.isOpen())
  {
   window.clear(sf::Color::Black);
   window.draw(rec_for_fill);
   window.draw(rec_for_non_fill);
   
   while (window.pollEvent(event))
    {
     if (event.type == sf::Event::Closed) window.close();
	 if (event.type == sf::Event::KeyPressed)
	 {
		 if (event.key.code == sf::Keyboard::F)
		 {
			 text.setString("f");
			 letter = 1;
			 change_letter = true;
		 }
		 if (event.key.code == sf::Keyboard::B)
		 {
			 text.setString("b");
			 letter = 2;
			 change_letter = true;
		 }
		 if (event.key.code == sf::Keyboard::L)
		 {
			 text.setString("l");
			 letter = 3;
			 change_letter = true;
		 }
		 if (event.key.code == sf::Keyboard::R)
		 {
			 text.setString("r");
			 letter = 4;
			 change_letter = true;
		 }
		 if (event.key.code == sf::Keyboard::A)
		 {
			 text.setString("a");
			 letter = 5;
			 change_letter = true;
		 }
		 if (event.key.code == sf::Keyboard::C)
		 {
			 text.setString("c");
			 letter = 6;
			 change_letter = true;
		 }

		 if (event.key.code == sf::Keyboard::W)
		 {
			 text.setString("w");
			 letter = 7;
			 change_letter = true;
		 }

		 if (event.key.code == sf::Keyboard::O)
		 {
			 text.setString("o");
			 letter = 8;
			 change_letter = true;;
		 }
		 if (event.key.code == sf::Keyboard::Escape) window.close();
	 }
     //Tu trzeba obsluzyc zdarzenia zwiazane z myszka oraz klawiatura. 
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

	/* if (change_letter)
	 {
		 window.draw(help_rec);
		 change_letter = false;
	 }*/
	 
	 if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	 {
		 if (sf::Mouse::getPosition(window).y > 60 && sf::Mouse::getPosition(window).y < 600)
		 {
			 start_x = sf::Mouse::getPosition(window).x;
			 start_y = sf::Mouse::getPosition(window).y;
			 draw_flag = true;
		 }
	 }
	if (event.type == event.MouseButtonReleased && draw_flag)
	{
			 draw_flag = false;
			
			texture.update(temp.copyToImage());
			
	}
	
   }
   //Draw BEGIN
   // Pomiêdzy "Draw BEGIN" a "Draw End" trzeba "cos" dopisac :-). Na pewno znajd¹ siê tam te dwie linijki:
   
   window.draw(sprite);
   //window.draw(sprite_temp);
   if (draw_flag)
   {
	   if (letter == 3)
	   {
		   if (sf::Mouse::getPosition(window).y > 60 && sf::Mouse::getPosition(window).y < 600)
		   {
			   line[0].position = sf::Vector2f(start_x, start_y);
			   line[0].color = non_fill_color;
			   line[1].position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			   line[1].color = fill_color;
			   window.draw(line);
		   }
	   }
	   else if (letter == 4)
	   {
		   if (sf::Mouse::getPosition(window).y > 60 && sf::Mouse::getPosition(window).y < 600)
		   {
			   rectangle.setPosition(sf::Vector2f(start_x, start_y));
			   rectangle.setSize(sf::Vector2f(sf::Mouse::getPosition(window).x - start_x, sf::Mouse::getPosition(window).y - start_y));
			   rectangle.setFillColor(sf::Color::Transparent);
			   rectangle.setOutlineThickness(1);
			   rectangle.setOutlineColor(non_fill_color);
			   window.draw(rectangle);
		   }
	   }
	   else  if (letter == 5)
	   {
		   if (sf::Mouse::getPosition(window).y > 60 && sf::Mouse::getPosition(window).y < 600)
		   {
			   rectangle.setPosition(sf::Vector2f(start_x, start_y));
			   rectangle.setSize(sf::Vector2f(sf::Mouse::getPosition(window).x - start_x, sf::Mouse::getPosition(window).y - start_y));
			   rectangle.setFillColor(fill_color);
			   rectangle.setOutlineThickness(1);
			   rectangle.setOutlineColor(non_fill_color);
			   window.draw(rectangle);
		   }
	   }
	   else if (letter == 6)
	   {
		   if (sf::Mouse::getPosition(window).y > 60 && sf::Mouse::getPosition(window).y < 600)
		   {
			   float radius = sqrt(pow((sf::Mouse::getPosition(window).x - start_x), 2) + pow((sf::Mouse::getPosition(window).y - start_y), 2)) / 2;
			   circle.setPosition(((start_x + sf::Mouse::getPosition(window).x) / 2.0) - radius, ((sf::Mouse::getPosition(window).y + start_y) / 2.0) - radius);
			   circle.setFillColor(sf::Color::Transparent);
			   circle.setOutlineThickness(1);
			   circle.setOutlineColor(non_fill_color);
			   circle.setRadius(radius);
			   window.draw(circle);
		   }
	   }
   }

   window.draw(menu);
   temp.update(window);
   window.draw(text);
   window.draw(rec_for_non_fill);
   window.draw(rec_for_fill);
 
   window.display();
   if (letter == 7)
   {
	   texture.copyToImage().saveToFile("result.png");
	   letter = 0;
   }
   if (letter == 8)
   {
	   letter = 0;
	   texture.loadFromFile("result.png");
   }

   //Draw END
  }
 return 0;
}