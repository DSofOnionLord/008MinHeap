#include <stdio.h>
#include <stdlib.h>

//값 바꿔주기
void swap(int *a, int *b)
{
	int temp = (*a);
	(*a) = (*b);
	(*b) = temp;
}

int main()
{
	int *heap;
	int n;
	int i;
	int temp;
	int front;
	int rear;
	int size = 1;
	FILE * in = fopen("input.txt", "r");
	FILE * out = fopen("output.txt", "w");
	
	//Size를 받고, 동적할당
	fscanf(in, "%d", &n);
	heap = (int*)malloc(sizeof(int)* (n + 1));


	//입력 받음, 단 parent값보다 입력받은 child값이 크면 서로 switch해서 Min Heap로 만든다.
	for ( i = 1 ; i <= n ; i ++ )
	{
		fscanf(in, "%d", &heap[i]);
		temp = i;//입력받는 위치 손실을 막기위해 임시로 지정.
		while(1)
		{
			if( temp == 1 ) //현재 입력받는 값이 root값이거나, 해당 값이 root에 도달할때는 while중단.
			{
				break;
			}
			else if(heap[temp] < heap[temp/2])//parent값보다 현재 child값이 작을때 바꿔준다. =>부호만 바꾸면 max heap!
			{
				swap(&heap[temp], &heap[temp/2]);
				temp /= 2; //parent로 값이 이동.
			}
			else//parent값보다 현재 child값이 작을때
			{
				break;
			}
		}
	}

	front = 1;
	rear = n;
	
	for ( i = 1 ; i <= n ; i ++)
	{
		fprintf(out, "%d %d\n", i, heap[i]);
	}

	free(heap);
	fclose(in);
	fclose(out);
	return 0;
}