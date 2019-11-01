/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** bsq
*/

# ifndef MY_H_
# define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef	struct	s_list
{
	char **tab;
	char	*buff;
	int	error;
	int	len;
	int	lencpy;
	int	x;
	int	x2;
	int	y;
	int	y2;
	int	width;
	int	lenght;
	int	xidx;
	int	yidx;
	int	size;
	int	maxsize;
}t_list;

int	main(int ac, char **av);
void	my_str_to_tab(char *str, t_list *bsq);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	my_creat(char *str, t_list *bsq);
int	good_square(t_list *bsq, char **map, int x, int y);
void    is_square(t_list *bsq, char **map, int idx, int idx2);
void    square_code(t_list *bsq, char **map);
int	is_line(t_list *bsq);
int	my_len(char *str);
void	my_algo(char *str, t_list *bsq);
void	square_aff(char **tab, t_list *bsq);

# endif /* MY_H_ */
