//
// Created by merlin on 7/3/26.
//

#include <gtest/gtest.h>

#include "lexer.h"

TEST(Lexer, BasicTest) {
    EXPECT_EQ(lexer::test(), 42);
}
