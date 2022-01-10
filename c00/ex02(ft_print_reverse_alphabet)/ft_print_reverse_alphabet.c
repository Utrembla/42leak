/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/02/16 23:28:08 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex02/
**  Файлы для сдачи: ft_print_reverse_alphabet.c	
**  Разрешенные функции: write
**
** ************************************************************************** **
**
**  - Создайте функцию, которая отображает алфавит в нижнем регистре на одной 
**  строке в порядке убывания, начиная с символа «z».
**
**
**	- Функция должна быть обьялена следующим образом:
--------------------------------------------------------------------------------

    void	ft_print_reverse_alphabet(void)

--------------------------------------------------------------------------------
**
**
** ************************************************************************** **
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
** ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char	letter;

	letter = 'z';
	while (letter >= 'a')
	{
		ft_putchar(letter);
		letter--;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	int		i;
	char	c;

	i = 122;
	while (i >= 97)
	{
		c = i;
		ft_putchar(c);
		i--;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
