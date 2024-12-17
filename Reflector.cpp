#include "include/Reflector.hpp"

using namespace std;

Reflector::Reflector(const string &wiring) : wiring_(wiring) {}

char Reflector::Encode(char c) const { return wiring_[c - 'A']; }
