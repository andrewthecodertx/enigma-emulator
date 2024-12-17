#include "Reflector.hpp"
#include "Rotor.hpp"
#include <array>
#include <map>

using namespace std;

class Enigma {
public:
  Enigma(const array<Rotor, 3> &rotors, const Reflector &reflector,
         const map<char, char> &plugboard);

  char EncryptChar(char c);
  string EncryptMessage(const std::string &msg);
  void SetRotorPositions(char left, char middle, char right);

private:
  void StepRotors();

  array<Rotor, 3> rotors_;
  Reflector reflector_;
  map<char, char> plugboard_;
};
