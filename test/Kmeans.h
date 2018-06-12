#include"random.h"
#include<math.h>
#include<malloc.h>
#include<vector>
#define k 10
using namespace std;

/*
设计思路：
选择k个点作为初始均值
loop
	遍历每个点，形成k个簇
	重新计算每个簇的均值
until	簇不再发生变化，即均值保持不变
*/
//保存均值的结构
typedef struct 
{
	double x;
	double y;
}Mpt;
//计算质心与目标点之间的距离
float getDist(Mpt mean, Pt target);
//获取目标点属于的簇标志
int getFlag(Mpt *means, Pt target);
//随机设置k个初始均值
void getFirstMeans(Mpt *means);
//获取簇的均值
Mpt newMeans(vector<Pt> arr);
//判断新的均值是否与原来的相等
int Equals(Mpt *oldm, Mpt* newm);
//复制均值
void cpmeans(Mpt *oldm, Mpt *newm);
//输出最终得到的簇
void display(vector<vector<Pt> > arr);
//Kmeans算法
void Kmeans(Pt* Arr);



float getDist(Mpt mean, Pt target)
{
	float dist;
	dist = sqrt((mean.x - target.x) * (mean.x - target.x) + (mean.y - target.y) * (mean.y - target.y));
	return dist;
}

int getFlag(Mpt *means, Pt target)
{
	//计算出目标点关于均值的所有距离，最小的那个就是目标点所在簇的flag
	float dist = getDist(means[0], target);
	float temp;
	int flag = 0;

	for (int i = 1; i < k; i++)
	{
		temp = getDist(means[i], target);
		if (temp < dist)
		{
			dist = temp;
			flag = i;
		}
	}
	return flag;
}

void getFirstMeans(Mpt *means)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < k; i++)
	{
		means[i].x = rand() % 30000 + 1;
		means[i].y = rand() % 30000 + 1;
	}
}

Mpt newMeans(vector<Pt> arr)
{
	Mpt temp;

	temp.x = 0, temp.y = 0;
	for (int j = 0; j < arr.size(); j++)
	{
		temp.x += arr[j].x;
		temp.y += arr[j].y;
	}
	temp.x /= arr.size();
	temp.y /= arr.size();
	return temp;
}

int Equals(Mpt *oldm, Mpt* newm)
{
	//判断上一次得到的均值与新的均值是否相等，相等则说明已经完成聚类
	for (int i = 0 ;i < k; i++)
	{
		if (oldm[i].x != newm[i].x || oldm[i].y != newm[i].y)
			return 0;
	}
	return 1;
}

void cpmeans(Mpt *oldm, Mpt *newm)
{
	//复制当前的均值
	for (int i = 0; i < k; i++)
	{
		oldm[i].x = newm[i].x;
		oldm[i].y = newm[i].y;
	}
}

void display(vector<vector<Pt> > arr)
{
	for (int i = 0; i < k; i++)
	{
		printf("%d:\n", i);
		printf("{ ");
		for (int j = 0; j < arr[i].size(); j++)
		{
			printf("(%d, %d) ", arr[i][j].x, arr[i][j].y);
		}
		printf("}\n\n");
	}
}

void Kmeans(Pt* Arr)
{
	//创建Pt的二维数组保存数据
	vector<vector<Pt> > clusters(k);
	//均值数组
	Mpt means[k];
	//获取初始均值
	getFirstMeans(means);
	//记录上一次的均值
	Mpt oldm[k];
	//初始化旧均值数组
	for (int i = 0; i < k; i++)
	{
		oldm[i].x = 0;
		oldm[i].y = 0;
	}
	//目标点所在簇的标志
	int flag;
	//当新均值与旧均值不相等时继续循环
	while (Equals(oldm, means) == 0)
	{
		//将现在的均值赋值给旧均值数组
		cpmeans(oldm, means);
		//获取新的均值，if语句是避免第一次循环就初始化了均值
		if (clusters[0].size() > 0)
		{
			for (int i = 0; i < k; i++)
			{
				means[i] = newMeans(clusters[i]);
			}
		}
		//每一次循环都清空原来的簇
		for (int i = 0; i < k; i++)
		{
			clusters[i].clear();
		}
		//遍历数据，然后进行聚类
		for (int i = 0; i < 1000; i++)
		{
			flag = -1;
			flag = getFlag(means, Arr[i]);
			clusters[flag].push_back(Arr[i]);
		}
	}
	//完成算法，输出结果
	display(clusters);
}