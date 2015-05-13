/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:06:43 by ncharret          #+#    #+#             */
/*   Updated: 2015/03/23 19:03:32 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		**update_array(char **array, int len)
{
	char	**new_array;

	if (!(new_array = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	if (array)
	{
		while (len)
		{
			new_array[len - 1] = array[len - 1];
			len--;
		}
		free(array);
	}
	return (new_array);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	size;
	int		start;
	int		i;
	char	**return_value;

	i = 0;
	size = 1;
	return_value = (char **)malloc(1);
	while (s && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		if (!s[i])
			break ;
		while (s[i] != c && s[i])
			i++;
		size++;
		if (!(return_value = update_array(return_value, size)))
			return (NULL);
		if (!(return_value[size - 2] = ft_strsub(s, start, i - start)))
			return (NULL);
	}
	return_value[size - 1] = NULL;
	return (s ? return_value : NULL);
}
