#ifndef HEADER_H
#define HEADER_H
#include <vector>
#include <string>
using namespace std;
//class Coordinates {
//	int x, y, z;
//public:
//	Coordinates();
//	Coordinates(int x, int y, int z);
//	int get_x();
//	int get_y();
//	int get_z();
//    void set_x(int x);
//   void set_y(int y);
//	void set_z(int z);
//};
class Coordinates {
	bool x, y, z;
	int c1, c2, c3;
public:
	Coordinates();
	Coordinates(bool x, bool y, bool z, int c1, int c2, int c3);
	void set_plane(bool x, bool y, bool z);
	void set_coordinates(int c1, int c2, int c3);
	bool get_x();
	bool get_y();
	bool get_z();
	int get_c1();
	int get_c2();
	int get_c3();
	void display_coordinates();
};
class Shape {
protected:
	int type;
	string name;
	static double pi;
	Coordinates coordinates;

public:
	Shape();
	virtual void display() = 0;
	virtual string get_name() = 0;
	virtual int get_type() = 0;
	//virtual bool check();
	Coordinates get_coordinates();
		
	
};
class Shape2d: public Shape {
protected:
	double area;
	double perimeter;
public:
	Shape2d();
	virtual double calculate_perimeter() = 0;
	virtual double calculate_area() = 0;
	
	string get_name() {
		return this->name;
	 }
};
class Shape3d:public Shape {
protected:
	double surface_area;
	double volume;
public:
	Shape3d();
	virtual double calculate_surface_area() = 0;
	virtual double calculate_volume() = 0;
	
};
class Circle :public Shape2d {
protected:
	double radius;

public:
	Circle();
	Circle(string name,double radius,Coordinates coordinates);
	double calculate_area();
	double calculate_perimeter();
	void display();
	void set_radius(double radius);
	string get_name();
	double get_radius();
	int get_type();
	
};
class Rectangle : public Shape2d {
protected:
	double length, breadth;
public:
	Rectangle();
	Rectangle(string name,double length, double breadth, Coordinates coordinates);
	double calculate_perimeter();
	double calculate_area();
	void set_dimensions(double length,double breadth);
	double get_length();
	double get_breadth();
	string get_name();
	void display();
	int get_type();
	////Rectangle();
};
class Square : public Shape2d {
protected:
	double side;
public:
	Square();
	Square(string name,double side, Coordinates coordinates);
	double calculate_perimeter();
	double calculate_area();
	double get_side();
	void set_side(double side);
	void display();
	int get_type();
	////Square();
	
};
class Sphere :  public Shape3d
{
protected:
	Circle pcircle;
public:
	Sphere();
	Sphere(string name,double radius, Coordinates coordinates);
	double calculate_surface_area();
	double calculate_volume();
	double get_radius();
	string get_name();
	void display();
	int get_type();
	//Sphere();


};

class Cylinder : public Shape3d
{
protected:
	Circle ccircle;
	double height;
public:
	Cylinder();
	Cylinder(double radius,string name,double height, Coordinates coordinates);
	double calculate_surface_area();
	double calculate_volume();
	void display();
	void get_dimensions();
	string get_name();
	int get_type();
	//Cylinder();
};
class Cube : public Shape3d {
	Square sq;
public:
	Cube();
	Cube(string name,double side, Coordinates coordinates);
	double calculate_surface_area();
	double calculate_volume();
	void set_side(float side);
	double get_side();
	string get_name();
	void display();
	int get_type();
	//Cube();
};
class Cuboid : public Shape3d
{
protected:
	Rectangle rec;
	double height;
public:
	Cuboid();
	Cuboid(string name,double length, double breadth, double height, Coordinates coordinates);
	double calculate_surface_area();
	double calculate_volume();
	string get_name();
	void set_height(double height);
	double get_height();
	void display();
	int get_type();
	//Cuboid();

};

class Menu {
public:
	void printMenu();
	////Menu();
};
class Warehouse {
private:
	vector<Shape*>shapes;
	vector<Shape*>shapes2d;
	vector<Shape*>shapes3d;

public:
	void addShape();
	void searchShape();
	void updateShape();
	void deleteShape();
	void display2d_perimeter();
	void display3d_volume();
	void displayAll();
};
#endif // !HEADER_H

                                                                                                                                                                                                                             
                                                                                                                                                                                                                             
