/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** displays string of caracters
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
