/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** itoa string
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "runner.h"

void itoa_negative(int *x, int *neg)
{
    if (*x < 0) {
        *x *= -1;
        *neg = 1;
    }
}

char *itoa_simple(int x)
{
    int tmp = x;
    int size = 2;
    int neg = 0;
    char *string;

    itoa_negative(&x, &neg);
    while (tmp /= 10)
        size++;
    size += neg;
    if ((string = malloc(sizeof(char) * size)) == NULL)
        return (NULL);
    string[--size] = '\0';
    while (size--) {
        string[size] = x % 10 + '0';
        x = x / 10;
    }
    return (string);
}

void destroy(runner_t *runner, sprite_t *sprite, offset_t *offset)
{
    //sfMusic_stop(runner->jump_sound);
    //sfMusic_stop(runner->game_music);
    //sfMusic_destroy(runner->game_music);
    //sfMusic_destroy(runner->jump_sound);
    sfText_destroy(runner->text.text2);
    sfText_destroy(runner->text.text);
    for (int i = 0; i <= 15; i++)
        sfSprite_destroy(sprite->back[i]);
    for (int i = 0; i < 9; i++)
        sfSprite_destroy(runner->menu.sprite_player[i]);
    sfClock_destroy(runner->clock);
    sfFont_destroy(runner->text.font);
}
