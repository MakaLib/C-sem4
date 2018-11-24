#include "MapPoint.h"
#include <cmath>

int MapPoint::next_free_id = 1;

void MapPoint::set_latitude(const double x)
{
	first = x;
}

void MapPoint::set_longitude(const double y)
{
	second = y;

}

void MapPoint::assign_id()
{
	ID = next_free_id;
	next_free_id++;
}

void MapPoint::print()
{
	//Point with ID=1 : (19.9383, 50.0614)
	std::cout<<"Point with ID="<<ID<<" : ("<<first<<", "<<second<<")\n";
}
void MapPoint::set_coordinates (const double x, const double y)
{
	first = x;
	second = y;
}

MapPoint MapPoint::closest(MapPoint a, MapPoint b)
{
	double range1,range2;
	range1 = sqrt(pow((first - a.first),2) + pow((second - a.second),2));
	range2 = sqrt(pow((first - b.first),2) + pow((second - b.second),2));
	if(range1 > range2) return b;
	else return a;
}

MapDistance MapPoint::distance(MapPoint a)
{
	MapDistance wsk;

	wsk.distance_y = sqrt(pow(first - a.first,2));
	wsk.distance_x = sqrt(pow(second - a.second,2));
	return wsk;
}