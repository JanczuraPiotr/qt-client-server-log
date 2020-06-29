## Architektura

Kod dzielony jest na **kontrolery**, **akcje**, **serwisy**, **algorytmy**, **data** (**rekord**, **kolekcja**). Akcje i serwisy to **operatorzy**. Podział ma swoje odzwierciedlenie w strukturze katalogów. Katalog common nie ma narzuconej struktury ale częściowo może pokrywać się ze strukturą katalogów server i client.
Kontroler może rozpoczynać swoje działanie na danych wejściowych a także wysyłać te dane na zewnątrz aplikacji. Analizę danych wejściowych wykonują **wejścia**. Przygotowanie danych wyjściowych wykonują **wyjścia**.
Podział kodu odzwierciedlony jest w przestrzeni nazw.
Podstawowym "narzędziem" pracy kontrolera jest **sygnał**. Swoje zadania realizuje po otrzymaniu sygnału a jeżeli scenariusz tego wymaga wysyłają odpowiednie sygnały z powiadomieniami. Sygnały realizowane są metodą connect biblioteki QT.

### Kontroler

Widok jest kontrolerem.

Obsługuje sygnały. Nie ma dostępu do modelu i algorytmów.
Odbierając sygnał kontroler uruchamia klasę przeznaczoną do jego obsługi. Może nią być klasa action::Operator lub service::Operator. Odbiera od operatora wynik działania i obsługuje w zależności od kontekstu (rest api, socket , konsola, plik, inny blok aplikacji).
Operatorzy wykonują swoje operacje na obiektach przekazanych przez referencje w konstruktorze. Wynik swojego działania pozostawiają do interpretacji w miejscu swojego wywołania.
Kontroler w jednym zadaniu może wykonać kilka operatorów.

### Akcja
Obiekt klasy action::Operator tworzony dynamicznie na potrzeby konkretnego zadnia. Ma dostęp do algorytmów, modelu i innych operatorów. 

### Serwis
Obiekt klasy action::Operator istniejący jako singleton wywoływany na potrzeby konkretnego zadania, różni się od akcji tym, że pamięta stan pomiędzy wywołaniami. Ma dostęp do algorytmów, modelu i innych operatorów.

### Algorytm
Klasa/funkcja przetwarzająca dane wejściowe, zwraca wynik - nie modyfikuje niczego w aplikacji. Nie ma dostępu do operatorów i modelu.

### Model
Przechowuje w bazie danych pozwala wyszukiwać i modyfikować. Model zakłada się z rekordów i ich kolekcji. Kolekcje realizują wszystkie operacje na zbiorach danych.

### Wejście
Analiza danych wejściowych. Sprawdzenie ich poprawności pod względem bezpieczeństwa aplikacji oraz zgodnością z wykonywanym zadaniem.

### Wyjście
Przygotowuje dane do wysłania na zewnątrz aplikacji.

## Komunikacja 

<small>Obecnie, komunikaty nie zwracają informacji o ewentualnym błędzie. W przypadku błędu zwracany jest pusty zbiór.</small>

Serwer rozsyła powiadomienia w postaci tekstowej.
Format wiadomości zależy od jej typu, domyślnie jest to one. 
Serwer wysyła wiadomości i odpowiedzi. Wiadomości wysyłane są do wszystkich podłączonych klientów. Odpowiedzi tylko do nadawcy zapytania.

Każda wiadomość poprzedzona jest nazwą typu wiadomości oddzielony znakiem "|". Typ wiadomości pozwala odbiorcy przekierować odebraną wiadomość do właściwego obiektu gdzie nastąpi właściwa analiza.

Wymiana danych pomiędzy pomiędzy klientem i serwerem odbywa się za pośrednictwem dwóch protokołów. Wybór możliwy jest przez podanie odpowiednich parametrów w wierszu poleceń podczas uruchamiania serwera. Klient wybiera protokół podczas nawiązywanie połączenia z serwerem. 

Parametry : ...

### Protokół JSON

#### Wiadomości automatycznie generowane przez server
Struktura :

``"type|{data}"``

Cały komunikat może składać się tylko z tokenów oddzielonych znakiem "|". Pierwszy token to zawsze jest nazwą typu wiadomości a pozostałe i ich ilość zależą od typu :

``"type|parametr0|parametr1|parametr..."``

#### Komunikaty, odpowiedzi i żądania.
Format odpowiedzi na odebrane żądanie podobny jest do wiadomości automatycznie generowanych przez serwer ale typ odpowiedzi ma tą samą nazwę co zapytanie oraz parametry:

żądanie:

``"getLogsBetween|2011-11-11-11-11-11|2011-11-11-12-12-12"``

odpowiedź:

``"getLogsBetween|2011-11-11-11-11-11|2011-11-11-12-12-12{logi wygenerowane przed datą z zapytania}"``

#### Komendy

``stopPushingLogs``  - klient wyłącza automatyczne wysyłanie nowych logów przez serwer do siebie

``startPushingLogs`` - klient włącza automatyczne wysyłanie nowych logów przez serwer do siebie

### Protokół EBNF

#### Wiadomości automatycznie generowane przez server

Struktura :

```
...
```

...

```
....
```

#### Komunikaty, odpowiedzi i żądania.

Format odpowiedzi na odebrane żądanie podobny jest do wiadomości automatycznie generowanych przez serwer ale typ odpowiedzi ma tą samą nazwę co zapytanie oraz parametry:

żądanie:

```
...
```

odpowiedź:

```
...
```

#### Komendy

```...```  - klient wyłącza automatyczne wysyłanie nowych logów przez serwer do siebie

```...``` - klient włącza automatyczne wysyłanie nowych logów przez serwer do siebie