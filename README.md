## Варіант #2
Визначити переможця чемпіонату Англії з футболу. Результати матчів подано в [файлах](examples_2/var2/premier_league1.csv) ([посилання на папку на гітхабі](https://github.com/ProgramEngineeringKPI/Introduction-To-Programming/blob/master/labs_spring_2020/examples_2/var2)) наступному форматі – `Назва команди, результати матчу №1-№10`, наприклад:
```csv
1
Chelsea FC,3:0,0:0,1:0,0:2,4:1,3:1,0:3,1:5,0:2,4:1
```
Перший рядок задає кількість команд, результати яких знаходяться в цьому файлі.

Результат матчу подається у форматі `A:B`, де А – результат команди, В – результат супротивника. За перемогу команда отримує 3 очка, за нічию – 1, за програш – 0. Необхідно вивести підсумкову таблицю чемпіонату.

#### Вхідні та вихідні дані
На вхід програми подається назва теки. Вивід – файл results.csv з результатами всіх команд ліги.
Вихідні дані повинні містити єдиний результат виконання для всіх файлів вхідної директорії.
