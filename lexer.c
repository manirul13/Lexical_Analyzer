 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

static FILE *source;

// --- Summary struct ---
typedef struct {
    int keywordCount;
    int identifierCount;
    int operatorCount;
    int literalCount;
    int constantCount;
    int unknownCount;
    int totalTokens;
} Summary;

static Summary summary;

// Keywords list
static const char *keywords[] = {
    "int", "float", "if", "else", "while", "for", "return", "char", "double", NULL
};

void initLexer(FILE *fp) {
    source = fp;
    memset(&summary, 0, sizeof(summary)); // Reset counts
}

const char* tokenTypeToString(TokenType type) {
    switch (type) {
        case TOKEN_KEYWORD: return "Keyword";
        case TOKEN_IDENTIFIER: return "Identifier";
        case TOKEN_OPERATOR: return "Opearator";
        case TOKEN_LITERAL: return "Literal";
        case TOKEN_CONSTANT: return "Constant";
        case TOKEN_UNKNOWN: return "Unknown";
        case TOKEN_EOF: return "EOF";
        default: return "Unknown";
    }
}

int isKeyword(const char *str) {
    for (int i = 0; keywords[i]; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

Token getNextToken() {
    Token token;
    int c;

    while ((c = fgetc(source)) != EOF) {
        if (isspace(c)) continue;

        // Identifiers or Keywords
        if (isalpha(c) || c == '_') {
            int i = 0;
            token.lexeme[i++] = c;
            while (isalnum(c = fgetc(source)) || c == '_') {
                token.lexeme[i++] = c;
            }
            token.lexeme[i] = '\0';
            ungetc(c, source);

            if (isKeyword(token.lexeme)) {
                token.type = TOKEN_KEYWORD;
                summary.keywordCount++;
            } else {
                token.type = TOKEN_IDENTIFIER;
                summary.identifierCount++;
            }
            summary.totalTokens++;
            return token;
        }

        // Numbers (constants)
        if (isdigit(c)) {
            int i = 0;
            token.lexeme[i++] = c;
            while (isdigit(c = fgetc(source))) {
                token.lexeme[i++] = c;
            }
            token.lexeme[i] = '\0';
            ungetc(c, source);

            token.type = TOKEN_CONSTANT;
            summary.constantCount++;
            summary.totalTokens++;
            return token;
        }

        // String / Character literals
        if (c == '"' || c == '\'') {
            int i = 0;
            char quote = c;
            while ((c = fgetc(source)) != quote && c != EOF) {
                token.lexeme[i++] = c;
            }
            token.lexeme[i] = '\0';
            token.type = TOKEN_LITERAL;
            summary.literalCount++;
            summary.totalTokens++;
            return token;
        }

        // Operators
        if (strchr("+-*/=%!<>&|", c)) {
            token.lexeme[0] = c;
            token.lexeme[1] = '\0';
            token.type = TOKEN_OPERATOR;
            summary.operatorCount++;
            summary.totalTokens++;
            return token;
        }

        // Symbols (treat as operators)
        if (strchr("(){};,", c)) {
            token.lexeme[0] = c;
            token.lexeme[1] = '\0';
            token.type = TOKEN_OPERATOR;
            summary.operatorCount++;
            summary.totalTokens++;
            return token;
        }

        // Unknown
        token.lexeme[0] = c;
        token.lexeme[1] = '\0';
        token.type = TOKEN_UNKNOWN;
        summary.unknownCount++;
        summary.totalTokens++;
        return token;
    }

    token.type = TOKEN_EOF;
    strcpy(token.lexeme, "EOF");
    return token;
}

void printSummary() {
    
    printf("\n======= Lexical Analysis Summary =======\n\n");
    printf("| Keywords        : %-19d|\t\n", summary.keywordCount);
    printf("| Identifiers     : %-19d|\t\n", summary.identifierCount);
    printf("| Operators       : %-19d|\t\n", summary.operatorCount);
    printf("| Literals        : %-19d|\t\n", summary.literalCount);
    printf("| Constants       : %-19d|\t\n", summary.constantCount);
    printf("| Unknown         : %-19d|\t\n", summary.unknownCount);
    printf("| Total           : %-19d|\t\n", summary.totalTokens);
}

void printToken(Token t)
{
    printf("Token: %-12s Lexer: %s\n", 
        (t.type == TOKEN_KEYWORD) ? "Keyword" :
        (t.type == TOKEN_IDENTIFIER) ? "Identifier" :
        (t.type == TOKEN_OPERATOR) ? "Operator" :
        (t.type == TOKEN_LITERAL) ? "Literal" :
        (t.type == TOKEN_CONSTANT) ? "Constant" :
        (t.type == TOKEN_UNKNOWN) ? "Unknown" : "EOF",
        t.lexeme);
}

