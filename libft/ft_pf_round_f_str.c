/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_round_f_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:05:16 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_norounding(char *str, size_t i, int alt_form)
{
	str[i--] = '\0';
	if (str[i] == '.' && !alt_form)
		str[i] = '\0';
}

static size_t	ft_roundup(char *str, size_t len, t_strdata *strdata)
{
	size_t	i;

	i = len - 1;
	if (str[i] == '.')
		i--;
	if (str[i] <= '8')
	{
		str[i] = str[i] + 1;
		if (!strdata->flags.alt_form && i > 0)
			str[i + 1] = '\0';
		return (i);
	}
	while (str[i] == '9' && i > 0)
	{
		str[i] = '0';
		i--;
		if (str[i] == '.')
			i--;
		if (str[i] <= '8' && str[i] >= '0')
			str[i] = str[i] + 1;
	}
	if (!strdata->flags.alt_form)
		str[len] = '\0';
	return (i);
}

static	void	ft_integral_extends(char **str, size_t original_size, \
t_strdata *strdata)
{
	char	*to_free;
	size_t	i;

	i = 2;
	to_free = *str;
	*str = (char *)malloc(original_size + 1);
	str[0][0] = '1';
	str[0][1] = '0';
	while (to_free[i - 1])
	{
		str[0][i] = to_free[i - 1];
		i++;
	}
	strdata->strlen++;
	free(to_free);
}

void	ft_pf_round_f_str(char **str, t_strdata *strdata, \
size_t i, long double nb)
{
	size_t	rounding_i;

	if (!ft_pf_need_upround(nb, strdata->precision, strdata))
	{
		ft_norounding(*str, i, strdata->flags.alt_form);
		return ;
	}
	rounding_i = ft_roundup(*str, i, strdata);
	if (rounding_i == 0 && str[0][rounding_i] == '9')
		ft_integral_extends(str, i, strdata);
}
