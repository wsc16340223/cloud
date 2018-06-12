#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//存储点的结构体，坐标x，y
typedef struct 
{
    int x;
    int y;
}Pt;
//坐标样本，一共1000个
Pt Arr[1000];
//创建随机坐标并且保存在文件中
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

    printf("Done!\n");
    fclose(file);
}
//读取文件中的坐标保存在数组里
void readData()
{
    FILE *file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("open file error!\n");
        exit(0);
    }

    char ch1, ch2;

    for (int i = 0; i < 1000; i++)
    {
        fscanf(file, "%d%c%d%c", &Arr[i].x, &ch1, &Arr[i].y, &ch2);
    }

    fclose(file);
}