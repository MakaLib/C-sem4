#ifndef MAP_DISTANCE_H
#define MAP_DISTANCE_H
#include <iostream>

class MapDistance
{
	friend class MapPoint;
public:
	void print();
	~MapDistance();

private:
	double distance_x;
	double distance_y;

};

#endif