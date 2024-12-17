#include "include/Reflector.hpp"

Reflector::Reflector(const string &wiring) : wiring_(wiring) {}

char Reflector::Encode(char c) const { return wiring_[c - 'A']; }
