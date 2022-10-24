/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:08:07 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 12:10:09 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	add_to_map(t_hashmap *map, char *key, void *ptr)
{
	map->key = key;
	map->ptr = ptr;
	return (1);
}

static	int	handle_collision(t_hashmap *map, unsigned long long i, \
char *key, void *ptr)
{
	while (map[i].ptr && i < MAP_SIZE)
	{
		if (ft_strequ(key, map[i].key))
			return (0);
		i++;
	}
	if (i < MAP_SIZE && !map[i].ptr)
		return (add_to_map(&map[i], key, ptr));
	if (i >= MAP_SIZE)
		i = 0;
	while (map[i].ptr && i < MAP_SIZE)
	{
		if (ft_strequ(key, map[i].key))
			return (0);
		i++;
	}
	if (i < MAP_SIZE && !map[i].ptr)
		return (add_to_map(&map[i], key, ptr));
	return (-1);
}

int	ft_hash_add(void *ptr, char *key)
{
	t_hashmap			*map;
	unsigned long long	hash;
	unsigned long long	i;

	hash = ft_hash_key(key);
	map = ft_hash_map();
	i = hash % MAP_SIZE;
	if (!map[i].ptr)
		return (add_to_map(&map[i], key, ptr));
	if (map[i].ptr && ft_strequ(key, map[i].key))
		return (0);
	return (handle_collision(map, i, key, ptr));
}
