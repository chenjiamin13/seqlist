#include <stdio.h>

int last=7;//�����ЧԪ���±�

//1���������еڼ���λ�ò�������
void insertIntoA(int *p,int post,int data){
	//1.��last~postλ���±����ݣ����������ƶ�һ��λ��
	for(int i=last;i>=post;i--){
		p[i+1]=p[i];	
	}

	//2.��������data��ֵ��ָ������λ��
	p[post]=data;
	//���һ����ЧԪ���±�+1
	last++;
}

//2��������������ЧԪ��
void showA(int *p){
	int i;
	for(i=0;i<=last;i++){
		printf("%d ",p[i]);	
	}
	printf("\n");
}

//3��ɾ������ָ��λ�õ�����
void deleteFromA(int *p,int post){
	//��post+1~lastλ����ǰ�ƶ�һ��λ�ã�����ɾ��
	for(int i=post+1;i<=last;i++){//post����Ҫɾ�����ݵ��±�
		p[i-1]=p[i];
	}
	//�������Ԫ���±�-1
	last--;
}

int main()
{
	int a[100] = {1,2,3,4,5,6,7,8};
	insertIntoA(a,3,100); 
	//��ַ��������������±꣬���������
	showA(a);//1 2 3 100 4 5 6 7 8
	//�ող�����100
	deleteFromA(a,4);//ɾ���±�Ϊ4����
	showA(a);
	return 0;
}

