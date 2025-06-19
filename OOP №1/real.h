class Real {
private:
    Integer integerPart;
    Rational fractionalPart;

public:
    // Конструктор по умолчанию
    Real() : integerPart(0), fractionalPart(0, 1) {}

    // Конструктор с параметрами
    Real(const Integer& intPart, const Rational& fracPart) : integerPart(intPart), fractionalPart(fracPart) {}

    // Конвертация из целого
    Real(int value) : integerPart(value), fractionalPart(0, 1) {}

    // Конвертация из дробного
    Real(double value) {
        integerPart = Integer(static_cast<int>(value));
        fractionalPart = Rational(static_cast<int>((value - integerPart.getValue()) * 10000), 10000); // 4 знака после запятой
    }

    // Конвертация из строкового значения
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

    // Методы для работы с полями
    Integer getIntegerPart() const { return integerPart; }
    Rational getFractionalPart() const { return fractionalPart; }

    // Определение свойств
    bool isDecimal() const {
        // Проверяем, есть ли дробная часть
        return fractionalPart.getNumerator() != 0;
    }

    bool isNegative() const {
        return (integerPart.getValue() < 0) || (integerPart.getValue() == 0 && fractionalPart.getNumerator() < 0);
    }

    bool isPositive() const {
        return (integerPart.getValue() > 0) || (integerPart.getValue() == 0 && fractionalPart.getNumerator() > 0);
    }

    // Операторы
    Real operator+(const Real& other) const {
        // Сложение целых и дробных частей
        return Real(integerPart + other.integerPart, fractionalPart + other.fractionalPart);
    }

    Real operator-(const Real& other) const {
        // Вычитание целых и дробных частей
        return Real(integerPart - other.integerPart, fractionalPart - other.fractionalPart);
    }

    Real operator*(const Real& other) const {
        // Произведение
        return Real(integerPart * other.integerPart, fractionalPart * other.fractionalPart);
    }

    Real operator/(const Real& other) const {
        // Деление
        if (other.integerPart.getValue() == 0 && other.fractionalPart.getNumerator() == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return Real(integerPart / other.integerPart, fractionalPart / other.fractionalPart);
    }

    Real operator+() const {
        return *this; // Унарный плюс
    }

    Real operator-() const {
        return Real(-integerPart.getValue(), fractionalPart); // Унарный минус
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

