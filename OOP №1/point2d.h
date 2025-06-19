#include <iostream>
class Point2d {
private:
    Real x;
    Real y;

public:
    // ����������� �� ���������
    Point2d() : x(0), y(0) {}

    // ����������� � �����������
    Point2d(const Real& xCoord, const Real& yCoord) : x(xCoord), y(yCoord) {}

    // ����� ��� ������� � �����������
    Real getX() const { return x; }
    Real getY() const { return y; }

    // �������� ==
    bool operator==(const Point2d& other) const {
        return x == other.x && y == other.y;
    }

    // ����� ��� ����������� ���������� ����� �������
    double distance(const Point2d& other) const {
        double deltaX = static_cast<double>(x.getIntegerPart()) - static_cast<double>(other.x.getIntegerPart());
        double deltaY = static_cast<double>(y.getIntegerPart()) - static_cast<double>(other.y.getIntegerPart());
        return std::sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    // ����������� ����������
    virtual ~Point2d() {}
};