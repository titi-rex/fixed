/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:53:32 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/21 23:15:11 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <stdint.h>
# include <math.h>
# include <stdbool.h>

# define N_FRAC_BITS 16
# define N_PRINT_FRAC 6
# define L_BIT_MASK	(1 << N_FRAC_BITS) 
# define R_BIT_MASK	(1 >> N_FRAC_BITS) 

# define INT_TO_FIXED(i) ((i) << N_FRAC_BITS)
# define FIXED_TO_INT(fixed) ((fixed) >> N_FRAC_BITS)

# define FLOAT_TO_FIXED(f) roundf((f * L_BIT_MASK))
# define FIXED_TO_FLOAT(fixed) ((float)(fixed) / L_BIT_MASK)

# define FX_NEG(a) (~(a) + 1)
# define FX_ADD(a, b) ((a) + (b))
# define FX_SUB(a, b) ((a) - (b))
# define FX_MULT(a, b) (((a) * (b)) >> N_FRAC_BITS)
# define FX_DIV(a, b) (((a) << N_FRAC_BITS) / (b) )


typedef union
{
	int32_t	raw;
	struct
	{
		uint32_t	fpart: 16;
		int32_t		ipart: 16;
	} parts;
} fixed16_16_t;

struct s_fixed 
{
	int32_t	rawBits;
	int			point;	
};



void	print_fixed(int32_t raw);

#endif

// 2 -1	   -2   -3    -4     -5       -6     -7				-8			-16
// = 0.5 0.25 0.125 0.0625 0.03125 0.015625 0.0078125   0.00390625  0.00001526
// 5  1   2     3      4      5        6      7				8
// = 5   25   125    625     3125   15625    78125        390625