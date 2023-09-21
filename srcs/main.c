/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:54:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/21 23:15:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fixed.h"
#include "../include/libft.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <inttypes.h>


void	mprintf(char *str, int32_t f)
{
	ft_printf("%s", str);
	print_fixed(f);
	ft_printf("\n");
}

int	main(void)
{
	int32_t			f1;
	int32_t			f2;
	int32_t			f3;


	f1 = FLOAT_TO_FIXED(1.75f);
	f2 = FLOAT_TO_FIXED(5.5f);

	mprintf("f1 ", f1);
	mprintf("f2 ", f2);
	
	f3 = FX_ADD(f1, f2);
	mprintf("sum ", f3);

	f3 = FX_SUB(f1, f2);
	mprintf("sub ", f3);

	f3 = FX_MULT(f1, f2);
	mprintf("mult ", f3);

	f3 = FX_DIV(f1, f2);
	mprintf("div ", f3);

	return (0);
}
