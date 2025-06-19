#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

class Integer {
private:
    int value;

public:
    // ����������� �� ���������
    Integer() : value(0) {}

    // ����������� � ����������� ���� �����
    Integer(int val) : value(val) {}

    // ����������� ����������� �� double, int � bool
    Integer(double val) : value(static_cast<int>(val)) {}
    Integer(bool val) : value(val ? 1 : 0) {}

    // ����������� ����������� �� ��������� ������
    Integer(const std::string& str) {
        value = std::stoi(str);
    }

    // ������ ��� ������ � ������
    int getValue() const {
        return value;
    }

    void setValue(int val) {
        value = val;
    }

    // ������-���������
    bool isEven() const {
        return value % 2 == 0;
    }

    bool isOdd() const {
        return value % 2 != 0;
    }

    bool isNegative() const {
        return value < 0;
    }

    bool isPositive() const {
        return value > 0;
    }

    bool isPrime() const {
        if (value <= 1) return false;
        for (int i = 2; i <= std::sqrt(value); i++) {
            if (value % i == 0) return false;
        }
        return true;
    }

    bool areCoprime(const Integer& other) const {
        return gcd(value, other.value) == 1;
    }

    bool isSameObject(const Integer& other) const {
        return this == &other;
    }

    // ������ ��� ����������� ��������
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    std::string primeFactors() const {
        std::string factors;
        int num = value;
        for (int i = 2; i <= num; i++) {
            while (num % i == 0) {
                factors += std::to_string(i) + " ";
                num /= i;
            }
        }
        return factors;
    }

    // ���������
    Integer operator+(const Integer& other) const {
        return Integer(value + other.value);
    }

    Integer operator-(const Integer& other) const {
        return Integer(value - other.value);
    }

    Integer operator*(const Integer& other) const {
        return Integer(value * other.value);
    }

    Integer operator/(const Integer& other) const {
        if (other.value == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return Integer(value / other.value);
    }

    Integer operator%(const Integer& other) const {
        if (other.value == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return Integer(value % other.value);
    }

    Integer& operator++() {
        ++value;
        return *this;
    }

    Integer operator++(int) {
        Integer temp = *this;
        ++*this;
        return temp;
    }

    Integer& operator--() {
        --value;
        return *this;
    }

    Integer operator--(int) {
        Integer temp = *this;
        --*this;
        return temp;
    }

    bool operator==(const Integer& other) const {
        return value == other.value;
    }

    bool operator!=(const Integer& other) const {
        return !(*this == other);
    }

    bool operator>(const Integer& other) const {
        return value > other.value;
    }

    bool operator>=(const Integer& other) const {
        return value >= other.value;
    }

    bool operator<(const Integer& other) const {
        return value < other.value;
    }

    bool operator<=(const Integer& other) const {
        return value <= other.value;
    }

    Integer operator-() const {
        return Integer(-value);
    }

    Integer operator+() const {
        return *this; // ������� ���� ������ �� ������
    }
};