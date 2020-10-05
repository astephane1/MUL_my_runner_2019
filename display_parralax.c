/*
** EPITECH PROJECT, 2019
** repository
** File description:
** runner
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "runner.h"

sfSprite *back_sprite05(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
        ("assets/_05_hill1.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *back_sprite06(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
        ("assets/_04_bushes.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *back_sprite07(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile
        ("assets/_02_trees and bushes.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}

sfSprite *ground_sprite08(runner_t *runner, sprite_t *sprite, int x, int y)
{
    sfTexture *back = sfTexture_createFromFile("assets/_01_ground.png", NULL);
    sfSprite *sprites = sfSprite_create();
    sfSprite_setPosition(sprites, (sfVector2f){x, y});
    sfSprite_setScale(sprites, (sfVector2f){0.39, 0.39});
    sfSprite_setTexture(sprites, back, sfTrue);
    return (sprites);
}
