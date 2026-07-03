#pragma once

#include <cmath>
#include <cstdint>
#include <string_view>
#include <variant>

namespace ciq::token {
    // base
    struct EoF {
    };

    struct ID {
        std::string_view val;
    };

    // types
    struct INT {
    };

    struct FLOAT {
    };

    struct CHAR {
    };

    struct VOID {
    };

    struct NULL_KW {
    };

    // literals
    struct INT_LITERAL {
        int32_t val;
    };

    struct FLOAT_LITERAL {
        float_t val;
    };

    struct CHAR_LITERAL {
        char val;
    };

    struct STRING_LITERAL {
        std::string_view val;
    };

    // logical
    struct IF {
    };

    struct ELSE {
    };

    struct AND {
    };

    struct OR {
    };

    struct NOT {
    };

    struct BIT_AND {
    };

    struct BIT_OR {
    };

    struct BIT_XOR {
    };

    struct SHL {
    };

    struct SHR {
    };

    struct BIT_NOT {
    };

    // syntax
    struct WHILE {
    };

    struct FOR {
    };

    struct BREAK {
    };

    struct CONTINUE {
    };

    struct FUNCTION {
    };

    struct TRY {
    };

    struct CATCH {
    };

    struct THROW {
    };

    struct RETURN {
    };

    struct PRINT {
    }; // костыль чтобы не реализовывать в стд

    // symbols
    struct LPAREN {
    };

    struct RPAREN {
    };

    struct LBRACE {
    };

    struct RBRACE {
    };

    struct LBRACKET {
    };

    struct RBRACKET {
    };

    struct SEMI {
    };

    struct COMMA {
    };

    struct ASSIGN {
    };

    struct DOT {
    };

    struct COLON {
    };

    struct QUESTION {
    };

    // math
    struct PLUS {
    };

    struct MINUS {
    };

    struct MUL {
    };

    struct DIV {
    };

    struct MOD {
    };

    struct token {
        int32_t line;
        int32_t col;

        // TODO посмотреть как это можно решить хитровыебаным путем по типу рефлексии cтатической
        using type = std::variant<
            EoF, ID,

            INT, FLOAT, CHAR, VOID, NULL_KW,

            INT_LITERAL, FLOAT_LITERAL, CHAR_LITERAL, STRING_LITERAL,

            IF, ELSE, AND, OR, NOT, BIT_AND, BIT_OR, BIT_XOR, SHL, SHR, BIT_NOT,

            WHILE, FOR, BREAK, CONTINUE, FUNCTION, TRY, CATCH, THROW, RETURN, PRINT,

            LPAREN, RPAREN, LBRACE, RBRACE, LBRACKET, RBRACKET, SEMI, COMMA, ASSIGN,
            DOT, COLON, QUESTION,

            PLUS, MINUS, MUL, DIV, MOD>;
    };
};
