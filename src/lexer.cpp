//
// Created by merlin on 7/3/26.
//

#include "lexer.hpp"

#include <charconv>
#include <format>
#include <map>
#include <stdexcept>

#include "token.hpp"

using namespace token;

std::vector<token::Any> lexer::tokenize(std::string_view code) {
    int line = 1;
    std::vector<token::Any> result;

    for (auto it = code.begin(); it != code.end(); ++it) {
        auto remainingString = std::ranges::subrange(it, code.end());
        auto findBlank = [&] {
            return std::ranges::find_if(remainingString, [](char c) {
                switch (c) {
                    case ' ':
                    case '\t':
                    case '\n':
                        return true;
                    default:
                        return false;
                }
            });
        };
        switch (*it) {
            default:
                if (std::isalpha(*it)) {
                    auto blank = std::ranges::find_if(remainingString, [](char c) {
                        return !std::isalnum(c) && c != '_';
                    });
                    std::string_view valueString(it, blank);
                    it = std::prev(blank);

                    static std::map<std::string_view, Keyword> keywords = {
                        {"return", Keyword::RETURN},
                        {"fn", Keyword::FN},
                        {"if", Keyword::IF},
                    };

                    if (auto keyword = keywords.find(valueString); keyword != keywords.end()) {
                        result.emplace_back(keyword->second);
                        break;
                    }
                    result.emplace_back(Identifier{.value = std::string(valueString)});
                    break;
                }

                if (std::isdigit(*it)) {
                    auto end = std::ranges::find_if(remainingString, [](char c) {
                        return !std::isdigit(c);
                    });
                    std::string_view digitString(it, end);
                    int integer = 0;
                    std::from_chars(digitString.data(), digitString.data() + digitString.size(), integer);
                    result.emplace_back(Integer{.value = integer});
                    it = std::prev(end);
                    break;
                }

                throw std::runtime_error(std::format("Unexpected character: '{}', at line {}", &*it, line));

            case ' ':
            case '\r':
            case '\t':
                break;

            case '\n':
                ++line;
                break;

            case '(':
                result.emplace_back(LPar{});
                break;
            case ')':
                result.emplace_back(RPar{});
                break;
            case '{':
                result.emplace_back(LCurlyBracket{});
                break;
            case '}':
                result.emplace_back(RCurlyBracket{});
                break;
            case ';':
                result.emplace_back(Semicolon{});
                break;
            case '+':
                result.emplace_back(Plus{});
                break;
            case '-':
                result.emplace_back(Minus{});
                break;
            case '*':
                result.emplace_back(Asterisk{});
                break;
            case '/':
                result.emplace_back(Slash{});
                break;
            case ',':
                result.emplace_back(Comma{});
                break;

            case '=':
                if (std::next(it) != code.end()) {
                    if (*std::next(it) == '=') {
                        it++;
                        result.emplace_back(Equal2{});
                        break;
                    }
                }
                result.emplace_back(Equal{});
                break;

            case '"':
                auto end = std::ranges::find(
                    std::ranges::subrange(std::next(remainingString.begin()), remainingString.end()), '"');
                if (end == remainingString.end()) {
                    throw std::runtime_error(std::format("string literal is not finished, at line {}", line));
                }
                result.emplace_back(String{.value = std::string(std::next(it), end)});
                it = end;
                break;
        }
        if (it == code.end()) {
            break;
        }
    }
    return result;
}
