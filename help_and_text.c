/*
** EPITECH PROJECT, 2019
** csfml
** File description:
** runner
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "runner.h"

int my_putstr(char const *str);

char *itoa_simple(int x);

void setup_text(runner_t *runner)
{
    char *str = itoa_simple(runner->player.score);
    sfText_setString(runner->text.text2, str);
    sfText_setFont(runner->text.text2, runner->text.font);
    sfText_setCharacterSize(runner->text.text2, 30);
    sfText_setPosition(runner->text.text2, (sfVector2f){105, 550});
    sfText_setColor(runner->text.text2, (sfColor){1, 1, 1, 255});
}

void display_score(runner_t *runner)
{
    sfText_setString(runner->text.text, "score :");
    sfText_setFont(runner->text.text, runner->text.font);
    sfText_setCharacterSize(runner->text.text, 30);
    sfText_setPosition(runner->text.text, (sfVector2f){0, 550});
    sfText_setColor(runner->text.text, (sfColor){1, 1, 1, 255});
}

void help_use(void)
{
    my_putstr("Finite runner created with CSFML\n");
    my_putstr("\n");
    my_putstr("USAGE\n");
    my_putstr("\n");
    my_putstr("./my_runner map.txt");
    my_putstr("\n");
    my_putstr("\n");
    my_putstr("\nOPTIONS\n");
    my_putstr("\n -i    launch the game in infinity mode\n");
    my_putstr(" -h       print the usage and quit");
    my_putstr("\n USER INTERACTIONS");
    my_putstr("\n SPACE_KEY     jump.\n");
}
