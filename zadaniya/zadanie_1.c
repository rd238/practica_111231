/*
Угол задан a в градусах, минутах и секундах. Найти его величи-
ну в радианах (с максимально возможной точностью).
 */
double zadanie1(double grad, double min, double sec){
    return grad + (min + sec / 60) / 60;
}



#include <stdio.h>
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