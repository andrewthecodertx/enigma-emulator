#include "Reflector.cpp"
#include "Rotor.cpp"
#include <array>
#include <map>
#include <string>

class Enigma {
public:
  Enigma(const std::array<Rotor, 3> &rotors, const Reflector &reflector,
         const std::map<char, char> &plugboard);

  char EncryptChar(char c);
  std::string EncryptMessage(const std::string &msg);
  void SetRotorPositions(char left, char middle, char right);

private:
  void StepRotors();

  std::array<Rotor, 3> rotors_;
  Reflector reflector_;
  std::map<char, char> plugboard_;
};

Enigma::Enigma(const std::array<Rotor, 3> &rotors, const Reflector &reflector,
               const std::map<char, char> &plugboard)
    : rotors_(rotors), reflector_(reflector), plugboard_(plugboard) {}

void Enigma::SetRotorPositions(char left, char middle, char right) {
  rotors_[0].SetPosition(left);
  rotors_[1].SetPosition(middle);
  rotors_[2].SetPosition(right);
}

char Enigma::EncryptChar(char c) {
  if (!std::isalpha(static_cast<unsigned char>(c))) {
    return c;
  }

  c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));

  StepRotors();

  c = plugboard_.at(c);

  c = rotors_[2].EncodeForward(c);
  c = rotors_[1].EncodeForward(c);
  c = rotors_[0].EncodeForward(c);

  c = reflector_.Encode(c);

  c = rotors_[0].EncodeBackward(c);
  c = rotors_[1].EncodeBackward(c);
  c = rotors_[2].EncodeBackward(c);

  c = plugboard_.at(c);

  return c;
}

std::string Enigma::EncryptMessage(const std::string &msg) {
  std::string result;
  for (auto ch : msg) {
    if (std::isalpha(static_cast<unsigned char>(ch))) {
      result.push_back(EncryptChar(ch));
    } else {
      result.push_back(ch);
    }
  }
  return result;
}

void Enigma::StepRotors() {
  bool rightAtNotch = rotors_[2].AtNotch();
  bool middleAtNotch = rotors_[1].AtNotch();

  rotors_[2].Advance();

  if (middleAtNotch || rightAtNotch) {
    rotors_[1].Advance();
  }

  if (middleAtNotch) {
    rotors_[0].Advance();
  }
}
