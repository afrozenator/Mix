#include "instruction.h"

#include <cmath>

#include "macros.h"

namespace mix {

Instruction::Instruction(const Word& word)
  : word_(word),
    aa_(word_.value(0, 2)),
	  i_(word_.value(3, 3)),
	  f_(word_.value(4, 4)),
	  c_(word_.value(5, 5)),
	  op_code_(DetermineOpCode(c_, f_)) {
}

bool Instruction::sign() const {
	return word_.sign();
}

int32_t Instruction::aa() const {
	return aa_;
}

uint32_t Instruction::aau() const {
	return abs(aa_);
}

uint32_t Instruction::i() const {
	return i_;
}

uint32_t Instruction::f() const {
	return f_;
}

uint32_t Instruction::c() const {
	return c_;
}

Instruction Instruction::FromString(const std::string& val) {
	ASSERT(false, "This hasn't been implemented yet.");
	Instruction i;
	return i;
}

// TODO(afrozm): Implement more.
OpCode Instruction::DetermineOpCode(uint32_t c, uint32_t f) const {
  switch (c()) {
    case 8:
		  return LDA;
    default:
		  return NOP;
  }
}

OpCode Instruction::op_code() const {
	return op_code_;
}

}  // namespace mix
