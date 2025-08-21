#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int main(int argc, char *argv[])
{
    //validation of arguments
    if (argc != 2)
    {
        printf("\nUsage:➡️ ./lexer <.c (or) .txt file>\n\n");
        return 1;
    }

    char *fname = argv[1];
    FILE *src = fopen(fname, "r");
    if (!src)
    {
        printf("Open    : %s : Failed❌\n", fname);
        return 1;
    }

    // ✅ Initial messages
    printf("========================================\n");
    printf("Open    : %s      : Success✅\n", fname);
    printf("Parsing : %s      : Started⏸️\n\n", fname);

    initLexer(src);

    Token t;
    while ((t = getNextToken()).type != TOKEN_EOF)
    {
        printToken(t);
    }

    // ✅ Print summary
    printSummary(fname);

    // ✅ Ending message
    printf("\nParsing     : %s      : Done✅\n", fname);
    printf("========================================\n");

    fclose(src);
    return 0;
}
