/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 01:10:35 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_display_file(int i, int fd, int argc, char **argv)
{
	char	buffer;											/* Обьявляем переменную для временного хранения данных при чтениии из файла */
	int		rnum;											/* Обьявляем переменную для получения размера считанных из файла в буфер данных или же для хранения ошибок чтения файла */
	int		readed;											/* Обьявляем переменную для подсчета количества пройденных в файле байт */
	int		offset;											/* Обьявляем переменную для числа, которое скажет с какого места начать печать файла */

	if (argv[1][0] == '-' && (argv[1][1] == 'C' || argv[1][1] == 'c'))	/* Проверяем аргументы программы, если все хорошо запускаем код внутри */
	{
		ft_print_name(i, argc, argv[i]);					/* Запускаем функцию, которая печатает имя файла, только если файл отпраленный в аргументах на печать не один */
		offset = (ft_size_file(argv[i]) - ft_atoi(argv[2]));/* Посчитаем количество байт которое нам нужно пропустит чтобы напечатать определенное количество символов с конца файла */
		readed = 0;											/* Обнулим переменную отвечающую за хранение количества пройденных в файле байт */
		while (readed < offset)								/* Запускаем цикл который ориентируясь по переменной 'readed' и 'offset' сдвинет метку начала чтения файла
															** на ту позицию которая нам нужна чтобы напечатать строго определенное количество байт с конца файла */
		{
			if ((rnum = read(fd, &buffer, 1)) == -1)		/* Считываем на каждой итерации по одному байту из файла и проверяем прошло ли чтение файла без ошибок */
			{
				ft_display_custom_error(errno, argv[i]);	/* Если есть ошибка чтения файла, то печатаем ее */
				break;										/* И завершаем цикл смещения метки начала чтения файла */
			}
			readed += rnum;									/* Если ошибки чтения нет, то прибавляем к переменнной 'readed' количество считанных данных и переходим к след. итерации */
		}
		if (readed == offset)								/* Если предыдущий цикл без ошибок сдвинул метку начала чтения файла на ту позицию которая нам нужна 
															** то запускаем код ниже, который напечатает нужное нам количество данных с конца файла */
		{
			while  ((rnum = read(fd, &buffer, 1)))			/* Запускаем цикл, который с помощью функции 'read', сразу из условия, будет порциями считывать данные из файла 
															** во временный буфер используя дескриптор файла(идентификатор потока к файлу), адресс перменной 'buffer' и размер буфера.
															** После считывания порции данных из файла, функция сместит метку указывающую на адрес начала файла, с  
															** которого функция должна начать читать данные, на другой адрес, который будет указывать на символ
															** идущий после последнего считаного символа.
															** После завершения работы функция вернет нам число, отражающее колличество считанных в буфер символов, которое
															** мы сохраним в переменной 'rnum'.
															** Цикл проверит содержимое переменной 'rnum' и если он увидит что функция 'read' вернула некоторое число, то он 
															** запустит код внутри себя, который проверит это число, и если все хорошо, напечатает содержимое буфера */
			{
				if (rnum == -1)								/* Проверяем число которое нам вернула функция 'read'. Если это число равно '-1' значит у нас произошла ошибка чтения */
				{
					ft_display_custom_error(errno, argv[i]);/* И мы запускаем функцию для печати подробной ошибки, отправляя ей в аргументы содержимое переменной
															** 'errno' хранящей номер последней ошибки программы и адрес строки, с которой была связана ошибка */
					break;									/* И завершаем цикл */
				}
				write(1, &buffer, 1);						/* Если ошибки чтения нет, то печатаем считанные в буфер данные, и переходим к считаванию след порции данных */
			}
		}
	}
}