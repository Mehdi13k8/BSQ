/*
** EPITECH PROJECT, 2018
** *
** File description:
** a
*/

#include "my.h"

int	good_square(t_list *bsq, char **map, int y, int x)
{
	int i = 0;
	int i2 = 0;

	while (i < bsq->size && i+x < bsq->len) {
		i2 = 0;
		while (i2 < bsq->size && i2+y < bsq->y) {
			if (map[i2+y][i+x] != '.')
				return (0);
			i2 += 1;
		}
		i++;
	}
	if (i != bsq->size || i2 != bsq->size)
		return (0);
	return (1);
}

int	size_recup(t_list *bsq, char **map, int idx1, int idx2)
{
	while (good_square(bsq, map, idx1, idx2))
		bsq->size += 1;
	bsq->size = bsq->size - 1;
	return (0);
}

void	is_square(t_list *bsq, char **map, int idx1, int idx2)
{
	bsq->size = 1;

	size_recup(bsq, map, idx1, idx2);
	if (bsq->size > bsq->maxsize) {
		bsq->y2 = idx2;
		bsq->x2 = idx1;
		bsq->maxsize = bsq->size;
	}
}

void	modif_square(t_list *bsq, char **map)
{
	int i = 0;
	int j = 0;

	while (i < bsq->maxsize) {
		j = 0;
		while (j < bsq->maxsize) {
			map[i + bsq->x2][j + bsq->y2] = 'x';
			j++;
		}
		i++;
	}
}

void	square_code(t_list *bsq, char **map)
{
	int i = 0, j = 0;
	bsq->y2 = bsq->y, bsq->x2 = bsq->len;

	while (i + bsq->maxsize < bsq->y) {
		j = 0;
		while (j + bsq->maxsize < bsq->len) {
			is_square(bsq, map, i, j);
			j++;
		}
		i++;
	}
	modif_square(bsq, map);
}
