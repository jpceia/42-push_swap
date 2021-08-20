/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:50:03 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/19 21:52:29 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	while (ft_contains(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_contains(s1[end], set) && start < end)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
