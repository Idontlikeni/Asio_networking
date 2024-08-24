Простое клиент-серверное приложение на C++ c использованием библиотеки asio. Симулирует работу биржи с покупкой-продажей долларов за рубли.

Для правильной работы проекта скачайте библиотеку asio отсюда: https://think-async.com/Asio/
И распакуйте в папке проекта. (т.е Папка `asio-<версия библиотеки>`) должна лежать там же, где и файлы `server.cpp` и `client.cpp`

Для сборки проекта: 
1) `cmake -G "<Генератор на ваш выбор>" <путь к файлу CMakeLists.txt>` или просто `сmake <Путь к файлу CMakeLists.txt>`
2) в папке в которой вы собирали проект: `cmake --build . --target client`, `cmake --build . --target server`
3) Запускайте server.exe, client.exe

Пользование проектом:
1) Запустите server.exe
2) Запустите client.exe

Введите ID пользователя.
Дальше у вас будет выбор из 3-х комманд:
`buy <usd> <rub>` - Отправка заявки на покупку долларов за рубли. Первый параметр - кол-во долларов, второй - рубль за доллар
`sell <usd> <rub>` - Отправка заявки на продажу долларов за рубли. Первый параметр - кол-во долларов, второй - рубль за доллар
`exit` - Выход из програмы.
Изменения баланса и заявок можно посмотреть в консоли сервера
