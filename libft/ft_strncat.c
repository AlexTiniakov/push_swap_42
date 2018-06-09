/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:04:31 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/21 13:18:07 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (s1[i++] != '\0')
		;
	while (s2[++j] != '\0' && n--)
		s1[i++ - 1] = s2[j];
	s1[--i] = '\0';
	return (s1);
}
