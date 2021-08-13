/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 06:05:31 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/13 09:37:24 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include "libft.h"

int     ft_strcmp(char *s1, char *s2);
char	*ft_lltoa(long long nb);
char	*ft_ulltoa(unsigned long long nb);
char	*ft_lltoa_base(long long nb, const char *base);
char	*ft_ulltoa_base(unsigned long long nb, const char *base);
int		ft_contains(char c, char *s);
char	*ft_strreverse(char *s);

#endif
