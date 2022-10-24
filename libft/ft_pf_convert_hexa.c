/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_convert_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:42:24 by lasalmi           #+#    #+#             */
/*   Updated: 2022/06/03 00:03:48 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_status	ft_pf_generate_hexastr(t_strdata *strdata, \
size_t count, char *buf)
{
	size_t	total_len;
	size_t	i;

	i = 0;
	total_len = strdata->strlen + count + 2 + 1;
	strdata->variable_str = (char *)malloc(total_len);
	if (!strdata->variable_str)
		return (MALLOCFAIL);
	strdata->variable_str[i++] = '0';
	strdata->variable_str[i++] = 'x';
	while (count-- > 0)
		strdata->variable_str[i++] = '0';
	ft_strlcpy(&strdata->variable_str[i], buf, strdata->strlen + 2);
	strdata->strlen = total_len - 1;
	return (OKAY);
}

/* Counts the amount of zeropadding needed. The +2 f for 0x. */
static size_t	ft_pf_count_zeropad(t_strdata *strdata, size_t count)
{
	if (strdata->width < (strdata->strlen + count + 2))
		return (0);
	else
		return (strdata->width - (strdata->strlen + count + 2));
}

static t_status	ft_pf_check_precision(t_strdata *strdata, char *buf)
{
	size_t		added_zeroes;
	t_status	ret;

	added_zeroes = 0;
	ret = OKAY;
	if (strdata->precision > strdata->strlen)
		added_zeroes = strdata->precision - strdata->strlen;
	if (strdata->flags.pad_with_zeroes == 1)
		added_zeroes += ft_pf_count_zeropad(strdata, added_zeroes);
	ret = ft_pf_generate_hexastr(strdata, added_zeroes, buf);
	if (ret == MALLOCFAIL)
		ft_pf_mallocfail(strdata);
	return (ret);
}

t_status	ft_pf_convert_hexa(t_strdata *strdata, long long ptr)
{
	char		buffer[50];
	static char	table[] = "0123456789abcdef";
	size_t		i;
	t_status	ret;

	i = 50;
	buffer[--i] = '\0';
	if (ptr == 0 && !strdata->explicit_zeroprec)
		buffer[--i] = '0';
	while (ptr > 0)
	{
		buffer[--i] = table[ptr % 16];
		ptr /= 16;
	}
	strdata->strlen = 49 - i;
	ret = ft_pf_check_precision(strdata, &buffer[i]);
	return (ret);
}
