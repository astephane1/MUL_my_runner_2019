/*
** EPITECH PROJECT, 2019
** the principal function
** File description:
** my_runner
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "my.h"
#include "runner.h"

int my_putstr(char const *str);

int play_game(sprite_t *sprite, runner_t *runner, offset_t *offset);

int start_p(runner_t *runner, sprite_t *sprite, offset_t *offset, sfEvent evnt);

int game_loop2(runner_t *runner, sprite_t *sprite, offset_t *offset);

void help_use(void);

sfRenderWindow *create_the_window(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    window = sfRenderWindow_create(mode, "my_runner", sfResize |
sfClose, NULL);
    if (!window) {
        return (window);
    }
    return (window);
}

int map_open_read(char *filepath, runner_t *runner)
{
    char *mapping;
    int fd;
    int str;
    char **map_tab;
    struct stat size;

    stat(filepath, &size);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    mapping = malloc(sizeof(char) * (size.st_size + 1));
    if (!mapping)
        return (84);
    str = read(fd, mapping, size.st_size);
    if (str < 0)
        return (84);
    mapping [size.st_size] = '\0';
    runner->map_string = mapping;
    return (0);
}

int display_sprite(runner_t *runner, sprite_t *sprite)
{
    for (int i = 0; i <= 15; i++) {
        sfRenderWindow_drawSprite(runner->window, sprite->back[i], NULL);
    }
    sfRenderWindow_drawSprite(runner->window, sprite->player, NULL);
    return (0);
}

int game_loop1(runner_t *runner, sprite_t *sprite, offset_t *offset)
{
    sfClock *clock_fly = sfClock_create();
    sfEvent evenement;
    sprite_move(runner, sprite);
    display_score(runner);
    while (sfRenderWindow_isOpen(runner->window)) {
        setup_text(runner);
        sfRenderWindow_clear(runner->window, sfCyan);
        if (runner->player.player_pos.y > 360)
            player_move(&runner->rect_player, runner, sprite);
        event_loop(evenement, runner, sprite, offset);
        game_loop2(runner, sprite, offset);
    }
    destroy(runner, sprite, offset);
}

int main(int ac, char **av)
{
    sfEvent event;
    runner_t *runn = malloc(sizeof(*runn));
    sprite_t *spr = malloc(sizeof(*spr));
    offset_t *off = malloc(sizeof(*off));

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            help_use();
            return (0);
        }
    }
    if (ac == 1) {
        my_putstr("./my_runner: bad arguments: 0 given but 1 is required\n");
        my_putstr("retry with -h\n");
        return (84);
    }
    if (map_open_read(av[1], runn) == 84)
        return (84);
    runn->window = create_the_window();
    sfRenderWindow_setFramerateLimit(runn->window, 60);
    play_game(spr, runn, off);
    play_music(runn);
    start_p(runn, spr, off, event);
    if (game_loop1(runn, spr, off))
        return (0);
}
