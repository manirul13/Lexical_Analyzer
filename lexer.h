#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_LITERAL,
    TOKEN_CONSTANT,
    TOKEN_UNKNOWN,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char lexeme[100];
} Token;

void initLexer(FILE *fp);
Token getNextToken();
const char* tokenTypeToString(TokenType type);
void printSummary();   
void printToken(Token t);

#endif
 
