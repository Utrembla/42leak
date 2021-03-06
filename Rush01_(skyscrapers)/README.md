# SkySkrapers

  Логическая головоломка «Небоскребы», также известная как «Башни».


## Правила головоломки

  Цель состоит в том, чтобы разместить небоскребы во всех ячейках сетки в
соответствии с правилами:

- Высота небоскребов составляет от 1 до размера сетки, то есть от 1 до 4 для
  головоломки 4x4.
- Нельзя разместить два небоскреба одинаковой высоты в одной строке или столбце.
- Цифры по сторонам сетки показывают, сколько небоскребов вы увидите, если
  посмотрите в направлении стрелки. Отсутствие цифры или ноль означает, что для
  данного направления подсказки нет.

Например, простой вариант 4x4:

```
     2   2   1   3
  -+---+---+---+---+-
3  |   |   |   |   |  2
  -+---+---+---+---+-
1  |   |   |   |   |  2
  -+---+---+---+---+-
2  |   |   |   |   |  3
  -+---+---+---+---+-
3  |   |   |   |   |  1
  -+---+---+---+---+-
     3   2   2   1
```

Результат решения головоломки:

```
     2   2   1   3
  -+---+---+---+---+-
3  | 1 | 3 | 4 | 2 |  2
  -+---+---+---+---+-
1  | 4 | 2 | 1 | 3 |  2
  -+---+---+---+---+-
2  | 3 | 4 | 2 | 1 |  3
  -+---+---+---+---+-
3  | 2 | 1 | 3 | 4 |  1
  -+---+---+---+---+-
     3   2   2   1
```

## Полезные ссылки

- https://www.puzzle-skyscrapers.com/
- [Codewars :: 4 By 4 Skyscrapers](https://www.codewars.com/kata/5671d975d81d6c1c87000022)
- [Codewars :: 6 By 6 Skyscrapers](https://www.codewars.com/kata/5679d5a3f2272011d700000d)
- [Codewars :: 7x7 Skyscrapers](https://www.codewars.com/kata/5917a2205ffc30ec3a0000a8)
- [Codewars :: N By N Skyscrapers](https://www.codewars.com/kata/5f7f023834659f0015581df1)


