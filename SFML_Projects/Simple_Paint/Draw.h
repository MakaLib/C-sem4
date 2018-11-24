#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

void getCollor(unsigned int x,unsigned int y, sf::Color &color);
void Draw_Line(float &start_x, float &start_y, sf::Event &event, sf::Color &start_color, sf::Color &end_color, std::vector<int>&bufor, int &bufor_size, bool &flag, std::vector<sf::VertexArray> &line, int &line_size, sf::RenderWindow &window);
void Draw_Empty_Rec(float &start_x, float &start_y, sf::Event &event,const sf::Color &color,const sf::Color &fill, std::vector<int> &bufor, int &bufor_size, bool &flag, std::vector<sf::RectangleShape> &rec, int &rec_size);
void Draw_Circle(float &start_x, float &start_y, sf::Event &event, const sf::Color &color, const sf::Color &fill_color, std::vector<sf::CircleShape> &circle, int &circle_size, bool &flag, std::vector<int> &bufor, int &bufor_size);