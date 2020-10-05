/*
** EPITECH PROJECT, 2019
** bttf_runner
** File description:
** runner
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "runner.h"

void select_play(runner_t *runner);

void change_sprite(runner_t *runner)
{
    sfSprite *start_screen_sprite = start_screen();
    runner->menu.sprite_player = malloc(sizeof(sfSprite *) * 8);
    runner->menu.sprite_player[0] = create_sprite(3,
    "assets/pink.png", 270, 350);
    runner->menu.sprite_player[1] = create_sprite(3,
    "assets/red.png", 270, 350);
    runner->menu.sprite_player[2] = create_sprite(3,
    "assets/blue.png", 270, 350);
    runner->menu.sprite_player[3] = create_sprite(3,
    "assets/cyan.png", 270, 350);
    runner->menu.sprite_player[4] = create_sprite(3,
    "assets/green.png", 270, 350);
    runner->menu.sprite_player[5] = create_sprite(3,
    "assets/yellow.png", 270, 350);
    runner->menu.sprite_player[7] = create_sprite(2.5, "assets/left.png",
200, 350);
    runner->menu.sprite_player[8] = create_sprite(2.5, "assets/right.png",
    500, 350);
}

sfSprite *create_sprite(float size, char *string, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile(string,
    NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){size, size});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

void display_start(runner_t *runner)
{
    for (int x = 7; x <= 8; x++) {
        sfRenderWindow_drawSprite(runner->window,
        runner->menu.sprite_player[x], NULL);
    }
}

void choice_color(runner_t *runner)
{
    if (runner->menu.pick > 6)
        runner->menu.pick = 0;
    if (runner->menu.pick < 0)
        runner->menu.pick = 6;
    sfRenderWindow_drawSprite(runner->window,
    runner->menu.sprite_player[runner->menu.pick], NULL);
    select_play(runner);
}

void select_play(runner_t *runner)
{
    sfTime time1;
    float seconds = 0;
    time1 = sfClock_getElapsedTime(runner->clock);
    seconds = time1.microseconds / 50000;
    sfFloatRect b_left = sfSprite_getGlobalBounds
    (runner->menu.sprite_player[3]);
    sfFloatRect b_right = sfSprite_getGlobalBounds
    (runner->menu.sprite_player[4]);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(runner->window);
    if (seconds >= 1.5) {
        if ((sfFloatRect_contains(&b_left, mouse.x, mouse.y) &&
        (sfMouse_isButtonPressed(sfMouseLeft))) ||
        sfKeyboard_isKeyPressed(sfKeyRight))
            runner->menu.pick--;
        if (sfFloatRect_contains(&b_right, mouse.x, mouse.y) &&
        (sfMouse_isButtonPressed(sfMouseLeft)) ||
        sfKeyboard_isKeyPressed(sfKeyLeft))
        runner->menu.pick++;
        sfClock_restart(runner->clock);
    }
}
