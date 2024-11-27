# Документация на програмата

## Описание
Програмата е написана на C++ и позволява работа с масив от цели числа. Тя включва:
1. Въвеждане на размер и елементи на масив.
2. Изчисления:
    - Средната стойност на числата, делими на 6.
    - Намиране на максималното отрицателно число и неговия индекс.
3. Изход от програмата.

## Функции

#### setSizeOfArrayAndInsertNumbers(int K[ ], int &L)
- **Описание**: Позволява въвеждане на размер на масив (от 1 до 30) и неговите елементи.
- **Параметри**:
    - `K[]`: Масив за съхранение на числата.
    - `L`: Размер на масива.

#### calculateMeanDivisibleBySix(const int K[ ], int L)
- **Описание**: Изчислява средната стойност на числата, делими на 6.
- **Параметри**:
    - `K[]`: Масивът от числа.
    - `L`: Размерът на масива.
- **Резултат**:
    - Връща средната стойност или 0, ако няма числа, делими на 6.

#### findMaxNegative(const int K[ ], int L, int &maxNegative, int &index)
- **Описание**: Намира максималното отрицателно число и неговия индекс.
- **Параметри**:
    - `K[]`: Масивът от числа.
    - `L`: Размерът на масива.
    - `maxNegative`: Максималното отрицателно число.
    - `index`: Индексът на това число.
- **Резултат**:
    - Ако няма отрицателни числа, `index` остава -1.

#### printArray(const int K[ ], int L)
- **Описание**: Извежда всички елементи на масива.

## Основна Логика
1. **Главно меню**:
    - Опция 1: Въвеждане на масив.
    - Опция 2: Изчисления върху масива.
    - Опция 3: Изход от програмата.
2. **Подменю за изчисления**:
    - Средна стойност на числата, делими на 6.
    - Максимално отрицателно число и индекс.
3. Програмата проверява дали масивът е въведен преди изчисления.




