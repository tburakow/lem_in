/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_conv_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:59:26 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_infnan(long double nb, char *str)
{
	if (nb != nb)
	{
		ft_strlcpy(str, "nan", 4);
		return (1);
	}
	if (nb == -1.0 / 0 || nb == 1.0 / 0)
	{
		ft_strlcpy(str, "inf", 4);
		return (1);
	}
	return (0);
}

static	size_t	ft_get_decimal(long double nb, char *temp, \
size_t i, t_strdata *strdata)
{
	size_t	count;

	count = strdata->precision + 1;
	temp[i++] = '.';
	nb -= (long long)nb;
	while (count--)
	{
		nb *= 10;
		temp[i++] = (int)nb + '0';
		nb -= (long long)nb;
	}
	temp[i] = '\0';
	return (i - 1);
}

static	size_t	ft_get_integral(long double nb, char *temp)
{
	unsigned long long	integral;
	char				result[20];
	size_t				i;
	size_t				j;

	j = 0;
	i = 18;
	result[19] = '\0';
	integral = (unsigned long long)nb;
	if (!integral)
	{
		temp[j++] = '0';
		return (j);
	}
	while (integral > 0)
	{
		result[i--] = (integral % 10) + '0';
		integral /= 10;
	}
	while (result[++i])
		temp[j++] = result[i];
	return (j);
}

void	ft_pf_conv_f(t_vardata *vardata, t_strdata *strdata, \
long double nb, char *str)
{
	char	*temp;
	size_t	i;

	if (ft_infnan(nb, str))
		return ;
	temp = (char *)malloc((size_t)(vardata->intlen + strdata->precision + 5));
	if (!temp)
		ft_pf_mallocfail(strdata);
	if (nb < 0)
		nb *= -1;
	i = ft_get_integral(nb, temp);
	i = ft_get_decimal(nb, temp, i, strdata);
	ft_pf_round_f_str(&temp, strdata, i, nb);
	i = 0;
	while (temp[i])
		*str++ = temp[i++];
	free(temp);
}
