/*
** my.h for my in /home/julian-ladjani/delivery/PSU/my_ls/PSU_2016_my_ls/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Mon Nov 28 16:12:40 2016 julian ladjani
** Last update Feb Dec 19 20:52:33 2016 Julian Ladjani
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <dirent.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <ncurses.h>
# include <string.h>

typedef struct		s_game
{
  	int		nbo;
  	char		**mapbase;
  	char		**map;
  	int		posx;
  	int		posy;
  	int		mapx;
  	int		mapy;
  	int		win;
  	int		error;
  	int		trow;
  	int		tcol;
}			t_game;

void		my_putstr(char *str);
void		my_putstr_error(char *str);
void		my_putchar(char c);
void		print_sokoban(t_game game);
void		my_sokoban(t_game game);

int		my_strlen(char *str);
int		main(int ac, char **av);
int		flag_search_ls(char c);
int		my_printf(char *str, ...);
int		my_strcmp(char *str1, char *str2);
int		my_comp_alf(char *s1, char *s2);
int		my_strlen(char *str);

char		*my_strcpy(char *dest, char *src);
char		*my_strcat(char *dest, char *src);
char		*my_strcapitalize(char *str);
char		**parse_it(char *path, char **map);

t_game		prepare_my_game(char *path);
t_game		map_lenght(t_game game);
t_game		check_map(t_game game);
t_game		check_term(t_game game);
t_game		move_up(t_game game);
t_game		move_down(t_game game);
t_game		move_left(t_game game);
t_game		move_right(t_game game);


#endif /* !MY_H_ */
