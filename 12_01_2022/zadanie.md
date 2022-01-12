# Napisać program, 
w którym użytkownik podaje trzy wartości: 
- liczbę godzin,
- minut
- sekund 
# Program ma przeliczyć podany czas na liczbę sekund. 
# W programie mogą wystąpić trzy różne klasy wyjątków:
- HoursException, jeśli liczba godzin jest mniejsza od zera, 
- MinutesException, jeśli liczba minut wychodzi poza zakres 0-59
- SecondsException, również przy wyjściu poza zakres 0-59. 

Każdy wyjątek ma dostarczać metodę what(), która zwraca stałą tablicę znaków - treść błędu (np. "Liczba godzin nie może być ujemna"). 

W funkcji main umieścić odpowiednie bloki try ... catch ... (ile bloków catch potrzeba, by wyłapać każdy z możliwych wyjątków?)

Następnie rozbudować program tak, aby trzy klasy wyjątków dziedziczyły z jednej wspólnej klasy TimeRangeException. 

Zmienić blok try...catch tak, by wykorzystać mechanizm polimorfizmu i wyłapać oraz wypisać za pomocą what() każdy możliwy wyjątek, tym razem tylko z jedną klauzulą catch.