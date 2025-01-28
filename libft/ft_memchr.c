/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 01:20:53 by emustafa          #+#    #+#             */
/*   Updated: 2024/08/11 12:11:19 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_usc	*str;
	t_usc	chr;
	size_t	i;

	str = (t_usc *)s;
	chr = (t_usc)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
