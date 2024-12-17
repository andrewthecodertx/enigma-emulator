#include "include/Enigma.hpp"

using namespace std;

Enigma::Enigma(const array<Rotor, 3> &rotors, const Reflector &reflector,
               const map<char, char> &plugboard)
    : rotors_(rotors), reflector_(reflector), plugboard_(plugboard) {}

void Enigma::SetRotorPositions(char left, char middle, char right) {
  rotors_[0].SetPosition(left);
  rotors_[1].SetPosition(middle);
  rotors_[2].SetPosition(right);
}

char Enigma::EncryptChar(char c) {
  if (!isalpha(static_cast<unsigned char>(c))) {
    return c;
  }

  c = static_cast<char>(toupper(static_cast<unsigned char>(c)));

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

string Enigma::EncryptMessage(const string &msg) {
  string result;
  for (auto ch : msg) {
    if (isalpha(static_cast<unsigned char>(ch))) {
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
