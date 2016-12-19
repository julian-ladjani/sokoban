/*
** fonc4.c for my_sokoban in /home/julian-ladjani/delivery/PSU/my_sokoban/PSU_2016_my_sokoban/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 20 00:41:43 2016 Julian Ladjani
** Last update Mar Dec 20 00:50:06 2016 Julian Ladjani
*/

#include "my.h"

t_game		reset_game(t_game game)
{
  int		y;

  y = 0;
  while (game.map[y] != NULL)
    {
      my_strcpy(game.map[y], game.mapbase[y]);
      y++;
    }
  game = check_map(game);
  game = map_lenght(game);
  getmaxyx(stdscr, game.trow, game.tcol);
  game = check_term(game);
  game.win = 0;
  if (game.nbo == 0)
    exit(0);
  return (game);
}
