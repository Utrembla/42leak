/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/25 02:57:31 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>					/* Подкоючаем библиотеку содержащую функцию для вывода символов(write) */
#include <stdlib.h>					/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для подсчета размера переменной(sizeof) */

/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putstr(char *str)		/* Функция печати строки */
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

/* ************************************************************************** */
/* ************************************************************************** */

int		ft_ctoi(char c)				/* Функция переводит символ в число и возвращает его. Если символ условиям не соответствует то возвращается (-1)*/
{
	if (c >= '0' && c <= '9')		/* Если символ числа от 0 до 9 */
		return (c - '0');			/* То вычесть из символа числа символ нуля чтобы в остатке осталось только само число в диапазоне до 9 включительно */
	if (c >= 'A' && c <= 'F')		/* Если символ в пределах от 'A' до 'F' то значит перед нами число в пределах от 10 до 16 включительно */
		return (c - 'A' + 10);		/* Чтобы его достать нужно из символа вычесть 'A' и к получившемуся числу прибавить 10.
									** После завершаем функцию и возвращаем добытое число */
	if (c >= 'a' && c <= 'f')		/* Если символ в пределах от 'a' до 'f' то значит перед нами число в пределах от 10 до 16 включительно */
		return (c - 'a' + 10);		/* Чтобы его достать нужно из символа вычесть 'a' и к получившемуся числу прибавить 10.
									** После завершаем функцию и возвращаем добытое число */
	return (-1);					/* Если символ не соответсвует ни одному условию то завершаем функцию и возвращаем (-1). */
}

/* ************************************************************************** */
/* ************************************************************************** */

int		ft_pow(int nb, int power)	/* Функция возведения в степень */
{
	int	result;						/* обьявляем переменную для хранения добытого результата */

	result = 1;						/* инициализируем ее единицей для начала вычислений результата возведения в степень */
	if(power < 0)					/* Проверяем соответствует ли число в степени условиям */
		return (0);					/* Если не соответствует то завершаем функцию и возвращаем ноль */
	if(power == 0)					/* Проверяем соответствует ли число в степени условиям */
		return (1);					/* Если не соответствует то завершаем функцию и возвращаем ноль */
	while (power--)					/* Запускаем цикл который умножит переменную 'result' на 'nb' столько раз сколько записано в 'power'. Возведет в 'nb' в степень 'power'. */
		result *= nb;				/* Умножая 'result' на 'nb' и сохраняя результат в той же переменной 'result' столько раз сколько записано в 'power'  
									** мы сможем получить результат возведения в степень 'power' числа 'nb'. */
	return (result);				/* Завершаем функцию и возвращаем результат возведения в степень */
}

/* ************************************************************************** */
/* ************************************************************************** */

/* Функция проверки массива с нужной на системой счисления на корректность */
int		ft_check_base(char *base)		/* Функция проверки массива с нужной на системой счисления на корректность. Она принимает 
										** адресс массива и возвращает, если все корректно, число отражающее размер  проверяемого
										** базового типа. Если же массив не пройдет проверку на корректность, то функция вернет '0' */
{
	int	i;								/* обьявляем счетчик */
	int	z;								/* обьявляем счетчик */

	i = 0;								/* инициализируем счетчик нулем чтобы начать с начала массива */
	if (!base || !base[1])				/* Проверяем наличие в массиве данных. Если массив пуст */
		return (0);						/* то мы завершаем функцию и возвращаем '0' */
	while (base[i])						/*  Запускаем цикл пройдется по всему массиву символов до тех пор пока мы не дойдетдо конца массива.
										** Он проверит относится ли каждый элемент массива только к символам цифр или букв алфавита, а так же выяснит
										** не повторяется ли символ в какой либо части текущего массива. */
	{
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z'))) /* Провеяем каждый елемент массива, чтобы там были только символы чисел
										** или букв алфавита */
			return (0);					/* Если в массиве есть что то не нужное нам, то мы завершаем функцию и возвращаем '0' */
										/* Теперь проверим повторяется ли текущий символ где ли бо еще в массиве с помощью цикла ниже */
		z = i + 1;						/* Используем переменную 'z' для хранения числа указывающего на ячейку, которая следует после той ячейки, на
										** которую указывает число, в переменной 'i' */
		while (base[z])					/* Запускаем цикл, который проверит все ячеки которые следуют за теми на которые указывает переменная 'i'
										** и выясним повторяется ли текущий символ в какой либо части текущего массива символов */
		{
			if (base[i] >= base[z])		/* Если символ из ячейки, на которую указывает переменная 'i', такой же что и в другой ячейке массива, 
										** на котрую указывает переменная 'z', или больше по значению */ 
				return (0);				/* То мы завершаем функцию и возвращаем '0' */
			z++;						/* Если же похожий или меньший символ не найден, то мы увеличиваем содержимое переменной 'z' для перехода
										** к проверке след ячейки массива и продолжаем цикл, пробегаясь по остальным ячейкам массива, сравнивая их
										** с символом из ячейки, на котрую указывает переменная 'i' */
		}
		i++;							/* Если мы дошли до сюда, значит текущий символ массива из ячейки на которую указывает переменная 'i'
										** соответсвует условиям и мы увеличиваем увеличиваем содержимое переменной 'i' для перехода к след ячейке
										** массива и проверке её содержимого на соответствие нашим условиям */
	}
	return (i);							/* Если дошли до сюда, значит массив проверен и соответсвует нашим условиям.
										** Завершаем функцию и возвращаем размер базового типа, как знак положительного прохождения теста */
}

