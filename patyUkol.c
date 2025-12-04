#include <stdio.h>
#include <stdlib.h>

void initializeMap(char* map, int rows, int cols) {
    for(int i = 0; i < rows * cols; i++)
        map[i] = '.';
}

void printMap(char* map, int rows, int cols, int numberOfTurtles, int turtlesPositions[3][2]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int isTurtle = 0;
            
            for(int k = 0; k < numberOfTurtles; k++) {
                if(turtlesPositions[k][0] == i && turtlesPositions[k][1] == j)
                    isTurtle = 1;
            }
            
            int index = i * cols + j;
            
            if(isTurtle && map[index] != 'o')
                printf("%c", 'z');
            else
                printf("%c", map[index]);
        }
        printf("\n");
    }
}

void move(int facingDirections[3][1], int numberOfTurtles, int turtlePositions[3][2], int rows, int cols) {
    for (int i = 0; i < numberOfTurtles; i++) {
        int direction = facingDirections[i][0];
        int row = turtlePositions[i][0];
        int col = turtlePositions[i][1];

        switch (direction) {
            // RIGHT
            case 0:
                if (col + 1 < cols)
                    turtlePositions[i][1] = col + 1;
                else
                    turtlePositions[i][1] = 0;
                break;
            // DOWN
            case 1:
                if (row + 1 < rows)
                    turtlePositions[i][0] = row + 1;
                else
                    turtlePositions[i][0] = 0;
                break;
            // LEFT
            case 2:
                if (col - 1 >= 0)
                    turtlePositions[i][1] = col - 1;
                else
                    turtlePositions[i][1] = cols - 1;
                break;
            // UP
            case 3:
                if (row - 1 >= 0)
                    turtlePositions[i][0] = row - 1;
                else
                    turtlePositions[i][0] = rows - 1;
                break;
            default:
                printf("Neplatny smer\n");
                break;
        }
    }
}


void addTurtle(int turtlePositions[3][2], int* numberOfTurtles, int facingDirections[3][1]) {
    if(*numberOfTurtles < 3) {
        turtlePositions[*numberOfTurtles][0] = 0;
        turtlePositions[*numberOfTurtles][1] = 0;
        facingDirections[*numberOfTurtles][0] = 0;
        *numberOfTurtles += 1;
    }
}

int main(void) {
    int rows = 0, cols = 0;
    int numberOfTurtles = 1;
    int turtlesPositions[3][2];
    int running = 1;
    char choice = ' ';
    int facingDirections[3][1] = {{0},{0},{0}};
    
    scanf("%d %d", &rows, &cols);

    
    char* map = (char*) malloc(sizeof(char) * cols * rows);

    //KOD ZDE
    turtlesPositions[0][0] = 0;
    turtlesPositions[0][1] = 0;
    
    initializeMap(map, rows, cols);
    
    while(running) {
        scanf(" %c", &choice);
        
        switch(choice) {
            case 'r':
                for(int i = 0; i < numberOfTurtles; i++)
                    if(facingDirections[i][0] < 3) {
                        facingDirections[i][0]++;;
                    }
                    else {
                        facingDirections[i][0] = 0;
                    }
                break;
            case 'l':
                for(int i = 0; i < numberOfTurtles; i++)
                    if(facingDirections[i][0] > 0) {
                        facingDirections[i][0]--;
                    }
                    else {
                        facingDirections[i][0] = 3;
                    }
                break;
            case 'm':
                move(facingDirections, numberOfTurtles, turtlesPositions, rows, cols);
                break;
            case 'o':
                for(int i = 0; i < rows; i++) {
                    for(int j = 0; j < cols; j++) {
                        int isTurtle = 0;
                        int countOfTurtles = 0;
                        
                        for(int k = 0; k < numberOfTurtles; k++) {
                            if(turtlesPositions[k][0] == i && turtlesPositions[k][1] == j) {
                                isTurtle = 1;
                                countOfTurtles++;
                            }
                        }
                        
                        int index = i * cols + j;
                        
                        if(isTurtle && countOfTurtles % 2 == 0)
                            break;
                        
                        if(isTurtle && map[index] != 'o')
                            map[index] = 'o';
                        else if(isTurtle && map[index] == 'o')
                            map[index] = '.';
                        
                    }
                }
                break;
            case 'f':
                addTurtle(turtlesPositions, &numberOfTurtles, facingDirections);
                break;
            case 'x':
                running = 0;
                printMap(map, rows, cols, numberOfTurtles, turtlesPositions);
                break;
            default:
                printf("Neplatny znak\n");
                break;
        }
    }
    
    free(map);
    
    return 0;
}
