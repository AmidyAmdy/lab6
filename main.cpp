#include <iostream>
#include <conio.h>
#include <string>
#include "1st_part/first_task.cpp"
#include "2nd_part/second_task.cpp"
using namespace std;

int main()
{
    cout << "MAIN MENU" << endl;
    cout << "1 - First task" << endl;
    cout << "2 - Second task" << endl;
    cout << "0 - Quit" << endl;

    while (1)
    {
        switch (_getch())
        {
        case '1':
            cout << "_________________________________________" << endl;
            cout << "FIRST TASK" << endl;
            first_task();
            cout << "_________________________________________" << endl;
            cout << "MAIN MENU" << endl;
            cout << "1 - First task" << endl;
            cout << "2 - Second task" << endl;
            cout << "0 - Quit" << endl;
            break;

        case '2':
            cout << "_________________________________________" << endl;
            cout << "SECOND TASK" << endl;
            second_task();
            cout << "_________________________________________" << endl;
            cout << "MAIN MENU" << endl;
            cout << "1 - First task" << endl;
            cout << "2 - Second task" << endl;
            cout << "0 - Quit" << endl;
            break;

        case '0':
            cout << "\nExiting program.";
            return 0;
            break;

        default:
            cout << "\nYou pressed a wrong button. Try again" << endl;
            break;
        }
    }
}

/*
"C:\MinGW\bin\g++.exe" -fdiagnostics-color=always -g "main.cpp" "1st_part\list_methods.cpp" "1st_part\order_methods.cpp" -o "main.exe"
*/