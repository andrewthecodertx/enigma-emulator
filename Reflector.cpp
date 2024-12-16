#include <string>

class Reflector {
public:
  Reflector(const std::string &wiring);
  char Encode(char c) const;
  char Decode(char c) const;

private:
  std::string wiring_;
};

Reflector::Reflector(const std::string &wiring) : wiring_(wiring) {}

char Reflector::Encode(char c) const { return wiring_[c - 'A']; }
