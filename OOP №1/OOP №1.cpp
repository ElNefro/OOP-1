#include <iostream>

class Integer
{
public:
    // Способы создания объектов
    Integer():Integer(false,0u){ }
    Integer(bool sign, unsigned units):sign(sign),units(units){ }
    Integer(int number){
        if (number < 0)
        {
            sign = true;
            units = ::abs(number);
        }
        else
        {
            sign = false;
            units = ::abs(number);
        }
    
    }
    // Способы обработки
    void setSign(bool sign)
    {
        this->sign = sign;
    }
    void setUnits(unsigned units)
    {
        this->units;
    }
    bool getSign()const
    {
        return sign;
    }
    unsigned getUnits()const
    {
        return units;
    }

    // Способы проверки
    bool isOdd()const
    {
        return bool(units % 2);
    }
    bool isPositive()const
    {
        return !sign;
    }
    //Перегрузки операторов
    Integer operator+(Integer other)const
    {
        return Integer();
    }
    friend Integer operator*(Integer a, Integer b)
    {
        return Integer();
    }

private:
    
    bool sign;
    unsigned units;
};

int main()
{
    
}


