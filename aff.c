/*
** EPITECH PROJECT, 2018
** azeaz
** File description:
** zaeaz
*/

#include "my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
}

void	square_aff(char **tab, t_list *bsq)
{
	int i = 0;

	while (tab[i] != NULL) {
		write(1, tab[i], bsq->len);
		my_putchar('\n');
		i++;
	}
}
