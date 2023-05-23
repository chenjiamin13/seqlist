#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct
{
	int data[N];
	int last;//last����������������һ����ЧԪ�ص��±�
}seqlist_t;

//1.����һ���յ�˳���
seqlist_t* CreateEpSeqlist();//���ص�������ռ���׵�ַ
//2.��˳����ָ��λ�ò�������
int InsertIntoSeqlist(seqlist_t* p, int post, int data);//post�ڼ���λ�ã�data���������
//3.����˳���sequence ˳�� list ��
void ShowSeqlist(seqlist_t* p);
//4.�ж�˳����Ƿ�Ϊ��,�����أ� δ�����أ�
int IsFullSeqlist(seqlist_t* p);
//5.�ж�˳����Ƿ�Ϊ��
int IsEpSeqlist(seqlist_t* p);
//6.ɾ��˳�����ָ��λ�õ�����postɾ��λ��
int DeletePostSeqlist(seqlist_t* p, int post);
//7.���˳���
void ClearSeqList(seqlist_t* p);
//8.�޸�ָ��λ�õ�����
int ChangePostSeqList(seqlist_t* p, int post, int data);//post���޸ĵ�λ�ã�data�޸ĳɵ�����
//9.����ָ�����ݳ��ֵ�λ��
int SearchDataSeqList(seqlist_t* p, int data);//data�������ҵ�����
#endif