
#include <stdio.h>
#include <inttypes.h>


float X1 = 0,X2 = 0,Y1 = 0 ,Y2 = 0;
float k = 0;
float b = 0;

int main(void)
{
	printf("��।����� �ࠢ����� ��אַ� �� ���न��⠬ ���� �祪. �ࠢ����� ���� y=k*x+b\n");
	printf("������ ���� 楫�� �᫠ �१ �஡��. ���न���� X1 Y1 X2 Y2\n");
	scanf("%f %f %f %f\n",&X1,&Y1,&X2,&Y2);
	
	printf("���㫠 ���� k = (Y2-Y1)/(X2-X1)\n");
	printf("���㫠 ���� b = Y1 - X1*(Y2-Y1)/(X2-X1)\n");
	k = (Y2-Y1)/(X2-X1);
	b = (Y1 - (X1*(Y2-Y1))/(X2-X1));
	printf("b = %.2f \n",b);
	printf("k = %.2f \n",k);
	return 0;
}

