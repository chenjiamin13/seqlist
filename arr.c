#include <stdio.h>

//1、向数组中第几个位置插入数据
//int *p:保存数组首元素地址
//int post:位置
//int data:数据
//int n:表示数组有效元素个数
void insertIntoA(int *p,int n,int post,int data){
	//1.将n-1~post位置下标数据，整体往后移动一个位置
	for(int i=n-1;i>=post;i--){
		p[i+1]=p[i];	
	}

	//2.将新数据data赋值到指定数组位置
	p[post]=data;
}

//2、遍历数组中有效元素
void showA(int *p,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",p[i]);	
	}
	printf("\n");
}

//3、删除数组指定位置的数据
void deleteFromA(int *p,int n,int post){
	//从post+1~n-1位置向前移动一个位置，覆盖删除
	for(int i=post+1;i<=n-1;i++){//post就是要删除数据的下标
		p[i-1]=p[i];
	}
}

int main()
{
	int a[100] = {1,2,3,4,5,6,7,8};
	insertIntoA(a,8,3,100); 
	//地址，个数，插入的下标，插入的数据
	showA(a,9);//1 2 3 100 4 5 6 7 8
	//刚刚插入了100
	deleteFromA(a,9,4);//删除下标为4的数
	showA(a,8);
	return 0;
}

