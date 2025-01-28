/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:55:44 by emustafa          #+#    #+#             */
/*   Updated: 2024/08/11 12:14:29 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ret;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	end = start + ft_strlen(s1);
	while (*start && ft_isset(*start, (char *)set))
		++start;
	while (start < end && ft_isset(*(end - 1), (char *)set))
		--end;
	ret = ft_substr(start, 0, end - start);
	return (ret);
}
