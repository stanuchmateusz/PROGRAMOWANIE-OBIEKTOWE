#include <iostream>

class TimeRangeException : public std::exception
{
public:
    TimeRangeException() {}
    const char *what() const noexcept { return "Podano błędny czas"; }
};

class HoursExeption : public TimeRangeException
{
public:
    HoursExeption() {}
    const char *what() const noexcept override { return "Liczba godzin jest mniejsza od 0!"; }
};
class MinutesExeption : public TimeRangeException
{
public:
    MinutesExeption() {}
    const char *what() const noexcept override { return "Liczba minut wychodzi poza zakres 0-59"; }
};
class SecondsExeption : public TimeRangeException
{
public:
    SecondsExeption() {}
    const char *what() const noexcept override { return "Liczba wychodzi poza zakres 0-59!"; }
};

int main(int argc, char const *argv[])
{
    int h, m, s;
    std::cin >> h >> m >> s;
    try
    {
        if (h < 0)
            throw HoursExeption();
        if (m < 0 || m > 59)
            throw MinutesExeption();
        if (s < 0 || s > 59)
            throw SecondsExeption();
        int czas = h * 3600 + m * 60 + s;
        std::cout << "Czas: " << czas << std::endl;
    }
    catch (TimeRangeException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
