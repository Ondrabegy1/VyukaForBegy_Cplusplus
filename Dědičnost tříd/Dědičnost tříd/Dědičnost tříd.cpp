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

class Rectangle :public Square
{
	public:
		Rectangle();
		Rectangle(int a, int b);
};

int main()
{

	Rectangle rec(5, 10);

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

Square::Square(int a)
{
	this->a = a;
	int obsah = a * a;
	int obvod = 4 * a;
	std::cout << "Obvod ctverce je: " << obvod << std::endl;
	std::cout << "Obsah ctverce je: " << obsah << std::endl;
}

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