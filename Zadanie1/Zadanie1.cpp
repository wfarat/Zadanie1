// Zadanie1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <set>
#include <string>
#include <sstream>

int main() {
  std::cout << "Wprowadź wieloliniowy ciąg (aby zakończyć, naciśnij Enter bez wpisywania tekstu):\n";

  std::string multilineInput;
  std::string line;
 
  while (std::getline(std::cin, line) && !line.empty()) {
    for (char& c : line) {
      c = std::toupper(c); // Zamień na dużą literę
    }
    multilineInput += line + '\n';
  }
  std::istringstream iss(multilineInput);
  std::string element;
  std::set<std::string> mySet;

  while (std::getline(iss, element, ',')) {
    // Usuń ewentualne spacje na początku i końcu elementu
    size_t start = element.find_first_not_of(" \t\n");
    size_t end = element.find_last_not_of(" \t\n");
    if (start != std::string::npos && end != std::string::npos) {
      element = element.substr(start, end - start + 1);
    }

    mySet.insert(element);
  }

  // Wyświetl zawartość zbioru
  for (const std::string& item : mySet) {
    std::cout << item << std::endl;
  }

  return 0;
}





// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

 //porady dotyczące rozpoczynania pracy:
 //  1. użyj okna eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
 //  2. użyj okna programu team explorer, aby nawiązać połączenie z kontrolą źródła
 //  3. użyj okna dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
 //  4. użyj okna lista błędów, aby zobaczyć błędy
 //  5. wybierz pozycję projekt > dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję projekt > dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
 //  6. aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji plik > otwórz > projekt i wybierz plik sln