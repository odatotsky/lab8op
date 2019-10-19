#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fpin;//входящий файловый указатель
	FILE* fpout;//выходящий файловый указатель
	fpin = fopen("test.txt", "r"); //чтение
	fpout = fopen("resut.txt", "w"); //запись
	char line[40];
	int count = 0;//счетчик строк
	int flag = 0;//0-число не найдено/ 1-найдено
	char* begin;
	char* end;
	char number[40]; //массив для числа
	int i = 0;//индекс массив с числом
	int result;
	int max = -9999;//максимальное значениеъ
	int numstring = 0;// номер строки с максимальным числом
	while (!feof(fpin))//пока файл не закончился
	{
		char * ptr = fgets(line, 40, fpin);//чтение одной строки
		if (ptr == NULL)
			break;
		count++;
		while (*ptr != '\0')
		{
			if ((*ptr == '1') || (*ptr == '2') || (*ptr == '3') || (*ptr == '4') || (*ptr == '5') || (*ptr == '6') || (*ptr == '7') || (*ptr == '8') || (*ptr == '9') || (*ptr == '0'))
			{
				if (flag == 0)
				{
					flag = 1;
					begin = ptr;//запомнили начало числа


				}
				
			}
			else
			{
				if (flag == 1)
				{
					end = ptr; //конец числа
					for (ptr = begin, i = 0; ptr != end; ptr++, i++)
					{
						number[i] = *ptr;

					}
					i++;
					number[i] = '\0';
					result = atoi(number);    //результат
					if (result > max)
					{
						max = result;
						numstring = count;
					}

					memset(number, 0, 40);//обнуление массива
					flag = 0;
					begin = NULL;
					end = NULL;


				}
			}
			ptr++;
		}
		memset(line, 0, 40);
	}
	fseek(fpin, 0, SEEK_SET);//указатель в файле становится на начало

}


