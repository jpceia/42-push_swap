/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 06:05:31 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/21 16:03:02 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include "libft.h"

int		ft_strcmp(char *s1, char *s2);
int		ft_mod(int a, int b);
int		ft_intmax(int x, int y);
int		ft_intmin(int x, int y);
char	*ft_lltoa(long long nb);
long	ft_atol(const char *str);
char	*ft_ulltoa(unsigned long long nb);
char	*ft_lltoa_base(long long nb, const char *base);
char	*ft_ulltoa_base(unsigned long long nb, const char *base);
int		ft_contains(char c, char const *s);
char	*ft_strreverse(char *s);
int     ft_isspace(int c);

#endif
