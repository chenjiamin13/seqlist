#include <stdio.h>

int last=7;//最后有效元素下标

//1、向数组中第几个位置插入数据
void insertIntoA(int *p,int post,int data){
	//1.将last~post位置下标数据，整体往后移动一个位置
	for(int i=last;i>=post;i--){
		p[i+1]=p[i];	
	}

	//2.将新数据data赋值到指定数组位置
	p[post]=data;
	//最后一个有效元素下标+1
	last++;
}

//2、遍历数组中有效元素
void showA(int *p){
	int i;
	for(i=0;i<=last;i++){
		printf("%d ",p[i]);	
	}
	printf("\n");
}

//3、删除数组指定位置的数据
void deleteFromA(int *p,int post){
	//从post+1~last位置向前移动一个位置，覆盖删除
	for(int i=post+1;i<=last;i++){//post就是要删除数据的下标
		p[i-1]=p[i];
	}
	//最后有限元素下标-1
	last--;
}

int main()
{
	int a[100] = {1,2,3,4,5,6,7,8};
	insertIntoA(a,3,100); 
	//地址，个数，插入的下标，插入的数据
	showA(a);//1 2 3 100 4 5 6 7 8
	//刚刚插入了100
	deleteFromA(a,4);//删除下标为4的数
	showA(a);
	return 0;
}

