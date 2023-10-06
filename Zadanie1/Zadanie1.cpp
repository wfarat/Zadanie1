// Zadanie1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

class StringCounter {
public:
  // Constructor
  StringCounter() {}

  // Add a string to the counter
  void addString(const std::string& str) {
    stringCount[str]++;
  }

  // Get the count of a specific string
  int getCount(const std::string& str) const {
    if (stringCount.find(str) != stringCount.end()) {
      return stringCount.at(str);
    }
    return 0;
  }

  // Print all elements in the counter
  void printAllElements() const {
    for (const auto& pair : stringCount) {
      std::cout << "String: " << pair.first << ", Count: " << pair.second << std::endl;
    }
  }

private:
  std::unordered_map<std::string, int> stringCount;
};
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
  StringCounter counter;
  while (std::getline(iss, element, ',')) {
    // Usuń ewentualne spacje na początku i końcu elementu
    size_t start = element.find_first_not_of(" \t\n");
    size_t end = element.find_last_not_of(" \t\n");
    if (start != std::string::npos && end != std::string::npos) {
      element = element.substr(start, end - start + 1);
    }
    
    counter.addString(element);
  }

  // Wyświetl zawartość zbioru
  counter.printAllElements();

  return 0;
}



