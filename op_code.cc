#include "op_code.h"

namespace mix {

// TODO(afrozm): Add AX where it makes sense.
Operations::Op Operations::operations_[Operations::NUM_OPS] = {
  { 0, 0, NOP,  "NOP" ,  NUM_REGISTERS},
	{ 1, 0, ADD , "ADD" ,  A},
	{ 2, 0, SUB , "SUB" ,  A},
	{ 3, 0, MUL , "MUL" ,  A},
	{ 4, 0, DIV , "DIV" ,  A},
  { 5, 0, NUM , "NUM" ,  AX},
  { 5, 1, CHAR, "CHAR" , AX},
  { 5, 2, HLT , "HLT" ,  NUM_REGISTERS},
  { 6, 0, SLA, "SLA", A},
  { 6, 1, SRA, "SRA", A},
  { 6, 2, SLAX, "SLAX", AX},
  { 6, 3, SRAX, "SRAX", AX},
  { 6, 4, SLC, "SLC", A},
  { 6, 5, SRC, "SRC", A},
  { 7, 0, MOVE, "MOVE", I1},
  { 8, 0, LDA , "LDA" ,  A},
  { 9, 0, LD1 , "LD1" , I1},
  {10, 0, LD2 , "LD2" , I2},
  {11, 0, LD3 , "LD3" , I3},
  {12, 0, LD4 , "LD4" , I4},
  {13, 0, LD5 , "LD5" , I5},
  {14, 0, LD6 , "LD6" , I6},
  {15, 0, LDX , "LDX" ,  X},
  {16, 0, LDAN, "LDAN",  A},
  {17, 0, LD1N, "LD1N",  I1},
  {18, 0, LD2N, "LD2N",  I2},
  {19, 0, LD3N, "LD3N",  I3},
  {20, 0, LD4N, "LD4N",  I4},
  {21, 0, LD5N, "LD5N",  I5},
  {22, 0, LD6N, "LD6N",  I6},
  {23, 0, LDXN, "LDXN",   X},
  {24, 0, STA , "STA" ,   A},
  {25, 0, ST1,  "ST1",  I1},
  {26, 0, ST2,  "ST2",  I2},
  {27, 0, ST3,  "ST3",  I3},
  {28, 0, ST4,  "ST4",  I4},
  {29, 0, ST5,  "ST5",  I5},
  {30, 0, ST6,  "ST6",  I6},
  {31, 0, STX , "STX" ,   X},
  {32, 0, STJ , "STJ" ,   J},
  {33, 0, STZ , "STZ" ,   A},
  
  // TODO(afrozm): IO Operators
  {34, 0, JBUS, "JBUS", NUM_REGISTERS},
  {35, 0, IOC, "IOC", NUM_REGISTERS},
  {36, 0, IN, "IN", NUM_REGISTERS},
  {37, 0, OUT, "OUT", NUM_REGISTERS},
  {38, 0, JRED, "JRED", NUM_REGISTERS},
  
  {39, 0, JMP,  "JMP" ,   J},
  {39, 1, JSJ, "JSJ" , J},
  {39, 2, JOV, "JOV" , J},
  {39, 3, JNOV, "JNOV" , J},
  {39, 4, JL, "JL", J},
  {39, 5, JE, "JE", J},
  {39, 6, JG, "JG", J},
  {39, 7, JGE, "JGE", J},
  {39, 8, JNE, "JNE", J},
  {39, 9, JLE, "JLE", J},
	{40, 0, JAN, "JAN", J},
	{40, 1, JAZ, "JAZ", J},
	{40, 2, JAP, "JAP", J},
	{40, 3, JANN, "JANN", J},
	{40, 4, JANZ, "JANZ", J},
	{40, 5, JANP, "JANP", J},
	{41, 0, J1N, "J1N"},
	{41, 1, J1Z, "J1Z"},
	{41, 2, J1P, "J1P"},
	{41, 3, J1NN, "J1NN"},
	{41, 4, J1NZ, "J1NZ"},
	{41, 5, J1NP, "J1NP"},
	{42, 0, J2N, "J2N"},
	{42, 1, J2Z, "J2Z"},
	{42, 2, J2P, "J2P"},
	{42, 3, J2NN, "J2NN"},
	{42, 4, J2NZ, "J2NZ"},
	{42, 5, J2NP, "J2NP"},
	{43, 0, J3N, "J3N"},
	{43, 1, J3Z, "J3Z"},
	{43, 2, J3P, "J3P"},
	{43, 3, J3NN, "J3NN"},
	{43, 4, J3NZ, "J3NZ"},
	{43, 5, J3NP, "J3NP"},
	{44, 0, J4N, "J4N"},
	{44, 1, J4Z, "J4Z"},
	{44, 2, J4P, "J4P"},
	{44, 3, J4NN, "J4NN"},
	{44, 4, J4NZ, "J4NZ"},
	{44, 5, J4NP, "J4NP"},
	{45, 0, J5N, "J5N"},
	{45, 1, J5Z, "J5Z"},
	{45, 2, J5P, "J5P"},
	{45, 3, J5NN, "J5NN"},
	{45, 4, J5NZ, "J5NZ"},
	{45, 5, J5NP, "J5NP"},
	{46, 0, J6N, "J6N"},
	{46, 1, J6Z, "J6Z"},
	{46, 2, J6P, "J6P"},
	{46, 3, J6NN, "J6NN"},
	{46, 4, J6NZ, "J6NZ"},
	{46, 5, J6NP, "J6NP"},
	{47, 0, JXN, "JXN", J},
	{47, 1, JXZ, "JXZ", J},
	{47, 2, JXP, "JXP", J},
	{47, 3, JXNN, "JXNN", J},
	{47, 4, JXNZ, "JXNZ", J},
	{47, 5, JXNP, "JXNP", J},
  {48, 0, INCA, "INCA",   A},
  {48, 1, DECA, "DECA",   A},
  {48, 2, ENTA, "ENTA",   A},
  {48, 3, ENNA, "ENNA",   A},
  {49, 0, INC1, "INC1",  I1},
  {49, 1, DEC1, "DEC1",  I1},
  {49, 2, ENT1, "ENT1",  I1},
  {49, 3, ENN1, "ENT1",  I1},
  {50, 0, INC2, "INC2",   I2},
  {50, 1, DEC2, "DEC2",   I2},
  {50, 2, ENT2, "ENT2",   I2},
  {50, 3, ENN2, "ENT2",   I2},
  {51, 0, INC3, "INC3",   I3},
  {51, 1, DEC3, "DEC3",   I3},
  {51, 2, ENT3, "ENT3",   I3},
  {51, 3, ENN3, "ENT3",   I3},
  {52, 0, INC4, "INC4",   I4},
  {52, 1, DEC4, "DEC4",   I4},
  {52, 2, ENT4, "ENT4",   I4},
  {52, 3, ENN4, "ENT4",   I4},
  {53, 0, INC5, "INC5",   I5},
  {53, 1, DEC5, "DEC5",   I5},
  {53, 2, ENT5, "ENT5",   I5},
  {53, 3, ENN5, "ENT5",   I5},
  {54, 0, INC6, "INC6",   I6},
  {54, 1, DEC6, "DEC6",   I6},
  {54, 2, ENT6, "ENT6",   I6},
  {54, 3, ENN6, "ENT6",   I6},
  {55, 0, INCX, "INCX",   X},
  {55, 1, DECX, "DECX",   X},
  {55, 2, ENTX, "ENTX",   X},
  {55, 3, ENNX, "ENTX",   X},
  {56, 0, CMPA, "CMPA",   A},
  {57, 0, CMP1, "CMP1",   I1},
  {58, 0, CMP2, "CMP2",   I2},
  {59, 0, CMP3, "CMP3",   I3},
  {60, 0, CMP4, "CMP4",   I4},
  {61, 0, CMP5, "CMP5",   I5},
  {62, 0, CMP6, "CMP6",   I6},
  {63, 0, CMPX, "CMPX",   X},
};

const Operations::Op* Operations::op(uint32_t c, uint32_t f) {
	// TODO(afrozm): Assertions on the value of c.
  for (int i = 0; i < NUM_OPS; ++i) {
    if (operations_[i].c_ != c) {
			continue;
    }
		// TODO(afrozm): Code this.
  }
	return nullptr;
}

}  // namespace mix
