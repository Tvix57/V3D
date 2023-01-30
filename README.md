<h1 align="center"> V3D </h1>

<h2 align="center"> Вид главного окна </h2>

<img src="src/mainwindow.png">

1. Зона отображения объекта
1. Основные настройки приложения
1. Область управления объектом/сценой
1. Область управления светом
1. Область управления текстурами

<p>С тремя описанными выше областями возможно производить различные манипуляции (отображать поверх зоны отображения, закрывать/открывать, изменять размер и местоположение), например так:</p>

<img src="src/randomplace.png">

<hr>

<h2 align="center"> Основные настройки </h2>
<h3><b> Вкладка файл: </b></h3>

1. Загрузить модель из файла (формат obj)
1. Сделать изображение текущего состояния зоны отображения, при нажатии открывается дополнительное окно (скриншот представлен ниже) выбора формата изображения и его разрешения, которое пользователь может задать вручную, либо выбрать из соответствующих пресетов

<img src="src/savewindow.png">

<hr><hr>

<h3><b> Вкладка модель: </b></h3>

1. Ребра
    - Способ отображения (по умолчанию none)
        - none - не отображать ребра у объекта
        - линия - отображать ребра линиями
    - Размер - изменить толщину линий
    - Цвет - изменить цвет линий
1. Вершины
    - Способ отображения (по умолчанию none)
        - none - не отображать вершины у объекта
        - Круг - отображать вершины кругами
        - Квадрат - отображать вершины квадратами
    - Размер - изменить радиус точек
    - Цвет - изменить цвет точек
1. Текстуры
    - Способ отображения (по умолчанию поверхность)
        - none - не отображать текстуры
        - Каркас - отображать каркасную модель объекта
        - Поверхность - отображать модель поверхностями

<p> При изменении толщины линии, отображается вспомогательное окно с наглядным отображением толщины и возможностью ее изменения: </p>

<img src="src/changevertex.png">
<hr>
<h2 align="center"> Примеры: </h2>

| Способ отображения ребер |  | Толщина ребер |  | Цвет ребер |  |
| :---: | :---: | :---: | :---: | :---: | :---: |
| `none` | <img src="src/defaultmodel.png"> | `defaut` | <img src="src/withlinesmodel.png"> | `defaut` | <img src="src/withbiglinesmodel.png"> |
| `Линия` | <img src="src/withlinesmodel.png"> | `default++` | <img src="src/withbiglinesmodel.png"> | `pink` | <img src="src/withpinklinesmodel.png"> |



| Способ отображения вершин |  | Радиус вершин |  | Цвет вершин |  |
| :---: | :---: | :---: | :---: | :---: | :---: |
| `none` | <img src="src/defaultmodel.png"> | `defaut` | <img src="src/withpointsmodel.png"> | `defaut` | <img src="src/withpointsmodel.png"> |
| `Круг` | <img src="src/withbigpointsmodel.png"> | `default++` | <img src="src/withbigpointsmodel.png"> | `pink` | <img src="src/withcoloredpointsmodel.png"> |
| `Квадрат` | <img src="src/withrectmodel.png"> |

| Способ отображения текстур | `none` | `Каркас` | `Поверхность` |
| :---: | :---: | :---: | :---: | 
| | <img src="src/notexturemodel.png"> | <img src="src/surfacemodel.png"> | <img src="src/model.png"> |

<hr><hr>

<h3><b> Вкладка сцена: </b></h3>

1. Цвет - изменить цвет сцены (корректно отображается только при отключенном окружении)
1. Свет
    - Плоское затенение - равномерное на весь полигон
    - Мягкое затенение - использует градиентное изменение цвета полигона
1. Тип проекции
    - Центральная 
    - Параллельная
1. Сетка (оси координат и квадратики в пространстве)
    - none
    - Отображать
1. Сглаживание
    - Твердые ребра
    - Мягкие ребра
1. Окружение (ландшафт вокруг)
    - none
    - Отображать

<hr>
<h2 align="center"> Примеры: </h2>

| `Желтый цвет сцены` | `Зеленый цвет сцены` |
| :---: | :---: | 
| <img src="src/noskybox.png"> | <img src="src/greenscene.png"> |

| `Плоское затенение` | `Мягкое затенение` |
| :---: | :---: | 
| <img src="src/hardlight.png"> | <img src="src/softlight.png"> |

