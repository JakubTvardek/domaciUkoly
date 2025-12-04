#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 100

bool containsArg(int argc, char* argv[], char argument[]) {
    for(int i = 0; i < argc; i++) {
        if(strcmp(argv[i], argument) == 0) {
            return true;
        }
    }
    return false;
}

bool containsIgnoreCase(char* radek, char* needle) {
    int delkaRadku = strlen(radek);
    int delkaNeedle = strlen(needle);
    
    for(int i = 0; i <= delkaRadku - delkaNeedle; i++) {
        bool shoda = true;
        for(int j = 0; j < delkaNeedle; j++) {
            if(tolower(radek[i+j]) != tolower(needle[j])) {
                shoda = false;
                break;
            }
        }
        if(shoda) return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    //Povinné
    char* filename = NULL;
    char* needle = NULL;
    //Nepovinné
    char* output = NULL;
    bool ignoreCase = false;
    int necessaryIndex = 0;

    //Ostatní
    FILE* file = NULL;
    int countOfI = 0;
    int countOfO = 0;

    //Kontrola počtu parametrů
    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-o") == 0) {
            countOfO++;
            if(i + 1 < argc) {
                output = argv[i+1];
            }
            else {
                printf("Missing output path\n");
                return 1;
            }
        } else if(strcmp(argv[i], "-i") == 0) {
            countOfI++;
            ignoreCase = true;
        } else {
            if(necessaryIndex == 0) {
                filename = argv[i];
                necessaryIndex++;
            } else if(necessaryIndex == 1) {
                needle = argv[i];
            } else {
                necessaryIndex++;
            }
        }
    }
    if(necessaryIndex > 2) {printf("Too many parameters provided\n");return 1;}
    if(countOfI > 1) {printf("Parameter -i provided multiple times\n"); return 1;}
    if(countOfO > 1) {printf("Parameter -o provided multiple times\n"); return 1;}
    if(!filename) {printf("Input path not provided\n"); return 1;}
    if(!needle) {printf("Needle not provided\n"); return 1;}

    file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];

    //Vypsani shod
    FILE* outputFile = NULL;
    if(output != NULL) {
        outputFile = fopen(output, "w");
        if(!outputFile) {
            printf("chyba\n");
            return 1;
        }
    }
    while(fgets(buffer, BUFFER_SIZE, file)) {
        bool shoda = false;

        if(ignoreCase) {
            shoda = containsIgnoreCase(buffer, needle);
        }
        else {
            if(strstr(buffer, needle) != NULL) {
                shoda = true;
            }
        }
        
        if(shoda) {
            if(outputFile != NULL) {
                fprintf(outputFile, "%s", buffer);
            } else {
                printf("%s", buffer);
            }
        }
    }
    if(outputFile) {
        fclose(outputFile);
    }
    fclose(file);
    
    return 0;
}