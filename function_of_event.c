/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** my_runner
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

int perso_jump(sprite_t *sprite, runner_t *runner, offset_t *offset);

sfEvent event_loop(sfEvent event, runner_t *runner, sprite_t *sprite, \
offset_t *offset)
{
    while (sfRenderWindow_pollEvent(runner->window, &event)) {
        perso_jump(sprite, runner, offset);
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
            close_window(runner, &event, sprite, offset);
        }
    }
    return (event);
}

int close_window(runner_t *runner, sfEvent *event, sprite_t *sprite,
offset_t *offset)
{
    sfRenderWindow_close(runner->window);
    return (0);
}

int perso_jump(sprite_t *sprite, runner_t *runner, offset_t *offset)
{

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (runner->player.status < 3) {
            runner->player.velocity.y = -5.2;
            runner->player.velocity.x = 0;
            runner->player.status++;
            sfMusic_play(runner->jump_sound);
        }
    }
}
