/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 13:53:10 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */
/* ************************************************************************** */

/* Эта функция принимает число int разделяет на кусочки и добавляет каждой к отделенной друг от друга цифре 48 */ 

/* Зачем мы добавляем к числу 48? По тому что если сразу отправить в ft_putchar отделеное число например ft_putchar(5);
** то выведется не символ '5' а с символ '#', который хранится в таблице символов под числом 5 */

/*
**  т.е. чтобы напечетать любое число от 0 до 9 отправляя его в путчар мы:
**  либо дожны записать его код вот так ft_putchar(53); 
**  либо написать сам символ в кавычках вот так ft_putchar('5'); 
** 
**  Но мы будем высчитывать код символа каждую итерацию. Так что вариант нам нужен другой вариант, котрый мы описали ниже.
**  Мы будем высчитывать код символа за счет прибавления к числу кода нулевого символа. ВОТ ТАК ft_putchar(5 + 48); где 48 -код нулевого символа, ИЛИ ТАК ft_putchar(5 + '0');
**  Программма при приеме этого вычисления(5 + '0'  или 5 + 48) поймет что вы хотите увидеь символ под кодом 53 и наапечатает его.
**  (число должнобыть не меньше нуля и не больше 9 иначе вычисление не сработает)
*/

void	ft_putnbr(int nb)           /* Функция вывода числа */
{
	int	temp;                       /* Обьявляем переменную для временного хранения данных переменной 'nb' */
	int	size;                       /* Обьявляем переменную для хранения размера числа*/

	size = 1;                       /* Установим ей начальный размер */

	if (nb < 0)                     /* Проверяем яляется полученное нами число в 'nb' отрицательным */	
	{
		ft_putchar('-');            /* Если число отрицательное, то мы печатаем символ минуса '-' */ 
		nb = -nb;                   /* Делаем содержимое переменной 'nb' положительным, с помощью хитрости(nb = -nb), помня из математики, что минус на минус дает плюс */
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;                      /* Сохраним в переменную 'temp' наше число 'nb' для вычисления размера этого числа */

	while ((temp /= 10) > 0)        /* Вычисляем размер числа c помощью накопления количества умноженых десяток друг на друга */ 
		size *= 10;                 /* Если результ деления нашего числа в 'temp' на 10 больше нуля то увеличиваем переменную 'size' умножив ее содержимое на 10 */

                                    /* НУЖО ПОМНИТЬ что при делении целого числа на целое результат сохраняемый в переменной типа 'int' будет без плавающей точки. 
                                    ** она автоматически отбрасывается */ /* Пример: делим 4  на 10  в итоге результат будет 0.4 но в переменной типа 'int' сохраниться
                                    ** только 0, потому что всё после точки в числе отбрасывается и в целочисленную переменную не записывается. */

	temp = nb;                      /* Восстановим расстерзаное делением число в переменную 'temp'. Оно нам снова понадобится 
                                    ** для того чтобы отделить цифры нужного нам числа и напечатать по отдельности */

	while (size)                    /* проверяем длинну числа если длинна еще не равна нулю (в результате уменьшения на 10 в цикле) то продолжаем работу цикла */
	{
		ft_putchar((char)((temp / size)) + '0');/* Делим число на размер, который у нас получился */   /* тут тоже хитрость */  
                                    /* допустим размер полученогонами числа 345 получисля равным 100 */ 
                                    /* деля 345 на 100  мы получим 3.45*/ /* 0.45 отбрасывается по тому что идет приведение к целому числу */ /* и остаеться 3 */
                                    /* Так вот мы и отделяем 3 от 45 и уже можем ее напечатать тройку прибавив к ней 48, чтоб полуить код символа '3' */

		temp %= size;               /* Здесь с помощь деления числа temp (в примере у нас это 345) по модулю на size (в примере у нас это 100) мы получим 
                                    ** оставшуюся часть без первого символа temp ( т.е у нас получится 45. Тройка канула в лету. Так мы ее отбрасываем чтоб потом,
                                    ** на новой итерации цикла напечатать 4 и 5 и т.д по мере отделения и печати чисел,  и помере того как size уменьшается */

		size /= 10;                 /* после то как отделили 3 от 45 в числе 345 и после того как оставили себе только 45 для дальнейшего отделения. число 100 нам больше не нужно.
                                    ** Так что делим size на 10 чтобы в след итерации число 45 уже делилось на 10 отдавая 4 на печать, и еще 45 делилось по модулю на 10 сохраняя 5 
                                    ** на следующую итерацию, потом снова уменьшение size на 10 (чтобы можно было работать с temp, которое теперь уже хранит 5). 
                                    ** Теперь 5 делм на 1 получаем пять отдаем его на печать, 5 деленное по модулю на 1 сохраняет в переменную 0 но это нам уже не нужно.
                                    ** Потому что дальше size делится на 10 снова и размер size становится равным нулю. А при след итерации цикл будет проверять размер size 
                                    ** и если он равен 0 то цикл завершается */
                                    /* И жили они долго и счастливо, конец */
	}
}

/* ************************************************************************** */
/* ************************************************************************** */

int 	main(void)
{	
	ft_putnbr(345);                 /* тестим эту функцию */

	return (0);
}
