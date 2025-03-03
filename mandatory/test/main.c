/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <massias.antoine.pro@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:42:40 by amassias          #+#    #+#             */
/*   Updated: 2025/03/03 10:32:24 by amassias         ###   ########.fr       */
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

extern size_t	ft_strlen(const char *str);
extern char		*ft_strcpy(char *dst, const char *src);

static void test_strlen();
static void test_strcpy();

int	main(void)
{
	test_strlen();
	test_strcpy();
	return (0);
}

static void test_strlen()
{
	const char		*strs[] = {
		"",
		"aled",
		"wawawawawawawawawawawawaw"
	};
	const size_t	n = sizeof(strs) / sizeof(char *);

	printf("TESTING STRLEN (%zu tests)\n", n);
	printf("============================\n");
	for (size_t i = 0; i < sizeof(strs) / sizeof(char *); ++i)
	{
		const char	*str = strs[i];
		if (ft_strlen(str) == strlen(str))
			printf("ft_strlen (%zu) passed.\n", i);
		else
			printf("ft_strlen (%zu) did not pass.\n", i);
	}
	printf("============================\n");
}

static void test_strcpy()
{
	const char		*strs[] = {
		"",
		"aled",
		"wawawawawawawawawawawawaw"
	};
	char buffer[512];
	const size_t	n = sizeof(strs) / sizeof(char *);

	printf("TESTING STRCPY (%zu tests)\n", n);
	printf("============================\n");
	for (size_t i = 0; i < sizeof(strs) / sizeof(char *); ++i)
	{
		const char	*str = strs[i];
		char		*res = ft_strcpy(buffer, str);

		if (res == buffer && strlen(res) == strlen(str) && strcmp(res, str) == 0)
			printf("ft_strcpy (%zu) passed.\n", i);
		else
			printf("ft_strcpy (%zu) did not pass... (%p => %p, \"%s\" => \"%s\")\n", i, str, res, str, res);
	}
	printf("============================\n");
}
