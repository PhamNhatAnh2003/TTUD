#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.141592654

void problem1();
void problem2();
void problem3();
void problem4();

int Fib(int n)
{
    int x = 1, y = 1;
    if (n == 1 || n == 2)
        return 1;
    int i = 3, z;
    while (i <= n)
    {
        z = x + y;
        x = y;
        y = z;
        i++;
    }
    return z;
}

double F(double x,int n) {
 	int a;
	if (n % 2 == 0) a = 1;
	else a = -1;
	double temp = 1;
	for (int i = 1; i <= 2 * n + 1; i++){
		temp = temp * x / i;		
	}

	return a * temp;
}

double H()
{
 	double x, e, sin = 0;
	scanf("%lf %lf",&x,&e);
 	int n = 0;
 	while (fabs(F(x,n)) > e ) {
 		sin += (F(x,n));

 		n++;
	}
	return sin;	
}



int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Invalid parameters!\n");
    return 0;
  }
  switch (atoi(argv[1])) {
  case 1:
    problem1(); 
    break;
  case 2:
    problem2(); 
    break;
  case 3:
    problem3(); 
    break;
  case 4:
    problem4();
     break;
 default:
    printf("Invalid parameters!\n");
    break;
  }
}

void problem1() {
  int a,b;
   scanf("%d %d",&a,&b);
	while (b!=0){
		int r = a%b;
		a = b;
		b = r;
	}
	printf("%d",a);
}

void problem2() {
  {
    int n;
    scanf("%d", &n);
    int k = 1;
    for (int i = 1; i <= n; i++){
    	for (int j = 1; j <= n; j++){
    		printf("+-----");
		}
		printf("+\n");
		for (int z = 1; z <= n; z++){
			printf("|%5d",k);
			k++;
		}
		printf("|\n");
	}
    
    for (int i = 1; i <= n; i++){
    	printf("+-----");
	}
	printf("+\n");
}
}

void problem3() {
 double k = H();
	printf("%lf",k);
}

void problem4() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    printf("So Fibonacci thu %d la: %d", n, Fib(n));

}


