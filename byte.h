#ifndef __BYTE_H__
#define __BYTE_H__

#include <cstdint>
#include <string>

namespace mix {

using std::string;

class Byte {
 public:
	uint8_t value() const { return value_;}
	void set_value(uint8_t value);
	string DebugString() const;
	static const uint8_t kMaxValues;
	static const uint8_t kMinValues;
	static const uint8_t kBase;
	static const uint8_t kBits;
	static const uint8_t kMaxVal;
 private:
	uint8_t value_;
};

}  // namespace mix

// TODO(afrozm): Make it work
// extern std::ostream& operator<<(std::ostream& os, const mix::Byte& byte);

#endif // __BYTE_H__
