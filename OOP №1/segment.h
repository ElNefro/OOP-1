#include <iostream>
#include <cmath>
class Segment {
private:
    Point2d* pointA;
    Point2d* pointB;

public:
    // ����������� �� ���������
    Segment() : pointA(new Point2d()), pointB(new Point2d()) {}

    // ����������� � ����� �������
    Segment(Point2d* a, Point2d* b) : pointA(new Point2d(*a)), pointB(new Point2d(*b)) {}

    // ���������� �����������
    Segment(const Segment& other)
        : pointA(new Point2d(*other.pointA)), pointB(new Point2d(*other.pointB)) {}

    // �������� ������������
    Segment& operator=(const Segment& other) {
        if (this != &other) {
            delete pointA;
            delete pointB;
            pointA = new Point2d(*other.pointA);
            pointB = new Point2d(*other.pointB);
        }
        return *this;
    }

    // ����������
    ~Segment() {
        delete pointA;
        delete pointB;
    }

    // ��������� �� �����
    bool operator<(const Segment& other) const {
        return length() < other.length();
    }

    // ��������� �� ���������
    bool operator==(const Segment& other) const {
        return (pointA->distance(*pointB) == other.pointA->distance(*other.pointB));
    }

    // ����� ��� ��������� ����� �������
    double length() const {
        return pointA->distance(*pointB);
    }

    // ����� �������� ����������� �������� (������� ����������)
    bool intersects(const Segment& other) const {
        // ��� ����� ����� ����������� ��������, ��������, "������� ����������" ��� "����� ������������ ��������"
        // ��� ����� ����������� ���������� ��� ��������� ������-������� ��� ������ ��� ��������
        return false; // �������� ���������� false
    }

    void printLength() const {
        std::cout << "Length of the segment: " << length() << std::endl;
    }
};