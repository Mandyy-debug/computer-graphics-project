#include <graphics.h>
#include <math.h>
#include <unistd.h> // for sleep()

// Function to draw tree (used for animation)
void drawTree(int x, int y, int colorLeaf)
{
    // Trunk
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(x, y + 50, x + 20, y + 100);
    floodfill(x + 5, y + 60, BROWN);

    // Leaves
    setcolor(colorLeaf);
    setfillstyle(SOLID_FILL, colorLeaf);
    fillellipse(x + 10, y + 30, 30, 30);
}

// Function to animate smoke rising (smooth & continuous)
void animateSmoke(int x, int y)
{
    for (int i = 0; i < 100; i += 5)
    {
        // Draw smoke puff
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        fillellipse(x, y - i, 18, 10);

        // Add a light gray outer puff for realism
        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        fillellipse(x + 5, y - i - 5, 22, 12);

        delay(100);

        // Erase lower smoke (but keep upper for continuous effect)
        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        fillellipse(x, y - i, 18, 10);
        fillellipse(x + 5, y - i - 5, 22, 12);
    }
}

// Draw beautiful nature
void drawBeautifulNature()
{
    setbkcolor(LIGHTBLUE);
    cleardevice();

    // Sun
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(550, 80, 40, 40);

    // Green land
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(0, 350, 640, 480);
    floodfill(10, 360, GREEN);

    // Trees
    for (int i = 100; i <= 500; i += 150)
        drawTree(i, 250, GREEN);

    // River
    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    ellipse(320, 400, 0, 360, 250, 40);
    floodfill(320, 400, CYAN);

    // Message
    setcolor(BLACK);
    settextstyle(3, 0, 2);
    outtextxy(120, 30, (char *)"Beautiful Nature Before Global Warming");
    delay(1500);
}

// Animate trees being cut (disappearing)
void animateTreeCut()
{
    for (int i = 100; i <= 500; i += 150)
    {
        drawTree(i, 250, GREEN);
        delay(150);

        // Simulate cutting: erase leaves + show dry branches
        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        bar(i - 10, 250, i + 40, 300);
        setcolor(DARKGRAY);
        line(i + 10, 300, i - 10, 270);
        line(i + 10, 300, i + 30, 270);
        delay(150);
    }
}

// Draw global warming effect with smooth smoke animation
void drawGlobalWarmingEffect()
{
    setbkcolor(LIGHTGRAY);
    cleardevice();

    // Hot Sun
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(550, 80, 40, 40);

    // Dry land
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(0, 350, 640, 480);
    floodfill(10, 360, BROWN);

    // Factories
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle(80, 250, 130, 350);
    floodfill(100, 300, DARKGRAY);
    rectangle(200, 230, 250, 350);
    floodfill(220, 300, DARKGRAY);

    // Animate smoke continuously while cutting trees
    for (int frame = 0; frame < 3; frame++)
    {
        animateSmoke(105, 230); // Left chimney smoke
        animateSmoke(225, 210); // Right chimney smoke

        if (frame == 1)
            animateTreeCut();
    }

    // Melted ice
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    fillellipse(500, 430, 40, 20);

    // Message
    setcolor(RED);
    settextstyle(3, 0, 2);
    outtextxy(100, 30, (char *)"Global Warming is Destroying Nature!");
    delay(2000);
}

// Prevention scene (restoration)
void drawPreventionScene()
{
    setbkcolor(LIGHTGREEN);
    cleardevice();

    // Sun (cooler)
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(550, 80, 30, 30);

    // Replanted trees
    for (int i = 100; i <= 500; i += 150)
    {
        drawTree(i, 250, GREEN);
        delay(200);
    }

    // Message
    setcolor(BLACK);
    settextstyle(3, 0, 2);
    outtextxy(60, 40, (char *)"Reduce Global Warming by Planting Trees!");
    outtextxy(80, 80, (char *)"Use Renewable Energy & Protect Nature!");
    delay(3000);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawBeautifulNature();
    cleardevice();

    drawGlobalWarmingEffect();
    cleardevice();

    drawPreventionScene();

    setcolor(BLUE);
    settextstyle(3, 0, 3);
    outtextxy(120, 220, (char *)"SAVE EARTH - STOP GLOBAL WARMING!");
    delay(4000);

    closegraph();
    return 0;
}
