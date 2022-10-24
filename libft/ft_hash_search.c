/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:54:02 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 12:09:51 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	need_to_iterate_again(t_hashmap *map, int *i, char *key)
{
	if (*i >= MAP_SIZE)
		return (0);
	if (!map[*i].ptr || !map[*i].key)
		return (1);
	if (ft_strequ(map[*i].key, key))
		return (0);
	return (1);
}

static void	*hash_search_beginning(t_hashmap *map, char *key)
{
	int	i;

	i = 0;
	while (need_to_iterate_again(&map[i], &i, key))
		i++;
	if (i < MAP_SIZE)
		return (map[i].ptr);
	else
		return (NULL);
}

void	*ft_hash_search(char *key)
{
	t_hashmap	*map;
	int			i;

	map = ft_hash_map();
	i = ft_hash_key(key) % MAP_SIZE;
	if (!map[i].key)
		return (NULL);
	if (ft_strequ(map[i].key, key))
		return (map[i].ptr);
	while (need_to_iterate_again(map, &i, key))
		i++;
	if (i < MAP_SIZE)
		return (map[i].ptr);
	return (hash_search_beginning(map, key));
}
