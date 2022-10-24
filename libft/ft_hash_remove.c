/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:13:07 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 12:10:38 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	remove_key(t_hashmap *map, int i)
{
	map[i].key = NULL;
	map[i].ptr = NULL;
	return (1);
}

static int	need_to_iterate(t_hashmap *map, int *i, char *key)
{
	if (*i >= MAP_SIZE)
		return (0);
	if (!map[*i].ptr)
		return (1);
	if (ft_strequ(map[*i].key, key))
		return (0);
	return (1);
}

static int	hash_search_beginning(t_hashmap *map, char *key)
{
	int	i;

	i = 0;
	while (need_to_iterate(map, &i, key))
		i++;
	if (i < MAP_SIZE)
		return (i);
	else
		return (-1);
}

int	ft_hash_remove(char *key)
{
	int			i;
	t_hashmap	*map;

	map = ft_hash_map();
	i = ft_hash_key(key) % MAP_SIZE;
	if (ft_strequ(key, map[i].key))
		return (remove_key(map, i));
	while (need_to_iterate(map, &i, key))
		i++;
	if (i < MAP_SIZE)
		return (remove_key(map, i));
	i = hash_search_beginning(map, key);
	if (i < 0)
		return (i);
	return (remove_key(map, i));
}
