#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "font.h"
#include <vector>

float min(const float &r, const float &g, const float &b)
{
	if (r < b && r < g) return r;
	if (g < r && g < b) return g;
	return b;
}
float max(const float &r, const float &g, const float &b)
{
	if (r > b && r > g) return r;
	if (g > r && g > b) return g;
	return b;
}


inline void set_pixels(sf::Uint8 *pixels,const int &x,const int &y, const float &x1, const float &x2, const float &x3, const float alfa)
{
	pixels[4 * (y * 250 + x) + 0] = x1;
	pixels[4 * (y * 250 + x) + 1] = x2;
	pixels[4 * (y * 250 + x) + 2] = x3;
	pixels[4 * (y * 250 + x) + 3] = alfa;
}

inline void update_pix(sf::Uint8 *&pixels, const int &x, const int &y, const float &b)
{
	pixels[4 * (y * 250 + x) + 2] = b;
}

void RGB_Draw(sf::RenderWindow *window, sf::Texture *texture,const float *bar, sf::Uint8 *&RGB, sf::Uint8 *&CMY, sf::Uint8 *&HSL, sf::Uint8 *&HSV, const bool &done)
{	
	float radius;
	float cos;
	float angle,R,G,H,S;
	float B = *bar;
	float L = (*bar) / 255.0;
	float V = L;
	float HSL_r = 0, HSL_g = 0, HSL_b = 0, HSV_r = 0, HSV_g = 0, HSV_b = 0;
	float c, d, m;
	float r, g, b, rv, gv, bv,cv,dv,mv;
	for (int x = 0; x < 250; x++)
	{
		for (int y = 0; y < 250; y++)
		{
			radius = sqrt(pow((x-125), 2) + pow((125 - y),2));
			cos = ((double)(x)-125) / radius;
			

			angle = acos(cos);

			if (y > 125) angle = 6.28 - angle;

			R = radius * 255 / 125;
			G = angle * 255 / 6.28;
			
			H = angle / 6.28;
			S = radius / 125;
	
			

			if (radius <= 125)
			{
				
				c = (1.0 - fabs(2 * L - 1.0)) * S;
				d = c * (1.0 - fabsf(fmodf((H *6), 2.0) - 1.0));
				m = L - c / 2.0;
				cv = V * S;
				dv = cv * (1.0 - fabsf(fmodf(6 * H, 2) - 1.0));
				mv = V - cv;

				if (angle >= 0 && angle < 6.28 / 6.0)
				{
					r = c;	rv = cv;
					g = d;	gv = dv;
					b = 0;	bv = 0;
				}
				else if (angle >= 6.28/6 && angle < 6.28 /3)
				{
					r = d;	rv = dv;
					g = c;	gv = cv;
					b = 0;	bv = 0;
				}
				else if (angle >= 6.28/3 && angle < 6.28 / 2)
				{
					r = 0;	rv = 0;
					g = c;	gv = cv;
					b = d;	bv = dv;
				
				}
				else if (angle >= 6.28 / 2 && angle < 2*6.28 / 3)
				{
					r = 0;	rv = 0;
					g = d;	gv = dv;
					b = c;	bv = cv;
					
				}
				else if (angle >= 2*6.28 / 3 && angle < 5*6.28 / 6)
				{
					r = d;	rv = dv;
					g = 0;	gv = 0;
					b = c;	bv = cv;
				}
				else
				{
					r = c;	rv = cv;
					g = 0;	gv = 0;
					b = d;	bv = dv;
					
				}
				HSL_r = (r + m) * 255;	HSV_r = (rv + mv) * 255;
				HSL_g = (g + m) * 255;	HSV_g = (gv + mv) * 255;
				HSL_b = (b + m) * 255;	HSV_b = (bv + mv) * 255;
			}
			

			if (done && radius <= 125)
			{
				update_pix(RGB, x, y, B);
				update_pix(CMY, x, y,255 - B);
				set_pixels(HSL, x, y, HSL_r, HSL_g, HSL_b, 255);
				set_pixels(HSV, x, y, HSV_r, HSV_g, HSV_b, 255);
			}
			else if (radius > 125)
			{
				set_pixels(RGB,x,y, 0, 0, 0, 0);
				set_pixels(CMY, x, y, 0, 0, 0, 0);
				set_pixels(HSL, x, y, 0, 0, 0, 0);
				set_pixels(HSV, x, y, 0, 0, 0, 0);
			}
			else
			{
				set_pixels(RGB,x,y, R,G,B, 255);
				set_pixels(CMY, x, y, 255 - R,255 -  G,255 - B, 255);
				set_pixels(HSL, x, y,HSL_r,HSL_g, HSL_b, 255);
				set_pixels(HSV, x, y, HSV_r,HSV_g,HSV_b, 255);
			}


		
		}
	}
	sf::Texture RGB_texture;
	sf::Texture CMY_texture;
	sf::Texture HSL_texture;
	sf::Texture HSV_texture;

	sf::Sprite CMY_sprite;
	sf::Sprite RGB_sprite;
	sf::Sprite HSL_sprite;
	sf::Sprite HSV_sprite;

	RGB_texture.create(250, 250);
	RGB_texture.update(RGB);
	RGB_sprite.setTexture(RGB_texture);
	RGB_sprite.setPosition(365, 375);

	CMY_texture.create(250, 250);
	CMY_texture.update(CMY);
	CMY_sprite.setTexture(CMY_texture);
	CMY_sprite.setPosition(35,375);

	HSL_texture.create(250, 250);
	HSL_texture.update(HSL);
	HSL_sprite.setTexture(HSL_texture);
	HSL_sprite.setPosition(35, 65);

	HSV_texture.create(250, 250);
	HSV_texture.update(HSV);
	HSV_sprite.setTexture(HSV_texture);
	HSV_sprite.setPosition(365, 65);

	window->draw(HSL_sprite);
	window->draw(CMY_sprite);
	window->draw(RGB_sprite);
	window->draw(HSV_sprite);
	texture->update(*window);
}

