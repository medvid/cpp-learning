#include "my_vector.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(my_vector, test_push_back)
{
    my_vector<int> v1(2,0);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    EXPECT_THAT(v1, ElementsAre(0, 0, 1, 2, 3, 4));

    my_vector<double> v2(1, 0.0);
    v2.push_back(1.1);
    v2.push_back(2.2);
    v2.push_back(3.3);
    v2.push_back(4.4);
    EXPECT_THAT(v2, ElementsAre(0, 1.1, 2.2, 3.3, 4.4));

    my_vector<std::string> v3(0, std::string{});
    v3.push_back("a");
    v3.push_back("b");
    v3.push_back("c");
    v3.push_back("d");
    v3.push_back("e");
    v3.push_back("f");
    v3.push_back("g");
    v3.push_back("h");
    v3.push_back("i");
    EXPECT_THAT(v3, ElementsAre("a", "b", "c", "d", "e", "f", "g", "h", "i"));
}
