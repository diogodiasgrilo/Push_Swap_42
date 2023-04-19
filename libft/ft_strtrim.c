/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:44:11 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/12 14:08:49 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_to_trim(char c, const char *set)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (c == set[i])
			return (1);
	}
	return (0);
}

unsigned int	ft_get_start(char const *s1, char const *set)
{
	int				i;
	unsigned int	start;

	i = 0;
	start = 0;
	while (s1[i])
	{
		if (ft_to_trim(s1[i], set))
			start++;
		else
			break ;
		i++;
	}
	return (start);
}

int	ft_get_end(char const *s1, char const *set, int len)
{
	int	end;

	end = 0;
	while (s1[len])
	{
		if (ft_to_trim(s1[len], set))
		{
			len--;
			end++;
		}
		else
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				len;
	unsigned int	start;
	int				end;
	int				size;
	char			*trimmed;

	len = ft_strlen(s1);
	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set, len - 1);
	size = len - start - end;
	trimmed = ft_substr(s1, start, size);
	return (trimmed);
}

// int	main(void)
// {
// 	char s1[] = "STRTRIM_TEST !";
// 	printf("%s\n", ft_strtrim(s1, "SAT"));
// }
