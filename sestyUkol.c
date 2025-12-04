#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define BUFFER_SIZE 51

void normalizeWord(char word[]) {
    bool oneUpper = false;
    
    for(size_t i = 0; i < strlen(word); i++) {
        if(isupper(word[i])) {
            oneUpper = true;
        }
    }
    
    if(oneUpper) {
        word[0] = (char) toupper(word[0]);
        for(size_t i = 1; i < strlen(word); i++)
            word[i] = (char) tolower(word[i]);
    }
    else {
        for(size_t i = 0; i < strlen(word); i++)
            word[i] = (char) toupper(word[i]);
    }
}

void normalizeLine(char* line) {
    int lowerOriginal = 0;
    int upperOriginal = 0;
    int spacesOriginal = 0;
    int lowerAfter = 0;
    int upperAfter = 0;
    int spacesAfter = 0;
    
    if(line[strlen(line) - 1] == '\n')
        line[strlen(line) - 1] = '\0';
    
    //Vypocet statistiky na zacatku
    for(size_t i = 0; i < strlen(line); i++) {
        if(isupper(line[i])) upperOriginal++;
        if(islower(line[i])) lowerOriginal++;
        if(line[i] == ' ') spacesOriginal++;
    }
    
    //Odstraneni mezer
    //Zacatek
    while(line[0] == ' ') {
        for(size_t j = 0; j < strlen(line); j++)
            line[j] = line[j+1];
    }
    
    //Mezi slovy
    int i = 0;
        while (line[i] != '\0') {
            if (line[i] == ' ' && line[i + 1] == ' ') {
                int j = i;
                while (line[j] != '\0') {
                    line[j] = line[j + 1];
                    j++;
                }
            } else {
                i++;
            }
        }
    
    //Konec
    i = (int) strlen(line) - 1;
    while(i >= 0 && line[i] == ' ') {
        line[i] = '\0';
        i--;
    }
    
    //Normalizace jednotlivych slov
    char temp[BUFFER_SIZE] = "";
    char* token = strtok(line, " ");
    
    while(token != NULL) {
        normalizeWord(token);
        strcat(temp, token);
        token = strtok(NULL, " ");
        if(token != NULL)
            strcat(temp, " ");
    }
    strcpy(line, temp);
    
    //Odstraneni duplicity
    for(size_t i = 0; i < strlen(line); i++) {
        while(line[i] == line[i + 1] && line[i] != '\0') {
            for(size_t j = i + 1; j < strlen(line); j++) {
                line[j] = line[j + 1];
            }
        }
    }
    
    //Vypocet zmen
    for(size_t i = 0; i < strlen(line); i++) {
        if(islower(line[i])) lowerAfter++;
        if(isupper(line[i])) upperAfter++;
        if(isspace(line[i])) spacesAfter++;
    }
    
    //Statistika
    printf("%s\n", line);
    printf("lowercase: %d -> %d\n", lowerOriginal, lowerAfter);
    printf("uppercase: %d -> %d\n", upperOriginal, upperAfter);
    printf("spaces: %d -> %d\n", spacesOriginal, spacesAfter);
}

int main(void) {
    int n;
    char** text;
    char buffer[BUFFER_SIZE];
    
    fgets(buffer, BUFFER_SIZE, stdin);
    
    n = atoi(buffer);
    text = malloc((size_t) n * sizeof(char*));
    
    for(int i = 0; i < n; i++) {
        text[i] = malloc(BUFFER_SIZE * sizeof(char));
        fgets(buffer, BUFFER_SIZE, stdin);
        strcpy(text[i], buffer);
    }
    
    for(int i = 0; i < n; i++) {
        normalizeLine(text[i]);
        if(i != n - 1)
            printf("\n");
    }
    
    for(int i = 0; i < n; i++) {
        free(text[i]);
    }
    
    free(text);
    
    return 0;
}
