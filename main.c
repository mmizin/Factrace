/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 12:15:57 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/22 12:16:00 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		f_part_one(mpz_t *get_num, mpz_t *one, mpz_t *two, mpz_t *three)
{
	mpz_init(*get_num);
	mpz_init(*two);
	mpz_init(*one);
	mpz_init(*three);
	mpz_set_ui(*two, 2);
	mpz_set_ui(*one, 1);
	mpz_set_ui(*three, 1);
	return (1);
}

static void		f_print(t_hot *f_race)
{
	mpz_t get_num;
	mpz_t one;
	mpz_t two;
	mpz_t three;

	f_part_one(&get_num, &one, &two, &three);
	while (f_race->next != NULL)
	{
		mpz_init_set_str(get_num, f_race->str, 10);
		while (mpz_get_d(one) != 0)
		{
			mpz_mmod(one, get_num, two);
			mpz_add_ui(two, two, 1);
		}
		gmp_printf("%Zd=", get_num);
		mpz_sub(two, two, three);
		gmp_printf("%Zd*", two);
		mpz_div(one, get_num, two);
		gmp_printf("%Zd\n", one);
		f_race = f_race->next;
	}
}

static int		f_is_file(int *fd, t_hot **f_race)
{
	int		c;
	char	*line;
	t_hot	*tmp;

	c = 0;
	(*f_race) = (t_hot *)malloc(sizeof(t_hot));
	tmp = *(f_race);
	while ((get_next_line(*fd, &line)) == 1)
	{
		(*f_race)->str = ft_strnew(1);
		if (!*line)
			c++;
		if (c == 1)
		{
			(*f_race)->next = NULL;
			*(f_race) = tmp;
			return (1);
		}
		(*f_race)->str = f_join_free((*f_race)->str, line, 1);
		(*f_race)->next = (t_hot *)malloc(sizeof(t_hot));
		(*f_race) = (*f_race)->next;
	}
	(*f_race)->next = NULL;
	*(f_race) = tmp;
	return (1);
}

int				main(int argc, char *argv[])
{
	int		fd;
	t_hot	*f_race;

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		fd = 0;
	if (fd > 0 && argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	f_is_file(&fd, &f_race);
	f_print(f_race);
	return (0);
}
