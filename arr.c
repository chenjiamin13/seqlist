#include <stdio.h>

//1���������еڼ���λ�ò�������
//int *p:����������Ԫ�ص�ַ
//int post:λ��
//int data:����
//int n:��ʾ������ЧԪ�ظ���
void insertIntoA(int *p,int n,int post,int data){
	//1.��n-1~postλ���±����ݣ����������ƶ�һ��λ��
	for(int i=n-1;i>=post;i--){
		p[i+1]=p[i];	
	}

	//2.��������data��ֵ��ָ������λ��
	p[post]=data;
}

//2��������������ЧԪ��
void showA(int *p,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",p[i]);	
	}
	printf("\n");
}

//3��ɾ������ָ��λ�õ�����
void deleteFromA(int *p,int n,int post){
	//��post+1~n-1λ����ǰ�ƶ�һ��λ�ã�����ɾ��
	for(int i=post+1;i<=n-1;i++){//post����Ҫɾ�����ݵ��±�
		p[i-1]=p[i];
	}
}

int main()
{
	int a[100] = {1,2,3,4,5,6,7,8};
	insertIntoA(a,8,3,100); 
	//��ַ��������������±꣬���������
	showA(a,9);//1 2 3 100 4 5 6 7 8
	//�ող�����100
	deleteFromA(a,9,4);//ɾ���±�Ϊ4����
	showA(a,8);
	return 0;
}

