#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <cstdint>
#include <string>

#include "op_code.h"
#include "word.h"

namespace mix {

class Instruction {
 public:
  Instruction() {}
	explicit Instruction(const Word& word);
	bool sign() const;
	int32_t aa() const;
	uint32_t aau() const;  // unsigned AA
	uint32_t i() const;
  uint32_t f() const;
  uint32_t c() const;
	OpCode op_code() const;
  // TODO(afrozm): Implement this.
	static Instruction FromString(const std::string& val);
 private:
  OpCode DetermineOpCode(uint32_t c, uint32_t f) const;
	Word word_;
	int32_t aa_;
	uint32_t i_;
	uint32_t f_;
	uint32_t c_;
	OpCode op_code_;
};

}  // namespace mix

#endif // __INSTRUCTION_H__
