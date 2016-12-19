/*
** fonc2.c for my_sokoban in /home/julian-ladjani/delivery/PSU/my_sokoban/PSU_2016_my_sokoban/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Feb Dec 19 17:40:10 2016 Julian Ladjani
** Last update Feb Dec 19 20:48:49 2016 Julian Ladjani
*/

#include "my.h"

t_game		prepare_my_game(char *path)
{
  t_game	game;

  initscr();
  game.map = parse_it(path);
  game.mapbase = parse_it(path);
  game = check_map(game);
  game = map_lenght(game);
  game.error = check_term(game);
  getmaxyx(stdscr, game.trow, game.tcol);
  game.win = 0;
  if (game.nbo == 0)
    exit(0);
  return (game);
}

t_game		map_lenght(t_game game)
{
  int		x;
  int		y;
  int		maxx;

  x = 0;
  y = 0;
  while (map[y] != NULL)
    {
      while (map[y][x] != '\0')
	x++;
      if (x > maxx)
	maxx = x;
      x = 0;
      y++;
    }
  game.mapx = maxx;
  game.mapy = maxy;
  return (game);
}

t_game		check_map(t_game game)
{
  int		x;
  int		y;
  int		play;

  x = -1;
  y = -1;
  play = 0;
  while (game.map[++y] != NULL)
    {
      while (game.map[y][++x] != '\0')
	{
	  if (play > 1)
	    exit(84);
	  if (game.map[y][x] == 'O')
	    game.nbo++;
	  else if (game.map[y][x] == 'P' && (play++) > 0 && (game.x = x) >= 0)
	    game.y = y;
	  else if (game.map[y][x] != '#' && game.map[y][x] != ' ' &&
		   game.map[y][x] != 'X')
	    exit(84);
	}
      x = -1;
    }
  return (game);
}

void		print_sokoban(t_game game)
{
  int		y;

  y = -1;
  if (game.error == 0)
    {
      while (game.map[++y] != NULL)
	mvprintw(0, 0, game.map[y]);
    }
  else
    mvprintw(game.trow/2, (game.tcol - 20)/2, "Enlarge The Terminal");
  cur_set(0);
}

t_game		check_term(t_game game)
{
  getmaxyx(stdscr, game.trow, game.tcol);
  if (game.trow > game.mapy || game.tcol > game.mapx)
    game.error = 1;
  else
    game.error = 0;
  return (game);
}
