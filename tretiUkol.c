#include "drawing.h"

// Zadani
void printLine(int dots);
void printStairs(int count);
void printFlower(int width, int height);
void printMeadow(int rows, int columns);
void printAnimation();

// Vlastni
void printLines();
void printFlowers();
void printVerticalLine(int length);
void printHorizontalLine(int length);
void changeColor(int color);

int main() {
    clear_screen();
    
    int drawing = 0;
    scanf("%d", &drawing);
    
    clear_screen();
    
    switch (drawing) {
        case 0:
            printLines();
            break;
        case 1:
            printStairs(5);
            break;
        case 2:
            printFlowers();
            break;
        case 3:
            printMeadow(2, 10);
            break;
        case 4:
            printAnimation();
            break;
        default:
            break;
    }
    end_drawing();
    
    return 0;
}
void changeColor(int color) {
    switch (color) {
        case 0:
            set_red_color();
            break;
        case 1:
            set_green_color();
            break;
        case 2:
            set_blue_color();
            break;
        case 3:
            set_yellow_color();
            break;
        case 4:
            set_white_color();
            break;
        case 5:
            set_black_color();
            break;
        default:
            changeColor(10 % color);
            break;
    }
}
void printDottedLine(int dots) {
    for (int i = 0; i < dots; i++) {
        draw_pixel();
        move_right();
        move_right();
    }
}
void printVerticalLine(int length) {
    for (int i = 0; i < length; i++) {
        draw_pixel();
        move_down();
    }
}
void printHorizontalLine(int length) {
    for (int i = 0; i < length; i++) {
        draw_pixel();
        move_right();
    }
}
void printLines() {
    for (int i = 1; i <= 6; i++) {
        changeColor(i);
        move_to(i * 3, i * 3);
        printDottedLine(i * 4);
    }
}
void printStairs(int count) {
    for (int i = 0; i < count; i++) {
        changeColor(i);
        printHorizontalLine(5 + i);
        printVerticalLine(3 + i);
    }
}
void printFlower(int width, int height) {
    set_green_color();
    for (int i = 0; i < height / 2; i++) {
        draw_pixel();
        move_up();
    }
    set_yellow_color();
    draw_pixel();
    set_red_color();
    for (int i = 0; i < width / 2; i++) {
        move_right();
        draw_pixel();
    }
    for (int i = 0; i < width / 2; i++) {
        move_left();
    }
    for (int i = 0; i < width / 2; i++) {
        move_left();
        draw_pixel();
    }
    for (int i = 0; i < width / 2; i++) {
        move_right();
    }
    move_up();
    for (int i = 0; i < height / 2; i++) {
        draw_pixel();
        move_up();
    }
}
void printFlowers() {
    move_to(10, 10);
    for (int i = 6; i < 5 + 5; i++) {
        printFlower(i + 3, i + 3);
        for (int j = 0; j < i + 8; j++) {
            move_down();
            move_right();
        }
    }
}
void printMeadow(int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            move_to(i * 6 + 5, j * 6 + 5);
            printFlower(5, 5);
        }
    }
}
void printAnimatedLine(int length, int pixelPos) {
    for (int i = 0; i < length; i++) {
        if (i == pixelPos) {
            set_blue_color();
        }
        draw_pixel();
        move_down();
        set_white_color();
    }
}
void printLogo(int lineIndex, int bluePixel) {
    set_white_color();
    move_to(10, 10);
    if (lineIndex == 0) {
        printAnimatedLine(5, bluePixel);
    } else {
        printVerticalLine(5);
    }
    for (int i = 0; i < 3; i++) {
        move_up();
    }
    for (int i = 0; i < 4; i++) {
        move_right();
    }
    if (lineIndex == 1) {
        printAnimatedLine(5, bluePixel);
    } else {
        printVerticalLine(5);
    }
    for (int i = 0; i < 3; i++) {
        move_up();
    }
    for (int i = 0; i < 4; i++) {
        move_right();
    }
    if (lineIndex == 2) {
        printAnimatedLine(5, bluePixel);
    } else {
        printVerticalLine(5);
    }
    for (int i = 0; i < 7; i++) {
        move_up();
    }
    for (int i = 0; i < 4; i++) {
        move_right();
    }
    if (lineIndex == 3) {
        printAnimatedLine(5, bluePixel);
    } else {
        printVerticalLine(5);
    }
    for (int i = 0; i < 7; i++) {
        move_up();
    }
    for (int i = 0; i < 4; i++) {
        move_right();
    }
    if (lineIndex == 4) {
        printAnimatedLine(5, bluePixel);
    } else {
        printVerticalLine(5);
    }
}
void printAnimation() {
    int bluePixel = 0;
    int lineIndex = 0;
    while (1) {
        clear_screen();
        printLogo(lineIndex, bluePixel);
        animate();
        if (bluePixel + 1 < 5) {
            bluePixel++;
        } else {
            bluePixel = 0;
            if (lineIndex + 1 < 5)
                lineIndex++;
            else
                lineIndex = 0;
        }
    }
}
