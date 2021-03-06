/*
** fonc4.c for my_sokoban in /home/julian-ladjani/delivery/PSU/my_sokoban/PSU_2016_my_sokoban/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 20 00:41:43 2016 Julian Ladjani
** Last update Mar Dec 20 22:29:57 2016 Julian Ladjani
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

int		check_win(t_game game)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  if (game.nbo == 0)
    {
      game.win = 1;
      return (game.win);
    }
  while (game.map[y] != NULL)
    {
      while (game.map[y][x] != '\0')
	{
	  if (game.map[y][x] == 'X' && (game.win = check_box(game, x, y)) == 0)
	    return (game.win);
	  x++;
	}
      y++;
      x = 0;
    }
  return (game.win);
}

int		check_box(t_game game, int posx, int posy)
{
  int		block;

  block = 0;
  if ((game.map[posy][posx - 1] == 'X' || game.map[posy][posx - 1] == '#') &&
      (game.map[posy + 1][posx] == 'X' || game.map[posy + 1][posx] == '#'))
    block = -2;
  if ((game.map[posy][posx + 1] == 'X' || game.map[posy][posx + 1] == '#') &&
      (game.map[posy + 1][posx] == 'X' || game.map[posy + 1][posx] == '#'))
    block = -2;
  if ((game.map[posy][posx + 1] == 'X' || game.map[posy][posx + 1] == '#') &&
      (game.map[posy - 1][posx] == 'X' || game.map[posy - 1][posx] == '#'))
    block = -2;
  if ((game.map[posy][posx - 1] == 'X' || game.map[posy][posx - 1] == '#') &&
      (game.map[posy - 1][posx] == 'X' || game.map[posy - 1][posx] == '#'))
    block = -2;
  if (block > -2)
    block = 0;
  return (block);
}

t_game		check_map_loop(t_game game, int y)
{
  int		x;

  x = -1;
  while (game.map[y][++x] != '\0')
    {
      if (game.play > 1)
	exit(84);
      if (game.map[y][x] == 'O')
	game.nbo++;
      else if (game.map[y][x] == 'P')
	{
	  game.posy = y;
	  game.posx = x;
	  game.play++;
	}
      else if (game.map[y][x] != ' ' && game.map[y][x] != '\n' &&
	       game.map[y][x] != 'X' && game.map[y][x] != '#')
	exit(84);
    }
  return (game);
}
