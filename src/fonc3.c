/*
** fonc3.c for my_sokoban in /home/julian-ladjani/delivery/PSU/my_sokoban/PSU_2016_my_sokoban/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Dec 20 00:24:35 2016 Julian Ladjani
** Last update Mar Dec 20 17:28:41 2016 Julian Ladjani
*/

#include "my.h"

t_game		move_box_left(t_game game)
{
  char		temp;
  int		posx;

  posx = game.posx - 1;
  if (posx > 0)
    {
      if (game.map[game.posy][posx - 1] == 'O' && (game.nbo -= 1) > -1)
	{
	  temp = game.map[game.posy][posx];
	  game.map[game.posy][posx] = ' ';
	  game.map[game.posy][posx - 1] = temp;
	  game = move_left(game);
	}
      else if (game.map[game.posy][posx - 1] == ' ')
	{
	  temp = game.map[game.posy][posx];
	  if (game.mapbase[game.posy][posx] == 'O' && (game.nbo += 1) > 0)
	    game.map[game.posy][posx] = 'O';
	  else
	    game.map[game.posy][posx] = ' ';
	  game.map[game.posy][posx - 1] = temp;
	  game = move_left(game);
	}
    }
  return (game);
}

t_game		move_box_right(t_game game)
{
  char		temp;
  int		posx;

  posx = game.posx + 1;
  if (game.map[game.posy][posx + 1] != '\0')
    {
      if (game.map[game.posy][posx + 1] == 'O' && (game.nbo -= 1) > -1)
	{
	  temp = game.map[game.posy][posx];
	  game.map[game.posy][posx] = ' ';
	  game.map[game.posy][posx + 1] = temp;
	  game = move_right(game);
	}
      else if (game.map[game.posy][posx + 1] == ' ')
	{
	  temp = game.map[game.posy][posx];
	  if (game.mapbase[game.posy][posx] == 'O' && (game.nbo += 1) > 0)
	    game.map[game.posy][posx] = 'O';
	  else
	    game.map[game.posy][posx] = ' ';
	  game.map[game.posy][posx + 1] = temp;
	  game = move_right(game);
	}
    }
  return (game);
}

t_game		move_box_up(t_game game)
{
  char		temp;
  int		posy;

  posy = game.posy - 1;
  if (posy > 0)
    {
      if (game.map[posy - 1][game.posx] == 'O' && (game.nbo -= 1) > -1)
	{
	  temp = game.map[posy][game.posx];
	  game.map[posy][game.posx] = ' ';
	  game.map[posy - 1][game.posx] = temp;
	  game = move_up(game);
	}
      else if (game.map[posy - 1][game.posx] == ' ')
	{
	  temp = game.map[posy][game.posx];
	  if (game.mapbase[posy][game.posx] == 'O' && (game.nbo += 1) > 0)
	    game.map[posy][game.posx] = 'O';
	  else
	    game.map[posy][game.posx] = ' ';
	  game.map[posy - 1][game.posx] = temp;
	  game = move_up(game);
	}
    }
  return (game);
}

t_game		move_box_down(t_game game)
{
  char		temp;
  int		posy;

  posy = game.posy + 1;
  if (game.map[posy + 1] != NULL)
    {
      if (game.map[posy + 1][game.posx] == 'O' && (game.nbo -= 1) > -1)
	{
	  temp = game.map[posy][game.posx];
	  game.map[posy][game.posx] = ' ';
	  game.map[posy + 1][game.posx] = temp;
	  game = move_down(game);
	}
      else if (game.map[posy + 1][game.posx] == ' ')
	{
	  temp = game.map[posy][game.posx];
	  if (game.mapbase[posy][game.posx] == 'O' && (game.nbo += 1) > 0)
	    game.map[posy][game.posx] = 'O';
	  else
      	    game.map[posy][game.posx] = ' ';
	  game.map[posy + 1][game.posx] = temp;
      	  game = move_down(game);
	}
    }
  return (game);
}
