
#define _USE_MATH_DEFINES
#include<iostream>

//#include"Matrix.h"
#include"SList.h"
//#include"doublelist.h"
//#include"Ship.h"
//#include"CruiseShip.h"
//#include"BinTree.h"
#include"Person.h"
#include"SportMan.h"
#include<ctime>
#include"PriorityQueue.h"











using namespace std;




class Circle {
private:
	double radius = 10;

public:

    Circle() = default;

	Circle(double radius) {
		setRadius(radius); 
	}


	double getRadius() {
		return radius;
	}
	void setRadius(const double&radius) {
		if (radius >= 0) {
			this->radius = radius;
		}
	}
	void print() {
		cout << "rad >> " << radius << endl;
		cout <<"area >>"<< area() << endl;
		cout << "length >>" << length() << endl;
	}

	double area() {
		
		 return  M_PI * radius*radius;

	}
	double length() {
		return 2 * M_PI*radius;
	}

};


class Square {

private:
	double side = 20;
public:
	Square() = default;
	Square(double side) {
		setSide(side);
	}
	double getSide() {
		return side;
	}
	void setSide(const double&side) {
		if (side >= 0) {
			this->side = side;
		}
	}

	void print() {
		cout << "side >> " << side << endl;
		cout << "plosch >>" << plosh() << endl;
		cout << "perimetr" << perimetr() << endl;
	}
	double plosh() {
		return side*side;
	}
	double perimetr() {
		return 2*(side+side);
	}

};

class CircleInSquare :public Circle , public Square
{
public:



	CircleInSquare() : Square(),Circle() {}
	CircleInSquare(double side) :Square(side) {
		Circle::setRadius(side / 2);
	}


	CircleInSquare(const Circle&a) :Circle(a) {
		Square::setSide(Circle::getRadius() * 2);
	}
	CircleInSquare(const Square&a) :Square(a) {
	Circle::setRadius(Square::getSide() / 2);
	}
	

	double plosch() {
		return plosh() - area();
	}
	double dovz() {
		return length() + perimetr();
	}
	void print() {
		Circle::print();
		cout << endl;
		Square::print();
		//cout << "zagalna dovzhuna >>"<<dovz() << endl;
		// << "plosch chast >>" << plosch() << endl;
	}
	void setSide(double side) {
		Square::setSide(side);
		Circle::setRadius(Square::getSide() / 2);
	}
	void setRadius(double radius) {
		Circle::setRadius(radius);
		Square::setSide(Circle::getRadius() * 2);
	}

};


int main() {

	






	/*Person person("vadim", 20);
	person.print();
	SportMan sportman("vadim", 20, "box");
	sportman.achivement.push_back("chempion country ");
	sportman.achivement.push_back("chempion world");
	sportman.print();
	SportMan sp("valeryii", 18, "tennis");
	sp.achivement.push_back("olimpic champion");
	sp.achivement.push_back("winner cup island");
	sp.print();*/
	
 
    
	

	/*��������� ����� ����(�����) �� �������(�������).����� ������ ������  ������ ���������� ���� �����(square()) �� ������ �����(length(), ������� ���� ��� ����, �������� �������� ��� ����� �������), ������ ������� �� ����(getters, setters).

		��������������  �������� ������������.��������� ���� ����_�������_�_������� �� �������_�_����(�� ����), ����  ����� �� ������



		����������� �� ������������� ������� ������ � �����  ������, �� ����� 1
		�����������  � ����������(���������� ������� ��������(��� �����), �����(������� ��������) ���� �������������� �����������  �� �����)
		����������� ������������ �������� � ����������     ������(CircleInSquare(const Square &))
		����������� ������������ ���� � ����������     ������(CircleInSquare(const Circle &))
		����������  �������� ������� ������(����� ������� ���� + �������� ��������),
		���������� ����� ������� ������(����� ������� ������ - ����� ������� ������).
		������������  ������ ������(�� ����������� ���������), ����� ������������ ������ ������ CicleInSquare(��� SquareInCircle) ������� ����������� ������������ ������� �������� ����� �������� �������
		������������  ������� ��������(�� ����������� ���������), ����� ������������ ������� �������� ��� ������ CicleInSquare(��� SquareInCircle) ������� ����������� ������������ ����� �����
		����� ��������� ���������� ��� ������ �� �����


		����������� �������� ������������.

		������������ ������ �����.*/

	/*Ship ship("vict", 2007);
	ship.print();
	CruiseShip ship1("baba", 2008, 3000);
	ship1.print();*/


















  



	/*srand(time(NULL));
	BinTree<int>tree;
	for (size_t i = 0; i < 10; i++)
	{
		int number = rand() % 60;
		cout << "add node" << number << endl;
		tree.AddNode(number);

	}
	
	tree.print();

	cout << "min >> " << tree.min() << endl;;
	cout << "max >> " << tree.max() << endl;;

	
	cout << "------" << endl;
	cout << "findd" << tree.find(0) << endl;;
    tree.clear();*/













	
	/*Matrix<double>M(5,5);
	M += 10;
	//cout << M << endl;
	//cin >> M;
	//M.print();
	M(0, 0) = 100;
	M(1, 1) = 200;
	cout << M << endl;
	Matrix<double>c = M + 2;
	c.print();
	Matrix<double>d = M + 4;
	d.print();
	bool result = M == c;
	cout << "result" << result << endl;
	 
	 Matrix<double>A;
   	 A = M + c;
	 A.print();*/
   
	
	//M.sumMatrix();
	//M.maxElementMatrix();

	/*Matrix<int>M1(4, 4);
	
	M1.print();
	M1.sumMatrix();
	M1.maxElementMatrix();*/

cout << "________" << endl;
























 /*DList<int>list;
 list.addHead(5);
 list.addHead(4);
 list.addHead(6);
 list.addTail(7);
 list.print();
 list.printR();

 list.delTail();
 list.print();
 list.printR();
 list.insertBefore(5, -5);
 list.insertBefore(4, -4);

 list.print();
 list.printR();
 list.clear();
 list.print();
 list.printR();*/
 
 /*for(auto it=list.begin();it!=list.end();it++)
 {
	 cout << *it << "\t";
 }*/

	SList<int> list;
	
	list.addHead(11);
	//list.addTail(19);
	list.print();
	list.delHead();
	list.print();
	list.addTail(300);
	list.print();



	list.addHead(6);
	list.addTail(200);
	list.print();

	list.addHead(3);
	list.print();
	list.delTail();
	list.print();
	cout << "clear" << endl;
	list.clear();
	cout << "list" << endl;
	list.print();

	list.addHead(10);
	list.print();
	list.addTail(11);
	list.print();


	cout << endl;
	cout << "coopyyyy" << endl;
	SList<int> list1(list);
	list1.print();
	list1.insert(99,2);
	list1.addHead(87);
	cout << "insert" << endl;
	list1.print();
	list1.deleteIndex(2);
	
	cout << "delete" << endl;
	list1.print();

	list1.addHead(87);
	list1.addHead(86);
	list1.addHead(85);
	list1.addHead(84);
	list1.print();
	list1.reverse();
	cout << "reverse" << endl;
	list1.print();
	list1.find(84);
	cout << "findd" << endl;
	list1.print();
	system("pause");
	return 0;
}    










