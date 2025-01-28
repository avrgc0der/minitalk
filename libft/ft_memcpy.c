/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoshahi < enoshahi@student.42abudhabi.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:08:31 by emustafa          #+#    #+#             */
/*   Updated: 2025/01/23 19:14:40 by enoshahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	t_usc	*tmp_src;
	t_usc	*tmp_dst;

	tmp_src = (t_usc *) src;
	tmp_dst = (t_usc *) dst;
	i = -1;
	if (!src && !dst)
		return (NULL);
	while (++i < n)
		tmp_dst[i] = tmp_src[i];
	return (dst);
}