/* ************************************************************************** */
/* ************************************************************************** */

/*
** (atoi) - ASCII to Integer(в целое число)
** Функция преобразует в целое десятичное число строку из указателя 'str', 
** содержащую число в строчном эквиваленте некторой системы счисления.
** Основание системы счисления определено содержимым указателя 'base'.


----------------------------------------------------------
:                                                        :
:             Перевод в десятичную систему               :
:                                                        :
----------------------------------------------------------

----------------------------------------------------------
:  Степень         4  3     2  1  0                      :
:   числа          |  |     |  |  |                      :
----------------------------------------------------------
:                  |  |     |  |  |                      :
:    hex           2  f(15) 5  4  a(10) = 193866         :
:                                                        :
----------------------------------------------------------

---------------------------------------------------------------------------------------------------
:                                                                                                 :
:                                                                                                 :
: 1 цифра числа(слева) * (исходная_система_счисления возведенная в степень позиции 5 числа( 4 ))  :
:                                                                                                 :
:           +                                                                                     :
:                                                                                                 :
: 2 цифра числа(слева) * (исходная_система_счисления возведенная в степень позиции 4 числа( 3 ))  :
:                                                                                                 :
:           +                                                                                     :
:                                                                                                 :
: 3 цифра числа(слева) * (исходная_система_счисления возведенная в степень позиции 3 числа( 2 ))  :
:                                                                                                 :
:           +                                                                                     :
:                                                                                                 :
: 4 цифра числа(слева) * (исходная_система_счисления возведенная в степень позиции 2 числа( 1 ))  :
:                                                                                                 :
:           +                                                                                     :
:                                                                                                 :
: 5 цифра числа(слева) * (исходная_система_счисления возведенная в степень позиции 1 числа( 0 ))  :
:                                                                                                 :
:                                                                                                 :
---------------------------------------------------------------------------------------------------

----------------------------------------------------------
:                                                        :
:    2  * (16^4) = 2  * 65536 = 131072 \                 :
:                                +      \                :
:    15 * (16^3) = 15 * 4096  = 61440    \               :
:                                +        \              :
:    5  * (16^2) = 5  * 256   = 1280       | = 193866    :
:                                +        /              :
:    4  * (16^1) = 4  * 16    = 64       /               :
:                                +      /                :
:    10 * (16^0) = 10 * 1     = 10     /                 :
:                                                        :
----------------------------------------------------------

----------------------   т.е   -----------------------------------------------
:                                                                            :
:                                                                            :
: (2*(16^4)) + (15*(16^3)) + (5*(16^2)) + (4*(16^1)) + (10*(16^0)) = 193866; :
:                                                                            :
: (2*65536) + (15*4096) + (5*256) + (4*16) + (10*1) = 193866;                :
:                                                                            :
: 131072 + 61440 + 1280 + 64 + 10 = 193866;                                  :
:                                                                            :
:                                                                            :
------------------------------------------------------------------------------

 */
