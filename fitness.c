#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int num;
	char name[20];
	double weight;
}Fitness;

Fitness* ary[100];									//포인터배열 선언
void total_number(int count);						//전체 등록 회원 수 반환	/	void는 리턴 값이 없다.
double average_weight(Fitness** pary, int count);	//평균 체중 반환
int max_weight(Fitness** pary, int count);			//최대 체중 회원의 index반환
void print_info(Fitness** pary, int index);			//회원 정보 출력
void free_ary(Fitness** pary, int count);			//동적 할당 영역 해제

int main()
{
	Fitness* ary[100];
	int i,k;
	int index;
	
	printf("저장할 회원 수 : ");
	scanf("%d", &k);
	printf("\n");

	for (i = 0; i < k; i++)
	{

		ary[i] = (Fitness*)malloc(sizeof(Fitness));	//Fitness배열 저장 공간 동적 할당

		printf("회원정보 : ");
		scanf("%d", &ary[i]->num);					//배열 i 번지 에 입력받은 값을 num에 전달한다.
		if (ary[i]->num < 0) break;					// 음수 일때 브레이크, 회원정보 입력 밑에 넣어야 다른 정보 일일히 안넣고 바로 종료할 수 있다.
		printf("%d\n", ary[i]->num);				//배열 i 번지에 저장된 num 값을 출력한다.(회원정보)
		printf("이름 : ");
		scanf("%s", &ary[i]->name);					//배열 i 번지 에 입력받은 값을 name에 전달한다.					
		printf("%s\n", ary[i]->name);				//배열 i 번지 에 저장된 값을 출력한다.(이름정보)
		printf("무게 : ");
		scanf("%lf", &ary[i]->weight);				//배열 i 번지 에 입력받은 값을 weight에 전달한다.
		printf("%.1lf\n\n", ary[i]->weight);		//배열 i 번지 에 저장된 값을 weight에 전달한다.

	}
	total_number(i);								//void total_number(int count)방의 count 수를 for문을 돌린 i 만큼 출력한다.
	printf("평균 값  : %.1lf\n", average_weight(ary, i));
	index = max_weight(ary, i);
	printf("최대 몸무게 회원 번호: %d\n", index);		//max_weight(ary,i));
	print_info(ary, index);
	free_ary(ary, i);


	return 0;
}


void total_number(int count)						//void는 return 값이 없다 그래서 안쓴다.
{
	printf("전체등록 회원 수 : %d\n", count);			//전체 회원수를 count한다.
}

double average_weight(Fitness** pary, int count)		
{
	int i;
	double res;
	double sum=0;
	for (i = 0; i < count; i++)							
	{
		sum += pary[i]->weight;								//sum에 배열 i 값에 저장된 체중을 +=을 통하여 i만큼 누적해서 더한다.
	}
	res = sum / (double)count;								//sum에 저장된 값을 count(총 입력한 회원 수)를 넣어 평균 몸무게를 구한다./ i는 0번지 부터 시작이기 때문에 1이 밀린다.
	return res;
}
int max_weight(Fitness** pary, int count)
{
	int i;
	int index = (pary[0]->num);								//index에 최대 몸무게를 가진 사람의 회원번호를 조회하기 위해 0번지 부터 비교를 위해서 초기화한다.
	double max = (pary[0]->weight);							//최대 몸무게를 계산할 max함수를 0번지에서부터 시작하게 초기화한다.
	for (i = 1; i < count; i++)								//0번지와 1번지의 비교를 위해서 i에 1 을 넣어서 비교한다. 
	{
		if (max < (pary[i]->weight))						//무게를 0번지에 초기화한 값부터 계산을 시작한다. / 0번지가 i 번지 보다 작으면 max에 i 번지의 값을 저장한다. 
		{
			max = pary[i]->weight;
		
			index = pary[i]->num;							//i번지에 저장된 값을 num에 저장한다.
		}			
	}
	return index;
}


void print_info(Fitness** pary, int index)
{
	printf("최대 체중의 회원 정보\n");
	printf("번호 : %d\t이름 : %s\t체중 : %.1lf\t", (pary[index-1])->num, (pary[index-1])->name, (pary[index-1])->weight);		//최대체중의 사람 정보를 출력
}

void free_ary(Fitness** pary, int count)
{
	int i;
	for (i = 0; i < count; i++);						//0번지부터 count까지 동적할당을 계속해서 한다.
	free(ary[i]);										//동적할당 해제
}