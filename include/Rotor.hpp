#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <string>

using namespace std;

class Rotor {
public:
  Rotor(const string &wiring, char notch);

  void SetPosition(char c);
  void Advance();
  char EncodeForward(char c) const;
  char EncodeBackward(char c) const;
  bool AtNotch() const;

private:
  string wiring_;
  char notch_;
  int position_;
};

#endif