int		ft_atoi_base(char *str, char *base)
{
	int		num;						/* Обьявляем перменную, в которую мы положим преобразованное число */
	int		negative;					/* Обьявляем перменную для хранения информации о том отрицательное это число или положительное */
	int		i;							/* Обьявляем перменную для счетчика, с помощью которого мы пройдемся по массиву переобразовывая каждый символ */
	int		pow;						/* Обьявляем перменную для счетчика, который будет говорить о том в какую степень возвести добытое из символа 
										** число в зависимости от позиции ячейки добытого из символа числа */
	int		base_type;					/* Обьявляем перменную для хранения информации о базовом типе числа в строке */

	negative = 1;						/* Инициализируем единицей переменную хранящую состояние. В конце функции она умножается на добытое число,
										** в случае если знак у числа в строке будет отрицательным. Это для того чтобы применить знак к добытому числу */
	i = 0;								/* Инициализируем нулем переменную счетчика чтобы начать работать с массивом символов с нулевой позиции */
	if((base_type = ft_check_base(base)))/* Запускаем проверку соответствия массива содержащего символы нужной нам системы счисления
										** и сохраняем результат в переменную 'base_type'.
										** Проверяем число, полученое после проверки массива, с нужной системой счисления. Если проверка прошла успешно,
										** то в переменной должно находиться положительное число. Если число положительно, то мы запускаем код внутри  */
	{
		if (*str == '-')				/* Если нулевая ячейка, массива символов 'str', хранит символ, который равен отрицательному знаку */
		{
			i++;						/* то переходим к след ячейке */
			negative = -1;				/* А в переменную 'negative' записываем (-1), чтобы потом, перед возвращением добытого числа ,умножить его
										** на эту переменную и получить такое же отрицательное число, какое было принято на преобразование */
		}
		while (str[i])					/* Запускаем цикл, который пройдется мо массиву символов(строке) и посчитает его длинну */
			i++;
		pow = 0;						/* Инициализируем нулем переменную указывающую на степень, в которую нужно будет возводить число отражающее
										** систему счисления */
		num = 0;						/* Инициализируем нулем переменную для хранения добытого числа */
		while (--i >= 0)				/* Запускаем цикл который начиная с конца масива перобразует символы в цифры и собирает их в одно число работая 
										** до тех пор пока не пройдет по всем ячейкам */
		{
			if ((ft_ctoi(str[i]) != -1) && (ft_ctoi(str[i]) < base_type))/* Если символ в ячейке соответствует условиям то запускаем преобразование символа */ 
				num += ft_ctoi(str[i]) * ft_pow(base_type, pow++);	/* получаем из символа число и умножаем это число на его систему счисления возведенную
																	** в степень, которая равна позиции символа в строке. И в конце сохраняем все в "num", 
																	** прибавля полученое к тому что там уже хранится */
		}
		return (num * negative);		/* Завершаем функцию и возвращаем полученый результат умноженый на единицу, хранящую полученный нами знак 
										** отрицательности или положительности конвертируемого числа */
	}
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */

/* 
** (atoi) - Integer to ASCII (целое число в строку из ASCII символов)
** Функция конвертирует целое число 'nbr' в строчный эквивалент и возвращает адресс строки с конвертированным числом. 
** Основание системы счисления для записи выходной строки определено содержимым указателя 'base'.
*/
char	*ft_itoa_base(int nbr, char *base)
{
	int		i;								/* Обьявляем счетчик для подсчета количества найденых символов*/
	int		j;								/* обьявляем счетчик для перемещения по финальному массиву */
	int		base_type;						/* Обьявляем переменную для хранения основания числа отражающего систему счисления, котораяе нам будет нужна для вычислений,
											** Это число мы получим после проверив массива содержащего нужную нам систему счисления */
	int		n[16];							/* Обьявляем массив целых чисел для печати */
	char	*final;							/* Обьявляем указатель на массив для которого выделим память для хранения результата конвертирования */

	i = 0;									/* Инициализируем счетчик найденых символов нулем */
	if ((base_type = ft_check_base(base)))	/* Запускаем проверку соответствия массива содержащего символы нужной нам системы счисления
											** и сохраняем результат в переменную 'base_type'.
											** Проверяем число, полученое после проверки массива, с нужной системой счисления. Если проверка прошла успешно,
											** то в переменной должно находиться положительное число. Если число положительно, то мы запускаем код внутри  */
	{
		if (nbr < 0)						/* Проверяем является отрицательным число, которое мы переводим в другую систему счисления */
		{
			nbr = -nbr;						/* Если да, то для последующих операций числом делаем его положительным используя хитрость(nbr = -nbr)
											** помня из математики, что минус на минус дает плюс  */
			n[i] = '-';						/* Сохраняем символ отрицательного числа(чтобы оно было перед тем как будет напечатано само число) */
			i++;
		}
		while (nbr)							/* Пока значение переменной хранящей число не равно нулю */
		{
			n[i] = nbr % base_type;			/* ВЫЧИСЛЯЕМ накаждой итерации цикла, то как выглядит каждый элемент текущего числа в нужной нам системе
											** счисления, с помощью 'base_type' (содержащего размер нужной нам системы счисления).
											** Для этого делим nbr на base_type по модулю и записывая результат в массив начиная с первой ячейки.
											** Так мы узнаем значение крайнего символа в нужной нам системе счисления */

			nbr /= base_type;				/* Теперь для вычисления оставшихся чисел уменьшаем само число в nbr, разделив его на 
											** 'base_type' (размер нужной нам системы счисления) и сохраняем результат в той же переменной nbr */

			i++;							/* Увеличиваем счетчик для перехода к след ячейке. Так же переменная i нам понадобиться позже. 
											** Накопленное в ней значение скажет нам о размере получившегося массива, которое мы используем 
											** чтобы напечатать символы в правильном порядке. */
		}
		if ((final = (char *)malloc(sizeof(char) * (i + 1))) == ((void *)0))/* Теперь выделим память для сохранения туда результата. 
											** Выделим память на 1 ячейку больше чем длинна нужного массива. Мы используем это чтобы создать 
											** массив с лишней ячейкой для записи в лишнюю ячейку результируючего символа '\0' */
			return (((void *)0));			/* Если что то пошло не так(не достаточно памяти) то возвращаем нулевой указатель(NULL) */
		if ((n[0] == '-'))					/* Прверяем было ли трансофрмироуемое число отрицательным */
			final[0] = n[0];				/* Если да то сохраняем в первую ячейку финального массива смивол '-' */
		j = 1;								/* Используем счетчик для перемещения по финальному массиву, инициализируя ее нулем чтобы 
											** начать заполнять массив с нулевой ячейки */
		while (i > 0)						/* Запускаем цикл который восстановит порядок найденых нами значений символов и запишет их в final */
		{
			--i;							/* Уменьшаем счетчик чтобы двигаться вниз по массиву отдающему символу */
			final[j] = base[n[i]];			/* Для этого мы используем найденные нами значения, каждой цифры числа 'nbr' сохраненные 
											** в массива 'n', как шифр к массиву хранящему значения базового типа.
											** Мы будем вызывать числа из массива 'n' и вставлять как указатель на нужное значение.
											** Чтобы восстановить порядок найденых нами символов(развернуть число в нормальный вид) мы 
											** будем заполнять его двигаясь по нему от начала к концу, a другой массив в это же время будет 
											** отправлять нам символы двигаясь с конца массива к началу */
			j++;							/* Увеличиваем счетчик чтобы двигаться по результирующему массиву вверх */
		}
		final[j] = '\0';					/* Записываем в конец массива символ завершающего нуля */
	}
	return (final);							/* Завершаем функцию и возвращаем адрес строки содержащей символы числа в нужной системе счисления */
}

/* ************************************************************************** */
/* ************************************************************************** */

/* Функция конвертирующая строку с числом(nbr) из одной системы счисления(base_from) в другую систему счисления(base_to) */
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)/* Принимаем в аргументах строку с числом, прошлую систему счисления и желаемую систему счисления */
{
	int dec;								/* Обьявим переменную для хранния числа преобразованного из прошлой системы счисления в десятичное число */
	char *final;							/* Обьявим указатель для адреса строки с результатом конвертирования  уже из десятичной системы в нужную нам систему счисления */
											/* А теперь мы плавно и переведем строку с числом определенной системы счисления сначала в  десятичное число
											** а потом переведем десятичное в строку с числом нужной нам системы счисления */
	dec = ft_atoi_base(nbr, base_from);		/* Вызовем функцию преобразования строки с числом определенной системы счислени в десятичное число и сохраним в "dec" */
	final = ft_itoa_base(dec, base_to);		/* Вызовем функцию преобразования десятичного числа в строку с числом определенной системы счислени и полученый адрес сохраним в "final" */

	return (final);							/* Возвращаем адресс полученой строки и завершаем функцию */
}

