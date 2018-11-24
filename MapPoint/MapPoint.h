#ifndef MAP_POINT_H
#define MAP_POINT_H
#include"MapDistance.h"


class MapPoint
{
public:
	static int next_free_id;

	void set_latitude(const double);
	void set_longitude(const double);
	void assign_id();
	void print();
	void set_coordinates (const double, const double);
	MapPoint closest(MapPoint, MapPoint);
	MapDistance distance(MapPoint);

private:
	double first;
	double second;
	int ID;

};

#endif