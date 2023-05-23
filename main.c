#include <stdio.h>
#include "seqlist.h"

int main()
{
	seqlist_t* p = CreateEpSeqlist();//����һ���յ�˳���
	InsertIntoSeqlist(p, 0, 1);
	InsertIntoSeqlist(p, 1, 2);
	InsertIntoSeqlist(p, 2, 3);
	InsertIntoSeqlist(p, 3, 4);
	ShowSeqlist(p);//1 2 3 4
	DeletePostSeqlist(p, 1);
	ShowSeqlist(p);//1 3 4
	ChangePostSeqList(p, 1, 100);
	ShowSeqlist(p);//1 100 4
	int t;//�нӲ������ݵ��±�
	t=SearchDataSeqList(p, 100);
	printf("%d\n", t);//1
	return 0;
}

