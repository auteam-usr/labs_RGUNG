# Лабораторная работа №2
## Работа с базовыми типами, реализация сигналов и слотов

---

### Цель работы:
- Освоение механизма сигналов и слотов в Qt.
- Практика работы с базовыми типами данных Qt.

---

## Формирование отчета
В отчёте по лабораторной работе необходимо кратко изложить описание выполненных действий с использованием соответствующих команд, приложить скриншоты настроек и результатов тестов для наглядности. Также следует указать на возникшие в процессе работы проблемы и описать найденные способы их решения. В случае наличия контрольных вопросов, ответы на них должны быть интегрированы в текст.

---

## ЧАСТЬ 1
### Работа с QString и сигналами/слотами

#### Цели задания:
- Изучить базовые операции с QString.
- Реализовать простую форму для ввода текста и кнопку для его обработки.
- Использовать сигналы и слоты для реализации логики приложения.

### Шаг 1. Создание проекта и формы.
1. Запустите **Qt Creator** и создайте новый проект "Приложение Qt Widgets".

<img src="https://raw.githubusercontent.com/auteam-usr/labs_RGUNG/refs/heads/main/SPTL_spring_2025/lab2/lab2_images/01.jpg" alt="" style="margin-left: 20px; display: block;">

2. Укажите название проекта **"laba2"** и выберите директорию для проекта.

<img src="https://raw.githubusercontent.com/auteam-usr/labs_RGUNG/refs/heads/main/SPTL_spring_2025/lab2/lab2_images/02.jpg" alt="" style="margin-left: 20px; display: block;">

3. Выберите систему сборки **CMake**.
4. Оставьте информацию о классах по умолчанию.
5. Файл перевода можно оставить пустым.
6. Выберите комплект для сборки (должен быть автоматически определён).
7. Завершите создание проекта, нажав **"Завершить"**.
8. Добавьте на форму **QLineEdit** для ввода текста.
9. Добавьте **QPushButton** для обработки текста.
10. Добавьте **QLabel** для вывода результата.

### Шаг 2. Настройка объектов.
1. В **objectName** укажите **inputLineEdit** для QLineEdit.
2. Аналогично настройте **processButton** и **resultLabel**.
3. Измените свойство **text** у **QPushButton** и **QLabel**.
4. Сохраните изменения **(Ctrl+S)**.

### Шаг 3. Реализация слота для обработки.
В `mainwindow.h` добавьте слот:
```cpp
private:
    void processText();
```
В `mainwindow.cpp` реализуйте слот:
```cpp
void MainWindow::processText() {
    QString text = ui->inputLineEdit->text();
    ui->resultLabel->setText(text.toUpper());
}
```

### Шаг 4. Соединение сигналов и слотов.
```cpp
connect(ui->processButton, &QPushButton::clicked, this, &MainWindow::processText);
```

### Шаг 5. Тестирование.
1. Соберите приложение **(Ctrl+B)**.
2. Запустите приложение **(Ctrl+R)**.
3. Проверьте ввод текста и его обработку.

---
## ЧАСТЬ 2
### Использование QVariant для работы с различными типами данных

#### Цели задания:
- Практика применения QVariant.
- Разработка функции для обработки разнотипных данных.

### Шаг 1. Реализация обработки QVariant.
Добавьте слот в `mainwindow.h`:
```cpp
private:
    void processVariant();
```
Настроим соединение в конструкторе `mainwindow.cpp`:
```cpp
connect(ui->processButton, &QPushButton::clicked, this, &MainWindow::processVariant);
```
Реализация `processVariant()` в `mainwindow.cpp`:
```cpp
#include <QDate>
#include <QDebug>

void MainWindow::processVariant() {
    QString inputText = ui->inputLineEdit->text();
    QVariant var;
    bool isNumber;
    int intValue = inputText.toInt(&isNumber);

    QDate dateValue = QDate::fromString(inputText, "dd.MM.yyyy");
    if (!dateValue.isValid()) {
        dateValue = QDate::fromString(inputText, "dd-MM-yyyy");
    }
    if (!dateValue.isValid()) {
        dateValue = QDate::fromString(inputText, "dd/MM/yyyy");
    }

    if (isNumber) {
        var = intValue;
    } else if (dateValue.isValid()) {
        var = dateValue;
    } else {
        var = inputText;
    }

    QString resultText;
    if (var.type() == QVariant::Int) {
        resultText = "Число: " + QString::number(var.toInt() * 2);
    } else if (var.type() == QVariant::Date) {
        resultText = "Дата: " + var.toDate().toString("dd.MM.yyyy");
    } else {
        resultText = "Строка: " + var.toString();
    }

    ui->resultLabel->setText(resultText);
}
```

### Шаг 2. Тестирование.
1. Проверка на **число**.
2. Проверка на **дату**.
3. Проверка на **строку**.

---
## ЧАСТЬ 3
### Создание собственных сигналов и слотов

#### Цели задания:
- Ознакомление с процессом создания сигналов и слотов.

### Шаг 1. Создание класса DataProcessor
Файл `data_processor.h`:
```cpp
#ifndef DATA_PROCESSOR_H
#define DATA_PROCESSOR_H

#include <QObject>

class DataProcessor : public QObject {
    Q_OBJECT
public:
    explicit DataProcessor(QObject *parent = nullptr) : QObject(parent) {}
signals:
    void dataProcessed(const QString &result);
};

#endif // DATA_PROCESSOR_H
```

### Шаг 2. Реализация обработки данных
Файл `data_processor.cpp`:
```cpp
#include "data_processor.h"

void DataProcessor::processData(const QString &input) {
    QString processedData = "Обработано: " + input;
    emit dataProcessed(processedData);
}
```

### Шаг 3. Интеграция в MainWindow
Файл `mainwindow.h`:
```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "data_processor.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private slots:
    void handleProcessedData(const QString &data);
    void onProcessButtonClicked();
private:
    QLineEdit *inputField;
    QLabel *outputLabel;
    QPushButton *processButton;
    DataProcessor *processor;
};

#endif // MAINWINDOW_H
```

Файл `mainwindow.cpp`:
```cpp
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    inputField = new QLineEdit(this);
    processButton = new QPushButton("Обработать", this);
    outputLabel = new QLabel("Результат: ", this);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(inputField);
    layout->addWidget(processButton);
    layout->addWidget(outputLabel);

    processor = new DataProcessor(this);

    connect(processor, &DataProcessor::dataProcessed, this, &MainWindow::handleProcessedData);
    connect(processButton, &QPushButton::clicked, this, &MainWindow::onProcessButtonClicked);
}
```

