# Zadanie należy wykonać do piątku tj. 28.01 do końca dnia. 
> Oddanie poprawnego rozwiązania jest warunkiem wpisania zaliczenia.

# Napisać klasę Samochod, która:
- przechowuje stan samochodu (uruchomiony/zgaszony, bieg, poziom paliwa, pojemność baku, zużycie paliwa/km, całkowity przebieg) i informacje o nim (model, rocznik),
- udostępnia metody pozwalające zmienić stan samochodu (uruchom, zgaś, zmień bieg, przejedz x kilometrów, zatankuj x litrów paliwa);
metoda przejedz x kilometrów ma obniżyć poziom paliwa zgodnie z podanym zużyciem i zwiększyć całkowity przebieg samochodu
- posiada konstruktor parametrowy i konstruktor kopiujący.

## Następnie dodać klase **Silnik** i dodać w klasie Samochod pole typu Silnik, który przechowuje informacje o stanie 
(uruchomiony/wyłączony oraz bieg) i udostępnia metody do zmiany stanu.

## Dodać kolejna klase: **SamochodElektryczny**.
SamochodElektryczny ma te same pola co **Samochod** z wyjątkiem **zużycia paliwa i poziomu paliwa**: zamiast tego, przechowuje informacje o **poziomie naladowania baterii i maksymalnym zasięgu** *(obydwie wielkości wyrazone w kilometrach).*

Zamiast metody **zatankuj**, udostępnia bezparametrowa metode doladuj, która ustawia poziom naladowania baterii na **maksymalny zasięg**.

## Dodatkowa klasa **SamochodElektryczny** ma posiadać zmienną statyczną, która ma służyć jako licznik instancji klasy (przechowywać informację, ile obiektów tej klasy istnieje w danym momencie w programie) i metodę do wyświetlenia tej wartości. 
> Uwaga - nalezy pamiętać zarówno o zwiększaniu, jak i o zmniejszaniu licznika w odpowiednich składowych klasy.

## Dodać klase bazowa **PojazdSilnikowy**, przenieść do niej elementy,
które są wspólne dla dwóch utworzonych wcześniej klas i wydzielić jedną metodę czysto wirtualna 
> (która z metod jest dobrym kandydatem na metodę polimorficzna?)

## W programie utworzyć kilka obiektów klas **Samochod** i **SamochodElektryczny** i wywołać za pomocą odpowiednich wskaźników metodę polimorficzna 
> (można posłużyć się tablica wskaźników lub kontenerem vector przechowującym wskaźniki).

## Na koniec **przeciążyć operator >>** 
> (wypisywanie obiektu PojazdSilnikowy na strumień wyjścia) 
oraz wprowadzić zastosowanie wyjątków 
> (np. rzucać wyjątek przy probie zatankowania zbyt dużej ilości paliwa) 
można użyć własnej klasy lub użyć gotowej klasy wyjątku z biblioteki standardowej.