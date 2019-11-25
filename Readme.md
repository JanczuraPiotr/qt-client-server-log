## Architektura

Kod dzielony jest na **kontrolery**, **akcje**, **serwisy**, **algorytmy**, **model** (**rekord**, **kolekcja**). Akcje i serwisy to **operatorzy**. Podział ma swoje odzwierciedlenie w strukturze katalogów. Katalog common nie ma narzuconej struktury ale częściowo może pokrywać się ze strukturą katalogów sv i client.
Kontroler może rozpoczynać swoje działanie na danych wejściowych a także wysyłać te dane na zewnątrz aplikacji. Analizę danych wejściowych wykonują **wejścia**. Przygotowanie danych wyjściowych wykonują **wyjścia**.
Podział kodu odzwierciedlony jest w przestrzeni nazw.
Podstawowym "narzędziem" pracy kontrolera jest **sygnał**. Swoje zadania realizuje po otrzymaniu sygnału a jeżeli scenariusz tego wymaga wysyłają odpowiednie sygnały z powiadomieniami. Sygnały realizowane są metodą connect biblioteki QT ale za pośrednictwem klasy SignalBus. Dodatkowa klasa opakowująca sygnały biblioteki QT ma pomóc w testowaniu.

### Kontroler
Obsługuje sygnały. Nie ma dostępu do modelu i algorytmów.
Odbierając sygnał kontroler uruchamia klasę przeznaczoną do jego obsługi. Może nią być klasa action::Operator lub service::Operator. Odbiera od operatora wynik działania i obsługuje w zależności od kontekstu (rest api, socket , konsola, inny blok aplikacji).
Operatorzy wykonują swoje operacje na obiektach przekazanych przez referencje w konstruktorze. Wynik swojego działania pozostawiają do interpretacji w miejscu swojego wywołania.
Kontroler w jednym zadaniu może wykonać kilka operatorów.

### Akcja
Obiekt klasy action::Operator tworzony dynamicznie na potrzeby konkretnego zadnia. Ma dostęp do algorytmów, modelu i innych operatorów. 

### Serwis
Obiekt klasy action::Operator istniejący jako singleton wywoływany na potrzeby konkretnego zadania, różni się od akcji tym, że pamięta stan pomiędzy wywołaniami. Ma dostęp do algorytmów, modelu i innych operatorów.

### Algorytm
Klasa/funkcja przetwarzająca dane wejściowe, zwraca wynik - nie modyfikuje niczego w aplikacji. Nie ma dostępu do operatorów i modelu.

### Model
Przechowuje w bazie danych pozwala wyszukiwać i modyfikować.o Model zakłada się z rekordów i ich kolekcji. Kolekcje realizują wszystkie operacje na zbiorach danych.

### Wejście
Analiza danych wejściowych. Sprawdzenie ich poprawności pod względem bezpieczeństwa aplikacji oraz zgodnością z wykonywanym zadaniem.

### Wyjście
Przygotowuje dane do wysłania na zewnątrz aplikacji.

## Komunikacja 
Serwer rozsyła powiadomienia w postaci tekstowej.
Format wiadomości zależy od jej typu, domyślnie jest to json. 
Server wysyła wiadomości i odpowiedzi. Wiadomości wysyłane są do wszystkich podłączonych klientów. Odpowiedzi tylko do nadawcy zapytania.
### Wiadomości automatycznie generowane przez server
Każda wiadomość poprzedzona jest nazwą typu wiadomości oddzielony znakiem "|". Typ wiadomości pozwala odbiorcy przekierować odebraną wiadomość do właściwego obiektu gdzie nastąpi właściwa analiza.
Struktura :
```
"type|{data}"

```
Cały komunikat może składać się tylko z tokenów oddzielonych znakiem "|". Pierwszy token to zawsze jest nazwą typu wiadomości a pozostałe i ich ilość zależą od typu :
```
"type|parametr0|parametr1|parametr..."

```
### Odpowiedzi na komunikaty i żądania.
Format odpowiedzi na odebrane żądanie podobny jest do wiadomości automatycznie generowanych przez server ale typ odpowiedzi ma tą samą nazwę co zapytanie:
żądanie:
```
"getTime"
```
odpowiedź
```
"getTime|2019-11-11 11-11-11"
```

żądanie:
```
"setTime|2019-11-11 11-11-11"
```
odpowiedź:
```
"setTime|success"
```
a do wszystkich klientów może zostać wysłane powiadomienie:
```
"currentTime|2019-11-11 11-11-11"
```
