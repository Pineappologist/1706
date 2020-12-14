#include <iostream>
#include <fstream>
#include <ctime>
#include <random>

/* План:
 * Ветка G:
 * 1. Генерация и вывод чисел на экран
 * 2. Запись чисел в data.txt
 * Ветка А:
 * 1. Чтение(из файла) и запись в переменную n количества чисел
 * 2. Чтение(из файла) всех чисел и вывод их на экран
 * 3. Вывод троек
 * 4. Вывод только подходящих троек
 * 5. Подсчёт подходящих троек
 * 6. Вывод ответа
 * Ветка B:
 * 1. Чтение(из файла) и запись в переменную n количества чисел
 * 2. Создание новых переменных для решения
 * 3. Чтение(из файла) всех чисел и поиск минимумов среди чётных и нечётных чисел
 * 4. Вывод чисел или -1
 * */

using namespace std;

int main() {

    ifstream ifs("data.txt");
    int n(0), tmp(0), final_sum(0);
    ifs >> n;

    int greatest_min_even(1001),
            mid_min_odd(1001), mid_min_even(1001),
            least_min_odd(1001), least_min_even(1001);

    for (int i = 0; i < n; ++i) {
        ifs >> tmp;
        if (tmp % 2 == 0) {
            if (tmp < least_min_even and tmp < mid_min_even) {
                mid_min_even = least_min_even;
                least_min_even = tmp;
            } else if (tmp > least_min_even and tmp < mid_min_even) {
                greatest_min_even = mid_min_even;
                mid_min_even = tmp;
            } else if (tmp > mid_min_even and tmp < greatest_min_even) {
                greatest_min_even = tmp;
            }
        } else {
            if (tmp < least_min_odd and tmp < mid_min_odd) {
                mid_min_odd = least_min_odd;
                least_min_odd = tmp;
            } else if (tmp > least_min_odd and tmp < mid_min_odd) {
                mid_min_odd = tmp;
            }
        }
    }

}
