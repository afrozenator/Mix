#ifndef __MIX_H__
#define __MIX_H__

#include "byte.h"
#include "io_device.h"
#include "register.h"

namespace mix {

class Instruction;

enum ComparisonIndicator {LESS, EQUAL, GREATER};

class Mix {
 public:
	Mix();
	~Mix();
  // Const accessors.
	bool overflow_toggle() const { return overflow_toggle_; }
	const Register* a() const { return &a_; }
	const Register* x() const { return &x_; }
	const Register* i() const { return &i_[0]; }
	const Register* j() const { return &j_; }
	const Word* memory() const { return &memory_[0]; }
	const IODevice* const* io_devices() const { return &io_devices_[0]; }
	ComparisonIndicator comparison_indicator() const { return comparison_indicator_; }
  // Excute an instruction.
	void Execute(const Instruction& instruction);
 private:
  // Execute LD*
	void ExecuteLoad(const Instruction& instruction, Register* reg);
	Register5 a_;
	Register5 x_;
	Register2 i_[6];
	RegisterJ j_;
	bool overflow_toggle_;
	ComparisonIndicator comparison_indicator_;
	Word memory_[4000];
	IODevice* io_devices_[21];
};

}  // namespace mix

#endif // __MIX_H__

