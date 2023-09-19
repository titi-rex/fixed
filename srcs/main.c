/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:54:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/19 22:43:41 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fixed.h"
#include "../include/libft.h"
#include <stdio.h>


#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

static const uint64_t TWO_THIRTY  = 1UL << 30;
static const uint64_t ONE_BILLION = 1000000000;

static uint32_t fraction(uint32_t fpart)
{
    assert(fpart < TWO_THIRTY);
    uint64_t result = (fpart * ONE_BILLION) / TWO_THIRTY;
    assert(result < ONE_BILLION);
    return result;
}

int maasdin(void)
{
     for (uint32_t i = 0; i < 32; i++)
         printf("%10" PRIu32 " = 0.%.9" PRIu32 "\n", i, fraction(i));

     return 0;
}


int	main(void)
{
	int32_t	f;
	int32_t	f2;
	int32_t	f3;
	float	fl;
	fixed2_30_t	x;

	x.raw = 0;
	x.raw = FLOAT_TO_FIXED(1.75);
	ft_printf("raw : %#32.32b\n", x.raw);
	ft_printf("ipart : %#32.24b\n", x.parts.ipart);
	ft_printf("fpart : %#32.8b\n", x.parts.fpart);
	

	fl = FIXED_TO_FLOAT(x.raw);
	printf("%f\n", fl);
	
	
	
	return (0);
	printf("hello\n");
	f = INT_TO_FIXED(1);
	f = FLOAT_TO_FIXED(1.2);
	printf("%d\n", f);
	printf("%d\n", f2);

	f3 = f + f2;
	fl = FIXED_TO_FLOAT(f3);
	printf("%f\n", fl);

	f3 = FX_SUB(f, f2);
	fl = FIXED_TO_FLOAT(f3);
	printf("%f\n", fl);

	
	return (0);
}
