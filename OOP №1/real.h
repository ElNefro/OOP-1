class Real {
private:
    Integer integerPart;
    Rational fractionalPart;

public:
    // ����������� �� ���������
    Real() : integerPart(0), fractionalPart(0, 1) {}

    // ����������� � �����������
    Real(const Integer& intPart, const Rational& fracPart) : integerPart(intPart), fractionalPart(fracPart) {}

    // ����������� �� ������
    Real(int value) : integerPart(value), fractionalPart(0, 1) {}

    // ����������� �� ��������
    Real(double value) {
        integerPart = Integer(static_cast<int>(value));
        fractionalPart = Rational(static_cast<int>((value - integerPart.getValue()) * 10000), 10000); // 4 ����� ����� �������
    }

    // ����������� �� ���������� ��������
    Real(const std::string& str) {
        size_t dotPosition = str.find('.');
        if (dotPosition != std::string::npos) {
            int intPart = std::stoi(str.substr(0, dotPosition));
            double fracPart = std::stod(str.substr(dotPosition));
            integerPart = Integer(intPart);
            fractionalPart = Rational(static_cast<int>((fracPart - intPart) * 10000), 10000);
        }
        else {
            integerPart = Integer(std::stoi(str));
            fractionalPart = Rational(0, 1);
        }
    }

    // ������ ��� ������ � ������
    Integer getIntegerPart() const { return integerPart; }
    Rational getFractionalPart() const { return fractionalPart; }

    // ����������� �������
    bool isDecimal() const {
        // ���������, ���� �� ������� �����
        return fractionalPart.getNumerator() != 0;
    }

    bool isNegative() const {
        return (integerPart.getValue() < 0) || (integerPart.getValue() == 0 && fractionalPart.getNumerator() < 0);
    }

    bool isPositive() const {
        return (integerPart.getValue() > 0) || (integerPart.getValue() == 0 && fractionalPart.getNumerator() > 0);
    }

    // ���������
    Real operator+(const Real& other) const {
        // �������� ����� � ������� ������
        return Real(integerPart + other.integerPart, fractionalPart + other.fractionalPart);
    }

    Real operator-(const Real& other) const {
        // ��������� ����� � ������� ������
        return Real(integerPart - other.integerPart, fractionalPart - other.fractionalPart);
    }

    Real operator*(const Real& other) const {
        // ������������
        return Real(integerPart * other.integerPart, fractionalPart * other.fractionalPart);
    }

    Real operator/(const Real& other) const {
        // �������
        if (other.integerPart.getValue() == 0 && other.fractionalPart.getNumerator() == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return Real(integerPart / other.integerPart, fractionalPart / other.fractionalPart);
    }

    Real operator+() const {
        return *this; // ������� ����
    }

    Real operator-() const {
        return Real(-integerPart.getValue(), fractionalPart); // ������� �����
    }

    bool operator==(const Real& other) const {
        return integerPart == other.integerPart && fractionalPart == other.fractionalPart;
    }

    bool operator!=(const Real& other) const {
        return !(*this == other);
    }

    bool operator>(const Real& other) const {
        return (integerPart > other.integerPart) || (integerPart == other.integerPart && fractionalPart > other.fractionalPart);
    }

    bool operator>=(const Real& other) const {
        return (*this > other) || (*this == other);
    }

    bool operator<(const Real& other) const {
        return !(*this >= other);
    }

    bool operator<=(const Real& other) const {
        return !(*this > other);
    }
};

