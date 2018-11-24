#include "Draw.h"
#include <iostream>
#include <cmath>

void getCollor(unsigned int x,unsigned int y, sf::Color &color)
{
		if (y <= 30 && y >= 1)
		{
			if (x <= 255) color = sf::Color(x, 255, 0, 255);
			if (x > 255 && x <= 510) color = sf::Color(255, 510 - x, 0, 255);
			if (x > 510 && x < 766) color = sf::Color(255, 0, x-510, 255);
		}
		else if (y <= 60 && y > 30)
		{
			if (x <= 255) color = sf::Color(0, 255, x, 255);
			if (x > 255 && x <= 510) color = sf::Color(0, 510 - x, 255, 255);
			if (x > 510 && x < 766) color = sf::Color(x - 510, 0, 255, 255);
		}
}

void Draw_Line(float &start_x, float &start_y, sf::Event &event, sf::Color &start_color, sf::Color &end_color, std::vector<int>&bufor, int &bufor_size, bool &flag, std::vector<sf::VertexArray> &line, int &line_size, sf::RenderWindow &window)
{
	
	if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && flag == false)
	{
		if (event.mouseButton.y < 600 && event.mouseButton.y > 60)
		{
			line_size++;
			line.resize(line_size);
			line[line_size - 1] = sf::VertexArray(sf::LinesStrip, 2);
			start_x = event.mouseButton.x;
			start_y = event.mouseButton.y;
			bufor_size++;
			bufor.resize(bufor_size);
			bufor[bufor_size - 1] = 3;
			flag = true;
		}
		
	}
	else if (event.type == event.MouseMoved && flag == true )
	{
		if (event.mouseMove.y < 600 && event.mouseMove.y > 60)
		{
			line[line_size - 1][0].position = sf::Vector2f(start_x, start_y);
			line[line_size - 1][0].color = start_color;
			line[line_size - 1][1].position = sf::Vector2f(sf::Mouse::getPosition(window));
			line[line_size - 1][1].color = end_color;
		}
		
	}
	else if(event.type == event.MouseButtonReleased && flag == true)
	{
		if (event.mouseButton.y < 600 && event.mouseButton.y > 60)
		{
			line[line_size - 1][0].position = sf::Vector2f(start_x, start_y);
			line[line_size - 1][0].color = start_color;
			line[line_size - 1][1].position = sf::Vector2f(sf::Mouse::getPosition(window));
			line[line_size - 1][1].color = end_color;
			flag = false;
		}
	}
}

void Draw_Empty_Rec(float &start_x, float &start_y, sf::Event &event,const sf::Color &color,const sf::Color &fill, std::vector<int> &bufor, int &bufor_size, bool &flag, std::vector<sf::RectangleShape> &rec, int &rec_size)
{
	if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && flag == false)
	{
		if (event.mouseButton.y < 600 && event.mouseButton.y > 60)
		{
			start_x = event.mouseButton.x;
			start_y = event.mouseButton.y;
			rec_size++;
			rec.resize(rec_size);
			flag = true;
			bufor_size++;
			bufor.resize(bufor_size);
			bufor[bufor_size - 1] = 4;
		}
	}
	else if (event.type == event.MouseMoved && flag)
	{
		if (event.mouseMove.y < 600 && event.mouseMove.y > 60)
		{
			rec[rec_size - 1].setPosition(sf::Vector2f(start_x, start_y));
			rec[rec_size - 1].setSize(sf::Vector2f(event.mouseMove.x - start_x, event.mouseMove.y - start_y));
			rec[rec_size - 1].setFillColor(fill);
			rec[rec_size - 1].setOutlineThickness(1.0f);
			rec[rec_size - 1].setOutlineColor(color);
		}
	}
	else if (event.type == event.MouseButtonReleased && flag)
	{
		if (event.mouseButton.y < 600 && event.mouseButton.y > 60)
		{
			rec[rec_size - 1].setPosition(sf::Vector2f(start_x, start_y));
			rec[rec_size - 1].setSize(sf::Vector2f(event.mouseButton.x - start_x, event.mouseButton.y - start_y));
			rec[rec_size - 1].setFillColor(fill);
			rec[rec_size - 1].setOutlineThickness(1.0f);
			rec[rec_size - 1].setOutlineColor(color);
			flag = false;
		}
	}
}


void Draw_Circle(float &start_x, float &start_y, sf::Event &event, const sf::Color &color, const sf::Color &fill_color, std::vector<sf::CircleShape> &circle, int &circle_size, bool &flag, std::vector<int> &bufor, int &bufor_size)
{
	float radius;
	if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && flag == false)
	{
		if (event.mouseButton.y < 600 && event.mouseButton.y > 60)
		{
			start_x = event.mouseButton.x;
			start_y = event.mouseButton.y;
			circle_size++;
			circle.resize(circle_size);
			flag = true;
			bufor_size++;
			bufor.resize(bufor_size);
			bufor[bufor_size - 1] = 6;
		}
	}
	else if (event.type == event.MouseMoved && flag)
	{
		if (event.mouseMove.y < 600 && event.mouseMove.y > 60)
		{
			radius = sqrt(pow((event.mouseMove.x - start_x), 2) + pow((event.mouseMove.y - start_y), 2)) / 2;
			if (((event.mouseMove.y + start_y) / 2.0) - radius < 600 && ((event.mouseMove.y + start_y) / 2.0) - radius > 60)
			{
				circle[circle_size - 1].setPosition(((start_x + event.mouseMove.x) / 2.0) - radius, ((event.mouseMove.y + start_y) / 2.0) - radius);
				circle[circle_size - 1].setOutlineThickness(2.0);
				circle[circle_size - 1].setOutlineColor(color);
				circle[circle_size - 1].setFillColor(fill_color);
				circle[circle_size - 1].setRadius(radius);
			}
		}
	}
	else if (event.type == event.MouseButtonReleased && flag)
	{
		if (event.mouseMove.y < 600 && event.mouseMove.y > 60)
		{
			radius = sqrt(pow((event.mouseButton.x - start_x), 2) + pow((event.mouseButton.y - start_y), 2))/2;
			if (((event.mouseButton.y + start_y) / 2.0) - radius < 600 && ((event.mouseButton.y + start_y) / 2.0) - radius > 60)
			{
				circle[circle_size - 1].setPosition((start_x + event.mouseButton.x) / 2.0 - radius, (event.mouseButton.y + start_y) / 2.0 - radius);
				circle[circle_size - 1].setOutlineThickness(2.0);
				circle[circle_size - 1].setOutlineColor(color);
				circle[circle_size - 1].setFillColor(fill_color);
				circle[circle_size - 1].setRadius(radius);
				flag = false;
			}
		}
	}
}