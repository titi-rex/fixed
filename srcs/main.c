/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:54:09 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/18 23:43:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fixed.h"
#include <stdio.h>

int	main(void)
{
	int32_t	f;
	int32_t	f2;
	float	f3;

	printf("hello\n");
	f = INT_TO_FIXED(1);
	f2 = FLOAT_TO_FIXED(1.575);
	printf("%d\n", f);
	printf("%d\n", f2);
	f3 = FIXED_TO_FLOAT(f2);
	printf("%f\n", f3);
	return (0);
}
