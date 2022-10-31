#include "../src/Token.h"
#include <gtest/gtest.h>

// Run tests  ./build/app/unit_tests/unit_tests

namespace tests
{

struct CalculatorTests : ::testing::Test
{
};

TEST_F( CalculatorTests, tests_0 )
{
    ASSERT_TRUE( true );
}

TEST_F( CalculatorTests, Token_constructor )
{
    calculator::Token token{ '1' };
    ASSERT_TRUE( token.kind == '1' );
}

} // namespace tests
