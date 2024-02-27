#ifndef SOURCE_CPP
#define SOURCE_CPP
#include <iostream>
#include "Header.h"
#include <algorithm>
using namespace std;
double Shape::pi = 3.14;
Coordinates::Coordinates() {

}
Coordinates::Coordinates(bool x, bool y, bool z, int c1, int c2, int c3)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->c1 = c1;
	this->c2 = c2;
	this->c3 = c3;
}
void Coordinates::set_plane(bool x, bool y, bool z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
void Coordinates::set_coordinates(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
bool Coordinates::get_x()
{
	return x;
}
bool Coordinates::get_y()
{
	return y;
}
bool Coordinates::get_z()
{
	return z;
}
int Coordinates::get_c1()
{
	return c1;
}
int Coordinates::get_c2()
{
	return c2;
}
int Coordinates::get_c3()
{
	return c3;
}
void Coordinates::display_coordinates()
{
	if (get_x() == 0)
	{
		cout << "the shape lies in yz plane" << endl;
	}
	else if (get_y() == 0)
	{
		cout << "the shape lies in xz plane" << endl;
	}
	else if (get_z() == 0)
	{
		cout << "the shape lies in the xy plane" << endl;
	}
	else {
		cout << "the shape lies in the xyz plane" << endl;
	}
	cout << "the coordinates of the centroid of the shape is:" << "c1= " << get_c1() << " c2=" << get_c2() << " c3=" << get_c3() << endl;
}
Shape::Shape()
{
	name = "";
}
Coordinates Shape::get_coordinates()
{
	return coordinates;
}
Shape2d::Shape2d() {
	perimeter = 0;
	area = 0;
}
Shape3d::Shape3d()
{
	surface_area = 0;
	volume = 0;
}
//2d shape classes
Circle::Circle()
{
	//name = "";
	radius = 0;
}
Circle::Circle(string name,double radius,  Coordinates coordinates)
{
	this->type = 1;
	this->name = name;
	this->radius = radius;
	this->coordinates = coordinates;
}
double Circle::calculate_area()
{
	area = pi * get_radius() * get_radius();
	return area;
}
double Circle::calculate_perimeter()
{
	perimeter = 2 * pi * radius;
	return perimeter;
}
string Circle::get_name()
{
	return name;
}
double::Circle::get_radius()
{
	return radius;
}
void Circle::display() {
	cout << "shape: circle" << endl;
	cout << "name:" << get_name() << endl;
	cout << "radius= " << get_radius() << endl;
	cout << "perimeter= " << calculate_perimeter() << endl;
	cout << "area= " << calculate_area() << endl;
	get_coordinates().display_coordinates();

}
void Circle::set_radius(double radius)
{
	this->radius = radius;
}
int Circle::get_type()
{
	return type;
}

Rectangle::Rectangle()
{
	name = "";
	length = 0;
	breadth = 0;
}
Rectangle::Rectangle(string name,double length, double breadth, Coordinates coordinates)
{
	this->type = 1;
	this->name = name;
	this->length = length;
	this->breadth = breadth;
	this->coordinates = coordinates;
}
double Rectangle::calculate_area()
{
	area = length * breadth;
	return area;
}
double Rectangle::calculate_perimeter()
{
	perimeter = 2 * (length + breadth);
	return perimeter;
}
string Rectangle:: get_name()
{
	return name;
}
void Rectangle::set_dimensions(double length, double breadth)
{
	this->length = length;
	this->breadth = breadth;
}
double  Rectangle::get_length()
{
	return length;
}
double  Rectangle::get_breadth()
{
	return breadth;
}
void Rectangle::display()
{
	cout << "shape: rectangle" << endl;
	cout << "name:" << get_name()<<endl;
	cout << "length= " << get_length() << " breadth= " << get_breadth() << endl;
	cout << "perimeter= " << calculate_perimeter() << endl;
	cout << "area= " << calculate_area() << endl;
	get_coordinates().display_coordinates();
}
int Rectangle::get_type()
{
	return type;
}
Square::Square()
{
	name = "";
	side = 0;
}
Square::Square(string name, double side,  Coordinates coordinates)
{
	this->type = 1;
	this->name = name;
	this->side = side;
	this->coordinates = coordinates;
}
double Square::calculate_area()
{
	area = side * side;
	return area;
}
double Square::calculate_perimeter()
{
	perimeter = 4 * side;
	return perimeter;
}
double Square::get_side()
{
	return side;
}
void Square::set_side(double side)
{
	this->side = side;
}
void Square::display()
{
	cout << "shape: square" << endl;
	cout << "name:" << get_name() << endl;
	cout << "side= " << get_side() << endl;
	cout << "perimeter= " << calculate_perimeter() << endl;
	cout << "area= " << calculate_area() << endl;
	get_coordinates().display_coordinates();
}
int Square::get_type()
{
	return type;
}
//void Square::set_side(float side)
//{
//	this->side = side;
//}
//2d shapes ended
//3d shapes started
Sphere::Sphere()
{
}
Sphere::Sphere(string name, double radius, Coordinates coordinates)  {
	this->type = 2;
	pcircle.set_radius(radius);
	this->name = name;
	this->coordinates = coordinates;
}
double Sphere::calculate_surface_area()
{
	this->type = 2;
	surface_area = 4 * pi * pcircle.get_radius() * pcircle.get_radius();
	return surface_area;
}
double Sphere::calculate_volume()
{
	volume = 4 * pi * pcircle.get_radius() * pcircle.get_radius() *  pcircle.get_radius() / 3;
	return volume;
}
double Sphere::get_radius()
{
	return  pcircle.get_radius();
}

void Sphere::display()
{
	cout << "shape: sphere" << endl;
	cout << "name:" << get_name() << endl;
	cout << "radius= " << pcircle.get_radius() << endl;
	cout << "surafce area= " << calculate_surface_area() << endl;
	cout << "volume= " << calculate_volume() << endl;
	get_coordinates().display_coordinates();
}
string	Sphere::get_name()
{
	return name;
}
int Sphere::get_type()
{
	return type;
}
Cylinder::Cylinder()  {
	height = 0;
}
Cylinder::Cylinder(double radius, string name, double height, Coordinates coordinates)
{
	this->type = 2;
	ccircle.set_radius(radius);
	this->name = name;
	this->height = height;
	this->coordinates = coordinates;
}
double Cylinder :: calculate_surface_area()
{
	surface_area = 2 * pi * ccircle.get_radius() * height;
	return surface_area;
}
double Cylinder::calculate_volume()
{
	volume = pi * ccircle.get_radius() * ccircle.get_radius() * height;
	return volume;
}
void Cylinder::get_dimensions()
{
	cout << "radius=" << ccircle.get_radius() << " " << "height= " << height << endl;
}
void Cylinder::display()
{
	cout << "shape:Cylinder" << endl;
	cout << "name:" << get_name() << endl;
	get_dimensions();
	cout << "surafce area= " << calculate_surface_area() << endl;
	cout << "volume= " << calculate_volume() << endl;
	get_coordinates().display_coordinates();
}
string Cylinder::get_name(){
	return name;
}
int Cylinder::get_type()
{
	return type;
}
Cube::Cube() {

}
Cube::Cube(string name, double side, Coordinates coordinates)  {
	this->type = 2;
	sq.set_side(side);
	this->name = name;
	this->coordinates = coordinates;

}
double Cube::get_side()
{
	return sq.get_side();
}
double Cube::calculate_surface_area()
{
	surface_area = 6 * sq.get_side() * sq.get_side();
	return surface_area;
}
double Cube::calculate_volume()
{
	volume = sq.get_side() * sq.get_side() * sq.get_side();
	return volume;
}
void Cube::display()
{
	cout << "shape: cube" << endl;
	cout << "name:" << get_name() << endl;;
	cout << "side= " << sq.get_side() << endl;
	cout << "surface_area= " << calculate_surface_area() << endl;
	cout << "volume= " << calculate_volume() << endl;
	get_coordinates().display_coordinates();
}
string Cube::get_name() {
	return name;
}
	int Cube::get_type()
	{
		return type;
	}
Cuboid::Cuboid() {
	height = 0;
}
Cuboid::Cuboid(string name, double length, double breadth, double height, Coordinates coordinates)  {
	this->type = 2;
	rec.set_dimensions(length, breadth);
	this->height = height;
	this->name = name;
	this->coordinates = coordinates;
}
double Cuboid::calculate_surface_area()
{
	surface_area = 2 * ((rec.get_length() * rec.get_breadth()) + (rec.get_breadth() * height) + (height * rec.get_length()));
		return surface_area;
}
double Cuboid::calculate_volume()
{
	volume = rec.get_breadth() * rec.get_breadth() * height;
	return volume;
}

void Cuboid::display()
{
	cout << "shape: cuboid" << endl;
	cout << "name:" << get_name() << endl;;
	cout << "length=" << rec.get_length() << " breadth= " << rec.get_breadth() << " height= " << height << endl;
	cout << "surafce area= " << calculate_surface_area() << endl;
	cout << "volume= " << calculate_volume() << endl;
	get_coordinates().display_coordinates();

}
double Cuboid::get_height()
{
	return height;
}
void Cuboid::set_height(double height)
{
	this->height = height;
}
string Cuboid::get_name()
{
	return name;
}
int Cuboid::get_type()
{
	return type;
}
//3d shapes ended


//menu
void Menu::printMenu()
{
	cout << "1.ADD THE SHAPE" << endl;
	cout << "2.SEARCH THE SHAPE" << endl;
	cout << "3.UPDATE THE SHAPE" << endl;
	cout << "4.DELETE THE SHAPE" << endl;
	cout << "5.DISPLAY ALL" << endl;
	cout << "6.DISPLAY 2D SHAPES" << endl;
	cout << "7.DISPLAY 3D SHAPES" << endl;
	cout << "HOW YOU WANT TO PROCEED" << endl;
}
//warehouse
void Warehouse::addShape()
{
	string shape;
	string shape_name;
	cout << "Enter the name of your shape" << endl;
	cin >> shape;
	cout << "Enter the name you want to give to your shape" << endl;
	cin >> shape_name;
	for (int i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->get_name() == shape_name)
		{
			cout << "The shape name already exist" << endl;
			return;
		}
	}
	bool x, y, z;
	int c1, c2, c3;
	cout << "Enter the palne you want the shape to be in" << endl;
	cout << "plane:x,y,z" << endl;
	cin >> x >> y >> z;
	cout << "Enter the coordinates of the centre" << endl;
	cin >> c1 >> c2 >> c3;
	Coordinates c (x, y, z, c1, c2, c3);
	if (shape == "circle")
	{
		if (c.get_x() * c.get_y() * c.get_z() != 0||(c.get_x()==0&&c.get_c1()!=0)|| (c.get_y() == 0 && c.get_c2() != 0) || (c.get_z() == 0 && c.get_c3() != 0))
		{
			cout << "the shape cannot lie in this plane" << endl;
			return;
		}
		double r;
		cout << "Enter the radius for you circle" << endl;
		cin >> r;
		Shape* s = new Circle(shape_name,r,c);
		shapes.push_back(s);
		if (s->get_type() == 1)
		{
			shapes2d.push_back(s);
		}
		else {
			shapes3d.push_back(s);
		}
	}
	else if (shape == "rectangle")
	{
		/*if (x * y * z != 0)
		{
			cout << "this shape is not possible" << endl;
			return;
		}*/
		if (c.get_x() * c.get_y() * c.get_z() != 0 ||(c.get_x() == 0 && c.get_c1() != 0) || (c.get_y() == 0 && c.get_c2() != 0) || (c.get_z() == 0 && c.get_c3() != 0))
		{
			cout << "the shape cannot lie in this plane" << endl;
			return;
		}
		double length, breadth;
		cout << "Enter the length and breadth of the rectangle" << endl;
		cout << "length= " << endl;
		cin >> length;
		cout << "breadth= " << endl;
		cin >> breadth;
		Shape* s = new Rectangle(shape_name, length, breadth,c);
		shapes.push_back(s);
		if (s->get_type() == 1)
		{
			shapes2d.push_back(s);
		}
		else {
			shapes3d.push_back(s);
		}
	}
	else if (shape == "square")
	{
		/*if (x * y * z != 0)
		{
			cout << "this shape is not possible" << endl;
			return;
		}*/
		if (c.get_x() * c.get_y() * c.get_z() != 0 || (c.get_x() == 0 && c.get_c1() != 0) || (c.get_y() == 0 && c.get_c2() != 0) || (c.get_z() == 0 && c.get_c3() != 0))
		{
			cout << "the shape cannot lie in this plane" << endl;
			return;
		}
		double side;
		cout << "Enter the side of the square" << endl;
		cout << "side= " << endl;
		cin >> side;
		Shape* s = new Square(shape_name, side,c);
		shapes.push_back(s);
		if (s->get_type() == 1)
		{
			shapes2d.push_back(s);
		}
		else {
			shapes3d.push_back(s);
		}
	}
	else if (shape == "sphere")
	{
		/*if (x == 0 || y == 0 || z == 0)
		{
			cout << "this shape is not possible" << endl;
			return;
		}*/
		if (c.get_x() * c.get_y() * c.get_z()==0)
		{
			cout << "the shape is invalid" << endl;
			return;
		}
		double radius;
		cout << "Enter the radius of the sphere" << endl;
		cout << "radius= " << endl;
		cin >> radius;
		Shape* s = new Sphere(shape_name, radius,c);
		shapes.push_back(s);
		if (s->get_type() == 1)
		{
			shapes2d.push_back(s);
		}
		else {
			shapes3d.push_back(s);
		}
	}
	else if (shape == "cylinder")
	{

		/*if (x == 0 || y == 0 || z == 0)
		{
			cout << "this shape is not possible" << endl;
			return;
		}*/
		if (c.get_x() * c.get_y() * c.get_z()==0)
		{
			cout << "the shape is invalid" << endl;
			return;
		}
		double radius, height;
		cout << "Enter the radius and height of the cylinder" << endl;
		cout << "radius= " << endl;
		cin >> radius;
		cout << "height= " << endl;
		cin >> height;
		Shape* s = new Cylinder(radius, shape_name, height,c);
		shapes.push_back(s);
		if (s->get_type() == 1)
		{
			shapes2d.push_back(s);
		}
		else {
			shapes3d.push_back(s);
		}

	}
	else if (shape == "cube")
	{

		/*if (x == 0 || y == 0 || z == 0)
		{
			cout << "this shape is not possible" << endl;
			return;
		}*/
		if (c.get_x() * c.get_y() * c.get_z()==0)
		{
			cout << "the shape is invalid" << endl;
			return;
		}
		double side;
		cout << "enter the side of the cube" << endl;
		cin >> side;
		Shape* s = new Cube(shape_name, side,c);
		shapes.push_back(s);
		if (s->get_type() == 1)
		{
			shapes2d.push_back(s);
		}
		else {
			shapes3d.push_back(s);
		}
	}
	else if (shape == "cuboid")
	{

		/*if (x == 0 || y == 0 || z == 0)
		{
			cout << "this shape is not possible" << endl;
			return;
		}*/
		if (c.get_x() * c.get_y() * c.get_z()==0)
		{
			cout << "the shape is invalid" << endl;
			return;
		}
		double length, breadth, height;
		cout << "enter the dimensions" << endl;
		cout << "length" << endl;
		cin >> length;
		cout << "breadth" << endl;
		cin >> breadth;
		cout << "height" << endl;
		cin >> height;
		Shape* s = new Cuboid(shape_name, length, breadth, height,c);
		shapes.push_back(s);
		if (s->get_type() == 1)
		{
			shapes2d.push_back(s);
		}
		else {
			shapes3d.push_back(s);
		}
	}
	else {
		cout << "INVALID" << endl;
	}
}
void Warehouse::searchShape()
{
	string search_name;
	cout << "Enter the name of your shape you want to search." << endl;
	cin >> search_name;
	bool flag = false;
	for (int i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->get_name() == search_name)
		{
			cout << "The shape is present" << endl;
			shapes[i]->display();
			flag = true;
			break;
		}
		
	}
	if (flag == false)
	{
		cout << "the shape is not present and invalid" << endl;
	}
}
void Warehouse::updateShape()
{
	string shape;
	string updateShapeName;
	Coordinates c;
	cout << "Enter the name shape you want to update" << endl;
	cin >> shape;
	cout << "enter the name of your shape" << endl;
	cin >> updateShapeName;
	bool x, y, z;
	int c1, c2, c3;
	cout << "enter the plane coordinates" << endl;
	cin >> x >> y >> z;
	cout << "enter the center coordinates" << endl;
	cin >> c1 >> c2 >> c3;



	bool flag = false;
	for (int i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->get_name() == updateShapeName)
		{
			shapes.erase(shapes.begin() + i);
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "NO SUCH SHAPE IS PRESENT" << endl;
		return;
	}
	if (shape == "circle")
	{
		double r;
		cout << "Enter the radius for you circle" << endl;
		cin >> r;
		Shape* s = new Circle(updateShapeName, r,c);
		shapes.push_back(s);
	}
	else if (shape == "rectangle")
	{
		double length, breadth;
		cout << "Enter the length and breadth of the rectangle" << endl;
		cout << "length= " << endl;
		cin >> length;
		cout << "breadth= " << endl;
		cin >> breadth;
		Shape* s = new Rectangle(updateShapeName, length, breadth,c);
		shapes.push_back(s);
	}
	else if (shape == "square")
	{
		double side;
		cout << "Enter the side of the square" << endl;
		cout << "side= " << endl;
		cin >> side;

		Shape* s = new Square(updateShapeName, side,c);
		shapes.push_back(s);
	}
	else if (shape == "sphere")
	{
		double radius;
		cout << "Enter the radius of the sphere" << endl;
		cout << "radius= " << endl;
		cin >> radius;
		Shape* s = new Sphere(updateShapeName, radius,c);
		shapes.push_back(s);
	}
	else if (shape == "cylinder")
	{
		double radius, height;
		cout << "Enter the radius and height of the cylinder" << endl;
		cout << "radius= " << endl;
		cin >> radius;
		cout << "height= " << endl;
		cin >> height;
		Shape* s = new Cylinder(radius, updateShapeName, height,c);
		shapes.push_back(s);

	}
	else if (shape == "cube")
	{
		double side;
		cout << "enter the side you want to update" << endl;
		cin >> side;
		Shape* s = new Cube(updateShapeName, side,c);
		shapes.push_back(s);
	}
	else if (shape == "cuboid")
	{
		double length, breadth, height;
		cout << "length" << endl;
		cin >> length;
		cout << "breadth" << endl;
		cin >> breadth;
		cout << "height" << endl;
		cin >> height;
		Shape* s = new Cuboid(updateShapeName, length, breadth, height,c);
		shapes.push_back(s);
	}
	
	else {
		cout << "INVALID" << endl;
	}
}
void Warehouse::deleteShape()
{
	string deleteShapeName;
	cout << "Enter the name of the shape you want to delete " << endl;
	cin >> deleteShapeName;
	bool flag = false;
	for (int i = 0; i < shapes.size(); i++)
	{
		if (shapes[i]->get_name() == deleteShapeName)
		{
			shapes.erase(shapes.begin() + i);
			flag = true;
			break;
		}
	}
		
	if (flag == false)
	{
		cout << "THERE IS NO SUCH SHAPE NAME" << endl;
	}
}
//void Warehouse::display2d()
//{

//}
void Warehouse::displayAll()
{
	if (shapes.empty())
	{
		cout << "NO SHAPES PRESENT" << endl;
		return;
	}
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->display();
		cout << endl;
	}

}
//bool comp(const Shape* a, const Shape* b)
//{
//	// Compare on basis of roll number
//	if () {
//		return true;
//	}
//	return false;
//}
void Warehouse::display2d_perimeter() {
	sort(shapes2d.begin(), shapes2d.end());
	for (int i = 0; i < shapes2d.size(); i++)
	{
		shapes2d[i]->display();
	}
}
void Warehouse::display3d_volume() {
	sort(shapes3d.begin(), shapes3d.end());
	for (int i = 0; i < shapes3d.size(); i++)
	{
		shapes3d[i]->display();
	}
}


#endif // !SOURCE_CPP
