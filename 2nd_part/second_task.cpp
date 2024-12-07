#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
#include "exceptions.h"

using namespace std;

void second_task()
{
    stringstream text, line;
    int counter = 0, max_counter = 0, begin_of_sentence = 0;

    cout << "Choose the source\n";
    cout << "1. File\n";
    cout << "2. String\n";

    char choice = getch();

    if (choice == '1')
    {
        ifstream input("2nd_part/text.txt");
        if (!input)
        {
            throw FileOpenException("Error with opening the file!");
        }

        string line_from_file;
        while (getline(input, line_from_file))
        {
            text << line_from_file << '\n';
        }
        input.close();
    }
    else if (choice == '2')
    {
        cout << "Enter the text:" << endl;
        string input_text;
        while (getline(cin, input_text))
        {
            text << input_text << '\n';
        }
    }
    else
    {
        cerr << "Not a correct choise!" << endl;
        return;
    }

    for (char &ch : text.str())
    {
        if (ch == '.' || ch == '!' || ch == '?')
        {
            if (counter > max_counter)
            {
                max_counter = counter;
            }
            counter = 0;
        }
        else if (ch == ',' || ch == ':' || ch == '-' || ch == '"')
        {
            counter++;
        }
    }

    counter = 0;

    for (int i = 0; i <= text.str().size(); i++)
    {
        if (text.str()[i] == '.' || text.str()[i] == '!' || text.str()[i] == '?')
        {
            if (counter == max_counter)
            {
                line.str("");
                line.clear();
                line << text.str().substr(begin_of_sentence, i - begin_of_sentence + 1);
                cout << line.str() << endl;
            }
            counter = 0;
            begin_of_sentence = i + 1;
        }
        else if (text.str()[i] == ',' || text.str()[i] == ':' || text.str()[i] == '-' || text.str()[i] == '"')
        {
            counter++;
        }
    }
}
