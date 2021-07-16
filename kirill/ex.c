#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, *b;
    system("chcp 1251");
    system("cls");
    a = 134;
    b = &a;
    // %x = вывод числа в шестнадцатеричной форме
    printf("\n Значение переменной a равно %d = %x шестн.", a,a);
    printf("\n Адрес переменной a равен %x шестн.", &a);
    printf("\n Данные по адресу указателя b равны %d = %x шестн.", *b,*b);
    printf("\n Значение указателя b равно %x шестн.", b);
    printf("\n Адрес расположения указателя b равен %x шестн.", &b);
    getchar();
    return 0;
}