/* ************************************************************************** */
/* ************************************************************************** */

int     main(void)							/* Основаная функция */
{
	char *hex = "0123456789ABCDEF";			/* Обьявим и инициализируем строку с шестнадцатиричной системой счисления для передачи её в аргументы как тип 
											** желаемого результата */
	char *binary = "01";					/* Обьявим и инициализируем строку с двоичной системой счисления для передачи её в аргументы как показатель того
											** в какой системе счисления находится строки с числом "nbr" */
	char *number = "010100100101001010";	/* Обьявим и инициализруем строку содержащую число(84298) в определенной(двоичной) системе счисления для конвертирования
											** этого числа в другую систему сичсления */
	char *result;

	result = ft_convert_base(number, binary, hex);/* Запускаем функцию(ft_convert_base) которая берет строку с числом(в двоичной системе счисления) 
											** и преобразовывает его из текущей системы счисления(двоичной) в другую систему счисления(шестнадцатричную).
											** После перевода числа в другую систему счисления функция возвращает адресс сконвертированной строки с числом
											** в другой системе счислений(шестнадцатиричной). */
	ft_putstr(result);						/* Этот адрес мы отправляем на печать в функцию печати строки для проверки результата */
	ft_putchar('\n');						/* Печатаем символ перевода строки */
	free(result);							/* Освобождаем память, выделенную под строку с результатом конвертирования числа из одного типа в другой */
	return (0);								/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}