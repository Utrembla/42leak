/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 01:11:28 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_print_name(int i, int argc, char *name)	/* Функция печатает имя файла, только если в программу на печать отправленно несколько файлов */
{
	if (argc > 4)					/* Проверяем количество аргументов переданных в программу. Если количество аргументов больше четырех, значит
									** в программу для печати отправленно несколько файлов. И мы запускаем код ниже чтобы напечатать их имена */
	{
		if (i >= 4)					/* Если значение переменной 'i' больше или равно четырем значит сейчас мы печатаем имя не первого файла */
			ft_putstr("\n==> ");	/* По этому перед печатью символов обрамляющих имя программы мы добавим символ переноса строки для корректного отображения имени файла*/
		else						/* Если значение переменной 'i' меньше или равно четырем значит сейчас мы печатаем имя первого файла */
			ft_putstr("==> ");		/* Печатаем обрамляющие символы для корректного отображения имени файла */
		ft_putstr(name);			/* Печатаем само имя файла */
		ft_putstr(" <==\n");		/* Печатаем обрамляющие символы  для корректного отображения имени файла */
	}
}