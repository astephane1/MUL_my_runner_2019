/*
** EPITECH PROJECT, 2019
** the game
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

void moving_back(sprite_t *sprite, offset_t *offset, runner_t *runner);

void move_jump(sprite_t *sprite, runner_t *runner);

int game_loop2(runner_t *runner, sprite_t *sprite, offset_t *offset);

int score(runner_t *runner)
{
    sfTime time_one;
    float seconds = 0;
    time_one = sfClock_getElapsedTime(runner->clock);
    seconds = time_one.microseconds / 50000;
    if (seconds >= 4) {
        runner->clock_counter = 0;
        runner->player.score++;
        sfClock_restart(runner->clock);
    }
}

void end_text(runner_t *runner)
{
    sfText_setString(runner->text.text_end, " Score : ");
    sfText_setFont(runner->text.text_end, runner->text.font);
    sfText_setCharacterSize(runner->text.text_end, 30);
    sfText_setPosition(runner->text.text_end, (sfVector2f){280, 100});
    sfText_setColor(runner->text.text_end, (sfColor){1, 1, 1, 255});
}

void play_music(runner_t *run)
{
    run->jump_sound = (sfMusic_createFromFile("assets/jump_sound.ogg"));
    run->game_music = (sfMusic_createFromFile("assets/naruto.ogg"));
    sfMusic_setVolume(run->game_music, 30.0);
    sfMusic_setLoop(run->game_music, sfTrue);
    sfMusic_play(run->game_music);
}

int game_loop2(runner_t *runner, sprite_t *sprite, offset_t *offset)
{
    runner->player.player_pos = sfSprite_getPosition(sprite->player);
    score(runner);
    move_jump(sprite, runner);
    display_sprite(runner, sprite);
    moving_back(sprite, offset, runner);
    sfRenderWindow_drawText(runner->window, runner->text.text, NULL);
    sfRenderWindow_drawText(runner->window, runner->text.text2, NULL);
    sfRenderWindow_display(runner->window);
}
