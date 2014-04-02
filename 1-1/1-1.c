#include <stdio.h>
#include <stdlib.h>

//�� �ٲ��ֱ�
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
	
	//Size�� �ް�, �����Ҵ�
	fscanf(in, "%d", &n);
	heap = (int*)malloc(sizeof(int)* (n + 1));


	//�Է� ����, �� parent������ �Է¹��� child���� ũ�� ���� switch�ؼ� Min Heap�� �����.
	for ( i = 1 ; i <= n ; i ++ )
	{
		fscanf(in, "%d", &heap[i]);
		temp = i;//�Է¹޴� ��ġ �ս��� �������� �ӽ÷� ����.
		while(1)
		{
			if( temp == 1 ) //���� �Է¹޴� ���� root���̰ų�, �ش� ���� root�� �����Ҷ��� while�ߴ�.
			{
				break;
			}
			else if(heap[temp] < heap[temp/2])//parent������ ���� child���� ������ �ٲ��ش�. =>��ȣ�� �ٲٸ� max heap!
			{
				swap(&heap[temp], &heap[temp/2]);
				temp /= 2; //parent�� ���� �̵�.
			}
			else//parent������ ���� child���� ������
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