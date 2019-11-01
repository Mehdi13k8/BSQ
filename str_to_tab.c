/*
** EPITECH PROJECT, 2018
** minshell
** File description:
** tab
*/

# include "my.h"
# include <stdio.h>

int	my_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		i++;
	}
	return (i);
}

int	my_line(char *str, int i)
{
	int	len = 0;

	while (str[i] != '\0') {
		if (str[i] == '\n')
			return (len);
		len++;
		i++;
	}
	return (0);
}

int	my_len(char *str)
{
	int	i = 0;
	int	len = 0;

	while (str[i] != '\0'){
		if (str[i] == '\n') {
			len++;
		}
		i++;
	}
	return (len);
}

void	my_str_to_tab(char *str, t_list *stock)
{
	int	a = 0, x = 0, y = 0;

	stock->tab = malloc(sizeof(char *) * my_len(str) + 1);
	stock->tab[y] = malloc(sizeof(char)* my_line(str, a) +1);
	while (str[a] != '\0') {
		if (str[a] == '\n') {
			stock->tab[y][x] = str[a];
			x = 0;
			y++;
			a++;
			stock->tab[y] = malloc(sizeof(char)
					* my_line(str, a) + 2);
		}
		else  {
			stock->tab[y][x] = str[a];
			x++;
			a++;
		}
	}
	stock->tab[y][x] = '\n';
}
