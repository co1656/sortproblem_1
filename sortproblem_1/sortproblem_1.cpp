#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
#include <time.h>

int ran;
time_t start, end;
double result;
int myArray[100000] = { 0, }; //더 늘리고싶으면 여기숫자 바꾸기
bool checkNumber(int number);

void BB(int list[], int n) //버블정렬
{
	int i, j, temp;

	for (i = n - 1; i > 0; i--) //마지막 하나는 최대값이 남기때문에 n-1
	{
		for (j = 0; j < i; j++) 
		{
			if (list[j] < list[j + 1]) //앞뒤체크
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

bool checkNumber(int number)//중복체크
{
	for (int i = 0; i < ran; i++)
	{
		if (number == myArray[i])
			return false;
	}

	return true;
};

int main()
{

	printf("생성할 난수의 갯수 입력: ");
	scanf("%d", &ran);


	std::mt19937 mtRand; //난수생성기
	std::uniform_int_distribution<int> dist(0, ran); //int는 정수타입 real은 실수타입 난수 분포(소수점까지)

	int Random = 0;

	for (int i = 0; i < ran; i++)//난수 중복 체크
	{
		while (true)
		{
			Random = dist(mtRand); //배열에 저장된 값

			if (checkNumber(Random) == false) //중복일경우 continue 다시뽑기
				continue;

			myArray[i] = Random; //뽑은 값 넣기
			break;
		}
	}

	for (int i = 0; i < ran; i++) //난수 출력
	{
		std::cout << "Random[" << i << "] : ";
		std::cout << myArray[i] << std::endl;
	}

	start = clock(); //시간측정 시작

	BB(myArray, ran); //버블정렬 실행

	for(int i = 0; i <= ran; i++) //버블정렬 출력
	{
			printf("%d\n", myArray[i]);
	}

	end = clock(); //시간측정 끝
	result = (double)(end - start)/1000;
	printf("사용된 시간 : %f", result); //결과 출력

	return 0;
}

