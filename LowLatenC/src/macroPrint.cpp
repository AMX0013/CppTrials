#include<stdio.h>
#include<stdlib.h>

#define Print(x,size) for(int i = 0 ; i < size ; i++){\
                        printf("%d\n",*x);\
                        x++;\
                        }

int arr[] = {10,20,30,40,50,60,70,80,90};

int main(){
	int *p = arr;
	int size = sizeof(arr)/sizeof(arr[0]);
	Print(p,size);
	getchar();
	return 0;
}