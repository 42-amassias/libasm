/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <massias.antoine.pro@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:42:40 by amassias          #+#    #+#             */
/*   Updated: 2025/03/03 11:07:28 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

extern size_t	ft_strlen(const char *str);
extern char		*ft_strcpy(char *dst, const char *src);
extern int		ft_strcmp(const char *dst, const char *src);

static void test_strlen();
static void test_strcpy();
static void test_strcmp();

int	main(void)
{
	test_strlen();
	test_strcpy();
	test_strcmp();
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

static void test_strcmp()
{
	const char		*strs1[] = {
		"",
		"aa",
		"aled",
		"noo"
		"wawawawawawawawawawawawaw"
	};
	const char		*strs2[] = {
		"",
		"",
		"aled",
		"wawawawawawawawawawawawaw"
		"aled"
	};
	static_assert(sizeof(strs1) / sizeof(char*) == sizeof(strs2) / sizeof(char*));
	const size_t	n = sizeof(strs1) / sizeof(char *);
	printf("TESTING STRCMP (%zu tests)\n", n);
	printf("============================\n");
	for (size_t i = 0; i < n; ++i)
	{
		const char	*str1 = strs1[i];
		const char	*str2 = strs2[i];

		const int	r1 = strcmp(str1, str2);
		const int	r2 = ft_strcmp(str1, str2);

		if (r1 == r2)
			printf("ft_strcpy (%zu) passed.\n", i);
		else
			printf("ft_strcpy (%zu) did not pass... (\"%s\", \"%s\" => %d (%d expected))\n", i, str1, str2, r2, r1);
	}
	printf("============================\n");
}
