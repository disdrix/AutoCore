// =============================================================================
// StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00406de0
// Address:   0x00406de0  (autoassault.exe, image base 0x400000)
// Body:      0x00406de0–0x00406e48 (104 B / 0x68); ret 0xC; pad CC
// System:    util / container (std::vector elem stride 0x28)
// Generated: 2026-08-04 WQ9G-H dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_00406de0
// =============================================================================
//
// PURPOSE:
//   Insert exactly one 0x28-byte element into an MSVC-style vector, then rebind
//   an out-iterator so it remains valid after a possible reallocation of begin.
//
// ABI (customcc — sealed from bytes C2 0C 00 + parent FUN_00406220):
//   EDI        = vector*  (begin@+4, end@+8, capEnd@+0xC)
//   stack arg0 = T** outIt
//   stack arg1 = T*  insert position (push_back passes end)
//   stack arg2 = const T* value (pointer to 0x28 POD)
//   return     = EAX = outIt; ret 0xC
//
// CALLEE:
//   FUN_00408050 — insert-N engine for elem 0x28
//     ECX=vec*, EDX=value*, stack where*, count; count forced to 1 here
//
// PARENT:
//   FUN_00406220 push_back: capacity room → ConstructN@end + end+=0x28;
//                           else this unit with where=end.
//
// TWINS (CF shape):
//   aa_0040b6d0 StdVector_InsertOne_RebindIt_Via419880_Inferred (dword / ret 8)
//   aa_0040dbf0 StdVector_InsertOne_RebindIt_Thiscall_Inferred
// =============================================================================

#include <cstdint>

// Insert-N for 0x28-byte elements (undualed residual; CF known from parent).
// ECX = vec*, EDX = value*, stack where*, count.
extern "C" void FUN_00408050(
    /*ECX*/ void* vec,
    /*EDX*/ const void* value,
    /*stack*/ void* where,
    /*stack*/ unsigned count);

// Customcc cannot be expressed portably; register contract documented in plate.
// Body mirrors recovered CF with explicit parameters for readability.

extern "C" void** StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred(
    void* vec /*EDI*/,
    void** outIt /*stack*/,
    void* where,
    const void* value)
{
  int begin = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 4);
  int index;
  if (begin != 0 &&
      ((*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) - begin) / 0x28) != 0) {
    index = (reinterpret_cast<int>(where) - begin) / 0x28;
  } else {
    index = 0;
  }

  // Bytes: mov edx, value; push 1; push where; mov ecx, edi; call FUN_00408050
  FUN_00408050(vec, value, where, 1);

  *outIt = reinterpret_cast<void*>(
      *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 4) + index * 0x28);
  return outIt; // EAX = outIt; ret 0xC
}
