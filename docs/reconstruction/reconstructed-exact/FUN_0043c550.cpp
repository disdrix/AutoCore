// FUN_0043c550 / GuardedVector_EraseFirstEqual
// Stable ID: aa_0043c550
// Address:   0x0043c550–0x0043c5e1
// Twin plate: prefer GuardedVector_EraseFirstEqual.cpp for named CF.
// This FUN_* alias preserves the Ghidra symbol for xref continuity.

#include <cstdint>

// See GuardedVector_EraseFirstEqual.cpp for sealed clean reconstruction.
// Retail: ESI=container; stack key*; RET 4; AL=bool found+erased.

extern "C" uint8_t FUN_0043c550(int* key);
