# Инструкция запуска лабораторной №5 на платформах Linux и Windows

## Общие требования
Для работы требуется установленный компилятор:
- **Linux**: GCC
- **Windows**: MinGW или Microsoft Visual Studio

## Общие предварительные действия в Linux
```bash
sudo apt update

sudo apt install g++
```

## Общие предварительные действия в Windows
- Скачать библиотеку MinGW и установить
- Убедитесь, что компилятор (например, MinGW) установлен, и путь к его папке bin добавлен в переменную среды PATH

### Компиляция и запуск в Linux
```bash
g++ lab5.cpp -o lab5

./lab5
```

### Компиляция и запуск в Windows
```bash
g++ lab5.cpp -o lab5.exe

lab5.exe
```