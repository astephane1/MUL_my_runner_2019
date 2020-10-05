/*
** EPITECH PROJECT, 2018
** header
** File description:
** header
*/
#include <stdarg.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "runner.h"

#ifndef MY_H_
#define MY_H_

int my_getnbr(char *str);
int my_strlen(char *str);
void my_putchar(char c);
char *my_strlowcase(char *str);
int map_open_read_file(char *filepath, runner_t *runner);
char **my_str_to_word_array(char const *str);
int my_strlen(char *str);
char *my_strcpy(char *dest, char const *src);
int game_loop(runner_t *runner, sprite_t *sprite, offset_t *offset);
sfRenderWindow *create_the_window(void);
sfEvent event_loop(sfEvent ev, runner_t *runner, sprite_t *sprite,
offset_t *offset);
int close_window(runner_t *runner, sfEvent *event, sprite_t *sprite,
offset_t *offset);
int display_sprite(runner_t *runner, sprite_t *sprite);
void sprite_factory(runner_t *runner, sprite_t *sprite);
sfSprite *back_sprite01(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *back_sprite02(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *back_sprite03(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *back_sprite04(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *back_sprite05(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *back_sprite06(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *back_sprite07(runner_t *runner, sprite_t *sprite, int x, int y);
sfSprite *ground_sprite08(runner_t *runner, sprite_t *sprite, int x, int y);
void key_press(sprite_t *sprite, runner_t *runner);
void sprite_move(runner_t *runner, sprite_t *sprite);
sfSprite *create_sprite_player(runner_t *runner,
sprite_t *sprite, int x, int y);
void move_rect_player(sfIntRect *rect);
void player_move(sfIntRect *rect, runner_t *runner, sprite_t *sprite);
int player_jump(sprite_t *sprite, runner_t *runner, offset_t *offset);
void play_music(runner_t *runner);
void move_back(sprite_t *sprite, offset_t *offset, runner_t *runner);
void setup_offset(offset_t *offset);
void reset_back_pos(sprite_t *sprite, runner_t *runner);
void display_txt(char *txt);
int score(runner_t *runner);
void display_score(runner_t *runner);
void setup_text(runner_t *runner);
int game_loop_2(runner_t *runner, sprite_t *sprite, offset_t *offset);
char *itoa_simple(int n);
void destroy(runner_t *runner, sprite_t *sprite, offset_t *offset);
sfSprite *create_sprite_end(runner_t *runner, sprite_t *sprite, int x, int y);
void dispay_end(runner_t *runner);
void end_text(runner_t *runner);
sfSprite *create_sprite_restart(runner_t *runner);
int restart(runner_t *runner, sprite_t *sprite, offset_t *offset);
sfSprite *start_screen(void);
int start(runner_t *runner, sprite_t *sprite, offset_t *offset, sfEvent ev);
void player_move_jump(sfIntRect *rect, runner_t *runner, sprite_t *sprite);
void move_rect_player_jump(sfIntRect *rect);
void create_sprite_jump(runner_t *runner);
void reset_ground(runner_t *runner, sprite_t *sprite);
void generate_sprite(runner_t *runner);
sfSprite *create_sprite(float size, char *str, int x, int y);
void display_start(runner_t *runner);
void choose_color(runner_t *runner);
void select_color(runner_t *runner);
void help(void);
#endif