| `Центральная проекция` | `Параллельная проекция` |
| :---: | :---: | 
| <img src="src/centralprojection.png"> | <img src="src/parallelprojection.png"> |

| `Отображать сетку` | `Сетка none` |
| :---: | :---: | 
| <img src="src/centralprojection.png"> | <img src="src/nogrid.png"> |

| `Отображать окружение` | `Окружение none` |
| :---: | :---: | 
| <img src="src/centralprojection.png"> | <img src="src/noskybox.png"> |

<hr><hr>

<h2 align="center"> Область управления объектом </h2>

<table align="center">
<tr> 
    <td> <img src="src/menutransformation.png"> </td>
    <td><p>
        1-2. Смещение по оси X <br>
        3-4. Смещение по оси Y <br>
        5-6. Смещение по оси Z <br>
        7. Шаг смещения <br>
        8. Текущая координата по оси X <br>
        9. Текущая координата по оси Y <br>
        10. Текущая координата по оси Z <br>
        11. Вращение относительно оси X <br>
        12. Вращение относительно оси Y <br>
        13. Вращение относительно оси Z <br>
        14. Пропорциональное изменение модели по оси X <br>
        15. Пропорциональное изменение модели по оси Y <br>
        16. Пропорциональное изменение модели по оси Z <br>
        17. Пропорциональное изменение модели по всем осям одновременно <br>
        18. Приводит размеры объекта к единичному формату <br>
        19. Наводит камеру на выбранный объект <br>
        20. При выборе сцены, пользователь будет изменять параметры всех объектов <br>
        21. При выборе конкретного объекта, пользователь будет изменять параметры этого объекта <br>
        22. При выборе конкретной части объекта, пользователь может изменять только материалы этой части<br>
        23. При нажатии на поле remove рядом с объектом, объект удаляется со сцены
    <p></td>
</tr>
</table>

<hr>
<h2 align="center"> Примеры: </h2>

| `Оригинал` | `Смещение по X` | `Смещение по Y` | `Смещение по Z` |
| :---: | :---: | :---: | :---: | 
| <img src="src/centralprojection.png"> | <img src="src/movex.png"> | <img src="src/movey.png"> | <img src="src/movez.png"> |
| `Поворот по X` | `Поворот по Y (по Z 45)` | `Поворот по Z` | `Total scale` |
| <img src="src/rotatex.png"> | <img src="src/rotatey.png"> | <img src="src/rotatez.png"> | <img src="src/scaletotal.png"> |
| `Scale X` | `Scale Y` | `Scale Z` | `Normalize` |
| <img src="src/scalex.png"> | <img src="src/scaley.png"> | <img src="src/scalez.png"> | <img src="src/normalize.png"> |

<hr><hr>

<h2 align="center"> Область управления светом </h2>

<table align="center">
<tr> 
    <td> <img src="src/menulight.png"> </td>
    <td><p>
        1. Цвет свечение самого объекта <br>
        2. Цвет рассеивающегося света <br>
        3. Цвет отражающегося света <br>
        4. Направление света <br>
        5. Положение источника света в пространстве <br>
        6. Дистанция луча <br>
        7. Внутренний круг освещаемого пространства <br>
        8. Внешний круг зоны рассеивания света <br>
        9. Статус глобального источника света <br>
        10. Статус позиционных источников света и их список <br>
        11. Статус узконаправленных позиционных источников света и их список
    <p></td>
</tr>
</table>

<hr><hr>

<h2 align="center"> Область управления текстурами </h2>

<table align="center">
<tr> 
    <td> <img src="src/menutexture.png"> </td>
    <td><p>
        1. Фоновое освещение <br>
        2. Диффузное освещение <br>
        3. Освещение зеркальных бликов <br>
        4. Коэффициент блеска <br>
        5. Коэффициент прозрачности <br>
        6. Коэффициент преломления <br>
        7. Коэффициент отражения <br>
        8. Коэффициент шероховатости <br>
        9. Задать всем коэффициентам значения по-умолчанию<br>
        10. Включить/выключить отображение загруженной текстуры<br>
        11. Перевернуть текстуру<br>
        12. Добавить текстуру<br>
        13. Удалить текстуру
    <p></td>
</tr>
</table>

<hr>
<h2 align="center"> Примеры: </h2>

| `Блик` | `Отражение` | `Прозрачность` |
| :---: | :---: | :---: |
| <img src="src/highlight.png"> | <img src="src/reflect.png"> | <img src="src/refract.png"> |

<hr><hr>
