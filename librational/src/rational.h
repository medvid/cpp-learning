#pragma once

#include <iostream>

namespace librational
{

class rational
{
private:
    int m_num;
    int m_denom;

    void reduce();

public:
    static const rational Inf;
    static const rational NaN;

    rational(int num, int denom);
    int num() const;
    int denom() const;

    friend std::ostream& operator<<(std::ostream& os, const rational &r);
    friend std::istream& operator>>(std::istream& is, rational &r);

    bool operator==(const rational &other) const;
    bool operator!=(const rational &other) const;
    rational& operator+=(const rational &other);
    rational& operator-=(const rational &other);
    rational& operator*=(const rational &other);
    rational& operator/=(const rational &other);
};

inline rational operator+(rational x, const rational &y)
{
    return x += y;
}

inline rational operator-(rational x, const rational &y)
{
    return x -= y;
}

inline rational operator*(rational x, const rational &y)
{
    return x *= y;
}

inline rational operator/(rational x, const rational &y)
{
    return x /= y;
}

}
