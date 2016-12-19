/*
** main.c for my_sokoban in /home/julian-ladjani/delivery/PSU/my_sokoban/PSU_2016_my_sokoban/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Feb Dec 19 09:20:19 2016 Julian Ladjani
** Last update Feb Dec 19 20:42:15 2016 Julian Ladjani
*/

#include <stdio.h>
#include <stdlib.h>

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
      if (line[0] != '#' || line[read] != '#' || tab >= 99)
	exit(84);
      if ((map[tab] = malloc((read + 1) * sizeof(char *))) == NULL)
	exit(84);
      my_strcpy(map[tab], line)
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

  if (ac < 2)
    exit(84);
  game = prepare_my_game(av[1]);
  my_sokoban(game);
  return (0);
}
