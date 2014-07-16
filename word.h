#ifndef __WORD_H__
#define __WORD_H__

#include "byte.h"

namespace mix {

// This can hold numbers from 0 to 1,073,741,823

class Word {
 public:
	uint8_t num_bytes() const { return 5; }
	const Byte* bytes() const { return &bytes_[0]; }
	bool sign() const { return sign_; }
	int32_t value(uint8_t field) const;
  int32_t value(uint8_t l, uint8_t r) const;
	const Byte& byte(uint8_t n) const;
 private:
	bool sign_;
	Byte bytes_[5];
};

}  // namespace mix

#endif // __WORD_H__
