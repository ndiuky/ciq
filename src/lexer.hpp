//
// Created by merlin on 7/3/26.
//

#ifndef CIQ_LEXER_H
#define CIQ_LEXER_H
#include <string_view>
#include <vector>

#include "token.hpp"


class lexer {
    public:
        static std::vector<token::Any> tokenize(std::string_view input);
};


#endif //CIQ_LEXER_H
