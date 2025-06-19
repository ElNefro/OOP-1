#include <iostream>
#include <cmath>
class Segment {
private:
    Point2d* pointA;
    Point2d* pointB;

public:
    // Конструктор по умолчанию
    Segment() : pointA(new Point2d()), pointB(new Point2d()) {}

    // Конструктор с двумя точками
    Segment(Point2d* a, Point2d* b) : pointA(new Point2d(*a)), pointB(new Point2d(*b)) {}

    // Копирующий конструктор
    Segment(const Segment& other)
        : pointA(new Point2d(*other.pointA)), pointB(new Point2d(*other.pointB)) {}

    // Оператор присваивания
    Segment& operator=(const Segment& other) {
        if (this != &other) {
            delete pointA;
            delete pointB;
            pointA = new Point2d(*other.pointA);
            pointB = new Point2d(*other.pointB);
        }
        return *this;
    }

    // Деструктор
    ~Segment() {
        delete pointA;
        delete pointB;
    }

    // Сравнение по длине
    bool operator<(const Segment& other) const {
        return length() < other.length();
    }

    // Сравнение на равенство
    bool operator==(const Segment& other) const {
        return (pointA->distance(*pointB) == other.pointA->distance(*other.pointB));
    }

    // Метод для получения длины отрезка
    double length() const {
        return pointA->distance(*pointB);
    }

    // Метод проверки пересечения отрезков (базовая реализация)
    bool intersects(const Segment& other) const {
        // Вам нужно будет реализовать алгоритм, например, "графика исключений" или "метод направленных отрезков"
        // Это может потребовать надстройки для получения лямбда-функции или другой тип проверки
        return false; // Временно возвращаем false
    }

    void printLength() const {
        std::cout << "Length of the segment: " << length() << std::endl;
    }
};