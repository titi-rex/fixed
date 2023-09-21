/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:58:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/21 22:58:45 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fixed.h"
#include "../include/libft.h"

uint64_t	ft_iterative_power(uint64_t nb, int power)
{
	uint64_t	res;

	if (power < 0)
		return (0);
	res = 1;
	if (power == 0)
		return (1);
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

bool	only_zero(int raw, int start)
{
	int	i;

	i = N_FRAC_BITS - start;
	while (i >= 0)
	{
		if (raw & (1 << i))
			return (0);
		--i;
	}
	return (1);
}

int	len_num(long long unsigned int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num /= 10;
		++i;
	}
	return (i);
}

uint64_t	get_frac(int32_t raw, int *idx)
{
	uint64_t	res;
	int			pow;

	res = 0;
	pow = 1;
	*idx = 1;
	while (*idx <= N_FRAC_BITS)
	{
		if (raw & (1 << (N_FRAC_BITS - *idx)))
			res += ft_iterative_power(5, pow);
		++pow;
		++*idx;
		if (only_zero(raw, *idx))
			break ;
		res *= 10;
	}
	return (res);
}


void	print_fixed(int32_t raw)
{
	uint64_t	res;
	int			idx;
	char		buf[17];
	int			len;
	int			j;

	ft_bzero(buf, sizeof(buf));
	res = get_frac(raw, &idx);
	len = len_num(res);
	j = 0;
	buf[0] = '.';
	while (++j < (idx - len - 1))
		buf[j] = '0';
	idx = len + j;
	while (--idx > N_PRINT_FRAC)
		res /= 10;
	while (idx >= j)
	{
		buf[idx] = res % 10 + 48;
		res /= 10;
		--idx;
	}
	ft_putnbr_fd(FIXED_TO_INT(raw), 1);
	ft_putstr_fd(buf, 1);
}
