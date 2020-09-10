#include "rational.h"
#include <cassert>
#include <cmath>
#include <string>
#include "gcd.h"

namespace librational
{

const rational rational::Inf{1, 0};
const rational rational::NaN{0, 0};

void rational::reduce()
{
    if (m_denom == 0)
    {
        if (m_num != 0)
        {
            m_num = (m_num > 0) ? 1 : -1;
        }
        return;
    }

    int gcd_val = gcd(abs(m_num), m_denom);
    assert(m_num % gcd_val == 0);
    assert(m_denom % gcd_val == 0);
    m_num /= gcd_val;
    m_denom /= gcd_val;
}

rational::rational(int num, int denom) : m_num(num), m_denom(denom)
{
    reduce();
}

int rational::num() const
{
    return m_num;
}

int rational::denom() const
{
    return m_denom;
}

std::ostream& operator<<(std::ostream& os, const rational &r)
{
    if (r == rational::Inf)
    {
        os << "Inf";
    }
    else if (r == rational::NaN)
    {
        os << "NaN";
    }
    else if (r.m_denom == 1)
    {
        os << r.m_num;
    }
    else
    {
        os << r.m_num << '/' << r.m_denom;
    }
    return os;
}

std::istream& operator>>(std::istream& is, rational &r)
{
    std::string input_data;
    is >> input_data;

    try
    {
        size_t slashidx = input_data.find('/');
        if (slashidx == std::string::npos) // "3" -> 3
        {
            int num = std::stoi(input_data);
            r = rational(num, 1);
        }
        else if (slashidx == 0) // "/3" -> 1/3
        {
            int denom = std::stoi(input_data.substr(slashidx + 1));
            r = rational(1, denom);
        }
        else // "1/3" -> 1/3
        {
            int num = std::stoi(input_data.substr(0, slashidx));
            int denom = std::stoi(input_data.substr(slashidx + 1));
            r = rational(num, denom);
        }
    }
    catch (std::invalid_argument const &e)
    {
        std::cerr << "Bad input: " << e.what() << std::endl;
    }
    catch (std::out_of_range const &e)
    {
        std::cerr << "Integer overflow: " << e.what() << std::endl;
    }
    return is;
}

bool rational::operator==(const rational &other) const
{
    return (m_num == other.m_num) && (m_denom == other.m_denom);
}

bool rational::operator!=(const rational &other) const
{
    return !(*this == other);
}

rational& rational::operator+=(const rational &other)
{
    if ((m_denom == 0) || (other.m_denom == 0))
    {
        m_denom = 0;
    }
    else
    {
        // TODO: overflow
        int new_num = m_num * other.m_denom + m_denom * other.m_num;
        int new_denom = m_denom + other.m_denom;
        m_num = new_num;
        m_denom = new_denom;
    }
    reduce();
    return *this;
}

rational& rational::operator-=(const rational &other)
{
    if ((m_denom == 0) || (other.m_denom == 0))
    {
        m_denom = 0;
    }
    else
    {
        // TODO: overflow
        int new_num = m_num * other.m_denom - m_denom * other.m_num;
        int new_denom = m_denom + other.m_denom;
        m_num = new_num;
        m_denom = new_denom;
    }
    reduce();
    return *this;
}

rational& rational::operator*=(const rational &other)
{
    if ((m_denom == 0) || (other.m_denom == 0))
    {
        m_denom = 0;
    }
    else
    {
        // TODO: overflow
        int new_num = m_num * other.m_num;
        int new_denom = m_denom * other.m_denom;
        m_num = new_num;
        m_denom = new_denom;
    }
    reduce();
    return *this;
}

rational& rational::operator/=(const rational &other)
{
    if ((m_denom == 0) || (other.m_num == 0))
    {
        m_denom = 0;
    }
    else
    {
        // TODO: overflow
        int new_num = m_num * other.m_denom;
        int new_denom = m_denom + other.m_num;
        m_num = new_num;
        m_denom = new_denom;
    }
    reduce();
    return *this;
}

}
