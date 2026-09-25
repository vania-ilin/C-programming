// Задача: Среднее арифметическое последовательности чисел
#include <iostream>
#include <string>
#include <Windows.h>

#include <exception>
#include <stdexcept>


using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 0; int sum = 0;
    string size_string;
    bool ok = true;

    do
    {
        try
        {
            cout << "Введите количество чисел ";
            cin >> size_string; // вводим строку
            size = stoi(size_string); // преобразуем в целое число (функция stof() в вещественное)
            ok = true;
            if (size <= 0)
            {
                // выбрасываем исключение
                throw runtime_error("size <= 0!"); // runtime_error - общий тип исключений, которые возникают во время выполнения
                ok = false;
            }
        }

        catch (invalid_argument) // ловит исключение по некорректному типу данных
        {
            cout << "Ошибка invalid_argument ";
            ok = false;
        }

        catch (out_of_range) // ловит исключение выхода на диапазон типа данных
        {
            cout << "Число слишком большое или маленькое \n";
            ok = false;
        }

        catch (runtime_error e) // ловит исключение которые возникают во время выполнения программы
        {
            cout << "Ошибка runtime_error " << e.what();
            ok = false;
        }


        catch (...) // ловит все исключения
        {
            cout << "Какая то ошибка ... ";
            ok = false;
        }


    } while (!ok);

    double srednee = 0;
    int number; string number_string;
    for (int i = 0; i < size; i++)
    {
        try
        {
            cout << "Введите " << i + 1 << "-ое число: ";
            cin >> number_string; // вводим строку
            number = stoi(number_string); // преобразуем в число
            sum += number;

        }
        catch (exception err)
        {
            cout << "Ошибка____: " << err.what();
            i--;
        }
    }
    srednee = (double)sum / size;
    cout << "Среднее арифметическое последовательности равно: " << srednee;

    cin.get();
}
