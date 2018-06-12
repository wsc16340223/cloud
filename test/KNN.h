#include"random.h"
#include<math.h>
#define k 100

//存储最近邻的结构体，保存距离和id
typedef struct 
{
	float dist;
	int id;
}ans;

//计算两个点之间的距离
float getDist(Pt target, Pt other);
//交换函数
void swap(ans* a, ans* b);
//冒泡排序
void bubble(ans *array);
//排序方法，用于调整最近邻
void SORT(ans *array);
//计算knn，并将结果保存在结构数组myKNN中
void findKNN(ans* myKNN, Pt* Arr, Pt target);
//输出函数，输出KNN的id
void display(ans *array);


float getDist(Pt target, Pt other)
{
	float dist;
	dist = sqrt((target.x - other.x) * (target.x - other.x) + (target.y - other.y) * (target.y - other.y));
	return dist;
}

void swap(ans* a, ans* b)
{
	ans *temp = malloc(sizeof(ans));
	temp->dist = a->dist, temp->id = a->id;
	a->dist = b->dist, a->id = b->id;
	b->dist = temp->dist, b->id = temp->id;
}

void bubble(ans *array)
{
	ans temp;
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = 0; j < k - 1 - i; j++)
		{
			if (array[j].dist > array[j + 1].dist)
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

void SORT(ans *array)
{
	for (int i = k - 1; i > 0; i--)
	{
		if (array[i].dist < array[i - 1].dist)
		{
			swap(&array[i], &array[i - 1]);
		}
		else
			break;
	}
}

void findKNN(ans* myKNN, Pt* Arr, Pt target)
{
	ans temp;
	for (int i = 0; i < k; i++)
	{
		temp.dist = getDist(target, Arr[i]);
		temp.id = i;
		myKNN[i] = temp;
	}

	bubble(myKNN);


	for (int i = k; i < 1000; i++)
	{
		temp.dist = getDist(target, Arr[i]);
		if (temp.dist < myKNN[k - 1].dist)
		{
			temp.id = i;
			myKNN[k - 1] = temp;
			SORT(myKNN);
		}
	}
}

void display(ans *array)
{
	for (int i = 0; i < k; i++)
	{
		printf("%d ", array[i].id);
	}
	printf("\n");
}