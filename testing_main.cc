#include <iostream>

#include "byte.h"
#include "mix.h"

using namespace std;

using mix::Byte;

int main() {
	{
		Byte b;
		b.set_value(63);
		cout << b.DebugString() << endl;
	}
	cout << mix::ComparisonIndicator::LESS << endl;
  printf("%ju\n", (intmax_t)(INT32_MAX));
}
