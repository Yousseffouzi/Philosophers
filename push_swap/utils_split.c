/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <yofouzi@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:50:07 by root              #+#    #+#             */
/*   Updated: 2025/04/07 07:50:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(const char *str, unsigned int start, size_t n)
{
	size_t	i;
	size_t	str_n;
	char	*substr;

	if (!str)
		return (NULL);
	str_n = ft_strlen(str);
	if (start >= str_n)
		return (ft_calloc(1, sizeof(char)));
	if (n > str_n - start)
		n = str_n - start;
	substr = (char *)malloc((n + 1) * (sizeof(char)));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < n && str[start + i])
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
