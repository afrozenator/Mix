#include "word.h"

#include <assert.h>
#include <limits>

namespace mix {

int32_t Word::value(uint8_t field) const {
  // field is represented as 8L + R
	return value(field / 8, field % 8);
}

const Byte& Word::byte(uint8_t n) const {
	assert(n >= 1); assert(n <= 5);
	return bytes_[n - 1];
}

int32_t Word::value(uint8_t l, uint8_t r) const {
	if (l == r) {
  	if (l == 0) {
			return sign_;
    }
		return byte(l).value();
  }
  assert(l < r);
	bool is_signed = (l == 0);
  if (is_signed) {
		l = 1;
  } 
	int32_t value = 0;
	for (size_t i = l; i <= r; ++i) {
		value = (value * Byte::kMaxVal) + byte(i).value();
  }
	return is_signed ? -value : value;
}

}  // namespace mix
