/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:53:32 by tlegrand          #+#    #+#             */
/*   Updated: 2023/09/18 23:41:36 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <stdint.h>

# define N_FRAC_BITS 8
# define L_BIT_MASK	(1 << N_FRAC_BITS) 
# define R_BIT_MASK	(1 >> N_FRAC_BITS) 

# define INT_TO_FIXED(i) i << N_FRAC_BITS
# define FIXED_TO_INT(fixed) fixed >> N_FRAC_BITS

# define FLOAT_TO_FIXED(f) f * L_BIT_MASK
# define FIXED_TO_FLOAT(fixed) (float)fixed / L_BIT_MASK


# define FX_NEG(a) ~a + 1
# define FX_ADD(a, b) a + b 
# define FX_SUB(a, b) a - b
# define FX_MULT(a, b) (a * b) >> N_FRAC_BITS
# define FX_DIV(a, b) (a << N_FRAC_BITS) / b 


struct s_fixed 
{
	int32_t	rawBits;
	int			point;	
};

#endif