/**************************************************************
*此为柔性数组创建斐波那契数列程序
*
*23/6/2019
*vincent you
*nanshan hi-tech park ShenZhen
***************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct FIBO_SHELL {
	int length;
	//int arr[];
	unsigned int array[];
	
}flexblearray;

flexblearray* assign_fibo(int size)
{
	flexblearray* ret = NULL;
	
	
	if(size<=0)
	{
		printf("please enter a positive integer!\n");
	}else{
		ret = (flexblearray*)malloc(sizeof(ret)+size*sizeof(*(ret->array)));//sizeof(ret)+size*sizeof(*(ret->array)) not sizeof(flexblearray)+size*sizeof(*(flexblearray->array)) 
		ret->length = size;
	}
	printf("ret's value = %x\n",ret);
	printf("ret's addr = %x\n",&ret);
	printf("sizeof ret = %d\n",sizeof(ret));
	printf("sizeof(*(ret->array)) = %d\n",sizeof(*(ret->array)));
	return ret;
}
	


void create_fibo(flexblearray* fp)
{
	int i;
	assert(fp!=NULL);
	
	if(fp->length<=0)
		{
			printf("fiboarray length can't be 0 or negative integer!\n");
		}
	else{
			if(1 == fp->length)
			fp->array[0] = 1;
			else
			{
				fp->array[0] = 1;
				fp->array[1] = 1;
				//一步达成？
				for(i=2;i<fp->length;i++)
				{
					fp->array[i] = fp->array[i-1] + fp->array[i-2];
				}
			}
		}
	
}

void print_fibo(flexblearray* fp)
{	
		int i;
		if(fp!=NULL)
		{
			for(i=0;i<fp->length;i++)
			{
				printf("%d ",fp->array[i]);
			}
		printf("\n");
		}
}

void free_fibo_space(flexblearray* fp)
{
	free(fp);
}

int main()
{
	int fibo_length = 10;
	flexblearray* pfibo = NULL;
	
	printf("pfibo's value = %x\n",pfibo);
	printf("pfibo's addr = %x\n",&pfibo);
	
	pfibo = assign_fibo(fibo_length);
	create_fibo(pfibo);
	print_fibo(pfibo);
	free_fibo_space(pfibo);
	
}