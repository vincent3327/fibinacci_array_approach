/**************************************************************
*此为 温习 柔性数组创建斐波那契数列程序
*空指针malloc对应长度后才可赋值操作
scanf 不能再来个 \n
*10/11/2019
*vincent you
*xm interchange futian ShenZhen
***************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//define struct which includes flexible array
typedef struct flex_array_tag{
int length;
unsigned int fibo_array[];
}flex_array;


//create flexible array
flex_array* create_fibo_with_given_length(int len,flex_array *ptr)
{
	assert(0<len);
	
	ptr = (flex_array*)malloc(sizeof(flex_array) + len*sizeof(*(ptr->fibo_array)));
	ptr->length = len;
	if(1==len)
	{
		ptr->fibo_array[0] = 1;
		
	}
	else{
		ptr->fibo_array[0] = 1;
		ptr->fibo_array[1] = 1;
		for(int i = 2;i<len;i++)
		{
			ptr->fibo_array[i] = ptr->fibo_array[i-1] + ptr->fibo_array[i-2];
		}
		return ptr;
	}
}

//func to print fibonacci array
void printfibo(flex_array *ptr)
{
	for(int i = 0;i<ptr->length;i++)
	//printf("%d ",*(ptr->fa+i));
	printf("%d ",ptr->fibo_array[i]);
	printf("\n");
}

//free memories that applied before
void freefibo(flex_array * fp)
{
	free(fp);
}

//main function
int main()
{
	int length_of_fibonacci;
	flex_array *fibo1_ptr = NULL;
	printf("please enter the number of fibonacci array you want\n");
	scanf("%d",&length_of_fibonacci);
	printf("the length of fibonacci you want is %d\n",length_of_fibonacci);
	//length_of_fibonacci = 3;
	fibo1_ptr = create_fibo_with_given_length(length_of_fibonacci,fibo1_ptr);
	printfibo(fibo1_ptr);
	freefibo(fibo1_ptr);
	
}