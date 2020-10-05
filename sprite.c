/*
** EPITECH PROJECT, 2019
** runner
** File description:
** move parallax
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

sfSprite *back_sprite01(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
    ("assets/_11_background.png", NULL);
    sfSprite *sprites = sfSprite_create();

    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *back_sprite02(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
    ("assets/_10_distant_clouds.png", NULL);
    sfSprite *sprites = sfSprite_create();

    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *back_sprite03(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile("assets/_08_clouds.png", NULL);
    sfSprite *sprites = sfSprite_create();

    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *back_sprite04(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
    ("assets/_07_huge_clouds.png", NULL);
    sfSprite *sprites = sfSprite_create();

    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

void sprite_move(runner_t *runner, sprite_t *sprite)
{
    sprite->back = malloc(sizeof(sfSprite *) * 16);
    sprite->back[0] = back_sprite01(runner, sprite, 0, 0);
    sprite->back[1] = back_sprite01(runner, sprite, 790, 0);
    sprite->back[2] = back_sprite02(runner, sprite, 0, 0);
    sprite->back[3] = back_sprite02(runner, sprite, 790, 0);
    sprite->back[4] = back_sprite03(runner, sprite, 0, 0);
    sprite->back[5] = back_sprite03(runner, sprite, 790, 0);
    sprite->back[6] = back_sprite04(runner, sprite, 0, 0);
    sprite->back[7] = back_sprite04(runner, sprite, 790, 0);
    sprite->back[8] = back_sprite05(runner, sprite, 0, 0);
    sprite->back[9] = back_sprite05(runner, sprite, 790, 0);
    sprite->back[10] = back_sprite06(runner, sprite, 0, 0);
    sprite->back[11] = back_sprite06(runner, sprite, 790, 0);
    sprite->back[12] = back_sprite07(runner, sprite, 0, 0);
    sprite->back[13] = back_sprite07(runner, sprite, 790, 0);
    sprite->back[14] = ground_sprite08(runner, sprite, 0, 0);
    sprite->back[15] = ground_sprite08(runner, sprite, 790, 0);
    sprite->player = runner->menu.sprite_player[runner->menu.pick];
    sfSprite_setPosition(sprite->player, (sfVector2f){0, 390});
}
