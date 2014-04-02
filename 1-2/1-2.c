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
	int rch, lch;
	FILE * in = fopen("input.txt", "r");
	FILE * out = fopen("output.txt", "w");
	
	//Size를 받고, 동적할당
	fscanf(in, "%d", &n);
	heap = (int*)malloc(sizeof(int)* (n + 1));


	//입력 받음, 단 parent값보다 입력받은 child값이 크면 서로 switch해서 Max Heap로 만든다.
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
			{//MIN <-> MAX변환시 등식 부호 바꾸기
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
	
	//Heap Sorting을 한다.
	temp = front;
	while(1)
	{
		if(rear == front)//rear값이 감소하여 끝까지 올라온 경우 종료 => 모든 값이 처리되었다.
		{
			break;
		}
		
		while(1)
		{
			rch = (temp*2) + 1;
			lch = temp * 2;
			
			if(temp > rear )//값의 위치가 원래 크기에서 벗어나면 탐색 끝.
			{
				temp = front;//탐색위치 초기화
				if(heap[front] < heap[rear])
					swap(&heap[front], &heap[rear]);//최대값과 rear값 바꿈.
				rear--;//rear값 감소
				
				break;
			}
			 
			if((heap[temp] < heap[lch] && heap[temp] < heap[rch]) || (rch > rear && lch > rear) )//RCH,LCH위치가 rear을 벗어나거나, 현재 위치 값이 LCH, RCH보다 작을때
			{//MIN <-> MAX변환시 앞에 두 등식 부호 바꾸기
				temp = front;//탐색위치 초기화
				if(heap[front] < heap[rear])
					swap(&heap[front], &heap[rear]);//최대값과 rear값 바꿈.
				rear--;//rear값 감소
				
				break;
			}
			else
			{
				if(heap[lch] < heap[rch] || rch > rear) // RCH위치 범위가 rear을 벗어나거나 LCH가 RCH보다 작을때
				{//MIN <-> MAX변환시 등식 부호 바꾸기
					swap(&heap[lch], &heap[temp]);//최대값과 LCH값 바꿈.
					temp = lch;//LCH로 이동
					break;
				}
				else if(heap[lch] > heap[rch] || lch < rear)// LCH위치 범위가 rear을 벗어나거나 RCH가 LCH보다 작을때
				{//MIN <-> MAX변환시 등식 부호 바꾸기
					swap(&heap[rch], &heap[temp]);//최대값과 RCH값 바꿈.
					temp = rch;//RCH로 이동
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