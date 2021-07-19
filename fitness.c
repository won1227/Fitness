#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int num;
	char name[20];
	double weight;
}Fitness;

Fitness* ary[100];									//�����͹迭 ����
void total_number(int count);						//��ü ��� ȸ�� �� ��ȯ	/	void�� ���� ���� ����.
double average_weight(Fitness** pary, int count);	//��� ü�� ��ȯ
int max_weight(Fitness** pary, int count);			//�ִ� ü�� ȸ���� index��ȯ
void print_info(Fitness** pary, int index);			//ȸ�� ���� ���
void free_ary(Fitness** pary, int count);			//���� �Ҵ� ���� ����

int main()
{
	Fitness* ary[100];
	int i,k;
	int index;
	
	printf("������ ȸ�� �� : ");
	scanf("%d", &k);
	printf("\n");

	for (i = 0; i < k; i++)
	{

		ary[i] = (Fitness*)malloc(sizeof(Fitness));	//Fitness�迭 ���� ���� ���� �Ҵ�

		printf("ȸ������ : ");
		scanf("%d", &ary[i]->num);					//�迭 i ���� �� �Է¹��� ���� num�� �����Ѵ�.
		if (ary[i]->num < 0) break;					// ���� �϶� �극��ũ, ȸ������ �Է� �ؿ� �־�� �ٸ� ���� ������ �ȳְ� �ٷ� ������ �� �ִ�.
		printf("%d\n", ary[i]->num);				//�迭 i ������ ����� num ���� ����Ѵ�.(ȸ������)
		printf("�̸� : ");
		scanf("%s", &ary[i]->name);					//�迭 i ���� �� �Է¹��� ���� name�� �����Ѵ�.					
		printf("%s\n", ary[i]->name);				//�迭 i ���� �� ����� ���� ����Ѵ�.(�̸�����)
		printf("���� : ");
		scanf("%lf", &ary[i]->weight);				//�迭 i ���� �� �Է¹��� ���� weight�� �����Ѵ�.
		printf("%.1lf\n\n", ary[i]->weight);		//�迭 i ���� �� ����� ���� weight�� �����Ѵ�.

	}
	total_number(i);								//void total_number(int count)���� count ���� for���� ���� i ��ŭ ����Ѵ�.
	printf("��� ��  : %.1lf\n", average_weight(ary, i));
	index = max_weight(ary, i);
	printf("�ִ� ������ ȸ�� ��ȣ: %d\n", index);		//max_weight(ary,i));
	print_info(ary, index);
	free_ary(ary, i);


	return 0;
}


void total_number(int count)						//void�� return ���� ���� �׷��� �Ⱦ���.
{
	printf("��ü��� ȸ�� �� : %d\n", count);			//��ü ȸ������ count�Ѵ�.
}

double average_weight(Fitness** pary, int count)		
{
	int i;
	double res;
	double sum=0;
	for (i = 0; i < count; i++)							
	{
		sum += pary[i]->weight;								//sum�� �迭 i ���� ����� ü���� +=�� ���Ͽ� i��ŭ �����ؼ� ���Ѵ�.
	}
	res = sum / (double)count;								//sum�� ����� ���� count(�� �Է��� ȸ�� ��)�� �־� ��� �����Ը� ���Ѵ�./ i�� 0���� ���� �����̱� ������ 1�� �и���.
	return res;
}
int max_weight(Fitness** pary, int count)
{
	int i;
	int index = (pary[0]->num);								//index�� �ִ� �����Ը� ���� ����� ȸ����ȣ�� ��ȸ�ϱ� ���� 0���� ���� �񱳸� ���ؼ� �ʱ�ȭ�Ѵ�.
	double max = (pary[0]->weight);							//�ִ� �����Ը� ����� max�Լ��� 0������������ �����ϰ� �ʱ�ȭ�Ѵ�.
	for (i = 1; i < count; i++)								//0������ 1������ �񱳸� ���ؼ� i�� 1 �� �־ ���Ѵ�. 
	{
		if (max < (pary[i]->weight))						//���Ը� 0������ �ʱ�ȭ�� ������ ����� �����Ѵ�. / 0������ i ���� ���� ������ max�� i ������ ���� �����Ѵ�. 
		{
			max = pary[i]->weight;
		
			index = pary[i]->num;							//i������ ����� ���� num�� �����Ѵ�.
		}			
	}
	return index;
}


void print_info(Fitness** pary, int index)
{
	printf("�ִ� ü���� ȸ�� ����\n");
	printf("��ȣ : %d\t�̸� : %s\tü�� : %.1lf\t", (pary[index-1])->num, (pary[index-1])->name, (pary[index-1])->weight);		//�ִ�ü���� ��� ������ ���
}

void free_ary(Fitness** pary, int count)
{
	int i;
	for (i = 0; i < count; i++);						//0�������� count���� �����Ҵ��� ����ؼ� �Ѵ�.
	free(ary[i]);										//�����Ҵ� ����
}