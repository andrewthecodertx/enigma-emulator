#include <string>

class Rotor {
public:
  Rotor(const std::string &wiring, char notch);

  void SetPosition(char c);
  void Advance();
  char EncodeForward(char c) const;
  char EncodeBackward(char c) const;
  bool AtNotch() const;

private:
  std::string wiring_;
  char notch_;
  int position_;
};

Rotor::Rotor(const std::string &wiring, char notch)
    : wiring_(wiring), notch_(notch), position_(0) {}

void Rotor::SetPosition(char c) { position_ = c - 'A'; }

void Rotor::Advance() { position_ = (position_ + 1) % 26; }

char Rotor::EncodeForward(char c) const {
  int offset = (c - 'A' + position_) % 26;
  char encoded = wiring_[offset];
  int decoded = (encoded - 'A' - position_ + 26) % 26;
  return static_cast<char>(decoded + 'A');
}

char Rotor::EncodeBackward(char c) const {
  int offset = (c - 'A' + position_) % 26;
  char target = static_cast<char>(offset + 'A');
  int idx = static_cast<int>(wiring_.find(target));
  int decoded = (idx - position_ + 26) % 26;
  return static_cast<char>(decoded + 'A');
}

bool Rotor::AtNotch() const { return position_ == (notch_ - 'A'); }
