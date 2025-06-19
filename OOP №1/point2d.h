#include <iostream>
class Point2d {
private:
    Real x;
    Real y;

public:
    // Конструктор по умолчанию
    Point2d() : x(0), y(0) {}

    // Конструктор с параметрами
    Point2d(const Real& xCoord, const Real& yCoord) : x(xCoord), y(yCoord) {}

    // Метод для доступа к координатам
    Real getX() const { return x; }
    Real getY() const { return y; }

    // Оператор ==
    bool operator==(const Point2d& other) const {
        return x == other.x && y == other.y;
    }

    // Метод для определения расстояния между точками
    double distance(const Point2d& other) const {
        double deltaX = static_cast<double>(x.getIntegerPart()) - static_cast<double>(other.x.getIntegerPart());
        double deltaY = static_cast<double>(y.getIntegerPart()) - static_cast<double>(other.y.getIntegerPart());
        return std::sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    // Виртуальный деструктор
    virtual ~Point2d() {}
};