#include "byte.h"

#include <assert.h>
#include <cmath>

namespace mix {

const uint8_t Byte::kMaxValues = 100;
const uint8_t Byte::kMinValues = 64;
const uint8_t Byte::kBase = 2;
const uint8_t Byte::kBits = 6;
const uint8_t Byte::kMaxVal = pow(kBase, kBits);  // kBase ^ kBits

void Byte::set_value(uint8_t value) {
	assert(value < kMaxVal);
	value_ = value;
}

string Byte::DebugString() const {
	return "Value: " + std::to_string(value_);
}

}  // namespace mix

// TODO(afrozm): Make it work
/*
std::ostream& operator<<(std::ostream& os, const mix::Byte& byte) {
	return os << byte.DebugString();
}
*/
