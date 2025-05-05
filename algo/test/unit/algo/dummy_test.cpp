#include <gtest/gtest.h>

#include <dummy.hpp>

namespace
{
    TEST(dummy, test)
    {
        const auto expected_result = std::string{"Hello World"};
        const auto actual_result = dummy();

        ASSERT_EQ(expected_result, actual_result);
    }
}