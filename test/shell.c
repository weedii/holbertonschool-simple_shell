#include "shell.h"

/***/

int main()
{
    char input_String[MAXCOM], *parsedArgs[MAXLIST];
    char *parsedArgsPiped[MAXLIST];
    int execFlag = 0;

    while (1)
    {
        printDir();

        if (takeInput(input_String))
            continue;

        execFlag = processString(input_String,
                                 parsedArgs, parsedArgsPiped);

        if (execFlag == 1)
            execArgs(parsedArgs);

        if (execFlag == 2)
            execArgsPiped(parsedArgs, parsedArgsPiped);
    }
    return 0;
}