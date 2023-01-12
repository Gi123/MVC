#pragma once
#include <iostream>
#include <sstream>
#include <string>


#pragma region Point
class Point {
public:
/**
* @brief конструктор для класса Point координатами 0,0
* 
*/
	Point() : valx{ 0. }, valy{ 0. } {}
/**
 * @brief конструктор для класса Point переданными координатами
 * 
 * @param newx 
 * @param newy 
 */
	Point(double newx, double newy)
		: valx{ newx }, valy{ newy }
	{}
	double getX() const {
		return valx;
	}
	double getY() const {
		return valy;
	}
	void setX(double newx) {
		valx = newx;
	}
	void setY(double newy) {
		valy= newy;
	}
private:
	double valx;
	double valy;
};
#pragma endregion
/**
 * @brief Базовый класс для всех фигур
 * 
 */
class base_primitive {
public:

	virtual ~base_primitive() {};
	virtual std::string draw_figure() = 0;
};

#pragma region Line
/**
 * @brief Класс представляющий Линию
 * 
 */
class Line :public base_primitive {
public:
/**
 * @brief Конструктор обьекта Линии
 * 
 * @param f координата начала линии
 * @param t координата конца линии
 */
	Line(Point f, Point t) :
		from{ f }, to{ t } {
	}
	/**
	 * @brief Деструткор
	 * 
	 */
	~Line() override {};
	/**
 	* @brief Функция прорисовки линии
	* @return std::string возвращает сообщение о прорисовки
	 */
	std::string draw_figure() override {
		std::stringstream ss;
		ss << "LINE from {" << from.getX() << ", " << from.getY() << "} to {" << to.getX() << ", " << to.getY() << "}";
		return ss.str();
	};

private:
	Point from;	 
	Point to;	 
};
#pragma endregion

#pragma region Circle/**
 * @brief Класс представляющий Окружность
 * 
 */
class Circle :public base_primitive {
public:
/**
 * @brief Конструктор обьекта Окружность
 * 
 * @param c сслыка на обект Coord соодержащий координаты
 * @param r радиус окружности
 */
	Circle(Point c, int r) :
		center{ c }, rad{ r } {
	}
	~Circle() override {};
	/**
	/**
 	* @brief Функция прорисовки окружности
	* @return std::string возвращает сообщение о прорисовки
	 */
	std::string draw_figure() override {
		std::stringstream ss;
		ss << "CIRCLE at {" << center.getX() << ", " << center.getY() << "}  with radius " << rad;
		return ss.str();
	};

private:
	Point center;
	int rad;
};

#pragma endregion

#pragma region Rectangle
/**
 * @brief Класс представляющий  прямоугольник
 * 
 */
class Rectangle :public base_primitive {
public:
/**
 * @brief Конструктор обьекта Прямоугольник
 * 
 * @param a  координата угла для прорисовки прямоугольника
 * @param b  координата угла для прорисовки прямоугольника
 * @param c  координата угла для прорисовки прямоугольника
 * @param d  координата угла для прорисовки прямоугольника
 */
	Rectangle(Point _a, Point _b, Point _c, Point _d) :
		a{ _a }, b{ _b } , c{_c}, d{_d} {
	}
	~Rectangle() override {};
	/**
 	* @brief Функция прорисовки прямоугольника
	* @return std::string возвращает сообщение о прорисовки
	 */
	std::string draw_figure() override {
		std::stringstream ss;
		ss << "RECTANGLE {" << a.getX() << ", " << a.getY() << "} " << "b {" << b.getX() << ", " << b.getY() << "} " << "c {" << c.getX() << ", " << c.getY() << "} " <<
			 "d {" << d.getX() << ", " << d.getY() << "} ";
;
		return ss.str();
	};
private:
	Point a;
	Point b;
    Point c;
    Point d;
};
#pragma endregion