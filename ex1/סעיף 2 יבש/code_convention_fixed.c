#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

char *stringDuplicator(char *stringToDuplicate, int numberOfDuplications)
{
    
    assert(stringToDuplicate);
    assert(numberOfDuplications > 0);

    int lengthOfString = strlen(stringToDuplicate);
    char *duplicatedString = malloc(lengthOfString * numberOfDuplications + 1);

    if(duplicatedString == NULL){
        return(NULL)
    }

    for (int i = 1; i <= numberOfDuplications; i++)
    {
        strcpy(duplicatedString, stringToDuplicate);
        duplicatedString = duplicatedString + lengthOfString;
    }

    return duplicatedString - (numberOfDuplications * lengthOfString);
}

int main(int argc, char const *argv[])
{
   printf("%s",stringDuplicator("eran1 ", 3));
    return 0;
}