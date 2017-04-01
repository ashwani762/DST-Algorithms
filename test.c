#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define START 0
#define NEWLINE '\n'
#define SPACE ' '
#define TAB '\t'
#define EXIT '@'

int main()
{
    char choice[20];

    int newCharacter, lineCount, spaceCount, tabCount, characterCount, wordCount, flag, totalCharCount;
    system("clear");
    FILE *fptr;
    
    lineCount = spaceCount = tabCount = characterCount = wordCount = flag = totalCharCount = START;
    
    printf("lol.c (~/) - gedit\n");
    printf("---\n");
    printf("\n %d. ", ++lineCount);
    
    fptr = fopen("temp.c", "w");
    
    while((newCharacter = getchar()) != EXIT) {
    
        fprintf(fptr, "%c", newCharacter);
        
        if(newCharacter == NEWLINE) {
            if(flag == 1) {
                wordCount++;
            }
            
            lineCount++;
            flag = START;
            
            if(lineCount < 10) {
                printf(" %d. ", lineCount);
            }
            else {
                printf("%d. ", lineCount);
            }
        }
        else if(newCharacter == SPACE) {
            if(flag == 1) {
                wordCount++;
            }
            spaceCount++;
            flag = START;
        }
        else if(newCharacter == TAB) {
            if(flag == 1) {
                wordCount++;
            }
            tabCount++;
            flag = START;
        }
        else {
            characterCount++;
            flag = 1;
        }
        
        totalCharCount++;
    }
    
    fclose(fptr);
    printf("\n---\n");
    
    printf("\nType: Document Statistics | Compile and Run\nYou: ");
    fgets(choice, 20, stdin);   fgets(choice, 20, stdin);
    
    if(strstr(choice, "Document Statistics")) {
        printf("\n---\n");
        printf("Document Statistics\n");
        printf("      lol.c\n");
        printf("---");
        printf("\nLines           %d", lineCount);
        printf("\nWords           %d", ++    wordCount);
        printf("\nCharacters:");
        printf("\n   With spaces  %d", totalCharCount);
        printf("\n   No spaces    %d", characterCount);
        printf("\nSpaces          %d", spaceCount);
        printf("\nTabs            %d", tabCount);
        printf("\nBytes           %d\n", totalCharCount);
        printf("---\n");
    }
    else if(strstr(choice, "Compile and Run")) {
        system("clear");   system("cc temp.c");  system("./a.out");
    }
    
    return 0;
}