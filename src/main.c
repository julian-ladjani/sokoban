/*
** main.c for my_sokoban in /home/julian-ladjani/delivery/PSU/my_sokoban/PSU_2016_my_sokoban/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Feb Dec 19 09:20:19 2016 Julian Ladjani
** Last update Mar Dec 20 19:11:46 2016 Julian Ladjani
*/

#include "my.h"

char		**parse_it(char *path, char **map)
{
  FILE		*stream;
  char		*line;
  size_t	len;
  ssize_t	read;
  int		tab;

  len = 0;
  line = NULL;
  tab = 0;
  if ((stream = fopen(path, "r")) == NULL)
    exit(84);
  while ((read = getline(&line, &len, stream)) != -1)
    {
      if ((line[0] != '#' || line[read - 2] != '#' || tab >= 99) &&
	  line[0] != '\n')
	exit(84);
      if ((map[tab] = malloc((read + 1) * sizeof(char *))) == NULL)
	exit(84);
      my_strcpy(map[tab], line);
      tab++;
    }
  map[tab] = NULL;
  free(line);
  fclose(stream);
  return (map);
}

int		main(int ac, char **av)
{
  t_game	game;
  int		win;

  if (ac < 2)
    exit(84);
  game = prepare_my_game(av[1]);
  win = my_sokoban(game);
  endwin();
  if (win < 0)
    return (1);
  else if (win > 0)
    return (0);
  return (0);
}
