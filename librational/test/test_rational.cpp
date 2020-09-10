#include "rational.h"
#include "gtest/gtest.h"

using librational::rational;

#define RATIONAL_EXPECT_EQ(r, n, d) \
    EXPECT_EQ(n, r.num()); \
    EXPECT_EQ(d, r.denom())

TEST(rational, test_ctor)
{
    rational r1{1, 2};
    RATIONAL_EXPECT_EQ(r1, 1, 2);

    rational r2{2, 4};
    RATIONAL_EXPECT_EQ(r2, 1, 2);

    EXPECT_EQ(r1, r2);

    rational r3{0, 0};
    EXPECT_EQ(rational::NaN, r3);

    rational r4{1, 0};
    EXPECT_EQ(rational::Inf, r4);

    rational r5{-36, 12};
    RATIONAL_EXPECT_EQ(r5, -3, 1);
}

TEST(rational, test_multiplies_assign)
{
    rational r1{1, 2}, r2{2, 5};
    r1 *= r2;
    RATIONAL_EXPECT_EQ(r1, 1, 5);
}
