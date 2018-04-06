/* Task: Transofrmations 
 * Plik wykonywalny: atest 
 * 
 * Opis: Celem zadania jest napisać system klas który mógłby być
 * wykorzystany w programach graficznych.
 * 
 * Dwie klasy są już podane: Transformable (abstrakcyjna klasa 
 * odpowiadająca za transformacje figur) oraz Point. Proszę zwrócić 
 * uwagę na zależność pomiędzy tymi klasami. 
 * 
 * Po klasie Transformable dziedziczy klasa Figure, będąca kontenerem
 * na obiekty klasy Point, po której dziedziczą wszystkie pozostałe 
 * figury. Figury dwuwymiarowe dziedziczą dodatkowo po interfejsie Area,
 * który odpowiada za obliczanie pola powierzchni. Area nie może 
 * dziedziczyć po klasie Figure.
 * 
 * Pole powierzchni trojkata o wierzcholkach A,B,C:
 *     A = 0.5 * | (Ax - Cx)(By - Ay) - (Ax - Bx)(Cy - Ay) |
 * 
 * W celach edukacyjnych należy unikać używania kontenerów biblioteki
 * standardowej. Użycie std::vector jest dopuszczalne, ale obniża ocenę
 * z zadania o 1pkt za kod.  
 * 
 * Stała PI została zdefiniowana w klasie Transformable, skąd powinna
 * być dostępna do wszystkich potrzebnych zastosowań.
 * 
 */ 

#include "Transformable.h"
#include "Point.h"
#include "Figure.h"
#include "Triangle.h"
#include "Circle.h"

#include <iostream>

using namespace std;

void print(const Figure * fig){
	fig->print();
	cout << "Length = " << fig->length() << endl;
		
	const Area * area = dynamic_cast<const Area*>(fig);
	if( area ){
		cout << "Area = " << area->area() << endl;
	} else {
		cout << "The figure do not have area" << endl;
	}
}

int main()
{ 
	cout << "\n ======== POINTS ======== " << endl;
	Point A;
	cout << "Origin A" << A << endl;
	
	A.setCoordinates(1.5, 2);
	cout << "Point A" << A << endl;
	
	A.move(1, 2);
	cout << "A moved by [1, 2] => A" << A << endl;
	
	A.scale(Point(1, 1), 2);
	cout << "A scaled by 2.0 around (1, 2) => A" << A << endl;	
	
	A.rotate(Point(), Transformable::PI);
	cout << "A rotated around (0,0) => A" << A << endl;	



	cout << "\n ======== SEGMENT ======== " << endl;
	Figure segment(2);
	
	segment.print();
	cout << "Segment length = " << segment.length() << endl;
	
	segment.setPoint(1, 1.0, 1.0);
	cout << "Segment length = " << segment.length() << endl;
		
		
		
	cout << "\n ======== TRIANGLE ======== " << endl;
	Triangle triangle(Point(0.0), Point(2,0), Point(0,5));

	Triangle * rotatetTriangle = new Triangle(triangle);
	rotatetTriangle->rotate(Point(), Transformable::PI);

	triangle.print();
	rotatetTriangle->print();
	
	
	
	cout << "\n ======== FIGURES ======== " << endl;
	Figure * circle = new Circle(Point(0.0), 5);
	
	Figure * table[] = {&segment, &triangle, circle};
	for ( unsigned int idx = 0; idx < sizeof(table)/sizeof(Figure*); ++idx ) {
		cout << " ** Base ** " << endl;
		print(table[idx]);
		
		cout << " ** Rotate around origin by 0.5PI** " << endl;
		table[idx]->rotate(Point(), 0.5*Transformable::PI);
		print(table[idx]);
		
		cout << " ** Scale by 2.0 around origin** " << endl;
		table[idx]->scale(Point(), 2);
		print(table[idx]);
		
		cout << " ** Move by [2, 1] ** " << endl;
		table[idx]->move(2, 1);
		print(table[idx]);
		
		cout << "\n +++++++++++++++++++++++++ " << endl;
	}
	
	
	delete circle;
	delete rotatetTriangle;
}

/* Output: 

 ======== POINTS ======== 
Origin A(0, 0)
Point A(1.5, 2)
A moved by [1, 2] => A(2.5, 4)
A scaled by 2.0 around (1, 2) => A(4, 7)
A rotated around (0,0) => A(-4, -7)

 ======== SEGMENT ======== 
Figure : [(0, 0),(0, 0)]
Segment length = 0
Segment length = 1.41421

 ======== TRIANGLE ======== 
Triangle : [(0, 0),(2, 0),(0, 5)]
Triangle : [(0, 0),(-2, 0),(0, -5)]

 ======== FIGURES ======== 
 ** Base ** 
Figure : [(0, 0),(1, 1)]
Length = 1.41421
The figure do not have area
 ** Rotate around origin by 0.5PI** 
Figure : [(0, 0),(-1, 1)]
Length = 1.41421
The figure do not have area
 ** Scale by 2.0 around origin** 
Figure : [(0, 0),(-2, 2)]
Length = 2.82843
The figure do not have area
 ** Move by [2, 1] ** 
Figure : [(2, 1),(2.22045e-16, 3)]
Length = 2.82843
The figure do not have area

 +++++++++++++++++++++++++ 
 ** Base ** 
Triangle : [(0, 0),(2, 0),(0, 5)]
Length = 7.38516
Area = 5
 ** Rotate around origin by 0.5PI** 
Triangle : [(0, 0),(0, 2),(-5, 0)]
Length = 7.38516
Area = 5
 ** Scale by 2.0 around origin** 
Triangle : [(0, 0),(0, 4),(-10, 0)]
Length = 14.7703
Area = 20
 ** Move by [2, 1] ** 
Triangle : [(2, 1),(2, 5),(-8, 1)]
Length = 14.7703
Area = 20

 +++++++++++++++++++++++++ 
 ** Base ** 
Circle : O(0, 0), radius = 5
Length = 31.4159
Area = 78.5398
 ** Rotate around origin by 0.5PI** 
Circle : O(0, 0), radius = 5
Length = 31.4159
Area = 78.5398
 ** Scale by 2.0 around origin** 
Circle : O(0, 0), radius = 10
Length = 62.8319
Area = 314.159
 ** Move by [2, 1] ** 
Circle : O(2, 1), radius = 10
Length = 62.8319
Area = 314.159

 +++++++++++++++++++++++++ 
*/ 
