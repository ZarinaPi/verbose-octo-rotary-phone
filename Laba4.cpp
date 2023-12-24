// Laba4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <cctype>

using namespace std;

void linearSearch(char* text, char* pattern) {
    int sizeText = strlen(text);
    int sizePat = strlen(pattern);

    for (int i = 0; i <= sizeText - sizePat; i++)
    {
        int j;
        for (j = 0; j < sizePat; j++)
            if (text[i + j] != pattern[j])
                break;

        if (j == sizePat)
            cout << "Индекс вхождения строки: " << i+1 << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251); //кодировка для считывания русских символов

    const int maxLength{ 550 };
    char strIn[maxLength]{};
    char strOut[maxLength]{};
    cout << "Введите текст: ";
    cin.getline(strIn, maxLength, '.');
    cout << "Вы ввели: " << strIn << "." << "\n";

    //проверка на количество введённых слов
    int sumSlov = 0;
    int i = 0;
    int slovo;
    while (strIn[i] == ' ' && strIn[i] != '\0')
        i++;
    slovo = 0;
    while (strIn[i] != '\0') 
    {
        if (strIn[i] != ' ' && slovo == 0)
        {
            slovo = 1;
            sumSlov++;
        }
        else if (strIn[i] == ' ')
            slovo = 0;
        i++;
    }
    
    if (sumSlov > 50)
    {
        cout << "Вы ввели слишком много слов!\n";
        cout << "Введите текст: ";
        cin.getline(strIn, maxLength, '.');
        cout << "Вы ввели: " << strIn << "." << "\n";
    }

    //удаляем лишние знаки препинания пробелы 

    int inputIndex = 0, outputIndex = 0, counterDot = 0;
    while (strIn[inputIndex] != '\0')
    {
        strOut[outputIndex] = strIn[inputIndex];

        if (strIn[inputIndex] == ' ' || strIn[inputIndex] == ',' || strIn[inputIndex] == ':' || strIn[inputIndex] == '"')
        {
            while (strIn[inputIndex + 1] == ' ' || strIn[inputIndex + 1] == ',' || strIn[inputIndex + 1] == ':' || strIn[inputIndex + 1] == '"')
                inputIndex++;
        }

        outputIndex++;
        inputIndex++;
    }
    strOut[outputIndex] = '\0';

    cout << "Строка без лишних знаков препинания и пробелов: " << strOut << "." << endl;

    for (size_t i = 1; i < strlen(strOut); ++i) {
        strOut[i] = towlower(strOut[i]);
    }

    cout << "Изменённый регистр: " << strOut << "." << endl;

    //Строка в обратном порядке

    int len = strlen(strOut);
    for (int j = 0; j < len/2; j++)
    {
        char temp = strOut[j];
        strOut[j] = strOut[len - j - 1];
        strOut[len - j - 1] = temp;
    }

    cout << "В обратном порядке: " << strOut << "." << endl;

    //Вывести все слова исходной последовательности на экран вертикально.
    cout << "Вывод всех слов вертикально: " << endl;

    for (int i = 0; i < strlen(strOut); i++)
    {
        if (strOut[i] == ' ')
        {
            cout << endl;
        }
        cout << strOut[i];
    }
    cout << endl;

    //Линейный поиск

    char substring[maxLength];

    cout << "Введите подстроку: ";
    cin >> substring;
    linearSearch(strIn, substring);
    cout << "\n";

    return 0;
}