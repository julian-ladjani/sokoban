/*
** fonc1.c for my_sokoban in /home/julian-ladjani/delivery/PSU/my_sokoban/PSU_2016_my_sokoban/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Feb Dec 19 16:11:32 2016 Julian Ladjani
** Last update Mar Dec 20 19:01:12 2016 Julian Ladjani
*/

#include "my.h"

int		my_sokoban(t_game game)
{
  int		ch;

  ch = 0;
  while (1)
    {
      if (ch == KEY_UP)
	game = move_up(game);
      else if (ch == KEY_DOWN)
	game = move_down(game);
      else if (ch == KEY_LEFT)
	game = move_left(game);
      else if (ch == KEY_RIGHT)
	game = move_right(game);
      else if (ch == KEY_RESIZE)
	game = check_term(game);
      else if (ch == ' ')
	game = reset_game(game);
      game.win = check_win(game);
      if (game.win != 0)
	return (game.win);
      print_sokoban(game);
      ch = getch();
    }
}

t_game		move_up(t_game game)
{
  char		temp;

  if (game.posy > 0)
    {
      if (game.map[game.posy - 1][game.posx] == 'O')
	{
	  temp = game.map[game.posy][game.posx];
	  game.map[game.posy][game.posx] = ' ';
	  game.map[game.posy - 1][game.posx] = temp;
	  game.posy--;
	}
      else if (game.map[game.posy - 1][game.posx] == ' ')
	{
	  temp = game.map[game.posy][game.posx];
	  if (game.mapbase[game.posy][game.posx] == 'O')
	    game.map[game.posy][game.posx] = 'O';
	  else
	    game.map[game.posy][game.posx] = ' ';
	  game.map[game.posy - 1][game.posx] = temp;
	  game.posy--;
	}
      else if (game.map[game.posy - 1][game.posx] == 'X')
	game = move_box_up(game);
    }
  return (game);
}

t_game		move_down(t_game game)
{
  char		temp;

  if (game.map[game.posy + 1] != NULL)
    {
      if (game.map[game.posy + 1][game.posx] == 'O')
	{
	  temp = game.map[game.posy][game.posx];
	  game.map[game.posy][game.posx] = ' ';
	  game.map[game.posy + 1][game.posx] = temp;
	  game.posy++;
	}
      else if (game.map[game.posy + 1][game.posx] == ' ')
	{
	  temp = game.map[game.posy][game.posx];
	  if (game.mapbase[game.posy][game.posx] == 'O')
	    game.map[game.posy][game.posx] = 'O';
	  else
	    game.map[game.posy][game.posx] = ' ';
	  game.map[game.posy + 1][game.posx] = temp;
	  game.posy++;
	}
      else if (game.map[game.posy + 1][game.posx] == 'X')
	game = move_box_down(game);
    }
  return (game);
}

t_game		move_left(t_game game)
{
  char		temp;

  if (game.posx > 0)
    {
      if (game.map[game.posy][game.posx - 1] == 'O')
	{
	  temp = game.map[game.posy][game.posx];
	  game.map[game.posy][game.posx] = ' ';
	  game.map[game.posy][game.posx - 1] = temp;
	  game.posx--;
	}
      else if (game.map[game.posy][game.posx - 1] == ' ')
	{
	  temp = game.map[game.posy][game.posx];
	  if (game.mapbase[game.posy][game.posx] == 'O')
	    game.map[game.posy][game.posx] = 'O';
	  else
	    game.map[game.posy][game.posx] = ' ';
	  game.map[game.posy][game.posx - 1] = temp;
	  game.posx--;
	}
      else if (game.map[game.posy][game.posx - 1] == 'X')
	game = move_box_left(game);
    }
  return (game);
}

t_game		move_right(t_game game)
{
  char		temp;

  if (game.map[game.posy][game.posx + 1] != '\0')
    {
      if (game.map[game.posy][game.posx + 1] == 'O')
      	{
	  temp = game.map[game.posy][game.posx];
	  game.map[game.posy][game.posx] = ' ';
	  game.map[game.posy][game.posx + 1] = temp;
	  game.posx++;
	}
      else if (game.map[game.posy][game.posx + 1] == ' ')
	{
	  temp = game.map[game.posy][game.posx];
          if (game.mapbase[game.posy][game.posx] == 'O')
            game.map[game.posy][game.posx] = 'O';
          else
	    game.map[game.posy][game.posx] = ' ';
	  game.map[game.posy][game.posx + 1] = temp;
	  game.posx++;
	}
      else if (game.map[game.posy][game.posx + 1] == 'X')
	game = move_box_right(game);
    }
  return (game);
}
