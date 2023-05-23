#include <stdio.h>
#include "seqlist.h"

//1.����һ���յ�˳���
seqlist_t* CreateEpSeqlist()//���ص�������ռ���׵�ַ
{
	//��̬����һ��ռ�
	seqlist_t* p = (seqlist_t*)malloc(sizeof(seqlist_t));
	//sizeof(seqlist_t)����ṹ��Ĵ�С
	if (p == NULL) {
		printf("�����˳������\n");
		return NULL;
	}
	//last�����һ����ЧԪ�ص��±�
	p->last = -1;//��
	return p;
}

//4.�ж�˳����Ƿ�Ϊ��,�����أ� δ�����أ�
int IsFullSeqlist(seqlist_t* p)
{
	return p->last + 1 == N;//��������1������������������0
}

//2.��˳����ָ��λ�ò�������
int InsertIntoSeqlist(seqlist_t* p, int post, int data)//post�ڼ���λ�ã�data���������
{
	//1���ݴ��ж�
	//С����С���������˳������˰������
	if (post<0 || post>p->last+1|| IsFullSeqlist(p)) {
		printf("����ʧ��\n");
		return -1;//���󷵻�
	}
	//2��last-post�����ƶ�һ��λ��
	int i;
	for (i = p->last; i >= post; i--) {
		p->data[i + 1] = p->data[i];
	}
	//3����������
	p->data[post] = data;
	//4��p->last+1
	p->last++;
	return 0;
}



//3.����˳���sequence ˳�� list ��
void ShowSeqlist(seqlist_t* p)
{
	int i;
	for (i = 0; i <= p->last; i++) {
		printf("%d ", p->data[i]);
	}
	printf("\n");
}

//5.�ж�˳����Ƿ�Ϊ��
int IsEpSeqlist(seqlist_t* p)
{
	return p->last == -1;
}

//6.ɾ��˳�����ָ��λ�õ�����postɾ��λ��
int DeletePostSeqlist(seqlist_t* p, int post)
{
	//1���ݴ��ж�
	if (post > p->last || post < 0 || IsEpSeqlist(p)) {
		printf("ɾ��ʧ��\n");
		return -1;
	}
	//2��post+1-last��ǰ�ƶ�һ��λ��
	int i;
	for (i = post + 1; i <= p->last; i++) {
		p->data[i - 1] = p->data[i];
	}
	//3����ЧԪ��-1
	p->last--;
	return 0;
}

//7.���˳�����գ����ʲ��������ڴ浱�л���;���٣��ڴ���գ�
void ClearSeqList(seqlist_t* p)
{
	p->last = -1;
}

//8.�޸�ָ��λ�õ�����
int ChangePostSeqList(seqlist_t* p, int post, int data)//post���޸ĵ�λ�ã�data�޸ĳɵ�����
{
	//1���ݴ��ж�
	if (post<0 || post>p->last) {
		printf("�޸�ʧ��\n");
		return -1;
	}
	//2���޸�ָ��λ������
	p->data[post] = data;
}

//9.����ָ�����ݳ��ֵ�λ��
int SearchDataSeqList(seqlist_t* p, int data)//data�������ҵ�����
{
	int i;
	for (i = 0; i <= p->last; i++) {
		if (p->data[i] == data) {
			return i;
		}
	}
	return -1;
}


