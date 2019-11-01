/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** mehdi
*/

# include "my.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

char	**cut_dat(int i, t_list *bsq, char *str, char **tab)
{
	i = 0;
	bsq->x = 0;
	bsq->y = 0;
	while (str[i] != '\0') {
		if (str[i] == '\n') {
			bsq->y++;
			bsq->x = 0;
		}
		else {
			tab[bsq->y][bsq->x] = str[i];
			tab[bsq->y][bsq->x+1] = '\0';
			bsq->x++;
			bsq->len = bsq->x;
		}
		i++;
	}
	return (tab);
}

char	**my_alloc(char **tab, t_list *bsq, int i)
{
	tab = malloc(sizeof(char *) * bsq->y+1);
	i = 0;
	while (i != bsq->y) {
		tab[i] = malloc(sizeof(char) * (bsq->x + 1));
		i++;
	}
	return (tab);
}
char	**stock_map(char *str, t_list *bsq)
{
	char **tab = NULL;
	bsq->x = 0;
	bsq->y = 0;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == '\n') {
			bsq->y++;
			i++;
		}
		else {
			bsq->x++;
			i++;
		}
	}
	tab = my_alloc(tab, bsq, i);
	tab = cut_dat(i, bsq, str, tab);
	return (tab);
}

void	algo(char *str, t_list *bsq)
{
	int i = 0;
	int n;
	char **map = NULL;

	while (str[i] != '\n')
		&*++str;
	&*str++;
	i++;
	n = 0;
	while (str[++n] != '\n');
	map = stock_map(str, bsq);
	bsq->maxsize = 0;
	square_code(bsq, map);
	square_aff(map, bsq);
	while (map[i] != NULL) {
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(int ac, char **av)
{
	int	fd;
	t_list	bsq;
	struct	stat buf;

	if (ac != 2)
		return (84);
	else {
		stat(av[1], &buf);
		bsq.buff = malloc(sizeof(char) * buf.st_size +1);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (84);
		else
			read(fd, bsq.buff,  buf.st_size);
		bsq.buff[buf.st_size] = '\0';
		close (fd);
		algo(bsq.buff, &bsq);
		free(bsq.buff);
	}
	return (0);
}
