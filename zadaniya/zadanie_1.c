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




/*
Строки матрицы A(m,n) заполнены не полностью: в массиве
L(m) указано количество элементов в каждой строке. Переслать эле-
менты матрицы построчно в начало одномерного массива T(m*n) и
подсчитать их количество.
 */
int zadanie5(int **A, int *L, int *T, int m, int n) {
    int size_T = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < L[i]; j++) {
            T[size_T++] = A[i][j];
        }
    }

    return size_T;
}




/*
Седловой точкой в матрице называется элемент, являющийся
одновременно наибольшим в столбце и наименьшим в строке. Седло-
вых точек может быть несколько. В матрице A(m,n) найти все седло-
вые точки либо установить, что таких точек нет.
 */
void zadanie6(int **A, int m, int n) {
    for(int i = 0; i < m; i++) {
        int min_element = A[i][0];
        int min_index = 0;

        for(int j = 1; j < n; j++)
            if(min_element > A[i][j])
                min_element = A[i][j], min_index = j;

        int max_element = A[0][min_index];
        for(int j = 1; j < m; j++)
            if(A[j][min_index] > max_element)
                max_element = A[j][min_index];

        if(max_element == min_element)
            printf("\n(%d) (%d, %d) is saddle point\n", min_element, i, min_index);
    }
}





/*
Натуральное число в p-ичной системе счисления задано своими
цифрами, хранящимися в массиве K(n). Проверить корректность тако-
го представления и перевести число в q-ичную систему (возможно,
число слишком велико, чтобы получить его внутреннее представление;
кроме того, p <= 10, q <= 10 ).
 */
void zadanie7(int *K, int n, int p, int q) {
    int is_correctly = 1;
    for(int i = 0; i < n; i++)
        if(K[i] < 0 && K[i] >= p)
            is_correctly = 0;

    if(is_correctly) {
        int digit = 0;
        for(int i = 0, j = n - 1; i < n; i++, j--) {
            int factor = 1;
            for(int k = 0; k < j; k++)
                factor *= p;
            digit += K[i] * factor;
        }

        int res[n + n];
        int size_res = 0;
        while(digit != 0) {
            res[size_res++] = digit % q;
            digit /= q;
        }
        for(int i = size_res-1; i >= 0; i--)
            printf("%d", res[i]);
        printf("\n");
    }
}






