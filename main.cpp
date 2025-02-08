#include "include/Enigma.hpp"
#include <iostream>

int main() {
  string rotorI_wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
  string rotorII_wiring = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
  string rotorIII_wiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";

  Rotor rotorI(rotorI_wiring, 'Q');
  Rotor rotorII(rotorII_wiring, 'E');
  Rotor rotorIII(rotorIII_wiring, 'V');

  string reflectorB_wiring = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
  Reflector reflectorB(reflectorB_wiring);

  map<char, char> plugboard;
  for (char c = 'A'; c <= 'Z'; ++c) {
    plugboard[c] = c;
  }

  plugboard['A'] = 'B';
  plugboard['B'] = 'A';
  plugboard['C'] = 'D';
  plugboard['D'] = 'C';

  array<Rotor, 3> rotors = {rotorI, rotorII, rotorIII};
  Enigma enigma(rotors, reflectorB, plugboard);
  enigma.SetRotorPositions('A', 'A', 'A');

  string plaintext = "here comes the music. please listen";
  string ciphertext = enigma.EncryptMessage(plaintext);
  cout << "Plaintext:  " << plaintext << "\n";
  cout << "Ciphertext: " << ciphertext << "\n";

  enigma.SetRotorPositions('A', 'A', 'A');
  string decrypted = enigma.EncryptMessage(ciphertext);
  cout << "Decrypted:  " << decrypted << "\n";
}
