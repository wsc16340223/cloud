#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct Pt
{
    int x;
    int y;
};

Pt Arr[1000];

void createData()
{
    FILE *file = fopen("data.txt", "w");

    int i = 0;

    srand((unsigned int)time(NULL));

    int a, b;
    char ch = ' ';
    for (int i = 0; i < 1000; i++)
    {
        a = rand() % 30000 + 1;
        b = rand() % 30000 + 1;
        fprintf(file, "%d%c%d%c", a, ch, b, ch);
    }

    fclose(file);
}

void readData()
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("open file error!\n");
        exit(0);
    }

    char ch;

    for (int i = 0; i < 1000; i++)
    {
        fscanf(file, "%d%c%d%c", Arr[i].x, ch, Arr[i].y, ch);
    }

    fclose(file);
}