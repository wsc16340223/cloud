#include"KNN.h"
#include<malloc.h>

void testKNN()
{
	ans *myKNN = malloc(sizeof(ans) * k);
	Pt target1;

	int num = 10;
	for (int i = 0; i < num; i++)
	{
		target1.x = rand() % 30000 + 1;
		target1.y = rand() % 30000 + 1;

		findKNN(myKNN, Arr, target1);
		display(myKNN);
		printf("\n");
	}
	free(myKNN);
}

int main(int argc, char const *argv[])
{
	readData();
	testKNN();
	return 0;
}