int main()
{
	
 sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close);
 sf::Clock clock;
 sf::Time time = sf::Time::Zero;
 unsigned int FPS = 0 , frame_counter = 0;
 bool draw_flag = false;
 float chossen_y;

 sf::Font font;
	 font.loadFromMemory(font_data, font_data_size);
 sf::Text text, RGB, HSV, HSL, CMY,L,V,Y,B;
 text.setFont(font); RGB.setFont(font); HSV.setFont(font); HSL.setFont(font); CMY.setFont(font); L.setFont(font); V.setFont(font); Y.setFont(font); B.setFont(font);
 text.setString("0 FPS"); RGB.setString("RGB"); HSV.setString("HSV"); HSL.setString("HSL"); CMY.setString("CMY");

 /////////////////
 text.setPosition(sf::Vector2f(650, 290)); RGB.setPosition(sf::Vector2f(350, 360));  HSV.setPosition(sf::Vector2f(350, 60));  CMY.setPosition(sf::Vector2f(50, 360));  HSL.setPosition(sf::Vector2f(50, 60));
 L.setPosition(sf::Vector2f(230, 300)); V.setPosition(sf::Vector2f(570, 300)); Y.setPosition(sf::Vector2f(230, 610)); B.setPosition(sf::Vector2f(570, 610));
 text.setFillColor(sf::Color::Black);  HSL.setFillColor(sf::Color::Black);  HSV.setFillColor(sf::Color::Black);  CMY.setFillColor(sf::Color::Black); RGB.setFillColor(sf::Color::Black);
 L.setFillColor(sf::Color::Black); V.setFillColor(sf::Color::Black); Y.setFillColor(sf::Color::Black); B.setFillColor(sf::Color::Black);
 text.setCharacterSize(12); HSL.setCharacterSize(12); HSV.setCharacterSize(12); CMY.setCharacterSize(12); RGB.setCharacterSize(12);
 V.setCharacterSize(12); L.setCharacterSize(12); Y.setCharacterSize(12); B.setCharacterSize(12);

 ///Event///////////////
 sf::Event event;
 ///////////////////////

 //tablice kolek /////////////////////////
 sf::Uint8 *RGB_pix = new sf::Uint8[250 * 250 * 4];
 sf::Uint8 *CMY_pix = new sf::Uint8[250 * 250 * 4];
 sf::Uint8 *HSL_pix = new sf::Uint8[250 * 250 * 4];
 sf::Uint8 *HSV_pix = new sf::Uint8[250 * 250 * 4];
 /////////////////////////////////'

 ///////////////////////////////////////////////

 sf::RectangleShape rec_line;
 rec_line.setFillColor(sf::Color::Transparent);
 rec_line.setOutlineColor(sf::Color::Black);
 rec_line.setOutlineThickness(1.0f);
 rec_line.setPosition(sf::Vector2f(647, 13));
 rec_line.setSize(sf::Vector2f(46, 259));

 sf::VertexArray line(sf::LinesStrip, 2);
 line[0].position = sf::Vector2f(635,142);
 line[0].color = sf::Color::Black;
 line[1].position = sf::Vector2f(705, 142);
 line[1].color = sf::Color::Black;

 sf::Uint8 *pixels = new sf::Uint8[40 * 255 * 4];

 for (unsigned int x = 0; x < 40; x++)
	 for (unsigned int y = 0; y < 255; y++)
	 {
		 pixels[4 * (y * 40 + x) + 0] = y;
		 pixels[4 * (y * 40 + x) + 1] = y;
		 pixels[4 * (y * 40 + x) + 2] = y;
		 pixels[4 * (y * 40 + x) + 3] = 255;
	 }
 sf::Texture bar, texture;
 sf::Sprite sprite_bar, sprite;

 bar.create(40, 255); texture.create(800, 650);
 bar.update(pixels);
 sprite_bar.setTexture(bar); sprite.setTexture(texture);
 sprite_bar.setPosition(650, 15);
 chossen_y = 255 / 2;
 RGB_Draw(&window, &texture, &chossen_y,RGB_pix,CMY_pix,HSL_pix,HSV_pix,false);


 texture.update(window);
 //inicjalizacja 
 clock.restart().asMilliseconds();
 while (window.isOpen())
 {
	 window.clear(sf::Color::White);
	 


  while (window.pollEvent(event))
  {
    // zdarzenia
	  if (event.type == sf::Event::Closed) window.close();
	  //if (event.type == sf::Event::MouseMoved) std::cout << "d: " << event.mouseMove.x << " Y: " << event.mouseMove.y << "\n";
	  if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	  {
		  if (sf::Mouse::getPosition(window).x > 650 && sf::Mouse::getPosition(window).x < 690 && sf::Mouse::getPosition(window).y >= 15 && sf::Mouse::getPosition(window).y <= 270 && !draw_flag)
		  {
			  line[0].position = sf::Vector2f(635, sf::Mouse::getPosition(window).y);
			  line[1].position = sf::Vector2f(705, sf::Mouse::getPosition(window).y);
			  draw_flag = true;
			  texture.update(window);
		  }
	  }
	  if (event.type == event.MouseMoved && draw_flag)
	  {
		  if (sf::Mouse::getPosition(window).x > 650 && sf::Mouse::getPosition(window).x < 690 && sf::Mouse::getPosition(window).y >= 15 && sf::Mouse::getPosition(window).y <= 270)
		  {
			  line[0].position = sf::Vector2f(635, sf::Mouse::getPosition(window).y);
			  line[1].position = sf::Vector2f(705, sf::Mouse::getPosition(window).y);
			  texture.update(window);
			  chossen_y = sf::Mouse::getPosition(window).y - 15;
			 // RGB_Draw(&window, &texture, &chossen_y, RGB_pix, CMY_pix, HSL_pix, HSV_pix,true);
		  }
	  }
	  if (event.type == event.MouseButtonReleased && draw_flag)
	  {
		  if (sf::Mouse::getPosition(window).x > 650 && sf::Mouse::getPosition(window).x < 690 && sf::Mouse::getPosition(window).y >= 15 && sf::Mouse::getPosition(window).y <= 270)
		  {
			  line[0].position = sf::Vector2f(635, sf::Mouse::getPosition(window).y);
			  line[1].position = sf::Vector2f(705, sf::Mouse::getPosition(window).y);
			  draw_flag = false;
			  texture.update(window);
			  chossen_y = sf::Mouse::getPosition(window).y - 15;
			//  RGB_Draw(&window, &texture, &chossen_y, RGB_pix, CMY_pix, HSL_pix, HSV_pix,true);
		  }
	  }
  }
  
  RGB_Draw(&window, &texture, &chossen_y, RGB_pix, CMY_pix, HSL_pix, HSV_pix, true);

  L.setString("L = " + std::to_string(float(chossen_y/255))); 
  V.setString("V = " + std::to_string(float(chossen_y/255))); 
  Y.setString("Y = " + std::to_string(int(chossen_y/255 * 100)) + "%");
  B.setString("B = " + std::to_string(int(chossen_y)) );
  //tu wyrysować wszystko na ekran
  window.draw(sprite);
 
  window.draw(line);
  window.draw(text);
  window.draw(HSV);
  window.draw(HSL);
  window.draw(CMY);
  window.draw(RGB);
  window.draw(L);
  window.draw(V);
  window.draw(Y);
  window.draw(B);
  window.draw(sprite_bar);
  window.draw(rec_line);
 
  //tu wypisać na ekran wartość FPS
  if (clock.getElapsedTime().asSeconds() >= 1.0f)
  {
   FPS = (unsigned int)((float)frame_counter / clock.getElapsedTime().asSeconds());
   std::string frames = std::to_string(FPS);
   clock.restart();
   frame_counter = 0;
   text.setString(frames + " FPS");
   window.draw(text);
   

  }
  frame_counter++;
  
 
  window.display();
 }

 delete[] RGB_pix;
 delete[] CMY_pix;
 delete[] HSV_pix;
 delete[] HSL_pix;
}