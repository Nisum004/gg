#include <iostream>
#include <graphics.h>
#include <windows.h>

bool buttonPressed = false;

void drawButton() {
    setcolor(WHITE);
    rectangle(250, 200, 450, 350);
    outtextxy(270, 220, "FACE DETECTOR");
}

void handleMouseClick(int mx, int my) {
    if (mx >= 250 && mx <= 450 && my >= 200 && my <= 350) {
        // Button is clicked
        buttonPressed = true;
    }
}

int main() {
    initwindow(600, 500, "BUTTON");

    while (!buttonPressed) {
        cleardevice();
        drawButton();

        int mx, my;
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            handleMouseClick(mx, my);
        }

        delay(100);
    }

    closegraph();
    return 0;
}
