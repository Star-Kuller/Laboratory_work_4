#include <iostream>     
using namespace std;

struct time //эта  структура учавствует в большинстве заданиях (1, 2 и 4)
{
    int days = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
};

long hms_to_secs(int hours, int minutes, int seconds)
{
    return hours * 3600 + minutes * 60 + seconds;
}

void N_1()
{
    struct time clock;
    char dummychar;
    string AgainOrBack;
    cout << ">----------------[Начало выполнения N_1]----------------<\n";
    do {
        cout << "\n------------------------------------------------------\n";
        cout << "Введите время в формате (Часы:Минуты:Секунды): "; cin >> clock.hours >> dummychar >> clock.minutes >> dummychar >> clock.seconds;
        cout << "Всего секунд: " << hms_to_secs(clock.hours, clock.minutes, clock.seconds) << "\n";
        cout << "------------------------------------------------------\n";
        cout << "\n\nВведите \"Again\" чтобы повторить или \"Back\" чтобы вернуться к выбору задания\n";
        cin >> AgainOrBack;

    } while (AgainOrBack == "Again" | AgainOrBack == "again");
    cout << ">----------------[Конец выполнения N_1]----------------<\n";
    return;
}

long time_to_secs(struct time time) //эта функция учувствует в двух заданиях (2 и 4)
{
    return time.days * 86400 + time.hours * 3600 + time.minutes * 60 + time.seconds;
}

struct time secs_to_time(long seconds) //эта функция учувствует в двух заданиях (2 и 4)
{
    struct time answer;
    answer.days = seconds / 86400;
    seconds = seconds - answer.days * 86400;
    answer.hours = seconds / 3600;
    seconds = seconds - answer.hours * 3600;
    answer.minutes = seconds / 60;
    answer.seconds = seconds - answer.minutes * 60;
    return answer;
}

void N_2()
{
    struct time clock_A, clock_B, clock_ansver;
    char dummychar;
    cout << ">----------------[Начало выполнения N_2]----------------<\n";
    cout << "Введите первое время в формате (Часы:Минуты:Секунды): "; cin >> clock_A.hours >> dummychar >> clock_A.minutes >> dummychar >> clock_A.seconds;
    cout << "Введите второе время в формате (Часы:Минуты:Секунды): "; cin >> clock_B.hours >> dummychar >> clock_B.minutes >> dummychar >> clock_B.seconds;
    clock_ansver = secs_to_time(time_to_secs(clock_A) + time_to_secs(clock_B));
    printf("\nСумма времени: %d:%02d:%02d:%02d", clock_ansver.days, clock_ansver.hours, clock_ansver.minutes, clock_ansver.seconds);
    cout << "\n\n>----------------[Конец выполнения N_2]----------------<\n";
}

template <typename T> 
void Swap(T &a, T &b) //эта  шаблонная функция учувствует в двух заданиях (3 и 4)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
    return;
}

void N_3()
{
    int a, b;
    cout << ">----------------[Начало выполнения N_3]----------------<\n";
    cout << "Введите переменную A: "; cin >> a;
    cout << "Введите переменную B: "; cin >> b;
    Swap(a, b);
    cout << "\nПеременная A = " << a << "\nПеременная B = " << b;
    cout << "\n\n>----------------[Конец выполнения N_3]----------------<\n";
}

void N_4()
{
    struct time clock_A, clock_B;
    char dummychar;
    cout << ">----------------[Начало выполнения N_4]----------------<\n";
    cout << "Введите время A в формате (Часы:Минуты:Секунды): "; cin >> clock_A.hours >> dummychar >> clock_A.minutes >> dummychar >> clock_A.seconds;
    cout << "Введите время B в формате (Часы:Минуты:Секунды): "; cin >> clock_B.hours >> dummychar >> clock_B.minutes >> dummychar >> clock_B.seconds;
    Swap(clock_A, clock_B);
    clock_A = secs_to_time(time_to_secs(clock_A));
    clock_B = secs_to_time(time_to_secs(clock_B));
    printf("\nВремя A времени: %d:%02d:%02d:%02d", clock_A.days, clock_A.hours, clock_A.minutes, clock_A.seconds);
    printf("\nВремя B времени: %d:%02d:%02d:%02d", clock_B.days, clock_B.hours, clock_B.minutes, clock_B.seconds);
    cout << "\n\n>----------------[Конец выполнения N_4]----------------<\n";
}

int N_5_1_counter;

void N_5_1()
{
    N_5_1_counter++;
}

int N_5_2(int control_counter)
{
    static int counter = 0;
    switch (control_counter)
    {
    case 0:
        counter++;
        break;
    case 1:
        return counter;
    case 2:
        counter = 0;
        break;
    default:
        break;
    }
}

void N_5()
{
    int number_of_times;
    enum etype { perform, get, reset };
    cout << ">----------------[Начало выполнения N_5]----------------<\n";
    cout << "Сколько раз вызвать функцию с глобальным счётчиком вызова?\n"; cin >> number_of_times;
    for (int i = 0; i < number_of_times; i++) {
        N_5_1();
    }
    cout << "\nфункция была вызвана " << N_5_1_counter << " раз\n";
    cout << "------------------------------------------------------\n";
    cout << "Сколько раз вызвать функцию со статическим счётчиком вызова?\n"; cin >> number_of_times;
    for (int i = 0; i < number_of_times; i++) {
        N_5_2(perform);
    }
    cout << "\nфункция была вызвана " << N_5_2(get) << " раз";
    cout << "\n------------------------------------------------------\n";
    N_5_1_counter = 0;
    N_5_2(reset);
    cout << "Счётчики сброшены в исходное положение";
    cout << "\n>----------------[Конец выполнения N_5]----------------<\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int selected;
    while (true) {
        cout << "\n\n>--------------------[Главное меню]--------------------<\n";
        cout << "0 - Завершить работу\n1,2,3,4,5 - доступные задания\n";
        cout << "Выберите задание или 0: "; cin >> selected;
        switch (selected)
        {
        case 0:
            return 0;
            break;
        case 1:
            N_1();
            break;
        case 2:
            N_2();
            break;
        case 3:
            N_3();
            break;
        case 4:
            N_4();
            break;
        case 5:
            N_5();
            break;
        default:
            break;
        }
    }
    return 0;
}