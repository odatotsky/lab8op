#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fpin;//�������� �������� ���������
	FILE* fpout;//��������� �������� ���������
	fpin = fopen("test.txt", "r"); //������
	fpout = fopen("resut.txt", "w"); //������
	char line[40];
	int count = 0;//������� �����
	int flag = 0;//0-����� �� �������/ 1-�������
	char* begin;
	char* end;
	char number[40]; //������ ��� �����
	int i = 0;//������ ������ � ������
	int result;
	int max = -9999;//������������ ���������
	int numstring = 0;// ����� ������ � ������������ ������
	while (!feof(fpin))//���� ���� �� ����������
	{
		char * ptr = fgets(line, 40, fpin);//������ ����� ������
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
					begin = ptr;//��������� ������ �����


				}
				
			}
			else
			{
				if (flag == 1)
				{
					end = ptr; //����� �����
					for (ptr = begin, i = 0; ptr != end; ptr++, i++)
					{
						number[i] = *ptr;

					}
					i++;
					number[i] = '\0';
					result = atoi(number);    //���������
					if (result > max)
					{
						max = result;
						numstring = count;
					}

					memset(number, 0, 40);//��������� �������
					flag = 0;
					begin = NULL;
					end = NULL;


				}
			}
			ptr++;
		}
		memset(line, 0, 40);
	}
	fseek(fpin, 0, SEEK_SET);//��������� � ����� ���������� �� ������

}


