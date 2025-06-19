class Rational {
private:
    Integer numerator; // Числитель
    Integer denominator; // Знаменатель

    void simplify() {
        // Упрощение дроби
        // ...
    }

public:
    // Конструктор по умолчанию
    Rational() : numerator(0), denominator(1) {}

    // Конструктор с параметрами
    Rational(Integer num, Integer denom) : numerator(num), denominator(denom) {
        if (denominator.getValue() == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        simplify();
    }

    // Конструктор для int
    Rational(int num) : numerator(num), denominator(1) {}

    // Конструктор для double
    Rational(double value) {
        // Конвертация из double
        numerator = Integer(static_cast<int>(value));
        denominator = Integer(1);
        // Упрощение при необходимости
    }

    // Методы для работы с полями
    Integer getNumerator() const { return numerator; }
    Integer getDenominator() const { return denominator; }

    bool isProper() const {
        return std::abs(numerator.getValue()) < std::abs(denominator.getValue());
    }

    bool isImproper() const {
        return std::abs(numerator.getValue()) >= std::abs(denominator.getValue());
    }

    bool isPositive() const {
        return (numerator.getValue() > 0) != (denominator.getValue() < 0);
    }

    bool isNegative() const {
        return !isPositive() && (numerator.getValue() != 0);
    }

    bool isEqual(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    // Методы для получения значений
    Rational inverse() const {
        return Rational(denominator, numerator);
    }

    Rational simplified() const {
        Rational result = *this; // Копия текущей дроби
        result.simplify();
        return result;
    }

    Integer wholePart() const {
        return Integer(numerator.getValue() / denominator.getValue());
    }

    Rational fractionalPart() const {
        return Rational(numerator.getValue() % denominator.getValue(), denominator);
    }

    // Метод упрощения дроби
    void simplify() {
        // Логика упрощения (находите НОД и делите числитель и знаменатель)
    }

    // Замена на обратную
    void replaceWithInverse() {
        std::swap(numerator, denominator);
    }

    // Операторы
    Rational operator+(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational& other) const {
        if (other.numerator.getValue() == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Rational& other) const {
        return isEqual(other);
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator<(const Rational& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Rational& other) const {
        return other < *this;
    }

    bool operator<=(const Rational& other) const {
        return !(other < *this);
    }

    bool operator>=(const Rational& other) const {
        return !(*this < other);
    }
};