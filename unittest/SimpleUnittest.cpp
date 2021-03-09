#include <gtest/gtest.h>
#include <string>

TEST(FirstTestExpectEq, string)
{
    std::string testString;
    testString = "are_unit_tests_working";

    EXPECT_EQ(testString, "are_unit_tests_working");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
