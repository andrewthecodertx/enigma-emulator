#include <string>

using namespace std;

class Reflector {
public:
  Reflector(const string &wiring);
  char Encode(char c) const;
  char Decode(char c) const;

private:
  string wiring_;
};
