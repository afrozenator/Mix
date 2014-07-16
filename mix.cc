#include "mix.h"

namespace mix {

Mix::Mix() {

	for (size_t i = 0; i < 8; ++i) {
		io_devices_[i] = new MagneticTape();
  }
	for (size_t i = 8; i < 16; ++i) {
		io_devices_[i] = new DiskOrDrum();
  }
	io_devices_[16] = new CardReader();
	io_devices_[17] = new CardPunch();
	io_devices_[18] = new LinePrinter();
	io_devices_[19] = new TypeWriter();
	io_devices_[20] = new PaperTape();
}

Mix::~Mix() {
	for (size_t i = 0; i < 21; ++i) {
		delete io_devices_[i];
  }
}

void Mix::Execute(const Instruction& instruction) {
  switch (instruction.op_code()) {
    case LDA:
    case LDX:
    case LD1:
    case LD2:
    case LD3:
    case LD4:
    case LD5:
    case LD6:
    	
  	case ADD:
    case SUB:
    case MUL:
    case DIV:
  }
}

}  // namespace mix