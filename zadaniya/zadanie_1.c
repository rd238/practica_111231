#include <stdio.h>


/*
Угол задан a в градусах, минутах и секундах. Найти его величи-
ну в радианах (с максимально возможной точностью).
 */
double zadanie1(double grad, double min, double sec){
    return grad + (min + sec / 60) / 60;
}




/*
Заданы три числа: a, b, c. Определить, могут ли они быть сторо-
нами треугольника, и если да, то определить его тип: равносторонний,
равнобедренный, разносторонний.
*/
void zadanie2(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a)
        if (a == b || a == c || b == c)
            if (a == b && a == c && b == c)
                printf("Equilateral triangle.\n");
            else
                printf( "Isosceles triangle.\n");
        else
            printf( "Scalene triangle.\n");
    else
        printf( "Triangle doesn't exist.\n");
}



/*
Численно убедиться, является ли заданная функция y = f(x)
чётной или нёчетной на заданном отрезке -a <= x <= a . Учесть по-
грешность вычислений и возможные точки разрыва функции.
 */

/*  проверка на нечетность. Возвращает ~0 если нечетная */
double odd(double x, double (*f)(double))
{   return f(x) + f(-x);
}
/*  проверка на четность. Возвращает ~0 если четная */
double even(double x, double (*f)(double))
{   return f(x) - f(-x);
}
double fabs(double a) {
    if(a < 0)
        return -a;
    return a;
}
/*  общая проверка, вывод результата    */
void zadanie3(double(*f)(double), double a){
    double x = 0., step = 0.1, epsilon = 1E-10;
    int isOdd = 1, isEven = 1;

    while(x <= a)
    {   if(f(x)> epsilon)
    {   if(fabs(odd(x,f)) < epsilon)
        isEven *= 0;
    else if(fabs(even(x,f)) < epsilon)
        isOdd *= 0;
    else
    {   isEven *= 0;
        isOdd *= 0;
    }
    }
        x += step;
    }

    if(isOdd)
        printf("odd");
    else if (isEven)
        printf("even");
    else
        printf("neither odd nor even");
}



/*
В массиве c(n) подсчитать количество отрицательных и сумму
положительных элементов.
*/
void zadanie4(int *c, int n) {
    int sum_positive = 0;
    int quantity_negative = 0;
    for(int i = 0; i < n; i++) {
        if(c[i] < 0)
            quantity_negative++;
        else
            sum_positive += c[i];
    }

    printf("\n%d - sum positive elements\n", sum_positive);
    printf("%d - quantity negative elements\n", quantity_negative);
}