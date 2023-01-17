#include <stdio.h>
#include <locale.h>
int y = 1;
void vvod(int x) 
{ 
	if (x > 0) 
	{ 
		int n; 
		setlocale(LC_ALL, "Russian"); 
		printf("Введите число %d :", y); 
		y++; 
		scanf_s("%d", &n); 
		vvod(x - 1); 
		printf("%2d", n);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int x;
	printf("Введите кол-во элементов:\n");
	scanf_s("%d", &x);
	vvod(x);
	return 0;
}
