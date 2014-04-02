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
	int rch, lch;
	FILE * in = fopen("input.txt", "r");
	FILE * out = fopen("output.txt", "w");
	
	//Size�� �ް�, �����Ҵ�
	fscanf(in, "%d", &n);
	heap = (int*)malloc(sizeof(int)* (n + 1));


	//�Է� ����, �� parent������ �Է¹��� child���� ũ�� ���� switch�ؼ� Max Heap�� �����.
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
			{//MIN <-> MAX��ȯ�� ��� ��ȣ �ٲٱ�
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
	
	//Heap Sorting�� �Ѵ�.
	temp = front;
	while(1)
	{
		if(rear == front)//rear���� �����Ͽ� ������ �ö�� ��� ���� => ��� ���� ó���Ǿ���.
		{
			break;
		}
		
		while(1)
		{
			rch = (temp*2) + 1;
			lch = temp * 2;
			
			if(temp > rear )//���� ��ġ�� ���� ũ�⿡�� ����� Ž�� ��.
			{
				temp = front;//Ž����ġ �ʱ�ȭ
				if(heap[front] < heap[rear])
					swap(&heap[front], &heap[rear]);//�ִ밪�� rear�� �ٲ�.
				rear--;//rear�� ����
				
				break;
			}
			 
			if((heap[temp] < heap[lch] && heap[temp] < heap[rch]) || (rch > rear && lch > rear) )//RCH,LCH��ġ�� rear�� ����ų�, ���� ��ġ ���� LCH, RCH���� ������
			{//MIN <-> MAX��ȯ�� �տ� �� ��� ��ȣ �ٲٱ�
				temp = front;//Ž����ġ �ʱ�ȭ
				if(heap[front] < heap[rear])
					swap(&heap[front], &heap[rear]);//�ִ밪�� rear�� �ٲ�.
				rear--;//rear�� ����
				
				break;
			}
			else
			{
				if(heap[lch] < heap[rch] || rch > rear) // RCH��ġ ������ rear�� ����ų� LCH�� RCH���� ������
				{//MIN <-> MAX��ȯ�� ��� ��ȣ �ٲٱ�
					swap(&heap[lch], &heap[temp]);//�ִ밪�� LCH�� �ٲ�.
					temp = lch;//LCH�� �̵�
					break;
				}
				else if(heap[lch] > heap[rch] || lch < rear)// LCH��ġ ������ rear�� ����ų� RCH�� LCH���� ������
				{//MIN <-> MAX��ȯ�� ��� ��ȣ �ٲٱ�
					swap(&heap[rch], &heap[temp]);//�ִ밪�� RCH�� �ٲ�.
					temp = rch;//RCH�� �̵�
					break;
				}
			}
		}
	}

	for ( i = 1 ; i <= n ; i ++)
	{
		fprintf(out, "%d ", heap[i]);
	}

	free(heap);
	fclose(in);
	fclose(out);
	return 0;
}