#include <stdio.h>
#include "seqlist.h"

//1.创建一个空的顺序表
seqlist_t* CreateEpSeqlist()//返回的是申请空间的首地址
{
	//动态申请一块空间
	seqlist_t* p = (seqlist_t*)malloc(sizeof(seqlist_t));
	//sizeof(seqlist_t)计算结构体的大小
	if (p == NULL) {
		printf("申请空顺序表错误\n");
		return NULL;
	}
	//last是最后一个有效元素的下标
	p->last = -1;//空
	return p;
}

//4.判断顺序表是否为满,满返回１ 未满返回０
int IsFullSeqlist(seqlist_t* p)
{
	return p->last + 1 == N;//成立返回1（满），不成立返回0
}

//2.向顺序表的指定位置插入数据
int InsertIntoSeqlist(seqlist_t* p, int post, int data)//post第几个位置，data插入的数据
{
	//1、容错判断
	//小于最小，大于最大；顺序表满了帮你插入
	if (post<0 || post>p->last+1|| IsFullSeqlist(p)) {
		printf("插入失败\n");
		return -1;//错误返回
	}
	//2、last-post往后移动一个位置
	int i;
	for (i = p->last; i >= post; i--) {
		p->data[i + 1] = p->data[i];
	}
	//3、插入数据
	p->data[post] = data;
	//4、p->last+1
	p->last++;
	return 0;
}



//3.遍历顺序表sequence 顺序 list 表
void ShowSeqlist(seqlist_t* p)
{
	int i;
	for (i = 0; i <= p->last; i++) {
		printf("%d ", p->data[i]);
	}
	printf("\n");
}

//5.判断顺序表是否为空
int IsEpSeqlist(seqlist_t* p)
{
	return p->last == -1;
}

//6.删除顺序表中指定位置的数据post删除位置
int DeletePostSeqlist(seqlist_t* p, int post)
{
	//1、容错判断
	if (post > p->last || post < 0 || IsEpSeqlist(p)) {
		printf("删除失败\n");
		return -1;
	}
	//2、post+1-last向前移动一个位置
	int i;
	for (i = post + 1; i <= p->last; i++) {
		p->data[i - 1] = p->data[i];
	}
	//3、有效元素-1
	p->last--;
	return 0;
}

//7.清空顺序表（清空：访问不到，但内存当中还有;销毁：内存清空）
void ClearSeqList(seqlist_t* p)
{
	p->last = -1;
}

//8.修改指定位置的数据
int ChangePostSeqList(seqlist_t* p, int post, int data)//post被修改的位置，data修改成的数据
{
	//1、容错判断
	if (post<0 || post>p->last) {
		printf("修改失败\n");
		return -1;
	}
	//2、修改指定位置数据
	p->data[post] = data;
}

//9.查找指定数据出现的位置
int SearchDataSeqList(seqlist_t* p, int data)//data代表被查找的数据
{
	int i;
	for (i = 0; i <= p->last; i++) {
		if (p->data[i] == data) {
			return i;
		}
	}
	return -1;
}


