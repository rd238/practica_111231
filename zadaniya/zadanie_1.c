/*
Угол задан a в градусах, минутах и секундах. Найти его величи-
ну в радианах (с максимально возможной точностью).
 */
double zadanie1(double grad, double min, double sec){
    return grad + (min + sec / 60) / 60;
}