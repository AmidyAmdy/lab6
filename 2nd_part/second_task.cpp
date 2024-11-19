/*
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла и выводит на экран предложения,
содержащие максимальное количество знаков пунктуации.
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "exceptions.h"

using namespace std;

void second_task() {
    string line, text;
    int counter = 0, max_counter = 0, begin_of_sentence = 0;
    ifstream input("text.txt");
    if (!input)
        throw FileOpenException("Error with opening text.txt!");

    while (getline(input, line)) {
        text += line;
    }

    input.close();

    for (char &ch : text) {
        if (ch == '.' || ch == '!' || ch == '?') {
            if (counter > max_counter) {
                max_counter = counter;
            }
            counter = 0;
        }
        else if (ch == ',' || ch == ':' || ch == '-' || ch == '"') 
            counter++;
    }

    counter = 0;

    for (int i = 0; i <= text.size(); i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            if (counter == max_counter) {
                line = text.substr(begin_of_sentence, i - begin_of_sentence + 1); 
                cout << line << endl;
            }
            counter = 0;
            begin_of_sentence = i + 1;
        }
        else if (text[i] == ',' || text[i] == ':' || text[i] == '-' || text[i] == '"') 
            counter++;
    }
}
