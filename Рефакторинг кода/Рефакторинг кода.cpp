#include <iostream>
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#elif __linux
#include <termios.h>
#endif
using namespace std;

string replaceCharacters(const string& source, const string& characters) {
    string result;
    char qt;

    cout << "Для закінчення введення даних натисніть клавішу esc\n";

    while (true) {
        if (_kbhit()) {
            qt = _getch();
            for (int i = 0; i < characters.length(); i++) {
                if (qt == characters[i]) {
                    qt = ' ';
                }
                else if (qt == 13) {
                    qt = '\n';
                }
                else if (qt == 27) {
                    return result;
                }
            }
            result += qt;
            cout << qt;
        }
    }
}

int main() {
    string Ukr = "йцукенгшщзхждлорпавфячсмитьбюЙЦУКЕНГШЩЗХЖДЛОРПАВФЯЧСМИТЬБЮґҐІіЄєЇї";
    string Eng = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";
    string Num = "0123456789";
    string Symb = "`~!@#$%^&*()_+}{|\":<>?/.,\\';][=-№";
    int choice;

#ifdef __linux
    struct termios Old, New;

    while (true) {
        cout << "Натисніть 1 для заміни цифр пробілами\n";
        cout << "Натисніть 2 для заміни розділових знаків пробілами\n";
        cout << "Натисніть 3 для заміни англійських букв пробілами\n";
        cout << "Натисніть 4 для заміни українських букв пробілами\n";
        cin >> choice;

        switch (choice) {
        case 1:
            system("clear");
            cout << "Ви ввели текст:\n" << replaceCharacters("", Num) << endl;
            break;
        case 2:
            system("clear");
            cout << "Ви ввели текст:\n" << replaceCharacters("", Symb) << endl;
            break;
        case 3:
            system("clear");
            cout << "Ви ввели текст:\n" << replaceCharacters("", Eng) << endl;
            break;
        case 4:
            system("clear");
            cout << "Ви ввели текст:\n" << replaceCharacters("", Ukr) << endl;
            break;
        default:
            return 0;
        }
    }
#elif _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    bool run = true;
    string text;

    while (run) {
        cout << "Натисніть 1 для заміни цифр пробілами\n";
        cout << "Натисніть 2 для заміни розділових знаків пробілами\n";
        cout << "Натисніть 3 для заміни англійських букв пробілами\n";
        cout << "Натисніть 4 для заміни українських букв пробілами\n";
        cin >> choice;

        switch (choice) {
        case 1:
            system("CLS");
            cout << "Ви ввели текст:\n" << replaceCharacters("", Num) << endl;
            break;
        case 2:
            system("CLS");
            cout << "Ви ввели текст:\n" << replaceCharacters("", Symb) << endl;
            break;
        case 3:
            system("CLS");
            cout << "Ви ввели текст:\n" << replaceCharacters("", Eng) << endl;
            break;
        case 4:
            system("CLS");
            cout << "Ви ввели текст:\n" << replaceCharacters("", Ukr) << endl;
            break;
        default:
            run = false;
            break;
        }
    }
#endif
    return 0;
}
