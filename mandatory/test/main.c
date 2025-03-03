/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <massias.antoine.pro@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:42:40 by amassias          #+#    #+#             */
/*   Updated: 2025/03/03 10:07:57 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST(CMP, N, TEST_FUN, TARGET_FUN, ...)						\
{																	\
	int __r = CMP(TEST_FUN(__VA_ARGS__), TARGET_FUN(__VA_ARGS__));	\
	if (__r == 0)													\
		printf(#TEST_FUN " (%zu) passed.\n", N);					\
	else															\
		printf(#TEST_FUN " (%zu) did not pass.\n", N);				\
}																	\

extern int	ft_strlen(const char *str);

static int	cmp_int(int a, int b);

int	main(void)
{
	const char	*strs[] = {
		"",
		"aled",
		"wawawawawawawawawawawawaw"
	};

	for (size_t i = 0; i < sizeof(strs) / sizeof(char *); ++i)
		TEST(cmp_int, i, ft_strlen, strlen, strs[i]);
	return (0);
}

int	cmp_int(int a, int b)
{
	return (b - a);
}
