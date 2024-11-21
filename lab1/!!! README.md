# Инструкция запуска лабораторной №1 на платформах Linux и Windows

## Общие требования
Для работы требуется установленный компилятор:
- **Linux**: GCC
- **Windows**: MinGW или Microsoft Visual Studio

## Общие предварительные действия в Linux
```bash
sudo apt update

sudo apt install g++ libsfml-dev
```

## Общие предварительные действия в Windows
- Скачать библиотеку SFML с официального сайта, распаковать в C:\SFML
- Скачать библиотеку MinGW и установить
- Убедитесь, что компилятор (например, MinGW) установлен, и путь к его папке bin добавлен в переменную среды PATH

## Версия лабораторной 1.1

### Компиляция и запуск в Linux
```bash
g++ lab1.1.cpp -o lab1.1

./lab1.1
```

### Компиляция и запуск в Windows
```bash
g++ lab1.1.cpp -o lab1.1.exe

lab1.1.exe
```

## Версия лабораторной 1.2

### Компиляция и запуск в Linux
```bash
g++ lab1.2-dyn-input.cpp -o lab1.2-dyn-input

./lab1.2-dyn-input
```

### Компиляция и запуск в Windows
```bash
g++ lab1.2-dyn-input.cpp -o lab1.2-dyn-input.exe

lab1.2-dyn-input.exe
```

## Версия лабораторной 1.3

### Компиляция и запуск в Linux
```bash
g++ -c lab1.3-sfml.cpp

g++ lab1.3-sfml.o -o lab1.3-sfml-app -lsfml-graphics -lsfml-window -lsfml-system

./lab1.3-sfml-app
```

### Компиляция и запуск в Windows
```bash
g++ lab1.3-sfml.cpp -o lab1.3.exe -I C:\SFML\include -L C:\SFML\lib -lsfml-graphics -lsfml-window -lsfml-system

lab1.3.exe
```