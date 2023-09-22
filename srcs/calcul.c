/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:40:27 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/22 22:47:24 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fixed.h"
#include "../include/libft.h"

int	ft_factorial(int nb)
{
	int		res;

	if (nb < 0)
		return (0);
	if (nb <= 0)
		return (1);
	res = 1;
	while (nb > 0)
	{
		res *= nb;
		nb--;
	}
	return (res);
}

int32_t	fx_power(int32_t fx, int pow)
{
	int32_t	res;
	
	if (pow == 1)
		return (1);
	res = FX_ONE;
	if (pow < 0)
	{
		while (pow < 0)
		{
			res = FX_DIV(res, fx);
			++pow;
		}
		return (res);
	}
	while (pow > 0)
	{
		res = FX_MULT(res, fx);
		--pow;
	}
	return (res);
}


int32_t	fx_sin(int32_t fx)
{
	if (fx > FX_PI || fx < -FX_PI)
		return (dprintf(2, "error not in range\n"), 0);

	int32_t	res;
	int64_t	tmp;
	int32_t	fac;

	res = fx;
	tmp = fx_power(fx, 3) / ft_factorial(3);
	res -= tmp;

	tmp = fx_power(fx, 5) / ft_factorial(5);
	res += tmp;

	tmp = fx_power(fx, 7) / ft_factorial(7);
	res -= tmp;

	tmp = fx_power(fx, 9) / ft_factorial(7);
	tmp = tmp / (9 * 8);
	res += tmp;
	return (res);
}
