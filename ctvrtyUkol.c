#include <stdio.h>
#define ARRAY_SIZE 1000

int getDigitCount(int number) {
    int digitCount = 1;

    while(number >= 10) {
        number /= 10;
        digitCount++;
    }

    return digitCount;
}

int getNumberCount(int* arr, int countOfNumbers, int number) {
    int result = 0;

    for(int i = 0; i < countOfNumbers; i++) {
        if(arr[i] == number)
            result++;
    }

    return result;
}

int getInvalidCount(int* arr, int countOfNumbers, int range) {
    int invalid = 0;

    for(int i = 0; i < countOfNumbers; i++) {
        if(!(arr[i] >= range && arr[i] <= range + 8)) {
            invalid++;
        }
    }
    return invalid;
}

void printHorizontalGraph(int* numbers, int countOfNumbers, int range) {
    int mostDigits = getDigitCount(range + 8);

    for(int i = range; i <= range + 8; i++) {
        for(int j = 0; j < mostDigits - getDigitCount(i); j++) {
            printf(" ");
        }
        printf("%d", i);

        if(getNumberCount(numbers, countOfNumbers, i) > 0)
            printf(" ");

        for(int j = 0; j < getNumberCount(numbers, countOfNumbers, i); j++) {
            printf("#");
        }
        printf("\n");
    }

    if(getInvalidCount(numbers, countOfNumbers, range) > 0) {
        printf("invalid: ");
        for(int i = 0; i < getInvalidCount(numbers, countOfNumbers, range); i++) {
            printf("#");
        }
        printf("\n");
    }
}

void printVerticalGraph(int* numbers, int countOfNumbers) {
    int modusCount = 0;
    int invalid = 0;

    for(int i = 0; i < countOfNumbers; i++) {
        if(numbers[i] > 9)
            invalid++;
    }

    for(int i = 0; i < countOfNumbers; i++) {
        int count = getNumberCount(numbers, countOfNumbers, numbers[i]);
        if(count > modusCount)
            modusCount = count;
    }

    if(invalid > modusCount) 
        modusCount = invalid; 

    for(int i = modusCount; i > 0; i--) {
        if(modusCount - invalid <= i)
            printf("#");
        else
            printf(" ");

        for(int j = 1; j <= 9; j++) {
            if(getNumberCount(numbers, countOfNumbers, j) >= i)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
    
    printf("i");
    for(int i = 1; i <= 9; i++) {
        printf("%d", i);
    }
    printf("\n");
}


int main(void) {
    int countOfNumbers = 0, range = 0;
    char direction = '0';
    int numbers[ARRAY_SIZE];

    scanf("\n%c", &direction);

    if(direction != 'h' && direction != 'v') {
        printf("Neplatny mod vykresleni\n");
        return 1;
    }

    scanf("\n %d %d", &countOfNumbers, &range);

    if(countOfNumbers < 0 || range < 0) {
        printf("Zadana cisla musi byt nezaporna");
        return 1;
    }

    for (int i = 0; i < countOfNumbers; i++) {
        scanf("%d", &numbers[i]);
    }

    if(direction == 'h')
        printHorizontalGraph(numbers, countOfNumbers, range);
    else if(direction == 'v')
        printVerticalGraph(numbers, countOfNumbers);


    return 0;
}
