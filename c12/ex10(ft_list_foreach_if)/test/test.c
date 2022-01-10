/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:34:54 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */

#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для
										 * подсчета размера (sizeof) и функцию(free) для освобождения выделеной памяти */
#include "ft_list.h"					/* Подключаем заголовочный файл содержащий нужную нам структуру */


/* ************************************************************************** */

void		ft_putchar(char c)			/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

t_list		*ft_create_elem(void *data)	/* Функция создает экземпляр структуры типа t_list, заполняет его данными - адрес из указателя data
										 * в первый элемент экземпляра структуры, нулевой адрес во второй элемент экземпляра структуры. И в 
										 * конце функция его возвращает адрес созданого экземпляра структуры типа t_list*/
{
	t_list	*tmp;						/* Обьявляем указатель структуры типа t_list для хранения там адреса экземпляра структуры типа t_list */

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))/* Инициализируем указатель, сохраняя туда адрес выделеной под экземпляр памяти */
		return ((void *)0);										/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
	tmp->next = ((void *)0);			/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры нулевой указатель */
	tmp->data = data;					/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры адрес принятого
										 * в аргументах элемента неизвестного типа */
	return (tmp);						/* Завершаем функцию и возвращаем адрес созданного нами экземпляра структуры типа t_list */
}

/* ************************************************************************** */

void		ft_putstr(void *str)			/* Функция принимает адрес неизвестного типа но предпологаая что там находится строка переводит адрес в
										 * тип 'char' и печатает cсодержимое */
{
	while (*((char *)str))
		ft_putchar(*((char *)str++));
}

int			ft_strcmp(char *s1, char *s2)	/* Функция сравнивает две строки и возвращает разницу между ними */
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/* Функция 'ft_list_foreach_if' c помощью других функций(адреса которых мы получили в аргументах) ищет среди цепи связанных между 
 * собой экземпляров структур(адрес которых мы получили в аргументах функции) тот экземпляр структуры, который содержит такие же 
 * данные, как и данные, которые содержатся по адресу, который мы получили с аргументами в указатель *data_ref.
 * Если функция находит экземпляр структуры с таким же содержимым, как и содержимое по адресу указателя *data_ref, то она печатает
 * содержимое этого экземпляра */
void		ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

int			main(void)
{
	t_list	*list;						/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */

	list = ft_create_elem("Bro ");		/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
										 * данных которыем мы ей отправим) и вернет адрес этого экземпляра структуры типа t_list,
										 * который мы сохраним в указателе на экземпляр структуры типа t_list */
	list->next = ft_create_elem("Hey ");/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
										 * данных которыем мы ей отправим) и вернет адрес этого экземпляра структуры типа t_list 
										 * И сохранит этот адрес в указателе на экземпляр структуры типа t_list, который хранится в одном из элементов 
										 * текущего экземпляра структуры, адрес которой хранится в указателе 'list' */
	/* И создадим еще дополнительно несколько экземпляров структуры, которые свяжем между собой и с предыдущим экземпляром */
	list->next->next = ft_create_elem("Hello ");
	list->next->next->next = ft_create_elem("My ");
	list->next->next->next->next = ft_create_elem("Cool ");
	list->next->next->next->next->next = ft_create_elem("Friend ");

	ft_list_foreach_if(list, &ft_putstr, list->next->next->data, &ft_strcmp);/* Ищем в текущей цепи связанных между собой экземпляров структур нужный 
										 * нам экземпляр с такой же строкой внутри. Если строка в одном из экземпляров цепи нашлась то печатаем её. */

	ft_putchar('\n');					/* Печатаем символ переноса строки для кореектного отображения вывода */
	return (0);							/* Завершаем функцию и возвращаем ноль */
}