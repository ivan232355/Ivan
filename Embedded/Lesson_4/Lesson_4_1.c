
#include <stdio.h>


long a = 0, b = 0;

int main(void)
{
	printf("¬ведите два целый числа\n");
	scanf("%ld %ld\n",&a,&b);
	if(a>b)
	{
		printf("%ld %ld\n",b,a);
	}
	else 
	{
		printf("%ld %ld\n",a,b);	
	}
	
	return 0;
}

