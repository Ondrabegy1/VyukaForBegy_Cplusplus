//Příklad pro dědičnost tříd

#include <iostream>

class Shape
{
public:
	Shape();
};

Shape::Shape()
{
	std::cout << "Vykresluji obrazec" << std::endl;
}

class Square :public Shape
{
private:
		int a;
public:
	int getA() { return a; }
	Square();
	Square(int b);
};

Square::Square(int a)
{
	this->a = a;
	int obsah = a * a;
	int obvod = 4 * a;
	std::cout << "Obvod ctverce je: " << obvod << std::endl;
	std::cout << "Obsah ctverce je: " << obsah << std::endl;
	std::cout << "Strana A je: " << a << std::endl;
}

class Rectangle :public Square
{
	public:
		Rectangle();
		Rectangle(int a, int b);
};

Rectangle::Rectangle(int a, int b) :Square(a)
{
	int A = getA();
	int obsah = A * b;
	int obvod = 2 * (A + b);
	std::cout << "Obvod obdelniku je: " << obvod << std::endl;
	std::cout << "Obsah obdelniku je: " << obsah << std::endl;
	std::cout << "Strana A je: " << A << std::endl;
	std::cout << "Strana B je: " << b << std::endl;
}

class Circle :public Square
{
	public:
		Circle();
		Circle(int a);
};

Circle::Circle(int a) :Square(a)
{
	int r = getA();
	int obsah = 3.14 * (r * r);
	int obvod = 2 * 3.14 * r;
	std::cout << "Obvod kruhu je: " << obvod << std::endl;
	std::cout << "Obsah kruhu je: " << obsah << std::endl;
	std::cout << "Polomer je: " << r << std::endl;
}

class Cube :public Square
{
	public:
		Cube();
		Cube(int a);
};

Cube::Cube(int a) :Square(a)
{
	int A = getA();
	int obsah = 6 * (A * A);
	int objem = A * A * A;
	std::cout << "Objem krychle je: " << objem << std::endl;
	std::cout << "Obsah krychle je: " << obsah << std::endl;
	std::cout << "Strana A je: " << A << std::endl;
}

class Cuboid :public Square
{
	public:
		Cuboid();
		Cuboid(int a, int b, int c);
};

Cuboid::Cuboid(int a, int b, int c) :Square(a)
{
	int A = getA();
	int obsah = 2 * (A * b + A * c + b * c);
	int objem = A * b * c;
	std::cout << "Objem kvadru je: " << objem << std::endl;
	std::cout << "Obsah kvadru je: " << obsah << std::endl;
	std::cout << "Strana A je: " << A << std::endl;
	std::cout << "Strana B je: " << b << std::endl;
	std::cout << "Strana C je: " << c << std::endl;
}

class Sphere :public Square
{
	public:
		Sphere();
		Sphere(int a);
};

Sphere::Sphere(int a) :Square(a)
{
	int r = getA();
	int obsah = 4 * 3.14 * (r * r);
	int objem = (4 / 3) * 3.14 * (r * r * r);
	std::cout << "Objem koule je: " << objem << std::endl;
	std::cout << "Obsah koule je: " << obsah << std::endl;
	std::cout << "Polomer je: " << r << std::endl;
}

class Cylinder :public Square
{
	public:
		Cylinder();
		Cylinder(int a, int b);
};

Cylinder::Cylinder(int a, int b) :Square(a)
{
	int r = getA();
	int obsah = 2 * 3.14 * r * (r + b);
	int objem = 3.14 * (r * r) * b;
	std::cout << "Objem valce je: " << objem << std::endl;
	std::cout << "Obsah valce je: " << obsah << std::endl;
	std::cout << "Polomer je: " << r << std::endl;
	std::cout << "Vyska je: " << b << std::endl;
}

int main()
{

	Rectangle rec(5, 10);

	std::cout << std::endl;

	Circle cir(5);

	std::cout << std::endl;

	Cylinder cyl(5, 10);

	return 0;
}
/*
Square::Square():Shape()
{
	std::cout<<"Vytvarime ctverec"<<std::endl;
}

Square::Square(int a)
{
	this->a = a;
	std::cout << "Vytvarime ctverec" << std::endl;
}

Rectangle::Rectangle()
{
	std::cout << "Vytvarime obdelnik" << std::endl;
}

Rectangle::Rectangle(int a, int b) :Square(a)
{
	std::cout << "Vytvarime obdelnik" << std::endl;
}*/
