#include "lexer.hpp"
#include "token.hpp"
#include <gtest/gtest.h>

using namespace token;

constexpr std::string_view fun = R"(fn main() {
    return (228 + 1260);
};)";

constexpr std::string_view expected = R"(
"hello"
)";

TEST(LEXER_TEXT, Function) {
    std::vector<Any> processed = lexer::tokenize(fun);
    std::vector<Any> expected{
        Keyword::FN,
        Identifier{.value = "main"},
        LPar{},
        RPar{},
        LCurlyBracket{},
        Keyword::RETURN,
        LPar{},
        Integer{.value = 228},
        Plus{},
        Integer{.value = 1260},
        RPar{},
        Semicolon{},
        RCurlyBracket{},
        Semicolon{},
    };

    EXPECT_EQ(processed, expected);
}

TEST(LEXER_TEST, RETURN_STRING_LITERAL) {
    std::vector<Any> processed = lexer::tokenize(expected);
    std::vector<Any> expected {
        String{.value = "hello"},
    };

    EXPECT_EQ(processed, expected);
}
