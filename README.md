# Test_LestaG
 Test tasks for Lesta Games 
**********************************************************************  

Файл содержит некоторые результаты работы программы и описание заданий.  

Проект выполнен на языке C++  
Причина выбора языка: Для реализации данного задания я выбрала  
C++, т.к. время на реализацию было не ограничено, задачи не используют  
доп. программы, код прост, компилируем и высокопроизводителен.  
Проект состоит из файлов:  

main.cpp - основной файл для запуска и тестирования функций  
Functions.cpp - функции  
FIFO.cpp - реализация циклических буферов  

Автор: Михневич Анастасия Дмитриевна  

**********************************************************************  
Задание 1:   
  Алгоритм с использованием остатка от деления (пример из задания):  
       Легок для чтения и понимания, интуитивный подход для решения задачи.  
       В некоторых случаях может быть менее эффективным, ибо операция нахождения остатка от деления  
      может быть более затратной по времени, чем побитовые операции.    

  Алгоритм с использованием побитовой операции ( альтернативное решение задачи):  
       На низком уровне данный тип операций быстрее, так как побитовые операции обычно оптимизируются компиляторами  
      и выполняются быстрее, чем деление.  
       В отличие от методов, использующих арифметические операции, метод с логическими операциями и работой с битами имеет  
      меньшую читаемость для тех, кто не знаком с данными операциями.  
       Метод может быть излишним для простых задач, где простота кода важнее производительности.  

  Время выполнения обеих функций можно считать O(1), так как они выполняют фиксированное количество операций (независимо от значения входного числа).  

Результаты работы программы:  

1.      
Enter an integer value:   123234.   
Number  123234  is even.    

2.       

Enter an integer value:   200.   
Number  200  is even.   

3.  
Enter an integer value:   0.   
Number  0  is even.  
  
    
**********************************  
**********************************  


Задание 2:  
Сравнение реализаций.  

 Полнота и качество реализации:  

Циклический буфер на основе массива:  
    Простой  код без лишних зависимостей, контроль памяти.  
    Необходимость ручного управления памятью может привести к утечкам или ошибкам.   
	
Циклический буфер на основе std::vector:  
   Использование стандартной библиотеки облегчает управление памятью.  
   Позволяет автоматически подстраиваться под размер буфера  
   Более сложная структура данных может занимать больше памяти на малых буферах.  
   Использование методов вектора  приводит к дополнительным  
   накладным расходам по сравнению с простым массивом.  

 Оформление кода:  

 Оба класса написаны просто и читабельно, но реализация на основе вектора делает код короче.  
 Класс на основе вектора безопаснее за счет работы с памятью.  

 Сравнение быстродействия:  

Циклический буфер на основе массива:  
 Операции push и pop выполняются за O(1), так как требуется только обновление указателей и извлечение значения.  
 Используется статический массив, нет дополнительных накладных расходов на управление памятью.  
Циклический буфер на основе std::vector:  
  В общем случае, для операций push и pop время выполнения  O(1).  
  Если размер буфера заранее известен и не изменяется, использование  может быть избыточным,  
  но для гибкости удобен.  

Итог:  

 Если нужна максимальная производительность и контроль памяти и минимизировать  
 использование стандартной библиотеки, то лучше использовать   
   Циклический буфер на основе массива.  
 Если нужно безопасное управление памятью и  гибкость, то   
   Циклический буфер на основе вектора.  

Результаты работы программы:  

1.      
Vector:    
1
2
3
4
5
6.  
Array:  
10
20
30
40
50
60.  
Vector is empty: true.   
Array is full: false.  

2.  
Vector:   
1
2
3
4
5
6.   
Array:   
10
20
30
40
50
60.   
Vector is empty: true.   
Array is full: false.

3.  
Vector:    
1
2
3
4
5
6.   
Array:   
10
20
30
40
50
60.   
Vector is empty: true.   
Array is full: false.

**********************************  
**********************************  

Задание 3:  
 Для выполнения задания был выбран алгоритм быстрой сортировки(сортировка Хоара).  
 Причины эффективности:  
 Один из самых быстрых известных универсальных алгоритмов сортировки массивов.  
 В большинстве случаев быстрая сортировка имеет временную сложность O(n log n),   
 что делает её быстрой даже для больших массивов.  
 При правильно выбранном опорном элементе сортировка часто показывает практически   
 линейный поиск времени выполнения даже в среднем.  
 Если массив уже отсортирован — можно использовать другие методы для   
 избежания худшего случая (например, чтобы избежать O(n²)),  
 но с применением оптимизаций, как использование рандомизации для выбора опорного элемента,   
 алгоритм может по-прежнему работать эффективно.  
 Алгоритм требует мало дополнительной памяти.   
 С учетом стека вызовов рекурсии, его пространственная сложность составляет O(log n).  
 
 Быстрая сортировка может быть не самым лучшим выбором для массивов,   
 состоящих из дубликатов, так как в худшем случае он может деградировать до O(n²).  
 Но, если использовать оптимизации, такие как выбор медианы или использование метода трёх опор, можно решить эту проблему.  


1.  
Enter a size of array  :   6.   
Enter an integer array :   7 6 90 21 0 5.   
Sorted array: 0 5 6 7 21 90.      
2.  
Enter a size of array  :   18.   
Enter an integer array :   374 3746 0 745 98457 1 6 0.   
8745 745 1 6 84597 322 886 0 0 0 0 0 0 0.   
Sorted array: 0 0 0 0 0 1 1 6 6 322 374 745 745 886 3746 8745 84597 98457.  
3.  
Enter a size of array  :   2.   
Enter an integer array :   01 10.   
Sorted array: 1 10. 


