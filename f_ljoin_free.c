/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ljoin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmizin <nmizin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:53:00 by nmizin            #+#    #+#             */
/*   Updated: 2018/04/22 09:55:42 by nmizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*f_join_free(char *s1, char *s2, int i)
{
	char		*new;
	size_t		sumconcat;
	int			j;
	int			k;

	j = -1;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	sumconcat = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (sumconcat + 1));
	if (!new)
		return (NULL);
	while (s1[++j])
		new[j] = s1[j];
	while (s2[k])
		new[j++] = s2[k++];
	new[j] = '\0';
	if (i == 1 || i == 3)
		free(s1);
	if (i == 2 || i == 3)
		free(s2);
	return (new);
}
