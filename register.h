#ifndef __REGISTER_H__
#define __REGISTER_H__

#include "byte.h"
#include "macros.h"
#include "word.h"

namespace mix {

enum Registers {
	A,
  I1,
  I2,
  I3,
  I4,
  I5,
  I6,
  X,
  J,
  AX,
  NUM_REGISTERS,
};

class Register {
 public:
	virtual ~Register();
	virtual bool sign() const ABSTRACT;
	virtual uint8_t num_bytes() const ABSTRACT;
	virtual const Byte* bytes() const ABSTRACT;
};

class Register5 : public Register {
 public:
	virtual bool sign() const override { return w_.sign();}
	virtual uint8_t num_bytes() const override { return w_.num_bytes(); }
	virtual const Byte* bytes() const override { return w_.bytes();}
 private:
	Word w_;
};

class Register2 : public Register {
 public:
	virtual bool sign() const override { return sign_;}
	virtual uint8_t num_bytes() const override { return 2; }
	virtual const Byte* bytes() const override { return &bytes_[0];}
 private:
	Byte bytes_[2];
	bool sign_;
};

class RegisterJ : public Register2 {
 public:
	virtual bool sign() const override { return true;}
	virtual uint8_t num_bytes() const override { return 2; }
	virtual const Byte* bytes() const override { return &bytes_[0];}
 private:
	Byte bytes_[2];
};

}  // namespace mix

#endif // __REGISTER_H__